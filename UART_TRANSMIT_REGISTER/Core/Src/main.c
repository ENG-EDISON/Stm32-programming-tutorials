#include "stm32f4xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void USART_Init(void);           //CREATE A CUSTOM INIT FUNCTION TO INTIIALIZE THE USART
void USART_Write(int ch);        //CREATE THE USART_WRITE FUNCTION TO OUTPUT CHARACTERS
void DelayMs();                  //FUNCTION TO CREATE DELAY.
int main()
{
	USART_Init();
	while(1)
	{
		USART_Write('h');      //OUTPUT CAHARATER 'H'
		USART_Write('i');      //OUTPUT CAHARCTER 'i'
		USART_Write('r');      //PERFOM CARRIAGE RETURN
		USART_Write('\n') ;    //JUMP TO THE NEXT LINE
		DelayMs();             //CREATE  A DELAY FUNCTION
	}

}
void USART_Init(void)
{

	RCC->APB1ENR |=(1<<17);      //Enable RCC_APB1ENR BIT-17 TO ENABLE CLOCK FOR USART2
	RCC->AHB1ENR |=(1<<0);       //ENABLE RCC_AHB1ENR BIT0 TO ENABLE CLOCK FOR FOR GPIOA
	GPIOA->AFR[0] |= 0x0700 ;    //SET ALTERNATE FUNCTION AF7 TO UART2 BECAUSE ITS A GENERAL PURPOSE GPIO
	GPIOA->MODER |=(1<<5);       //SET THE GPIO_MODER REGISTER BIT-10 TO ACTIVATE ALTERNATE FUNCTION FOR GPIOA
	USART2->BRR =0x0683;         //Set BAUDRATE FOR COMMUNICATION
	USART2->CR1 =(1<<3);         //SET CONTROL REGISTER BIT3 (Transmit-Enable REGISTER)
	USART2->CR1 |=(1<<13);       //SET CONTROL REGISTER BIT 13 (UART-ENABLE REGISTER)

}
void USART_Write(int ch)
{
		while(!(USART2->SR & (1<<7))){}          //WAIT UNTILL THE TX BUFFER IS EMPTY
       USART2->DR =(ch & 0xFF);                  //PERFORM BITWISE OPERATION AND OUTPUT THE CHARACTER
}

void DelayMs()                                   //USER DELAY FUNCTION
{
	for(int i =0;i<=900000;i++){}                //ADD ARTIFICIAL DELAY
}
