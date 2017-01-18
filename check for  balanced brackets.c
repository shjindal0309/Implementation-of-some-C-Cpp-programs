#include <stdio.h>
char s1[1000]={0};
int count1=0,count2=0,count3=0,stackcounter=-1;
void push(char c)
{
    if(c=='(')
    {
        stackcounter++;
        s1[stackcounter]=c;
        count1++;
    }
    if(c=='{')
    {
        stackcounter++;
        s1[stackcounter]=c;
        count2++;
    }
    if(c=='[')
    {
        stackcounter++;
        s1[stackcounter]=c;
        count3++;
    }
}
void pop(char c)
{
    if(c==')')
    {
        stackcounter--;
        count1--;
    }
    else if(c=='}')
    {
        stackcounter--;
        count2--;
    }
    else if(c==']')
    {
        stackcounter--;
        count3--;
    }
}
int main()
{   int x,y,z,w,i;
    char s[1000];
    printf("enter the string");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        push(s[i]);
        else
        {
            if((count1==0 && count2==0 && count3==0)|| ((s[i]-s[stackcounter])>2 || (s[i]-s[stackcounter])<1) )
            {
                printf("invalid string");
                return 1;
            }
            else
                pop(s[i]);
        }
    }
    printf("valid string");
    return 0;
    }
