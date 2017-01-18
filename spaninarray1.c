//Assignment 2 , Q.4 a) O(n^2) algorithm
//Shubham Jindal 
//Roll No:150101071
#include <stdio.h>	//including standard input/output library
void findspan(int *x,int *s,int n)  //findspan to function to find span s[i] of each x[i]
{
	int c,i,j;		//declaring variables to store array indices and 
					//c is used to store value of span for each x[i]

	for(i=0;i<n;i++)    //outer for loop
	{ 
		s[i]=1;			//making s[i]=1 as x[i] will always be equal to itself

		for(j=i-1;j>=0 && x[j]<=x[i];j--) // inner for loop with condition for breaking from the loop
		{								  // comparing x[j] with x[i] to find value of s[i]
			s[i]++;				    	  // incrementing s[i] if match found
		}		
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
