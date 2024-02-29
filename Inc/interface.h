/*
 * measurements.h
 *
 *  Created on: 27 sie 2023
 *      Author: majorBien
 */
#include "stm32l4xx_hal.h"
#include "main.h"
#include <stdio.h>


int chooseFunction(int analog_choice);

int capacity2pressure(double cylinderCapacity);

void printFunction(int choice);

double scaleNormPressure(int pressure);

char* double2string(double pressure, uint8_t x, uint8_t y);

char* float2string(float value, uint8_t x, uint8_t y);

void turboLeakTest(double inputPressure, double targetPressure,double testPressure);

void cylinderLeakTest(double inputPressure, double targetPressure,double testPressure);

void compressionTest(double pressure);

void trottleFlowTest(void);


