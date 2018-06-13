#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "string.h"	
#include "stm32f10x_usart.h"

void uart_init(uint32_t argument);
void copy_datas(uint8_t* buff1,uint8_t* buff2,uint8_t num);
void clear_str_temp(uint8_t* buff1,uint8_t num);

#endif


