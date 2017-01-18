//Assignment 3 Q.3
//Shubham Jindal   Roll No.150101071

//Time complexity of insertbinary function is O(h) also the time complexity of
//findLCA function is O(n) as the method does a simple tree traversal
//in bottom up fashion so it goes through all the
//elements of the tree and time complexity of searchkey function is also O(h)
//where h is the height of the tree and n is the number of elements in the tree
//so overall time complexity of this solution is O(n)

//Standard libraries used in th program
#include<stdio.h>

//creating node for tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//This function will search whether the key1 and key2 that
//user entered exits in tree or not
//We are receiving the address of root node in temp
int searchkey(struct node** temp,int key)
{
    int x=0,y=0;
    if(*temp!=NULL)
    {
        if(key > (*temp)->data)
        {
            x=searchkey(&(*temp)->right,key);
            return x;
        }
        else if(key < (*temp)->data)
        {
            y=searchkey(&(*temp)->left,key);
            return y;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }

}

//this function finds the lowest common ancestor
// here we are receiving the address of root node in local pointer
//to pointer variable root.
struct node* findLCA(struct node** root,int key1,int key2)
{
  if (*root == NULL)
        return NULL;

    if ((*root)->data == key1 || (*root)->data == key2)
    {           // If either key1 or key2 matches with root's key, report
                // the presence by returning root (Note that if a key is
                // ancestor of other, then the ancestor key becomes LCA
        return *root;
    }

    //Look for keys in leftsubtree
    struct node* LCAinlefttree  = findLCA(&(*root)->left, key1, key2);

    //Look for keys in rightsubtree
    struct node* LCAinrighttree = findLCA(&(*root)->right, key1, key2);

    // If both of the above calls return Non-NULL,
    // then one key is present in once subtree
    //and other is present in other,So this node is the LCA
    if (LCAinlefttree!=NULL && LCAinrighttree!=NULL)
    {

        return *root;
    }
    if(LCAinlefttree!=NULL)
        return LCAinlefttree;  //if the leftsubtree contains LCA
    else
        return LCAinrighttree;  //if the right subtree contains LCA
}

//function to insert node in the Binary Search Tree
//receiving address of root in temp1 and data to insert in key
struct node* insertbinary(struct node** temp1,int key)
{
    if(*temp1==NULL)
    {
        struct node* temp;

        //Allocation of memory for node
        temp=(struct node*)malloc(sizeof(struct node));

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

    for(i=0;i<size;i++)  //we are taking 100 hundred elements so 100 is there in loop
    {
        a[i]=rand();     //taking each element of array randomly
    }
}

//This function will print randomly generated array
void print_array(int *a,int size)
{
    printf("Randomly generated array is:\n");
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
    int i,key1,key2;
    int x,y;

    struct node* root=NULL;
    struct node* temp;

    int a[100];
    generate_array(a,100);   //Function to generate array with 100 elements

    print_array(a,100);     //printing the randomly generated array

    for(i=0;i<100;i++)   //we are taking 100 hundred elements so 100 is there in loop
        root=insertbinary(&root,a[i]);    //inserting each element in BST

    printf("\n100 random numbers generated now Enter key1 and key2:\n"\
            "(Remember the numbers u enter may not be in tree) ");

    scanf("%d %d",&key1,&key2);  //taking key1 and key2 to find their
                                 //lowest common ancestor in binary search tree

    x=searchkey(&root,key1);
    y=searchkey(&root,key2);
    if(x==1 && y==1)    //if x and y both exists in tree than find LCA

    {
        temp=findLCA(&root,key1,key2);  //find the lowest common ancestor and receiving
                                    //the return value in temp to determine whether
                                    // the lowest common ancestor exists or not

        printf("\nLCA=%d\n",temp->data);   //printing the lowest common ancestor
    }
    else        //if either x or y or both don't exist in tree then show error
    {
         printf("\nNo lowest common ancestor exists,means one of key1 and key2"\
               " or both key1 and key2 are not there in tree\n");
    }

    return 0;
}
//Time complexity of insertbinary function is O(h) also the time complexity of
//findLCA function is O(n) as the method does a simple tree traversal
//in bottom up fashion so it goes through all the
//elements of the tree and time complexity of searchkey function is also O(h)
//where h is the height of the tree and n is the number of elements in the tree
//so overall time complexity of this solution is O(n)

