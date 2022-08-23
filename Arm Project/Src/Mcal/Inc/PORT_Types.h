/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port
 *
 *  Description:  This is a header file to introduce the driver types to the user 
 *                so he and the developer can use it in this driver   
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*

This is a type for Writing Channels in the PORT Driver. Starting from A0 to F4

*/


typedef enum 
{
PORT_Channel_A0 ,
PORT_Channel_A1 ,
PORT_Channel_A2 ,
PORT_Channel_A3 ,
PORT_Channel_A4 ,
PORT_Channel_A5 ,
PORT_Channel_A6 ,
PORT_Channel_A7 ,
PORT_Channel_B0 ,
PORT_Channel_B1 ,
PORT_Channel_B2 ,
PORT_Channel_B3 ,
PORT_Channel_B4 ,
PORT_Channel_B5 ,
PORT_Channel_B6 ,
PORT_Channel_B7 ,
PORT_Channel_C0 ,
PORT_Channel_C1 ,
PORT_Channel_C2 ,
PORT_Channel_C3 ,
PORT_Channel_C4 ,
PORT_Channel_C5 ,
PORT_Channel_C6 ,
PORT_Channel_C7 ,
PORT_Channel_D0 ,
PORT_Channel_D1 ,
PORT_Channel_D2 ,
PORT_Channel_D3 ,
PORT_Channel_D4 ,
PORT_Channel_D5 ,
PORT_Channel_D6 ,
PORT_Channel_D7 ,
PORT_Channel_E0 ,
PORT_Channel_E1 ,
PORT_Channel_E2 ,
PORT_Channel_E3 ,
PORT_Channel_E4 ,
PORT_Channel_E5 ,
PORT_Channel_F0  =40 ,
PORT_Channel_F1 ,
PORT_Channel_F2 ,
PORT_Channel_F3 ,
PORT_Channel_F4

}Port_ChannelType;

 /*

This is a type for Writing type of the pin 
which you'd like to use in your application in the Port Driver. 

*/
 
typedef enum 
{
  Port_DIO,
  Port_UART,
  Port_ADC ,
  Port_I2C ,
  Port_SPI ,
  Port_EXTI

}Port_PinType;


/*

This is a type for Writing Pin Direction of each Pin in the Port Driver. 
Input or Output

*/

typedef enum
{
Port_Input,
Port_Output
}Port_PinDirectionType;


/*

This is A type for Writing Channel Levels in the Port Driver. High or Low

*/



typedef enum
{
Port_LowLevel=0 ,
Port_HighLevel 
}Port_PinLevelValueType;

/*

This is A type for Writing the type of attachment for the input pins in the PORT Driver. 

*/


typedef enum
{
Port_PullUpResistor ,
Port_PullDownResistor,
Port_OpenDrain  ,
Port_NoAttach

}Port_PinInternalAttachType;

/*

This is A type for Writing the type of output current for the output pins in the PORT Driver. 

*/

typedef enum
{
Port_2maCurrent ,
Port_4maCurrent ,
Port_8maCurrent 
}Port_PinOutputCurrentType;

/*

This is a struct to collect all the information desired for Pins to work properly in this Port Driver.

*/

typedef struct 
{
    /* data */
    Port_ChannelType Pin_Channel;
    Port_PinType PinType;
    Port_PinDirectionType PinDirection;
    Port_PinInternalAttachType PinInternalAttach;
    Port_PinOutputCurrentType PinOutputCurrent;
}Port_ConfigType;






/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
