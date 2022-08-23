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
#include "EXTI.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
EXTI_CallBackFunctionType CallBackFunctionArr[NUM_OF_PORTS] = {NULL_PTR};
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
 * \Syntax          : void EXTI_AttachInterrupt(EXTI_ChannelType Copy_EXTI_Channel, EXTI_SenseType Copy_EXTI_Sense, EXTI_CallBackFunctionType Copy_EXTI_CallBackFunction)
 * \Description     : This Function is used to attach a callback function to the desired pin. it initializes and configures the pin as External interrupt
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_EXTI_Channel >>   Specific Channel that Wanted to be interrupt activated
 *                    Copy_EXTI_Sense   >>   Type of interrupt activation sense (level,edge)(high,low,both)
 *                    Copy_EXTI_CallBackFunction >> Callback Function that will be excuted when interrupt is activated
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void EXTI_AttachInterrupt(EXTI_ChannelType Copy_EXTI_Channel, EXTI_SenseType Copy_EXTI_Sense, EXTI_CallBackFunctionType Copy_EXTI_CallBackFunction)
{
    volatile EXTI_PortType LocalPort;
    volatile uint32 LocalBaseAddress;
    switch (Copy_EXTI_Channel)
    {
    case EXTI_Channel_A0 ... EXTI_Channel_A7:
        LocalBaseAddress = GPIOA_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTA;
        break;
    case EXTI_Channel_B0 ... EXTI_Channel_B7:
        LocalBaseAddress = GPIOB_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTB;
        break;
    case EXTI_Channel_C0 ... EXTI_Channel_C7:
        LocalBaseAddress = GPIOC_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTC;
        break;
    case EXTI_Channel_D0 ... EXTI_Channel_D7:
        LocalBaseAddress = GPIOD_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTD;
        break;
    case EXTI_Channel_E0 ... EXTI_Channel_E5:
        LocalBaseAddress = GPIOE_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTE;
        break;
    case EXTI_Channel_F0 ... EXTI_Channel_F4:
        LocalBaseAddress = GPIOF_APB_BASE_ADDRESS_MASK;
        LocalPort = EXTI_PORTF;
        break;
    default:
        break;
    }

    switch (Copy_EXTI_Sense)
    {
    case EXTI_SenseHighLevel:
        /* code */
        {
            GPIO_GPIOIS(LocalBaseAddress) |= (1 << (Copy_EXTI_Channel % 8));   // Level
            GPIO_GPIOIBE(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Event
            GPIO_GPIOIEV(LocalBaseAddress) |= (1 << (Copy_EXTI_Channel % 8));  // Rising or HIGH
        }
        break;
    case EXTI_SenseLowLevel:
        /* code */
        {
            GPIO_GPIOIS(LocalBaseAddress) |= (1 << (Copy_EXTI_Channel % 8));   // Level
            GPIO_GPIOIBE(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Event
            GPIO_GPIOIEV(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Falling or LOW
        }
        break;
    case EXTI_SenseRisingEdge:
        /* code */
        {
            GPIO_GPIOIS(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8));  // Edge
            GPIO_GPIOIBE(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Event
            GPIO_GPIOIEV(LocalBaseAddress) |= (1 << (Copy_EXTI_Channel % 8));  // Rising or HIGH
        }
        break;
    case EXTI_SenseFallingEdge:
        /* code */
        {
            GPIO_GPIOIS(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8));  // Edge
            GPIO_GPIOIBE(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Event
            GPIO_GPIOIEV(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Falling or LOW
        }
        break;
    case EXTI_SenseBothEdges:
        /* code */
        {
            GPIO_GPIOIS(LocalBaseAddress) &= ~(1 << (Copy_EXTI_Channel % 8)); // Edge
            GPIO_GPIOIBE(LocalBaseAddress) |= (1 << (Copy_EXTI_Channel % 8)); // Both Edges
        }
        break;

    default:
        break;
    }
    GPIO_GPIOCR(LocalBaseAddress) |= (1<<Copy_EXTI_Channel%8); // Clear interrupt mask
    CallBackFunctionArr[LocalPort] = Copy_EXTI_CallBackFunction; // put function if callback mode
    GPIO_GPIOIM(LocalBaseAddress) |= (1<<Copy_EXTI_Channel%8); // Enable interrupt
}





void GPIOA_Handler(void)
{
	
	static EXTI_CallBackFunctionType Local_EXTI_GPIO_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTA] != NULL)
	{
		Local_EXTI_GPIO_CallBackFunction = CallBackFunctionArr[EXTI_PORTA];
		Local_EXTI_GPIO_CallBackFunction();
	}
}


void GPIOB_Handler(void)
{
	
	static EXTI_CallBackFunctionType Local_EXTI_GPIO_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTB] != NULL)
	{
		Local_EXTI_GPIO_CallBackFunction = CallBackFunctionArr[EXTI_PORTB];
		Local_EXTI_GPIO_CallBackFunction();
	}
}

void GPIOC_Handler(void)
{
	
	static EXTI_CallBackFunctionType Local_EXTI_GPIOA_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTC] != NULL)
	{
		Local_EXTI_GPIOA_CallBackFunction = CallBackFunctionArr[EXTI_PORTC];
		Local_EXTI_GPIOA_CallBackFunction();
	}
}

void GPIOD_Handler(void)
{

	static EXTI_CallBackFunctionType Local_EXTI_GPIOA_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTD] != NULL)
	{
		Local_EXTI_GPIOA_CallBackFunction = CallBackFunctionArr[EXTI_PORTD];
		Local_EXTI_GPIOA_CallBackFunction();
	}
}

void GPIOE_Handler(void)
{
	
	static EXTI_CallBackFunctionType Local_EXTI_GPIOA_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTE] != NULL)
	{
		Local_EXTI_GPIOA_CallBackFunction = CallBackFunctionArr[EXTI_PORTE];
		Local_EXTI_GPIOA_CallBackFunction();
	}
}

void GPIOF_Handler(void)
{
	
	static EXTI_CallBackFunctionType Local_EXTI_GPIOA_CallBackFunction;
	if (CallBackFunctionArr[EXTI_PORTF] != NULL)
	{
		Local_EXTI_GPIOA_CallBackFunction = CallBackFunctionArr[EXTI_PORTF];
		Local_EXTI_GPIOA_CallBackFunction();
	}
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
