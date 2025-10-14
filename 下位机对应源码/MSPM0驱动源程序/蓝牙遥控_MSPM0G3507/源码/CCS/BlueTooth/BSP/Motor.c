#include "Motor.h"

/**************************************************************************
�������ܣ����������ת	Function: forward and reverse rotation of the motor
��ڲ������ٶ�ֵ		Entry parameters: speed value
����  ֵ����			Return value: None
**************************************************************************/

void Forward(int Speed)
{
		PWMA_IN1(Speed);PWMA_IN2(0);  //��ǰ��	Left front wheel
		PWMB_IN1(0);PWMB_IN2(Speed);  //��ǰ��	Right front wheel
		PWMC_IN1(Speed);PWMC_IN2(0);  //�����	Left rear wheel
		PWMD_IN1(0);PWMD_IN2(Speed);  //�Һ���	Right rear wheel
}
void Backward(int Speed)
{
		PWMA_IN1(0);PWMA_IN2(Speed);
		PWMB_IN1(Speed);PWMB_IN2(0);
		PWMC_IN1(0);PWMC_IN2(Speed);
		PWMD_IN1(Speed);PWMD_IN2(0);
		
	}
void Turnleft(int Speed)
{
		PWMA_IN1(0);PWMA_IN2(0);
		PWMB_IN1(0);PWMB_IN2(Speed); 
		PWMC_IN1(0);PWMC_IN2(0);
		PWMD_IN1(0);PWMD_IN2(Speed);
}
void Turnright(int Speed)
{
		PWMA_IN1(Speed);PWMA_IN2(0);
		PWMB_IN1(0);PWMB_IN2(0);
		PWMC_IN1(Speed);PWMC_IN2(0);
		PWMD_IN1(0);PWMD_IN2(0);
}
void Stop(void)
{
		PWMA_IN1(0);PWMA_IN2(0);
		PWMB_IN1(0);PWMB_IN2(0);
		PWMC_IN1(0);PWMC_IN2(0);
		PWMD_IN1(0);PWMD_IN2(0);
}
void SpinLeft(int Speed)//���ֺ�������ǰ��	Left wheel moves backwards and right wheel moves forwards
{
		PWMA_IN1(0);PWMA_IN2(Speed);
		PWMB_IN1(0);PWMB_IN2(Speed);
		PWMC_IN1(0);PWMC_IN2(Speed);
		PWMD_IN1(0);PWMD_IN2(Speed);
}
void SpinRight(int Speed)//����ǰ�����ֺ���	Left wheel forward, right wheel backward
{
		PWMA_IN1(Speed);PWMA_IN2(0);
		PWMB_IN1(Speed);PWMB_IN2(0);
		PWMC_IN1(Speed);PWMC_IN2(0);
		PWMD_IN1(Speed);PWMD_IN2(0);
}

void Data_Analyse(void)//���������жϴ��ڽ��յ�����	Parse the data received by the serial port interrupt
{
		if(recv0_flag == 1)
		{
			switch(recv0_buff[0])
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
			switch(recv0_buff[2])
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
			recv0_flag = 0;
		}			
}

void Car_Function(unsigned int Car_state)//����С����ͬ״̬	Control the car in different states
{
    switch(Car_state)
    {
			case 0:
					printf("Stop\n");
					Stop();
					break;
			case 1:
					printf("Forward\n");
					Forward(2300);
					break;
			case 2:
					printf("Backward\n");
					Backward(2300);
					break;
			case 3:
					printf("Turnleft\n");
					Turnleft(2500);
					break;
			case 4:
					printf("Turnright\n");
					Turnright(2500);
					break;
			case 5:
					printf("SpinLeft\n");
					SpinLeft(2500);
					break;
			case 6:
					printf("SpinRight\n");
					SpinRight(2500);
					break;
    }
}
