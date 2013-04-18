# DataStructure Demos and Examples

A collection of DataStructure experiments I've created, now open source and on GitHub, so please go ahead and help me hack this resource in to a wealth of demos that other authors can learn from.

# Aim

* If a user can hit view source on the demo, then we've done our job
* All content is open source and just enjoy it
* Individual demos, if authored by someone other than [@westhacker](http://twitter.com) can be credited as appropriate

# Language

* C
* C++

# Develop Tool

* Visual Studio 2010

# Queue

* 队列是一种特殊的线性表，它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作。进行插入操作的端称为队尾，进行删除操作的端称为队头。队列中没有元素时，称为空队列。
* In computer science, a queue is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed. Often a peek or front operation is also implemented, returning the value of the front element without dequeuing it. A queue is an example of a linear data structure, or more abstractly a sequential collection.

#Content

<pre><code>
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
</code></pre>

# Thanks

Thanks for your reading and happy coding