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
{   int count;
    struct node *temp,*temp1;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
        {
         head=temp;
         temp->next=NULL;
        }
    else if(head!=NULL){
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
int main()
{   char c,m=0;
    int n=1;
    struct node *temp;
    printf("Do u want to enter the elements to the list?press e or q to quit");
    scanf("%c",&c);
    do{
    createnode(n);
    m++;
    printf("Do u want to enter the another element..press e or q to quit");
    getchar();
    scanf("%c",&c);
    printf("Enter the position(>0 and <=%d) at which u want to enter another new node: ",m+1);
    scanf("%d",&n);
    }while(c=='\n');
}

