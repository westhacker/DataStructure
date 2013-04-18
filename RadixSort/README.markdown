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

# RadixSort

* 基数排序法又称“桶子法”（bucket sort）或bin sort，顾名思义，它是透过键值的部份资讯，将要排序的元素分配至某些“桶”中，藉以达到排序的作用，基数排序法是属于稳定性的排序，其时间复杂度为O (nlog(r)m)，其中r为所采取的基数，而m为堆数，在某些时候，基数排序法的效率高于其它的比较性排序法。
* In computer science, radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. A positional notation is required, but because integers can represent strings of characters (e.g., names or dates) and specially formatted floating point numbers, radix sort is not limited to integers. Radix sort dates back as far as 1887 to the work of Herman Hollerith on tabulating machines.

# Content

<pre><code>
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void radixsort(string a[],int n)
{
	Queue<string> word[27];	
	char base[]="abcdefghijklmnopqrstuvwxyz";
	for(int k=20;k>=0;k--)
	{
	//入桶
	for(int i=0;i<n;i++)
	{
		if(a[i].length()<=k)
			word[26].EnQueue(a[i]);
		else{
		for(int j=0;j<26;j++)
			if(a[i][k]==base[j])
			word[j].EnQueue(a[i]);
		}
	}
	//收集
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(!word[26].Empty())
		{
			a[i]=word[26].Gethead();
			word[26].DeQueue();
		}
		else{
		while(word[j].Empty())
			j++;
		if(j==27)break;
		if(!word[j].Empty())
		{
		a[i]=word[j].Gethead();
		word[j].DeQueue();
		}
		}
	}

	}
	printf("Succeed sorting the data.\n");
}



void cfile()
{
	ofstream out("data.txt");
	if(out)printf("Succeed creating data.txt.\n");
	else printf("Fail creating data.txt .\n");
	string initdic[10]={"apple","and","an","significant","us","significance","value","change","hacker","west"};
	for(int i=0;i<10;i++)
	out<<initdic[i]<<"\n";
	out.close();
}

int rfile(string a[])
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
		printf("Succeed reading data.txt.\n");
		fin.close();
		return i-1;
	}
	else printf("Fail reading data.txt.\n");
}

void ofile(string a[],int n)
{
	ofstream out("output.txt");
	if(!out)printf("Fail creating output.txt.\n");
	for(int i=0;i<n;i++)
		out<<a[i]<<"\n";
	out.close();
	printf("Succeed creating output.txt.\n");
}



int main()
{
	string a[1000];
	int n;
	cout<<"RadixSort Your Data Version 1.0"<<endl;
	cfile();
	cout<<"Now please input the original data in data.txt."<<endl;
	char choice;
	while(1){
	cout<<"Are you ready? (Y or N)";
	cin>>choice;
	if(choice=='Y'||choice=='y')
	{
		cout<<endl;
		n=rfile(a);
		cout<<"The original data:\n";
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<endl;
		radixsort(a,n);
		cout<<"The sorted data:\n";
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<endl;
		char choice2;
		cout<<"Do you want to output the sorted data?(Y or N)";
		cin>>choice2;
		if(choice2=='Y'||choice2=='y')
			ofile(a,n);
		break;
	}
	}
	cout<<"Input somethinf to Quit...";
	cin>>choice;
	return 0;
}
</code></pre>

# Thanks

Thanks for your reading and happy coding