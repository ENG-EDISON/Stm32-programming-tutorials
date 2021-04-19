#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
int main(void)
{
	RCC->AHB1ENR |=(1<<0);//ENABLE CLOCK FOR PORT A
	RCC->AHB1ENR |=(1<<2);//ENABLE CLOCK FOR PORFT C
	GPIOA->MODER |=(1<<10);//OPERATION MODE OF PORTA SET TO OUTPUT MODE
	while(1)
	{
		if(GPIOC->IDR & 0x2000)
		{
			GPIOA-> ODR |=(0<<5);
		}
		else

		{
			GPIOA->ODR |=(1<<5);
		}

	}
}
