//Assignment 3 Q.2
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

//this function finds the number of leaves in the binary search tree
//we are receiving the address of root node in temp
int findleavescount(struct node** temp)
{
    int lh=0,rh=0;  //lh and rh are used to store the number of leaves in left and
                    // right subtree recursively

    //finding the height of right and left subtrees based on the fact
    //that on which node we are currently there

    //This situation tells that the node has both
    //right and left child
    if( (*temp)->right!=NULL && (*temp)->left!=NULL )
    {
        lh=findleavescount(&(*temp)->left);

        rh=findleavescount(&(*temp)->right);

    }

    //This situation tells that the node does not has
    //right child
    else if((*temp)->right==NULL && (*temp)->left!=NULL )
        {
            lh=findleavescount(&(*temp)->left);

        }

    //This situation tells that the node does not has
    //left child
    else if((*temp)->right!=NULL && (*temp)->left==NULL )
        {
            rh=findleavescount(&(*temp)->right);

        }

    //This situation implies that we are at leaf node
    else if((*temp)->right==NULL && (*temp)->left==NULL)
    {
       printf("%d\t",(*temp)->data);
       return 1;
    }
    return
        lh+rh;     //returning the lh+rh which represents the
                  //final number of leaf nodes in the tree
}

//function to insert node in the Binary Search Tree
//receiving address of root in temp1 and data to insert in key
struct node* insertbinary(struct node** temp1,int key)
{
    if(*temp1==NULL)
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));  //Allocation of memory for node
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;  //returning the address of newly created node
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
    int Number_of_leaf_nodes;  //this c will store the value of number of leaf nodes

    int i,j,a[100];

    generate_array(a,100);   //Function to generate array with 100 elements

    print_array(a,100);     //printing the randomly generated array

    for(i=0;i<100;i++)   //we are taking 100 hundred elements so 100 is there in loop
    root=insertbinary(&root,a[i]);   //inserting each element in BST

    printf("\nleaf nodes are:\n");
    Number_of_leaf_nodes=findleavescount(&root);   //finding the number of leaves in the binary search tree

    printf("\n\nNumber of leaf nodes=%d\n",Number_of_leaf_nodes);

	return 0;
}




