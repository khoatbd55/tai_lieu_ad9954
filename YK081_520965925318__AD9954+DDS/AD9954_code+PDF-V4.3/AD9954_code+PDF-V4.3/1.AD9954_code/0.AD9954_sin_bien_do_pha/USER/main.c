/**********************************************************
                       ��������
���ܣ�stm32f103rct6����AD9954ģ�������Ƶ���Ҳ���Ƶ�ʣ����ȣ���λ�ɵ�
�ӿڣ��������Žӿ������AD9954.h
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
#include "AD9954.h"

int main(void)
{
	MY_NVIC_PriorityGroup_Config(NVIC_PriorityGroup_2);	//�����жϷ���
	delay_init(72);	//��ʼ����ʱ����
	delay_ms(1000);//��ʱһ������ȴ��ϵ��ȶ�,ȷ��AD9954�ȿ��ư����ϵ硣
	
	//������ֲ����
	//1.�޸�ͷ�ļ�AD9954.h�У��Լ����ư�ʵ����Ҫʹ����Щ�������š���AD9954_CS�Ÿĳ�PA0���ƣ�����"#define AD9954_CS	PAout(0)" 
	//2.�޸�C�ļ�AD9954.c�У�AD9954_GPIO_Init�����������õ��ܽŵ�GPIO������ܳ�ʼ��
	//3.���
	
	AD9954_Init();				//��ʼ������AD9954��Ҫ�õ���IO��,���Ĵ���
	AD9954_Set_Fre(1000.0);//�������Ƶ��1000Hz
	AD9954_Set_Amp(16383);//���÷��ȣ���Χ0~16383 ����Ӧ����Լ��0~500mv)
	AD9954_Set_Phase(0);//������λ����Χ0~16383����Ӧ�Ƕȣ�0��~360��)
	
	while(1);

}

