#include "stm32f4xx.h"                  // Device header


int main()
{
	RCC->AHB1ENR |=1;//ENABLE CLOCK ACCESS TO PORT A
	RCC->APB1ENR |=1;//ENABLE CLOCK ACCESS TO TIM2
	GPIOA->MODER |=0x800;//SET PA5 AS ALTERNATE FUNCTION
	GPIOA->AFR[0] |=0x100000;//SET ALTERNATE MODE TO AF1 FOR TIM2
	
	//set TIM2 TO OUTPUT COMPARE
	TIM2->PSC =800-1;//DIVIDE CLOCK BY 1600
	TIM2->ARR =10000-1;//DIVIDE CLOCK BY 10000 TO GET 1HZ
	TIM2->CNT =0;//INITIALIZE COUNTER TO ZERO
	TIM2->CCMR1 |=0x30;//SET THE OUTPUT TO TOGGLE OC1REF REGISTER ON MATCH
	TIM2->CCR1 =0;//SET THE VALUE TO BE MATCHED
	TIM2->CCER |=1;//ENABLE CHANNEL1 COMPARE MODE
	TIM2->CR1 |=1;//ENABLE COUNTER
	
		
		while(1)
		{
	
		
		}

}