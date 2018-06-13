#ifndef __KEY_H
#define __KEY_H	 

#include "stm32f10x_gpio.h"
#include "keythread.h"   
#include "rtx_signal.h"

#define KEY0  (GPIOC->IDR & GPIO_Pin_1)
#define KEY1  (GPIOC->IDR & GPIO_Pin_13)
 
extern uint8_t key0_press_falg;
extern uint8_t key1_press_falg;

void KEY_Init(void);
			    
#endif
