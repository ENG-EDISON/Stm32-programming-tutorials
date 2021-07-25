#include "stm32f4xx.h"  // Device header

int period,freq;
int main()
{
	int last_value=0;
	int current_value;
	//SET PA5
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x800;
	GPIOA->AFR[0]=0x100000;//Set PA5 to AF1 for TIM2 CH1
	
	//configure TIM2
	RCC->APB1ENR |=1;
	TIM2->PSC =800-1;
	TIM2->ARR =10000-1;
	TIM2->CCMR1 =0x30;//Set output to toggle on match
	TIM2->CCR1 =0;//Set match mode
	TIM2->CCER |=1;
	TIM2->CR1 =1;
	
	//SET PA6 AS INPUT COMPARE
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x2000;//PA6 at alternate function
	GPIOA->AFR[0] |=0x2000000;//set pa5 to AF2 for TIM3 CH1
	
	RCC->APB1ENR |=2;//Enable clock to TIM3
	TIM3->PSC = 16000-1;
	TIM3->CCMR1 = 0x41;
	TIM3->CCER =0x0B;
	TIM3->CR1 =1;
	while(1)
	{
		while(!(TIM3->SR &2)){}//wait untill edge is captured
			current_value =TIM3->CCR1;
			period =current_value-last_value;
			last_value=current_value;
			freq= 1000.0f/ period;
			last_value =current_value;
			
			
			
	
	}
	
	
	
	
	
	
	

}
