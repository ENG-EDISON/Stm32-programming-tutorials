#include "stm32f4xx.h"                  // Device header

int main()
{
	//SET PA5
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=	0x800;//SET PA5 TO ALTERNATE FUNCTION
	GPIOA->AFR[0] |=0x100000;//SET PA5 TO AF2 TIM2 MODE
	
	//SET TIM2
	RCC->APB1ENR |=1;//Enable clock to TIM2
	TIM2->PSC =160-1;//Prescale TIM2 by 1600
	TIM2->ARR =26667-1;//Get 1HZ requency
	TIM1->CNT=0;//initialize counter to zero
	TIM2->CCMR1 |=0x60;//Enable PWM mode
	TIM2->CCER |=1;//Enable PWM ch1
	TIM2->CCR1=13333-1;
	TIM2->CR1 =1;//Enbale counter
	
	while(1)
	{
	
	}
	
	
	
	


}
