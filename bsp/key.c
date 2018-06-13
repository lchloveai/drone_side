#include "key.h"

uint8_t key0_press_falg=0;
uint8_t key1_press_falg=0;

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;				
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;							
  NVIC_Init(&NVIC_InitStructure); 
		
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;								
  NVIC_Init(&NVIC_InitStructure);  	  
		
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Line=EXTI_Line1;	        
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	 
	 
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource13);
  EXTI_InitStructure.EXTI_Line=EXTI_Line13;	
  EXTI_Init(&EXTI_InitStructure);	 	
} 

void EXTI1_IRQHandler(void)
{
	osSignalSet(key_thread_id,KEY0_PRESSED_SIGNAL);
	key0_press_falg=1;
	EXTI->PR = EXTI_Line1;
}
void EXTI15_10_IRQHandler(void)
{
	osSignalSet(key_thread_id,KEY1_PRESSED_SIGNAL);
	key1_press_falg=1;
	EXTI->PR = EXTI_Line13;
}
