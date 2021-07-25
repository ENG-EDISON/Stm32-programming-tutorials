#include "stm32f4xx.h"                  // Device header
//configure systick interrupt to toggle led interrupt
//at 1HZ,System clock is 16MHz
int main(void)
{
	__disable_irq();
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x400;
	SysTick->LOAD =1600000000-1;
	SysTick->VAL=0;
	SysTick->CTRL =7;
	__enable_irq();
	
	while(1)
	{
	}

}
void SysTick_Handler(void)
{
GPIOA->ODR ^=0x20;

}
