/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  GPT
 *
 *  Description:  This is a header file to introduce the driver types to the user 
 *                so he and the developer can use it in this driver
 *
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

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

This is a type for Timers used in this GPT Driver. 

*/


typedef enum
{
    GPT_16_32_BitTimer0,
    GPT_16_32_BitTimer1,
    GPT_16_32_BitTimer2,
    GPT_16_32_BitTimer3,
    GPT_16_32_BitTimer4,
    GPT_16_32_BitTimer5,
    GPT_32_64_BitWideTimer0,
    GPT_32_64_BitWideTimer1,
    GPT_32_64_BitWideTimer2,
    GPT_32_64_BitWideTimer3,
    GPT_32_64_BitWideTimer4,
    GPT_32_64_BitWideTimer5

} GPT_ChannelType;

/*

This is a type for Values used in this GPT Driver.
This Value is Put inside Load Registers 

*/

typedef uint32 GPT_ValueType;


/*

This is a type for CallBackFunction Pointers in the GPT Driver. 
Used with functions to pass functions as arguments.

*/


typedef void (*GPT_Notification)();


/*

This is a type for Frequency used in this GPT Driver.
This Value is Put to measure Prescaler

*/

typedef uint32 GPT_ChannelTickFrequency;


/*

This is a type for Values used in this GPT Driver.


*/
typedef uint32 GPT_ChannelTickValueMax;

/*

This is a type for Modes used in this GPT Driver.
Options are One shot mode or Periodic (Continous) Mode. 

*/

typedef enum
{
    GPT_ModeContinuous,
    GPT_ModeOneShot
} GPT_ChannelMode;

/*

This is a type for Modes used in this GPT Driver.
Options are Normal mode or Sleep Mode. 

*/

typedef enum
{
    GPT_ModeNormal,
    GPT_ModeSleep
} GPT_ModeType;


/*

This is a type for writing Predefined Timers in this GPT Driver.
Write the one you desire to operate with

*/

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
} GPT_PredefTimerType;

/*

This is a struct to collect all the information desired for a Timer to work properly in this GPT Driver.

*/

typedef struct 
{
    GPT_ChannelType ChannelType;
    GPT_ChannelTickFrequency ChannelTickFrequency;
    GPT_ChannelTickValueMax ChannelTickValueMax;
    GPT_ChannelMode ChannelMode;
} GPT_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/
