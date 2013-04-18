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