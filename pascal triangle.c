#include <stdio.h>
#include <math.h>
int fact(int);
int main()
{
    int x,y=1,z,w,v,p,q,r,t;
  printf("enter the number of lines");
  scanf("%d",&x);

for(z=1;z<=x;z++)
{
  //  printf("1stfor\n");
    for(w=(x-z);w>=0;w--)
    {
        printf("\t");
    }
    for(v=0;v<=z-1;v++)
    {
       // printf("2ndfor\n");
        q=fact(z-1);
        r=fact(z-1-v);
        t=fact(v);
        //printf("%d",r*t);
        p=q/(r*t);
        printf("%-3d \t\t",p);
     }
    printf("\n");
    y++;
}
       return 0;
}
int fact(a)
{
  //  printf("infact\n");
    int q;
    for(q=a-1; q>=1; q--)
    {
        a=a*q;
    }
    if(a<=0)
    {
        return 1;
    }
    else
        return a;
}
