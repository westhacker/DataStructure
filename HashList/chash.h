#include "hash.h"

template<class Type>
class CHASH:public HASH<Type>
{
private:
	struct node
	{
		Type info;
		int state;
		node(){state=0;}
	};
	node *Array;
	int size;

public:
	CHASH(int length=101)
	{
		size=length;
		Array=new node[size];
	}

	~CHASH(){delete []Array;}

	int find(Type x)const
	{
		int initpos,pos;
		bool flag=1;
		initpos=pos=Hash(x)%size;
		do{
			if(Array[pos].state==0)
							return -1;
						if(Array[pos].state==1)
						{
							for(int i=0;i<strlen(Array[pos].info);i++)
							{
								if(Array[pos].info[i]!=x[i])
								{
									flag=0;break;
								}
							}
							if(flag)
							return pos;
						}
						pos=(pos+1)%size;
		}while(pos!=initpos);
		return -1;
	}

	bool insert(Type x)
	{
		int initpos,pos;

		initpos=pos=Hash(x)%size;
		do{
			if(Array[pos].state!=1)
			{
				
				Array[pos].info=x;
				Array[pos].state=1;
				return true;
			}
			if(Array[pos].state==1&&Array[pos].info==x)
				return true;
			pos=(pos+1)%size;
		}while(pos!=initpos);

		return false;
	}

	bool remove(Type x)
	{
		bool flag=1;
		int initpos,pos;
		initpos=pos=Hash(x)%size;
		do{
			if(Array[pos].state==0)
				return false;
			if(Array[pos].state==1)
						{
							for(int i=0;i<strlen(Array[pos].info);i++)
							{
								if(Array[pos].info[i]!=x[i])
								{
									flag=0;break;
								}
							}
							if(flag){
							Array[pos].state=2;
							return true;
							}
						}
			pos=(pos+1)%size;
		}while(pos!=initpos);

		return false;
	}

	void rehash()
	{
		node *temp=new node[size];
		for(int i=0;i<size;i++)
		{
			if(Array[i].state==1)
			{
				temp[i].state=1;
				temp[i].info=Array[i].info;
			}
		}
		Array=new node[size];
		for(int i=0;i<size;i++)
		{
			if(temp[i].state==1)
				insert(temp[i].info);
		}
		delete []temp;
	}

	void view(int x)
	{
		for(int i=0;i<size;i++)
		{
			if(Array[i].state==1)
			{
			cout<<i<<":"<<"  -->"<<Array[i].info;
			if(x==i)cout<<"  <=="<<endl;
			else cout<<endl;
			}
		}
	}
};

int Hash(char *str)
{
	int hash = 0;
	int x	= 0;

	while (*str)
	{
		hash = (hash << 4) + (*str++);
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}