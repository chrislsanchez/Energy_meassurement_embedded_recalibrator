//***************************************************************************
//  File........: nokia1100_lcd_lib.h
//  Author(s)...: Chiper
//  URL(s)......: http://digitalchip.ru/
//  Device(s)...: ATMega...
//  Compiler....: AVR-GCC
//  Description.: LCD-controller driver from Nokia1100 with graphic functions
//  Data........: 28.03.12
//  Version.....: 2.1 
//***************************************************************************
//  Notice: All control contacts LCD-controller must be connected to 
// The same port on the microcontroller
//***************************************************************************
#ifndef _NOKIA1100_LCD_LIB_H_
#define _NOKIA1100_LCD_LIB_H_

//******************************************************************************
//******************************************************************************

#include "derivative.h"
#include "string.h"
#include <stdlib.h>
#include "nokia1100_lcd_font.h"	// Hooking font (will be placed in program memory)

// library Setup

// Port to which the controller is connected LCD-NOKIA 1100
//#define PORT_LCD PORTC
//#define PIN_LCD  PINC
#define DDR_LCD  DDRC

#define sclk   PTAD_PTAD3  
#define sda    PTAD_PTAD2 
#define cs     PTAD_PTAD5//Siempre en =0 si e maneja solo una LCD
#define rst    PTDD_PTDD2

// Non-port pins, which are connected to the conclusions LCD-controller
#define SCLK_LCD_PIN    3
#define SDA_LCD_PIN     2
#define CS_LCD_PIN      1
#define RST_LCD_PIN     0

// Apply a full set of characters. 
//#define FULL_CHARSET 

// *****!!!!! Minimum delay, which works with my LCD-controller
// *****!!!!! Chosen experimentally for a specific controller
#define NLCD_MIN_DELAY	34

//******************************************************************************
//******************************************************************************

// Macros, definitions, utility variables

#define SCLK_LCD_SET    PTAD_PTAD3 = 1   
#define SDA_LCD_SET     PTAD_PTAD2 = 1  
#define CS_LCD_SET      PTAD_PTAD5 = 1   
#define RST_LCD_SET     PTDD_PTDD2 = 1   

#define SCLK_LCD_RESET  PTAD_PTAD3 = 0   
#define SDA_LCD_RESET   PTAD_PTAD2 = 0   
#define CS_LCD_RESET    PTAD_PTAD5 = 0   
#define RST_LCD_RESET   PTDD_PTDD2 = 0   

#define CMD_LCD_MODE	0
#define DATA_LCD_MODE	1

#define PIXEL_ON	0
#define PIXEL_OFF	1
#define PIXEL_INV 	2

#define FILL_OFF	0
#define FILL_ON		1

#define INV_MODE_ON		0
#define INV_MODE_OFF	1

// Display resolution in pixels
#define NLCD_X_RES	96		// horizontal resolution
#define NLCD_Y_RES	68		// vertical resolution

#define f_wide 1
#define f_normal 0

// Framebuffer. Work through the buffer, as controller of the data can not be read NOKIA1100, and for
// graphics mode, we need to know the contents of video memory. (9 banks in 96 bytes)
static unsigned char nlcd_memory[NLCD_X_RES-1][(NLCD_Y_RES/8)+1];
											
// Tukuschie coordinates (pointers) in the video buffer
// nlcd_xcurr - in pixels, nlcd_ycurr-v Bank (Stroke)
static unsigned char nlcd_xcurr, nlcd_ycurr;

//******************************************************************************
// function Prototypes

void nlcd_Init(void);
void nlcd_Clear(void);
void nlcd_SendByte(char mode,unsigned char c);
void nlcd_Putc(unsigned char c);

void printBNUMB(unsigned char c);

void nlcd_PutcWide(unsigned char c);
void nlcd_Print(char *message);
void nlcd_PrintF (unsigned char *message,unsigned char wide);
void nlcd_PrintWide(unsigned char *message);

void nlcd_big_char(char chr);
void nlcd_big_str(char* str);

void nlcd_GotoX (char x);
void nlcd_GotoY (char y);
void nlcd_GotoXY(char x,char y);
void nlcd_GotoXY_pix(char x, char y);

void nlcd_Inverse(unsigned char mode);

void nlcd_Pixel (unsigned char x,unsigned char y, unsigned char pixel_mode);
void nlcd_Line  (unsigned char x1,unsigned char y1, unsigned char x2,unsigned char y2, unsigned char pixel_mode);
void nlcd_Circle(unsigned char x, unsigned char y, signed char radius, unsigned char fill, unsigned char pixel_mode);
void nlcd_Rect  (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, unsigned char pixel_mode);
void nlcd_Pict  (unsigned char x, unsigned char y, unsigned char * picture);
void delay_ms(unsigned int t);
void delay_us(unsigned int t);//retardo minimo de 23 us

void graph_NOKIA (unsigned char IMG[64][8]); 

#endif /* _NOKIA1100_LCD_LIB_H_ */
