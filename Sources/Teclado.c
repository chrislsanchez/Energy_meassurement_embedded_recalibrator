#include "Teclado.h"

char Tecla;
static char f,c,band_tecla;
char matrix [4][4] = {'D','#','0','*','C','9','8','7',
					'B','6','5','4','A','3','2','1'};

void delay(unsigned int a)
	{
	int l,lt;
	for (l=0;l<=a;l++)
		{
		for (lt=0;lt<=100;lt++)
			{
			asm(nop);
			}
		}
	}
	

void verf(void)
{
if(band_tecla==0)
	{		
	if(TIN1==0)
		{
		f=0;
		}
	else if(TIN2==0)
		{
		f=1;
		}
	else if(TIN3==0)
		{
		f=2;
		}
	else if(TIN4==0)
		{
		f=3;
		}
	else
		{
		f=4;
		}	
 	}
}


char check_tecla(void)
{
band_tecla=0;
TEX1=0;
TEX2=0;
TEX3=0;
TEX4=0;
delay(100);
verf();
if(f!=4)
	{
	band_tecla=0;
	TEX1=0;
	TEX2=1;
	TEX3=1;
	TEX4=1;
	delay(10);		 
	verf();
	if(f!=4 && band_tecla==0)
		{
		c=0;
		band_tecla=1;
		}
	TEX1=1;
	TEX2=0;
	TEX3=1;
	TEX4=1;
	delay(10);	
	verf();
	if(f!=4 && band_tecla==0)
		{
		c=1;
		band_tecla=1;
		}
	TEX1=1;
	TEX2=1;
	TEX3=0;
	TEX4=1;
	delay(10);	
	verf();
	if(f!=4 && band_tecla==0)
		{
		c=2;
		band_tecla=1;
		}
	TEX1=1;
	TEX2=1;
	TEX3=1;
	TEX4=0;
	delay(10);	
	verf();	 
	if(f!=4 && band_tecla==0)
		{
		c=3;
		band_tecla=1;
		}
	Tecla = matrix[f][c];	
	}
else
	{
	Tecla='N';
	}

return Tecla;

}				 
