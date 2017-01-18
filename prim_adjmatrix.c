//Assignment 6
//Name:Shubham Jindal
//Roll No:150101071


#include <stdio.h>
#include <limits.h>
#include <limits.h>

//This function will find the edge with minimum weight
//Adjacent to given node
int min_weight(int *key,int *color,int V)
{
	//color[i]=1 means color is Black
	//color[i]=0 means color is white

	int i,index,limit=INT_MAX;
	for(i=1;i<V+1;i++)
	{
		if(key[i]<limit && color[i]==0)
		{
			limit=key[i];
			index=i;
		}
	}
	return index;
}

//This function will find the MST
void prim_algo(int *key,int *color,int *parent,int V,int a[][V+1])
{

	//color[i]=1 means color is Black
	//color[i]=0 means color is white
	//Defining the roor as the first element of the array
	key[1]=0;
	parent[1]=-1;

	int i,j;

	for (i=1;i<V;i++)
    {
    	//In the adjacent of a node finding the element with 
    	//minimum edge weight
        int adj=min_weight(key,color,V);

        //make color of that edge 1
       	color[adj]=1;

        for (j=1;j<V+1;j++)
		{
			if (a[adj][j]!=0 && color[j] == 0 && a[adj][j] <  key[j])
            {
            	parent[j]=adj;
            	key[j]=a[adj][j];
            }
		}
    }
}

//This function will print the MST formed
void print_MST(int V,int a[][V+1],int *parent)
{
	int i;
	printf("Edges\tWeights\n");
	for(i=2;i<V+1;i++)
	{
		
		{
			printf("%d<--->%d\t  %d\n",parent[i],i,a[i][parent[i]]);
		}
	}
}

//This function will insert an edge in the graph
int insertedge(int V,int a[][V+1],int src,int dest,int w)
{
	a[src][dest]=w;
	a[dest][src]=w;
}

//This function will drive all other functions
int main()
{
	int V;
	printf("Enter number of vertices: ");
	scanf("%d",&V);
	getchar();    //This is used to clear input buffer

	int E;
	printf("Enter number of edges: ");
	scanf("%d",&E);
	getchar();    //This is used to clear input buffer

    int i;
	int j;
	int a[V+1][V+1];
	for(i=0;i<V+1;i++)
	{
		for(j=0;j<V+1;j++)
		{
			a[i][j]=0;
		}
	}

	int key[V+1];
	
	//color[i]=1 means color is Black
	//color[i]=0 means color is white
	int color[V+1];


	int parent[V+1];
	int w[V+1];
	int v1,v2;

	for(i=0;i<V+1;i++)
	{
		key[i]=INT_MAX;
		color[i]=0;
		parent[i]=-1;
		w[i]=0;
	}

	for(i=1;i<=E;i++)
    {
    	printf("Enter edge %d is: ",i);
    	scanf("%d %d",&v1,&v2);
    	getchar();   //This is used to clear input buffer

    	//If the vertex number is not in the range [1,V]
    	//Then this while will ask you to enter the vertex number 
    	//in that range 	
    	while((v1>V || v2>V) || (v1 <=0 || v2 <=0))
    	{
            printf("    Enter vertex number in the range [1,%d]\n",V);
            printf("    Again enter edge %d : ",i);

            scanf("%d %d",&v1,&v2);
            getchar();    //This is used to clear input buffer
    	}
    	printf("Enter this Edge's weight: ");

    	scanf("%d",&w[i]);
    	getchar();   //This is used to clear input buffer
    	insertedge(V,a,v1,v2,w[i]);
    }
    printf("\n");
    printf("\n");
    
    // Printing the adjacency matrix representation
    // of grpah
    for(i=1;i<V+1;i++)
    {
    	for(j=1;j<V+1;j++)
    	{
    		printf("%-3d   ",a[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");
    printf("\n");

    //This function will find the Minimum Spanning Tree
    prim_algo(key,color,parent,V,a);

    //This function will print the Minimum Spanning Tree formed
    print_MST(V,a,parent);

    return 0;
}
