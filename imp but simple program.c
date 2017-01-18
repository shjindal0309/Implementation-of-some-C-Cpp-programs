#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int x=1,y,z,k=1,i,j;
    y=x;
    z=k;
    printf("y=%d",y);
    printf("        z=%d",z);
    i=y++;
    j=++z;
    printf("\ni=%d",i);
    printf("        j=%d",j);
    printf("\ny++=%d",y++);
    printf("        ++z=%d",++z);
    return 0;
}
