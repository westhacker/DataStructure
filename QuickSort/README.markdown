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

# QuickSort

* 快速排序（Quicksort）是对冒泡排序的一种改进。由C. A. R. Hoare在1962年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
* Quicksort, or partition-exchange sort, is a sorting algorithm that, on average, makes O(n log n) comparisons to sort n items. In the worst case, it makes O(n2) comparisons, though this behavior is rare. Quicksort is often faster in practice than other O(n log n) algorithms. Additionally, quicksort's sequential and localized memory references work well with a cache. Quicksort is a comparison sort and, in efficient implementations, is not a stable sort. Quicksort can be implemented with an in-place partitioning algorithm, so the entire sort can be done with only O(log n) additional space used by the stack during the recursion.

# Content

<pre><code>
#include "stack.h"

//快速排序
int partion(int a[],int low,int high)
{
int temp=a[low];
do{
while(low<high&&a[high]>=temp)high--;
if(low<high){a[low]=a[high];low++;}
while(low<high&&a[low]<=temp)low++;
if(low<high){a[high]=a[low];high--;}
}
while(low!=high);
a[low]=temp;
return low;
}

void quicksort(int a[],int n)
{
Stack<int> qt;
qt.push(n-1);
qt.push(0);
while(!qt.empty())
{
	int low=qt.pop();
	int high=qt.pop();
	int mid=partion(a,low,high);
	if(low<mid)
	{
		qt.push(mid-1);
		qt.push(low);
	}
	if(mid<high)
	{
		qt.push(high);
		qt.push(mid+1);
	}
}
}

int main()
{
	int a[]={5,7,3,0,4,2,1,9,6,8};
	quicksort(a,10);
	for(int i=0;i<10;i++)
		printf("%d",a[i]);
	scanf("%d",a[1]);
}
</code></pre>

# Thanks

Thanks for your reading and happy coding