#include "stm32f4xx.h"                  // Device header

 int analogue_value;
//CONFIGURE ADC CH1
int main()
{
	RCC->AHB1ENR |=1;//Enable clock to PORT A
	GPIOA->MODER |=0xc;//setting PA1 to analogue pin
	
	RCC->APB2ENR |=0x100;//Enable clock to ADC
	ADC1->CR2 =0;//Disable ADC
	ADC1->SQR3=1;//
	ADC1->CR2 |=1;//Enable ADC
	while(1)
	{
		ADC1->CR2 |=0x40000000;//start connversion
		//wait for conversion to be complete
		while(!(ADC1->SR & 2)){}
			analogue_value =ADC1->DR;
		
	
	}
 	


}
