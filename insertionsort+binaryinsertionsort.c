#include<stdio.h>
#include<stdlib.h>
int count1=0;
void printsortedarray(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int insertsort(int *a,int n)
{
    int i,j,key,count=0;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        for(;a[j]>key && j>=0;j--)
        {
            if(a[j]>key)
            {
                count++;
                a[j+1]=a[j];
            }
        }
        a[j+1]=key;
    }
    printsortedarray(a,n);
    return count;

}
int binarysearch(int *b,int start,int end,int key)
{
    int mid;
    if(start<end)
    {
        mid=(end-start)/2+start;
        if(b[mid]==key)
        {
            count1++;
            return mid;
        }
        else if(b[mid]<key)
        {
            count1++;
            return binarysearch(b,mid+1,end,key);
        }
        else
        {
            count1++;
            return binarysearch(b,start,mid,key);
        }
    }
    else
    {
        return end;
    }
}
int binaryinsertsort(int *b,int n)
{
    int i,j,key,count=0,zeroindex,position,k;
    for(i=1;i<n;i++)
    {
        key=b[i];
        j=i-1;
        zeroindex=0;
        position=binarysearch(b,zeroindex,j,key);
        for(;j>=position;j--)
        {
            b[j+1]=b[j];
        }
        b[j+1]=key;
    }
    printsortedarray(b,n);
    return count1;

}
int main()
{
    int n,i,x,y;
    printf("enter size of array");
    scanf("%d",&n);
    getchar();
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        b[i]=a[i];
    }
    x=insertsort(a,n);
    y=binaryinsertsort(b,n);
    printf("x=%d  y=%d",x,y);
    return 0;
}
