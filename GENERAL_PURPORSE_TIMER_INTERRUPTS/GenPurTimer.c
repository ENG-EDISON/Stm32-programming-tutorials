#include "stm32f4xx.h"                  // Device header
//Toggle LED at 1Hz 
//System clock is 16MHz

int main()
{
	__disable_irq();
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x400;//PA5 output
	
	RCC->APB1ENR |=1;//Enable clock to TIM2
	TIM2->PSC =16000-1;
	TIM2->ARR =1000-1;
	TIM2->CR1=1;
	TIM2->DIER |=1;//Enable update interrupt enable(UIE)
	NVIC_EnableIRQ(TIM2_IRQn);
	__enable_irq();
	
	while(1){}
	


}

void TIM2_IRQHandler(void)
{
	TIM2->SR =0;
	GPIOA->ODR ^=0x20;

}