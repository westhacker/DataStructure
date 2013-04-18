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

# NodeList

* 链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。 相比于线性表顺序结构，链表比较方便插入和删除操作。
* In computer science, a linked list is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of a datum and a reference (in other words, a link) to the next node in the sequence; more complex variants add additional links. This structure allows for efficient insertion or removal of elements from any position in the sequence.

# Content

<pre><code>
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
	bool ExchangePtr(int index1,int index2);
	ListNode* List::GetPtr(int index1);

};
#endif
</code></pre>

# Thanks

Thanks for your reading and happy coding