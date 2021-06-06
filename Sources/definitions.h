#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define	LED_TEST	PTAD_PTAD1

/*=====================================================================*/
//================ global variables ===================================//
 char teclita;
 char puntero_menu;//variable para configuracion de menus y sub menus
 unsigned int battery_level,battery_level_ant;//variables para guardar el porcentaje de carga de la bateria

 unsigned char xbee_port[20];
 char tx_vec[10];//variable para funcion itoa
 
 /*		VARIABLES EXTERNAS MCUinit.C		*/
 char buffer_opcion_teclado[10]=0;
 char fp_te,kk;//apuntador para buffer
 int retorno_teclado;//variable para almacenar los valores del teclado
 int error_menu;//variable de retorno para error cuando necesito retornar de una funcion al menu principal
char EM;//variable para almacenar el estado de los medidores, retorno funcion medidores en libreria funciones
 
 
 /*++++++++++++++++++++++++++++++++++++
  * VARIABLES DE LA LIBRERIA FUNCIONES
  * */
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//variables de la funcion valores_medidores
/*
union wh{
			unsigned char original_wh[4];
			unsigned short wh;
			}uno;

union whr{
			unsigned char original_whr[4];
			unsigned short whr;
			}dos;

union tension_dato{
					unsigned char original_tension[4];
					unsigned short tensionl;
					}tres;
					
union corriente_dato{
						unsigned char original_corriente[4];
						unsigned short corriente;
						}cuatro;
	
union kw_dato{
				unsigned char original_kw[4];
				unsigned short kw;
				}cinco;
				
union kwr_dato{
				unsigned char original_kwr[4];
				unsigned short kwr;
				}seis;
				
union hz{
		unsigned char original_hz[4];
		unsigned short hz;
		}siete;
		
union factor_dato{
				unsigned char original_factor[4];
				unsigned short factor;
				}ocho;
*/
long wh;// KW/h
long whr;//KVAR/h
int tension_dato;//voltaje
int corriente_dato;//corriente
int kw_dato;// KW instantanea
int kwr_dato;
int hz;//frecuencia
int factor_dato;//factor de potencia


				
				

				
						

 //++++++++++++++++++++++++++++++++++++++++++++++++++
 char apertura_caja=1;
 char disparo=0;
 int ventana_modbus;
 unsigned int ini_trama=0;
 char error=0;	//int	+
 char conteo,conteo1;

 int barrido_datos,TX3,TX4;

 char flag_recibido;	//int	+
 unsigned int barrido_datos2,barrido_datos3;
 unsigned short barrido_datos4,barrido_datos5;

 char LOCK;
 unsigned int secuencia;
 unsigned short temp_crc;

 char datos_medidoresX[39];

 char num_medidores;
 //char rs_out_485_read[250];
 char rs_out_485_write[11];

 char datos_medidor_buffer[81];	//201 +
 //char save_medidores[246];			//borrarla con la matriz
 char estado_rele[24];

unsigned char num_medidores_flash=24;					//*********	IMPORTANTE PARA EL BROADCAST Y SAVE DATA*************//

 unsigned int Seconds = 0;
 unsigned int Minutes = 34;
 unsigned int Hours = 1;
 
 extern unsigned int Days;
 extern unsigned int mes;
 extern unsigned int ano;

 unsigned long int T1;
 unsigned long int temp1;  //long int
 unsigned long int valor,adc;	
 unsigned long int prom1;	

 unsigned char xbee_port[20],i;
 unsigned char xbee_port_sin_CRC[6];
 unsigned char CRC_recibido[2];
 
 
 //DECLARACIONES PARA CERRAR Y ABRIR LOS RELES

 unsigned char broadcast[8]={0x0,0x3,0x0,0x0,0x0,0x13,0x5,0xD6};

 //----------------------------------------------------------------------------------------------------------
 unsigned char medidor0_rele_off[8]={0x1,0x6,0x0,0x0C,0x0,0x0,0x49,0xC9};
 unsigned char medidor1_rele_off[8]={0x2,0x6,0x0,0x0C,0x0,0x0,0x49,0xFA};
 unsigned char medidor2_rele_off[8]={0x3,0x6,0x0,0x0C,0x0,0x0,0x48,0x2B};
 unsigned char medidor3_rele_off[8]={0x4,0x6,0x0,0x0C,0x0,0x0,0x49,0x9C};
 unsigned char medidor4_rele_off[8]={0x5,0x6,0x0,0x0C,0x0,0x0,0x48,0x4D};
 unsigned char medidor5_rele_off[8]={0x6,0x6,0x0,0x0C,0x0,0x0,0x48,0x7E};

 unsigned char medidor6_rele_off[8]={0x7,0x6,0x0,0x0C,0x0,0x0,0x49,0xAF};
 unsigned char medidor7_rele_off[8]={0x8,0x6,0x0,0x0C,0x0,0x0,0x49,0x50};
 unsigned char medidor8_rele_off[8]={0x9,0x6,0x0,0x0C,0x0,0x0,0x48,0x81};
 unsigned char medidor9_rele_off[8]={0xA,0x6,0x0,0x0C,0x0,0x0,0x48,0xB2};
 unsigned char medidor10_rele_off[8]={0xB,0x6,0x0,0x0C,0x0,0x0,0x49,0x63};
 unsigned char medidor11_rele_off[8]={0xC,0x6,0x0,0x0C,0x0,0x0,0x48,0xD4};

 unsigned char medidor12_rele_off[8]={0xD,0x6,0x0,0x0C,0x0,0x0,0x49,0x05};
 unsigned char medidor13_rele_off[8]={0xE,0x6,0x0,0x0C,0x0,0x0,0x49,0x36};
 unsigned char medidor14_rele_off[8]={0xF,0x6,0x0,0x0C,0x0,0x0,0x48,0xE7};
 unsigned char medidor15_rele_off[8]={0x10,0x6,0x0,0x0C,0x0,0x0,0x4A,0x88};
 unsigned char medidor16_rele_off[8]={0x11,0x6,0x0,0x0C,0x0,0x0,0x4B,0x59};
 unsigned char medidor17_rele_off[8]={0x12,0x6,0x0,0x0C,0x0,0x0,0x4B,0x6A};

 //unsigned char medidor18_rele_off[9]={0x13,0x6,0x0,0x0C,0x0,0x0,0x4A,0xBB};	//No utlizar
 unsigned char medidor18_rele_off[8]={0x1F,0x6,0x0,0x0C,0x0,0x0,0x4A,0x77};
 unsigned char medidor19_rele_off[8]={0x14,0x6,0x0,0x0C,0x0,0x0,0x4B,0x0C};
 unsigned char medidor20_rele_off[8]={0x15,0x6,0x0,0x0C,0x0,0x0,0x4A,0xDD};
 unsigned char medidor21_rele_off[8]={0x16,0x6,0x0,0x0C,0x0,0x0,0x4A,0xEE};
 unsigned char medidor22_rele_off[8]={0x17,0x6,0x0,0x0C,0x0,0x0,0x4B,0x3F};
 unsigned char medidor23_rele_off[8]={0x18,0x6,0x0,0x0C,0x0,0x0,0x4B,0xC0};

 unsigned char medidor24_rele_off[8]={0x19,0x6,0x0,0x0C,0x0,0x0,0x4A,0x11};
 unsigned char medidor25_rele_off[8]={0x1A,0x6,0x0,0x0C,0x0,0x0,0x4A,0x22};
 unsigned char medidor26_rele_off[8]={0x1B,0x6,0x0,0x0C,0x0,0x0,0x4B,0xF3};
 unsigned char medidor27_rele_off[8]={0x1C,0x6,0x0,0x0C,0x0,0x0,0x4A,0x44};
 unsigned char medidor28_rele_off[8]={0x1D,0x6,0x0,0x0C,0x0,0x0,0x4B,0x95};
 unsigned char medidor29_rele_off[8]={0x1E,0x6,0x0,0x0C,0x0,0x0,0x4B,0xA6};

 //----------------------------------------------------------------------------------------------------------
 unsigned char medidor0_rele_on[8]={0x1,0x6,0x0,0x0C,0x0,0x1,0x88,0x09};
 unsigned char medidor1_rele_on[8]={0x2,0x6,0x0,0x0C,0x0,0x1,0x88,0x3A};
 unsigned char medidor2_rele_on[8]={0x3,0x6,0x0,0x0C,0x0,0x1,0x89,0xEB};
 unsigned char medidor3_rele_on[8]={0x4,0x6,0x0,0x0C,0x0,0x1,0x88,0x5C};
 unsigned char medidor4_rele_on[8]={0x5,0x6,0x0,0x0C,0x0,0x1,0x89,0x8D};
 unsigned char medidor5_rele_on[8]={0x6,0x6,0x0,0x0C,0x0,0x1,0x89,0xBE};

 unsigned char medidor6_rele_on[8]={0x7,0x6,0x0,0x0C,0x0,0x1,0x88,0x6F};
 unsigned char medidor7_rele_on[8]={0x8,0x6,0x0,0x0C,0x0,0x1,0x88,0x90};
 unsigned char medidor8_rele_on[8]={0x9,0x6,0x0,0x0C,0x0,0x1,0x89,0x41};
 unsigned char medidor9_rele_on[8]={0xA,0x6,0x0,0x0C,0x0,0x1,0x89,0x72};
 unsigned char medidor10_rele_on[8]={0xB,0x6,0x0,0x0C,0x0,0x1,0x88,0xA3};
 unsigned char medidor11_rele_on[8]={0xC,0x6,0x0,0x0C,0x0,0x1,0x89,0x14};

 unsigned char medidor12_rele_on[8]={0xD,0x6,0x0,0x0C,0x0,0x1,0x88,0xC5};
 unsigned char medidor13_rele_on[8]={0xE,0x6,0x0,0x0C,0x0,0x1,0x88,0xF6};
 unsigned char medidor14_rele_on[8]={0xF,0x6,0x0,0x0C,0x0,0x1,0x89,0x27};
 unsigned char medidor15_rele_on[8]={0x10,0x6,0x0,0x0C,0x0,0x1,0x8B,0x48};
 unsigned char medidor16_rele_on[8]={0x11,0x6,0x0,0x0C,0x0,0x1,0x8A,0x99};
 unsigned char medidor17_rele_on[8]={0x12,0x6,0x0,0x0C,0x0,0x1,0x8A,0xAA};

 //unsigned char medidor18_rele_on[9]={0x13,0x6,0x0,0x0C,0x0,0x1,0x8B,0x7B};	//NO UTILIZAR
 unsigned char medidor18_rele_on[8]={0x1F,0x6,0x0,0x0C,0x0,0x1,0x8B,0xB7};
 unsigned char medidor19_rele_on[8]={0x14,0x6,0x0,0x0C,0x0,0x1,0x8A,0xCC};
 unsigned char medidor20_rele_on[8]={0x15,0x6,0x0,0x0C,0x0,0x1,0x8B,0x1D};
 unsigned char medidor21_rele_on[8]={0x16,0x6,0x0,0x0C,0x0,0x1,0x8B,0x2E};
 unsigned char medidor22_rele_on[8]={0x17,0x6,0x0,0x0C,0x0,0x1,0x8A,0xFF};
 unsigned char medidor23_rele_on[8]={0x18,0x6,0x0,0x0C,0x0,0x1,0x8A,0x00};

 unsigned char medidor24_rele_on[8]={0x19,0x6,0x0,0x0C,0x0,0x1,0x8B,0xD1};
 unsigned char medidor25_rele_on[8]={0x1A,0x6,0x0,0x0C,0x0,0x1,0x8B,0xE2};
 unsigned char medidor26_rele_on[8]={0x1B,0x6,0x0,0x0C,0x0,0x1,0x8A,0x33};
 unsigned char medidor27_rele_on[8]={0x1C,0x6,0x0,0x0C,0x0,0x1,0x8B,0x84};
 unsigned char medidor28_rele_on[8]={0x1D,0x6,0x0,0x0C,0x0,0x1,0x8A,0x55};
 unsigned char medidor29_rele_on[8]={0x1E,0x6,0x0,0x0C,0x0,0x1,0x8A,0x66};
 
 
#endif /* DEFINICIONES */