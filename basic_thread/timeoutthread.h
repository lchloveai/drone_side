#ifndef __TIMEOUTTHREAD_H
#define __TIMEOUTTHREAD_H	 

#include "timer2.h"                                     
#include "cmsis_os.h"     
#include "uartthread.h"  

extern osThreadId timeout_thread_id;  
int Init_timeout_thread (void);

#endif
