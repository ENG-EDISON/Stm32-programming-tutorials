#include "stm32f4xx.h"                  // Device header

int timestamp=0;

int main()
{
	RCC->AHB1ENR |=1;//Enable clock to PORTA
	GPIOA->MODER |=0x800;//set PA5 as alternate function
	GPIOA->AFR[0]|=0x100000;//set PA5 as AF1 TIM1/2;
	
	RCC->APB1ENR |=1;//Enable clock to TIM2
	TIM2->PSC =1600-1;
	TIM2->ARR =10000-1;
	TIM2->CCMR1 =0x30;//Output toggle on match 
	TIM2->CCR1 =0;
	TIM2->CCER |=1;
	TIM2->CNT =0;
	TIM2->CR1 =1;
	
	GPIOA->MODER |=0x2000;//PA6 -alternate function
	GPIOA->AFR[0] |=0x2000000;
	
	//Conigure TIM3
	RCC->APB1ENR |=2;//Enable TIM3 clock	
	TIM3->PSC =16000-1;
	TIM3->CCMR1 =0x1;//Set CH1 capture at every edge
	TIM3->CCER =1;//Enable capture at rising edge
	TIM3->CR1 =1;
	
	while(1)
	{
		while(!(TIM3->SR & 2)){} 
			timestamp=TIM3->CCR1;
	}
	
}
