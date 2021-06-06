#include "funciones.h"


/*FUNCION PARA OBTENER EL NIVEL DE CARGA DE LA BATERIA*/
void get_battery_level(void){
	ADCSC1_ADCH = 0;
	while(ADCSC1_COCO == 0){};
	battery_level_ant=battery_level;
	//battery_level = (ADCR * 100)/184;  //184 equivale a la bateria al 100 % -->4,4 Volts (divisor por dos en HW)
	battery_level = (ADCR )/29;  //184 equivale a la bateria al 100 % -->4,4 Volts (divisor por dos en HW)
	battery_level=(battery_level+battery_level_ant)/2;
	
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++ permite transmitir una cadena de caracteres por RS-485 		 ++++++++++

//++ cadena_tx_rs ("cadena de caract entre comillas"); ++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void cadena_tx_rs (const char *str, char len)
{
    char e;
    EN_RS=1;  
    LED=0;
    //miliseg(5);	//5
    for(e=0;e<len;e++)
	{
	SCI2D=(unsigned char)str[e];
	while(SCI2S1_TC==0)
	    {} 
	} 
    LED=1;
    //miliseg(5);	
    EN_RS=0;
    secuencia=0;
    SCI2C2_RIE=1;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ventana(void)
{
    //TPAD=1;
	TPM2CNT=0;
    ventana_modbus=0;
    while(ventana_modbus==0)
    	{}	
    //TPAD=0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *FUNCION DE LECTURA DE MEDIDORES
 *Retorna'S' si el medidor contestó bien
 *Retorna 'N' si el medidor no contestó 
 * */
char medidores(unsigned int numero)
{
	unsigned char medidorbuf[8]={0x1,0x3,0x0,0x0,0x0,0x13,0x4,0x07};
	char bar,y,indice,cor;
	char es_medidor;
	
	switch(numero)
	{
	case 1:
		medidorbuf[0]=0x1;
		medidorbuf[6]=0x4;
		medidorbuf[7]=0x07;				
	break;
	
	case 2:
		medidorbuf[0]=0x2;
		medidorbuf[6]=0x04;
		medidorbuf[7]=0x34;	
	break;
	
	case 3:
		medidorbuf[0]=0x3;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0xE5;	
	break;
	
	case 4:
		medidorbuf[0]=0x4;
		medidorbuf[6]=0x4;
		medidorbuf[7]=0x52;	
	break;
	
	case 5:
		medidorbuf[0]=0x5;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0x83;	
	break;
	
	case 6:
		medidorbuf[0]=0x6;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0xB0;	
	break;
	
	case 7:
		medidorbuf[0]=0x7;
		medidorbuf[6]=0x4;
		medidorbuf[7]=0x61;	
	break;
	
	case 8:
		medidorbuf[0]=0x8;
		medidorbuf[6]=0x4;
		medidorbuf[7]=0x9E;	
	break;
	
	case 9:
		medidorbuf[0]=0x9;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0x4F;	
	break;
	
	case 10:
		medidorbuf[0]=0xA;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0x7C;	
	break;
	
	case 11:
		medidorbuf[0]=0xB;
		medidorbuf[6]=0x4;
		medidorbuf[7]=0xAD;	
	break;
	
	case 12:
		medidorbuf[0]=0xC;
		medidorbuf[6]=0x5;
		medidorbuf[7]=0x1A;	
	break;
	
	case 13:
		medidorbuf[0]=0xD;
		medidorbuf[6]=0x04;
		medidorbuf[7]=0xCB;	
	break;
	
	case 14:
		medidorbuf[0]=0xE;
		medidorbuf[6]=0x04;
		medidorbuf[7]=0xF8;	
	break;
	
	case 15:
		medidorbuf[0]=0xF;
		medidorbuf[6]=0x05;
		medidorbuf[7]=0x29;	
	break;
	
	case 16:
		medidorbuf[0]=0x10;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0x46;	
	break;
	
	case 17:
		medidorbuf[0]=0x11;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0x97;	
	break;
	
	case 18:
		medidorbuf[0]=0x12;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0xA4;	
	break;
	
	case 19:
		medidorbuf[0]=0x1F;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0xB9;	
	break;
	
	case 20:
		medidorbuf[0]=0x14;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0xC2;	
	break;
	
	case 21:
		medidorbuf[0]=0x15;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0x13;	
	break;
	
	case 22:
		medidorbuf[0]=0x16;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0x20;	
	break;
	
	case 23:
		medidorbuf[0]=0x17;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0xF1;	
	break;
	
	case 24:
		medidorbuf[0]=0x18;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0x0E;	
	break;
	
	case 25:
		medidorbuf[0]=0x19;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0xDF;	
	break;
	
	case 26:
		medidorbuf[0]=0x1A;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0xEC;	
	break;
	
	case 27:
		medidorbuf[0]=0x1B;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0x3D;	
	break;
	
	case 28:
		medidorbuf[0]=0x1C;
		medidorbuf[6]=0x07;
		medidorbuf[7]=0x8A;	
	break;
	
	case 29:
		medidorbuf[0]=0x1D;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0x5B;	
	break;
	

	case 30:
		medidorbuf[0]=0x1E;
		medidorbuf[6]=0x06;
		medidorbuf[7]=0x68;	
	break;
	
	}
	
	
			//PROGRAMA COMUN A TODOS
			LED=1;
			//miliseg(50);    
			cadena_tx_rs(medidorbuf,8);		//envio de la trama de lectura al medidor
			LED=0;
			ventana();
			SCI2C2_RIE=0;			
			bar=1;
			y=0;
			for (y=0;y<79;y++)
			{	    
			if(datos_medidor_buffer[y]==0x13)
				{
				datos_medidoresX[0]=datos_medidor_buffer[y-2];
				y+=1;	    	    
				for (cor=y;cor<=y+38;cor++)	
					{
					datos_medidoresX[bar]=datos_medidor_buffer[cor];
					bar++;
					}
				num_medidores=num_medidores++;
				error=0;
				es_medidor='S';				
				break;
				}

			else
				{
				error=1;
				es_medidor='N';
				}
			}
			for(indice=0;indice<=79;indice++)
				{
				datos_medidor_buffer[indice]=0;
				}
			
secuencia=0;

return es_medidor;
}



/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * FUNCION valores_medidores
 * A partir del vector datos_medidoresX obtengo los valores del medidor
 * */
void valores_medidores(void)
{
	wh=0;// KW/h
	wh=(datos_medidoresX[4]<<8 & 0x0000FF00) | datos_medidoresX[6];
	wh=datos_medidoresX[2]<<16 | wh; 
	
	whr=0;//KVAR/h
	whr=(datos_medidoresX[10]<<8 & 0x0000FF00) | datos_medidoresX[12];
	whr=datos_medidoresX[8]<<16 | whr; 
	
	tension_dato=0;//voltaje
	tension_dato=(datos_medidoresX[14]<<8 & 0xFF00) | datos_medidoresX[16];
	
	corriente_dato=0;//corriente
	corriente_dato=(datos_medidoresX[18]<<8 & 0xFF00) | datos_medidoresX[20];
	
	kw_dato=0;// KW instantanea
	kw_dato=(datos_medidoresX[22]<<8 & 0xFF00) | datos_medidoresX[24];
	
	kwr_dato=0;
	kwr_dato=(datos_medidoresX[26]<<8 & 0xFF00) | datos_medidoresX[28];
	
	hz=0;
	hz=(datos_medidoresX[30]<<8 & 0xFF00) | datos_medidoresX[32];//salida de la frecuencia
	
	factor_dato=0;//factor de potencia
	factor_dato=(datos_medidoresX[34]<<8 & 0xFF00) | datos_medidoresX[36];
}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		Funcion para calcular la suma de checkeo.
// 			CRC - 16 -> Modbus RTU
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
unsigned short CRC16(unsigned char *Data, unsigned short Length)
{
    static const unsigned short CRCTable[] = {
    0x0000, 0XC0C1, 0XC181, 0X0140, 0XC301, 0X03C0, 0X0280, 0XC241,
    0XC601, 0X06C0, 0X0780, 0XC741, 0X0500, 0XC5C1, 0XC481, 0X0440,
    0XCC01, 0X0CC0, 0X0D80, 0XCD41, 0X0F00, 0XCFC1, 0XCE81, 0X0E40,
    0X0A00, 0XCAC1, 0XCB81, 0X0B40, 0XC901, 0X09C0, 0X0880, 0XC841,
    0XD801, 0X18C0, 0X1980, 0XD941, 0X1B00, 0XDBC1, 0XDA81, 0X1A40,
    0X1E00, 0XDEC1, 0XDF81, 0X1F40, 0XDD01, 0X1DC0, 0X1C80, 0XDC41,
    0X1400, 0XD4C1, 0XD581, 0X1540, 0XD701, 0X17C0, 0X1680, 0XD641,
    0XD201, 0X12C0, 0X1380, 0XD341, 0X1100, 0XD1C1, 0XD081, 0X1040,
    0XF001, 0X30C0, 0X3180, 0XF141, 0X3300, 0XF3C1, 0XF281, 0X3240,
    0X3600, 0XF6C1, 0XF781, 0X3740, 0XF501, 0X35C0, 0X3480, 0XF441,
    0X3C00, 0XFCC1, 0XFD81, 0X3D40, 0XFF01, 0X3FC0, 0X3E80, 0XFE41,
    0XFA01, 0X3AC0, 0X3B80, 0XFB41, 0X3900, 0XF9C1, 0XF881, 0X3840,
    0X2800, 0XE8C1, 0XE981, 0X2940, 0XEB01, 0X2BC0, 0X2A80, 0XEA41,
    0XEE01, 0X2EC0, 0X2F80, 0XEF41, 0X2D00, 0XEDC1, 0XEC81, 0X2C40,
    0XE401, 0X24C0, 0X2580, 0XE541, 0X2700, 0XE7C1, 0XE681, 0X2640,
    0X2200, 0XE2C1, 0XE381, 0X2340, 0XE101, 0X21C0, 0X2080, 0XE041,
    0XA001, 0X60C0, 0X6180, 0XA141, 0X6300, 0XA3C1, 0XA281, 0X6240,
    0X6600, 0XA6C1, 0XA781, 0X6740, 0XA501, 0X65C0, 0X6480, 0XA441,
    0X6C00, 0XACC1, 0XAD81, 0X6D40, 0XAF01, 0X6FC0, 0X6E80, 0XAE41,
    0XAA01, 0X6AC0, 0X6B80, 0XAB41, 0X6900, 0XA9C1, 0XA881, 0X6840,
    0X7800, 0XB8C1, 0XB981, 0X7940, 0XBB01, 0X7BC0, 0X7A80, 0XBA41,
    0XBE01, 0X7EC0, 0X7F80, 0XBF41, 0X7D00, 0XBDC1, 0XBC81, 0X7C40,
    0XB401, 0X74C0, 0X7580, 0XB541, 0X7700, 0XB7C1, 0XB681, 0X7640,
    0X7200, 0XB2C1, 0XB381, 0X7340, 0XB101, 0X71C0, 0X7080, 0XB041,
    0X5000, 0X90C1, 0X9181, 0X5140, 0X9301, 0X53C0, 0X5280, 0X9241,
    0X9601, 0X56C0, 0X5780, 0X9741, 0X5500, 0X95C1, 0X9481, 0X5440,
    0X9C01, 0X5CC0, 0X5D80, 0X9D41, 0X5F00, 0X9FC1, 0X9E81, 0X5E40,
    0X5A00, 0X9AC1, 0X9B81, 0X5B40, 0X9901, 0X59C0, 0X5880, 0X9841,
    0X8801, 0X48C0, 0X4980, 0X8941, 0X4B00, 0X8BC1, 0X8A81, 0X4A40,
    0X4E00, 0X8EC1, 0X8F81, 0X4F40, 0X8D01, 0X4DC0, 0X4C80, 0X8C41,
    0X4400, 0X84C1, 0X8581, 0X4540, 0X8701, 0X47C0, 0X4680, 0X8641,
    0X8201, 0X42C0, 0X4380, 0X8341, 0X4100, 0X81C1, 0X8081, 0X4040 };
    unsigned char  Temp;
    unsigned short CRCWord = 0xFFFF;
    while (Length--)
	{
	Temp = *Data++ ^ CRCWord;	  
	CRCWord >>= 8;
	CRCWord ^= CRCTable[Temp];
	}
    return CRCWord;
}

/*
 * FUNCION PARA HABILITAR UN DETERMINADO MEDIDOR
 * */
void rele_on_medidor(int num_medidor)
{
	switch(num_medidor)
		{
		case 1:
			cadena_tx_rs(medidor0_rele_on,8);
			ventana();				
		break;
		
		case 2:
			cadena_tx_rs(medidor1_rele_on,8);
			ventana();
		break;
		
		case 3:
			cadena_tx_rs(medidor2_rele_on,8);
			ventana();				
		break;
		
		case 4:
			cadena_tx_rs(medidor3_rele_on,8);
			ventana();				
	
		break;
		
		case 5:
			cadena_tx_rs(medidor4_rele_on,8);
			ventana();				

		break;
		
		case 6:
			cadena_tx_rs(medidor5_rele_on,8);
			ventana();				
	
		break;
		
		case 7:
			cadena_tx_rs(medidor6_rele_on,8);
			ventana();				

		break;
		
		case 8:
			cadena_tx_rs(medidor7_rele_on,8);
			ventana();				
	
		break;
		
		case 9:
			cadena_tx_rs(medidor8_rele_on,8);
			ventana();				
	
		break;
		
		case 10:
			cadena_tx_rs(medidor9_rele_on,8);
			ventana();				
	
		break;
		
		case 11:
			cadena_tx_rs(medidor10_rele_on,8);
			ventana();				
	
		break;
		
		case 12:
			cadena_tx_rs(medidor11_rele_on,8);
			ventana();				

		break;
		
		case 13:
			cadena_tx_rs(medidor12_rele_on,8);
			ventana();				

		break;
		
		case 14:
			cadena_tx_rs(medidor13_rele_on,8);
			ventana();				
	
		break;
		
		case 15:
			cadena_tx_rs(medidor14_rele_on,8);
			ventana();				

		break;
		
		case 16:
			cadena_tx_rs(medidor15_rele_on,8);
			ventana();				
	
		break;
		
		case 17:
			cadena_tx_rs(medidor16_rele_on,8);
			ventana();				
	
		break;
		
		case 18:
			cadena_tx_rs(medidor17_rele_on,8);
			ventana();				
	
		break;
		
		case 19:
			cadena_tx_rs(medidor18_rele_on,8);
			ventana();				

		break;
		
		case 20:
			cadena_tx_rs(medidor19_rele_on,8);
			ventana();				
	
		break;
		
		case 21:
			cadena_tx_rs(medidor20_rele_on,8);
			ventana();				
	
		break;
		
		case 22:
			cadena_tx_rs(medidor21_rele_on,8);
			ventana();				
	
		break;
		
		case 23:
			cadena_tx_rs(medidor22_rele_on,8);
			ventana();				

		break;
		
		case 24:
			cadena_tx_rs(medidor23_rele_on,8);
			ventana();				
	
		break;
		
		case 25:
			cadena_tx_rs(medidor24_rele_on,8);
			ventana();				
	
		break;
		
		case 26:
			cadena_tx_rs(medidor25_rele_on,8);
			ventana();				
	
		break;
		
		case 27:
			cadena_tx_rs(medidor26_rele_on,8);
			ventana();				

		break;
		
		case 28:
			cadena_tx_rs(medidor27_rele_on,8);
			ventana();				
	
		break;
		
		case 29:
			cadena_tx_rs(medidor28_rele_on,8);
			ventana();				
	
		break;
		

		case 30:
			cadena_tx_rs(medidor29_rele_on,8);
			ventana();				
	
		break;	
		}
}


/*
 * FUNCION PARA DESHABILITAR UN DETERMINADO MEDIDOR
 * */
void rele_off_medidor(int num_medidor)
{
	switch(num_medidor)
		{
		case 1:
			cadena_tx_rs(medidor0_rele_off,8);
			ventana();				
		break;
		
		case 2:
			cadena_tx_rs(medidor1_rele_off,8);
			ventana();
		break;
		
		case 3:
			cadena_tx_rs(medidor2_rele_off,8);
			ventana();				
		break;
		
		case 4:
			cadena_tx_rs(medidor3_rele_off,8);
			ventana();				
	
		break;
		
		case 5:
			cadena_tx_rs(medidor4_rele_off,8);
			ventana();				

		break;
		
		case 6:
			cadena_tx_rs(medidor5_rele_off,8);
			ventana();				
	
		break;
		
		case 7:
			cadena_tx_rs(medidor6_rele_off,8);
			ventana();				

		break;
		
		case 8:
			cadena_tx_rs(medidor7_rele_off,8);
			ventana();				
	
		break;
		
		case 9:
			cadena_tx_rs(medidor8_rele_off,8);
			ventana();				
	
		break;
		
		case 10:
			cadena_tx_rs(medidor9_rele_off,8);
			ventana();				
	
		break;
		
		case 11:
			cadena_tx_rs(medidor10_rele_off,8);
			ventana();				
	
		break;
		
		case 12:
			cadena_tx_rs(medidor11_rele_off,8);
			ventana();				

		break;
		
		case 13:
			cadena_tx_rs(medidor12_rele_off,8);
			ventana();				

		break;
		
		case 14:
			cadena_tx_rs(medidor13_rele_off,8);
			ventana();				
	
		break;
		
		case 15:
			cadena_tx_rs(medidor14_rele_off,8);
			ventana();				

		break;
		
		case 16:
			cadena_tx_rs(medidor15_rele_off,8);
			ventana();				
	
		break;
		
		case 17:
			cadena_tx_rs(medidor16_rele_off,8);
			ventana();				
	
		break;
		
		case 18:
			cadena_tx_rs(medidor17_rele_off,8);
			ventana();				
	
		break;
		
		case 19:
			cadena_tx_rs(medidor18_rele_off,8);
			ventana();				

		break;
		
		case 20:
			cadena_tx_rs(medidor19_rele_off,8);
			ventana();				
	
		break;
		
		case 21:
			cadena_tx_rs(medidor20_rele_off,8);
			ventana();				
	
		break;
		
		case 22:
			cadena_tx_rs(medidor21_rele_off,8);
			ventana();				
	
		break;
		
		case 23:
			cadena_tx_rs(medidor22_rele_off,8);
			ventana();				

		break;
		
		case 24:
			cadena_tx_rs(medidor23_rele_off,8);
			ventana();				
	
		break;
		
		case 25:
			cadena_tx_rs(medidor24_rele_off,8);
			ventana();				
	
		break;
		
		case 26:
			cadena_tx_rs(medidor25_rele_off,8);
			ventana();				
	
		break;
		
		case 27:
			cadena_tx_rs(medidor26_rele_off,8);
			ventana();				

		break;
		
		case 28:
			cadena_tx_rs(medidor27_rele_off,8);
			ventana();				
	
		break;
		
		case 29:
			cadena_tx_rs(medidor28_rele_off,8);
			ventana();				
	
		break;
		

		case 30:
			cadena_tx_rs(medidor29_rele_off,8);
			ventana();				
	
		break;	
		}
}

/*
 * HABILITA TODOS LOS MEDIDORES
 * */
void rele_on_all(void)
{
	int ii;
	for(ii=1;ii<=30;ii++)
		{rele_on_medidor(ii);}
}


/*
 * DESHABILITA TODOS LOS MEDIDORES
 * */
void rele_off_all(void)
{
	int ii;
	for(ii=1;ii<=30;ii++)
		{rele_off_medidor(ii);}
}




//------------------------------------------------------------------------------------
void error_data(unsigned int number)
{
    if(error==1)
	{
	//medidores(number);
	}
    /*
    if(error==1)
	{
	medidores(number);
	}
    */
    error=0;
}
//------------------------------------------------------------------------------------
void rs_485_out_write(unsigned char registro,unsigned char estado)
{
    byte TX;
    rs_out_485_write[0]=0x1A;
    rs_out_485_write[1]=0x06;
    rs_out_485_write[2]=0x00;
    rs_out_485_write[3]=registro;
    rs_out_485_write[4]=0x00;
    rs_out_485_write[5]=estado;
    
    temp_crc=CRC16(&rs_out_485_write[0],6);	        
    rs_out_485_write[6]=temp_crc & 0x00FF;	// El menos significativo va primero.	     
    rs_out_485_write[7]=temp_crc >> 8;		// El mas significativo va despues.
    
    for (TX=0;TX<=7;TX++)
	    {
	    SCI1D=(unsigned char)rs_out_485_write[TX];
	    while(SCI1S1_TC==0)
		    {}	
	    }
}



//===============================================================================================
//				Lectura Modbus
//		______________________________________________________
//		|D.Modbus|T. Orden|R. Inicial &|  Contador |   CRC    | 		
//		------------------------------------------------------
//		   0x01	    0x03    0x00 0x00	 0x00 0x13  0x04 0x07
/*
 * 	Registros:
 * 		0000	State Reles
 * 		0001	Send Data
 * 		0002	Send Data Ins.
 *    		0003	R. On/Off
 * 		0004	Save Data
 *	Example: 		
//		Estado de los Reles				1A 03 00 00 00 01
//		Enviar  Datos					1A 03 00 01 00 01
//		Enviar Datos instantaneos de los medidores	1A 03 00 02 00 01
//		Rele On/Off All					1A 06 00 03 00 01/00	
//		Guardar Datos					1A 06 00 05 00 01	//en 1 para q guarden
//===============================================================================================
*/
void rs_485_in(void)
{          
if(xbee_port[0]==0x1A)	
    {	
    for(conteo1=0;conteo1<=5;conteo1++)
		{
		xbee_port_sin_CRC[conteo1]=xbee_port[conteo1];
		}       
    temp_crc=CRC16(&xbee_port_sin_CRC[0],6);	        
    CRC_recibido[0]=temp_crc & 0x00FF;		// El menos significativo va primero.	     
    CRC_recibido[1]=temp_crc >> 8;		// El mas significativo va despues.   	    	    	   	 	   

    if(CRC_recibido[0]==xbee_port[6] && CRC_recibido[1]==xbee_port[7])
		{
    	if(xbee_port[1]==0x03)		//------ LECTURA --------------------
				{
//				registros(xbee_port[3]);
				
				if(xbee_port[5]==0x02)
					{
//					registros(xbee_port[3]+0x01);
					}	    
				}
	//			-----		-------- ESCRITURA ------------------    
			if(xbee_port[1]==0x06)		
				{    
				if(xbee_port[3]==0x05)
					{
					if(xbee_port[5]==0x01)
						{
						rele_on_all();
						//registros_vector_write[0]=1;
						rs_485_out_write(0x05,0x01);
						}
					if(xbee_port[5]==0x00)
						{
						rele_off_all();
						//registros_vector_write[0]=0;
						rs_485_out_write(0x05,0x00);
						}	  
					}
				if(xbee_port[3]==0x06)
					{
					if(xbee_port[5]==0x01)
						{
//						save_data();			   
						//rs_485_out_write(0x06,0x01);
						}
					else
						{			   
						rs_485_out_write(0x06,0x0);
						}	  
					}	
				if(xbee_port[3]==0x07)		//SEGURO
					{
					if(xbee_port[5]==0x00)
						{
						apertura_caja=0;
						rs_485_out_write(0x07,0x00);
						}	  
					if(xbee_port[5]==0x01)
						{
						apertura_caja=1;
						rs_485_out_write(0x07,0x01);
						}
					if(xbee_port[5]==0x02)
						{
						apertura_caja=2;
						rs_485_out_write(0x07,0x02);
						}	  
					}
				if(xbee_port[3]==0x52)		//AÑO
					{
					ano=xbee_port[5];
					//rs_485_out_write(0x52,0x01);						  	
					}
				if(xbee_port[3]==0x53)		//MES
					{
					mes=xbee_port[5];
					//rs_485_out_write(0x53,0x01);						  	
					}
				if(xbee_port[3]==0x54)		//DAY
					{
					Days=xbee_port[5];
					//rs_485_out_write(0x54,0x01);						  	
					}
				if(xbee_port[3]==0x55)		//HORA
					{
					Hours=xbee_port[5];
					//rs_485_out_write(0x55,0x01);						  	
					}
				if(xbee_port[3]==0x56)		//MINUTES
					{
					Minutes=xbee_port[5];
					//rs_485_out_write(0x56,0x01);						  	
					}				
				if(xbee_port[3]==0x58)		//SEGURO
					{
					num_medidores_flash=xbee_port[5];
					rs_485_out_write(0x58,0x02);	  
					}				
				
				}    
			xbee_port[0]=0;	
		}
    }
else if(xbee_port[0]<=0x2F)
    {
    cadena_tx_rs(xbee_port,8);
    xbee_port[0]=50;
    xbee_port[1]=50;
	LED=0;
	//miliseg(150);	
	SCI2C2_RIE=0;

    if(flag_recibido==1)
	{    
	    for (barrido_datos=0;barrido_datos<199;barrido_datos++)
		{	    
		if(datos_medidor_buffer[barrido_datos]==0x13)
		    {
		    barrido_datos=barrido_datos-2;
		    for (TX3=barrido_datos;TX3<=barrido_datos+42;TX3++)	//40 datos + 2 CRC
			{		   
			while(SCI1S1_TC==0)
				{}	
			(void)(SCI1D==0);
			SCI1D=datos_medidor_buffer[TX3];
			while(SCI1S1_TC==0)
				{}	
			}
		    flag_recibido=0;
		    break;
		    }
		}    
	}
    else
	{
	flag_recibido=0;
	}
    }
//flag_xbee_port=0;
}

void sensado(void)
{
    ADCSC1_ADCH=3;
    while(ADCSC1_COCO==0)
	    {}
    //valor=ADCR;
    //valor=ADCR*330;
    adc=ADCR;

    valor=((unsigned long int)(ADCR)*11);
    prom1=valor-6144;
    temp1=100*prom1;
    T1=temp1/26624;
    T1=(unsigned char)(T1);

 }


