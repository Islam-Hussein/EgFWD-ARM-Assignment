/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

uint8 Counter =0;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = (0x05FA<<16)|(NVIC_GROUP_SYSTEM<<8);
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	for( Counter=0; Counter<NUMBER_OF_VECTORS; Counter++ )
{
 #if (NVIC_GROUP_SYSTEM == XXX)
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].GroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+5));
 #elif (NVIC_GROUP_SYSTEM == XXY)
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].GroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+6));
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].SubGroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+5));
 #elif (NVIC_GROUP_SYSTEM == XYY)
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].GroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+7));
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].SubGroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+5));
 #elif (NVIC_GROUP_SYSTEM == YYY)
PRI(((NVIC_VectorControlArray[Counter].InterruptName)/4)) |= ((NVIC_VectorControlArray[Counter].SubGroupNumber)<<((((NVIC_VectorControlArray[Counter].InterruptName)%4)*8)+5));
#endif
}
   


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
for( Counter=0; Counter<NUMBER_OF_VECTORS; Counter++ )
{
   EN(((NVIC_VectorControlArray[Counter].InterruptName)/32)) |= 1<<((NVIC_VectorControlArray[Counter].InterruptName)%32);
}

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
