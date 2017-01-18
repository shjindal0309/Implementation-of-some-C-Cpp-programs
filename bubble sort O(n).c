#include <stdio.h>
/*MOST OPTIMIZED VERSION*/
int main()
{ int n,c2=0;
    scanf("%d",&n);
    int a[n],i,j,k,l,m=0,flag=1;
    printf("enter \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;flag==1;i++)
        {flag=0;
        for(j=0;j<=n-i-1;j++)
    {
         if(a[j]>a[j+1])
     {   c2++;
         l=a[j];
         a[j]=a[j+1];
         a[j+1]=l;
         flag=1;
     }
     }
       if(flag==0)
        break;
        }

    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
   return 0;

}
