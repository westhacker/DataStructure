#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;


void menu(){
	printf("\t ====================== Menu ================================\n");
	printf("\t d -- delete           a -- append                           \n");
	printf("\t q -- quit             c -- clear                            \n");
	printf("\t s -- heapsort         v -- view_array                       \n");
	printf("\t ======================= End ================================\n");
	printf("Please enter your choice:");
}

void pushdown(int a[],int first,int last)
{
	int child;
	int tmp=a[first];
	while(first*2+1<last)
	{
		child=first*2+1;
		if(child!=last-1&&a[child+1]>a[child])
			child++;
		if(a[child]>tmp)a[first]=a[child];
		else break;
		first=child;
	}
	a[first]=tmp;
}

void initpushdown(int a[],int first,int last)
{
	int child;
	int tmp=a[first];
	while(first*2+1<last)
	{
		child=first*2+1;
		if(child!=last-1&&a[child+1]<a[child])
			child++;
		if(a[child]<tmp)a[first]=a[child];
		else break;
		first=child;
	}
	a[first]=tmp;
}

void pre_order(int a[],int b[],int n,int k)
{
	if(a[k]==NULL||k>=n)return;

	static int i=0;
	b[i++]=a[k];
	if(i==n)i=0;
	//printf("%d\t",a[k]);

	if(a[2*k+1]!=NULL&&2*k+1<n)
		pre_order(a,b,n,2*k+1);
	
	if(a[2*k+2]!=NULL&&2*k+2<n)
		pre_order(a,b,n,2*k+2);
}


void in_order(int a[],int b[],int n,int k)
{
	if(a[k]==NULL)return;
	if(a[2*k+1]!=NULL&&2*k+1<n)
		in_order(a,b,n,2*k+1);
	static int i=0;
	b[i++]=a[k];
	if(i==n)i=0;
	//printf("%d\t",a[k]);
	if(a[2*k+2]!=NULL&&2*k+2<n)
		in_order(a,b,n,2*k+2);
}

void preorder(int a[],int b[],int n)
{
	pre_order(a,b,n,0);
}

void inorder(int a[],int b[],int n)
{
	in_order(a,b,n,0);
}


void init(int a[],int n)
{
	if(n==0)
	{
		printf("Empty.\n");
		return;
	}
	BinaryTree<int> bt;

	for(int i=n/2-1;i>=0;i--)
		initpushdown(a,i,n);

	int c[100];
	preorder(a,c,n);
	int pre[100];
	for(int i=0;i<n;i++)
		pre[i]=c[i];

	int b[100];
	inorder(a,b,n);
	int in[100];
	for(int i=0;i<n;i++)
		in[i]=b[i];

	bt.preandin(pre,in,n-1);

	printf("\n");
	bt.view();
}

void initheap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		pushdown(a,i,n);
}


void heapsort(int a[],int n)
{
	initheap(a,n);

	for(int i=n-1;i>0;i--)
	{
		int tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;
		pushdown(a,0,i);
	}

	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void del(int a[],int n,int info)
{
	int i=0;
	while(a[i]!=info&&i<n)i++;
	if(i==n)
	{
		printf("Fail.");
	}
	else
	{
		for(int j=i;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		a[n-1]='\0';
		printf("Success.");
	}
}

void append(int a[],int n,int info)
{
	a[n]=info;
}

void clear(int a[],int n)
{
	for(int i=0;i<n;i++)
		a[i]='\0';
}


void main()
{
	char choice;
	int info;
	bool end_mark=false;
	int a[100]={97,77,58,26,44,39,31,14,23,36};
	int n=10;
	init(a,n);
	menu();

	while(end_mark==false){
		choice=getchar();
		//getchar();
		
	switch(choice)
	{
	case 'q':
		end_mark=true;
		break;
	case 'd':
		printf("Enter the info:");
		scanf("%d",&info);
		del(a,n,info);
		n--;
		init(a,n);
		menu();
		break;
	case 'a':
		printf("Enter the info:");
		scanf("%d",&info);
		getchar();
		append(a,n,info);
		n++;
		init(a,n);
		menu();
		break;
	case 'c':
		clear(a,n);
		n=0;
		init(a,n);
		menu();
		break;
	case 's':
		heapsort(a,n);
		printf("\n");
		menu();
		break;
	default:break;
}
	
	}
}