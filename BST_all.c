#include <stdio.h>
#include <time.h>
typedef struct node node;
struct node
{
	int data;
	node* parent;
	node* right;
	node* left;
};
node* insert1(node* root,int k)
{
	if(root==NULL)
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->data=k;
		temp->right=0;
		temp->left=0;
		temp->parent=root;
		return temp;
	}
	else if(root->data >= k){root->left=insert1(root->left,k); root->left->parent=root;}
	else {root->right=insert1(root->right,k);root->right->parent=root;}

	return root;
}
node* insert(node* root,int k)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k;
	temp->right=0;
	temp->left=0;
	temp->parent=0;
	if(root==NULL){
		root=temp;
		return root;
	}
	if(root!=NULL)
	{
		node* temp1=root;
		node* prev=temp1;
		while(temp1!=0)
		{
			prev=temp1;
			if(k <= temp1->data)temp1=temp1->left;
			else temp1=temp1->right;
		}
		if(k<=prev->data){
			prev->left=temp;
			temp->parent=prev;
		}
		else{
			prev->right=temp;
			temp->parent=prev;
		}
	}
	return root;
}
void inorder(node* root)
{
	if(root!=0)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
node* search(node* root,int k)
{
	if(root==0 || root->data == k)return root;
	if(k > root->data )return search(root->right,k);
	else if(k <= root->data)return search(root->left,k);
}

node* min(node* root)
{
	if(root->left==0)return root;
	return min(root->left);
}
node* max(node* root)
{
	if(root->right==0)return root;
	return max(root->right);
}
node* find_succes(node* root,int k)
{
	node* current=search(root,k);
	if(current!=0)
	{
		node* s;
		node* a=root;
		if(current->right!=0)return min(current->right);

		while(current!=a)
		{
			if(current->data <= a->data)
			{
				s=a;
				a=a->left;
			}
			else a=a->right;
		}
		return s;
	}
	return 0;
}
node* find_pred(node* root,int k)
{
	node* current=search(root,k);
	if(current!=0)
	{
		node* s;
		node* a=root;
		if(current->left!=0)return max(current->right);

		while(current!=a)
		{
			if(current->data > a->data)
			{
				s=a;
				a=a->right;
			}
			else a=a->left;
		}
		return s;
	}
	return 0;
}
int delete(node* root,int k)
{
	node* found=search(root,k);
	if(found==0){printf("key not found\n");return 0;}

	if(found!=0)
	{
		if(found->left!=0 && found->right!=0)
		{
			node* temp=find_succes(root,found->data);
			temp->parent->left=temp->right;
			found->data=temp->data;
			found=temp;
		}
		else if(found->left!=0 || found->right==0)
		{
			if(found->parent->left==found)found->parent->left=found->left;
			else if(found->parent->right==found)found->parent->right=found->left;
		}
		else if(found->left==0 || found->right!=0)
		{
			if(found->parent->left==found)found->parent->left=found->right;
			else if(found->parent->right==found)found->parent->right=found->right;
		}
		printf("deleted: %d\n",found->data);
		//case of leaf node included implicitly
		free(found);
	}
}
int main()
{
	node* root=0;
	int i=0;

	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);

	node* temp=root->left->right->right;
	printf("@=%d",temp->data);

	printf("min node is%d\n",min(root)->data);
	printf("root is %d\n",root->data);

	printf("inoder traversal is: ");
	inorder(root);printf("\n");

	/*for(i=0;i<5;i++)
	delete(root,rand()%100);

	printf("inoder traversal is: ");
	inorder(root);printf("\n");*/


	node* temp1=find_succes(root,temp->data);
	if(temp1==0)printf("sucess not found\n");
	else printf("succes is: %d\n",temp1->data);

	temp1=find_pred(root,temp->data);
	if(temp1==0)printf("pred not found\n");
	else printf("pred is: %d\n",temp1->data);

	printf("\n");

	printf("inoder traversal is: ");
	inorder(root);printf("\n");

}
