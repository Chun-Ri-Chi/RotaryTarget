#include "ti_msp_dl_config.h"
#include "delay.h"
#include "usart.h"
#include "usart.h"
#include "Motor.h"


int main(void)
{
    USART_Init();
    while (1)
	{
		Data_Analyse();//���������жϽ��յ�����	Parsing data received by serial port interrupt
		Car_Function(Car_state);//����С����ͬ״̬	Control the car in different states
    }
}
