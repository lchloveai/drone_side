#ifndef __LUATHREAD_H
#define __LUATHREAD_H	 

#include "led.h"                                     
#include "cmsis_os.h"     
#include <stdio.h>
#include "mculua.h"
#include "uartthread.h"   
#include "keythread.h"  

extern osThreadId lua_thread_id; 

int Init_lua_thread (void);

#endif
