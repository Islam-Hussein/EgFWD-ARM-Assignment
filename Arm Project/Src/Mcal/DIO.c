/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief    Digital Input Output Driver
 *
 *      \details    This Driver Controls all DIO functions whether to read or write Channels 
 *                  or you can read and write in whole Ports
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
#include "DIO_Types.h"
#include "DIO.h"

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
 * \Syntax          : DIO_LevelType DIO_ReadChannel(DIO_ChannelType Copy_DIO_ChannelId)
 * \Description     : This function is used to read channels of DIO Ports and return High or low Value
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_DIO_ChannelId >>  Number of Channel wanted to be read
 * \Parameters (out): State of This Channel
 * \Return value:   : HIGH/LOW
 *******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType Copy_DIO_ChannelId)
{
    volatile uint32 LocalBaseAddress;
    DIO_LevelType DIO_ReturnValue = 0;
    switch (Copy_DIO_ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F4:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;

    default:
        break;
    }
    DIO_ReturnValue = (*(volatile uint32 *)(LocalBaseAddress + (1 << (Copy_DIO_ChannelId % 8))));

    if (DIO_ReturnValue == DIO_LevelLow)
    {
        return DIO_LevelLow;
    }
    else
    {
        return DIO_LevelHigh;
    }
}

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
void DIO_WrtieChannel(DIO_ChannelType Copy_DIO_ChannelId, DIO_LevelType Copy_DIO_Level)
{
    volatile uint32 LocalBaseAddress;
    switch (Copy_DIO_ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F5:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    }

    (*(volatile uint32 *)(LocalBaseAddress + (1 << ((Copy_DIO_ChannelId % 8) + 2)))) = Copy_DIO_Level * 255;
}

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
DIO_PortLevelType DIO_ReadPort(DIO_PortType Copy_DIO_PortId)
{
    volatile uint32 LocalBaseAddress;
    switch (Copy_DIO_PortId)
    {
    case DIO_PORTA:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTB:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTC:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTD:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTE:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTF:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }

    return GPIO_GPIODATA(LocalBaseAddress);
}

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
void DIO_WritePort(DIO_PortType Copy_DIO_PortId, DIO_PortLevelType Copy_DIO_Level)
{
    volatile uint32 LocalBaseAddress;
    switch (Copy_DIO_PortId)
    {
    case DIO_PORTA:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTB:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTC:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTD:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTE:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_PORTF:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }

    GPIO_GPIODATA(LocalBaseAddress) = Copy_DIO_Level;
}

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
void DIO_FlipChannel(DIO_ChannelType Copy_DIO_ChannelId)
{
    volatile uint32 LocalBaseAddress;
    switch (Copy_DIO_ChannelId)
    {
    case DIO_Channel_A0 ... DIO_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;

        break;
    case DIO_Channel_B0 ... DIO_Channel_B7:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_C0 ... DIO_Channel_C7:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_D0 ... DIO_Channel_D7:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_E0 ... DIO_Channel_E5:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        break;
    case DIO_Channel_F0 ... DIO_Channel_F4:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        break;
    }
    TOG_BIT(GPIO_GPIODATA(LocalBaseAddress), (Copy_DIO_ChannelId % 8));
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
