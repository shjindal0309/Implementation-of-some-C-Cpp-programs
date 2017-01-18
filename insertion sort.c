#include<stdio.h>
int main()
{ int a[8],i,j,k,m,l;
   printf("enter elemrnt");
   for(i=0;i<8;i++)
   {
       scanf("%d",&a[i]);
   }
   for(j=1;j<8;j++)
   {
       for(k=0;k<j;k++)
       {
           if(a[k]>a[j])
           {   m=a[j];
               for(l=j-1;l>=k;l--)
               {
                   a[l+1]=a[l];
               }
               l++;
               a[l]=m;
           }
       }
   }
   for(i=0;i<8;i++)
   {
       printf("%d   ",a[i]);
   }
    return 0;
}
