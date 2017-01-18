#include<stdio.h>
int main()
{
    int x,y,z,dv,r,q,dv1,a[40000],i,j,b[40000]={0},c=0;
    char s[40000],s1[40000];
    printf("enter a number ");
    scanf("%d",&x);
    if(x==0 || x==1)
        printf("number is binary");
    printf("\nbinary conversion after adding one to that number\n");
    for(dv=x+1,i=0;dv!=0;i++)
    {
        a[i]=dv%2;
        q=dv/2;
        dv=q;
        //printf("%d",r);
    }a[i]=dv;
    for(j=i;j>=0;j--)
        printf("%d",a[j]);
    printf("\nenter another number in binary\n");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++);
    j=i;
    for(i=0;i<j;i++)
    {
        b[i]=(s[i]-'0')*pow(2,j-1-i);
    }
    for(i=0;i<j;i++)
        c=c+b[i];
    z=c+x;

    for(dv1=z,i=0;dv1!=0;i++)
    {
        a[i]=dv1%2;
        q=dv1/2;
        dv1=q;
        //printf("%d",r);
    }a[i]=dv1;
    for(j=i;j>=0;j--)
        printf("%d",a[j]);

}
