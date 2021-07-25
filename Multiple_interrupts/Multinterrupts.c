//Generate two interrupts from PB10 and  PC13
#include "stm32f4xx.h"                  // Device header

//Prototypes
void delay(int n);
void EXTI15_10_IRQHandler(void);

volatile int PB10_COUNTER;
volatile int PC13_COUNTER;

int main()
{
	__disable_irq();
	RCC->AHB1ENR |=1;//Enable clock to PORT A
	RCC->AHB1ENR |=0x2;//Enable clock to PORT B
	RCC->AHB1ENR |=0x4;//Enable clock to PORT C
	RCC->APB2ENR |=0x4000;//Enable SYSCFG clock
	GPIOA->MODER |=	0x400;//SET PA5 TO OUTPUT
	
	SYSCFG->EXTICR[3] |=0x20;//Select PORT C for EXTI13;
	EXTI->IMR |=0x2000;//Umask EXTI13
	EXTI->FTSR |=0x2000;//Select falling edge trigger
	GPIOB->PUPDR |=0x100000;//configure internal pull-UP resistor for PB10
	SYSCFG->EXTICR[2] |=0x100;//Select PORTB for EXT10
	EXTI->IMR |=0x400;//Un,ask EXTI10
	EXTI->FTSR |=0x0400;//Select falling edge trigger
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	__enable_irq();
	while(1)
	{
	
	}
	
	
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR ==0x2000)
		{
	PC13_COUNTER++;
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	EXTI->PR =0x2000;
		}
	else if(EXTI->PR ==0x400)
	{
	PB10_COUNTER++;
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	GPIOA->BSRR =0x20;
	delay(1000);
	GPIOA->BSRR =(1<<21);
	delay(1000);
	EXTI->PR =0x400;
		
	
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