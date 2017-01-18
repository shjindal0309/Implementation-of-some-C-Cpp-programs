#include<stdio.h>
int main()
{
int a,b,c,d;
char e;
printf("enter the two numbers whose GCD you want to calculate");
scanf("%d %d",&a,&b);
if(a<b)
{c=a;a=b;b=c;}
for(;;)
{d=a%b;
  if(d==0)
{printf("GCD is %d\n",b);
 printf("do u want to enter another two numbers Y/N");
 fflush(stdin); 
 scanf("%c",&e);
  if(e=='Y')
    continue;
  else 
    break;}
  else
  {a=b;b=d;}
}
 
}
