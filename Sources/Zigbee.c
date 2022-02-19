/*
 * Zigbee.c
 *
 *  Created on: Jun 24, 2014
 *      Author: IvanD
 */


#include "Zigbee.h"

const char in[]="+++";
const char atdh[]="ATDH";
//const char xbee_port[20];
const char atdl[]="ATDL";
const char atwr[]="ATWR";
const char atni[]="ATNI";
const char atid[]="ATID";
const char atcn[]="ATCN";
const char atfr[]="ATFR";
const char atd7[]="ATD7=1";
const char atd72[]="ATD7";
const char atro[]="ATRO=20";

//------------------------------   RETARDO INTERRUPCION ------------------------------------------------
void miliseg_int(unsigned long t)
    {
    tiempo=0;
    while(tiempo<t){}
    }
//------------------------------     RETARDO   ------------------------------------------------
void miliseg(unsigned int t)  
    {
    int i,k;
    for(i=0;i<t;i++)
	    {
	    for(k=0;k<216;k++)
		    {
		    asm(nop); 
		    }
	    }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++ permite transmitir una cadena de caracteres por el puerto serie del Xbee +++++++

//++ cadena_tx_xbee ("cadena de caract entre comillas", modo: 0=enter/1=no enter); ++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cadena_tx_xbee (const char *st,byte modo)	
{    
	transmitString_Xbee(st);
	if (modo == 0)transmitByte(0x0D);
	//SCI1C2_RIE=1;   
}

//------------------------------------------------------------------------------------
void conf_zigbee(byte mode)
{
    unsigned short barrido1;
    byte dir1=0;
    if(mode==0)
	{
	cadena_tx_xbee(in,1);
	miliseg(500);
	if(xbee_port[0]=='O' && xbee_port[1]=='K')
	    {	
	    cadena_tx_xbee(atdh,1);
	    cadena_tx_xbee(address_H,0);
	    miliseg_int(100);//miliseg(500);			//OK
	
	    cadena_tx_xbee(atdl,1);
	    cadena_tx_xbee(address_L,0);
	    miliseg_int(100);//miliseg(500);			//OK
	
	    cadena_tx_xbee(atni,1);
	    cadena_tx_xbee(ni,0);
	    miliseg_int(100);// miliseg(500);			//OK
	
	    cadena_tx_xbee(atid,1);		
	    cadena_tx_xbee(id,0);
	    miliseg_int(100);//miliseg(500);			//OK
	    
	    cadena_tx_xbee(atwr,0);
	    miliseg(500);
	    cadena_tx_xbee(atcn,0);
	    miliseg_int(100);//miliseg(500);
	    }
	}
    if(mode==1)
	{
    
    miliseg_int(500);//miliseg(1000);
	cadena_tx_xbee(in,1);
	miliseg_int(100);//miliseg(400);
	if(xbee_port[0]=='O' && xbee_port[1]=='K')
	    {			
	    for (barrido1=0x8000;barrido1<0x8006;barrido1++)	
		    { 
		    address_H[dir1]= *(unsigned char*far)barrido1;
		    dir1++;
		    }		
	    cadena_tx_xbee(atdh,1);
	    cadena_tx_xbee(address_H,0);
	    miliseg_int(200);// miliseg(500);			//OK
	    dir1=0;
	    for (barrido1=0x8006;barrido1<0x800E;barrido1++)	
		    { 
		    address_L[dir1]= *(unsigned char*far)barrido1;
		    dir1++;
		    }		
	    cadena_tx_xbee(atdl,1);
	    cadena_tx_xbee(address_L,0);
	    miliseg_int(200);//miliseg(500);			//OK
	    dir1=0;
	    for (barrido1=0x800E;barrido1<0x8013;barrido1++)	
		    { 
		    ni[dir1]= *(unsigned char*far)barrido1;
		    dir1++;
		    }
	    cadena_tx_xbee(atni,1);
	    cadena_tx_xbee(ni,0);
	    miliseg_int(200);//miliseg(500);			//OK
	    dir1=0;
	    for (barrido1=0x8013;barrido1<0x8016;barrido1++)	
		    { 
		    id[dir1]= *(unsigned char*far)barrido1;
		    dir1++;
		    }	    
	    cadena_tx_xbee(atid,1);		
	    cadena_tx_xbee(id,0);
	    miliseg_int(200);// miliseg(500);			//OK	    
	    cadena_tx_xbee(atwr,0);
	    miliseg_int(200);//miliseg(500);
	    cadena_tx_xbee(atcn,0);
	    }
	}    
    if(mode==2)
	{
	cadena_tx_xbee(in,1);
	miliseg_int(200);//miliseg(500);
	//LED=1;
	miliseg_int(200);//miliseg(400);
	if(xbee_port[0]=='O' && xbee_port[1]=='K')
	    {	
	    cadena_tx_xbee(atd7,0);
	    miliseg_int(200);//miliseg(500);			//OK	    	    	   
	  
	    cadena_tx_xbee(atwr,0);
	    miliseg_int(200);//miliseg(500);
	    cadena_tx_xbee(atcn,0);
	    miliseg_int(200);//miliseg(500);
	    }
	}
    
 }
//------------------------------------------------------------------------------------
void lectura_zigbee(void)
    {
    cadena_tx_xbee(in,1);
    miliseg_int(200);// miliseg(500);
    //LED=1;
    miliseg_int(200);//miliseg(400);
    cadena_tx_xbee(atd72,0);
    //LED=0;
    miliseg_int(200);//miliseg(400);
    /*codigo en main para leer
    miliseg_int(800);
    lectura_zigbee();
    miliseg_int(250);*/
    }

void reset_zigbee(void)
    {
	cadena_tx_xbee(in,1);
	miliseg(500); //500
	//LED=1;
	miliseg(400);	//400
    cadena_tx_xbee(atfr,0);
    //LED=0;
    miliseg(500);			//OK
    cadena_tx_xbee(atcn,0);
	miliseg(500);    
    }
    
