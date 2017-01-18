/* Using non-const in case label */
#include<stdio.h>

int main()
{int a[25],i,j,k=0;
printf("enter the numbers\n");
 for(i=0;i<=24;i++)
 {        scanf("%d",&a[i]);}
 printf("enter the number to be searched\n");
 scanf("%d",&j);
 for(i=0;i<=24;i++)
 {if(j==a[i])
   {  printf("Yes the number is present\n");
      break;}
     else
     continue;
 }
 for(i=0;i<=24;i++)
 {if(j==a[i])
    {k++;}
 }if(k==0)
 {
     printf("No,the number is not present");
 }
 printf("number of times the number occured is\"%d\"",k);
return 0;
}

