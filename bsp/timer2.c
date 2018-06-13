#include "timer2.h"
#include "cmsis_os.h"     
#include "uartthread.h"  
#include "timeoutthread.h"   

void TIM2_Int_Init(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = 9;     //10us
	TIM_TimeBaseStructure.TIM_Prescaler =71;   //1MHZ(1us)
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
 
	TIM_ITConfig(TIM2, TIM_IT_Update ,ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  

	TIM_Cmd(TIM2, ENABLE); 
}

void TIM2_IRQHandler(void)   //10us
{
	#ifdef USE_UART1
		if(uart1_receive_timerstart)
		{
			uart1_receive_timecount++;
		}
		if(uart1_receive_timecount >= 30) // uart receive frame timeout(300us)
		{
			uart1_receive_timecount = 0;
			uart1_receive_timerstart = 0;
			uart1_receive_overtime = 1;
			osSignalSet(timeout_thread_id,TIME2_TIMEOUT_SIGNAL); 
		}
	#endif
	#ifdef USE_UART2
		if(uart2_receive_timerstart)
		{
			uart2_receive_timecount++;
		}
		if(uart2_receive_timecount >= 30) // uart receive frame timeout(300us)
		{
			uart2_receive_timecount = 0;
			uart2_receive_timerstart = 0;
			uart2_receive_overtime = 1;
			osSignalSet(timeout_thread_id,TIME2_TIMEOUT_SIGNAL); 
		}
	#endif	
	#ifdef USE_UART3
		if(uart3_receive_timerstart)
		{
			uart3_receive_timecount++;
		}
		if(uart3_receive_timecount >= 30) // uart receive frame timeout(300us)
		{
			uart3_receive_timecount = 0;
			uart3_receive_timerstart = 0;
			uart3_receive_overtime = 1;
			osSignalSet(timeout_thread_id,TIME2_TIMEOUT_SIGNAL); 
		}
	#endif	
	#ifdef USE_UART4
		if(uart4_receive_timerstart)
		{
			uart4_receive_timecount++;
		}
		if(uart4_receive_timecount >= 30) // uart receive frame timeout(300us)
		{
			uart4_receive_timecount = 0;
			uart4_receive_timerstart = 0;
			uart4_receive_overtime = 1;
			osSignalSet(timeout_thread_id,TIME2_TIMEOUT_SIGNAL); 
		}
	#endif		
	TIM2->SR &= 0XFFFE; //clear update flag
}











