#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void menu(){
	printf("\t ========= ====== Menu ========= ========   \n");
	printf("\t 1 -- Clear                                 \n");
	printf("\t 2 -- IsEmpty                               \n");
	printf("\t 3 -- IsFull                                \n");
	printf("\t g -- GetTop                                \n");
	printf("\t i -- Push                                  \n");
	printf("\t d -- Pop                                   \n");
	printf("\t o -- Output                                \n");
	printf("\t q -- quit                                  \n");
	printf("\t ========= ====== End ========== ========   \n");
	printf("Please enter your choice:");
}

void main()
{
	Stack<char> stack;
	char choice,info;
	bool end_mark=false;
	int index=0;
	bool ret;

	while(end_mark==false){
		stack.output();
	    menu();
		choice=getchar();
		getchar();
		
	switch(choice)
	{
	case 'q':
		end_mark=true;
		break;
	case '1':
		stack.clear();
		break;
	case '2':
		ret=stack.empty();
		printf("The answer is %d \n",ret);
		break;
	case '3':
		ret=stack.full();
		printf("The answer is %d \n",ret);
		break;
	case 'g':
		info=stack.getTop();
		printf("Top is %c \n",info);
		break;
	case 'i':
		printf("Enter the info to push:");
		scanf("%c",&info);
		getchar();
		stack.push(info);
		break;
	case 'd':
		stack.pop();
		break;
	case 'o':
		stack.output();
		break;
	default:break;
	}
	}
}