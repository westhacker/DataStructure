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

# HeapSortSample

* 堆积排序(Heapsort)是指利用堆积树（堆）这种资料结构所设计的一种排序算法，可以利用数组的特点快速定位指定索引的元素。
* Heapsort is a comparison-based sorting algorithm to create a sorted array (or list), and is part of the selection sort family. Although somewhat slower in practice on most machines than a well-implemented quicksort, it has the advantage of a more favorable worst-case O(n log n) runtime. Heapsort is an in-place algorithm, but it is not a stable sort.

# Content

<pre><code>
#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;


void menu(){
	printf("\t ====================== Menu ================================\n");
	printf("\t d -- delete             a -- append                           \n");
	printf("\t q -- quit               c -- clear                            \n");
	printf("\t s -- heapsort           v -- view_heap                        \n");
	printf("\t 1 -- find_k_O(n+klogn)  2 -- find_k_O(nlogk)                  \n");
	printf("\t 3 -- create_data.txt    4 -- read_data.txt                    \n");
	printf("\t 5 -- output_output.txt                                        \n");
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

int cfile()
{
	ofstream out("data.txt");
	if(out)printf("Succeed creating data.txt.");
	else printf("Fail creating data.txt .");
	srand(time(NULL));
	int n=rand()*100/(RAND_MAX+1);
	for(int i=0;i<n;i++)
		out<<rand()*10000/(RAND_MAX+1)<<' ';
	out.close();
	return n;
}

int rfile(int a[])
{
	ifstream fin;
	fin.open("data.txt");
	if(fin)
	{
		int i=0;
		for(i=0;fin!=NULL;i++)
		{
		fin>>a[i];
		}
		return i+1;
		printf("Succeed reading data.txt.");
		fin.close();
	}
	else printf("Fail reading data.txt.");
}

void ofile(int a[],int n)
{
	ofstream out("output.txt");
	if(!out)printf("Fail creating output.txt .");
	for(int i=0;i<n;i++)
		out<<a[i]<<' ';
	out.close();
	printf("Succeed creating output.txt.");
}

//对原数组建最大堆，然后pop出k次,时间复杂度为O(n + k*logn)
int findk1(int a[],int n,int k)
{
	int temp[100];
	for(int i=0;i<n;i++)
		temp[i]=a[i];

	initheap(temp,n);

	for(int i=n-1;i>n-k-1;i--)
	{
		int tmp=temp[0];
		temp[0]=temp[i];
		temp[i]=tmp;
		pushdown(temp,0,i);
	}
	return temp[n-k];
}

//维护一个k大小的最小堆，对于数组中的每一个元素判断与堆顶的大小，若堆顶较大，则不管，否则，弹出堆顶，将当前值插入到堆中,时间复杂度O(n * logk)
int findk2(int a[],int n,int k)
{
	int tmp[100];
	for(int i=0;i<n;i++)
		tmp[i]=a[i];
	for(int i=k/2-1;i>=0;i--)
		initpushdown(tmp,i,k);

	for(int j=k;j<n;j++)
	{
	if(tmp[0]<tmp[j])
	{
		tmp[0]=tmp[j];
		initpushdown(tmp,0,k);
	}
	}
	return tmp[0];
}


void main()
{
	char choice;
	int info;
	bool end_mark=false;
	int a[100]={97,77,58,26,44,39,31,14,23,36};
	int n=10;
	int k;
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
	case 'v':
		init(a,n);
		menu();
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
	case '1':
		printf("Enter k:");
		scanf("%d",&k);
		getchar();
		printf("第%d个大的元素是%d",k,findk1(a,n,k));
		printf("\n");
		menu();
		break;
	case '2':
		printf("Enter k:");
		scanf("%d",&k);
		getchar();
		printf("第%d个大的元素是%d",k,findk2(a,n,k));
		printf("\n");
		menu();
		break;
	case '3':
		cfile();
		printf("\n");
		menu();
		break;
	case '4':
		n=rfile(a);
		printf("\n");
		printf("Total number:%d\n",n);
		menu();
		break;
	case '5':
		ofile(a,n);
		printf("\n");
		menu();
		break;
	default:break;
}
	
	}
}
</code></pre>

# Thanks

Thanks for your reading and happy coding