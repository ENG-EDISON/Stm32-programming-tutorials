#include "stm32f4xx.h"                  // Device header

void delay(int n);
void led_play(int value);
void USART2_IRQHandler(void);
void UART2_Init(void);

int main()
{
	__disable_irq();
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x400;
	UART2_Init();
	USART2->CR1 |=0x20;//Enable RX USART2 interrupt
	NVIC_EnableIRQ(USART2_IRQn);
	__enable_irq();
	while(1)
	{
	
	}
}

void UART2_Init(void)
{
	RCC->AHB1ENR |=1;
	RCC->APB1ENR |=0x20000;//Enable clock to UART2
	GPIOA->AFR[0] |=0x7000;//set to alternate function UART2
	GPIOA->MODER |=0x80;//enable PA3 as USART
	USART2->BRR |=0x008B;//115200b/s at 16MHz
	USART2->CR1 |=0x4;//Enable USART2 RECEIVER
	USART2->CR1 |=0x2000;//Enable USART2
}


void led_play(int value)
{
	value %=16;
	for(;value>0;value--)
	{
		GPIOA->BSRR=0x20;//Set PA5 to TURN ON LED
		delay(1000);//Wait
		GPIOA->BSRR=(1<<21);//Reset PA5 to TURN OFF LED
		delay(1000);//wait

	}
}

void delay(int n)
{
	SysTick->LOAD =16000;
	SysTick->VAL =0;
	SysTick->CTRL =0x5;//enable systick
	for(int i =0;i<n;i++)
	{
		while((SysTick->CTRL & 0x10000)==0){}
	
	}
	SysTick->CTRL =0;
}

void USART2_IRQHandler(void)
{
	if(USART2->SR & 0x20)
	{
		volatile char c;
		c = (USART2->DR);
		led_play(c);
	}

}
