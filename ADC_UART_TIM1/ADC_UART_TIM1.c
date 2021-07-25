//Read internal temperature and send to uart and controlled by TIM2
#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int data;
double voltage;
double celsius;
char name[20];
//Function prototypes

void Init_USART(void);
int USART2_Write(int c);

int main(void)
{
	int i;
	
	RCC->AHB1ENR |=1;//Enable clock source to PORTA
	RCC->APB1ENR |=1;
	TIM2->PSC =1600-1;
	TIM2->ARR =10000-1;
	TIM2->CNT =0;
	TIM2->CCMR1 =0x6800;
	TIM2->CCER =0x0010;//Enable TIM2 CH2
	TIM2->CCR2 =50-1;
	TIM2->CR1 =1;

	
	//ADC SETUP
	RCC->APB2ENR |=0x100;//Enable ADC clock
	ADC->CCR |=0x800000;
	ADC->CCR &=~ 0x400000;//Vbat must be disable for the temp sensor
	ADC1->SMPR1 =0x04000000;//sampling time minimun 10us
	ADC1->SQR3 =18;
	ADC1->CR2 =0x13000000;
	ADC1->CR2 |=1;
	Init_USART();

	while(1)
	{
		while(!(ADC1->SR)){}
			data = ADC1->DR;
			voltage = (double)data/4095*3.3;
			celsius=(voltage-0.76)/0.0025+25;
			sprintf(name, "%f", celsius);
		for(i=0;i<strlen(name);i++)
			{
				USART2_Write(name[i]);
			
			}
			USART2_Write('\n');
			USART2_Write('\r');
			
	}
	

}

void Init_USART(void)
{
	RCC->APB1ENR |= 0x20000;//Enble clock source to enable USART2
	RCC->AHB1ENR |=1;//Enable clock source to PORTA
	GPIOA->AFR[0] |= 0x700;//Set the GPIO->PA3 as alternate function pin X
	GPIOA->MODER |= 0x0020;//Set the mode of the PA3 as alternate function
	USART2->BRR |= 0x683;//set baud rate to 9600
	USART2->CR1 = 0x0008;//Enable RX mode by write to RE bit
	USART2->CR1 |= 0x2000;//Enable USART2

}
int USART2_Write(int ch)
{
	while(!(USART2->SR & 0x80)){}
		USART2->DR =(ch &0xFF);
}
