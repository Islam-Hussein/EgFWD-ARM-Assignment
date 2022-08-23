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
#include "GPT_Types.h"

#include "GPT_Cfg.h"
#include "GPT.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 Gpt_BaseAddress[MAX_NUM_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER1_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER2_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER3_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER4_BASE_ADDRESS,
                                                            GPT_16_32_BIT_TIMER5_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
                                                            GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
GPT_Notification	locGptNotification[MAX_NUM_OF_GPIO_GPT];
static const GPT_ConfigType*			globalGptConfig;
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
 * \Syntax          : void GPT_Init(const GPT_ConfigType *ConfigPtr)
 * \Description     : initialize GPT Module by parsing the Configuration 
*                    into GPT registers 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : ConfigPtr  >>  Pointer to array of structs that hold all the configurations needed 
 * 						to initializes the Timers Needed to be activated
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_Init(const GPT_ConfigType *ConfigPtr)
{
    
	uint32 i,prescale;
	uint32 gptBaseAddress;
	GPT_ChannelType  					locChannel;
	GPT_ChannelMode								locChannelMode;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	GPT_ChannelTickValueMax  	locChannelTickMaxValue;
	globalGptConfig = ConfigPtr;
	
	for(i=0;i<NUM_ACTIVE_TIMERS;i++)
	{
		locChannel								= ConfigPtr[i].ChannelType;
		locChannelTickFreq				= ConfigPtr[i].ChannelTickFrequency;
		locChannelTickMaxValue		= ConfigPtr[i].ChannelTickValueMax;
		locChannelMode						= ConfigPtr[i].ChannelMode;
		
		
		gptBaseAddress = Gpt_BaseAddress[locChannel];

		/*RESET*/
		GPTMCTL(gptBaseAddress) =	0;
		
		/*
		* For a 16/32-bit timer, this value selects the 16-bit timer configuration. 
		* For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
		*/ /*Concatinated  0x00
			Non Concatinated 0x04  */
		GPTMCFG(gptBaseAddress) = 0x00;
		
		/* counting down  0
			Count Up 1						*/
		GPTMTAMR(gptBaseAddress) &= ~(1<<TACDIR);
		
		/* channel mode */
		if (locChannelMode == GPT_ModeOneShot)
		{
			GPTMTAMR(gptBaseAddress) |= 0x1;
		}
		else if (locChannelMode == GPT_ModeContinuous)
		{
			GPTMTAMR(gptBaseAddress) |= 0x2; 
		}
		
		/* Disablling interupt notifation */
		GPT_DisableNotification(locChannel);
	}


}

/******************************************************************************
 * \Syntax          : void GPT_DisableNotification(GPT_ChannelType Channel)
 * \Description     : This function disables interrupt notification on the timer desired 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_DisableNotification(GPT_ChannelType Copy_GPTChannel)
{
    uint32 gptBaseAddress;
    gptBaseAddress = Gpt_BaseAddress[Copy_GPTChannel];
    GPTMIMR(gptBaseAddress) = 0;
}

/******************************************************************************
 * \Syntax          : void GPT_EnableNotification(GPT_ChannelType Channel, GPT_Notification CallBack)
 * \Description     : This function Enables interrupt notification on the timer desired 
 * 					and attaches the callback function into the right handler to be excuted
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * 					 Copy_GPTCallBack >> Callback Function that will be excuted when Timer interrupt is activated
 * 						
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_EnableNotification(GPT_ChannelType Copy_GPTChannel, GPT_Notification Copy_GPTCallBack)
{

    uint32 gptBaseAddress;
	locGptNotification[Copy_GPTChannel] = Copy_GPTCallBack;
    gptBaseAddress = Gpt_BaseAddress[Copy_GPTChannel];
    GPTMIMR(gptBaseAddress) = 0x1;
	
}



/******************************************************************************
 * \Syntax          : GPT_ValueType Gpt_GetTimeElapsed( GPT_ChannelType Channel )
 * \Description     : This Function Returns the Value of the timer from the start 
 * 					to indicate how much time has passed since its cycle has started
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Number of Timer wanted to be be time returned
 * \Parameters (out): Loc_GPT_Value >> Value of time in the Register
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/

GPT_ValueType Gpt_GetTimeElapsed( GPT_ChannelType Copy_GPTChannel )
{
	GPT_ValueType Loc_GPT_Value;
	uint32 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	GPT_ChannelTickValueMax  	locChannelMaxValue;
	
	gptBaseAddress = Gpt_BaseAddress[Copy_GPTChannel];
	for(i=0;i<MAX_NUM_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].ChannelType == Copy_GPTChannel)
		{
			locChannelTickFreq = globalGptConfig[i].ChannelTickFrequency;
			locChannelMaxValue = globalGptConfig[i].ChannelTickValueMax;
			
			break;
		}
	}
	
	prescale = 16000000 / locChannelTickFreq;
	
	for(i=2;;i*=2)
	{
		if(prescale/i == 1)
		{
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	Loc_GPT_Value = (GPTMTAV(gptBaseAddress) / prescale) & locChannelMaxValue;
	
	return Loc_GPT_Value;
}

/******************************************************************************
 * \Syntax          : void GPT_StartTimer(GPT_ChannelType Channel, GPT_ValueType Value)
 * \Description     : This Function Stops the Timer on the TimerType desired with the specific value of time in ms
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Type of Timer wanted to be activated
 * 						ValueinMs	>> Value of Desired time to pass in milliseconds
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_StartTimer(GPT_ChannelType Copy_GPTChannel, GPT_ValueType Copy_GPTValueinMs)
{
    uint32 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	GPT_ChannelTickFrequency 	locChannelTickFreq;
	
	gptBaseAddress = Gpt_BaseAddress[Copy_GPTChannel];
		for(i=0;i<MAX_NUM_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].ChannelType == Copy_GPTChannel)
		{
			locChannelTickFreq = globalGptConfig[i].ChannelTickFrequency;			
			break;
		}
	}
	
	/* adding the value deppending on the freq required */
	GPTMTAILR(gptBaseAddress) = (Copy_GPTValueinMs*((16000000-1)/1000));
	
	GPTMCTL(gptBaseAddress) |= (1<<TAEN);
}

/******************************************************************************
 * \Syntax          : void GPT_StopTimer(GPT_ChannelType Channel)
 * \Description     : This Function Stops the Timer on the TimerType desired
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_GPTChannel >>   Number of Timer wanted to be stopped
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_StopTimer(GPT_ChannelType Copy_GPTChannel)
{
    uint32 gptBaseAddress;
    gptBaseAddress = Gpt_BaseAddress[Copy_GPTChannel];

    GPTMCTL(gptBaseAddress) &= (~(1 << TAEN));
}

/******************************************************************************
 * \Syntax          : void GPT_Attach(GPT_Notification CallBack,GPT_ValueType Value)
 * \Description     : This Function is used to make user only attach the callback function + Value of time in milliseconds 
 * 						if he wants to work with only one timer in his application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : CallBack >> Callback Function that will be excuted when Timer interrupt is activated
 * 					  ValueinMs	>> Value of Desired time to pass in milliseconds
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GPT_Attach(GPT_Notification Copy_GPTCallBack,GPT_ValueType Copy_GPTValueinMs)
{
	
	GPT_EnableNotification(GPT_16_32_BitTimer1,Copy_GPTCallBack);
 	GPT_StartTimer(GPT_16_32_BitTimer1,Copy_GPTValueinMs);
}



/************************************************************/

void TIMER0A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer0]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BitTimer0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BitTimer0];
		gptNotificationFn_TIMER0A();
	}
}

void TIMER1A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer1]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_16_32_BitTimer1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_16_32_BitTimer1];
		gptNotificationFn_TIMER1A();
	}
}

void TIMER2A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer2]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_16_32_BitTimer2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_16_32_BitTimer2];
		gptNotificationFn_TIMER2A();
	}
}

void TIMER3A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer3]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_16_32_BitTimer3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_16_32_BitTimer3];
		gptNotificationFn_TIMER3A();
	}
}

void TIMER4A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer4]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_16_32_BitTimer4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_16_32_BitTimer4];
		gptNotificationFn_TIMER4A();
	} 
}

void TIMER5A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_16_32_BitTimer0]) |= 1<<0;
	static GPT_Notification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_16_32_BitTimer5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_16_32_BitTimer5];
		gptNotificationFn_TIMER5A();
	}
}




void WTIMER0A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer0]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER0A;
	if (locGptNotification[GPT_32_64_BitWideTimer0] != NULL)
	{
		gptNotificationFn_WTIMER0A = locGptNotification[GPT_32_64_BitWideTimer0];
		gptNotificationFn_WTIMER0A();
	}
}

void WTIMER1A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer1]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER1A;
	if (locGptNotification[GPT_32_64_BitWideTimer1] != NULL)
	{
		gptNotificationFn_WTIMER1A = locGptNotification[GPT_32_64_BitWideTimer1];
		gptNotificationFn_WTIMER1A();
	}
}


void WTIMER2A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer2]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER2A;
	if (locGptNotification[GPT_32_64_BitWideTimer2] != NULL)
	{
		gptNotificationFn_WTIMER2A = locGptNotification[GPT_32_64_BitWideTimer2];
		gptNotificationFn_WTIMER2A();
	}
}


void WTIMER3A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer3]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER3A;
	if (locGptNotification[GPT_32_64_BitWideTimer3] != NULL)
	{
		gptNotificationFn_WTIMER3A = locGptNotification[GPT_32_64_BitWideTimer3];
		gptNotificationFn_WTIMER3A();
	}
}

void WTIMER4A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer4]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER4A;
	if (locGptNotification[GPT_32_64_BitWideTimer4] != NULL)
	{
		gptNotificationFn_WTIMER4A = locGptNotification[GPT_32_64_BitWideTimer4];
		gptNotificationFn_WTIMER4A();
	}
}

void WTIMER5A_Handler(void)
{
	GPTMICR(Gpt_BaseAddress[GPT_32_64_BitWideTimer5]) |= 1<<0;
	static GPT_Notification gptNotificationFn_WTIMER5A;
	if (locGptNotification[GPT_32_64_BitWideTimer5] != NULL)
	{
		gptNotificationFn_WTIMER5A = locGptNotification[GPT_32_64_BitWideTimer5];
		gptNotificationFn_WTIMER5A();
	}
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
