#include <stdio.h>
#include <stdlib.h>
#define divide 47
#define multiply 42
#define add 43
#define minus 45
char s1[1000]={0};
int stackcounter=-1;
void push(char c)
{   if(stackcounter<0)
    {
        stackcounter++;
        s1[stackcounter]=c;
    }
    else
    {
        stackcounter++;
        s1[stackcounter]=c;
        if(s1[stackcounter]==divide)
        {
            while(s1[stackcounter]>=s1[stackcounter-1])
            {
                printf("%c",s1[stackcounter-1]);
                stackcounter--;
                if(stackcounter>0)
                    continue;
                else
                    break;
            }
            s1[stackcounter]=c;
        }
        if(s1[stackcounter]==minus)
        {
            printf("%c",s1[stackcounter]);
        }
        if(s1[stackcounter]==add && stackcounter>0)
        {
            while(s1[stackcounter-1]>=43 || s1[stackcounter-1]<=45 )
            {
                printf("%c",s1[stackcounter-1]);
                stackcounter--;
                if(stackcounter>0)
                    continue;
                else
                    break;
            }
            s1[stackcounter]=c;
        }
        if(s1[stackcounter]==multiply)
        {
            while(s1[stackcounter-1]<47)
            {
                printf("%c",s1[stackcounter-1]);
                stackcounter--;
                if(stackcounter>0)
                    continue;
                else
                    break;
            }
            s1[stackcounter]=c;
        }
    }
}
int main()
{   int j,flag,i;
    char s[1000];
    printf("enter the string");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {   flag=1;
        for(j=0;j<=9;j++)
        {
            if(s[i]==48+j)
            {
                flag=0;
                printf("%c",s[i]);
                break;
            }
        }
        if(flag==1)
        {
                push(s[i]);
        }
    }
    // printing remaining item in stack
    for(;stackcounter>=0;stackcounter--)
    {
        printf("%c",s1[stackcounter]);
    }
    return 0;
    }
