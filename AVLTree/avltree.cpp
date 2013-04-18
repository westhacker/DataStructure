#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;


void menu(){
	printf("\t ============= Menu =================   \n");
	printf("\t c -- clear                         \n");
	printf("\t f -- find          p -- parent     \n");
	printf("\t l -- llink         r -- rlink      \n");
	printf("\t m -- max           n -- min        \n");
	printf("\t b -- batch_insert_AVL              \n");
	printf("\t i -- insert        I -- insert_AVL \n");
	printf("\t d -- delete        D -- delete_AVL \n");
	printf("\t / -- rotate_left   \\ -- rotate_right   \n");
	printf("\t v -- view_avl_balance   \n");
	printf("\t q -- quit               \n");
	printf("\t ============= End ==================\n");
	printf("Please enter your choice:");
}

void main()
{
	AVL<char> bt;
	char choice;
	char info;
	bool end_mark=false;
	bool ret;
	char a[100];


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
	case 'c':
		bt.clear();
		break;
	case 'f':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		ret=bt.sfind(info);
		printf("The answer is %d \n",ret);
		break;
	case 'd':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.sdel(info);
		break;
	case 'p':
		bt.parent();
		break;
	case 'l':
		bt.leftChild();
		break;
	case 'r':
		bt.rightChild();
		break;
	case 'm':
		printf("The max is:%c\n",bt.sfindmax());
		break;
	case 'n':
		printf("The min is:%c\n",bt.sfindmin());
		break;
	case 'i':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.sinsert(info);
		break;
	case 'b':
		printf("Enter the batch infomation:");
		cin.getline(a,100,'\n');
		bt.clear();
		bt.batchinsertavl(a,strlen(a));
		break;
	case 'v':
		bt.viewBalance();
		break;
	case '\\':
		bt.rotateright();
		break;
	case '/':
		bt.rotateleft();
		break;
	case 'I':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.insertavl(info);
		break;
	case 'D':
		printf("Enter the info:");
		scanf("%c",&info);
		getchar();
		bt.deleteavl(info);
		break;
	default:break;

}
	}
}