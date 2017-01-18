#include <stdio.h>

int heapify(int* a,int i,int size)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;

	if(l<=size && a[l]>a[i])largest=l;
	else largest=i;
	if(r<=size && a[r]>a[largest])largest=r;

	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,largest,size);
	}
}
int build(int* a,int size)
{
    int i;
	for(i=size/2;i>=0;i--)
	{
		heapify(a,i,size);
	}
}
int heapsort(int* a,int size)
{
	build(a,size);
    int i;
	for(i=size;i>=1;i--) //greater than or equal to 1
	{					 //as after that in for loop size--->-1
		int temp=a[0];
		a[0]=a[size];
		a[size]=temp;
		size--;

		heapify(a,0,size);

	}
}

int main()
{
	int a[10]={8,5,6,3,1,4,9,7,10,1};

    int size=9;
	heapsort(a,size);

	int i;
	for(i=0;i<=size;i++)
	printf("%d ",a[i]);
}
