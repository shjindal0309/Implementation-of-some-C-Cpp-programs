#include <stdio.h>

int main()
{ int n;
    scanf("%d",&n);
    int a[n],i,j,k,l,m=0;
    printf("enter \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {

        for(j=0;j<=n-2;j++)
    {
         if(a[j]>a[j+1])
     {
         l=a[j];
         a[j]=a[j+1];
         a[j+1]=l;

     }
     }

        }

    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
   return 0;

}
