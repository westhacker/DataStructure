#include "chash.h"
#include <iostream>
using namespace std;

void menu(){
	printf("============= Menu =================   \n");
	printf("  i -- insert        s -- search         \n");
	printf("  d -- delete        v -- view           \n");
	printf("  q -- quit                              \n");
	printf("============= End ==================   \n");
	printf("Please enter your choice:");
}



int main() 
{
	    CHASH<char*> endic(101);
		char choice;
		char info[20]="";
		char temp[101][20];
		int index=0;
		bool end_mark=false;
		int ret=-1;
		char string[11][20]={"an","and","at","be","ball","by","cat","catch","china","chinese"};
		for(int i=0;i<10;i++)
			endic.insert(string[i]);

		while(end_mark==false)
		{
			//endic.rehash();
			endic.view(ret);
			menu();
			choice=getchar();
			getchar();

			switch(choice)
			{
			case 'q':
				end_mark=true;
				break;
			case 'i':
				cout<<"Please input the word to insert:";
		        gets(temp[index]);
				endic.insert(temp[index]);
				index++;
				break;
			case 'd':
				cout<<"Please input the word to delete:";
				scanf("%s",info);
				getchar();
				endic.remove(info);
				break;
			case 's':
				cout<<"Please input the word to search:";
				gets(info);
				ret=endic.find(info);
				if(ret==-1)cout<<"NO SUCH WORD!\n";
				break;
			case 'v':
				endic.view(ret);
				break;
			default:break;
		    }
		}

	return 0;
}
