#include "cc1101thread.h"  



void cc1101_thread (void const *argument);                             // thread function

osThreadId cc1101_thread_id;                                          // thread id
osThreadDef (cc1101_thread, osPriorityNormal, 1, 512);                   // thread object

u8 local_uavid[8] = "2750946F";
u8 wireless_data[23]={0};
u8 bat_power[3]="012";
u8 charge_site_addr;

int Init_cc1101_thread (void) {

  cc1101_thread_id = osThreadCreate (osThread(cc1101_thread), NULL);
  if (!cc1101_thread_id) return(-1);
  
  return(0);
}

void wireless_data_init()
{
	wireless_data[0]=0xeb;
	wireless_data[1]=charge_site_addr;
	wireless_data[2]=0x01;
	wireless_data[3]=0x13;
	wireless_data[4]='i';
	wireless_data[5]='d';
	wireless_data[6]=':';
	copy_datas(wireless_data+7,local_uavid,8);
	wireless_data[15]=',';
	wireless_data[16]='p';
	wireless_data[17]='o';
	wireless_data[18]='w';	
	wireless_data[19]=':';	
	copy_datas(wireless_data+20,bat_power,3);
}

void cc1101_send_data(u8 *data,u16 num)
{
	uart_send_msg_t *uart_send_msg;
	uart_send_msg = (uart_send_msg_t*)osPoolAlloc(uart1_send_mpool);											//Allocate a memory pool buffer
	uart_send_msg->Datanum = num;
	uart_send_msg->Datas=data;
	osMessagePut(uart1_send_queue, (uint32_t)uart_send_msg, osWaitForever);				//Post pointer to memory pool buffer
	osSignalWait(UART_SEND_FINISH_SIGNAL,osWaitForever);
}

void cc1101_thread (void const *argument) {       
	osEvent evt;	
	uart1_current_send_thread_id = cc1101_thread_id;
  while (1){
		evt = osMessageGet(uart1_receive_queue, osWaitForever);						//wait for message to arrive
		if (evt.status == osEventMessage) {													//check we have received a message
			uart_receive_msg_t *uart_receive_msg = (uart_receive_msg_t*)evt.value.p;
			if(uart_receive_msg->Datanum >4)
			{
				if(uart_receive_msg->Datas[0]==0xeb)
				{
					charge_site_addr=uart_receive_msg->Datas[1];
					if(uart_receive_msg->Datas[2]==1)//get charge site cmd
					{
						if(uart_receive_msg->Datas[3]==1)//nums
						{
							if(uart_receive_msg->Datas[4]=='g')
							{
								wireless_data_init();
								cc1101_send_data(wireless_data,23);
							}
						}
					}
				}
			}
			osPoolFree(uart1_receive_mpool, uart_receive_msg);															//Release the buffer
		}
}}

