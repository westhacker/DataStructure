#define NULL 0
#include "Queue.h"


template<class Type>
class BinaryTree{
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

	//�������
	void tQueue(BNODE *ptr)
	{
		if(ptr!=NULL){
		tQueue(ptr->llink);
		tqueue.EnQueue(ptr);
		tQueue(ptr->rlink);
		}
	}

	//ǰ�����
	void PreOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		printf("%d",ptr->info);
		PreOrder(ptr->llink);
		PreOrder(ptr->rlink);
		}
	}

	//�������
	void InOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		InOrder(ptr->llink);
		printf("%d",ptr->info);
		InOrder(ptr->rlink);
		}
	}

	//�������
	void PostOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		PostOrder(ptr->llink);
		PostOrder(ptr->rlink);
		printf("%d",ptr->info);
		}
	}

	//��lev�㣬��α���
	void LevelOrder(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev)
			printf("%d",ptr->info);
		LevelOrder(ptr->llink,lev);
		LevelOrder(ptr->rlink,lev);
		}
	}

	//��lev�㰴�����ӡ
	void Levelprint(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev){
			for(int i=0;i<setblank(ptr);i++)
				printf("\t");
			if(ptr==current)printf("==>%d",ptr->info);
			else printf("   %d",ptr->info);}
		Levelprint(ptr->llink,lev);
		Levelprint(ptr->rlink,lev);
		}
	}

	//��lev���Ƿ���
	int a;
	bool b;

	void Levelcount(BNODE *ptr,int lev)
	{
		
		if(ptr!=NULL){
		Levelcount(ptr->llink,lev);
		if(level(ptr)==lev)
			a++;
		Levelcount(ptr->rlink,lev);
	}
	}
    //���һ���Ƿ���ȫ
	void Levellast(BNODE *ptr)
	{
		if(ptr!=NULL){
		Levellast(ptr->llink);
		if(level(ptr)==height()){
				if(setblank(ptr)>2)b=0;
		}
		Levellast(ptr->rlink);
	}
	}



	//��lev��ڵ�����
	int levnum(int lev)
	{
		int lnum=1;
		for(int i=0;i<lev-1;i++)
		{
			lnum=lnum*2;
		}
		return lnum;
	}

	//��ȡ�ڵ������λ��
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

	//�ڽڵ����²���info
	bool findinfo(BNODE *ptr,Type info)
	{
		if(ptr!=NULL){
		if(ptr->info==info){
				current=ptr;
				//printf("SUCCESS.\n");
				flag=1;
				return 1;
			}
		
		findinfo(ptr->llink,info);
		findinfo(ptr->rlink,info);
		
		}
		return flag;
	}

public:
	BinaryTree(){root=NULL;current=NULL;}

	//αǰ���캯��
	BinaryTree(const Type *Array)
	{
		/*    BNODE *ptr;
			Stack<Type> tstack;
			Type temp='^';
			tstack.clear();
			
			else{
				Ins_root(Array[0]);
			tstack.push(Array[len-1]);
			tstack.push(Array[len-2]);

			for(int i=len-3;i>=0;i++)
			{
				if(Array[i]=='^')
				{temp=tstack.getTop();
					tstack.push(Array[i]);continue;}

				if(tstack.length<2)
				{temp=tstack.getTop();
					tstack.push(Array[i]);continue;}

				if(temp=='^'||tstack.getTop()=='^'){
					ptr->info=Array[i];
					if(tstack.getTop()=='^')ptr->rlink=NULL
					else ptr->rlink->info=getTop();
				tstack.pop();
				if(tstack.getTop()=='^')ptr->llink=NULL
					else ptr->llink->info=getTop();
				tstack.pop();

				temp=tstack.getTop();
				tstack.push(Array[i]);}
			}
			}*/
			root=NULL;current=NULL;
			Ins_root(Array[0]);

			for(int i=1;Array[i]!='\0';i=i+2)
			{
				if(current==NULL||Array[i+1]=='\0'){
					current=current->parent;
					break;
				}
				else{
				if(Array[i]=='^'&&Array[i+1]=='^')
					current=current->parent;
				if(Array[i]=='^'&&Array[i+1]!='^')
				{
					if(current->llink==NULL&&current->rlink==NULL)
						Ins_rightChild(Array[i+1]);
					else if(current->rlink==NULL)
					{
						current=current->parent;
						i=i-1;
					}
					else
					{
						current=current->parent;
						i=i-2;
					}
				}
				if(Array[i]!='^')
				{
					if(current->llink==NULL&&current->rlink==NULL)
					{
						Ins_leftChild(Array[i]);
						i--;
					}
					if(current->llink!=NULL&&current->rlink==NULL)
					{
						Ins_rightChild(Array[i]);
						i--;
					}
					if(current->rlink!=NULL)
					{
						current=current->parent;
						i=i-2;
					}
				}
				}
			}
			current=root;
	}

	//���������ݻ�ȡ����
	int getindex(Type info,const Type *Array)
	{
		int i=0;
		while(Array[i]!=info){
		i++;
		}
		return i;
	}

	//ǰ�����������
	BinaryTree(const Type *ArrayPre, const Type *ArrayIn)
	{
		Ins_root(ArrayPre[0]);
		for(int i=1;ArrayPre[i]!='\0';i++)
		{
			if(getindex(ArrayPre[i],ArrayIn)<getindex(ArrayPre[i-1],ArrayIn))
			{
				Ins_leftChild(ArrayPre[i]);
			}
			else
			{
				int j=i-1;
				while(getindex(ArrayPre[j],ArrayIn)<getindex(ArrayPre[i],ArrayIn))
				{
					j--;
					if(j==-1)break;
				}
				find(ArrayPre[j+1]);

				while(current->rlink!=NULL){current=current->rlink;}

				Ins_rightChild(ArrayPre[i]);
			}
		}
		current=root;
	}

	//����֪��������
	BinaryTree(const BinaryTree& t);

	//����
	~BinaryTree(){clear();}

	//����=
	BinaryTree& operator=(const BinaryTree& t)
	{
		BinaryTree<Type> temp;

		temp.root=t.root;
		temp.current=t.current;
		temp.flag=t.flag;
		temp.tqueue=t.tqueue;

		return temp;
	}

	//αǰ������
	void arraytree(const Type *Array)
	{
		root=NULL;current=NULL;
			Ins_root(Array[0]);

			for(int i=1;Array[i]!='\0';i=i+2)
			{
				if(current==NULL||Array[i+1]=='\0'){
					current=current->parent;
					break;
				}
				else{
				if(Array[i]=='^'&&Array[i+1]=='^')
					current=current->parent;
				if(Array[i]=='^'&&Array[i+1]!='^')
				{
					if(current->llink==NULL&&current->rlink==NULL)
						Ins_rightChild(Array[i+1]);
					else if(current->rlink==NULL)
					{
						current=current->parent;
						i=i-1;
					}
					else
					{
						current=current->parent;
						i=i-2;
					}
				}
				if(Array[i]!='^')
				{
					if(current->llink==NULL&&current->rlink==NULL)
					{
						Ins_leftChild(Array[i]);
						i--;
					}
					if(current->llink!=NULL&&current->rlink==NULL)
					{
						Ins_rightChild(Array[i]);
						i--;
					}
					if(current->rlink!=NULL)
					{
						current=current->parent;
						i=i-2;
					}
				}
				}
			}
			current=root;
	}

	//ǰ�����������
	void preandin(const Type *ArrayPre, const Type *ArrayIn,int n)
	{
		Ins_root(ArrayPre[0]);
		for(int i=1;i<=n;i++)
		{
			if(getindex(ArrayPre[i],ArrayIn)<getindex(ArrayPre[i-1],ArrayIn))
			{
				Ins_leftChild(ArrayPre[i]);
			}
			else
			{
				int j=i-1;
				while(getindex(ArrayPre[j],ArrayIn)<getindex(ArrayPre[i],ArrayIn))
				{
					j--;
					if(j==-1)break;
				}
				find(ArrayPre[j+1]);

				while(current->rlink!=NULL){current=current->rlink;}

				Ins_rightChild(ArrayPre[i]);
			}
		}
		current=root;
	}

	//�Ƿ�Ϊ��ȫ��
	bool iscomplete()
	{
		bool com=1;
		for(int i=1;i<=height()-1;i++){
			a=0;
			Levelcount(root,i);
			if(a!=levnum(i))
				com=0;
		}
		BNODE *ptr;
		ptr=root;
		while(ptr->llink!=NULL)
		{
			ptr=ptr->llink;
		}
		if(level(ptr)==height()&&getnum(ptr)==1)
		{
		b=com;
		Levellast(root);
		if(b==0)com=0;
		return com;
		}
		else return 0;
	}
	//�����
	void clear(){if(root!=NULL)clear(root);root=NULL;}

	//�ж����Ƿ��
	bool empty( ){ return root == NULL;}

	//�������Ľڵ�����
	int size( ){return size(root);}

	//���������ܲ���
	int level( ){return level(current);}

	//���������ܸ߶�
	int height( ){return height(root);}

	//���ص�ǰ�ڵ������
	char get( ){return current->info;}

	//�������ݽڵ�
	bool find(Type info)
	{
		flag=0;
		if(!empty()){
			flag=findinfo(root,info);
		}
		if(!flag)
			printf("FAIL.\n");
		return flag;
	}

	//����root
	void gotoRoot( ){current = root;}

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

	//��ӡǰ�����
	void printPreOrder( ){
		if(!empty()){
			printf("The PreOrder: ");
			PreOrder(root);
		}
	}

	//��ӡ�������
	void printInOrder( ){
		if(!empty()){
			printf("The InOrder: ");
			InOrder(root);
		}
	}

	//��ӡ�������
	void printPostOrder( ){
		if(!empty()){
			printf("The PostOrder: ");
		PostOrder(root);
		}
	}

	//��ӡ��α���
	void printLevelOrder( ){
		if(!empty()){
			printf("The LevelOrder: ");
			for(int i=1;i<=height();i++)
		       LevelOrder(root,i);
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


};