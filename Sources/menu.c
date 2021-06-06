#include "menu.h"


/*
 *  itoa(tx_vec,6,acc_vec[w]);//El caracter de encabezado es un enter al final de cada transmision 
    
 * */

void itoa (char * str, char len, long int val)
  {
	  char i=0;
	  long int copy=val;
	  unsigned long int val1;
	  if(val<0) 
	    {
	    val1=-val;
	    }
	  else
	    {
	    val1=val;
	    }
	    
	  while(copy!=0)
	  	{
	  	i++;
	  	copy/=10;
	  	}
	  if (len<i)
	  	{
	  	len=i;
	  	} 
	  for(i=1; i<=len; i++)
	  	{
	  	str[len-i] = (char) ((val1 % 10UL) + '0');
	  	val1/=10;
	  	}
	  str[i-1] = '\0';
	  
  } 








/*
 * MENSAJE DE ENTRADA MAS CONDICION PARA INICIO DEL PROGRAMA
 * */
void mensaje_entrada(void)
	{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);
	nlcd_Print("    TERMINAL");
	nlcd_GotoXY_pix(0,9);
	nlcd_Print("     MEDIDA");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("   CENTRALIZADA");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("  Version 1.0");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("   UIS 2014");	
	nlcd_GotoXY_pix(0,49);
	nlcd_Print("Presione * para");
	nlcd_GotoXY_pix(0,57);
	nlcd_Print("continuar");
	}

void info(void)
	{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);
	nlcd_PrintWide("TERMINAL");
	nlcd_GotoXY_pix(0,16);
	nlcd_Print("Version 1.0");
	nlcd_GotoXY_pix(0,24);
	nlcd_Print("Hecho en la UIS");
	nlcd_GotoXY_pix(0,32);
	nlcd_Print("12/2014");	
	nlcd_GotoXY_pix(0,40);
	nlcd_Print("Mayor info.");
	nlcd_GotoXY_pix(0,48);
	nlcd_Print("grupoera.com.co");
	nlcd_GotoXY_pix(0,56);
	nlcd_Print("*->Salir");		
	teclita=check_tecla();
	while(teclita!='*')
		{teclita=check_tecla();}
	puntero_menu='M';
	nlcd_Clear();
	}

/*
 * MENSAJE DE ERROR EN LA PANTALLA
 * */

void menu_error(void)
{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,9);
	nlcd_PrintWide(" ERROR!!!");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("   Por Favor");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("   Intentelo ");
	nlcd_GotoXY_pix(0,41);
	nlcd_Print("   Nuevamente");
	delay_ms(3000);
	nlcd_Clear();
	puntero_menu='M';//retorno al menu principal
}

void mensaje_sin_conexion(void)
{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,16);
	nlcd_PrintWide("SIN ");
	nlcd_GotoXY_pix(0,25);
	nlcd_PrintWide("CONEXION ");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("No se ha podido");
	nlcd_GotoXY_pix(0,41);
	nlcd_Print("conectar con el");
	nlcd_GotoXY_pix(0,49);
	nlcd_Print("medidor");
	delay_ms(3000);
	nlcd_Clear();
	puntero_menu='M';//retorno al menu principal
}

void menu_prueba(void)
	{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);
	nlcd_Print("Presione:");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("1- Des. Rele");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("2- Hab. rele");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("3- Menu Principal");	
	}
/*
 * VISUALIZACION DEL MENU PRINCIPAL
 * */
void menu_principal(void)
	{
	nlcd_GotoXY_pix(0,0);
	nlcd_PrintWide("MENU");
	nlcd_GotoXY_pix(0,9);
	nlcd_Print("Presione:");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("1-Prueba de");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("Medidores");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("2-Informacion de un  Medidor");
	nlcd_GotoXY_pix(0,49);
	nlcd_Print("3-Hab/Des Med.");
	nlcd_GotoXY_pix(0,57);
	nlcd_Print("4-Acerca de.");	
	}

void menu_visualizacion_medidor(int numero_medidor)
{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);
	nlcd_PrintWide("MEDIDOR");
	itoa(tx_vec,2,numero_medidor);
    nlcd_PrintWide(tx_vec);
    //Visualizacion de la tension
    nlcd_GotoXY_pix(0,9);
    itoa(tx_vec,3,tension_dato/10);    
    nlcd_Print(tx_vec);
    nlcd_Print(",");
    itoa(tx_vec,1,(tension_dato%10));
    nlcd_Print(tx_vec);
    nlcd_Print("V");
        
    //Visualizacion de la corriente
	nlcd_GotoXY_pix(48,9);
	itoa(tx_vec,2,corriente_dato/100);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,2,(corriente_dato%100));
	nlcd_Print(tx_vec);
	nlcd_Print("A");
	
	//Visualizacion de la frecuencia
	nlcd_GotoXY_pix(0,17);
	itoa(tx_vec,2,hz/100);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,2,(hz%100));
	nlcd_Print(tx_vec);
	nlcd_Print("Hz");
	
	//Visualizacion del factor de potencia
	nlcd_GotoXY_pix(48,17);
	nlcd_Print("fp=");
	itoa(tx_vec,2,factor_dato/100);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,2,(factor_dato%100));
	nlcd_Print(tx_vec);
	
	//Visualizacion de Potencia Instantanea
	nlcd_GotoXY_pix(0,25);
	itoa(tx_vec,2,kw_dato/100);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,2,(kw_dato%100));
	nlcd_Print(tx_vec);
	nlcd_Print("Kw");
	//Reactiva
	nlcd_GotoXY_pix(0,33);
	itoa(tx_vec,2,kwr_dato/100);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,2,(kwr_dato%100));
	nlcd_Print(tx_vec);
	nlcd_Print("Kvar");
	
	//Visualizacion de Potencia Instantanea
	nlcd_GotoXY_pix(0,41);
	itoa(tx_vec,5,wh/10);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,1,(wh%10));
	nlcd_Print(tx_vec);
	nlcd_Print("Kw/h");
	//Reactiva
	nlcd_GotoXY_pix(0,49);
	itoa(tx_vec,5,whr/10);    
	nlcd_Print(tx_vec);
	nlcd_Print(",");
	itoa(tx_vec,1,(whr%10));
	nlcd_Print(tx_vec);
	nlcd_Print("Kvar/h");
	
	//Salida
	nlcd_GotoXY_pix(0,56);
	nlcd_Print("* -> Salir");
	
	teclita=check_tecla();
	while(teclita!='*')
			{
			teclita=check_tecla();
			}
	puntero_menu='M';
	nlcd_Clear();
	
}

/*
 * FUNCION PARA DETECTAR QUE MEDIDOR ESPECIFICAMENTE QUIERO LEER Y 
 * MUESTRA LA INFORMACION DE ESE MEDIDOR
 * 
 * */

void menu_leer_medidor(void)
{	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);          
	nlcd_Print("Digite el numero");
	nlcd_GotoXY_pix(0,9);
	nlcd_Print("de medidor que");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("desea leer ");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("Aceptar -> *");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("Borrar  -> #");		
	
	for(kk=0;kk<10;kk++)//blanqueo el buffer
		{buffer_opcion_teclado[kk]=0;}
	fp_te=0;
	teclita=check_tecla();
	while(teclita!='*' && fp_te<10)
		{
		teclita=check_tecla();
		delay_ms(150);//RETARDO para evitar repeticion sucesiva por presionar la tecla
		if(teclita!='*' && teclita!='N')
			{
			if(teclita=='#')
				{
				if(fp_te>0)
					{fp_te-=1;}//me aseguro que nunca sea menor que cero
				buffer_opcion_teclado[fp_te]='-';
				nlcd_GotoXY_pix(0,49);
				nlcd_PrintWide(buffer_opcion_teclado);//hasta aqui solo para visualizar en pantalla				
				buffer_opcion_teclado[fp_te]=0;//coloco el caracter NULL por si termino ahi
				}
			else
				{
				buffer_opcion_teclado[fp_te]=teclita;
				fp_te++;
				nlcd_GotoXY_pix(0,49);
				nlcd_PrintWide(buffer_opcion_teclado);			
				}
			}
		}
	//si sali del buffer quiere decir que termine de escribir o que escribi mas de 10 caracteres
	
	retorno_teclado=atoi(buffer_opcion_teclado);
	
	if(retorno_teclado<1 || retorno_teclado>30)//intervalo de modbus de medidores validos
		{
		menu_error();
		}
	else
		{
		nlcd_Clear();
		nlcd_GotoXY_pix(0,25);          
		nlcd_Print("  Leyendo.");
		delay_ms(500);//PRUEBA!!!!!--> borrar
		nlcd_Print(".");
		delay_ms(500);//PRUEBA!!!!!--> borrar
	    nlcd_Print(".");
		EM=medidores(retorno_teclado);
		if(EM=='S')//medidor respondio
			{
			valores_medidores();
			menu_visualizacion_medidor(retorno_teclado);
			}
		else//medidor no respondio
			{
			mensaje_sin_conexion();
			}
		}
}


/*
 * 
 * FUNCION PARA LEER TODOS LOS MEDIDORES AL TIEMPO Y OBSERVAR
 * EL ESTADO DE TODOS LOS MEDIDORES EN LA PANTALLA
 * 
 * */

void menu_test_medidores(void)
	{
	int xm,xx,yy;
	
	//PRIMEROS 12 MEDIDORES
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0); 
	nlcd_Print("MED");
	nlcd_GotoXY_pix(20,0); 
	nlcd_Print("EST");
	nlcd_GotoXY_pix(49,0); 
	nlcd_Print("MED");
	nlcd_GotoXY_pix(69,0); 
	nlcd_Print("EST");
	
	xx=0;
	yy=9;
	for(xm=1;xm<=12;xm++)
		{
		EM=medidores(xm);
		itoa(tx_vec,2,xm);
		nlcd_GotoXY_pix(xx,yy); 
		nlcd_Print(tx_vec);
		nlcd_Print(".");
		if(EM=='S')//medidor respondio
			{
			nlcd_Print("OK");			
			}
		else
			{nlcd_Print("Error");}
		yy+=8;
		if(xm==6)
			{
			xx=49;
			yy=9;			
			}		
		}	
	nlcd_GotoXY_pix(0,57);          
	nlcd_Print("*->Siguiente");
	teclita=check_tecla();
	while(teclita!='*')
		{teclita=check_tecla();}
	
	//MEDIDORES DEL 13 AL 24
		nlcd_Clear();
		nlcd_GotoXY_pix(0,0); 
		nlcd_Print("MED");
		nlcd_GotoXY_pix(20,0); 
		nlcd_Print("EST");
		nlcd_GotoXY_pix(49,0); 
		nlcd_Print("MED");
		nlcd_GotoXY_pix(69,0); 
		nlcd_Print("EST");
		
		xx=0;
		yy=9;
		for(xm=13;xm<=24;xm++)
			{
			EM=medidores(xm);
			itoa(tx_vec,2,xm);
			nlcd_GotoXY_pix(xx,yy); 
			nlcd_Print(tx_vec);
			nlcd_Print(".");
			if(EM=='S')//medidor respondio
				{
				nlcd_Print("OK");			
				}
			else
				{nlcd_Print("Error");}
			yy+=8;
			if(xm==18)
				{
				xx=49;
				yy=9;			
				}		
			}	
		nlcd_GotoXY_pix(0,57);          
		nlcd_Print("*->Siguiente");
		teclita=check_tecla();
		while(teclita!='*')
			{teclita=check_tecla();}
		
		//ULTIMOS 6 MEDIDORES
		nlcd_Clear();
		nlcd_GotoXY_pix(0,0); 
		nlcd_Print("MED");
		nlcd_GotoXY_pix(20,0); 
		nlcd_Print("EST");
		
		xx=0;
		yy=9;
		for(xm=25;xm<=30;xm++)
			{
			EM=medidores(xm);
			itoa(tx_vec,2,xm);
			nlcd_GotoXY_pix(xx,yy); 
			nlcd_Print(tx_vec);
			nlcd_Print(".");
			if(EM=='S')//medidor respondio
				{
				nlcd_Print("OK");			
				}
			else
				{nlcd_Print("Error");}
			yy+=8;
			}	
		nlcd_GotoXY_pix(0,57);          
		nlcd_Print("*->SALIR");
		teclita=check_tecla();
		while(teclita!='*')
			{teclita=check_tecla();}
		puntero_menu='M';
		nlcd_Clear();
}

/*
 * sub_menu habilitar un medidor
 * */
void submenu_hab_medidor(void)
{
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);          
	nlcd_Print("Digite el numero");
	nlcd_GotoXY_pix(0,9);
	nlcd_Print("de medidor que");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("desea habilitar ");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("Aceptar -> *");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("Borrar  -> #");		
		
		for(kk=0;kk<10;kk++)//blanqueo el buffer
			{buffer_opcion_teclado[kk]=0;}
		fp_te=0;
		teclita=check_tecla();
		while(teclita!='*' && fp_te<10)
			{
			teclita=check_tecla();
			delay_ms(150);//RETARDO para evitar repeticion sucesiva por presionar la tecla
			teclita=check_tecla();
			if(teclita!='*' && teclita!='N')
				{
				if(teclita=='#')
					{
					if(fp_te>0)
						{fp_te-=1;}//me aseguro que nunca sea menor que cero
					buffer_opcion_teclado[fp_te]='-';
					nlcd_GotoXY_pix(0,49);
					nlcd_PrintWide(buffer_opcion_teclado);//hasta aqui solo para visualizar en pantalla				
					buffer_opcion_teclado[fp_te]=0;//coloco el caracter NULL por si termino ahi
					}
				else
					{
					buffer_opcion_teclado[fp_te]=teclita;
					fp_te++;
					nlcd_GotoXY_pix(0,49);
					nlcd_PrintWide(buffer_opcion_teclado);			
					}
				}
			}
		//si sali del buffer quiere decir que termine de escribir o que escribi mas de 10 caracteres
		
		retorno_teclado=atoi(buffer_opcion_teclado);
		
		if(retorno_teclado<1 || retorno_teclado>30)//intervalo de modbus de medidores validos
			{
			menu_error();
			}
		else
			{
			rele_on_medidor(retorno_teclado);	
			nlcd_Clear();
			nlcd_GotoXY_pix(0,25);          
			nlcd_PrintWide("  Listo!");
			delay_ms(1500);
			nlcd_Clear();
			}	
}

/*
 * sub_menu Deshabilitar un medidor
 * */
void submenu_deshab_medidor(void)
{
	nlcd_Clear();
		nlcd_GotoXY_pix(0,0);          
		nlcd_Print("Digite el numero");
		nlcd_GotoXY_pix(0,9);
		nlcd_Print("de medidor que");
		nlcd_GotoXY_pix(0,17);
		nlcd_Print("desea deshab. ");
		nlcd_GotoXY_pix(0,25);
		nlcd_Print("Aceptar -> *");
		nlcd_GotoXY_pix(0,33);
		nlcd_Print("Borrar  -> #");		
		
		for(kk=0;kk<10;kk++)//blanqueo el buffer
			{buffer_opcion_teclado[kk]=0;}
		fp_te=0;
		teclita=check_tecla();
		while(teclita!='*' && fp_te<10)
			{
			teclita=check_tecla();
			delay_ms(150);//RETARDO para evitar repeticion sucesiva por presionar la tecla
			if(teclita!='*' && teclita!='N')
				{
				if(teclita=='#')
					{
					if(fp_te>0)
						{fp_te-=1;}//me aseguro que nunca sea menor que cero
					buffer_opcion_teclado[fp_te]='-';
					nlcd_GotoXY_pix(0,49);
					nlcd_PrintWide(buffer_opcion_teclado);//hasta aqui solo para visualizar en pantalla				
					buffer_opcion_teclado[fp_te]=0;//coloco el caracter NULL por si termino ahi
					}
				else
					{
					buffer_opcion_teclado[fp_te]=teclita;
					fp_te++;
					nlcd_GotoXY_pix(0,49);
					nlcd_PrintWide(buffer_opcion_teclado);			
					}
				}
			}
		//si sali del buffer quiere decir que termine de escribir o que escribi mas de 10 caracteres
		
		retorno_teclado=atoi(buffer_opcion_teclado);
		
		if(retorno_teclado<1 || retorno_teclado>30)//intervalo de modbus de medidores validos
			{
			menu_error();
			}
		else
			{
			rele_off_medidor(retorno_teclado);	
			nlcd_Clear();
			nlcd_GotoXY_pix(0,25);          
			nlcd_PrintWide("  Listo!");
			delay_ms(1500);
			nlcd_Clear();
			}	
}


/*
 *FUNCION PARA HABILITAR O DESHABILITAR MEDIDORES 
 * */
void hab_des_medidores(void)
{
	
	nlcd_Clear();
	nlcd_GotoXY_pix(0,0);
	nlcd_PrintWide("  MENU");
	nlcd_GotoXY_pix(0,9);
	nlcd_Print("Presione:");
	nlcd_GotoXY_pix(0,17);
	nlcd_Print("1-Hab. Medidor");
	nlcd_GotoXY_pix(0,25);
	nlcd_Print("2-Des. Medidor");
	nlcd_GotoXY_pix(0,33);
	nlcd_Print("3-Hab. Todos");
	nlcd_GotoXY_pix(0,41);
	nlcd_Print("4-Des. Todos");
	nlcd_GotoXY_pix(0,49);
	nlcd_Print("5-Volver");
	teclita=check_tecla();
	while(teclita=='N')//Verifico tecla presionada
			{
			teclita=check_tecla();
			}
	switch(teclita)//Opciones del menu
		{
		case '1'://Menu Habilitar un medidor
			submenu_hab_medidor();
			nlcd_Clear();
			puntero_menu='M';		
		break;
		
		case '2' ://menu Deshabilitar un medidor
			submenu_deshab_medidor();
			puntero_menu='M';		
		break;
		
		case '3' ://Habilitar todos los medidores
			nlcd_Clear();
			nlcd_GotoXY_pix(0,25);          
			nlcd_Print(" Procesando...");
			rele_on_all();
			nlcd_Clear();
			puntero_menu='M';
		break;
		
		case '4' ://deshabilitar todos los medidores
			nlcd_Clear();
			nlcd_GotoXY_pix(0,25);          
			nlcd_Print(" Procesando...");
			rele_off_all();
			nlcd_Clear();
			puntero_menu='M';			
		break;
		
		case '5' ://volver al menu principal
			nlcd_Clear();
			puntero_menu='M';
		break;
		
		default:
			menu_error();
		break;
		
		}
}



void menu(char l)

{
	switch(l)
    {
    case 'E':
    	mensaje_entrada();
    	teclita=check_tecla();
    	while(teclita!='*')
    			{
    			teclita=check_tecla();
    			}
    	puntero_menu='M';
    break;
    
    case 'M' :
    	menu_principal();
    break;
    
    case 'T' :
        	menu_test_medidores();
    break;
    
    case 'L' :
        	menu_leer_medidor();
    break;
    
    case 'H' :
           	hab_des_medidores();
    break;
    
    case 'I' :
           	info();
    break;
        
    
  	}
}


