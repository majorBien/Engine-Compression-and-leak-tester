/*
 * buttons.c
 *
 *  Created on: Sep 23, 2023
 *      Author: shadow7
 */
#include "buttons.h"

void cylinder_capacity(void)
{
	//float cylinder_capacity = Cylinder_capacity;


	  if(HAL_GPIO_ReadPin(B_UP_GPIO_Port, B_UP_Pin)== GPIO_PIN_SET)
			  	  {
				  	 HAL_Delay(100);
			  		 Cylinder_capacity = Cylinder_capacity + 0.1;
			  		 HAL_Delay(100);
			  	  }
			  	  if(HAL_GPIO_ReadPin(B_DOWN_GPIO_Port, B_DOWN_Pin)== GPIO_PIN_SET)
			  	  {
			  		 HAL_Delay(100);
			  		 Cylinder_capacity = Cylinder_capacity - 0.1;
			  		 HAL_Delay(100);
			  	  }
			  	 Rounded_capacity = roundf(Cylinder_capacity * 10.0) / 10.0;
			  	 Rounded_capacity = Rounded_capacity + 0.00001;

}


void leak_test_start(void)
{
	if(HAL_GPIO_ReadPin(B_UP2_GPIO_Port, B_UP2_Pin)== GPIO_PIN_SET && choice == 1)
		{
		step == 1;
		}
}
