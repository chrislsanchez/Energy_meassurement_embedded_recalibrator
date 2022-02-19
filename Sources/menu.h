
#ifndef _MENU_H_
#define _MENU_H_

#include "Teclado.h"
#include "funciones.h"
#include "nokia1100_lcd_lib.h"
#include <stdlib.h>


extern char teclita;
extern char puntero_menu;
extern char buffer_opcion_teclado[10];
extern char fp_te,kk;//apuntador para buffer
extern int retorno_teclado;
extern int error_menu;
extern char tx_vec[10];
extern char EM;

extern long wh;// KW/h
extern long whr;//KVAR/h
extern int tension_dato;//voltaje
extern int corriente_dato;//corriente
extern int kw_dato;// KW instantanea
extern int kwr_dato;
extern int hz;//frecuencia
extern int factor_dato;//factor de potencia

void mensaje_entrada(void);
void menu(char l);
void itoa (char * str, char len, long int val);


#endif
