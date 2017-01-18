//Assignment 9
//Shubham Jindal
//Roll No: 150101071
//The code is immensely clear
//I have included as many commments as possible
//for your good reading

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Data structure used in the program
typedef struct fibonacci_heap
{
	int key;
	int degree;
	int mark;
	struct fibonacci_heap* parent;
	struct fibonacci_heap* left;
	struct fibonacci_heap* right;
	struct fibonacci_heap* leftmostchild;
}fnode;

struct headptr
{
	fnode* ptr;
	fnode* min;
	int number;
};

//This function will make heap in O(1)
fnode* make_fibonacci_heap()
{
	fnode* temp=NULL;
	return temp;
}

//This function will concatenate the 2 fibonacci heaps
void fibonacci_heap_concatenate(struct headptr* head1,struct headptr* head2)
{
	fnode* min1=head1->min;
	fnode* min2=head2->min;
	fnode* temp1=min1->right;
	fnode* temp2=min2->left;
	min1->right=min2;
	min2->left=min1;
	temp1->left=temp2;
	temp2->right=temp1;
}
//The union function to join the two fibonacci heaps
//so that the resultant structure is a fibonacci heap
struct headptr* fibonacci_heap_union(struct headptr* head1,struct headptr* head2)
{
	//make fibonacci heap
	struct headptr* head;
	head = (struct headptr*)malloc(sizeof(struct headptr));

	//concatenate the 2 fibonacci heaps

	fibonacci_heap_concatenate(head1,head2);

	head->ptr=head1->ptr;

	if(head2->min->key < head1->min->key)
	{
		head->min=head2->min;
	}
	else
	{
		head->min=head1->min;
	}
	head->number = head1->number + head2->number;

	return head;
}

//This function is inserting the element in the fibonacci heap
struct headptr* fibonacci_heap_insert(struct headptr* head,int key)
{
	struct headptr* head1;
	head1 = (struct headptr*)malloc(sizeof(struct headptr));

	head1->ptr=head1->min=make_fibonacci_heap();

	fnode* temp = (fnode*)malloc(sizeof(fnode));
	head1->ptr=temp;
	head1->min=temp;
	head1->number=1;
	temp->key = key;
	temp->degree = 0;
	temp->parent = NULL;
	temp->leftmostchild = NULL;
	temp->left = temp;
	temp->right = temp;
	temp->mark=0;

	if(head->ptr==NULL)
	{
		return head1;
	}
	else
	{
		head = fibonacci_heap_union(head,head1);
		return head;
	}

}

//This function will make one node the parent of the other
void fibonacci_heap_link(struct headptr** head,fnode* y,fnode* x)
{
	fnode* temp=y->left;
	temp->right=x;
	x->left=temp;

	y->parent=x;
	y->right=x->leftmostchild;
	fnode* temp1=x->leftmostchild->left;
	x->leftmostchild->left=y;
	temp1->right=y;
	x->leftmostchild=y;
	x->degree++;
	y->mark=0;
}

//
void consolidate(struct headptr** head)
{
	int i,max=INT_MIN;
	fnode* temp=(*head)->ptr;
	while(temp->right != (*head)->ptr)
	{
		if(temp->degree > max)
		{
			max=temp->degree;
		}
		temp=temp->right;	
	}
	fnode* a[max];
	for(i=0;i<max;i++)
	{
		a[i]=NULL;
	}
	temp=(*head)->min;
	fnode* x;
	fnode* y;
	fnode* w;
	int d;
	//-------upto here correct
	while(temp->right != (*head)->min)
	{
		x=temp;
		d=temp->degree;
		while(a[d]!=NULL)
		{
			y=a[d];
			if(x->key > y->key)
			{
				int temp=x->key;
				x->key=y->key;
				y->key=temp;
			}
			fibonacci_heap_link(head,y,x);
			a[d]=NULL;
			d++;
		}
		a[d]=x;
	}
	//---printf("10");
	(*head)->min=NULL;
	for(i=0;i<max;i++)
	{
		if(a[i]!=NULL)
		{
			if((*head)->min==NULL || a[i]->key < (*head)->min->key)
			{
				(*head)->min=a[i];
			}
		}
	}
}

//extractmin function to extract the minimum element from the fibonacci heap
//and then union of the resulting two fibonacci heaps
int fibonacci_heap_extractmin(struct headptr** head)
{
	int min=(*head)->min->key;
	fnode* m=(*head)->min;
	fnode* lmc=m->leftmostchild;
	fnode* l=m->left;
	fnode* r=m->right;

	fnode* last=(*head)->ptr;
	while(last->right!=(*head)->ptr)
	{
		last=last->right;
	}

	fnode* temp=lmc;
	if(temp!=0)
	{
		while(temp->right!=lmc)
		{
			temp->parent=NULL;
			temp=temp->right;
		}
		temp->parent=NULL;
	}

	if(lmc!=0 && m->left!=last)
	{
		l->right=lmc;
		lmc->left=l;
		temp->right=r;
		r->left=temp;
	}
	else if(lmc!=0 && m->left==last)
	{
		last->right=lmc;
		lmc->left=last;
		temp->right=r;
		r->left=temp;
		(*head)->ptr=lmc;
	}
	else if(lmc==0 && m->left==last)
	{
		last->right=r;
		r->left=last;
		(*head)->ptr=r;
	}
	else if(lmc==0 && m->left!=last)
	{
		l->right=r;
		r->left=l;
	}

	if(m==m->right)
	{
		(*head)->min=NULL;
	}
	else
	{
		(*head)->min=m->right;
	}

	m->leftmostchild=m->right=m->left=NULL;

	consolidate(head);
	(*head)->number--;
	return min;
}

//This function together with showfibonacciheap() function will print the
//fibonacci heap in 90 degree counter clockwise rotated form
//This function is given in the assignment
void showheap(fnode* x,int depth)
{
	int i;
	fnode* temp=x;
	if(x->right!=NULL)
	{
		showheap(x->right,depth);
		if(x->right!=NULL && depth==0)
		{
			printf("\n");
		}
	}
	if(x->leftmostchild!=NULL || x->parent==NULL)
	{
		for(i=1;i<=6*depth-1;i++)
		{
			printf(" ");
		}
		for(i=1;i<=4;i++)
		{
			printf(" ");
		}
		printf("%d",x->key);
		if(x->leftmostchild==NULL)
		{
			printf("\n");
		}
	}
	else
	{
		printf("    %d\n",x->key);
	}
	if(x->leftmostchild!=NULL)
	{
		showheap(x->leftmostchild,depth+1);
	}
}

//This function together with showfibonacciheap() function will print the
//fibonacci heap in 90 degree counter clockwise rotated form
//This function is given in the assignment
int showfibonacciheap(struct headptr* head)
{
	if(head->ptr==NULL)
	{
		printf("Heap is Empty\n");
		return 0;
	}
	else
	{
		fnode* temp=head->ptr;
		while(temp->right!=head->ptr)
		{
			printf(" %d ",temp->key);
			temp=temp->right;
		}
		printf("%d",temp->key);
		//showheap(head->ptr,0);
	}

}

int main()
{
	int key,choice,mark=1;
	struct headptr* head;
	char c,flag='+';

	FILE *fp;

		printf("Enter which file u want to use\n1) test1.txt\n2) test2.txt\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			fp=fopen("test1.txt.txt","r");
		}
		else if(choice==2)
		{
			fp=fopen("test2.txt.txt","r");
		}

	if(fp==NULL)
	{
		printf("File does not open\n");
		return 0;
	}
	while(1)
	{
		if(feof(fp)) 	//Exit condition
		{
			break;
		}

		//This while loop considers all the cases it avoids
		//lines starting with #
		while(1)
		{
			fscanf(fp,"%c",&c);
			if(feof(fp))
			{
				return 0;
			}
			if(c=='#')
			{
				mark=0;
			}
			if(mark==0 && c=='\n')
			{
				mark=1;
			}
			if(c=='-')
			{
				flag='-';
			}
			if(c=='+')
			{
				flag='+';
			}
			if(c=='c'||c=='i'||c=='e'||c=='S')
			{
				if(mark==1)
				{
					break;
				}
			}
		}
		if(c=='c')
		{
			head = (struct headptr*)malloc(sizeof(struct headptr));
			head->min = head->ptr = make_fibonacci_heap();
			head->number=0;
		}
		else if(c=='i')
		{
			fscanf(fp,"%d",&key);
			head=fibonacci_heap_insert(head,key);
			showfibonacciheap(head);
			printf("min=%d\n",head->min->key);
		}
		else if(c=='e')
		{
			if(flag=='+')
			{
				if(head->ptr==NULL)
				{
					printf("Heap is Empty\n\n");
				}
				else
				{
					int min=fibonacci_heap_extractmin(&head);
					printf("Minimum extracted with flag on: %d\n",min);
				}
			}
			else if(flag=='-')
			{
				if(head->ptr==NULL)
				{
					printf("Heap is Empty\n");
				}
				fibonacci_heap_extractmin(&head);
			}
		}
		else if(c=='S')
		{
			printf("\nfibonacci heap is:\n\n");
			showfibonacciheap(head);
			printf("\n");
		}

	}
	return 0;
}
