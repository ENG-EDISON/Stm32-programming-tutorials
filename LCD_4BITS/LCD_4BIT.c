#include "stm32f4xx.h"                  // Device header
//PC4-PC7
//PB5 :R/S
//GND:R/W
//PB7 :EN

#define RS 0x20
#define EN 0x80

void delay(int dlay);
void LEC_nibble_write(char data,unsigned char control);
void LCD_Data(char data);
void LCD_Command(unsigned char command);
void GPIO_Init(void);
void LCD_init(void);

int main()
{
	LCD_init();
	while(1)
	{
		LCD_Data('h');
		LCD_Data('e');
		LCD_Data('l');
		LCD_Data('l');
		LCD_Data('l');
		LCD_Data('0');
		delay(500);
		LCD_Command(0x01);
		delay(500);
		
	
	}




}
void LCD_init(void)
{
	GPIO_Init();
	
	delay(30);
	LEC_nibble_write(0x30,0);
	delay(5);
	LEC_nibble_write(0x30,0);
	delay(1);
	LEC_nibble_write(0x30,0);
	delay(1);
	LEC_nibble_write(0x20,0);
	delay(1);
	LCD_Command(0x28);
	LCD_Command(0x06);
	LCD_Command(0x01);
	LCD_Command(0x0F);
	
	

}
void GPIO_Init(void)
{
	RCC->AHB1ENR |=0x06;//port PB and PC
	GPIOB->MODER |=0x4400;
	GPIOB->BSRR =0x800000;//Clear EN
	
	GPIOC->MODER |=0x550;
	
	
}
void LEC_nibble_write(char data,unsigned char control)
{
	GPIOC->BSRR =0xF00000;
	GPIOC->BSRR =data & 0xF0;
	if(control &RS)
	{
		GPIOB->BSRR=RS;
	}
	else
	{
		GPIOB->BSRR=RS<<16;
	}
	
	//pulse EN line
	GPIOB->BSRR =EN;
	delay(0);
	GPIOB->BSRR =EN<<16;
}
void LCD_Command(unsigned char command)
{
	LEC_nibble_write(command & 0xF0,0);
	LEC_nibble_write(command<<4,0);
	if(command<4)
	{
		delay(2);
	}
	else
	{
		delay(1);

	}
}

void LCD_Data(char data)
{
	LEC_nibble_write(data & 0xF0,RS);
	LEC_nibble_write(data<<4,RS);
	delay(1);
	


}
void delay(int dlay)
{int i;
	for(;dlay>0;dlay--)
{
	for(i=0;i<3195;i++){}
}
		
}

