/*CREATING GPIO INTERRUPT*/

#include "stm32f4xx.h"                  // Device header

//LED:PA5
//Button:PC13

//Function prototypes
void EXTI15_10_IRQHandler(void);
void delay(int n);

int main(void)
{
	__disable_irq();
	
	RCC->AHB1ENR |=1;//Enable clock acces to PORT A
	RCC->AHB1ENR |=0x4;//Enable clock acces to PORT C
	RCC->APB2ENR |=0x4000;//Enable SYSCFG Clock
	GPIOA->MODER |=0x400;//Set PA5 TO OUTPUT;
	
	SYSCFG->EXTICR[3]=0x0020;//selecting PORT C for EXTI13
	EXTI->IMR |=0x2000;//Unmask EXTI13
	EXTI->FTSR |=0x2000;//Select falling edge trigger
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();
	while(1)
	{
		
	}
 
}
void EXTI15_10_IRQHandler(void)
{
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

