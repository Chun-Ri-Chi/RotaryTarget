#include "Motor.h"

/**************************************************************************
�������ܣ����������ת
��ڲ�����
����  ֵ����
**************************************************************************/

void Forward(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;  //��ǰ��  Speed=6000
		PWMB_IN1=0;PWMB_IN2=Speed;  //��ǰ��
		PWMC_IN1=0;PWMC_IN2=Speed;  //�Һ���
		PWMD_IN1=Speed;PWMD_IN2=0;  //�����
}
void Backward(int Speed)
{

	  PWMA_IN1=0;PWMA_IN2=Speed;
	  PWMB_IN1=Speed;PWMB_IN2=0;
		PWMC_IN1=Speed;PWMC_IN2=0;
	  PWMD_IN1=0;PWMD_IN2=Speed;		
		
	}
void Turnleft(int Speed)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=Speed; //Speed=6500   
		PWMC_IN1=0;PWMC_IN2=Speed;
		PWMD_IN1=0;PWMD_IN2=0;
}
void Turnright(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=6500
		PWMB_IN1=0;PWMB_IN2=0;
		PWMC_IN1=0;PWMC_IN2=0;
		PWMD_IN1=Speed;PWMD_IN2=0;
}
void Stop(void)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=0;
		PWMC_IN1=0;PWMC_IN2=0;
		PWMD_IN1=0;PWMD_IN2=0;
}
void SpinLeft(int Speed)   //���ֺ�������ǰ��     ���7.9V��������90������   ������8.43V��//Speed=7000
{
		PWMA_IN1=0;PWMA_IN2=Speed;
		PWMB_IN1=0;PWMB_IN2=Speed;
		PWMC_IN1=0;PWMC_IN2=Speed;
		PWMD_IN1=0;PWMD_IN2=Speed;
}
void SpinRight(int Speed)   //����ǰ�����ֺ���      ���7.9V��������90������
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=7000
		PWMB_IN1=Speed;PWMB_IN2=0;
		PWMC_IN1=Speed;PWMC_IN2=0;
		PWMD_IN1=Speed;PWMD_IN2=0;
}

void Data_Analyse(void)//���������жϴ��ڽ��յ�����
{
		if(rxd_flag == 1)
		{
			switch(rxd_buf[0])
			{
				case '1':
					printf("Forward!\n");
					Car_state = 1;
					break;
				case '2':
					printf("Backward!\n");
					Car_state = 2;
					break;
				case '3':
					printf("Left!\n");
					Car_state = 3;
					break;
				case '4':
					printf("Right!\n");
					Car_state = 4;
					break;
				case '0':
					printf("Stop!\n");
					Car_state = 0;
					break;
			}
			switch(rxd_buf[2])
			{
				case '1':
					printf("SpinLeft!\n");
					Car_state = 5;
					break;
				case '2':
					printf("SpinRight!\n");
					Car_state = 6;
					break;
			}
			rxd_flag = 0;
		}			
}

void Car_Function(unsigned int Car_state)//����С����ͬ״̬
{
    switch(Car_state)
    {
			case 0:
					printf("Stop\n");
					Stop();
					break;
			case 1:
					printf("Forward\n");
					Forward(6000);
					break;
			case 2:
					printf("Backward\n");
					Backward(6000);
					break;
			case 3:
					printf("Turnleft\n");
					Turnleft(6500);
					break;
			case 4:
					printf("Turnright\n");
					Turnright(6500);
					break;
			case 5:
					printf("SpinLeft\n");
					SpinLeft(7000);
					break;
			case 6:
					printf("SpinRight\n");
					SpinRight(7000);
					break;
    }
}
