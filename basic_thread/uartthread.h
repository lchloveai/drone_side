#ifndef __UARTTHREAD_H
#define __UARTTHREAD_H	 

#include "usart.h"                                     
#include "cmsis_os.h"     
#include "rtx_signal.h"
//*************************************************************************************************************//
#define UART_DATATEMP_SIZE 200

#define USE_UART1
#define USE_UART2
//#define USE_UART3
//#define USE_UART4

#define UART_SEND_THREAD_NUM 2
#define UART_RECEIVE_THREAD_NUM 2

#ifdef USE_UART1
extern osPoolId  uart1_send_mpool;
extern osMessageQId  uart1_send_queue;
extern osPoolId  uart1_receive_mpool;
extern osMessageQId  uart1_receive_queue;
extern osThreadId uart1_send_thread_id;
extern osThreadId uart1_receive_thread_id; 
extern osThreadId uart1_current_send_thread_id;

extern uint8_t uart1_frame_start;
extern uint8_t uart1_receive_timerstart;
extern uint8_t uart1_receive_timecount;
extern uint8_t uart1_receive_overtime;
extern uint16_t uart1_receive_datacount;
#endif

#ifdef USE_UART2
extern osPoolId  uart2_send_mpool;
extern osMessageQId  uart2_send_queue;
extern osPoolId  uart2_receive_mpool;
extern osMessageQId  uart2_receive_queue;
extern osThreadId uart2_send_thread_id;
extern osThreadId uart2_receive_thread_id; 
extern osThreadId uart2_current_send_thread_id;

extern uint8_t uart2_frame_start;
extern uint8_t uart2_receive_timerstart;
extern uint8_t uart2_receive_timecount;
extern uint8_t uart2_receive_overtime;
extern uint16_t uart2_receive_datacount;
#endif

#ifdef USE_UART3
extern osPoolId  uart3_send_mpool;
extern osMessageQId  uart3_send_queue;
extern osPoolId  uart3_receive_mpool;
extern osMessageQId  uart3_receive_queue;
extern osThreadId uart3_send_thread_id;
extern osThreadId uart3_receive_thread_id; 
extern osThreadId uart3_current_send_thread_id;

extern uint8_t uart3_frame_start;
extern uint8_t uart3_receive_timerstart;
extern uint8_t uart3_receive_timecount;
extern uint8_t uart3_receive_overtime;
extern uint16_t uart3_receive_datacount;
#endif

#ifdef USE_UART4
extern osPoolId  uart4_send_mpool;
extern osMessageQId  uart4_send_queue;
extern osPoolId  uart4_receive_mpool;
extern osMessageQId  uart4_receive_queue;
extern osThreadId uart4_send_thread_id;
extern osThreadId uart4_receive_thread_id; 
extern osThreadId uart4_current_send_thread_id;

extern uint8_t uart4_frame_start;
extern uint8_t uart4_receive_timerstart;
extern uint8_t uart4_receive_timecount;
extern uint8_t uart4_receive_overtime;
extern uint16_t uart4_receive_datacount;
#endif

typedef struct {
	  uint16_t Datanum;
    uint8_t Datas[UART_DATATEMP_SIZE];
} uart_receive_msg_t;

typedef struct {
	  uint16_t Datanum;
    uint8_t *Datas;
} uart_send_msg_t;
//*************************************************************************************************************//

int Init_uart_send_thread (uint32_t argument);
void uart_send_thread (void const *argument);                             // thread function
void uart_send_datas(USART_TypeDef* USARTx, uint16_t num,uint8_t *datas);

//*************************************************************************************************************//

int Init_uart_receive_thread (uint32_t argument);
void uart_receive_thread (void const *argument);                             // thread function
//*************************************************************************************************************//
int SendChar(int ch);
int GetKey(void);
void yu_puts(char *datas,uint16_t num);
void yu_prints(const char *format,const char *str);
int yu_readline(char *prompt,char *line);

#endif
