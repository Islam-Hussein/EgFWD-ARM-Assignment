/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  This is a header file to introduce the driver types to the user 
 *                so he and the developer can use it in this driver     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*This Macros are used by user and converted to driver by using those numbers 
in the register to identify the grouping and subgrouping system */
#define XXX     (4)
#define XXY      (5)
#define XYY     (6)
#define YYY     (7)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*

This is a type for Nvic Interrupt thar are there in this IntCtrl Driver.
Each one has the Offset to bu used and called with

*/

typedef enum
{
    NVIC_GPIO_PORT_A                ,
    NVIC_GPIO_PORT_B                ,
    NVIC_GPIO_PORT_C                ,
    NVIC_GPIO_PORT_D                ,
    NVIC_GPIO_PORT_E                ,
    NVIC_UART_0                     ,
    NVIC_UART_1                     ,
    NVIC_SSI_0                      ,
    NVIC_I2C_0                      ,
    NVIC_PWM_0_FAULT                ,
    NVIC_PWM_0_GEN_0                ,
    NVIC_PWM_0_GEN_1                ,
    NVIC_PWM_0_GEN_2                ,
    NVIC_QEI_0                      ,
    NVIC_ADC_0_SEQ_0                ,
    NVIC_ADC_0_SEQ_1                ,
    NVIC_ADC_0_SEQ_2                ,
    NVIC_ADC_0_SEQ_3                ,
    NVIC_TIMER_WATCHDOG_0_1         ,
    NVIC_16_32_TIMER_0_A            ,
    NVIC_16_32_TIMER_0_B            ,
    NVIC_16_32_TIMER_1_A            ,
    NVIC_16_32_TIMER_1_B            ,
    NVIC_16_32_TIMER_2_A            ,
    NVIC_16_32_TIMER_2_B            ,
    NVIC_ANALOG_COMPARATOR_0        ,
    NVIC_ANALOG_COMPARATOR_1        ,
    NVIC_SYSTEM_CONTROL = 28        ,
    NVIC_FLASH_EEPROM_MEMORY_CONTROL,
    NVIC_GPIO_PORT_F                 ,
    NVIC_UART_2 = 33                ,
    NVIC_SSI_1                      ,
    NVIC_16_32_TIMER_3_A            ,
    NVIC_16_32_TIMER_3_B            ,
    NVIC_I2C_1                      ,
    NVIC_QEI_1                      ,
    NVIC_CAN_0                      ,
    NVIC_CAN_1                      ,
    NVIC_HIBERNATION = 43           ,
    NVIC_USB                        ,            
    NVIC_PWM_GEN_3                  ,            
    NVIC_UDMA_SOFTWARE              ,
    NVIC_UDMA_ERROR                 ,     
    NVIC_ADC_1_SEQ_0                ,
    NVIC_ADC_1_SEQ_1                ,
    NVIC_ADC_1_SEQ_2                ,
    NVIC_ADC_1_SEQ_3                ,
    NVIC_SSI_2 = 57                 ,
    NVIC_SSI_3                      ,                
    NVIC_UART_3                     ,
    NVIC_UART_4                     ,
    NVIC_UART_5                     ,
    NVIC_UART_6                     ,
    NVIC_UART_7                     ,
    NVIC_I2C_2 = 68                 ,
    NVIC_I2C_3                      ,
    NVIC_16_32_TIMER_4_A            ,
    NVIC_16_32_TIMER_4_B            ,
    NVIC_16_32_TIMER_5_A = 92       ,
    NVIC_16_32_TIMER_5_B            ,
    NVIC_32_64_TIMER_0_A            ,
    NVIC_32_64_TIMER_0_B            ,
    NVIC_32_64_TIMER_1_A            ,
    NVIC_32_64_TIMER_1_B            ,
    NVIC_32_64_TIMER_2_A            ,
    NVIC_32_64_TIMER_2_B            ,
    NVIC_32_64_TIMER_3_A            ,
    NVIC_32_64_TIMER_3_B            ,
    NVIC_32_64_TIMER_4_A            ,
    NVIC_32_64_TIMER_4_B            ,
    NVIC_32_64_TIMER_5_A            ,
    NVIC_32_64_TIMER_5_B            ,
    NVIC_SYSTEM_EXCEPTION           ,
    NVIC_PWM_1_GEN_0 = 134          ,
    NVIC_PWM_1_GEN_1                ,
    NVIC_PWM_1_GEN_2                ,
    NVIC_PWM_1_GEN_3                ,
    NVIC_PWM_1_FAULT
}NVIC_InterruptsType;


/*

Those Types are used to Identify Group and SubGroup Priority

*/

typedef uint8 NVIC_GroupPriorityType;
typedef uint8 NVIC_SubGroupPriorityType;
 

/*

This is a struct to collect all the information desired 
for a Timer to work properly in this IntCtrl Driver.

*/

 typedef struct 
 {
    /****** This is where you write your interrupt perephiral***/
    NVIC_InterruptsType InterruptName;

    /***** This is where you write your group priopirty for your perephiral***/
    NVIC_GroupPriorityType GroupNumber;

    /***** This is where you write your Subgroup priopirty for your perephiral***/
    NVIC_SubGroupPriorityType SubGroupNumber;

    /* data */
 }NVIC_ConfigType;
 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
