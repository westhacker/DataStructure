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