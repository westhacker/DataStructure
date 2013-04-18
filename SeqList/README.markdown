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

# SeqList

* ���Ա������������򵥡�Ҳ����õ�һ�����ݽṹ�����Ա�������Ԫ��֮��Ĺ�ϵ��һ��һ�Ĺ�ϵ�������˵�һ�������һ������Ԫ��֮�⣬��������Ԫ�ض�����β��ӵġ����Ա���߼��ṹ�򵥣�����ʵ�ֺͲ�������ˣ����Ա��������ݽṹ��ʵ��Ӧ�����ǹ㷺���õ�һ�����ݽṹ��
* In computer science, sequential access means that a group of elements (e.g. data in a memory array or a disk file or on magnetic tape data storage) is accessed in a predetermined, ordered sequence. Sequential access is sometimes the only way of accessing the data, for example if it is on a tape. It may also be the access method of choice, for example if we simply want to process a sequence of data elements in order.

# Content

<pre><code>
#include "Abslist.h"
#define ARRAY_SIZE 10

class SeqList:public AbsList{
	char* elem;
	int length;
	int MaxSize;
	int curIndex;
public:
	SeqList(int InitSize);
	~SeqList();
	void Clear(){length=0; curIndex=0;};
	int Length() const {return length;};
	bool IsEmpty() const {return (length==0);};
	bool IsFull() const {return (length==MaxSize);};
	int Find( const char& info);
	bool Get( int i,char& info) const;
	bool Set_Cur(int i);
	bool Get_Cur(char& info) const;
	int Cur_Index() const;
	int Prior();
	int Next();
	bool Insert (int i,const char& info);
	bool Append (const char& info);
	bool Insert_Cur (const char& info);
	bool Delete(int i);
	bool Delete_v(char& info);
	bool Delete_cur();
	void Output() const;
private:
	void DoubleSpace();
};
</code></pre>

# Thanks

Thanks for your reading and happy coding