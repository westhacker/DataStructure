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

# HashTable

* Hashing定义了一种将字符组成的字符串转换为固定长度（一般是更短长度）的数值或索引值的方法，称为散列法，也叫哈希法。由于通过更短的哈希值比用原始值进行数据库搜索更快，这种方法一般用来在数据库中建立索引并进行搜索，同时还用在各种解密算法中。
* In computing, a hash table (also hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found.

# Content

<pre><code>
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
</code></pre>

# Thanks

Thanks for your reading and happy coding