#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "Includes.h"



#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */
void get_battery_level(void);




void main(void) {

	MCU_init();	/* call Dev ice Initialization */
  /* INICIALIZACION DE VARIABLES */
     LED_TEST=1;
     nlcd_Init();   //Nokia LCD initialization
	nlcd_Clear();
	//graph_NOKIA(UIS);
	nlcd_GotoXY_pix(0,23);
	nlcd_PrintWide("TERMINAL");
	nlcd_GotoXY_pix(0,33);
	nlcd_PrintWide("  UIS");
	nlcd_GotoXY_pix(0,43);
	nlcd_PrintWide("   ESSA");
	delay_ms(2000);
	nlcd_Clear();
	menu('E');//Despliega el mensaje de entrada para el menu					
	puntero_menu='M';  
	nlcd_Clear();
	
  for(;;) {
	  
	  
	  menu(puntero_menu);
	  teclita=check_tecla();
	  if(teclita=='1')//LEER TODOD LOS MEDIDORES Y MOSTRAR OK!! 
	  	  {puntero_menu='T'; }
	  else if (teclita=='2')//LEER MEDIDOR INDIVIDUAL
	  	  {puntero_menu='L';//PREGUNTAR CUAL MEDIDOR QUIERLO LEER}
	  	  }
	  else if (teclita=='3')//habilitar o deshabilitar un medidor
	 	  	  {puntero_menu='H';//PREGUNTAR CUAL MEDIDOR QUIERLO habilitar o deshabilitar
	 	  	   }
	  else if (teclita=='4')//INFORMACION
	  	 	  	  {puntero_menu='I';}	
	  
	  
	  get_battery_level();
	  itoa(tx_vec,2,battery_level);
	  nlcd_GotoXY_pix(60,0);
	  nlcd_Print(tx_vec);
	  nlcd_Print("%");
	  
	  
	  if(battery_level<75)
			{LED_TEST=~LED_TEST;}
	  else
	  	  {LED_TEST=0;}			
	  	  delay_ms(300);
	  
	  //delay_us(1);
	  
    /* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */
}


