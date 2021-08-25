/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
char num[4],key,hold[4];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
char Get_Key(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_UART_Transmit(&huart2,(uint8_t*)"PLEASE ENTER PASSWORD\r\n",25,100);
	while(1)
	{
		for(int n=0;n<=3;n++)
		{
			num[n] = Get_Key();
			HAL_Delay(100);
			HAL_UART_Transmit(&huart2,(uint8_t*)"*",1,100);
		}
		HAL_UART_Transmit(&huart2,(uint8_t*)"\r\n",2,100);
		
		if(strcmp(num,"1234")==0)
			{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				break;
			}
	}

		
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLRCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_Pin|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
char Get_Key(void)
{
	int done=1;
	while(done)
	{
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_SET);  //Pull the R1 HIGH
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);  // Pull the R2 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);  // Pull the R3 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);  // Pull the R4 High
	
	if ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)));   // wait till the button is pressed
		key='1';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)))   // if the Col 2 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
		key='2';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 3 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		key='3';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 4 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		key='A';
		break;
	}
	
	//COLUMN 2
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);  //Pull the R1 HIGH
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_10, GPIO_PIN_SET);  // Pull the R2 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);  // Pull the R3 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);  // Pull the R4 High
	
	if ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)));   // wait till the button is pressed
		key='4';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)))   // if the Col 2 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
		key='5';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 3 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		key='6';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 4 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		key='B';
		break;
	}
	//COLUMN 3
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);  //Pull the R1 HIGH
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);  // Pull the R2 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, GPIO_PIN_SET);  // Pull the R3 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);  // Pull the R4 High
	
	if ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)));   // wait till the button is pressed
		key='7';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)))   // if the Col 2 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
		key='8';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 3 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		key='9';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 4 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		key='C';
		break;
	}
	//COLUMN 4
	HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);  //Pull the R1 HIGH
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);  // Pull the R2 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);  // Pull the R3 High
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_5, GPIO_PIN_SET);  // Pull the R4 High
	
	if ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)))   // if the Col 1 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_3)));   // wait till the button is pressed
		key='*';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)))   // if the Col 2 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
		key='0';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)))   // if the Col 3 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0)));   // wait till the button is pressed
		key='#';
		break;
	}
	
	if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)))   // if the Col 4 is low
	{
		while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1)));   // wait till the button is pressed
		key='D';
		break;
	}
}
	return(key);
	
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
