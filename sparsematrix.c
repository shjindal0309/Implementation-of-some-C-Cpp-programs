//Assignment 4 Q.3 part i) and ii)
//Shubham Jindal 
//Roll No.150101071

//Necessary header files required in the program
#include <stdio.h>
#include <stdlib.h>

/*  All Nodes are of the type as given below;
    --------------------
   | data | data | data |
    --------------------
   | pointer  | pointer |
    --------------------
*/

//For row index linked list and column index
//linked list data fields are not used 
//I did it this way as Sir allowed us to do this way

//Defining struct node for sparse matrix
struct node
{
	int x;
	int y;
	int data;
	struct node* right;
	struct node* down;
};

//This function will create linked list which will contain row index
//hpr stands for head pointer
void rowindex(struct node** hpr,int row)
{
	int i;
	for(i=0;i<row;i++)
	{	
		//Creating node for row linked list
		struct node* temp=(struct node*)malloc(sizeof(struct node));

		//setting a pointer to head pointer hpr of linked list
		//hpr stands for head pointer

		//temp1 is used to traverse linked list of rowindex
		struct node* temp1=(*hpr);

		//if head pointer is NULL
		if((*hpr)==NULL)
		{
			(*hpr)=temp;
			temp->down=(*hpr);
			temp->right=temp;
		}

		//if head pointer is not NULL
		else
		{
			while(temp1->down!=(*hpr))
			{
				temp1=temp1->down;
			}

			//setting the links properly
			temp1->down=temp;
			temp->down=(*hpr);
			temp->right=temp;
		}
	}
}

//This function will create linked list which will contain column index
//hpc stands for head pointer of column linked list
void colindex(struct node** hpc,int col)
{
	int i;
	for(i=0;i<col;i++)
	{
		//Creating node for column linked list
		struct node* temp=(struct node*)malloc(sizeof(struct node));

		//setting a pointer to head pointer hpc of linked list
		//hpc stands for head pointer of column linked list

		//temp1 is used to traverse linked list of columnindex
		struct node* temp1=(*hpc);
		

		//if head pointer is NULL
		if((*hpc)==NULL)
		{
			(*hpc)=temp;
			temp->right=(*hpc);
			temp->down=temp;
		}

		//if head pointer is not NULL
		else
		{
			while(temp1->right!=(*hpc))
			{
				temp1=temp1->right;
			}

			//setting the links properly
			temp1->right=temp;
			temp->right=(*hpc);
			temp->down=temp;
		}
	}
}

//This function will insert the non zero elements in the matrix
//hpc stands for head pointer of column linked list
//hpr stands for head pointer of row linked list
//d is data to be inserted
//r_i_r stands for randomly generated row index
//r_i_c stands for randomly generated column index
void insert(struct node** hpr,struct node** hpc,int d,int r_i_r,int r_i_c,int row,int col)
{
	int i;

	//Creating a node for storing data in the matrix
	struct node* temp=(struct node*)malloc(sizeof(struct node));

	//Assigning proper values of row index,column index and data
	temp->x=r_i_r;   //x represents row index
	temp->y=r_i_c;   //y represents column index
	temp->data=d;

	//thpc for temporary head pointer for column linked list
	//thpr for temporary head pointer for row linked list
	struct node* thpr=(*hpr);
	struct node* thpc=(*hpc);

	//Traversing row linked list to find proper row index
	for(i=0;i<r_i_r;i++)
	{
		thpr=thpr->down;
	}

	//Traversing column linked list to find proper column index
	for(i=0;i<r_i_c;i++)
	{
		thpc=thpc->right;
	}

	//These steps assign proper links to and from the
	//element node of sparse matrix
	struct node* t1=thpr->right;
	struct node* prev1=thpr;
	if(thpr->right==thpr)
	{
		//These steps occur when there is no element in this row
		thpr->right=temp;
		temp->right=thpr;
	}
	else
	{
		while(t1->y < r_i_c && t1->right!=thpr)
		{
			prev1=t1;
			t1=t1->right;
		}
		if(t1->y > r_i_c)
		{
			prev1->right=temp;
			temp->right=t1;
		}
		else if(t1->right==thpr)
		{
			t1->right=temp;
			temp->right=thpr;
		}
	}

	//These steps assign remaining links to and from the 
	//element node of sparse matrix
	struct node* t2=thpc->down;
	struct node* prev2=thpc;
	if(thpc->down==thpc)
	{
		//These steps occur when there is no element in this column
		thpc->down=temp;
		temp->down=thpc;
	}
	else
	{
		while(t2->x < r_i_r && t2->down!=thpc)
		{
			prev2=t2;
			t2=t2->down;
		}
		if(t2->x > r_i_r)
		{
			prev2->down=temp;
			temp->down=t2;
		}
		else if(t2->down==thpc)
		{
			t2->down=temp;
			temp->down=thpc;
		}
	}

}

//This function finds the maximum element in the sparse matrix
//This function traverse the sparse matrix column wise and 
//storing the maximum value obtained in the traversal in max variable
//hpr stands for head pointer for row linked list
//hpc stands for head pointer for column linked list
int maximum(struct node** hpr,struct node** hpc,int row,int col)
{	
	//Setting the minimum possible value of max
	//based on the range of elements of the sparse matrix
	//as set in main function using % operator
	int max=-32000; 

	//Declaring to node pointer to be used later
	struct node* b=(*hpc);
	struct node* t=b;

	//These nested while loops will work for upto second last column
	while(b->right!=(*hpc))
	{	

		int count=0;
		t=b;
		while(t->down!=b)
		{
			count++;

			//going down in the column and finding max
			t=t->down; 

			if(t->data > max)
			{
				max = t->data;
			}
		}

		//Condition used for the corner case for last element in the column
		if(t->data > max && count>0)
			{
				max = t->data;
			}
		b=b->right;
	
	}

	//This while is for the last column
	t=b->down;
	while(t->down!=b)
	{
		//going down in the column and finding max
		t=t->down;

		if(t->data > max)
		{
			max = t->data;
		}
	}

	//Finally returning the max value obtained
	return max;
}

//This function runs all other functions plus
//takes necessary actions
int main()
{
	//seeding so to get different numbers evrytime
	srand(time(NULL)); 

	int row,col,num;

	printf("Enter number of rows and col in sequence: ");
	scanf("%d %d",&row,&col);

	//to clean input buffer which contains '\n' character
	getchar();

	struct node* hpr=0;
	struct node* hpc=0;

	char e;
	do
    {
        e='d';
        printf("Enter number of non zero elements: ");
        scanf("%d",&num);
        if(num > row*col || num < 0 )
        {
            printf("Please enter valid number");
            e='n';
        }
    }while(e=='n');

    //a[] is array of non zero numbers generated randomly
    int a[num];
    int k,i;
    
    //Generating  random non zero numbers  
	for(k=0;k<num;k++)
	{
		a[k]=rand()%30000;
		if(a[k]==0)
		{
			continue;
		}

	}

	//creating row linked list
	rowindex(&hpr,row);
	//creating column linked list
	colindex(&hpc,col);

	//b[] array stores row index
	//c[] array stores column index
	int b[num],c[num];
	int j=0,flag=0;

	for(i=0;i<num;i++)
	{
		//abs function is used to generate positive indices
		//b[] array stores row index
		//c[] array stores column index
		b[i]=abs(rand()%(row));
		c[i]=abs(rand()%(col));
		
		//This for loop checks whether this pair of indices
		//has already come or not
		for(j=0;j<i;j++)
		{	
			flag=0;
			if(b[j]==b[i] && c[j]==c[i])
			{
				flag=1;
				break;
			}
		}

		//if the pair of indices not repaeated
		if(flag==0)
			insert(&hpr,&hpc,a[i],b[i],c[i],row,col);

		//if the pair of indices are repeated
		else
		{
			i--;
			//This is used to counteract the increment by i++
			//we are using i-- as coordinates generated are same as earlier

			continue;
		}
	}

	int max=maximum(&hpr,&hpc,row,col);
	printf("Maximum value is %d ",max);
	return 0;
}
