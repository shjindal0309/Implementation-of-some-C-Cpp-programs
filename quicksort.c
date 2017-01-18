#include <stdio.h>

int part(int* a,int p,int q,int r)
{
	int j=q,i=p;
	while(i<=j)
	{
		while(i<=j && a[i]<=r)i++;
		while(j>=i && a[j]>r)j--;
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	return j;
}

void quicksort(int* a,int p,int q)
{
	int j;

	if(p<q)  //think in terms of p>=q
	{
		j=part(a,p+1,q,a[p]);
		int temp=a[j];
		a[j]=a[p];
		a[p]=temp;
		quicksort(a,p,j-1);
		quicksort(a,j+1,q);
	}
}
int main()
{
	int a[10]={5,8,4,6,3,9,7,2,10,4};

	quicksort(a,0,9);int i;
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
}
