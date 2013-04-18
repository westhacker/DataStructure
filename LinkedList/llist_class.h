#ifndef _LLIST_H_
#define _LLIST_H_

#include <stdio.h>
#include <stdlib.h>

class List;

class ListNode{
	friend class List;
private:
	ListNode *next;
	char info;
public:
	ListNode(const char &E,ListNode *N=NULL)
		:info(E),next(N){}
	ListNode():next(NULL){}
	~ListNode(){};
};

class List{
	class ListNode *head;
	class ListNode *curPtr;
	int length;
	int curIndex;
public:
	List();
	~List();
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;
	int List::Length()const;
	bool Get(int i,char& info) const;
	bool Goto(int i);
	int Find( char info);
	bool Set_Cur(int i);
	bool Get_Cur(char& info) const;
	int Cur_Index()const;
	int Prior();
	int Next();
	bool Insert (int i,const char& info);
	bool Append (char info);
	bool Insert_Cur (const char& info);
	bool Delete(int i);
	bool Delete_v(char info);
	bool Delete_cur();
	void Output() const;
	bool Exchange(char info1,char info2);
	void Reverse();
	void InsertSort();
	bool ExchangeIndex(int index1,int index2);
	char GetInfo(int index1);

};
#endif