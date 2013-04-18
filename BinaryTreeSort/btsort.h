#include "Queue.h"


template<class Type>
class BTSORT{
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
	BTSORT(){root=NULL;current=NULL;}

	//����
	~BTSORT(){clear();}

	//�����
	void clear(){if(root!=NULL)clear(root);root=NULL;}

	//���ظ��ڵ�
	void parent( ){if(current->parent!=NULL) current=current->parent;
	else printf("No father!\n");
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

	bool sfind(Type x)
	{
		return sfind(x,root);
	}
    void sinsert(Type x)
	{
		if(empty())Ins_root(x);
		else{
			flag=0;
		    sinsert(x,root);
		}
	}
	void sdel(const Type &x)
	{
		sdel(x,root);
	}

	Type sfindmax()
	{
		BNODE *ptr=root;
		while(ptr->rlink!=NULL)
			ptr=ptr->rlink;
		current=ptr;
		return current->info;
	}

	Type sfindmin()
	{
		BNODE *ptr=root;
		while(ptr->llink!=NULL)
			ptr=ptr->llink;
		current=ptr;
		return current->info;
	}

	void batchinsert(Type *Array,int l)
	{
		for(int i=0;i<l;i++)
			sinsert(Array[i]);
	    if(!empty())
			current=root;
	}
};