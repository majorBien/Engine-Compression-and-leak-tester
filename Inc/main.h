/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
uint8_t choice;
uint8_t arr[2];
uint8_t cnt;
int test_time;
double Cylinder_capacity;
double Rounded_capacity;
uint8_t capture;
uint8_t step;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOA
#define M_PHASE1_Pin GPIO_PIN_1
#define M_PHASE1_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define M_PHASE2_Pin GPIO_PIN_3
#define M_PHASE2_GPIO_Port GPIOA
#define M_PHASE3_Pin GPIO_PIN_4
#define M_PHASE3_GPIO_Port GPIOA
#define M_PHASE4_Pin GPIO_PIN_0
#define M_PHASE4_GPIO_Port GPIOB
#define B_UP_Pin GPIO_PIN_1
#define B_UP_GPIO_Port GPIOB
#define B_DOWN_Pin GPIO_PIN_8
#define B_DOWN_GPIO_Port GPIOA
#define B_UP2_Pin GPIO_PIN_11
#define B_UP2_GPIO_Port GPIOA
#define VALVE_DROP_Pin GPIO_PIN_12
#define VALVE_DROP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_3
#define LD3_GPIO_Port GPIOB
#define VALVE_FLOW_Pin GPIO_PIN_4
#define VALVE_FLOW_GPIO_Port GPIOB
#define B_DOWN2_Pin GPIO_PIN_5
#define B_DOWN2_GPIO_Port GPIOB
#define B_RIGHT_Pin GPIO_PIN_6
#define B_RIGHT_GPIO_Port GPIOB
#define B_LEFT_Pin GPIO_PIN_7
#define B_LEFT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
