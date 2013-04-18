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

# AVLTree

AVL树是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个儿子子树的高度最大差别为一，所以它也被称为高度平衡树。查找、插入和删除在平均和最坏情况下都是O(log n)。增加和删除可能需要通过一次或多次树旋转来重新平衡这个树。
In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.[1] In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

# Content

*	bool deleteavl(Type x,BNODE *t)//AVL结点删除
*	void insertavl(Type x,BNODE *t)//AVL插入结点
*	void rotateright(BNODE *t)//在结点t处树向右倾斜
*	void rotateleft(BNODE *t)//在结点t处树向左倾斜
*	bool sfind(Type x,BNODE *t)//二叉排序树搜索函数
*   void sinsert(Type x,BNODE *t)//二叉排序树插入函数
*	bool Ins_root(Type info)//插入root
*	bool Ins_leftChild(Type info)//插入左儿子
*	bool Ins_rightChild(Type info)//插入右儿子
*	void sdel(Type x,BNODE *t)//二叉排序树结点删除函数
*	int height(BNODE *ptr)const//获取节点高度
*	void clear(BNODE *ptr)//清空所有节点
*	int size(BNODE *ptr)const//获取节点下面所有节点的数目
*	int level(BNODE *ptr)const//获取节点层数
*	bool empty( ){ return root == NULL;}//判断树是否空	
*	int size( ){return size(root);}//返回树的节点总数
*	int level( ){return level(current);}//返回树的总层数	
*	int height( ){return height(root);}//返回树的总高度	
*	void tQueue(BNODE *ptr)//二叉排序树结点从小到大入队
*	void Levelprint(BNODE *ptr,int lev)//第lev层按中序打印info
*	void LevelprintBalance(BNODE *ptr,int lev)//第lev层按中序打印平衡因子
*	int getnum(BNODE *ptr)//获取二叉排序树结点的中序位置
*	int setblank(BNODE *ptr)//计算节点前TAB次数
*	AVL(){root=NULL;current=NULL;}//构造
*	~AVL(){clear();}//析构
*	void clear(){if(root!=NULL)clear(root);root=NULL;}//清空树
*	void parent( )//返回父节点
*	void leftChild( )//指向左儿子
*	void rightChild( )//指向右儿子
*	void view( )//打印树
*	void viewBalance( )//打印平衡因子
*	bool sfind(Type x)//查找
*   void sinsert(Type x)//二叉查找树插入
*	void sdel(const Type &x)//二叉查找树删除
*	Type sfindmax()//找最大
*	Type sfindmin()//找最小
*	void batchinsertavl(Type *Array,int l)//批量插入形成AVL树
*	void rotateright()//当前结点向右旋转
*	void rotateleft()//当前结点向左旋转
*	void insertavl(Type x)//插入AVL结点
*	void deleteavl(const Type &x)//删除AVL结点

# Thanks

Thanks for your reading and happy coding
