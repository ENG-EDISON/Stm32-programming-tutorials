//enable clock to PORTA
//enable clock to USART2
//Enable PIN PA2(TX),PIN PA3(RX) in ALternate function mode
//Select alternate function low registers
//Enable RX and TX mode in CR1 register
//Enable USART2 by setting bit 13 in the CR1 Register
//Integrate stdio with with HAL to enable use of printf() and scanf()


//includes
#include "stm32f446xx.h"
#include "stdio.h"


//Function prototypes
int UART_TX(int ch);//unction to transmit the charater
char UART_RX();//Fucntion to receive from Keyboard
void USART_Init(void);//Function to initialize uart RX &TX communication
void delay();//Functin to create delay or waste time



//main function
int main()
{

	USART_Init();
	char c;
	while(1)

	{
		c = UART_RX();//Function call to receive the character and store it in c
		UART_TX(c);//Transmit the data via UART to be visualized
		delay();//delay
	}
}


void USART_Init(void)
{
	RCC->AHB1ENR |=1;//Enable clock source to PORT A
	RCC->APB1ENR |=0x20000;//Envle clock to USART2
	GPIOA->AFR[0] |=0x7700;//Enable Alternate function for USART2 communication
	GPIOA->MODER |=0xA0;//Enable alternate function in PA3(RX) and PA2(TX)

	USART2->BRR |=0x683;//Set baudrate at 1600b/s at 16MHz Frequency
	USART2->CR1 |= 0xC;//Enable Transmission and Receiving enable for UART communication by setting TE and RE registers
	USART2->CR1 |=0x2000;//Enable USART communation

}


int UART_TX(int ch)
{
	while(!(USART2->SR & 0x80));//wait untill a flag is set to indicate a charater is ready to transmit
	USART2->DR |=(ch &0xFF);//when a character is received,put it in the data register(DR)
	return ch;//return the charater present at Data register
}


char UART_RX()
{
	while(!(USART2->SR & 0x20)){}//Wait untill a charster is received

	return(USART2->DR);//Return the character recived at the Data Register(DR)
}


void delay()
{

	for(int n=0;n<=90000;n++){}//waste time to create delay for approx. 1sec
}









