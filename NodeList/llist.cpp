#include "llist_class.h"

List::List()
{
	ListNode *ptr;
	ptr=new ListNode;
	if(ptr==NULL)
		exit(1);
	ptr->info='\0';
	ptr->next=NULL;

	head=ptr;
	length=0;
	curPtr=ptr;
	curIndex=0;
}

List::~List()
{
	Clear();
	delete head;
}

void List::Clear()
{
	ListNode *ptr=head;
	ListNode *ptr1;

	while(ptr->next!=NULL){
		ptr1=ptr->next;
		ptr->next=ptr1->next;
		length--;
		delete ptr1;
	}
	length=0;
	curPtr=head;
	curIndex=0;
}

bool List::IsEmpty()const
{
	return (length==0);
}

bool List::IsFull()const
{
	return 0;
}

//返回长度
int List::Length()const
{
	return length;
}

//向后移动
int List::Next()
{
	if(curIndex==0||curIndex==length)
		return 0;

	curIndex++;
	curPtr=curPtr->next;

	return curIndex;
}

//向前移动
int List::Prior()
{
	if(curIndex==0||curIndex==1)
		return 0;
	ListNode *ptr=head;
	while(ptr->next!=curPtr){
		ptr=ptr->next;}
	curIndex--;
	curPtr=ptr;

	return curIndex;
}

//设置当前位置
bool List::Set_Cur(int i)
{
	ListNode *ptr=head->next;
	int index=1;

	if((i<1)||(i>length))
		return false;
	while(ptr!=NULL&&index<i){
		ptr=ptr->next;
		index++;
	}
	if(index=i){
		curIndex=i;
		curPtr=ptr;
		return true;
	}else
		return false;
}

//返回当前位置
int List::Cur_Index()const
{return curIndex;}

//判断指点位置处内容
bool List::Get(int i,char& info)const
{
	ListNode *ptr=head->next;
	int index=1;
	if((i<1)||(i>length))
		return false;
	while(ptr!=NULL&&index<i){
		ptr=ptr->next;
		index++;
	}
	if(index=i&&info==ptr->info){
		return true;
	}else
		return 0;
}

//通过info查询index
int List::Find(char info)
{
	ListNode *ptr=head->next;
	int index=1;
	while(ptr!=NULL){
		if(ptr->info==info){
			curPtr=ptr;
			curIndex=index;
			return index;}
		ptr=ptr->next;
		index++;
	}
	printf("There is no such elem.\n");
	return false;
}

//插入
bool List::Insert(int i,const char&info)
{
	ListNode *ptr=head;
	ListNode *ptr_new;
	int index=1;

	if((i<1)||(i>length+1))
		return false;

	while(ptr->next!=NULL&&index<i){
		ptr=ptr->next;
		index++;
	}

	ptr_new=new ListNode;
	if(ptr_new==NULL)
		return false;

	ptr_new->info=info;
	ptr_new->next=ptr->next;

	ptr->next=ptr_new;

	length++;

	if(curIndex==0){
		curIndex=0;
		curPtr=head;
	}else
		Set_Cur(curIndex);

	return true;
}

//当前位置处添加
bool List::Insert_Cur (const char& info)
{
	Insert(curIndex,info);
	return true;
}

//尾部添加
bool List::Append(char info)
{
	Insert(length+1,info);
	return true;
}

//已知位置删除节点
bool List::Delete(int i)
{
	ListNode *ptr=head;
	ListNode *ptr1;
	int index=1;

	if((i<1)||(i>length))
		return false;
	/*
	while(ptr->next!=NULL&&index<=i){
		if(index=i){
			ptr1=ptr->next;
			ptr->next=ptr1->next;
			length--;
			delete(ptr1);
			break;
		}
		
		ptr=ptr->next;
		index++;
	}
	*/
	while(ptr->next!=NULL&&index<i){
		ptr=ptr->next;
		index++;
	}

	        ptr1=ptr->next;
			ptr->next=ptr1->next;
			length--;
			delete(ptr1);

	if(curIndex==0||curIndex>length){
		curIndex=0;
		curPtr=head;
	}else
		Set_Cur(curIndex);
	return true;
}

//通过info删除节点
bool List::Delete_v(char info)
{
	int index=Find(info);
	Delete(index);
	return true;
}

//删除当前节点
bool List::Delete_cur()
{
	Delete(curIndex);
	return true;
}

//输出
void List::Output()const
{
	bool ret=IsEmpty();
	ListNode *ptr=head->next;
	char info;
	int index=1;
	if(ret==true){
		printf("List is empty.\n");
		return;
	}

	while(ptr!=NULL){
		if(curIndex==index)
			printf("    ==>");

		printf("\t elem[%d]=%c \n",index,ptr->info);
		ptr=ptr->next;
		index++;
	}
}

//已知节点内容交换两个节点位置
bool List::Exchange(char info1,char info2)
{
	int index1=Find(info1);
	int index2=Find(info2);
	/*Delete(index1);
	Insert(index1,info2);
	Delete(index2);
	Insert(index2,info1);*/
	ExchangePtr(index1,index2);
	return true;	
}

//已知节点位置获取节点内容
char List::GetInfo(int index1)
{
	ListNode *ptr=head;
	int index=0;
	while(ptr->next!=NULL&&index<index1){
		ptr=ptr->next;
		index++;
	}
	return ptr->info;

}

//已知节点位置获取节点
ListNode* List::GetPtr(int index1)
{
	ListNode *ptr=head;
	int index=0;
	while(ptr->next!=NULL&&index<index1){
		ptr=ptr->next;
		index++;
	}
	return ptr;
}

//交换两节点位置
//bool List::ExchangeIndex(int index1,int index2)
//{
//	char info1=GetInfo(index1);
//	char info2=GetInfo(index2);
//	Exchange(info1,info2);
//	return true;
//}


//通过修改ListNode实现交换两节点位置
bool List::ExchangePtr(int index1,int index2)
{
	ListNode *temp1=GetPtr(index1)->next;
	ListNode *temp2=GetPtr(index2)->next;
	ListNode *tmp1=GetPtr(index1-1);
	ListNode *tmp2=GetPtr(index2-1);
	ListNode *p1=GetPtr(index1);
	ListNode *p2=GetPtr(index2);

	if(index2-index1==1){
		p1->next=temp2;
		tmp1->next=p2;
		p2->next=p1;
	}
	else if(index1-index2==1)
	{
		p2->next=temp1;
		tmp2->next=p1;
		p1->next=p2;
	}
	else{
	p1->next=temp2;
	p2->next=temp1;

	tmp1->next=p2;
	tmp2->next=p1;
	}

	return true;
}

//使链表反向排列
void List::Reverse()
{
	for(int i=1;i<=length/2;++i){
		ExchangePtr(i,length-i+1);}
	
}

//直接插入排序
void List::InsertSort()
{
	int i,j;
	for(i=2;i<=length;++i)
		for(j=i;j>0&&GetInfo(j-1)>GetInfo(j);j--){
			ExchangePtr(j-1,j);}
}