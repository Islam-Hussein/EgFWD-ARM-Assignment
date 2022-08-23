/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  Header File that include all prototypes of functions in This Driver    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPT_Types.h"
#include "GPT_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void GPT_Init(const GPT_ConfigType *ConfigPtr)
 * \Description     : initialize GPT Module by parsing the Configuration 
*                    into GPT registers 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr  >>  Pointer to array of structs that hold all the configurations needed 
 * 						to initializes the Timers Needed to be activated
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void GPT_Init(const GPT_ConfigType* ConfigPtr);

/******************************************************************************
 * \Syntax          : void GPT_DisableNotification(GPT_ChannelType Channel)
 * \Description     : This function disables interrupt notification on the timer desired 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_DisableNotification(GPT_ChannelType Copy_GPTChannel);


/******************************************************************************
 * \Syntax          : void GPT_EnableNotification(GPT_ChannelType Channel, GPT_Notification CallBack)
 * \Description     : This function Enables interrupt notification on the timer desired 
 * 					and attaches the callback function into the right handler to be excuted
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * 					 Copy_GPTCallBack >> Callback Function that will be excuted when Timer interrupt is activated
 * 						
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_EnableNotification(GPT_ChannelType Copy_GPTChannel, GPT_Notification Copy_GPTCallBack);

/******************************************************************************
 * \Syntax          : GPT_ValueType Gpt_GetTimeElapsed( GPT_ChannelType Channel )
 * \Description     : This Function Returns the Value of the timer from the start 
 * 					to indicate how much time has passed since its cycle has started
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Number of Timer wanted to be be time returned
 * \Parameters (out): Loc_GPT_Value >> Value of time in the Register
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
GPT_ValueType Gpt_GetTimeElapsed( GPT_ChannelType Copy_GPTChannel );

/******************************************************************************
 * \Syntax          : void GPT_StartTimer(GPT_ChannelType Channel, GPT_ValueType Value)
 * \Description     : This Function Stops the Timer on the TimerType desired with the specific value of time in ms
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * 						ValueinMs	>> Value of Desired time to pass in milliseconds
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_StartTimer(GPT_ChannelType Copy_GPTChannel, GPT_ValueType Copy_GPTValueinMs);

/******************************************************************************
 * \Syntax          : void GPT_StopTimer(GPT_ChannelType Channel)
 * \Description     : This Function Stops the Timer on the TimerType desired
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Number of Timer wanted to be stopped
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_StopTimer(GPT_ChannelType Copy_GPTChannel);

/******************************************************************************
 * \Syntax          : void GPT_Attach(GPT_Notification CallBack,GPT_ValueType Value)
 * \Description     : This Function is used to make user only attach the callback function + Value of time in milliseconds 
 * 						if he wants to work with only one timer in his application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : CallBack >> Callback Function that will be excuted when Timer interrupt is activated
 * 					  ValueinMs	>> Value of Desired time to pass in milliseconds
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_Attach(GPT_Notification Copy_GPTCallBack,GPT_ValueType Copy_GPTValueinMs);



#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
