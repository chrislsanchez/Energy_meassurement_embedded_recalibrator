//***************************************************************************
//  File........: nokia1100_lcd_lib.c
//  Author(s)...: Chiper
//  URL(s)......: http://digitalchip.ru/
//  Device(s)...: ATMega...
//  Compiler....: AVR-GCC
//  Description.: LCD-controller driver from Nokia1100 with graphic functions
//  Data........: 28.03.12
//  Version.....: 2.1
//***************************************************************************
//  Notice: All control contacts LCD-controller must be connected to 
// To the same port on the microcontroller
//***************************************************************************


#include "nokia1100_lcd_lib.h"

//******************************************************************************
// Macros, definitions, utility variables
// Macros to work with bats
#define ClearBit(reg, bit)       reg &= (~(1<<(bit)))
#define SetBit(reg, bit)         reg |= (1<<(bit))	
#define InvBit(reg, bit)         reg ^= 1<<bit	

//******************************************************************************
// initialization kontrollera
void nlcd_Init(void)
{	
	// Initialize the port to output for use with LCD-controller
	//DDR_LCD |= (1<<SCLK_LCD_PIN)|(1<<SDA_LCD_PIN)|(1<<CS_LCD_PIN)|(1<<RST_LCD_PIN);
	CS_LCD_RESET;
	RST_LCD_RESET;

	delay_ms(30);            // waiting at least 5ms to install generator (less than 5 ms can broken)

	RST_LCD_SET;

	nlcd_SendByte(CMD_LCD_MODE,0xE2); // *** SOFTWARE RESET 

	nlcd_SendByte(CMD_LCD_MODE,0x3A); // *** Use internal oscillator
	nlcd_SendByte(CMD_LCD_MODE,0xEF); // *** FRAME FREQUENCY:
	nlcd_SendByte(CMD_LCD_MODE,0x04); // *** 80Hz
	nlcd_SendByte(CMD_LCD_MODE,0xD0); // *** 1:65 divider
	
	
	//nlcd_SendByte(CMD_LCD_MODE,0x20); // Write to Vop
	nlcd_SendByte(CMD_LCD_MODE,0x90); // EV to adjust the lcd contrast  0x80 to 0x9F  31 Steps   (0x90 default)

	nlcd_SendByte(CMD_LCD_MODE,0xA4); // all on/normal display

	nlcd_SendByte(CMD_LCD_MODE,0x2F); // Power control set(charge pump on/off)
									  // Specifies the contrast

	nlcd_SendByte(CMD_LCD_MODE,0x40); // set start row address = 0
	nlcd_SendByte(CMD_LCD_MODE,0xB0); // set the Y-address = 0
	nlcd_SendByte(CMD_LCD_MODE,0x10); // install X-address, senior 3 bits
	nlcd_SendByte(CMD_LCD_MODE,0x00);  // install X-address, the lower 4 bits
	
	//nlcd_SendByte(CMD_LCD_MODE,0xC8); // mirror Y axis (about X axis)
	//nlcd_SendByte(CMD_LCD_MODE,0xA1); // Invert the screen horizontally

	nlcd_SendByte(CMD_LCD_MODE,0xAC); // set initial row (R0) of the display
	nlcd_SendByte(CMD_LCD_MODE,0x07);

	//nlcd_SendByte(CMD_LCD_MODE,0xF9); //

	/*
	//Inicializacion CHRISTIAN
	nlcd_SendByte(CMD_LCD_MODE,0x20);
	nlcd_SendByte(CMD_LCD_MODE,0x80);
	nlcd_SendByte(CMD_LCD_MODE,0xA4);
	nlcd_SendByte(CMD_LCD_MODE,0x2F);
	nlcd_SendByte(CMD_LCD_MODE,0x40);
	nlcd_SendByte(CMD_LCD_MODE,0xC8);
	nlcd_SendByte(CMD_LCD_MODE,0xA0);
	nlcd_SendByte(CMD_LCD_MODE,0xF8);
	nlcd_SendByte(CMD_LCD_MODE,0xA6);
	nlcd_SendByte(CMD_LCD_MODE,0xAF);
	*/
	
	
	nlcd_SendByte(CMD_LCD_MODE,0xAF); // Screen on / off

	nlcd_Clear(); // clear LCD
}

//******************************************************************************
// Cleaning the screen
void nlcd_Clear(void)
{
	unsigned int i;
	/*
	nlcd_SendByte(CMD_LCD_MODE,0x40); // Y = 0
	nlcd_SendByte(CMD_LCD_MODE,0xB0);
	nlcd_SendByte(CMD_LCD_MODE,0x10); // X = 0
	nlcd_SendByte(CMD_LCD_MODE,0x00);
	*/
	nlcd_SendByte(CMD_LCD_MODE,0x00);
	nlcd_SendByte(CMD_LCD_MODE,0xB0);
	nlcd_SendByte(CMD_LCD_MODE,0x10); // X = 0
	
	
	nlcd_xcurr=0; nlcd_ycurr=0;		  // Is set to 0 in the current coordinates of video buffer

	//nlcd_SendByte(CMD_LCD_MODE,0xAE); // disable display;
	
	for(i=0;i<864;i++)nlcd_SendByte(DATA_LCD_MODE,0x00);
	
	//nlcd_SendByte(CMD_LCD_MODE,0x07);
	//nlcd_SendByte(CMD_LCD_MODE,0xAF); // enable display;
}


//******************************************************************************
// Transfer bytes (teams or data) on the LCD Controller 
// Mode: CMD_LCD_MODE - peredaem command 
// DATA_LCD_MODE - peredaem data 
// C: value peredavaemogo bytes
void nlcd_SendByte(char mode,unsigned char c)
{
	unsigned char i;
	//CS_LCD_RESET;
    SCLK_LCD_RESET;

	if (mode) 				// DATA_LCD_MODE
	{
		nlcd_memory[nlcd_xcurr][nlcd_ycurr] = c;	// Write the bath to the video buffer
	    nlcd_xcurr++;								// Update the coordinates in the video buffer
		
		if (nlcd_xcurr>95){
			nlcd_xcurr = 0;
			nlcd_ycurr++;
		}
        if (nlcd_ycurr>8) nlcd_ycurr = 0;			

        SDA_LCD_SET;								// Transfer byte to LCD-controller
	}
	else SDA_LCD_RESET;	// CMD_LCD_MODE

    SCLK_LCD_SET;
   
   // unsigned char i;
    for(i=0;i<8;i++){
    	SCLK_LCD_RESET;

        if(c & 0x80) SDA_LCD_SET;
        else	     SDA_LCD_RESET;

        SCLK_LCD_SET;
        c <<= 1;

		//ID_delay_us(NLCD_MIN_DELAY);	// *****!!!!! 34 - Minimum delay, which works with my LCD-controller
    }	

   // CS_LCD_SET;
}

//******************************************************************************
// Output symbol on LCD-screen NOKIA 1100 at the current location
//  c: in characters
void nlcd_Putc(unsigned char c)
{
	unsigned char i,a,aa;
	if (c == 'I'||c == 'i'||c =='l'){a = 1; aa = 4;}
	else {a = 0;aa = 5;}
	
	if (c>127) c=c-64; 	// Portable Cyrillic characters in CP1251 encoding to start the second
	     				// Half of the ASCII table (starting with code 0x80)
	for ( i = a; i < aa; i++ ){
  //nlcd_SendByte(DATA_LCD_MODE,pgm_read_byte(&(nlcd_Font[c-32][i])));}
	nlcd_SendByte(DATA_LCD_MODE,nlcd_Font[c-32][i]);
	}
    
	nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between the characters horizontally 1 pixel
}

//******************************************************************************
// Print a wide character LCD- screen NOKIA 1100 at the current location
// C: character code
void nlcd_PutcWide (unsigned char c)
{
	unsigned char i,a,aa;
	if (c == 'I'||c == 'i'||c =='l'){a = 1; aa = 4;}
	else {a = 0;aa = 5;}

	if (c> 127 ) c = c- 64;					// Transferring Cyrillic characters in CP1251 encoding in the beginning of the second
     									// Half of the table ASCII ( since code 0x80)
	for (i = a;i<aa ; i++){
	unsigned char glyph = (nlcd_Font [c- 32 ][i]);
	nlcd_SendByte (DATA_LCD_MODE,glyph);
	nlcd_SendByte (DATA_LCD_MODE,glyph);
	}

//if (c == 'I'||c == 'i'||c =='l'){}
nlcd_SendByte (DATA_LCD_MODE, 0x00);
//else nlcd_SendByte (DATA_LCD_MODE, 0x00); // The gap between characters horizontally 1 pixel
									 // Nlcd_SendByte (DATA_LCD_MODE, 0x00); // You can make two lines
}



//******************************************************************************
// Output symbol on LCD-screen NOKIA 1100 at the current location
//  c: in characters
void printBNUMB(unsigned char c)
{
	unsigned char i;
	
	if (c>127) c = c - 64; 	// Portable Cyrillic characters in CP1251 encoding to start the second
	     				    // Half of the ASCII table (starting with code 0x80)
	for ( i = 0; i < 14; i++ ){
  	nlcd_SendByte(DATA_LCD_MODE,BigNumbers[c-0x27][i]);
	}
    nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between the characters horizontally 1 pixel
}


// ******************************************************************************
// Display Big characters on LCD- screen NOKIA 1100 at the current location
// From memory . If the string is out of the screen in the current row , the remainder
// On the next line .

//void lcd_big_char(char col, char row, char chr)
void nlcd_big_char(char chr)
{
	// uint8_t* f0 = fnt_terminus_24x14_bits + (chr-'0')*14*(24/8);
	// char f0 = fnt_libera_24x14_bits[(chr-0x30)*42];  //[(chr-'0')*14*(24/8)];
    // char f0 = (chr-0x2D)*42;  //[(chr-'0')*14*(24/8)];
    // char f;
	char col = nlcd_xcurr; 
	char row = nlcd_ycurr; 
    char r, c;
    for(r = 0; r<3; r++)
    {
       // f = f0 + (14*r);
        nlcd_GotoXY(col,row+r);
        for(c = 0+(14*r); c<14*(r+1); c++)
        {
        	
        	// char b = f;
            // if(lcd_flags.inverse_char) b = ~ b;
            // lcd_write_byte(b, 1);
            // nlcd_SendByte(DATA_LCD_MODE,fnt_libera_24x14_bits[b+c]);
        	nlcd_SendByte(DATA_LCD_MODE,BigNumbers[chr-0x2D][c]);
            
          //  f += 3;
        }
    }
    nlcd_GotoY(row);
    //nlcd_SendByte(DATA_LCD_MODE,0x00); // The gap between the characters horizontally 1 pixel
}
void nlcd_big_str(char* str)
{
  /*  char c;
    while((c = *str++) != 0)
    {
        lcd_big_char(c);
       // col += fnt_libera_24x14_width;
       // if(col >= lcdWidth()) return;
    }*/
    
    while(*str)nlcd_big_char(*str++);
    
}




// ************************************************ ******************************
// Display the string of characters on the LCD- screen NOKIA 1100 at the current location . If the string comes
// Screen for the current line , the remainder on the next line .
// Message: a pointer to a character string . 0x00 - a line terminator.
void nlcd_Print (char *message)
{
while (*message) nlcd_Putc (*message ++); // End of line denotes zero
}

// ************************************************ ******************************
// Display the string of characters on the LCD- screen NOKIA 1100 at the current location of the program memory.
// If the string is out of the screen in the current row , the remainder on the next line .
// Message: a pointer to a string in program memory. 0x00 - a line terminator .
void nlcd_PrintF (unsigned char *message,unsigned char wide)
{
	//void lcd_string(char *string){
	if(wide)  while(*message)nlcd_PutcWide(*message++);
	else while(*message)nlcd_Putc(*message++);
	
	     // lcd_character(*string++);
	//}
	
			/*	unsigned char data;
				while (data = pgm_read_byte (message), data)
				{
				nlcd_Putc (data);
				message ++;
				}*/
}


// ************************************************ ******************************
// Display the string of characters double width on LCD- screen NOKIA 1100 at the current location
// From memory . If the string is out of the screen in the current row , the remainder
// On the next line .
// Message: a pointer to a string in program memory. 0x00 - a line terminator .
void nlcd_PrintWide (unsigned char *message)
{
while (*message) nlcd_PutcWide (*message ++); // End of line denotes zero
}



// ************************************************ ******************************
// Sets the cursor to the desired position . Counting begins at the top
// Left corner. 16 character horizontally , vertically - 8
// X: 0 .. 15
void nlcd_GotoX (char x)
{
//x = x * 6 ; // Move from familiarity coordinates to the coordinates in pixels

nlcd_xcurr = x;

nlcd_SendByte (CMD_LCD_MODE, (0x10 | ((x >> 4 ) & 0x07))); // Set the addresses for X: 0010 0xxx - bits (x6 x5 x4)
nlcd_SendByte (CMD_LCD_MODE, (0x00 | (x & 0x0F)));         // Set the addresses for X: 0000 xxxx - bits (x3 x2 x1 x0)

}

// ************************************************ ******************************
// Sets the cursor to the desired position . Counting begins at the top
// Left corner. 16 character horizontally , vertically - 8
// Y: 0 .. 7
void nlcd_GotoY (char y)
{
//x = x * 6 ; // Move from familiarity coordinates to the coordinates in pixels

nlcd_ycurr = y;

nlcd_SendByte (CMD_LCD_MODE, (0xB0 | (y & 0x0F))); // Set the addresses for Y: 0100 yyyy

}




// ************************************************ ******************************
// Sets the cursor to the desired position . Counting begins at the top
// Left corner. 16 character horizontally , vertically - 8
// X: 0 .. 15
// Y: 0 .. 7
void nlcd_GotoXY (char x, char y)
{
//x = x * 6 ; // Move from familiarity coordinates to the coordinates in pixels

nlcd_xcurr = x;
nlcd_ycurr = y;

nlcd_SendByte (CMD_LCD_MODE, (0x10 | ((x >> 4 ) & 0x07))); // Set the addresses for X: 0010 0xxx - bits (x6 x5 x4)
nlcd_SendByte (CMD_LCD_MODE, (0x00 | (x & 0x0F))); // Set the addresses for X: 0000 xxxx - bits (x3 x2 x1 x0)
nlcd_SendByte (CMD_LCD_MODE, (0xB0 | (y & 0x0F))); // Set the addresses for Y: 0100 yyyy


}

// ************************************************ ******************************
// Ustanavlivaer inversion mode the whole screen . Data on the screen does not change , only inverted
// Mode: INV_MODE_ON or INV_MODE_OFF
void nlcd_Inverse (unsigned char mode)
{
if (mode) nlcd_SendByte (CMD_LCD_MODE, 0xA6);
else nlcd_SendByte (CMD_LCD_MODE, 0xA7);
}


// ************************************************ ******************************
// Sets the cursor in pixels. Counting begins at the top
// Left corner. 96 pixels horizontally , vertically - 65
// X: 0 .. 95
// Y: 0 .. 64

void nlcd_GotoXY_pix(unsigned char x, unsigned char y)
{
nlcd_xcurr = x;
//y=y+6;//					IMPORTANTE CORRECCION OFFSET DE ALGUNAS LCDS
nlcd_ycurr = (unsigned char)(y/8);

nlcd_SendByte (CMD_LCD_MODE, (0xB0 | (nlcd_ycurr & 0x0F))); // Set the addresses for Y: 0100 yyyy
nlcd_SendByte (CMD_LCD_MODE, (0x00 | (x & 0x0F)));          // Set the addresses for X: 0000 xxxx - bits (x3 x2 x1 x0)
nlcd_SendByte (CMD_LCD_MODE, (0x10 | ((x >> 4 ) & 0x07)));  // Set the addresses for X: 0010 0xxx - bits (x6 x5 x4)
}


// ************************************************ ******************************
// Output points on the LCD- screen NOKIA 1100
// X: 0 .. 95 horizontal coordinate (starting from the upper left corner )
// Y: 0 .. 64 vertical coordinate
// Pixel_mode: PIXEL_ON - for inclusion pikskela
// PIXEL_OFF - to turn off the pixel
// PIXEL_INV - to invert the pixel
void nlcd_Pixel (unsigned char x, unsigned char y, unsigned char pixel_mode)
{
unsigned char temp;

nlcd_GotoXY_pix (x, y);
temp = nlcd_memory [nlcd_xcurr] [nlcd_ycurr];

switch (pixel_mode)
{
case PIXEL_ON:
	SetBit (temp, y% 8);   // Include the pixel
	break;
case PIXEL_OFF:
	ClearBit (temp, y% 8); // Turn off the pixel
	break;
case PIXEL_INV:
	InvBit (temp, y% 8);   // Invert the pixel
	break;
}

nlcd_memory [nlcd_xcurr] [nlcd_ycurr] = temp; // Transfer bytes video buffer
nlcd_SendByte (DATA_LCD_MODE, temp); // Bytes transferred to the controller
}

// ************************************************ ******************************
// Output lines on the LCD- screen NOKIA 1100
// X1, x2: 0 .. 95 horizontal coordinate (starting from the upper left corner )
// Y1, y2: 0 .. 64 vertical coordinate
// Pixel_mode: PIXEL_ON - for inclusion pikskela
// PIXEL_OFF - to turn off the pixel
// PIXEL_INV - to invert the pixel
void nlcd_Line (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char pixel_mode)
{
int dy, dx;
signed char addx = 1 , addy = 1 ;
signed int P, diff;

unsigned char i = 0 ;

dx = abs ((signed char) (x2 - x1));
dy = abs ((signed char) (y2 - y1));

if (x1> x2) addx = -1;
if (y1> y2) addy = -1;

	if (dx >= dy)
	{
		dy *= 2 ;
		P = dy - dx;
		
		diff = P - dx;
		
		for (; i <= dx; ++i)
		{
			nlcd_Pixel (x1, y1, pixel_mode);
			
			if (P < 0)
			{
				P += dy;
				x1 += addx;
			}
			else
			{
				P += diff;
				x1 += addx;
				y1 += addy;
		    }
		}
	}
	else
	{
	dx *= 2 ;
	P = dx - dy;
	diff = P - dy;
	
		for (; i <= dy; ++i)
		{
		nlcd_Pixel (x1, y1, pixel_mode);
		
			if (P < 0)
			{
				P += dx;
				y1 += addy;
			}
			else
			{
				P += diff;
				x1 += addx;
				y1 += addy;
			}
		}
	}
}


// ************************************************ ******************************
// Display LCD- circle on the screen NOKIA 1100
// X: 0 .. 95 coordinates of the center of the circle (starting from the upper left corner )
// Y: 0 .. 64 vertical coordinate
// Radius: radius of the circle
// Fill: FILL_OFF - Unfilled circle
// FILL_ON - Filled
// Pixel_mode: PIXEL_ON - for inclusion pikskela
// PIXEL_OFF - to turn off the pixel
// PIXEL_INV - to invert the pixel

//void nlcd_Circle (unsigned char x, unsigned char y, unsigned char radius, unsigned char fill, unsigned char pixel_mode)

void nlcd_Circle (unsigned char x, unsigned char y, signed char radius, unsigned char fill, unsigned char pixel_mode)
{
	signed char a, b, P;
	
	a = 0 ;
	b = radius;
	P = 1-radius;

	   do
	   {
			if(fill)
			{
				nlcd_Line (x-a, y + b, x + a, y + b, pixel_mode);
				nlcd_Line (x-a, y-b, x + a, y-b, pixel_mode);
				nlcd_Line (x-b, y + a, x + b, y + a, pixel_mode);
				nlcd_Line (x-b, y-a, x + b, y-a, pixel_mode);
			}
			else
			{
				nlcd_Pixel (a + x, b + y, pixel_mode);
				nlcd_Pixel (b + x, a + y, pixel_mode);
				nlcd_Pixel (x-a, b + y, pixel_mode);
				nlcd_Pixel (x-b, a + y, pixel_mode);
				nlcd_Pixel (b + x, y-a, pixel_mode);
				nlcd_Pixel (a + x, y-b, pixel_mode);
				nlcd_Pixel (x-a, y-b, pixel_mode);
				nlcd_Pixel (x-b, y-a, pixel_mode);
			}
		
			if (P < 0 ) P += 3 + 2 * a ++;
			else P += 5 + 2 * (a ++ - b --);
		}while(a <= b);
}



// ************************************************ ******************************
// Display LCD- circle on the screen NOKIA 1100
// X1, x2: 0 .. 95 horizontal coordinate (starting from the upper left corner )
// Y1, y2: 0 .. 64 vertical coordinate
// Pixel_mode: PIXEL_ON - for inclusion pikskela
// PIXEL_OFF - to turn off the pixel
// PIXEL_INV - to invert the pixel
void nlcd_Rect (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, unsigned char pixel_mode)
{
	if (fill)
	{// Filled
		unsigned char i, xmin, xmax, ymin, ymax;
		
		if (x1 <x2) {xmin = x1; xmax = x2; } // Determine the minimum and maximum X coordinate of
		else {xmin = x2; xmax = x1; }
		
		if (y1 <y2) {ymin = y1; ymax = y2; } // Determine the minimum and maximum Y coordinate of
		else {ymin = y2; ymax = y1; }
		
		for (; xmin <= xmax; ++ xmin)
		{
		for (i = ymin; i <= ymax; ++ i) nlcd_Pixel (xmin, i, pixel_mode);
		}
	}
	else // No Fill
	{
		nlcd_Line (x1, y1, x2, y1, pixel_mode); // Draw the side pryamougolinika
		nlcd_Line (x1, y2, x2, y2, pixel_mode);
		nlcd_Line (x1, y1 +1, x1, y2- 1 , pixel_mode);
		nlcd_Line (x2, y1 +1, x2, y2- 1 , pixel_mode);
	}
}


// ************************************************ ******************************
// Display the pictures on the LCD- screen NOKIA 1100
// X: 0 .. 95 coordinate of the upper left corner of the horizontal (starting from the upper left corner of the screen )
// Y: 0 .. 64 of the upper -left corner coordinates in the vertical
// Picture: a pointer to an array of monochrome picture , the first 2 bytes indicate respectively
// Size of the image horizontally and vertically
/*void nlcd_Pict (unsigned char x, unsigned char y, unsigned char *picture)
{
unsigned char pict_width = pgm_read_byte (& picture [ 0]);      // Width in pixels of the sprite
unsigned char pict_height = pgm_read_byte (& picture [ 1]);     // Height of the sprite in pixels
unsigned char pict_height_bank = pict_height / 8 + ((pict_height % 8) > 0 ? 1:0) ; // Height of the sprite in banks
unsigned char y_pos_in_bank = y / 8 + ((y % 8) > 0 ? 1:0) ;     // Y position of banks ( lines 8 pixels).

int adr = 2 ; // Index of the current byte array with image
  unsigned char i ;
	for (i = 0 ; i < pict_height_bank; i ++)
	{ // Pass lines ( for banks )
	
		if (i <((NLCD_Y_RES / 8 ) +1) ) // do not display an image outside the screen
		{
		// positioning on a new line
		nlcd_xcurr = x;
		nlcd_ycurr = y_pos_in_bank + i;
		
		nlcd_SendByte (CMD_LCD_MODE, (0xB0 | ((y_pos_in_bank + i) & 0x0F))); // Set the addresses for Y: 0100 yyyy
		nlcd_SendByte (CMD_LCD_MODE, (0x00 | (x & 0x0F))); // Set the addresses for X: 0000 xxxx - bits (x3 x2 x1 x0)
		nlcd_SendByte (CMD_LCD_MODE, (0x10 | ((x >> 4 ) & 0x07))); // Set the addresses for X: 0010 0xxx - bits (x6 x5 x4)
		
			// output lines
		  unsigned char j;
			for (j = 0 ; j <pict_width; j ++)
			{
				if ((x + j) <NLCD_X_RES) nlcd_SendByte (DATA_LCD_MODE, pgm_read_byte (& (picture [adr]))); // Do not display an image outside the screen
				adr ++;
			}
		}
	}
}*/


void delay_ms(unsigned int t){
	unsigned int tt;
	for(tt = 0; tt < t; tt++){
	TPM1CNT = 0;
	while(TPM1CNT < 4335){}
    }
}


void delay_us(unsigned int t){
	unsigned int tt;
	for(tt = 0; tt < t; tt++){
	TPM1CNT = 0;
	while(TPM1CNT < 2){}
    }
}




void graph_NOKIA (unsigned char IMG[64][8]) 
	{
	static unsigned char puntero,dato_graph,nn,by,row,col;
	for(row=0;row<64;row++)
		{
		puntero=0;
		for(col=0;col<8;col++)
			{
			dato_graph=0x00;
			by=0x80;
			for(nn=0;nn<8;nn++)
				{
				dato_graph=0x00;
				dato_graph=IMG[row][col] & by;
				if(dato_graph!=0)
					{
					nlcd_Pixel(nn+puntero+16,row,0);
					}
				by=by>>1;
				}			
			puntero+=8;
			}
		}
	}




