#include<stdint.h>

#define SRAM_START       0x20000000UL
#define SRAM_SIZE        (96 * 1024) //96KB
#define SRAM_END         ((SRAM_START) + (SRAM_SIZE))

#define STACK_START      SRAM_END

extern uint32_t _etext;

extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

extern uint32_t _sbss;
extern uint32_t _ebss;

void __libc_init_array(void);

int main(void);


/* System exceptions */
void Reset_Handler(void);
void NMI_Handler(void) 						__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler(void) 				__attribute__((weak,alias("Default_Handler")));
void MemManage_Handler(void)				__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler(void)					__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler(void)				__attribute__((weak,alias("Default_Handler")));
void SVCall_Handler(void)					__attribute__((weak,alias("Default_Handler")));
void DebugMonitor_Handler(void)				__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler(void)					__attribute__((weak,alias("Default_Handler")));
void Systick_Handler(void)					__attribute__((weak,alias("Default_Handler")));

/* Peripheral interrupts (STM32F401) */
void WWDG_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void ADC_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void OTG_FS_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)			__attribute__((weak,alias("Default_Handler")));
void USART6_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)				__attribute__((weak,alias("Default_Handler")));
void FPU_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));
void SPI4_IRQHandler(void)					__attribute__((weak,alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
	STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,	//reserved 0x001C
	0,	//reserved 0x0020
	0,	//reserved 0x0024
	0,	//reserved 0x0028
	(uint32_t)&SVCall_Handler,
	(uint32_t)&DebugMonitor_Handler,
	0,	//reserved 0x0034
	(uint32_t)&PendSV_Handler,
	(uint32_t)&Systick_Handler,

	(uint32_t)&WWDG_IRQHandler,					//0
	(uint32_t)&PVD_IRQHandler,					//1
	(uint32_t)&TAMP_STAMP_IRQHandler,			//2
	(uint32_t)&RTC_WKUP_IRQHandler,				//3
	(uint32_t)&FLASH_IRQHandler,				//4
	(uint32_t)&RCC_IRQHandler,					//5
	(uint32_t)&EXTI0_IRQHandler,				//6
	(uint32_t)&EXTI1_IRQHandler,				//7
	(uint32_t)&EXTI2_IRQHandler,				//8
	(uint32_t)&EXTI3_IRQHandler,				//9
	(uint32_t)&EXTI4_IRQHandler,				//10
	(uint32_t)&DMA1_Stream0_IRQHandler,			//11
	(uint32_t)&DMA1_Stream1_IRQHandler,			//12
	(uint32_t)&DMA1_Stream2_IRQHandler,			//13
	(uint32_t)&DMA1_Stream3_IRQHandler,			//14
	(uint32_t)&DMA1_Stream4_IRQHandler,			//15
	(uint32_t)&DMA1_Stream5_IRQHandler,			//16
	(uint32_t)&DMA1_Stream6_IRQHandler,			//17
	(uint32_t)&ADC_IRQHandler,					//18
	0,											//19 reserved
	0,											//20 reserved
	0,											//21 reserved
	0,											//22 reserved
	(uint32_t)&EXTI9_5_IRQHandler,				//23
	(uint32_t)&TIM1_BRK_TIM9_IRQHandler,		//24
	(uint32_t)&TIM1_UP_TIM10_IRQHandler,		//25
	(uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,	//26
	(uint32_t)&TIM1_CC_IRQHandler,				//27
	(uint32_t)&TIM2_IRQHandler,					//28
	(uint32_t)&TIM3_IRQHandler,					//29
	(uint32_t)&TIM4_IRQHandler,					//30
	(uint32_t)&I2C1_EV_IRQHandler,				//31
	(uint32_t)&I2C1_ER_IRQHandler,				//32
	(uint32_t)&I2C2_EV_IRQHandler,				//33
	(uint32_t)&I2C2_ER_IRQHandler,				//34
	(uint32_t)&SPI1_IRQHandler,					//35
	(uint32_t)&SPI2_IRQHandler,					//36
	(uint32_t)&USART1_IRQHandler,				//37
	(uint32_t)&USART2_IRQHandler,				//38
	0,											//39 reserved
	(uint32_t)&EXTI15_10_IRQHandler,			//40
	(uint32_t)&RTC_Alarm_IRQHandler,			//41
	(uint32_t)&OTG_FS_WKUP_IRQHandler,			//42
	0,											//43 reserved
	0,											//44 reserved
	0,											//45 reserved
	0,											//46 reserved
	(uint32_t)&DMA1_Stream7_IRQHandler,			//47
	0,											//48 reserved
	(uint32_t)&SDIO_IRQHandler,					//49
	(uint32_t)&TIM5_IRQHandler,					//50
	(uint32_t)&SPI3_IRQHandler,					//51
	0,											//52 reserved
	0,											//53 reserved
	0,											//54 reserved
	0,											//55 reserved
	(uint32_t)&DMA2_Stream0_IRQHandler,			//56
	(uint32_t)&DMA2_Stream1_IRQHandler,			//57
	(uint32_t)&DMA2_Stream2_IRQHandler,			//58
	(uint32_t)&DMA2_Stream3_IRQHandler,			//59
	(uint32_t)&DMA2_Stream4_IRQHandler,			//60
	0,											//61 reserved
	0,											//62 reserved
	0,											//63 reserved
	0,											//64 reserved
	0,											//65 reserved
	0,											//66 reserved
	(uint32_t)&OTG_FS_IRQHandler,				//67
	(uint32_t)&DMA2_Stream5_IRQHandler,			//68
	(uint32_t)&DMA2_Stream6_IRQHandler,			//69
	(uint32_t)&DMA2_Stream7_IRQHandler,			//70
	(uint32_t)&USART6_IRQHandler,				//71
	(uint32_t)&I2C3_EV_IRQHandler,				//72
	(uint32_t)&I2C3_ER_IRQHandler,				//73
	0,											//74 reserved
	0,											//75 reserved
	0,											//76 reserved
	0,											//77 reserved
	0,											//78 reserved
	0,											//79 reserved
	0,											//80 reserved
	(uint32_t)&FPU_IRQHandler,					//81
	0,											//82 reserved
	0,											//83 reserved
	(uint32_t)&SPI4_IRQHandler,					//84
};

void Default_Handler(void){
	while(1);
}

void Reset_Handler(void){

	//copy .data section into SRAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata; //sram
	uint8_t *pSrc = (uint8_t*)&_la_data; //flash

	for(uint32_t i = 0 ; i < size ; i++){
		*pDst = *pSrc;
		pDst++;
		pSrc++;
	}

	//Init. the .bss section to zero in SRAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	
	pDst = (uint8_t*)&_sbss; 

	for(uint32_t i = 0 ; i < size ; i++){
		*pDst = 0;
		pDst++;
	}

	//Init. C std library
	__libc_init_array();

	//call main()
	main();

}
