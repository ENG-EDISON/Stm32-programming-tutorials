//APB1 BIT 17 :USART2
//SET THE BAUDRATE BY CONFIGURING BAUDRATE REGISTER
//USE COTROL REGISTER TO ENABLE OR DISABLE UART
//RE(BIT2) MEANS RECEIVER ENABLE AND TE(BIT3) MEANS TRANSMITTER ENABLE AND EU(BIT13) MEANS UART ENABLE
//ALL THE THREE REGISTER HAVE TO BE ENABLE OR DISABLE FOR THE FULLY FUNCTIONING OF THE UART
//UART WORK ON ALTERNATE FUNCTION SO CONFUGURING THAT IS ESSENTIAL
//ALTERNATE FUNCTION (AF7 IN ALTERNATE FUNCTION LOW)OF USART2 TO BE ENABLED
//USART CONNECTED TO PA2 SO ENABLE CLOCK TO PA2
#include "stm32f4xx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void USART_write(int ch);//function prototype for writing characters to the screen
void USART_Init(void);//prototype to initialize the USART Peripheral
void Write_string(char* message);
void delayMs(void);//custom delay function
char msg[ ]="hello Edison,i was required to go to the market and buy some fruits";
int main()
{
	USART_Init();
	while(1)
	{
		Write_string(msg);
		USART_write('\n');
		USART_write('\r');

		delayMs();

	}



}

void USART_Init(void)
{
	RCC->APB1ENR |=0x20000;//To enable clock for APB1 to access USART2
	RCC->AHB1ENR |=1; //ENABLE CLOCK FOR GPIOA_PORT
	GPIOA->AFR[0]|= 0x700;//SET ALTERNATE FUNCTION REGISTER(AFRL[])TO ENABLE ALTERNATE FUNCTION FOR USART2[00000000 00000111 00000000 00000000]
	GPIOA->MODER |= 0x0020;//set PA2 to alternate function
	USART2->BRR   = 0x0683;//9600 @16MHZ
	USART2->CR1   = 0x0008; //ENABLE TX BY SETTING THE BIT3 00000000000000000000000000001000
	USART2->CR1  |= 0x2000;//ENABLE USART MODULE BY SETTING UE REGISTER( BIT13 )

}
void USART_write(int ch)
{
	while(!(USART2->SR & 0x00080)){}//wait while Tx buffer is empty
	USART2->DR = (ch & 0xFF);//PERFORM BITWISE AND AND PLACE IT IN DATA REGISTER(DR);

}
void delayMs(void)
{
	for(int i=0;i<=900000;i++){}

}
void Write_string(char* message)
{
	for(int i=0;i<=sizeof(msg);i++)
	{
		while(!(USART2->SR & 0x00080)){}//wait while Tx buffer is empty
		USART2->DR =(msg[i] & 0xFF);
	}


}
/***USART_write('H');
USART_write('I');
USART_write ('\n');
USART_write ('\r');
***/
