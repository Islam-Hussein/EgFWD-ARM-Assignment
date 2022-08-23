/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEN  :3;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define RCGCGPIO                                *((volatile uint32*)( 0x400FE000 +0x608))
#define RCGCTIMER                               *((volatile uint32*)( 0x400FE000 +0x604))
#define RCGCWTIMER                              *((volatile uint32*)( 0x400FE000 +0x65C))
/*tHIS SECTION IS FOR System Timer (SysTick) Registers*/
#define STCTRL                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))
#define STRELOAD                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014))
#define STCURRENT                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018))

/*This Section is for NVIC Registers*/


#define EN(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100+offset)))
#define EN0                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

#define DIS(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180+offset)))
#define DIS0                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4                                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

#define PEND0                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))  
#define PEND1                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))  
#define PEND2                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))  
#define PEND3                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))  
#define PEND4                                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))  


#define UNPEND0                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))  
#define UNPEND1                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))  
#define UNPEND2                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))  
#define UNPEND3                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
#define UNPEND4                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))

#define ACTIVE0                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define ACTIVE1                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
#define ACTIVE2                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
#define ACTIVE3                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
#define ACTIVE4                                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))

#define PRI_BASE_MASK                       0xE000E400
#define PRI(offset)                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400+offset)))
#define PRI0                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define PRI5                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define PRI6                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define PRI7                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define PRI8                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define PRI9                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define PRI10                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define PRI11                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define PRI12                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define PRI13                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define PRI14                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define PRI15                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define PRI16                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define PRI17                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define PRI18                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define PRI19                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define PRI20                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define PRI21                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define PRI22                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define PRI23                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define PRI24                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define PRI25                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define PRI26                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define PRI27                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define PRI28                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define PRI29                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define PRI30                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define PRI31                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define PRI32                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define PRI33                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define PRI34                                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))



/*This section is for GPIO Registers*/

#define GPIO_GPIODATA(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x3FC))
#define GPIO_GPIODIR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x400))
#define GPIO_GPIOIS(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x404))
#define GPIO_GPIOIBE(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x408))
#define GPIO_GPIOIEV(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x40C))
#define GPIO_GPIOIM(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x410))
#define GPIO_GPIORIS(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x414))
#define GPIO_GPIOMIS(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x418))
#define GPIO_GPIOICR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x41C))
#define GPIO_GPIOFSEL(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x420))
#define GPIO_GPIODR2R(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x500))
#define GPIO_GPIODR4R(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x504))
#define GPIO_GPIODR8R(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x508))
#define GPIO_GPIOODR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x50C))
#define GPIO_GPIOPUR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x510))
#define GPIO_GPIOPDR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x514))
#define GPIO_GPIOSLR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x518))
#define GPIO_GPIODEN(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x51C))
#define GPIO_GPIOLOCK(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x520))
#define GPIO_GPIOCR(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x524))
#define GPIO_GPIOMSEL(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x528))
#define GPIO_GPIOPCTL(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x52C))
#define GPIO_GPIODCCTL(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x530))
#define GPIO_GPIODMACTL(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0x534))
#define GPIO_GPIOPeriphlD4(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFD0))
#define GPIO_GPIOPeriphlD5(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFD4))
#define GPIO_GPIOPeriphlD6(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFD8))
#define GPIO_GPIOPeriphlD7(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFDC))
#define GPIO_GPIOPeriphlD0(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFE0))
#define GPIO_GPIOPeriphlD1(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFE4))
#define GPIO_GPIOPeriphlD2(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFE8))
#define GPIO_GPIOPeriphlD3(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFEC))
#define GPIO_GPIOPCellID0(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFF0))
#define GPIO_GPIOPCellID1(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFF4))
#define GPIO_GPIOPCellID2(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFF8))
#define GPIO_GPIOPCellID3(GPIO_APB_BASE_ADDRESS_MASK)                            *((volatile uint32*)(GPIO_APB_BASE_ADDRESS_MASK+0xFFC))


/*GPIO A*/

#define GPIOA_APB_BASE_ADDRESS_MASK                       0x40004000
#define GPIOA_AHB_BASE_MASK                       0x40058000

/*GPIO B*/

#define GPIOB_APB_BASE_ADDRESS_MASK                    0x40005000
#define GPIOB_AHB_BASE_MASK                           0x40059000    

/*GPIO C*/

#define GPIOC_APB_BASE_ADDRESS_MASK                    0x40006000
#define GPIOC_AHB_BASE_MASK                           0x4005A000   

/*GPIO D*/

#define GPIOD_APB_BASE_ADDRESS_MASK                    0x40007000
#define GPIOD_AHB_BASE_MASK                           0x4005B000   

/*GPIO E*/

#define GPIOE_APB_BASE_ADDRESS_MASK                0x40024000
#define GPIOE_AHB_BASE_MASK                           0x4005C000   

/*GPIO F*/

#define GPIOF_APB_BASE_ADDRESS_MASK                0x40025000
#define GPIOF_AHB_BASE_MASK                         0x4005D000  

 
/*************GPT TIMERS**************/


#define GPT_16_32_BIT_TIMER0_BASE_ADDRESS							0x40030000
#define	GPT_16_32_BIT_TIMER1_BASE_ADDRESS							0x40031000
#define	GPT_16_32_BIT_TIMER2_BASE_ADDRESS							0x40032000
#define	GPT_16_32_BIT_TIMER3_BASE_ADDRESS							0x40033000
#define	GPT_16_32_BIT_TIMER4_BASE_ADDRESS							0x40034000
#define	GPT_16_32_BIT_TIMER5_BASE_ADDRESS							0x40035000
#define	GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS				0x40036000
#define	GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS				0x40037000
#define	GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS				0x4004C000
#define	GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS				0x4004D000
#define	GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS				0x4004E000
#define	GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS				0x4004F000

#define GPTMCFG_OFFSET					0x000
#define GPTMTAMR_OFFSET					0x004
#define GPTMTBMR_OFFSET					0x008
#define GPTMCTL_OFFSET					0x00C
#define GPTMIMR_OFFSET					0x018
#define GPTMTAV_OFFSET					0x050
#define GPTMTAILR_OFFSET				0x028
#define GPTMRIS_OFFEST                  0x01C
#define GPTMICR_OFFSET                   0x024


#define GPTMCFG(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCFG_OFFSET))
#define GPTMTAMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAMR_OFFSET))
#define GPTMTBMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTBMR_OFFSET))
#define GPTMCTL(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCTL_OFFSET))	
#define GPTMIMR(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMIMR_OFFSET))
#define GPTMTAV(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMTAV_OFFSET))
#define GPTMTAILR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAILR_OFFSET))
#define GPTMRIS(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMRIS_OFFEST))
#define GPTMICR(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMICR_OFFSET))

#define TAEN 		0
#define TBEN 		8

#define TACDIR	4
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
