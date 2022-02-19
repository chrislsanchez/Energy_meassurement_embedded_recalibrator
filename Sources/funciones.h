/*
 * funciones.h
 *  Created on: Dec 26, 2013
 *      Author: wilmer
 * FUNCTIONS USED : MCU_init
                    miliseg
                    cadena_tx_rs
                    cadena_tx_xbee                   
                    conf_DH
                    conf_DL
                    conf_NI
                    conf_ID
                    lectura_zigbee
                    conf_zigbee
                    medidores
                    rele_off_all
                    rele_on_all
                    error_data
                    rs_485_in    
                    RAM:1414 Bytes 
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//#include "constantes.h"
#include "string.h"
#include <mc9s08qe32.h>                /* I/O map for MC9S08QE32CLC */

#define	LED 			PTAD_PTAD5	// LED PCB
#define	EN_RS 			PTCD_PTCD5	// PIN DE HABILITACION PARA RECIBIR O ENVIAR RS-485

//---------------------------------- VARIABLES --------------------------------------------------
extern char puntero_menu;//variable del apuntador de los menus
extern unsigned int battery_level,battery_level_ant;//variables para guardar el porcentaje de carga de la bateria


extern char apertura_caja;
extern char disparo;
extern int ventana_modbus;
extern unsigned int ini_trama;
extern char error;	//int	+
extern char conteo,conteo1;

extern int barrido_datos,TX3,TX4;

extern char flag_recibido;	//int	+
extern unsigned int barrido_datos2,barrido_datos3;
extern unsigned short barrido_datos4,barrido_datos5;

extern char LOCK;
extern unsigned int secuencia;
extern unsigned short temp_crc;

extern char datos_medidoresX[39];

extern char num_medidores;
//extern char rs_out_485_read[250];
extern char rs_out_485_write[11];

extern char datos_medidor_buffer[81];	//201 +
//extern char save_medidores[246];			//borrarla con la matriz
extern char estado_rele[24];

extern unsigned char num_medidores_flash;					//*********	IMPORTANTE PARA EL BROADCAST Y SAVE DATA*************//

extern unsigned int Seconds;
extern unsigned int Minutes;
extern unsigned int Hours;

extern unsigned int Days;
extern unsigned int mes;
extern unsigned int ano;

extern unsigned long int T1;
extern unsigned long int temp1;  //long int
extern unsigned long int valor,adc;	
extern unsigned long int prom1;	

extern unsigned char xbee_port[20],i;
extern unsigned char xbee_port_sin_CRC[6];
extern unsigned char CRC_recibido[2];

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//variables de la funcion valores_medidores

extern long wh;// KW/h
extern long whr;//KVAR/h
extern int tension_dato;//voltaje
extern int corriente_dato;//corriente
extern int kw_dato;// KW instantanea
extern int kwr_dato;
extern int hz;//frecuencia
extern int factor_dato;//factor de potencia

//#define	LED 			PTAD_PTAD5	// LED PCB
//#define	EN_RS 			PTCD_PTCD5	// PIN DE HABILITACION PARA RECIBIR O ENVIAR RS-485
/*
#define	BUTTON 			PTAD_PTAD2	// PULSADOR CAJA MAESTRA
#define	BUTTON2 		PTAD_PTAD1	// PULSADOR CAJA ESCLAVA
#define	JUMPER 			PTCD_PTCD5	// JUMPER SETTING
#define	TPAD 			PTCD_PTCD3	// TEST PAD
*/
//----------------------------------------------------------------------------------------------

//-----------------LECTURA-----------
extern unsigned char broadcast[8];

//----------------------------------------------------------------------------------------------------------
extern unsigned char medidor0_rele_off[8];
extern unsigned char medidor1_rele_off[8];
extern unsigned char medidor2_rele_off[8];
extern unsigned char medidor3_rele_off[8];
extern unsigned char medidor4_rele_off[8];
extern unsigned char medidor5_rele_off[8];

extern unsigned char medidor6_rele_off[8];
extern unsigned char medidor7_rele_off[8];
extern unsigned char medidor8_rele_off[8];
extern unsigned char medidor9_rele_off[8];
extern unsigned char medidor10_rele_off[8];
extern unsigned char medidor11_rele_off[8];

extern unsigned char medidor12_rele_off[8];
extern unsigned char medidor13_rele_off[8];
extern unsigned char medidor14_rele_off[8];
extern unsigned char medidor15_rele_off[8];
extern unsigned char medidor16_rele_off[8];
extern unsigned char medidor17_rele_off[8];

//extern unsigned char medidor18_rele_off[9]={0x13,0x6,0x0,0x0C,0x0,0x0,0x4A,0xBB};	//No utlizar
extern unsigned char medidor18_rele_off[8];
extern unsigned char medidor19_rele_off[8];
extern unsigned char medidor20_rele_off[8];
extern unsigned char medidor21_rele_off[8];
extern unsigned char medidor22_rele_off[8];
extern unsigned char medidor23_rele_off[8];

extern unsigned char medidor24_rele_off[8];
extern unsigned char medidor25_rele_off[8];
extern unsigned char medidor26_rele_off[8];
extern unsigned char medidor27_rele_off[8];
extern unsigned char medidor28_rele_off[8];
extern unsigned char medidor29_rele_off[8];

//----------------------------------------------------------------------------------------------------------
extern unsigned char medidor0_rele_on[8];
extern unsigned char medidor1_rele_on[8];
extern unsigned char medidor2_rele_on[8];
extern unsigned char medidor3_rele_on[8];
extern unsigned char medidor4_rele_on[8];
extern unsigned char medidor5_rele_on[8];

extern unsigned char medidor6_rele_on[8];
extern unsigned char medidor7_rele_on[8];
extern unsigned char medidor8_rele_on[8];
extern unsigned char medidor9_rele_on[8];
extern unsigned char medidor10_rele_on[8];
extern unsigned char medidor11_rele_on[8];

extern unsigned char medidor12_rele_on[8];
extern unsigned char medidor13_rele_on[8];
extern unsigned char medidor14_rele_on[8];
extern unsigned char medidor15_rele_on[8];
extern unsigned char medidor16_rele_on[8];
extern unsigned char medidor17_rele_on[8];

//extern unsigned char medidor18_rele_on[9]={0x13,0x6,0x0,0x0C,0x0,0x1,0x8B,0x7B};	//NO UTILIZAR
extern unsigned char medidor18_rele_on[8];
extern unsigned char medidor19_rele_on[8];
extern unsigned char medidor20_rele_on[8];
extern unsigned char medidor21_rele_on[8];
extern unsigned char medidor22_rele_on[8];
extern unsigned char medidor23_rele_on[8];

extern unsigned char medidor24_rele_on[8];
extern unsigned char medidor25_rele_on[8];
extern unsigned char medidor26_rele_on[8];
extern unsigned char medidor27_rele_on[8];
extern unsigned char medidor28_rele_on[8];
extern unsigned char medidor29_rele_on[8];

/*
 * FUNCIONES DE LA LIBRERIA
 * */
void get_battery_level(void);
void cadena_tx_rs (const char *str, char len);
void ventana(void);
char medidores(unsigned int numero);
void valores_medidores(void);//funcion para obtener los datos de los medidores
unsigned short CRC16(unsigned char *Data, unsigned short Length);
void rele_on_medidor(int num_medidor);
void rele_off_medidor(int num_medidor);
void rele_on_all(void);
void rele_off_all(void);
void error_data(unsigned int number);
void rs_485_out_write(unsigned char registro,unsigned char estado);
void rs_485_in(void);
void sensado(void);

#endif /* FUNCIONES_H_ */
