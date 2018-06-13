#include "adcthread.h"   
 
void adc_thread (void const *argument);                             // thread function


osThreadId adc_thread_id;                                          // thread id
osThreadDef (adc_thread, osPriorityNormal, 1, 0);                   // thread object

u16 drone_power_adc_val = 0;

int Init_adc_thread (void) {

  adc_thread_id = osThreadCreate (osThread(adc_thread), NULL);
  if (!adc_thread_id) return(-1);
  
  return(0);
}

void adc_thread (void const *argument) {
	Adc_Init();
  while (1) 
	{
		drone_power_adc_val = Get_Adc_Average(ADC_Channel_1,10); 
		osDelay(1000);

  }
}
