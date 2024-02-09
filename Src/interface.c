/*
 * measurements.c
 *
 *  Created on: 27 sie 2023
 *      Author: shadow7
 */
#include <interface.h>
#include "i2c-lcd.h"
#include "main.h"
#include "stdbool.h"
#include "tim.h"

int chooseFunction(int analog_choice)
{

	if(analog_choice >=3200&&analog_choice<3600)
			{
					choice = 1;
			}
	if(analog_choice >=3600&&analog_choice<3750)
			{
					choice = 2;
			}
	if(analog_choice >=3750&&analog_choice<3850)
			{
					choice = 3;
			}
	if(analog_choice > 3850)
			{
					choice = 4;
			}




		return choice;
}


void printFunction(int choice)
{

	if (cnt ==0)
	{
		arr[cnt] = choice;
		cnt++;
	}
	if (cnt==1 && arr[cnt-1] != choice)
	{
		arr[cnt] = choice;
		cnt++;
	}
	if (cnt > 1)
	{
		cnt = 0;
	}
	if(arr[0] != arr[1]) lcd_clear();


	switch(choice)
		{
		case 1:

		lcd_set_cursor(2, 0);
		lcd_send_string("Test szczelnosci");
		lcd_set_cursor(5, 1);
		lcd_send_string("cylindrow");
	//	lcd_set_cursor(0, 2);
	//	lcd_send_string("pojemnosc skokowa:");

		break;

		case 2:

		lcd_set_cursor(2, 0);
		lcd_send_string("Test szczelnosci");
		lcd_set_cursor(1, 1);
		lcd_send_string("ukladu  dolotowego");

		break;

		case 3:

		lcd_set_cursor(3, 0);
		lcd_send_string("Test kompresji");
		lcd_set_cursor(7, 1);
		lcd_send_string("benzyna");
		break;

		case 4:

	    lcd_set_cursor(3, 0);
		lcd_send_string("Test kompresji");
		lcd_set_cursor(7, 1);
		lcd_send_string("diesel");

		break;
		}

}

double scaleNormPressure(int analog_pressure)
{
	uint16_t inputMin = 621;
	uint16_t inputMax = 4095;
	uint16_t outputMin = 0;
	uint16_t outputMax = 28;

	double pressure = (double)(analog_pressure - inputMin) / (inputMax - inputMin) * (outputMax - outputMin) + outputMin;
	return pressure;
}


char* double2string(double pressure, uint8_t x, uint8_t y)
{

		char outputString[6];
		sprintf(outputString, "%.1f", pressure);
		lcd_set_cursor(x, y);
		lcd_send_string(outputString);



}

char* float2string(float value, uint8_t x, uint8_t y)
{

		char outputString[6];
		sprintf(outputString, "%.1f", value);
		lcd_set_cursor(x, y);
		lcd_send_string(outputString);



}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim == &htim6)
	{
		test_time++;
	}

}

void cylinderLeakTest(double inputPressure, double targetPressure, double testPressure)
{

	motorControl(inputPressure, targetPressure);



}


