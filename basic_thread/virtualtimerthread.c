#include "virtualtimerthread.h"   
#include "uartthread.h"   

void virtualtimer_callback(void const *param);
osTimerDef(timer0_handle, virtualtimer_callback);

void Init_virtualtimer_thread (void) {
	osTimerId timer0 = osTimerCreate(osTimer(timer0_handle), osTimerPeriodic, NULL);	
	osTimerStart(timer0, 1);	
}

/*----------------------------------------------------------------------------
  Timer callback function. 
 *---------------------------------------------------------------------------*/
void virtualtimer_callback(void const *param)
{
	if(uart_receive_timerstart)
	{
		uart_receive_timecount++;
	}
	if(uart_receive_timecount >= 2) // uart receive frame timeout(2ms)
	{
		uart_receive_timecount = 0;
		uart_receive_timerstart = 0;
		uart_receive_overtime = 1;
		osSignalSet(current_uart_receive_thread_id,0x01); //send the last signal
	}
}
