#include "AbsQueue.h"
#include <stdlib.h>
#include <stdio.h>

#define InitSize 10

template<class infoType>
class Queue:public AbsQueue<infoType>{
	infoType* Array;
	int front,rear;
	int MaxSize;
	void doubleArray(int Max)	{
		infoType* temp;
		temp = new infoType[MaxSize];
		

		for(int i=front;i!=rear;)
		{
			temp[i-front]=Array[i];
			if(i<MaxSize-1)
			i++;
		    else
			i=0;
		}

		delete [] Array;
		
		Array = new infoType[Max];
		for(int i=0;i<MaxSize-1;i++)
		{
			Array[i]=temp[i];
		}

		delete [] temp;
		front=0;
		rear=MaxSize-1;
		MaxSize=Max;
	}

public:
	Queue(){
	Array = new infoType[InitSize];
	MaxSize = InitSize;
	front = rear = 0;
}

	~Queue(){
	delete [] Array;
}

	void Clear(){
	front = rear = 0;
}

	void EnQueue(const infoType &info){
	if(Full())
		doubleArray(MaxSize*2);
	Array[rear]=info;

	if(rear+1==MaxSize)
		rear=0;
	else
		rear++;
}

	void DeQueue(){
	if(Empty())
		printf("Queue is empty.\n");

	if(front == MaxSize-1)
		front=NULL;
	else
		front++;
}

	bool Empty() const{
	if(front == rear)
		return 1;
	else return 0;
}

	bool Full() const{
	if((rear+1)%MaxSize==front)
		return 1;
	else return 0;
}

	infoType Gethead() const{
	if(Empty())
	{
		printf("Queue is empty.\n");
	    return 0;
	}
	return Array[front];
}

	void Output() const{
	infoType info;

		if(Empty())
	{
		printf("Queue is empty.\n");
	    return;
	}

    for(int i=front;i!=rear;){
		info=Array[i];
		printf("Queue[%d]=%c \n",i,info);
		if(i<MaxSize-1)
			i++;
		else if(i==MaxSize-1)
			i=0;
	}
}


};