//Assignment 8
//Shubham Jindal
//Roll No: 150101071
//The code is immensely clear
//I have included as many commments as possible
//for your good reading

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Data structure used in the program
typedef struct binomial_heap
{
	int key;
	int degree;
	struct binomial_heap* parent;
	struct binomial_heap* sibling;
	struct binomial_heap* leftmostchild;
}bnode;

//This function will make heap in O(1)
bnode* make_binomial_heap()
{
	bnode* temp=NULL;
	return temp;
}

//This function is used to reverse linked list
int reverse_linkedlist(bnode** head,bnode* temp)
{
    if(temp!=0)
    {
        if(temp->sibling==NULL)
        {
            *head=temp;
            return 0;
        }
        else
        {
            reverse_linkedlist(head,temp->sibling);
            temp->sibling->sibling=temp;
            temp->sibling=NULL;
        }
    }
}

//This function is used to merge two binomial heaps
//This is exactly the same as we used in merge sort algorithm
bnode* binomial_heap_merge(bnode* head1,bnode* head2)
{
	bnode* temp1=head1;
	bnode* temp2=head2;
	bnode* head=NULL;
	bnode* temp=NULL;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->degree <= temp2->degree)
		{
			if(temp==NULL)
			{
				temp=temp1;
				head=temp;
			}
			else
			{
				temp->sibling=temp1;
				temp=temp->sibling;
			}
			temp1=temp1->sibling;
		}
		else
		{
			if(temp==NULL)
			{
				temp=temp2;
				head=temp;
			}
			else
			{
				temp->sibling=temp2;
				temp=temp->sibling;
			}
			temp2=temp2->sibling;
		}
	}

	if(temp==NULL && temp2!=NULL)
	{
		temp=temp2;
		head=temp;
		temp2=temp2->sibling;
		while(temp2!=NULL)
        {
            temp->sibling=temp2;
            temp=temp->sibling;
            temp2=temp2->sibling;
        }
        return head;
	}
	else if(temp==NULL && temp1!=NULL)
	{
		temp=temp1;
		head=temp;
		temp1=temp1->sibling;
		while(temp1!=NULL)
        {
            temp->sibling=temp1;
            temp=temp->sibling;
            temp1=temp1->sibling;
        }
        return head;
	}
	else if(temp==NULL && temp1==NULL && temp2==NULL)
	{
		return 0;
	}

	while(temp1!=NULL)
	{
		temp->sibling=temp1;
		temp=temp->sibling;
		temp1=temp1->sibling;
	}
	while(temp2!=NULL)
	{
		temp->sibling=temp2;
		temp=temp->sibling;
		temp2=temp2->sibling;
	}
	return head;
}

//This function will make one node the parent of the other
void binomial_heap_link(bnode* temp1,bnode* temp2)
{
	temp1->parent=temp2;
	temp1->sibling=temp2->leftmostchild;
	temp2->leftmostchild=temp1;
	temp2->degree++;
}

//The union function to join the two binomial heaps
//so that the resultant structure is a binomial heap
bnode* binomial_heap_union(bnode* head,bnode* head1)
{
	//make binomial heap
	bnode* head2=make_binomial_heap();
	//merger the 2 binomial heaps
	head2=binomial_heap_merge(head,head1);

	//trivial condition
	if(head2==NULL)
	{
		return head2;
	}

	bnode* prev_x = NULL;
	bnode* x = head2;
	bnode* next_x = x->sibling;
	while(next_x!=NULL)
	{
		//case 1
		if(next_x->sibling!=NULL)
		{
			if(x->degree==next_x->sibling->degree)
			{
				prev_x=x;
				x=next_x;
				next_x=x->sibling;
				continue;
			}
		}

		//case 2
		if(x->degree!=next_x->degree)
		{
			prev_x=x;
			x=next_x;
			next_x=x->sibling;
			continue;
		}

		//case 3
		if(x->degree==next_x->degree && x->key < next_x->key)
		{
			x->sibling=next_x->sibling;
			binomial_heap_link(next_x,x);
		}

		//case 4
		else if(x->degree==next_x->degree && x->key > next_x->key)
		{
			if(prev_x==NULL)
			{
				head2=next_x;
			}
			else
			{
				prev_x->sibling=next_x;
			}
			binomial_heap_link(x,next_x);
			x=next_x;
		}

		//adjusting the next_x pointer
		if(x!=NULL)
		{
			next_x=x->sibling;
		}
		else
		{
			next_x=x;
		}
	}
	//return the pointer to the newly formed binomial heap
	return head2;
}

//This function is inserting the element in the binomial heap
bnode* binomial_heap_insert(bnode* head,int key)
{
	bnode* head1 = make_binomial_heap();
	bnode* temp = (bnode*)malloc(sizeof(bnode));
	head1=temp;
	temp->key = key;
	temp->degree = 0;
	temp->parent = NULL;
	temp->leftmostchild = NULL;
	temp->sibling = NULL;
	head = binomial_heap_union(head,head1);
	return head;
}

//extractmin function to extract the minimum element from the binomial heap
//and then union of the resulting two binomial heaps
int binomial_heap_extractmin(bnode** head)
{
	int min=INT_MAX;
	bnode* ptr=NULL;
	bnode* prev_x=NULL;
	bnode* temp=*head;
	while(temp!=NULL)
	{
		if(temp->key < min)
		{
			min=temp->key;
			ptr=temp;
		}

		temp=temp->sibling;
	}
	temp=*head;

	if(temp->sibling!=NULL)
	{
		if(temp!=ptr)
		{
			while(temp->sibling!=ptr)
		    {
		        temp=temp->sibling;
		    }
		    prev_x=temp;
			prev_x->sibling=ptr->sibling;
		    ptr->sibling=NULL;
		}
		else
		{
			*head=ptr->sibling;
			ptr->sibling=NULL;
		}
			bnode* head1=make_binomial_heap();

			reverse_linkedlist(&(ptr->leftmostchild),ptr->leftmostchild);
			head1=ptr->leftmostchild;
			while(head1!=0)
			{
				head1->parent=NULL;
				head1=head1->sibling;
			}
			head1=ptr->leftmostchild;
			*head=binomial_heap_union(*head,head1);

			return min;
	}
	else
	{
		if(temp->degree!=0)
		{
			bnode* head1=make_binomial_heap();
			reverse_linkedlist(&(ptr->leftmostchild),ptr->leftmostchild);
			head1=ptr->leftmostchild;
			while(head1!=0)
			{
				head1->parent=NULL;
				head1=head1->sibling;
			}
			*head=head1=ptr->leftmostchild;
			return min;
		}
		else
		{
			*head=NULL;
			return min;
		}
	}
}

//This function together with showbinomialheap() function will print the
//binomial heap in 90 degree counter clockwise rotated form
//This function is given in the assignment
void showheap(bnode* x,int depth)
{
	int i;
	if(x->sibling!=NULL)
	{
		showheap(x->sibling,depth);
		if(x->sibling!=NULL && depth==0)
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

//This function together with showbinomialheap() function will print the
//binomial heap in 90 degree counter clockwise rotated form
//This function is given in the assignment
int showbinomialheap(bnode* head)
{
	if(head==NULL)
	{
		printf("Heap is Empty\n");
		return 0;
	}
	else
	{
		showheap(head,0);
	}

}

int main()
{
	char command,flag='+';
	int key,choice,ASCII;
	bnode* head;

	//These printf() clearly indicates what i want to do
	printf("Enter how you want to take input:\n");
	printf("1. From user\n2. From File\n");
	scanf("%d",&choice);

	//some required printf() to get good looking output
	if(choice==1)
	{
		printf("First command has to be c\n\n");
	}

	//some required printf() to get good looking output
	if(choice==2)
	{
		printf("By default flag is on\n");
	}

	if(choice==1)
		do
		{
			//This printf() clearly indicates what i want to do
			//Enter from these choices only otherwise it can cause problem
			printf("Enter given below commands only:\n");
			printf("1. MAKE-BINOMIAL-HEAP----> c\n2. BINOMIAL-HEAP-INSERT----> i\n"\
				    "3. BINOMIAL-HEAP-EXTRACT-MIN----> d\n"\
					"4. Turn off Print after extract min----> + "\
					"   By defualt the flag is +\n"
					"5. Turn on Print after extract min----> -\n"\
					"6. showbinomialheap----> s\n7. exit---->e\n\nEnter your command: ");

			//This is used to clear standard input
			getchar();
			scanf("%c",&command);
			if(command=='e')
				exit(1);
			printf("\n");

			while(command!='c' && command!='i' && command!='d' && command!='+' && command!='-'&&
					command!='s' && command!='e')
			{
				getchar();
				printf("Enter correct command: ");
				scanf("%c",&command);
			}
			//Flag changing condition
			if(command=='-')
			{
				flag='-';
				printf("Flag changed to %c\n\n",flag);
				continue;
			}

			//Flag changing condition
			if(command=='+')
			{
				flag='+';
				printf("Flag changed to %c\n\n",flag);
				continue;
			}

			if(command=='d')
			{
				command=flag;
			}
			ASCII=command;
			switch(ASCII)
			{
				case 'c':
					head=make_binomial_heap();
					printf("Binomial heap is made.\n\n");
					break;

				case 'i':
					printf("Enter key: ");
					getchar();
					scanf("%d",&key);
					head=binomial_heap_insert(head,key);
					printf("%d is inserted\n\n",key);
					break;

				case '+':
					if(head==NULL)
					{
						printf("Heap is Empty\n\n");
						break;
					}
					int min=binomial_heap_extractmin(&head);
					printf("Minimum extracted with flag on: %d\n\n",min);
					break;

				case '-':
					if(head==NULL)
					{
						printf("Heap is Empty\n\n");
						break;
					}
	                min=binomial_heap_extractmin(&head);
	                printf("Binomial heap 'after' extract_min with flag off:\n\n");
					showbinomialheap(head);
					printf("\n");
					break;

				case 's':
					printf("Binomial heap is:\n");
					showbinomialheap(head);
					printf("\n");
			}
		}while(command!='e');

	else if(choice==2)
	{
		//This is used to clear standard input
		fflush(stdin);
		char c;
		int mark=1,key;

		FILE *fp;
		fp=fopen("assign_8_binomialHeapTest.txt","r");
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
			//lines starting with # and changes flags at required positions
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
				if(c=='c'||c=='i'||c=='d'||c=='S')
				{
					if(mark==1)
					{
						break;
					}
				}

			}
			if(c=='c')
			{
				head=make_binomial_heap();
			}
			else if(c=='i')
			{
				fscanf(fp,"%d",&key);
				head=binomial_heap_insert(head,key);
			}
			else if(c=='d')
			{
				if(flag=='+')
				{
					if(head==NULL)
					{
						printf("Heap is Empty\n\n");
					}
					else
					{
						int min=binomial_heap_extractmin(&head);
						printf("Minimum extracted with flag on: %d\n",min);
					}
				}
				else if(flag=='-')
				{
					if(head==NULL)
					{
						printf("Heap is Empty\n");
					}
					binomial_heap_extractmin(&head);
				}
			}
			else if(c=='S')
			{
				printf("\nbinomial heap is:\n\n");
				showbinomialheap(head);
				printf("\n");
			}
		}
	}

    return 0;
}
