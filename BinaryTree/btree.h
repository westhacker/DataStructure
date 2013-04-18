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

	int height(BNODE *ptr)const{
		if(ptr==NULL) return 0;
		else{
			int lh=height(ptr->llink),rh=height(ptr->rlink);
			return (lh>rh?lh:rh)+1;
		}
	}

	void clear(BNODE *ptr)
	{
		if(ptr->llink!=NULL)clear(ptr->llink);
		if(ptr->rlink!=NULL)clear(ptr->rlink);
		delete ptr;
	}

	int size(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return size(ptr->llink)+size(ptr->rlink)+1;
	}

	int level(BNODE *ptr)const
	{
		if(ptr==NULL)return 0;
		return level(ptr->parent)+1;
	}

	void tQueue(BNODE *ptr)
	{
		if(ptr!=NULL){
		tQueue(ptr->llink);
		tqueue.EnQueue(ptr);
		tQueue(ptr->rlink);
		}
	}

	void PreOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		printf("%c",ptr->info);
		PreOrder(ptr->llink);
		PreOrder(ptr->rlink);
		}
	}

	void InOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		InOrder(ptr->llink);
		printf("%c",ptr->info);
		InOrder(ptr->rlink);
		}
	}

	void PostOrder(BNODE *ptr)
	{
		if(ptr!=NULL){
		PostOrder(ptr->llink);
		PostOrder(ptr->rlink);
		printf("%c",ptr->info);
		}
	}

	void LevelOrder(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev)
			printf("%c",ptr->info);
		LevelOrder(ptr->llink,lev);
		LevelOrder(ptr->rlink,lev);
		}
	}

	void Levelprint(BNODE *ptr,int lev)
	{
		if(ptr!=NULL){
		if(level(ptr)==lev){
			for(int i=0;i<=setblank(ptr);i++)
				printf("\t");
			if(ptr==current)printf("==>");
			printf("%c",ptr->info);}
		Levelprint(ptr->llink,lev);
		Levelprint(ptr->rlink,lev);
		}
	}

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

	int setblank(BNODE *ptr)
	{
		tqueue.Clear();
		tQueue(root);
		/*if(ptr==tqueue.Gethead())return 0;
		else{
		for(int i=1;i<=size();i++){
			BNODE *temp=tqueue.Gethead();
			tqueue.DeQueue();
			if(ptr==tqueue.Gethead()){
				return getnum(ptr)-getnum(temp);
				break;
			}
		}
		}*/
		BNODE *temp=NULL;
		for(int i=1;i<=size();i++){
			if(level(ptr)==level(tqueue.Gethead())){
				if(tqueue.Gethead()==ptr){return getnum(ptr);}
				else{
					while(tqueue.Gethead()!=ptr){
					temp=tqueue.Gethead();
					tqueue.DeQueue();
					}
					return getnum(tqueue.Gethead())-getnum(temp);
				}
				break;
			}
			else tqueue.DeQueue();
		}
	}

	bool findinfo(BNODE *ptr,Type info)
	{
		if(ptr!=NULL){
		if(ptr->info==info){
				current=ptr;
				printf("SUCCESS.\n");
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
	BinaryTree(const Type *Array);
	BinaryTree(const Type *ArrayPre, const Type *ArrayIn);
	BinaryTree(const BinaryTree& t);

	~BinaryTree(){clear();}

	BinaryTree& operator=(const BinaryTree& t);

	void clear(){if(root!=NULL)clear(root);root=NULL;}

	bool empty( ){ return root == NULL;}
	int size( ){return size(root);}
	int level( ){return level(current);}
	int height( ){return height(root);}
	char get( ){return current->info;}
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

	void gotoRoot( ){current = root;}
	void parent( ){if(current->parent!=NULL) current=current->parent;
	else printf("No father!\n");
	}
	void leftChild( ){if(current->llink!=NULL) current=current->llink;
	else printf("No leftChild!\n");
	}
	void rightChild( ){if(current->rlink!=NULL) current=current->rlink;
	else printf("No rightChild!\n");
	}

	void view( )
	{
		if(empty()) printf("The tree is empty.\n");

		for(int i=1;i<=height();i++)
		{
			Levelprint(root,i);
			printf("\n");
		}
	}

	void printPreOrder( ){
		if(!empty()){
			printf("The PreOrder: ");
			PreOrder(root);
		}
	}

	void printInOrder( ){
		if(!empty()){
			printf("The InOrder: ");
			InOrder(root);
		}
	}

	void printPostOrder( ){
		if(!empty()){
			printf("The PostOrder: ");
		PostOrder(root);
		}
	}

	void printLevelOrder( ){
		if(!empty()){
			printf("The LevelOrder: ");
			for(int i=1;i<=height();i++)
		       LevelOrder(root,i);
		}
	}

	bool Ins_root(Type info)
	{
		root=new BNODE(info,NULL,NULL,NULL);
		current=root;
		return 1;
	}

	bool Ins_leftChild(Type info)
	{
		if(current!=NULL){
		current->llink=new BNODE(info,NULL,NULL,current);
		current=current->llink;
		return 1;
		}
		else return 0;
	}

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