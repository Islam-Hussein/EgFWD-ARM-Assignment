/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Types.h
 *       Module:  DIO
 *
 *  Description:  This is a header file to introduce the driver types to the user 
 *                so he and the developer can use it in this driver  
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_types.h"

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

This is A type for Writing Channels in the DIO Driver. Starting from A0 to F4

*/
typedef enum 
{
DIO_Channel_A0 ,
DIO_Channel_A1 ,
DIO_Channel_A2 ,
DIO_Channel_A3 ,
DIO_Channel_A4 ,
DIO_Channel_A5 ,
DIO_Channel_A6 ,
DIO_Channel_A7 ,
DIO_Channel_B0 ,
DIO_Channel_B1 ,
DIO_Channel_B2 ,
DIO_Channel_B3 ,
DIO_Channel_B4 ,
DIO_Channel_B5 ,
DIO_Channel_B6 ,
DIO_Channel_B7 ,
DIO_Channel_C0 ,
DIO_Channel_C1 ,
DIO_Channel_C2 ,
DIO_Channel_C3 ,
DIO_Channel_C4 ,
DIO_Channel_C5 ,
DIO_Channel_C6 ,
DIO_Channel_C7 ,
DIO_Channel_D0 ,
DIO_Channel_D1 ,
DIO_Channel_D2 ,
DIO_Channel_D3 ,
DIO_Channel_D4 ,
DIO_Channel_D5 ,
DIO_Channel_D6 ,
DIO_Channel_D7 ,
DIO_Channel_E0 ,
DIO_Channel_E1 ,
DIO_Channel_E2 ,
DIO_Channel_E3 ,
DIO_Channel_E4 ,
DIO_Channel_E5 ,
DIO_Channel_F0  =40 ,
DIO_Channel_F1 ,
DIO_Channel_F2 ,
DIO_Channel_F3 ,
DIO_Channel_F4 ,
DIO_Channel_F5

}DIO_ChannelType;


/*

This is a type for Writing Ports in the DIO Driver. Starting from A to F

*/

typedef enum
{
    DIO_PORTA ,
    DIO_PORTB ,
    DIO_PORTC ,
    DIO_PORTD ,
    DIO_PORTE ,
    DIO_PORTF
}DIO_PortType;

/*

This is A type for Writing Channel Levels in the DIO Driver. High or Low

*/

typedef enum
{
    DIO_LevelLow ,
    DIO_LevelHigh
}DIO_LevelType;


/*

This is A type for Writing Port Levels in the DIO Driver. From 0 to 255

*/

typedef uint8 DIO_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Types.h
 *********************************************************************************************************************/
