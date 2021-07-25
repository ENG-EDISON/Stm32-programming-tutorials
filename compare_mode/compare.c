#include <stm32f4xx.h>

int main()
{
 RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x800;//set pa5 to alternate function
	GPIOA->AFR[0] =0x100000;//set pa5 as af1 for timer two to input
	
	RCC->APB1ENR |=1;
	TIM2->PSC =1600-1;
	TIM2 ->ARR =10000-1;
	TIM2 ->CCMR1=0x30;//011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR1.
	TIM2 ->CCR1 =0;//SET MATCH MODE
	TIM2 ->CCER =1;//ENABLE CHANEL1 COMPARE MODE
	TIM2->CNT =0;//CLEAR COUNTER
	TIM2 ->CR1 =1;//ENABLE TIMER2
	while(1)
	{
	}


}

