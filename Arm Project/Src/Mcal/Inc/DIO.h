/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  Header File that include all prototypes of functions in This Driver
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Types.h"



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
 * \Syntax          : DIO_LevelType DIO_ReadChannel(DIO_ChannelType Copy_DIO_ChannelId)
 * \Description     : This function is used to read channels of DIO Ports and return High or low Value
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_DIO_ChannelId >>  Number of Channel wanted to be read
 * \Parameters (out): State of This Channel
 * \Return value:   : HIGH/LOW
 *******************************************************************************/


DIO_LevelType DIO_ReadChannel(DIO_ChannelType Copy_DIO_ChannelId);



/******************************************************************************
 * \Syntax          : void DIO_WrtieChannel(DIO_ChannelType Copy_DIO_ChannelId, DIO_LevelType Copy_DIO_Level)
 * \Description     : This function is used to write on channels of DIO Ports
 *                      by Putting High or low Value on the pin
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Copy_DIO_ChannelId >>  Number of Channel wanted to be read
 *                      Copy_DIO_Level   >> Type of Copy_DIO_Level you want to Set this pin with 
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void DIO_WrtieChannel(DIO_ChannelType Copy_DIO_ChannelId,DIO_LevelType Copy_DIO_Level);



/******************************************************************************
 * \Syntax          : DIO_PortLevelType DIO_ReadPort(DIO_PortType Copy_DIO_PortId)
 * \Description     : This function is used to read DIO Ports and return Whole Value of Pins all together
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Copy_DIO_PortId >>  Type of Port wanted to be read
 * \Parameters (out): GPIO_GPIODATA(LocalBaseAddress)
 *                      >> Value of Register Holding the values of the port pins all together
 * \Return value:   : 0 : 255
 *******************************************************************************/
DIO_PortLevelType DIO_ReadPort (DIO_PortType Copy_DIO_PortId);



/******************************************************************************
 * \Syntax          : void DIO_WritePort(DIO_PortType Copy_DIO_PortId, DIO_PortLevelType Copy_DIO_Level)
 * \Description     : This function is used to write on DIO Ports
 *                      by Putting Whole Values on the pin all together
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Copy_DIO_PortId    >>  Type of Port wanted to be read
 *                      Copy_DIO_Level   >> Type of Copy_DIO_Level you want to Set this pin with 
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void DIO_WritePort (DIO_PortType Copy_DIO_PortId,DIO_PortLevelType Copy_DIO_Level);



/******************************************************************************
 * \Syntax          : DIO_LevelType DIO_FlipChannel(DIO_ChannelType Copy_DIO_ChannelId)
 * \Description     : This function is used to Flip Value on channels of DIO Ports
 *                      by Putting High or low Value on the pin
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Copy_DIO_ChannelId >>  Number of Channel wanted to be read
 *
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void DIO_FlipChannel(DIO_ChannelType Copy_DIO_ChannelId);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
