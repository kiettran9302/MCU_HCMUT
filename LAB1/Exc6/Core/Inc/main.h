/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define LED_ONE_Pin GPIO_PIN_4
#define LED_ONE_GPIO_Port GPIOA
#define LED_TWO_Pin GPIO_PIN_5
#define LED_TWO_GPIO_Port GPIOA
#define LED_THREE_Pin GPIO_PIN_6
#define LED_THREE_GPIO_Port GPIOA
#define LED_FOUR_Pin GPIO_PIN_7
#define LED_FOUR_GPIO_Port GPIOA
#define LED_FIVE_Pin GPIO_PIN_8
#define LED_FIVE_GPIO_Port GPIOA
#define LED_SIX_Pin GPIO_PIN_9
#define LED_SIX_GPIO_Port GPIOA
#define LED_SEVEN_Pin GPIO_PIN_10
#define LED_SEVEN_GPIO_Port GPIOA
#define LED_EIGTH_Pin GPIO_PIN_11
#define LED_EIGTH_GPIO_Port GPIOA
#define LED_NINE_Pin GPIO_PIN_12
#define LED_NINE_GPIO_Port GPIOA
#define LED_TEN_Pin GPIO_PIN_13
#define LED_TEN_GPIO_Port GPIOA
#define LED_ELEVEN_Pin GPIO_PIN_14
#define LED_ELEVEN_GPIO_Port GPIOA
#define LED_TWEVLE_Pin GPIO_PIN_15
#define LED_TWEVLE_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
