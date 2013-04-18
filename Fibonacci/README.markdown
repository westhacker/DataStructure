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

# Fibonacci

* 쳲������ڡ������顷�������һ����Ȥ���������⣺
һ����ԣ������ڳ��������º󣬾��з�ֳ������һ������ÿ����������һ��С����������������ö���������ôһ���Ժ���Է�ֳ���ٶ����ӣ�
���ǲ������³�����һ��С���ӷ���һ�£�
��һ����С����û�з�ֳ���������Ի���һ�ԣ�
�����º�����һ��С�������������ԣ�
�������Ժ�������������һ�ԣ���ΪС���ӻ�û�з�ֳ����������һ�������ԣ�
������
* In mathematics, the Fibonacci numbers or Fibonacci series or Fibonacci sequence are the numbers in the following integer sequence:
0,1,1,2,3,5,8,13,21,34,55,89,144...

# Content

<pre><code>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	Stack<int> stack;
	
	int f1,f2;
	bool end_mark=false;
	int N;
	printf("Fibonacci(0)=0\n");
		printf("Fibonacci(1)=1\n");
		printf("..............\n");
		printf("Fibonacci(N)=?\n");

	while(end_mark==false){
		stack.clear();
		stack.push(0);
	    stack.push(1);
		printf("\nPlease input N:(0 means quit)");
		scanf("%d",&N);
		getchar();
		if(N==0){
			end_mark=true;}
		else if(N==1){
			printf("Fibonacci(1)=1\n");
		}
		else{
			for(int i=1;i<N;++i){
				f1=stack.getTop();
				stack.pop();
				f2=stack.getTop();
				stack.push(f1);
				stack.push(f1+f2);
			}
			printf("Fibonacci(%d)=%d\n",N,stack.getTop());
		}
		
	}
}
</code></pre>

# Thanks

Thanks for your reading and happy coding