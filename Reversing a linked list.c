#include <stdio.h>
#include <malloc.h>
struct node {
        int data;
        struct node *next;
    };
struct node *head=NULL;
void print(){
    struct node *temp=head;
    printf("Upadated list is: ");
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
void reverse()
{
    struct node *current=head,*prev=NULL,*next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    print(head);
}
int main()
{   char c;
    int n=1,m=0;
    struct node *temp;
    printf("Do u want to enter the elements to the list?press e or q to quit: ");
    scanf("%c",&c);
    do
    {
    if(c=='e')
    {
        createnode(n);
        m++;
    }
    else if(c=='q')
        break;
    printf("Do u want to enter the another element?press e or q to quit: ");
    getchar();
    scanf("%c",&c);
    if(c=='e')
    {
    printf("Enter the position(>0 and <=%d) at which u want to enter another new node: ",m+1);
    getchar();
    scanf("%d",&n);
    }
    }while(c!='q');
    printf("Reversed ");
    reverse();
}

