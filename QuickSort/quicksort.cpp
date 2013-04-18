#include "stack.h"

//øÏÀŸ≈≈–Ú
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