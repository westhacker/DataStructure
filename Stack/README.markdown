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

# Stack

* ջ��stack���ڼ������ѧ�����޶����ڱ�β���в����ɾ�����������Ա�ջ��һ�����ݽṹ�������պ���ȳ���ԭ��洢���ݣ��Ƚ�������ݱ�ѹ��ջ�ף�����������ջ������Ҫ�����ݵ�ʱ���ջ����ʼ�������ݡ�ջ��ֻ����ĳһ�˲����ɾ�����������Ա���Ͱ�ѻ���Ʒ���ȶѽ�����ѹ�ڵ��£����һ��һ�����ѡ�ȡ��ʱ��ֻ�ܴ�����һ��һ��ȡ���Ѻ�ȡ���ڶ������У��ײ�һ���ǲ����ġ�ջ����һ������Ͱ�ѻ���Ʒ�����ݽṹ������ɾ���Ͳ����һ�˳�ջ������һ�ѳ�ջ�ס�����һ���Ϊ��ջ��ɾ�����Ϊ��ջ�� ջҲ��Ϊ����ȳ���
* In computer science, a stack is a particular kind of abstract data type or collection in which the principal (or only) operations on the collection are the addition of an entity to the collection, known as push and removal of an entity, known as pop.[1] The relation between the push and pop operations is such that the stack is a Last-In-First-Out (LIFO) data structure. In a LIFO data structure, the last element added to the structure must be the first one to be removed. This is equivalent to the requirement that, considered as a linear data structure, or more abstractly a sequential collection, the push and pop operations occur only at one end of the structure, referred to as the top of the stack. Often a peek or top operation is also implemented, returning the value of the top element without removing it.

# Content

<pre><code>
#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "absstack.h"


template <class infoType>
/*class List;

class ListNode{
	friend class List;
public:
	ListNode *next;
	char info;

	ListNode(const char &E,ListNode *N=NULL)
		:info(E),next(N){}
	ListNode():next(NULL){}
	~ListNode(){};
};
*/
class Stack:public AbsStack<infoType>
{private:
	struct ListNode{
		infoType info;
		ListNode *next;
		ListNode(const infoType &x,ListNode *N=NULL)
			{info=x;next=N;}
	ListNode():next(NULL){}
	~ListNode(){};
	};
	ListNode *top;
	int length;
public:
	Stack(){
	top=NULL;
	length=0;
    }

	~Stack(){clear();}

	void push(const infoType& info){
	ListNode *tmp=new ListNode(info,top);
	top=tmp;
	length++;
    }

	void pop(){
	ListNode *tmp=top;
	top=top->next;
	delete tmp;
	length--;
    }

	void clear(){
	ListNode *tmp;
	while(top!=NULL){
		tmp=top;
		top=top->next;
		delete tmp;
	}
	length=0;
    }

	bool empty()const{return top==NULL;}
	bool full()const {return false;}
	
	infoType getTop()const{
	return top->info;
    }

	void output()const{
	bool ret=empty();
	ListNode *ptr=top;
	infoType info;
	int index=1;
	if(ret==true){
		printf("List is empty.\n");
		return;
	}

	while(ptr!=NULL){
		if(ptr==top)
			printf("    ==>");

		printf("\t Stack[%d]=%c \n",length-index,ptr->info);
		ptr=ptr->next;
		index++;
	}
}

};


#endif
</code></pre>

# Thanks

Thanks for your reading and happy coding