/*
 * bernoullie_law.h
 *
 *  Created on: 14 lut 2024
 *      Author: A0H93628
 */

#ifndef INC_BERNOULLIE_LAW_H_
#define INC_BERNOULLIE_LAW_H_
#include "stm32l4xx_hal.h"
#include "main.h"
#include "math.h"

double BernoulieLawFunction(uint16_t k, double air_viscosity, double deltaAir, double tubeRadius, double distance);






#endif /* INC_BERNOULLIE_LAW_H_ */


