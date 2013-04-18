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

# BankQueue

* ���нк��Ŷ�ϵͳģ�⣬����Queue���нṹ��������һ����������Ա���ֻ�����ڱ��ǰ�ˣ�front������ɾ�����������ڱ�ĺ�ˣ�rear�����в�����������в�������Ķ˳�Ϊ��β������ɾ�������Ķ˳�Ϊ��ͷ��������û��Ԫ��ʱ����Ϊ�ն��С�
* In computer science, a queue is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed. Often a peek or front operation is also implemented, returning the value of the front element without dequeuing it. A queue is an example of a linear data structure, or more abstractly a sequential collection.


# Content

* bank();
* int averagetime()const;

# Class bank

<pre><code>
class bank{
	int latime;
	int hatime;
	int lwtime;
	int hwtime;
	int num;
public:
	bank();
	int averagetime()const;
};
</code></pre>

# Thanks

Thanks for your reading and happy coding