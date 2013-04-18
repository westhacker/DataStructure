#include "btree.h"
#include <stdio.h>
#include <stdlib.h>


void menu(){
	printf("\t ====================== Menu ================================\n");
	printf("\t 0 -- clone            2 -- empty                            \n");
	printf("\t 1 -- clear            3 -- size                             \n");
	printf("\t ------------------------------------------------------------\n");
	printf("\t 8 -- height           t -- root            x -- viewPre     \n");
	printf("\t 9 -- level            f -- father          y -- viewIn      \n");
	printf("\t s -- search           l -- leftChild       z -- viewPost    \n");
	printf("\t g -- Get              r -- rightChild      w -- viewLevel   \n");
	printf("\t ------------------------------------------------------------\n");
	printf("\t T -- Ins_root         N -- Input_newTree   v -- view        \n");
	printf("\t L -- Ins_leftChild    M -- Input_newTree2  S -- view_sum    \n");
	printf("\t R -- Ins_rightChild   X -- exchange_tree   m -- full menu   \n");
	printf("\t q -- quit             Y -- common yongest Ancester          \n");
	printf("\t ======================= End ================================\n");
	printf("Please enter your choice:");
}

void main()
{
	BinaryTree<char> bt;
	char choice;
	char info;
	bool end_mark=false;
	bool ret;

	while(end_mark==false){
		bt.view();
	    menu();
		choice=getchar();
		getchar();
		
	switch(choice)
	{
	case 'q':
		end_mark=true;
		break;
	case '1':
		bt.clear();
		break;
	case '2':
		ret=bt.empty();
		printf("The answer is %d \n",ret);
		break;
	case '3':
		printf("The size is %d \n",bt.size());
		break;
	case '8':
		printf("The height is %d \n",bt.height());
		break;
	case '9':
		printf("The current level is %d \n",bt.level());
		break;
	case 'g':
		printf("The current info is %c \n",bt.get());
		break;
	case 's':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.find(info);
		break;
	case 'T':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.Ins_root(info);
		break;
	case 'f':
		bt.parent();
		break;
	case 'l':
		bt.leftChild();
		break;
	case 'r':
		bt.rightChild();
		break;
	case 'x':
		bt.printPreOrder();
		printf("\n");
		break;
	case 'y':
		bt.printInOrder();
		printf("\n");
		break;
	case 'z':
		bt.printPostOrder();
		printf("\n");
		break;
	case 'w':
		bt.printLevelOrder();
		printf("\n");
		break;
	case 't':
		bt.gotoRoot();
		break;
	case 'L':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.Ins_leftChild(info);
		break;
	case 'R':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.Ins_rightChild(info);
		break;
	default:break;

}
	}
}