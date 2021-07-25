#include "stm32f4xx.h"                  // Device header
#include "stm32f446xx.h"

int main()
{
	RCC->APB1ENR |=1;
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=(1<<10);
	
	TIM2->PSC =1600-1;
	TIM2->ARR =10000-1;
	TIM2->CNT =0;
	TIM2->CR1 =1;
	while(1)
	{
		while(!(TIM2->SR & 1)){}
			TIM2->SR &= ~ 1;
			GPIOA->ODR ^=0x20;
	
	}
	
}

