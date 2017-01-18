//Assignment 2 , Q.4 b) O(n) algorithm
//Shubham Jindal
//Roll No:150101071
#include <stdio.h>	//including standard input/output library
#include <malloc.h> //including malloc library to use malloc function
// a linear time solution for stock span problem

struct stack{
	int data;
	struct stack* next;
};
struct stack* head;
int Isempty()		//This function checks if the stack is empty
{
	if(head==NULL)
		return 1;
	else
		return 0;
}
void push(int data)	 //This function pushed element on stack
{
	struct stack* temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->next=NULL;
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void pop()	//This function pop element from stack
{
	head=head->next;
}
int top()	//This element returns top elemetn of the stack
{
	return head->data;
}
//This function finds span for each s[i]
void findspan(int x[], int s[],int n)
{   int i;
   // Create a stack and push index of first element to it
    push(0);

    // Span value of first element is always 1
   s[0] = 1;

   // Calculate span values for rest of the elements
   for (i = 1; i < n; i++)
   {
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]
      while (!Isempty() && x[top()] <= x[i])
         	pop();

      // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
      s[i] = (Isempty())? (i + 1) : (i - top());

      // Push this element to stack
      push(i);
   }
}

void createarray(int *a,int n)	// function to take array as input from user
{
	int i;
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void printarrayX(int *a,int n)	//Function to print array X
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-6d ",a[i]);
	}
	printf("\n");
}
void printspanS(int *s,int n) // Function to print array S
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-6d ",s[i]);
	}
	printf("\n");
}
/*Driver function which runs all other function*/
int main()
{
	int n; 						//n=number of elements in an array
	printf("Enter number of the array X: ");
	scanf("%d",&n);  			// enter number of elements in an array
	int X[n],S[n];				//Declaring the two arrays
	createarray(X,n); 			// creating array X
	printarrayX(X,n);			//printing array X
	findspan(X,S,n);			// finding span
	printspanS(S,n);			//printing the span S[i] for each X[i]
	return 0;
}
