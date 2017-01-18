#include <stdio.h>
#include <math.h>
int main()
{  int x,n,z,w,v;
   printf("enter the number of lines to print");
   scanf("%d",&x);

  {for(z=1;z<=x;z++)
  {for(w=11-z;w>=1;w--)
    {printf("\t");}

       for(v=(z*z-z+2)/2;v<=(z*z+z)/2;v++)
             printf("%d\t",v);
           printf("\n");
       }
}
     return 0;
}
