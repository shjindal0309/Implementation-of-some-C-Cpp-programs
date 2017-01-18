#include <stdio.h>

int main()
{ int n;
    scanf("%d",&n);
    int a[n],i,j,k,temp,m=0;
    printf("enter \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=n-1;i++)
    {m=i;
         for(j=m+1;j<=n-1;j++)
       { if(a[m]>=a[j])
         {
            m=j;
         }
       }
      temp=a[i];
      a[i]=a[m];
      a[m]=temp;
    }
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
   return 0;

}
