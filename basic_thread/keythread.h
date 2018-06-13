#ifndef __KEYTHREAD_H
#define __KEYTHREAD_H	 

#include "key.h"                                     
#include "cmsis_os.h"     

extern osThreadId key_thread_id; 
extern osThreadId current_key0_focus_thread_id; 
extern osThreadId current_key1_focus_thread_id; 

int Init_key_thread (void);

#endif
