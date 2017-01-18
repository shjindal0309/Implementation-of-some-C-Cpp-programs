#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
int traversal(struct node** root,int key)  //level order traversal
{
    int x=0,y=0;
    if((*root)!=NULL)
    {
    if((*root)->data==key)
    {
        return 1;
    }
    if((*root)->data!=key)
    {
        x=traversal(&(*root)->left,key);
        y=traversal(&(*root)->right,key);
        if(x==1||y==1)
            return 1;
        else
            return 0;
    }
    }
    else if(*root==NULL)
        return 0;
}
struct node* insertbinary(struct node** temp1,int key)
{
    if(*temp1==NULL)
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(key <= (*temp1)->data)
        (*temp1)->left=insertbinary(&(*temp1)->left,key);
    else
        (*temp1)->right=insertbinary(&(*temp1)->right,key);
    return *temp1;
}
int main()
{
    struct node* root=NULL;
    int c,key;

    int i,j,a[11]={6,4,10,2,5,7,11,1,3,9,8};
    for(i=0;i<11;i++)
    root=insertbinary(&root,a[i]);
    printf("Enter key: ");
    scanf("%d",&key);
    c=traversal(&root,key);
    if(c)printf("yes");
    else printf("no");

	return 0;
}


