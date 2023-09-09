/**********************************************************
                       ��������
										 
���ܣ�stm32f103rct6���ƣ�20MHzʱ�ӣ�20��Ƶ�� AD9954���Ҳ���Ƶ�����LCD��ʾ��
			��������Ƶ�ʣ������м���л�ɨƵ����������
			��ʾ��12864cog
�ӿڣ����ƽӿ������AD9954.h  �����ӿ������key.h
ʱ�䣺2023/06/xx
�汾��4.3
���ߣ���������
������������ֻ��ѧϰʹ�ã�����ؾ���

					AD9959			��Ƭ��
Ӳ������:	AD9954_CS 	PA3
					AD9954_SCLK PA4	
					AD9954_SDIO PA5	
					AD9954_OSK 	PC0
					PS1 				PA2
					PS0 				PB10
					IOUPDATE 		PA7
					AD9954_SDO	PA8
					AD9954_IOSY PB1
					AD9954_RES 	PA6
					AD9954_PWR 	PB0
					GND				--GND(0V)  
					
������������뵽�Ա��꣬�������ӽ߳�Ϊ������ ^_^
https://kvdz.taobao.com/ 

**********************************************************/

#include "stm32_config.h"
#include "stdio.h"
#include "led.h"
#include "lcd.h"
#include "AD9954.h" 
#include "key.h"
#include "timer.h"
#include "task_manage.h"

char str[30];	//��ʾ����
extern u8 _return;
int main(void)
{
	u16 i=0;

	MY_NVIC_PriorityGroup_Config(NVIC_PriorityGroup_2);	//�����жϷ���
	delay_init(72);	//��ʼ����ʱ����
	LED_Init();	//��ʼ��LED�ӿ�
	key_init();
	initial_lcd();
	LCD_Clear();
	delay_ms(100);
	LCD_Refresh_Gram();
	
	//��ʱ��
	Timerx_Init(99,71);
	LCD_Clear();
	
	AD9954_Init();
	AD9954_Set_Fre(1000);//дƵ��1kHz
	AD9954_Set_Amp(16383);//0~16383��Ӧ���ֵ0mv~500mv(����)
	
	//1��
	//���������漰���漰�����������ܣ�Ƶ�ʻ���Ȼ������������ܱ���д�����ܵ��´˴����Ĳ�����Ч
	//���������ȡ������ע�ͼ��ɣ���ֱ�Ӹ���Ƶ�ʼ����ȣ�
//	AD9954_SETFRE(10000);	//дƵ��10kHz
//	Write_ASF(0X03FFF);//0X0000~0X3FFF��Ӧ���ֵ0mv~500mv(����)
//	while(1);
	
	
	//2��	
//	����ɨƵ��˵��
//	�ó����ɨƵ�������ö�ʱ���жϣ�����д���Լӵ�Ƶ��ʵ�֣�
//	��timer.C��TIM4_IRQHandler�н��ԼӺ��Ƶ��д��
	while(1)
	{
		KeyRead();
		Set_PointFre(Keycode, 0);
		if(_return){_return=0;LCD_Refresh_Gram();}
		KEY_EXIT();
	}
}

