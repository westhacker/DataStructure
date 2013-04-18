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

* 斐波那契在《算盘书》中提出了一个有趣的兔子问题：
一般而言，兔子在出生两个月后，就有繁殖能力，一对兔子每个月能生出一对小兔子来。如果所有兔都不死，那么一年以后可以繁殖多少对兔子？
我们不妨拿新出生的一对小兔子分析一下：
第一个月小兔子没有繁殖能力，所以还是一对；
两个月后，生下一对小兔总数共有两对；
三个月以后，老兔子又生下一对，因为小兔子还没有繁殖能力，所以一共是三对；
……　
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