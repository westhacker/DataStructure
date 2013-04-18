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
	//»ÎÕ∞
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
	// ’ºØ
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
