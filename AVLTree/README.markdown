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

* AVL树是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个儿子子树的高度最大差别为一，所以它也被称为高度平衡树。查找、插入和删除在平均和最坏情况下都是O(log n)。增加和删除可能需要通过一次或多次树旋转来重新平衡这个树。
* In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.[1] In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

# Content

*	bool deleteavl(Type x,BNODE *t)//AVL结点删除
*	void insertavl(Type x,BNODE *t)//AVL插入结点
*	void rotateright(BNODE *t)//在结点t处树向右倾斜
*	void rotateleft(BNODE *t)//在结点t处树向左倾斜
*	bool sfind(Type x,BNODE *t)//二叉排序树搜索函数
*   void sinsert(Type x,BNODE *t)//二叉排序树插入函数
*	bool Ins_root(Type info)//插入root
*	bool Ins_leftChild(Type info)//插入左儿子
*	bool Ins_rightChild(Type info)//插入右儿子
*	void sdel(Type x,BNODE *t)//二叉排序树结点删除函数
*	int height(BNODE *ptr)const//获取节点高度
*	void clear(BNODE *ptr)//清空所有节点
*	int size(BNODE *ptr)const//获取节点下面所有节点的数目
*	int level(BNODE *ptr)const//获取节点层数
*	bool empty( ){ return root == NULL;}//判断树是否空	
*	int size( ){return size(root);}//返回树的节点总数
*	int level( ){return level(current);}//返回树的总层数	
*	int height( ){return height(root);}//返回树的总高度	
*	void tQueue(BNODE *ptr)//二叉排序树结点从小到大入队
*	void Levelprint(BNODE *ptr,int lev)//第lev层按中序打印info
*	void LevelprintBalance(BNODE *ptr,int lev)//第lev层按中序打印平衡因子
*	int getnum(BNODE *ptr)//获取二叉排序树结点的中序位置
*	int setblank(BNODE *ptr)//计算节点前TAB次数
*	AVL(){root=NULL;current=NULL;}//构造
*	~AVL(){clear();}//析构
*	void clear(){if(root!=NULL)clear(root);root=NULL;}//清空树
*	void parent( )//返回父节点
*	void leftChild( )//指向左儿子
*	void rightChild( )//指向右儿子
*	void view( )//打印树
*	void viewBalance( )//打印平衡因子
*	bool sfind(Type x)//查找
*   void sinsert(Type x)//二叉查找树插入
*	void sdel(const Type &x)//二叉查找树删除
*	Type sfindmax()//找最大
*	Type sfindmin()//找最小
*	void batchinsertavl(Type *Array,int l)//批量插入形成AVL树
*	void rotateright()//当前结点向右旋转
*	void rotateleft()//当前结点向左旋转
*	void insertavl(Type x)//插入AVL结点
*	void deleteavl(const Type &x)//删除AVL结点

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

	//AVL结点删除
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

	//AVL插入结点
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
	
	//在结点t处树向右倾斜
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

	//在结点t处树向左倾斜
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

	//二叉排序树搜索函数
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

	//二叉排序树插入函数
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

    //插入root
	bool Ins_root(Type info)
	{
		root=new BNODE(info,NULL,NULL,NULL);
		current=root;
		return 1;
	}

	//插入左儿子
	bool Ins_leftChild(Type info)
	{
		if(current!=NULL){
		current->llink=new BNODE(info,NULL,NULL,current);
		current=current->llink;
		return 1;
		}
		else return 0;
	}

	//插入右儿子
	bool Ins_rightChild(Type info)	
	{
		if(current!=NULL){
		current->rlink=new BNODE(info,NULL,NULL,current);
		current=current->rlink;
		return 1;
		}
		else return 0;
	}

	//二叉排序树结点删除函数
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

	//获取节点高度
	int height(BNODE *ptr)const{
		if(ptr==NULL) return 0;
		else{
			int lh=height(ptr->llink),rh=height(ptr->rlink);
			return (lh>rh?lh:rh)+1;
		}
	}

	//清空所有节点
	void clear(BNODE *ptr)
	{
		if(ptr->llink!=NULL)clear(ptr->llink);
		if(ptr->rlink!=NULL)clear(ptr->rlink);
		delete ptr;
	}

	//获取节点下面所有节点的数目
	int size(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return size(ptr->llink)+size(ptr->rlink)+1;
	}

	//获取节点层数
	int level(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return level(ptr->parent)+1;
	}

	//判断树是否空
	bool empty( ){ return root == NULL;}

	//返回树的节点总数
	int size( ){return size(root);}

	//返回树的总层数
	int level( ){return level(current);}

	//返回树的总高度
	int height( ){return height(root);}

	//二叉排序树结点从小到大入队
	void tQueue(BNODE *ptr)
	{
		if(ptr!=NULL){
		tQueue(ptr->llink);
		tqueue.EnQueue(ptr);
		tQueue(ptr->rlink);
		}
	}

	//第lev层按中序打印info
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

	//第lev层按中序打印平衡因子
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

	//获取二叉排序树结点的中序位置
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

	//计算节点前TAB次数
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
	//构造
	AVL(){root=NULL;current=NULL;}

	//析构
	~AVL(){clear();}

	//清空树
	void clear(){if(root!=NULL)clear(root);root=NULL;}

	//返回父节点
	void parent( ){if(current->parent!=NULL) current=current->parent;
	else printf("No parent!\n");
	}

	//指向左儿子
	void leftChild( ){if(current->llink!=NULL) current=current->llink;
	else printf("No leftChild!\n");
	}

	//指向右儿子
	void rightChild( ){if(current->rlink!=NULL) current=current->rlink;
	else printf("No rightChild!\n");
	}

	//打印树
	void view( )
	{
		if(empty()) printf("The tree is empty.\n");

		for(int i=1;i<=height();i++)
		{
			Levelprint(root,i);
			printf("\n");
		}
	}

	//打印平衡因子
	void viewBalance( )
	{
		for(int i=1;i<=height();i++)
		{
			LevelprintBalance(root,i);
			printf("\n");
		}
	}

	//查找
	bool sfind(Type x)
	{
		return sfind(x,root);
	}

	//二叉查找树插入
    void sinsert(Type x)
	{
		if(empty())Ins_root(x);
		else{
			flag=0;
		    sinsert(x,root);
		}
	}

	//二叉查找树删除
	void sdel(const Type &x)
	{
		sdel(x,root);
	}

	//找最大
	Type sfindmax()
	{
		BNODE *ptr=root;
		while(ptr->rlink!=NULL)
			ptr=ptr->rlink;
		current=ptr;
		return current->info;
	}

	//找最小
	Type sfindmin()
	{
		BNODE *ptr=root;
		while(ptr->llink!=NULL)
			ptr=ptr->llink;
		current=ptr;
		return current->info;
	}

	//批量插入形成AVL树
	void batchinsertavl(Type *Array,int l)
	{
		for(int i=0;i<l;i++)
			insertavl(Array[i]);
	    if(!empty())
			current=root;
	}

	//当前结点向右旋转
	void rotateright()
	{
		rotateright(current);
	}

	//当前结点向左旋转
	void rotateleft()
	{
		rotateleft(current);
	}

	//插入AVL结点
	void insertavl(Type x)
	{
		if(empty())Ins_root(x);
		else{
			flag=0;
		    insertavl(x,root);
		}
	}

	//删除AVL结点
	void deleteavl(const Type &x)
	{
		deleteavl(x,root);
	}
};
</code></pre>

# Thanks

Thanks for your reading and happy coding
