#include "keythread.h"   

void key_thread (void const *argument);                             // thread function

osThreadId key_thread_id;                                          // thread id
osThreadDef (key_thread, osPriorityHigh, 1, 0);                   // thread object

osThreadId current_key0_focus_thread_id; 
osThreadId current_key1_focus_thread_id; 

int Init_key_thread (void) {

  key_thread_id = osThreadCreate (osThread(key_thread), NULL);
  if (!key_thread_id) return(-1);
  
  return(0);
}

void key_thread (void const *argument) {
	KEY_Init();
  while (1) 
	{
		osSignalWait(0x01,osWaitForever);	
		if(key0_press_falg)
		{
			key0_press_falg = 0;
			osDelay(20);
			if(KEY0 == 0)
			{
				if(current_key0_focus_thread_id)
				{
					osSignalSet(current_key0_focus_thread_id,KEY0_PRESSED_SIGNAL);
				}
			}
		}
		if(key1_press_falg)
		{
			key1_press_falg = 0;
			osDelay(20);
			if(KEY1 == 0)
			{
				if(current_key1_focus_thread_id)
				{
					osSignalSet(current_key1_focus_thread_id,KEY1_PRESSED_SIGNAL);
				}
			}
		}		
  }
}
