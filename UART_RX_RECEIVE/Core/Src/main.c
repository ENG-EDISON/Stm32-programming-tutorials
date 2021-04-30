#include "stm32f446xx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Init_USART(void);//	This function writes data to RX
char Char_Get(void);//This function gets character from computer keyboard
void delay(void);//This function provides for led to blink
void led_play(int value);//This function makes the LED blink as many times as the value pressed form the keyboard

int main()
{	RCC->AHB1ENR |=1;//This enable clock to GPIO Port A
	GPIOA->MODER |=0x400;//This sets GPIO PORTA to Output mode
	Init_USART();//This is a function call to initialize the USART2
	char ch;//Declaring charater 'ch' to hold the input data
	while(1)//loop that runs forever
	{
		ch=Char_Get();//Function to get the chaater that is input by pressing the keyboard
		led_play(ch);//Function that blinks the LED the number if times of the charater pressed by tthe user
	}

}

void Init_USART(void)
{
	RCC->AHB1ENR |=1;//Enable clock source to PORTA
	RCC->APB1ENR |= 0x20000;//Enble clock source to enable USART2
	GPIOA->AFR[0] |= 0x7000;//Set the GPIO->PA3 as alternate function pin RX
	GPIOA->MODER |= 0x0080;//Set the mode of the PA3 as alternate function
	USART2->BRR |= 0x683;//set baud rate to 9600
	USART2->CR1 = 0x0004;//Enable RX mode by write to RE bit
	USART2->CR1 |= 0x2000;//Enable USART2

}

char Char_Get(void)
{
	while(!(USART2->SR & 0x20)){}//Wait untill the buffer receives a charater
   return( USART2->DR & 0xFF);//When the buffer receives a charater,Write the dat to Data Register of USART2
}
void led_play(int value)
{
	value %=16;
	for(;value>0;value--)
	{
		GPIOA->BSRR=0x20;//Set PA5 to TURN ON LED
		delay();//Wait
		GPIOA->BSRR=(1<<21);//Reset PA5 to TURN OFF LED
		delay();//wait

	}
}

void delay(void)
{
	for(int i=0;i<=900000;i++){}//Delay for 1 second
}
