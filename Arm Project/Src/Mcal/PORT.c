/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "PORT_Cfg.h"
#include "PORT_Types.h"
#include "PORT.h"

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
 * \Syntax          : void PORT_Init (const Port_ConfigType* ConfigPtr[counter] )
 * \Description     : This Function is used to Initialize Ports as they are used to be in our Application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr[counter] >> Pointer to Struct that carries the whole data of ports
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void PORT_Init(const Port_ConfigType *ConfigPtr)
{
    volatile uint32 LocalBaseAddress;
    uint8 counter;
    for (counter = 0; counter < NUM_OF_PINS_ACTIVE; counter++)
    {
        switch (ConfigPtr[counter].Pin_Channel)
        {
        case PORT_Channel_A0 ... PORT_Channel_A7:
        {
            LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        }
        /* code */
        break;

        case PORT_Channel_B0 ... PORT_Channel_B7:
        {
            LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        }
        /* code */
        break;

        case PORT_Channel_C0 ... PORT_Channel_C7:
        {
            LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        }
        /* code */
        break;

        case PORT_Channel_D0 ... PORT_Channel_D7:
        {
            LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        }
        /* code */
        break;

        case PORT_Channel_E0 ... PORT_Channel_E5:
        {
            LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        }
        /* code */
        break;

        case PORT_Channel_F0 ... PORT_Channel_F4:
        {
            LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        }
        }

        switch (ConfigPtr[counter].PinType)
        {
        case Port_DIO:
            GPIO_GPIODEN(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;

        default:
            break;
        }

        switch (ConfigPtr[counter].PinDirection)
        {
        case Port_Input:
        {
            GPIO_GPIODIR(LocalBaseAddress) &= ~(1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;
        }
        case Port_Output:
        {
            GPIO_GPIODIR(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;
        }
        default:
            break;
        }

        switch (ConfigPtr[counter].PinInternalAttach)
        {
        case Port_PullDownResistor:
            GPIO_GPIOPDR(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;
        case Port_PullUpResistor:
            GPIO_GPIOPUR(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;
        case Port_OpenDrain:
            GPIO_GPIOODR(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;

        case Port_NoAttach:
            break;

        default:
            break;
        }

        switch (ConfigPtr[counter].PinOutputCurrent)
        {
        case Port_2maCurrent:
            GPIO_GPIODR2R(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;

        case Port_4maCurrent:
            GPIO_GPIODR4R(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;

        case Port_8maCurrent:
            GPIO_GPIODR8R(LocalBaseAddress) |= (1 << ((ConfigPtr[counter].Pin_Channel) % 8));
            break;

        default:
            break;
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
