#include "stm32f10x.h" 
#include "SysTick.h"
#include "Uart.h"
#include "Pwm.h"
#include "Motor.h"

int main(void)
{    
    SysTick_Configuration();		//���ö�ʱ��
    Uart1_Configuration();			//����UART1����
    Uart1_NVIC_Configuration();	//����UART1�����ж�
		PWM_Int(7199,0, 7199,0);		//PWM��ʼ��
	
    while(1)
    { 
			Data_Analyse();//���������жϽ��յ�����
			Car_Function(Car_state);//����С����ͬ״̬
    }  
}
