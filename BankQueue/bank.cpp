#include "bank.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

bank::bank()
{
	printf("�����뵽��ʱ�����Сֵ��");
	scanf("%d",&latime);
    
	printf("�����뵽��ʱ������ֵ��");
	scanf("%d",&hatime);
    
	printf("���������ʱ�����Сֵ��");
	scanf("%d",&lwtime);
    
	printf("���������ʱ������ֵ��");
	scanf("%d",&hwtime);
    
	printf("������ģ��Ŀͻ�����");
	scanf("%d",&num);
    
	srand(time(NULL));
}

int bank::averagetime()const
{
	int totaltime = 0;
	int ctime = 0;
	int etime = 0;
	Queue<int> bankqueue;
	int i;
	for(i=0;i<num;++i)
	{
		ctime+=latime+(hatime-latime+1)*rand()/(RAND_MAX+1);
		bankqueue.EnQueue(ctime);
	}

	ctime=0;
	while(!bankqueue.Empty())
	{
		etime=bankqueue.Gethead();
		bankqueue.DeQueue();
		if(etime<ctime)
			totaltime+=ctime-etime;
		else
			ctime=etime;
		ctime+=lwtime+(hwtime-lwtime+1)*rand()/(RAND_MAX+1);
	}
	return totaltime/num;

}