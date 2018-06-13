#include "ledthread.h"   
 
void led_thread (void const *argument);                             // thread function


osThreadId led_thread_id;                                          // thread id
osThreadDef (led_thread, osPriorityNormal, 1, 0);                   // thread object

int Init_led_thread (void) {

  led_thread_id = osThreadCreate (osThread(led_thread), NULL);
  if (!led_thread_id) return(-1);
  
  return(0);
}

void led_thread (void const *argument) {
	LED_Initialize ();
  while (1) 
	{
		LED_On(0);
		osDelay(500);
		LED_Off(0);
		osDelay(500);
  }
}
