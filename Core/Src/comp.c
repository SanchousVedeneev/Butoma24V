/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    comp.c
  * @brief   This file provides code for the configuration
  *          of the COMP instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "comp.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

COMP_HandleTypeDef hcomp2;

/* COMP2 init function */
void MX_COMP2_Init(void)
{

  /* USER CODE BEGIN COMP2_Init 0 */

  /* USER CODE END COMP2_Init 0 */

  /* USER CODE BEGIN COMP2_Init 1 */

  /* USER CODE END COMP2_Init 1 */
  hcomp2.Instance = COMP2;
  hcomp2.Init.InputPlus = COMP_INPUT_PLUS_IO2;
  hcomp2.Init.InputMinus = COMP_INPUT_MINUS_IO1;
  hcomp2.Init.OutputPol = COMP_OUTPUTPOL_NONINVERTED;
  hcomp2.Init.Hysteresis = COMP_HYSTERESIS_NONE;
  hcomp2.Init.BlankingSrce = COMP_BLANKINGSRC_NONE;
  hcomp2.Init.TriggerMode = COMP_TRIGGERMODE_NONE;
  if (HAL_COMP_Init(&hcomp2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN COMP2_Init 2 */

  /* USER CODE END COMP2_Init 2 */

}

void HAL_COMP_MspInit(COMP_HandleTypeDef* compHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(compHandle->Instance==COMP2)
  {
  /* USER CODE BEGIN COMP2_MspInit 0 */

  /* USER CODE END COMP2_MspInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**COMP2 GPIO Configuration
    PA3     ------> COMP2_INP
    PA5     ------> COMP2_INM
    PA7     ------> COMP2_OUT
    */
    GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_COMP2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN COMP2_MspInit 1 */

  /* USER CODE END COMP2_MspInit 1 */
  }
}

void HAL_COMP_MspDeInit(COMP_HandleTypeDef* compHandle)
{

  if(compHandle->Instance==COMP2)
  {
  /* USER CODE BEGIN COMP2_MspDeInit 0 */

  /* USER CODE END COMP2_MspDeInit 0 */

    /**COMP2 GPIO Configuration
    PA3     ------> COMP2_INP
    PA5     ------> COMP2_INM
    PA7     ------> COMP2_OUT
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_7);

  /* USER CODE BEGIN COMP2_MspDeInit 1 */

  /* USER CODE END COMP2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
