/*
 * measurements.c
 *
 *  Created on: 27 sie 2023
 *      Author: majorBien
 */
#include <interface.h>
#include "i2c-lcd.h"
#include "main.h"
#include "stdbool.h"
#include "tim.h"
#include "bernoullie_law.h"

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


int capacity2pressure(double cylinderCapacity)
{
	int targetPressure = 0.0;

	if(cylinderCapacity < 1.4)
	{
		targetPressure = 3.0;
	}
    if (cylinderCapacity > 1.4 && cylinderCapacity < 2.0)
	{
		targetPressure = 3.5;
	}

	if (cylinderCapacity >= 2.0)
	{
		targetPressure = 4.0;
	}
	return targetPressure;
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

	if(step == 0)
	{
	switch(choice)
		{
		case 1:

		lcd_set_cursor(2, 0);
		lcd_send_string("Test szczelnosci");
		lcd_set_cursor(5, 1);
		lcd_send_string("cylindrow");
		cylinder_capacity();
		lcd_set_cursor(0, 3);
		lcd_send_string("pojemnosc:");
		double2string(Cylinder_capacity,11,3);
		lcd_set_cursor(16, 3);
		lcd_send_string("cm^3");


		break;

		case 2:

		lcd_set_cursor(2, 0);
		lcd_send_string("Test szczelnosci");
		lcd_set_cursor(1, 1);
		lcd_send_string("ukladu  dolotowego");
		cylinder_capacity();
		lcd_set_cursor(0, 3);
		lcd_send_string("cisnienie:");
		double2string(targetPressure,11,3);
		lcd_set_cursor(16, 3);
		lcd_send_string("bar");
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

char* int2string(int value, uint8_t x, uint8_t y)
{

		char outputString[6];
		sprintf(outputString, "%d", value);
		lcd_set_cursor(x, y);
		lcd_send_string(outputString);



}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim == &htim6&&step==6||htim == &htim6&&step==8)
	{
		test_time++;
	}

}

void cylinderLeakTest(double inputPressure, double targetPressure,double testPressure)
{

	if(choice==1||choice==2)
	{

	uint8_t flag1;
	uint8_t flag2;
	uint8_t flag3;
	double pressureAfterStabilization;
	double airDrop;
	double procentageAirDrop;
	//float regulatorPressure = inputPressure + testPressure;

	if(step == 1)
	{
		lcd_clear();
		step = 2;
	}




	if(step == 2)
	{

	flag1 = 0;
	flag2 = 0;

	double regulatorPressure = BernoulieLawFunction(inputPressure, testPressure, 0.000018, 0.06, 0.05);


	lcd_set_cursor(0, 0);
	lcd_send_string("Kalibracja");
	lcd_set_cursor(0, 1);
	lcd_send_string("cisnienie:");
	lcd_set_cursor(0, 2);
	lcd_send_string("regulatora:");
	double2string(regulatorPressure,12 ,2);
	lcd_set_cursor(0, 3);
	lcd_send_string("zadane:");
	double2string(targetPressure,12 ,3);
	lcd_set_cursor(17, 2);
	lcd_send_string("bar");
	lcd_set_cursor(17, 3);
	lcd_send_string("bar");

	if(regulatorPressure > targetPressure - 0.05 && regulatorPressure < targetPressure + 0.05) step = 3;
	}



	if(step == 3)
	{

		if(flag1==0)
		{

			flag1 = 1;
			step = 4;
			lcd_clear();
		}

	}



	if(step == 4)
	{

		lcd_set_cursor(0, 0);
		lcd_send_string("Napelnianie");
		lcd_set_cursor(0, 1);
		lcd_send_string("cisnienie:");
		lcd_set_cursor(0, 2);
		lcd_send_string("wejsciowe:");
		double2string(testPressure,12 ,2);
		lcd_set_cursor(0, 3);
		lcd_send_string("zadane:");
		double2string(targetPressure,12 ,3);
		lcd_set_cursor(17, 2);
		lcd_send_string("bar");
		lcd_set_cursor(17, 3);
		lcd_send_string("bar");
		if(testPressure > targetPressure - 0.05&&testPressure < targetPressure + 0.05) step = 5;

	}



	if(step == 5)
	{

			test_time = 0;
			step = 6;
			lcd_clear();


	}



	if(step == 6)
	{

		lcd_set_cursor(0,0);
		lcd_send_string("Stabilizacja");
		lcd_set_cursor(0, 1);
		lcd_send_string("cisnienie");
		lcd_set_cursor(0, 2);
		lcd_send_string("testu:");
		double2string(testPressure,12 ,2);
		lcd_set_cursor(17, 2);
		lcd_send_string("bar");
		lcd_set_cursor(0, 3);
		lcd_send_string("czas");
		lcd_set_cursor(12, 3);
		int2string(test_time, 12, 3);
		lcd_set_cursor(18, 3);
		lcd_send_string("s");

		if(test_time==10) step = 7;


	}


	if(step == 7)
	{

			PressureAfterStabilization = testPressure;
			test_time = 0;
			step = 8;
			lcd_clear();
			AirDrop = 0.0;


	}


	if(step == 8)
	{
		AirDrop = PressureAfterStabilization - testPressure;
		lcd_set_cursor(0,0);
		lcd_send_string("Test szczelnosci");
		lcd_set_cursor(0, 1);
		lcd_send_string("spadek:");
		if (AirDrop > 0.0) double2string(AirDrop,11 ,1);
		lcd_set_cursor(0, 2);
		lcd_send_string("cisnienie:");
		double2string(testPressure,11 ,2);
		lcd_set_cursor(17, 1);
		lcd_send_string("bar");
		lcd_set_cursor(17, 2);
		lcd_send_string("bar");
		int2string(test_time, 12, 3);
		lcd_set_cursor(18, 3);
		lcd_send_string("s");
		if(test_time==10) step = 9;
	}

	if(step == 9)
	{


		step = 10;
		lcd_clear();



	}


	if(step == 10)
	{

		ProcentageAirDrop = AirDrop / PressureAfterStabilization * 100;
		lcd_set_cursor(0, 0);
		lcd_send_string("Spadek cisnienia:");
		lcd_set_cursor(0, 1);
		lcd_send_string("--------------------");
	    double2string(AirDrop,0 ,2);
		lcd_set_cursor(5, 2);
		lcd_send_string("bar");
		double2string(ProcentageAirDrop,0 ,3);
		lcd_set_cursor(5, 3);
		lcd_send_string("%");



	}


	}

}



void compressionTest(double pressure)
{

	if(choice==3||choice==4)
	{

	if(step == 1)
		{
		compression = 0.0;
		lcd_clear();
		step = 2;
		}

	if(step == 2)
	{


		if(pressure > 0.1)
		{
			if (pressure > highest_pressure)
			{
			    highest_pressure = pressure;
			    compression = pressure;
			    compression_psi = pressure*14.503774;
			}

		}

		lcd_set_cursor(0, 0);
		lcd_send_string("Pomiar kompresji:");
		lcd_set_cursor(0, 1);
		lcd_send_string("--------------------");
		double2string(compression_psi,0 ,2);
		lcd_set_cursor(6, 2);
		lcd_send_string("psi");
		double2string(compression,0 ,3);
		lcd_set_cursor(6, 3);
		lcd_send_string("bar");

	}

	}

}

