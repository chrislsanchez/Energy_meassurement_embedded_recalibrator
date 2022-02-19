/*
 * Zigbee.h
 *
 *  Created on: Dec 17, 2013
 *      Author: wilmer
 *      
 *      FUNCTIONS USED :    
			miliseg
			cadena_tx_xbee
			lectura_zigbee
			conf_zigbee  
			RAM:48 Bytes    
 */
#ifndef ZIGBEE_H_
#define ZIGBEE_H_

#include "derivative.h"
#include "UART_routines.h"

//static unsigned char xbee_port[10];
extern unsigned char xbee_port[20];
static unsigned int tiempo;
static const char ok[]="OK";
//-----------------------------------------------------------------------------------------------------------

//--------------------------------------- VALORES DE CONFIGURACION ZIGBEE ---------------------------------------------
static char address_H[7]="13A200";	//13A200
static char address_L[9]="40A206EB";//"40A2070F";	//40A2070F-Ivan   402D659B-Raul-Xstream   40A20710-Beagle
static char ni[6]="CAJA1";			//CAJA
static char id[4]="123";			//123


void miliseg_int(unsigned long t);
void miliseg(unsigned int t);
void cadena_tx_xbee (const char *st,byte modo);	
void conf_zigbee(byte mode);
void lectura_zigbee(void);
void reset_zigbee(void);


#endif /* ZIGBEE_H_ */
