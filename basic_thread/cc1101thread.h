#ifndef __CC1101THREAD_H
#define __CC1101THREAD_H	 
#include "uartthread.h"                              
#include "cmsis_os.h"     

extern u8 bat_power[3];

int Init_cc1101_thread (void);

#endif
