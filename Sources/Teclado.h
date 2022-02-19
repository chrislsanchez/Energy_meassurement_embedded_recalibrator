/*
** ###################################################################
**
**     Filename  : Teclado.h
**
**     Processor : MC9S08QE32CLC
**
**		Esta libreria permite controlar un teclado Matricial 4x4
**		los puertos que estan configurados 
**         	Son:
**
**				PTF7	Output check 
**				PTF6	Output check
**				PTF5	Output check
**	  		    PTF4	Output check
**				PTF3 	Input Verif.	
**				PTF2	Input Verif.
**				PTF1	Input Verif.
**				PTF0	Input Verif.
**
**
**     mail      : grupoera@pinguino.uis.edu.co 
**     Desarrollada por: Christian
**
** ###################################################################
*/


#ifndef _TECLADO_H_
#define _TECLADO_H_


#include <mc9s08qe32.h>                /* I/O map for MC9S08QE32CLC */

#define	TEX1	PTBD_PTBD5
#define	TEX2	PTBD_PTBD4
#define	TEX3	PTCD_PTCD3
#define	TEX4	PTCD_PTCD2

#define	TIN1	PTCD_PTCD1
#define	TIN2	PTCD_PTCD0
#define	TIN3	PTBD_PTBD3
#define	TIN4	PTBD_PTBD2


void delay(unsigned int a);
void verf(void);
char check_tecla(void);


#endif /*  */
/*
** ###################################################################
**   This file was created by ERA Electronic & Roboitcs Aplicated **
** ###################################################################
*/
