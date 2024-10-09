/*
 * File:   main.c
 * Author: frank
 *
 * Created on 5 de octubre de 2024, 06:57 AM
 */


#include <xc.h>
#include "glcd.h"


void GLCD_WriteString(const char *str, uint8_t pos, uint8_t line)
{
	uint16_t offset;
	uint8_t page = 0;
	
	
	
	
	if(pos < 9)
	{
		offset = pos * 8;
		GLCD_SelectPage0();
	}
	else
	{
		offset = (pos - 9) * 8;
		GLCD_SelectPage1();
		page = 1;
	}
	
	GLCD_CmdWrite(GLCD_SETX_ADDRESS | GLCD_MASKX(offset));
	GLCD_CmdWrite(GLCD_SETY_ADDRESS | GLCD_MASKY(line));
	
	while(*str)
	{
		
		if(pos >= 9 && page == 0)
		{
			GLCD_SelectPage1();
			page = 1;
			GLCD_CmdWrite(GLCD_SETX_ADDRESS | GLCD_MASKX(0));
			GLCD_CmdWrite(GLCD_SETY_ADDRESS | GLCD_MASKY(line));
		}
		GLCD_DisplayChar(*str++);
		pos++;
	}
	
	
}

void main(void) 
{
	ANSELB = 0;
	ANSELD = 0;
	PORTB = 0;
	PORTD = 0;
	TRISD = 0;
	TRISB = 0xC3U;
	
	GLCD_Init();
	
	GLCD_WriteString("Hola Mundo!!!", 0, 0);
	
	/*GLCD_SelectPage0();
	GLCD_CmdWrite(GLCD_SETX_ADDRESS | GLCD_MASKX(0));
	GLCD_CmdWrite(GLCD_SETY_ADDRESS | GLCD_MASKY(3));
	
	GLCD_DisplayChar('H');
	GLCD_DisplayChar('O');
	GLCD_DisplayChar('L');
	GLCD_DisplayChar('A');
	
	GLCD_SelectPage1();
	GLCD_CmdWrite(GLCD_SETX_ADDRESS | GLCD_MASKX(0));
	GLCD_CmdWrite(GLCD_SETY_ADDRESS | GLCD_MASKY(3));
	
	GLCD_DisplayChar('M');
	GLCD_DisplayChar('U');
	GLCD_DisplayChar('N');
	GLCD_DisplayChar('D');
	GLCD_DisplayChar('O');*/
	
	
	while(1)
	{
		
	}
}
