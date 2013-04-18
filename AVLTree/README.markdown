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

AVL�������ȷ�������ƽ��������������AVL�����κνڵ���������������ĸ߶������Ϊһ��������Ҳ����Ϊ�߶�ƽ���������ҡ������ɾ����ƽ���������¶���O(log n)�����Ӻ�ɾ��������Ҫͨ��һ�λ�������ת������ƽ���������
In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.[1] In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

# Content

*	bool deleteavl(Type x,BNODE *t)//AVL���ɾ��
*	void insertavl(Type x,BNODE *t)//AVL������
*	void rotateright(BNODE *t)//�ڽ��t����������б
*	void rotateleft(BNODE *t)//�ڽ��t����������б
*	bool sfind(Type x,BNODE *t)//������������������
*   void sinsert(Type x,BNODE *t)//�������������뺯��
*	bool Ins_root(Type info)//����root
*	bool Ins_leftChild(Type info)//���������
*	bool Ins_rightChild(Type info)//�����Ҷ���
*	void sdel(Type x,BNODE *t)//�������������ɾ������
*	int height(BNODE *ptr)const//��ȡ�ڵ�߶�
*	void clear(BNODE *ptr)//������нڵ�
*	int size(BNODE *ptr)const//��ȡ�ڵ��������нڵ����Ŀ
*	int level(BNODE *ptr)const//��ȡ�ڵ����
*	bool empty( ){ return root == NULL;}//�ж����Ƿ��	
*	int size( ){return size(root);}//�������Ľڵ�����
*	int level( ){return level(current);}//���������ܲ���	
*	int height( ){return height(root);}//���������ܸ߶�	
*	void tQueue(BNODE *ptr)//��������������С�������
*	void Levelprint(BNODE *ptr,int lev)//��lev�㰴�����ӡinfo
*	void LevelprintBalance(BNODE *ptr,int lev)//��lev�㰴�����ӡƽ������
*	int getnum(BNODE *ptr)//��ȡ������������������λ��
*	int setblank(BNODE *ptr)//����ڵ�ǰTAB����
*	AVL(){root=NULL;current=NULL;}//����
*	~AVL(){clear();}//����
*	void clear(){if(root!=NULL)clear(root);root=NULL;}//�����
*	void parent( )//���ظ��ڵ�
*	void leftChild( )//ָ�������
*	void rightChild( )//ָ���Ҷ���
*	void view( )//��ӡ��
*	void viewBalance( )//��ӡƽ������
*	bool sfind(Type x)//����
*   void sinsert(Type x)//�������������
*	void sdel(const Type &x)//���������ɾ��
*	Type sfindmax()//�����
*	Type sfindmin()//����С
*	void batchinsertavl(Type *Array,int l)//���������γ�AVL��
*	void rotateright()//��ǰ���������ת
*	void rotateleft()//��ǰ���������ת
*	void insertavl(Type x)//����AVL���
*	void deleteavl(const Type &x)//ɾ��AVL���

# Thanks

Thanks for your reading and happy coding
