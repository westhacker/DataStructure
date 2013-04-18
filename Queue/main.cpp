#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


void menu(){
	printf("\t ========= ====== Menu ========= ========   \n");
	printf("\t 1 -- Clear                                 \n");
	printf("\t 2 -- IsEmpty                               \n");
	printf("\t 3 -- IsFull                                \n");
	printf("\t g -- Gethead                               \n");
	printf("\t i -- EnQueue                               \n");
	printf("\t d -- DeQueue                               \n");
	printf("\t o -- Output                                \n");
	printf("\t q -- quit                                  \n");
	printf("\t ========= ====== End ========== ========   \n");
	printf("Please enter your choice:");
}

void main()
{
	Queue<char> queue;
	char choice,info;
	bool end_mark=false;
	int index=0;
	bool ret;

	while(end_mark==false){
		queue.Output();
	    menu();
		choice=getchar();
		getchar();
		
	switch(choice)
	{
	case 'q':
		end_mark=true;
		break;
	case '1':
		queue.Clear();
		break;
	case '2':
		ret=queue.Empty();
		printf("The answer is %d \n",ret);
		break;
	case '3':
		ret=queue.Full();
		printf("The answer is %d \n",ret);
		break;
	case 'g':
		info=queue.Gethead();
		printf("Head is %c \n",info);
		break;
	case 'i':
		printf("Enter the info to enqueue:");
		scanf("%c",&info);
		getchar();
		queue.EnQueue(info);
		break;
	case 'd':
		queue.DeQueue();
		break;
	case 'o':
		queue.Output();
		break;
	default:break;
	}
	}
}