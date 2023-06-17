/******************************************************************************/
/* File   : EcuabCanTrcv.c                                                    */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgEcuabCanTrcv.h"
#include "infEcuabCanTrcvEcuabCanIf.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(boolean, ECUABCANTRCV_CODE) EcuabCanTrcvEcuabCanIf_GetFlagWakeup(void){
   boolean bRetVal;
   if(GPIO_input_read(
      GPIO_ERR_TJA) == 0){
      bRetVal = TRUE;
   }
   else{
      bRetVal = FALSE;
   }
   return bRetVal;
}

FUNC(void, ECUABCANTRCV_CODE) EcuabCanTrcvEcuabCanIf_SetModeNormal(void){
   GPIO_output_on(GPIO_STB_TJA);
   GPIO_output_on(GPIO_EN_TJA);
}

FUNC(void, ECUABCANTRCV_CODE) EcuabCanTrcvEcuabCanIf_SetModeStandby(void){
   GPIO_output_off(GPIO_EN_TJA);
   WaitHard(20);
   GPIO_output_off(GPIO_STB_TJA);
   WaitHard(20);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

