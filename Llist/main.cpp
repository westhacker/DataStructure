#include "llist_class.h"
#include <stdio.h>
#include <stdlib.h>


void menu(){
	printf("\t ========= ====== Menu ========= ========   \n");
	printf("\t c -- Clear            i -- Insert          \n");
	printf("\t E -- IsEmpty          a -- Append          \n");
	printf("\t F -- IsFull           I -- Insert_cur      \n");
	printf("\t L -- Length           e -- Exchange        \n");
	printf("\t G -- Get              d -- Delete          \n");
	printf("\t p -- Prior            v -- Delete_v        \n");
	printf("\t n -- Next             D -- Delete_cur      \n");
	printf("\t f -- Find             R -- Reverse         \n");
	printf("\t g -- Goto             o -- Output          \n");
	printf("\t q -- quit             s -- InsertSort      \n");
	printf("\t ========= ====== End ========== ========   \n");
	printf("Please enter your choice:");
}

void main()
{
	List seq_List;
	char choice;
	char info,info1,info2;
	bool end_mark=false;
	int index=0;
	bool ret;

	while(end_mark==false){
		seq_List.Output();
	    menu();
		choice=getchar();
		getchar();
		
	switch(choice)
	{
	case 'q':
		end_mark=true;
		break;
	case 'c':
		seq_List.Clear();
		break;
	case 'E':
		ret=seq_List.IsEmpty();
		printf("The answer is %d \n",ret);
		break;
	case 'F':
		ret=seq_List.IsFull();
		printf("The answer is %d \n",ret);
		break;
	case 'L':
		index=seq_List.Length();
		printf("The Length is %d \n",index);
		break;
	case 'G':
		printf("Enter the index of the elem:");
		scanf("%d",&index);
		getchar();
		ret=seq_List.Get(index,info);
		if(ret==false)
			printf("Fail.\n");
		break;
		
		
	case 'a':
		printf("Enter the info to append:");
		scanf("%c",&info);
		getchar();
		seq_List.Append(info);
		break;
	case 'i':
		printf("Enter the index to insert:");
		scanf("%d",&index);
		getchar();
		printf("Enter the info to insert:");
		scanf("%c",&info);
		getchar();
		seq_List.Insert(index,info);
		break;
	case 'I':
		printf("Enter the info to insert:");
		scanf("%c",&info);
		getchar();
		seq_List.Insert_Cur(info);
		break;
	case 'd':
		printf("Enter the index to delete:");
		scanf("%d",&index);
		getchar();
		seq_List.Delete(index);
		break;
	case 'R':
		seq_List.Reverse();
		break;
	case 'p':
		seq_List.Prior();
		break;
	case 'v':
		printf("Enter the info to delete:");
		scanf("%c",&info);
		getchar();
		seq_List.Delete_v(info);
		break;
	case 'n':
		seq_List.Next();
		break;
	case 'e':
		printf("Enter the info1 to exchange:");
		scanf("%c",&info1);
		getchar();
		printf("Enter the info2 to exchange:");
		scanf("%c",&info2);
		getchar();
		seq_List.Exchange(info1,info2);
		break;
	case 'D':
		seq_List.Delete_cur();
		break;
	case 'f':
		printf("Enter the elem:");
		scanf("%c",&info);
		getchar();
		seq_List.Find(info);
		break;
	case 'g':
		printf("Enter the index to curser:");
		scanf("%d",&index);
		getchar();
		seq_List.Set_Cur(index);
		break;
	case 'o':
		seq_List.Output();
		break;
	case 's':
		seq_List.InsertSort();
		break;
	default:break;

}
	}
}