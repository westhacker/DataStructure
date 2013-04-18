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

* 线性表是最基本、最简单、也是最常用的一种数据结构。线性表中数据元素之间的关系是一对一的关系，即除了第一个和最后一个数据元素之外，其它数据元素都是首尾相接的。线性表的逻辑结构简单，便于实现和操作。因此，线性表这种数据结构在实际应用中是广泛采用的一种数据结构。
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