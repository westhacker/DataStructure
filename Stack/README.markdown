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

* 栈（stack）在计算机科学中是限定仅在表尾进行插入或删除操作的线性表。栈是一种数据结构，它按照后进先出的原则存储数据，先进入的数据被压入栈底，最后的数据在栈顶，需要读数据的时候从栈顶开始弹出数据。栈是只能在某一端插入和删除的特殊线性表。用桶堆积物品，先堆进来的压在底下，随后一件一件往堆。取走时，只能从上面一件一件取。堆和取都在顶部进行，底部一般是不动的。栈就是一种类似桶堆积物品的数据结构，进行删除和插入的一端称栈顶，另一堆称栈底。插入一般称为进栈，删除则称为退栈。 栈也称为后进先出表。
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