//this is a program to read input pin PC13(user button B1)
//when the button is pressed,the LED is switched on
#include"stm32f4xx.h"

int main(void)
{
	RCC->AHB1ENR |=(1<<0);//enable clock for PORT A
	RCC->AHB1ENR |=(1<<2);//Enable clock for PORT C
	GPIOA->MODER |=(1<<10);//This sets the port A as output(0x200)
	while(1)
	{
		if(GPIOC->IDR & 0x2000)//performing bitwise AND of 32bit value at IDR and 0x2000(00000000 00000000 00100000 00000000)
			GPIOA->BSRR |=0x200000;//0000 0000 0000 0000 0000 0000 0010 0000 Resetting BSSR register to TURN OFF LED
		else
			GPIOA->BSRR |=0x20;//0000 0000 0010 0000 0000 0000 0000 0000 set BSSR register to TURN ON LED
	}
}
