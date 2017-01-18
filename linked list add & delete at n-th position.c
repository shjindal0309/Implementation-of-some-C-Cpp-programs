#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void print()
{
    struct node *temp=head;
    printf("Updated list is: ");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void createnode(int n)
{
    int count;
    struct node *temp,*temp1;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else if(n==1)
    {
        temp->next=head;
        head=temp;
    }
    else if(head!=NULL)
    {
        temp1=head;
        for(count=1;count<n-1;count++)
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    print(head);
}
int deletenode(int n)
{
    int count;
    struct node *temp,*temp1,*temp2;
    if(head->next==NULL)
    {
        head=NULL;
        printf("Updated list is: NILL\n");
        return 0;
    }
    else if(n==1)
    {
        head=head->next;
        print(head);
        return 0;
    }
    else if(head!=NULL)
    {
        temp1=head;
        for(count=1;count<n-1;count++)
        {
            temp1=temp1->next;
        }
    }
    temp=temp1;
    temp1=temp1->next;
    if(temp1==NULL)
        temp=NULL;
    else
    temp2=temp1->next;
    temp->next=temp2;
    print(head);
    return 0;
}

int main()
{
    char c;
    int n=1,m=0;
    struct node *temp;
    printf("Do u want to enter/delete an element from the list?press e/d press q to quit: ");
    scanf("%c",&c);
    do
    {
    if((c=='d'|| c=='D')&& m==0)
        printf("can't delete as list is empty\n");
    else if((c=='d'||c=='D') && m>0)
    {
        m--;
        deletenode(n);
    }
    else if(c=='e' || c=='E')
    {
        m++;
        createnode(n);
    }
    else
        break;
    printf("Do u want to enter/delete an element from the list?press e/d press q to quit: ");
    getchar();
    scanf("%c",&c);
    if(c=='e'||c=='E')
    {
        printf("Enter the position(>0 and <=%d)at which u want to enter another new node: ",m+1);
        getchar();
        scanf("%d",&n);
    }
    else if(c=='d'&& m>0)
    {
        printf("Enter the position(>0 and <=%d) at which u want to delete a node: ",m);
        getchar();
        scanf("%d",&n);
    }
    }while(c!='q');
}

