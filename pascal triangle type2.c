#include <stdio.h>
#include <math.h>
//int fact(int);
int main()
{
    int x,y=1,z,w,v=1,p,q,r=1,t;
  printf("enter the number of lines");
  scanf("%d",&x);

for(z=1;z<=x;z++)
{
  //  printf("1stfor\n");
    for(w=(x-z);w>=0;w--)
    {
        printf("\t\t");
    }
   t=(4*r-3);
    for(v=1;v<=(t+1)/2;v++)
    {
        printf("%-3d\t\t",v);

    }
r++;
    printf("\n");
}return 0;
}
