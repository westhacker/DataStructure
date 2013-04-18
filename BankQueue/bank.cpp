#include "bank.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

bank::bank()
{
	printf("请输入到达时间的最小值：");
	scanf("%d",&latime);
    
	printf("请输入到达时间的最大值：");
	scanf("%d",&hatime);
    
	printf("请输入服务时间的最小值：");
	scanf("%d",&lwtime);
    
	printf("请输入服务时间的最大值：");
	scanf("%d",&hwtime);
    
	printf("请输入模拟的客户数：");
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