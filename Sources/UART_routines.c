//**************************************************************
//******** FUNCTIONS FOR SERIAL COMMUNICATION USING UART *******
//**************************************************************
//Controller		: ATmega32 (Clock: 8 Mhz-internal)
//Compiler			: AVR-GCC (winAVR with AVRStudio-4)
//Project Version	: DL_1.0
//Author			: CC Dharmani, Chennai (India)
//			  		  www.dharmanitech.com
//Date				: 10 May 2011
//**************************************************************

#include <mc9s08qe32.h>                  /* I/O map  */
#include "UART_routines.h"

//**************************************************
//UART0 initialize
//baud rate: 19200  (for controller clock = 8MHz)
//char size: 8 bit
//parity: Disabled
//**************************************************
void uart0_init(void)
{
/*	
 UCSRB = 0x00; //disable while setting baud rate
 UCSRA = 0x00;
 UCSRC = (1 << URSEL) | 0x06;
 UBRRL = 0x19; //set baud rate lo
 UBRRH = 0x00; //set baud rate hi
 UCSRB = 0x18;
 */
}

//**************************************************
//Function to receive a single byte
//*************************************************
/*
unsigned char receiveByte( void )
{
	unsigned char data, status;
	
	while(!(UCSRA & (1<<RXC))); 	// Wait for incomming data
	
	status = UCSRA;
	data = UDR;
	
	return(data);
	
}

*/
//***************************************************
//Function to transmit a single byte
//***************************************************
void transmitByte( unsigned char data )
{
	SCI1D=data;             /* Start transmition */
	while (!SCI1S1_TC){}    /* Wait for empty transmit buffer */
}

//***************************************************
//Function to transmit hex format data
//first argument indicates type: CHAR, INT or LONG
//Second argument is the data to be displayed
//***************************************************
void transmitHex( unsigned char dataType, unsigned long data )
{
	unsigned char count, i, temp;
	char dataString[] = "0x        ";
	//char dataString[] = "0x        ";

	if (dataType == CHAR) count = 2;
	if (dataType == INT) count = 4;
	if (dataType == LONG) count = 8;

	for(i=count; i>0; i--)
	{
	  temp =(unsigned char)data % 16;
	  if((temp>=0) && (temp<10)) dataString [i+1] = (char)(temp + 0x30);
	  else dataString [i+1] = (char)((temp - 10) + 0x41);

	  data = data/16;
	}

	transmitString (dataString);
}

//***************************************************
//Function to transmit a string in Flash
//***************************************************
void transmitString_Xbee(const char* string)
{
  // while (pgm_read_byte(&(*string)))
  // transmitByte(pgm_read_byte(&(*string++)));
	 while (*string)transmitByte(*string++);
}

//***************************************************
//Function to transmit a string in RAM
//***************************************************
//void transmitString(unsigned char* string)
void transmitString(char* string)
{
  while (*string) transmitByte(*string++);
}

//************ END ***** www.dharmanitech.com *******
