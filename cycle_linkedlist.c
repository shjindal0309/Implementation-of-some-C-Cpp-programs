//Assignment 2 , Q.6 O(n) algorithm
//Shubham Jindal
//Roll No:150101071

#include<stdio.h>  //including standard input/output library
#include<stdlib.h>

/* Link list node */
struct node         //defining node for linked lost
{
    int data;       //data field
    struct node* next;      //pointer field
};
struct node* head=NULL;
void insertnode()   //function to insert node in linked list
{
    int d,i,j,k=1;
    struct node* temp2=head;
    if(temp2!=NULL)
    {
    while(temp2->next!=NULL)    //going to the last node
    {
        temp2=temp2->next;
        k++;
    }
}
    if(head!=NULL)      // for the when there is atleast one node already present
    {                   // in linked list
    do
    {
    printf("enter index in the range [1,%d] after u want to insert: ",k);
    getchar();
    scanf("%d",&j);
    if(j>k || j<1)
    {
        printf("Enter valid index\n");
    }
    }while(j<1 || j>k);     // exit condition of do while loop
    }
    printf("enter data: ");
    scanf("%d",&d);
    struct node* temp;
    struct node* temp1=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    if(head==NULL)  // when linked list is empty
    {
        head=temp;
    }
    else
    {
        for(i=0;i<j-1;i++)      // adjust the links after which we want to insert element
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
}
/* Function to remove loop. */
//void removeLoop(struct node *);

/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop()
{
    // slow pointer and fast pointer to detect loop
    struct node *slow = head;
    struct node *fast = head->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
        while (slow != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
        return 1;  //return 1 if there is a loop
    }
    else
        return 0;  // return 0 if no loop

}

void printList(struct node *node)   //the function to print linked list
{

    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n(please carefully trace the above linked list)\n");
}

/* Driver program to test above function*/
int main()
{
    char c;
    int i,j,x;
    do
    {
        insertnode();
        getchar();  // clearing input buffer
        printf("If you want to insert node enter y else any other key: ");
        scanf("%c",&c);
    }while(c=='y'); // exit condition of do-while loop
    printf("linked list u entered is ");
    printList(head);
    struct node *temp=head;    // defining a temp node
    struct node *temp1=head;    // defining a temp1 node

    printf("\nEnter the node at which you want the loop to start: ");
    scanf("%d",&i);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    for(j=0;j<i-1;j++)
    {
        temp1=temp1->next;
    }

    temp->next=temp1;

    x=detectAndRemoveLoop();        // function to detect and remove loop

    if(x==1)                        // printing if loop exist or not
        printf("loop is found\n");
    else if(x==0)
        printf("No loop is found\n");

    printf("Linked List after removing loop ");
    printList(head);
    return 0;
}
