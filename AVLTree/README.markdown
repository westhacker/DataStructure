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

# AVLTree

* AVL�������ȷ�������ƽ��������������AVL�����κνڵ���������������ĸ߶������Ϊһ��������Ҳ����Ϊ�߶�ƽ���������ҡ������ɾ����ƽ���������¶���O(log n)�����Ӻ�ɾ��������Ҫͨ��һ�λ�������ת������ƽ���������
* In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.[1] In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

# Content

*	bool deleteavl(Type x,BNODE *t)//AVL���ɾ��
*	void insertavl(Type x,BNODE *t)//AVL������
*	void rotateright(BNODE *t)//�ڽ��t����������б
*	void rotateleft(BNODE *t)//�ڽ��t����������б
*	bool sfind(Type x,BNODE *t)//������������������
*   void sinsert(Type x,BNODE *t)//�������������뺯��
*	bool Ins_root(Type info)//����root
*	bool Ins_leftChild(Type info)//���������
*	bool Ins_rightChild(Type info)//�����Ҷ���
*	void sdel(Type x,BNODE *t)//�������������ɾ������
*	int height(BNODE *ptr)const//��ȡ�ڵ�߶�
*	void clear(BNODE *ptr)//������нڵ�
*	int size(BNODE *ptr)const//��ȡ�ڵ��������нڵ����Ŀ
*	int level(BNODE *ptr)const//��ȡ�ڵ����
*	bool empty( ){ return root == NULL;}//�ж����Ƿ��	
*	int size( ){return size(root);}//�������Ľڵ�����
*	int level( ){return level(current);}//���������ܲ���	
*	int height( ){return height(root);}//���������ܸ߶�	
*	void tQueue(BNODE *ptr)//��������������С�������
*	void Levelprint(BNODE *ptr,int lev)//��lev�㰴�����ӡinfo
*	void LevelprintBalance(BNODE *ptr,int lev)//��lev�㰴�����ӡƽ������
*	int getnum(BNODE *ptr)//��ȡ������������������λ��
*	int setblank(BNODE *ptr)//����ڵ�ǰTAB����
*	AVL(){root=NULL;current=NULL;}//����
*	~AVL(){clear();}//����
*	void clear(){if(root!=NULL)clear(root);root=NULL;}//�����
*	void parent( )//���ظ��ڵ�
*	void leftChild( )//ָ�������
*	void rightChild( )//ָ���Ҷ���
*	void view( )//��ӡ��
*	void viewBalance( )//��ӡƽ������
*	bool sfind(Type x)//����
*   void sinsert(Type x)//�������������
*	void sdel(const Type &x)//���������ɾ��
*	Type sfindmax()//�����
*	Type sfindmin()//����С
*	void batchinsertavl(Type *Array,int l)//���������γ�AVL��
*	void rotateright()//��ǰ���������ת
*	void rotateleft()//��ǰ���������ת
*	void insertavl(Type x)//����AVL���
*	void deleteavl(const Type &x)//ɾ��AVL���

# Class AVL

<pre><code>
#include "Queue.h"

template<class Type>
class AVL{
    struct BNODE{
		BNODE *llink,*rlink,*parent;
		Type info;
		BNODE():llink(NULL),rlink(NULL),parent(NULL){}
		BNODE(Type item,BNODE *L=NULL,BNODE *R=NULL,BNODE *P=NULL):
		info(item),llink(L),rlink(R),parent(P){}
		~BNODE(){}
	};

	BNODE *root;
	BNODE *current;
	bool flag;
	Queue<BNODE*> tqueue;

	//AVL���ɾ��
	bool deleteavl(Type x,BNODE *t)
	{
		bool stop=0;

		if(t==NULL)return 1;

		if(x<t->info)
		{
			flag=1;
			stop=deleteavl(x,t->llink);
		}
		else if(x>t->info)
		{
			flag=0;
			stop=deleteavl(x,t->rlink);
		}
		else if(t->llink!=NULL&&t->rlink!=NULL)
		{
			BNODE *temp=t->rlink;
			while(temp->llink!=NULL)
				temp=temp->llink;
			t->info=temp->info;
		    stop=deleteavl(t->info,t->rlink);
			flag=0;
		}
		else if(t->llink==NULL&&t->rlink==NULL)
		{
			if(t->parent==NULL)
			{
			clear();
			return 1;
			}
			else
			{
			if(flag)t->parent->llink=NULL;
			else t->parent->rlink=NULL;
			delete t;
			return 0;
			}
		}
		else
		{
			if(t->parent==NULL)
			{
			root=(t->llink!=NULL)?t->llink:t->rlink;
			root->parent=NULL;
			delete t;
			}
			else{
			if(flag)t->parent->llink=(t->llink!=NULL)?t->llink:t->rlink;
			else t->parent->rlink=(t->llink!=NULL)?t->llink:t->rlink;
			((t->llink!=NULL)?t->llink:t->rlink)->parent=t->parent;
			delete t;
			}
			return 0;
		}
		
		if(stop)
			return 1;

		int balance;

		switch(flag)
		{
		case 1:
			balance=height(t->llink)-height(t->rlink)+1;
			if(balance==0)
				return 1;
			if(balance==1)
				return 0;
			if(balance==-1)
			{
				int rbalance=height(t->rlink->llink)-height(t->rlink->rlink);
				switch(rbalance)
				{
				case 0:
					rotateleft(t);
					return 1;
				case -1:
					rotateleft(t);
					return 0;
				default:
					rotateright(t->rlink);
					rotateleft(t);
					return 0;
				}
			}
			break;
		case 0:
			balance=height(t->llink)-height(t->rlink)-1;
			if(balance==0)
				return 1;
			if(balance==-1)
				return 0;
			if(balance==1)
			{
				int lbalance=height(t->llink->llink)-height(t->llink->rlink);
				switch(lbalance)
				{
				case 0:
					rotateright(t);
					return 1;
				case -1:
					rotateright(t);
					return 0;
				default:
					rotateleft(t->llink);
					rotateright(t);
					return 0;
				}
			}
		}
	}

	//AVL������
	void insertavl(Type x,BNODE *t)
	{
		if(t==NULL)
		{
			if(flag)Ins_leftChild(x);
			else Ins_rightChild(x);
		}
		else if(x<t->info){
			current=t;
			flag=1;
			insertavl(x,t->llink);
			if(height(t->llink)-height(t->rlink)==2)
			{
				if(x<t->llink->info)
					rotateright(t);
				else{
					rotateleft(t->llink);
					rotateright(t);
				}
			}
		}
		else if(x>t->info){
			current=t;
			flag=0;
			insertavl(x,t->rlink);
			if(height(t->llink)-height(t->rlink)==-2)
			{
				if(x>t->rlink->info)
					rotateleft(t);
				else{
					rotateright(t->rlink);
					rotateleft(t);
				}
			}
		}
		else
		{
			current=t;
		}
	}
	
	//�ڽ��t����������б
	void rotateright(BNODE *t)
	{
		if(t->llink==NULL)
			return;

			
		BNODE* tmp=t->parent;

		BNODE* tmp1=t;
		BNODE* tmp2=t->llink;

		if(tmp2->rlink!=NULL)
		{
			tmp1->llink=tmp2->rlink;
			tmp1->llink->parent=tmp1;
		}
		else tmp1->llink=NULL;
		tmp1->parent=tmp2;

		tmp2->rlink=tmp1;
		if(t==root)
		{
		tmp2->parent=NULL;
		root=tmp2;
		}
		else
		{
			tmp2->parent=tmp;
			//t=tmp2;
			if(tmp->llink==t)
			tmp->llink=tmp2;
			else tmp->rlink=tmp2;
		}
	}

	//�ڽ��t����������б
	void rotateleft(BNODE *t)
	{
		if(t->rlink==NULL)
			return;

			
		BNODE* tmp=t->parent;
		BNODE* tmp1=t;
		BNODE* tmp2=t->rlink;

		if(tmp2->llink!=NULL)
		{
			tmp1->rlink=tmp2->llink;
			tmp1->rlink->parent=tmp1;
		}
		else tmp1->rlink=NULL;
		tmp1->parent=tmp2;

		tmp2->llink=tmp1;
		if(t==root)
		{
		tmp2->parent=NULL;
		root=tmp2;
		}
		else
		{
			tmp2->parent=tmp;
			//t=tmp2;
			if(tmp->llink==t)
			tmp->llink=tmp2;
			else tmp->rlink=tmp2;
		}
	}

	//������������������
	bool sfind(Type x,BNODE *t)
	{
		if(t==NULL)return false;
		else if(x<t->info)return sfind(x,t->llink);
		else if(x>t->info)return sfind(x,t->rlink);
		else
		{
			current=t;
			return true;
		}
	}

	//�������������뺯��
	void sinsert(Type x,BNODE *t)
	{
		if(t==NULL)
		{
			if(flag)Ins_leftChild(x);
			else Ins_rightChild(x);
		}
		else if(x<t->info){
			current=t;
			flag=1;
			sinsert(x,t->llink);
		}
		else if(x>t->info){
			current=t;
			flag=0;
			sinsert(x,t->rlink);
		}
		else
		{
			current=t;
		}
	}

    //����root
	bool Ins_root(Type info)
	{
		root=new BNODE(info,NULL,NULL,NULL);
		current=root;
		return 1;
	}

	//���������
	bool Ins_leftChild(Type info)
	{
		if(current!=NULL){
		current->llink=new BNODE(info,NULL,NULL,current);
		current=current->llink;
		return 1;
		}
		else return 0;
	}

	//�����Ҷ���
	bool Ins_rightChild(Type info)	
	{
		if(current!=NULL){
		current->rlink=new BNODE(info,NULL,NULL,current);
		current=current->rlink;
		return 1;
		}
		else return 0;
	}

	//�������������ɾ������
	void sdel(Type x,BNODE *t)
	{
		if(t==NULL)return;

		if(x<t->info)
		{
			flag=1;
			sdel(x,t->llink);
		}
		else if(x>t->info)
		{
			flag=0;
			sdel(x,t->rlink);
		}
		else if(t->llink!=NULL&&t->rlink!=NULL)
		{
			BNODE *temp=t->rlink;
			while(temp->llink!=NULL)
				temp=temp->llink;
			t->info=temp->info;
		    sdel(t->info,t->rlink);
		}
		else if(t->llink==NULL&&t->rlink==NULL)
		{
			if(t->parent==NULL)
			{
			clear();
			}
			else
			{
			if(flag)t->parent->llink=NULL;
			else t->parent->rlink=NULL;
			delete t;
			}
		}
		else
		{
			if(t->parent==NULL)
			{
			root=(t->llink!=NULL)?t->llink:t->rlink;
			root->parent=NULL;
			delete t;
			}
			else{
			if(flag)t->parent->llink=(t->llink!=NULL)?t->llink:t->rlink;
			else t->parent->rlink=(t->llink!=NULL)?t->llink:t->rlink;
			((t->llink!=NULL)?t->llink:t->rlink)->parent=t->parent;
			delete t;
			}
		}
	}

	//��ȡ�ڵ�߶�
	int height(BNODE *ptr)const{
		if(ptr==NULL) return 0;
		else{
			int lh=height(ptr->llink),rh=height(ptr->rlink);
			return (lh>rh?lh:rh)+1;
		}
	}

	//������нڵ�
	void clear(BNODE *ptr)
	{
		if(ptr->llink!=NULL)clear(ptr->llink);
		if(ptr->rlink!=NULL)clear(ptr->rlink);
		delete ptr;
	}

	//��ȡ�ڵ��������нڵ����Ŀ
	int size(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return size(ptr->llink)+size(ptr->rlink)+1;
	}

	//��ȡ�ڵ����
	int level(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return level(ptr->parent)+1;
	}

	//�ж����Ƿ��
	bool empty( ){ return root == NULL;}

	//�������Ľڵ�����
	int size( ){return size(root);}

	//���������ܲ���
	int level( ){return level(current);}

	//���������ܸ߶�
	int height( ){return height(root);}

	//��������������С�������
	void tQueue(BNODE *ptr)
	{
		if(ptr!=NULL){
		tQueue(ptr->llink);
		tqueue.EnQueue(ptr);
		tQueue(ptr->rlink);
		}
	}

	//��lev�㰴�����ӡinfo
	void Levelprint(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev){
			for(int i=0;i<setblank(ptr);i++)
				printf("\t");
			if(ptr==current)printf("==>%c",ptr->info);
			else printf("   %c",ptr->info);}
		Levelprint(ptr->llink,lev);
		Levelprint(ptr->rlink,lev);
		}
	}

	//��lev�㰴�����ӡƽ������
	void LevelprintBalance(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev){
			for(int i=0;i<setblank(ptr);i++)
				printf("\t");
			if(ptr==current)printf("==>%d",height(ptr->llink)-height(ptr->rlink));
			else printf("   %d",height(ptr->llink)-height(ptr->rlink));}
		LevelprintBalance(ptr->llink,lev);
		LevelprintBalance(ptr->rlink,lev);
		}
	}

	//��ȡ������������������λ��
	int getnum(BNODE *ptr)
	{
		if(ptr==NULL) return 0;

		tqueue.Clear();
		tQueue(root);

		int num=0;
		
		for(int i=1;i<=size();i++)
		{
			if(tqueue.Gethead()==ptr)
			{ 
			num=i;
			break;
			}
			else tqueue.DeQueue();
		}

		return num;
	}

	//����ڵ�ǰTAB����
	int setblank(BNODE *ptr)
	{
		tqueue.Clear();
		tQueue(root);

		BNODE *temp=NULL;
		for(int i=1;i<=size();i++){
			if(level(ptr)==level(tqueue.Gethead())){
				if(tqueue.Gethead()==ptr){return getnum(ptr);}
				else{
					while(tqueue.Gethead()!=ptr){
						if(level(ptr)==level(tqueue.Gethead()))
						{temp=tqueue.Gethead();}
					tqueue.DeQueue();
					}
					return getnum(tqueue.Gethead())-getnum(temp);
				}
				break;
			}
			else tqueue.DeQueue();
		}
	}

public:
	//����
	AVL(){root=NULL;current=NULL;}

	//����
	~AVL(){clear();}

	//�����
	void clear(){if(root!=NULL)clear(root);root=NULL;}

	//���ظ��ڵ�
	void parent( ){if(current->parent!=NULL) current=current->parent;
	else printf("No parent!\n");
	}

	//ָ�������
	void leftChild( ){if(current->llink!=NULL) current=current->llink;
	else printf("No leftChild!\n");
	}

	//ָ���Ҷ���
	void rightChild( ){if(current->rlink!=NULL) current=current->rlink;
	else printf("No rightChild!\n");
	}

	//��ӡ��
	void view( )
	{
		if(empty()) printf("The tree is empty.\n");

		for(int i=1;i<=height();i++)
		{
			Levelprint(root,i);
			printf("\n");
		}
	}

	//��ӡƽ������
	void viewBalance( )
	{
		for(int i=1;i<=height();i++)
		{
			LevelprintBalance(root,i);
			printf("\n");
		}
	}

	//����
	bool sfind(Type x)
	{
		return sfind(x,root);
	}

	//�������������
    void sinsert(Type x)
	{
		if(empty())Ins_root(x);
		else{
			flag=0;
		    sinsert(x,root);
		}
	}

	//���������ɾ��
	void sdel(const Type &x)
	{
		sdel(x,root);
	}

	//�����
	Type sfindmax()
	{
		BNODE *ptr=root;
		while(ptr->rlink!=NULL)
			ptr=ptr->rlink;
		current=ptr;
		return current->info;
	}

	//����С
	Type sfindmin()
	{
		BNODE *ptr=root;
		while(ptr->llink!=NULL)
			ptr=ptr->llink;
		current=ptr;
		return current->info;
	}

	//���������γ�AVL��
	void batchinsertavl(Type *Array,int l)
	{
		for(int i=0;i<l;i++)
			insertavl(Array[i]);
	    if(!empty())
			current=root;
	}

	//��ǰ���������ת
	void rotateright()
	{
		rotateright(current);
	}

	//��ǰ���������ת
	void rotateleft()
	{
		rotateleft(current);
	}

	//����AVL���
	void insertavl(Type x)
	{
		if(empty())Ins_root(x);
		else{
			flag=0;
		    insertavl(x,root);
		}
	}

	//ɾ��AVL���
	void deleteavl(const Type &x)
	{
		deleteavl(x,root);
	}
};
</code></pre>

# Thanks

Thanks for your reading and happy coding
