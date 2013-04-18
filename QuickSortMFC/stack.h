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

	infoType pop(){
	ListNode *tmp=top;
	infoType temp=top->info;
	top=top->next;
	delete tmp;
	length--;
	return temp;
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