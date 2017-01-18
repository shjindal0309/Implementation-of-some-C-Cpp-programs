#include <stdio.h>
#include <malloc.h>
struct node {
        int data;
        struct node *next;
    };
struct node *head=NULL;
void print(){
    struct node *temp=head;
    printf("upadated list is: ");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
void createnode()
{   struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    printf("enter data for new node: ");
    scanf("%d",&temp->data);

    if(head!=NULL)
        temp->next=head;
    head=temp;
    print(head);
}
int main()
{   char c;
    struct node *temp;
    printf("do u want to enter the elements to the list?press enter if yes");
    scanf("%c",&c);
    while(c=='\n'){
    createnode();
    printf("want to enter the another element..press enter if yes");
    getchar();
    scanf("%c",&c);
    }
}
