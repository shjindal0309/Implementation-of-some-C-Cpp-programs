#include <stdio.h>
#include <math.h>

int main()
{ int x,y=1,z,w,v;
  printf("enter the number of lines");
  scanf("%d",&x);

for(z=1;z<=x;z++)  
{ 
for(w=(x-z);w>=0;w--)
{printf("\t");
 }
for(v=(y*y-y+2)/2;v<=(y*y+y)/2;v++)
{printf("%-3d \t\t",v);
 }
printf("\n");
y++;
}
       return 0;
}
