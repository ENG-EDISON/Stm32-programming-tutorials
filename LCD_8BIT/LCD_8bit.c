#include "stm32f4xx.h"                  // Device header

//PC0-PC7 ->DO-D7
//PB5=RS
//PB6 =R/W
//PB7 =EN

#define RS 0x20  //0010 0000
#define RW 0x40
#define EN 0x80


//Prototypes
void delay(int dlay);
void GPIO_Init(void);
void LCD_Init(void);
void LCD_Command(unsigned char command);
void LCD_Data(char data);



int main(void)
{
	void LCD_Init(void);
	while(1)
	{
		LCD_Data('H');
		LCD_Data('E');
		LCD_Data('L');
		LCD_Data('L');
		LCD_Data('0');
		LCD_Data('\n');
		LCD_Data('\r');
		LCD_Command(1);//clear screen
		delay(500);
	}
	



}

void LCD_Init(void)
{
	GPIO_Init();
	//Init sequence
	delay(30);
	LCD_Command(0x30);
	delay(10);
	LCD_Command(0x30);
	delay(1);
	LCD_Command(0x30);
	
	LCD_Command(0x38);//set 8bit data mode 2-lone 5x7
	LCD_Command(0x06);//move cursor right
	LCD_Command(0x01);//Clear screen,move cursor home
	LCD_Command(0x0F);//turn display,blink cursor
	


}

void GPIO_Init(void)
{
	RCC->AHB1ENR |= 0x60;//Enable PORT B AND C
	GPIOA->MODER |=0x5400;
	GPIOB->BSRR =0xc;//Set EN AND RW LOW
	
	//SET PCO-PC7 AS OUTPUT
	GPIOC->MODER |=0x5555;//set pc0-pc7 to output pin
	


}

void LCD_Command(unsigned char command)
{
	GPIOB->BSRR =(RS|RW)<<16; //RS=0,R/W =0
	GPIOC->ODR =command;
	GPIOB->BSRR =EN;
	delay(0);
	GPIOB->BSRR =EN<<16;//CLEAR EN
	


}

void LCD_Data(char data)
{
	GPIOB->ODR=RS;//SET RS=1;
	GPIOB->ODR =0;//SET RW LINE TO ZERO
	GPIOC->ODR =data;
	GPIOB->BSRR =EN;
	delay(10);
	GPIOB->BSRR =0;//CLEAR EN

}

void delay(int dlay)
{
	int i;
	for(;dlay>0;dlay--)
	{
		for(i=0;i<3195;i++){}
	}
}
