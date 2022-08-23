/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  IntCtrl
 *
 *  Description:  Header file to write the fixed parameters that the user will write one time    
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
To define your grouping System you have to choose from:

XXX >> Write XXX to Declare your grouping System as 8 groups (0u:7u) and 1 Subgroup
XXY >> Write XXY to Declare your grouping System as 4 groups (0u:3u) and 2 Subgroups (0u:1u)
XYY >> Write XYY to Declare your grouping System as 2 groups (0u:1u) and 4 Subgroups (0u:3u)
YYY >> Write YYY to Declare your grouping System as 0 group  and 8 Subgroups (0u:7u)
*/
#define NVIC_GROUP_SYSTEM  XXY



/* 
This is to define the number of interrupts You'd like to enable 
write in this method >>> (Number of interrupts + u) eg. (3u)
*/
#define NUMBER_OF_VECTORS (3)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern NVIC_ConfigType NVIC_VectorControlArray[NUMBER_OF_VECTORS];

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
