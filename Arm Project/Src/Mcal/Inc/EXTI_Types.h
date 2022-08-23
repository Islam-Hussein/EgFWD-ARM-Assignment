/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EXTI_Types.h
 *       Module:  EXTI
 *
 *  Description:  This is a header file to introduce the driver types to the user 
 *                so he and the developer can use it in this driver     
 *  
 *********************************************************************************************************************/
#ifndef EXTI_TYPES_H
#define EXTI_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*

This Macro is used to indicate the number of Ports in the Micro Controller
In our case : A B C D E F = 6 Ports 
Written in a way (Number + u)  eg. (6u)

*/


#define NUM_OF_PORTS  (6u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*

This is a type for Writing Channels in the EXTI Driver. Starting from A0 to F4

*/


typedef enum 
{
EXTI_Channel_A0 ,
EXTI_Channel_A1 ,
EXTI_Channel_A2 ,
EXTI_Channel_A3 ,
EXTI_Channel_A4 ,
EXTI_Channel_A5 ,
EXTI_Channel_A6 ,
EXTI_Channel_A7 ,
EXTI_Channel_B0 ,
EXTI_Channel_B1 ,
EXTI_Channel_B2 ,
EXTI_Channel_B3 ,
EXTI_Channel_B4 ,
EXTI_Channel_B5 ,
EXTI_Channel_B6 ,
EXTI_Channel_B7 ,
EXTI_Channel_C0 ,
EXTI_Channel_C1 ,
EXTI_Channel_C2 ,
EXTI_Channel_C3 ,
EXTI_Channel_C4 ,
EXTI_Channel_C5 ,
EXTI_Channel_C6 ,
EXTI_Channel_C7 ,
EXTI_Channel_D0 ,
EXTI_Channel_D1 ,
EXTI_Channel_D2 ,
EXTI_Channel_D3 ,
EXTI_Channel_D4 ,
EXTI_Channel_D5 ,
EXTI_Channel_D6 ,
EXTI_Channel_D7 ,
EXTI_Channel_E0 ,
EXTI_Channel_E1 ,
EXTI_Channel_E2 ,
EXTI_Channel_E3 ,
EXTI_Channel_E4 ,
EXTI_Channel_E5 ,
EXTI_Channel_F0  =40 ,
EXTI_Channel_F1 ,
EXTI_Channel_F2 ,
EXTI_Channel_F3 ,
EXTI_Channel_F4 ,
EXTI_Channel_F5
}EXTI_ChannelType;

/*

This is a type for CallBackFunction Pointers in the EXTI Driver. 
Used with functions to pass functions as arguments.

*/

typedef void (*EXTI_CallBackFunctionType)();


/*

This is a type for Writing The Sense of you Pin in the EXTI Driver.
Options are : Level {High,Low}
              Edge {Rising,Falling}
              Both Edges

*/


typedef enum
{
EXTI_SenseHighLevel,
EXTI_SenseLowLevel,
EXTI_SenseRisingEdge,
EXTI_SenseFallingEdge,
EXTI_SenseBothEdges
}EXTI_SenseType;


/*

This is a type for Writing Ports in the EXTI Driver. 
Starting from A to F

*/

typedef enum
{
EXTI_PORTA,
EXTI_PORTB,
EXTI_PORTC,
EXTI_PORTD,
EXTI_PORTE,
EXTI_PORTF
}EXTI_PortType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* EXTI_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EXTI_Types.h
 *********************************************************************************************************************/
