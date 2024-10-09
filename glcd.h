/* 
 * File:   glcd.h
 * Author: frank
 *
 * Created on 5 de octubre de 2024, 06:58 AM
 */

#ifndef GLCD_H
#define	GLCD_H

#ifdef	__cplusplus
extern "C" {
#endif

//GLCD Commands
#define GLCD_DISPLAY_ON		0x3FU
#define GLCD_DISPLAY_OFF	0x3EU
#define GLCD_SETY_ADDRESS	0x40U
#define GLCD_SETX_ADDRESS	0xB8U
#define GLCD_SETZ_ADDRESS	0xC0U
	
//MASK TO CORRECT ADDRESSING
#define GLCD_SETY_MASK		0x3FU
#define GLCD_SETX_MASK		0x07U
	
//STATUS BITS
#define GLCD_STA_BUSY		0x80U
#define GLCD_STA_ONOFF		0x20U
#define GLCD_STA_RESET		0x10U
	
#define GLCD_BIT_BUSY	7
#define GLCD_BIT_ONOFF	5
#define GLCD_BIT_RESET	4
	
#define GLCD_MASKX(addr) (addr & GLCD_SETX_MASK)
#define GLCD_MASKY(addr) (addr & GLCD_SETY_MASK)
	
//Function prototype
void GLCD_SelectPage0(void);
void GLCD_SelectPage1(void);
void GLCD_CmdWrite(uint8_t cmd);
void GLCD_DataWrite(uint8_t dat);
void GLCD_Init(void);
void GLCD_DisplayChar(char c);



#ifdef	__cplusplus
}
#endif

#endif	/* GLCD_H */

