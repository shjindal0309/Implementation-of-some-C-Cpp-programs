//Assignment 3 Q.4
//Shubham Jindal   Roll No.150101071

//Time complexity of find_diameter function is O(n^2),time complexity of insertbinary function is
//O(h) and time complexity of searchkey function
//is O(h).So overall time complexity is O(n^2)+O(h)+O(h) which is equal to O(n^2)
// where h is the height of the root node and n is the number off elements in
//binary search tree.As in each recursion step of the find_diameter function we are scanning
// the elements of tree n times so in total times n^2 times.So overall
//Time complexity is O(n^2).

//Standard libraries used in th program
#include<stdio.h>
#include<math.h>
#include<malloc.h>

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

int maximum_of(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
}
int height(struct node** temp)
{
    if(*temp == NULL)
       return NULL;

    return (1 + maximum_of(height(&(*temp)->left), height(&(*temp)->right)));

}
//This function calculates the find_depth of the the node
//we are address of root node in temp
int find_diameter(struct node** temp)
{
    int lh,rh;  //lh means height of left subtree
                //rh means height if right subtree
    int ld,rd;  //ld meand diameter of left subtree
                //rd means diameter of right subtree

    if(*temp==NULL)
        return NULL;
    lh=height(&(*temp)->left);  //finding height of left subtree
    rh=height(&(*temp)->right); //finding height of right subtree

    ld=find_diameter(&(*temp)->left); //finding diameter of left subtree
    rd=find_diameter(&(*temp)->right); //finding diameter of right subtree

    //diameter is the maximum of ld,rd,lh+rh+1;
    return maximum_of(lh+rh+1,maximum_of(ld,rd));

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
    int i;
    int diameter;

    struct node* root=NULL;

    int a[100];

    generate_array(a,100);   //Function to generate array with 100 elements

    print_array(a,100);     //printing the randomly generated array

    for(i=0;i<100;i++)   //we are taking 100 hundred elements so 100 is there in loop
        root=insertbinary(&root,a[i]);    //inserting each element in BST

    diameter=find_diameter(&root)-1;
    printf("\nDiameter is the number of edges on the longest path between two leaves in the tree.");
    printf("\nDiameter=%d\n",diameter);
	return 0;
}
//Time complexity of find_diameter function is O(n^2),time complexity of insertbinary function is
//O(h) and time complexity of searchkey function
//is O(h).So overall time complexity is O(n^2)+O(h)+O(h) which is equal to O(n^2)
// where h is the height of the root node and n is the number off elements in
//binary search tree.As in each recursion step of the find_diameter function we are scanning
// the elements of tree n times so in total times n^2 times.So overall
//Time complexity is O(n^2).


