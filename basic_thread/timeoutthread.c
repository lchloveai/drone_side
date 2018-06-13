#include "timeoutthread.h"   
 
void timeout_thread (void const *argument);                             // thread function

osThreadId timeout_thread_id;                                          // thread id
osThreadDef (timeout_thread, osPriorityHigh, 1, 0);                   // thread object

int Init_timeout_thread (void) {

  timeout_thread_id = osThreadCreate (osThread(timeout_thread), NULL);
  if (!timeout_thread_id) return(-1);
  
  return(0);
}

void timeout_thread (void const *argument) {
	TIM2_Int_Init();
  while (1) 
	{
		osSignalWait(TIME2_TIMEOUT_SIGNAL,osWaitForever);
		#ifdef USE_UART1
			if(uart1_receive_overtime)
			{
				osSignalSet(uart1_receive_thread_id,UART_RECRIVE_START_SIGNAL); //send the last signal
			}
		#endif
		#ifdef USE_UART2
			if(uart2_receive_overtime)
			{
				osSignalSet(uart2_receive_thread_id,UART_RECRIVE_START_SIGNAL); //send the last signal
			}
		#endif
		#ifdef USE_UART3
			if(uart3_receive_overtime)
			{
				osSignalSet(uart3_receive_thread_id,UART_RECRIVE_START_SIGNAL); //send the last signal
			}
		#endif
		#ifdef USE_UART4
			if(uart4_receive_overtime)
			{
				osSignalSet(uart4_receive_thread_id,UART_RECRIVE_START_SIGNAL); //send the last signal
			}
		#endif
  }
}
