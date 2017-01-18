//Assignment 3 Q.1
//Shubham Jindal   Roll No.150101071

//Standard libraries used in th program
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

//creating node for tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//finding maxheight of the tree
int maxheight(struct node** temp) //receiving the address of root in temp
{
    int lh=0,rh=0;      //lh for calculating height of left subtree
                        //rh for calculating height of right subtree
    if(*temp!=NULL)
    {
        lh=maxheight(&(*temp)->left); //calculating height of left subtree
        rh=maxheight(&(*temp)->right); //calculating height of right subtree
    }
    else
        return -1;   //returning one when temp==NULL
    if(lh>=rh)
        return ++lh;   //incrementing lh and rh and rh as height of leaf node is zero
    else               // and height of empty tree is -1
        return ++rh;
}
int minheight(struct node** temp)  //receiving the address of root in temp
{
    int lh=0,rh=0;          //lh for calculating height of left subtree
                           //rh for calculating height of right subtree
    if(*temp!=NULL)
    {
        lh=minheight(&(*temp)->left);  //calculating height of left subtree
        rh=minheight(&(*temp)->right); //calculating height of right subtree
    }
    else
        return -1;   //returning one when temp==NULL
    if(lh<=rh)
        return ++lh;    //incrementing lh and rh and rh as height of leaf node is zero
    else                // and height of empty tree is -1
        return ++rh;
}

//function to insert node in the Binary Search Tree
//receiving address of root in temp1 and data to insert in key
struct node* insertbinary(struct node** temp1,int key)
{
    if(*temp1==NULL)
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node)); //Allocation of memory for node
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;   //returning the address of newly created node
    }
     //checking whether the key is smaller or greater than root data
    if(key <= (*temp1)->data)
        (*temp1)->left=insertbinary(&(*temp1)->left,key);
    else
        (*temp1)->right=insertbinary(&(*temp1)->right,key);
    return
        *temp1;
}

//This function will generate an array with 100 random elements
void generate_array(int *a,int size)
{
    int i;
    srand(time(NULL));    //seeding so that we get randomly generated different
                          //sequences of number everytime

    for(i=0;i<size;i++)    //we are taking 100 hundred elements so 100 is there in loop
    {
        a[i]=rand();     //taking each element of array randomly
    }
}

//This function will print randomly generated array
void print_array(int *a,int size)
{
    printf("Randomly Generated array :\n");
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

//Driver function to run all other functions
int main()
{
    struct node* root=NULL;
    int x=0,a[100],e[101]={0};

    int i,j,diff[50],c[50],b[50];

    for(j=1;j<=50;j++)   //we are repeating the process 50 times so 50 is there in loop
    {
        generate_array(a,100);   //Function to generate array with 100 elements

        for(i=0;i<100;i++)   //we are taking 100 hundred elements so 100 is there in loop
            root=insertbinary(&root,a[i]);  //inserting each element in BST

        c[j-1]=maxheight(&root);   //finding the max height of the tree and put it in c[] array
        b[j-1]=minheight(&root);   //finding the min height of the tree and put it in b[] array
        diff[j-1]=c[j-1]-b[j-1];   //finding difference between max and min height
                                   // and put it in diff[] array
    }
    for(j=0;j<=100;j++)    //maximum difference of heights can be 100 so 100 is there in loop
    {
        for(i=0;i<50;i++)   //since difference is for 50 processes so 50 is there in loop
        {
            if(j==diff[i])
            {
                e[j]++;    // storing the differences values from 1-100 in e[] array
            }
        }
    }

    //printing the table for 50 processes
    printf("Process No:\t Difference");

    for(j=1;j<=50;j++)
        printf("\n%10d\t(max height=%d - min height=%d)=%d",j,c[j-1],b[j-1],diff[j-1]);

    for(i=0;i<=100;i++)
        printf("\n%d processes resulted in difference %d",e[i],i);

    printf("\n");
	return 0;
}
        //IMPORTANT NOTE:
        //after this please go to the top of the output


