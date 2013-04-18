#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

SeqList::SeqList(int InitSize)
{
	if(InitSize<=0)
		InitSize=ARRAY_SIZE;

	elem=new char[InitSize];
	if(elem == NULL )
		exit(1);

	length=0;
	MaxSize=InitSize-1;
	curIndex=0;
}

SeqList::~SeqList()
{
	delete [] elem;
}

bool SeqList::Append(const char& info)
{
	if(length==MaxSize)
		DoubleSpace();

	elem[length+1]=info;
	length++;
	return true;
}



int SeqList::Find( const char& info)
{
	int num;
	for(num=1;num<length;++num)
		if(elem[num]==info) break;
	    if(num>length) num=0;
	curIndex=num;
	return num;
}

bool SeqList::Get( int i,char& info) const
{
	if(i<length&&i>0){
		info=elem[i];
		return true;
	}else
		return false;
}

bool SeqList::Set_Cur(int i)
{
	if((i<1)||(i>length))
		return false;
	curIndex=i;
	return true;
}

bool SeqList::Get_Cur(char& info) const
{   
	info=elem[curIndex];
	return true;
}

int SeqList::Cur_Index() const
{
	return curIndex;
}

int SeqList::Prior()
{
	int i=curIndex;
	if(curIndex==0) return 0;
	if((i-1)>0){
		curIndex--;
		return curIndex;
	}else
		return 0;
}

int SeqList::Next()
{
	int i=curIndex;
	if(curIndex<length){
		curIndex++;
		return curIndex;
	}else
		return length;
}

bool SeqList::Insert (int i,const char& info)
{
	int j;
	if((i<1)||(i>length+1))
		return false;
	if(MaxSize==length)
		DoubleSpace();
	for(j=length;j>=i;j--)
		elem[j+1]=elem[j];
	elem[i]=info;
	length++;
	return true;
}

bool SeqList::Insert_Cur (const char& info)
{
	Insert(curIndex,info);
	return true;
}

bool SeqList::Delete(int i)
{
	if((i<1)||(i>length))
		return false;
	for(int j=i;j<length;j++)
		elem[j]=elem[j+1];
	length--;
	if(curIndex>length)
		curIndex=0;
	return true;
}

bool SeqList::Delete_v(char& info)
{
	int index=Find(info);
	Delete(index);
	return true;
}

bool SeqList::Delete_cur()
{
	Delete(curIndex);
	return true;
}

void SeqList::DoubleSpace()
{
	char* temp;
	int newlength;
	newlength=length+10;
	temp=new char[length+1];
	if(temp == NULL )
		exit(1);
	for(int i=1;i<=length;++i)
		temp[i]=elem[i];
	delete []elem;
	elem=new char[newlength+1];
	if(elem == NULL )
		exit(1);
	for(int i=1;i<=newlength-10;++i)
		elem[i]=temp[i];
	delete []temp;
}

void SeqList::Output()const
{
	bool ret=IsEmpty();

	if(ret==true){
		printf("List is empty.\n");
		return;
	}

	for(int i=1;i<=length;i++){
		if(curIndex==i)
			printf("    ==>");
		printf("\t elem[%d]=%c \n",i,elem[i]);
	}
}