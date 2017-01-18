#include <stdio.h>


int heap(int* a,int i,int size)
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
		heap(a,largest,size);
	}
}
int build(int* a,int size)
{
    int i;
	for(i=size/2;i>=0;i--)
	{
		heap(a,i,size);
	}
}
int heapsort(int* a,int size)
{
	build(a,size);
    /*int i;
	for(i=size;i>=1;i--) //greater than or equal to 1
	{					 //as after that in for loop size--->-1
		int temp=a[0];
		a[0]=a[size];
		a[size]=temp;
		size--;

		heap(a,0,size);

	}*/
}
int extract_max(int* a,int size)
{
	int i=a[0];
    a[0]=a[size];

	size--;
	heap(a,0,size);

	return i;
}
int increase(int* a,int index,int key,int size)
{
	if(key < a[index])
	{
		printf("error");
		return 0;
	}
	a[index]=key;
	int p=(index-1)/2,temp;
	while(p>0 && a[p] <=a[index])
	{
        temp=a[index];
		a[index]=a[p];
		a[p]=temp;
		index=p;
		p=(index-1)/2;
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
	
	printf("\n\n");
	int j=extract_max(a,size);
	size--;
	printf("\nmax=%d\n",j);

    for(i=0;i<=size;i++)
	printf("%d ",a[i]); printf("\n");

	int index=7;
	increase(a,index,9,size);
	for(i=0;i<=size;i++)
	printf("%d ",a[i]);
}
