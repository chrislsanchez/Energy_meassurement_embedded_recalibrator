/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE EXPLICITLY MARKED SECTIONS.
**
**     Project     : DeviceInitialization
**     Processor   : MC9S08QE32CLC
**     Version     : Component 01.005, Driver 01.08, CPU db: 3.00.027
**     Datasheet   : MC9S08QE32RM Rev. 3 Draft A 11/2009
**     Date/Time   : 2014-12-17, 19:41, # CodeGen: 29
**     Abstract    :
**         This module contains device initialization code 
**         for selected on-chip peripherals.
**     Contents    :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

#ifndef __DeviceInitialization_H
#define __DeviceInitialization_H 1

/* Include shared modules, which are used for whole project */


/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */

#ifdef __cplusplus
extern "C" {
#endif
extern void MCU_init(void);
#ifdef __cplusplus
}
#endif
/*
** ===================================================================
**     Method      :  MCU_init (component MC9S08QE32_32)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/



/*lint -save  -e765 Disable MISRA rule (8.10) checking. */
__interrupt void isrVsci2tx(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci2tx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVsci2rx(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci2rx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVsci2err(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci2err
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVadc(void);
/*
** ===================================================================
**     Interrupt handler : isrVadc
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVsci1tx(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci1tx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVsci1rx(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci1rx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVsci1err(void);
/*
** ===================================================================
**     Interrupt handler : isrVsci1err
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVtpm2ovf(void);
/*
** ===================================================================
**     Interrupt handler : isrVtpm2ovf
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVtpm1ovf(void);
/*
** ===================================================================
**     Interrupt handler : isrVtpm1ovf
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



__interrupt void isrVlvd(void);
/*
** ===================================================================
**     Interrupt handler : isrVlvd
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/





/*lint -restore Enable MISRA rule (8.10) checking. */

/* END DeviceInitialization */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/