#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int rec(int *b,int m,int j,int i)
{
    int k;

    if(i<=m-1)
    {
        if(b[j]>b[i])
        { j=i;
          k=rec(b,m,j,i+1);
          return k;
        }

    else
        {k=rec(b,m,j,i+1);
        return k;}
    }
        else
            return j;
}
int main()
{
   int n;
   printf("enter ");
   scanf("%d",&n);
   int a[n],i,j=0,k;
   printf("enter elements of array");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("u have entered ");
   for(i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }
   k=rec(a,n,j,j+1);
   printf("\nsmallest %d %d",a[k]);

    return 0;
}
