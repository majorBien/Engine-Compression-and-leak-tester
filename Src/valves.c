/*
 * valves.c
 *
 *  Created on: Feb 29, 2024
 *      Author: majorBien
 */


#include "valves.h"



void leakTestCycle(void)
{

	if(step==1||step==2)
	{

		switch(step)
		{
		case 0:
		HAL_GPIO_WritePin(VALVE_IN_GPIO_Port, VALVE_IN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_RESET);
		break;

		case 1:
		HAL_GPIO_WritePin(VALVE_IN_GPIO_Port, VALVE_IN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_RESET);
		break;

		case 2:
		HAL_GPIO_WritePin(VALVE_IN_GPIO_Port, VALVE_IN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_SET);
		break;

		case 4:
		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_RESET);
		break;

		case 6:
		HAL_GPIO_WritePin(VALVE_IN_GPIO_Port, VALVE_IN_Pin, GPIO_PIN_RESET);
		break;

		case 10:

		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_SET);
		break;


		}

	}



}

void compressionCycle(void)
{

	if(step==3||step==4)
	{


		HAL_GPIO_WritePin(VALVE_IN_GPIO_Port, VALVE_IN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(VALVE_OUT_GPIO_Port, VALVE_OUT_Pin, GPIO_PIN_RESET);


	}



}
