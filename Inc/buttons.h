/*
 * buttons.h
 *
 *  Created on: Sep 23, 2023
 *      Author: majorBien
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_
#include "stm32l4xx_hal.h"
#include "main.h"
#include "math.h"
#include "gpio.h"


void cylinder_capacity(void);

void target_pressure(void);

void leak_test_start(double pressure1, double pressure2);

void compression_test_start(void);

#endif /* INC_BUTTONS_H_ */
