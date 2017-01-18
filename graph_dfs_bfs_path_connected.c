#include <stdio.h>
#include <stdlib.h>

struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};
struct adjlist
{
	struct adjlistnode* head;
};
struct graph
{
	int v;
	struct adjlist* array;
};
struct graph* creategraph(int V)
{
    int i;
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->v=V;
	g->array=(struct adjlist*)malloc(MAX*sizeof(struct adjlist));
	for(i=0;i<MAX;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}
struct adjlistnode* newadjlistnode(int dest)
{
    struct adjlistnode* newnode =
            (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}
void addedge(struct graph* g, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    if(src!=dest)
    {
    	struct adjlistnode* newnode = newadjlistnode(dest);
    	struct adjlistnode* temp=g->array[src].head;
	    if(temp==0)
	    {
	    	g->array[src].head=newnode;
	    }
	    else
	    {
		    while(temp->next!=NULL)
	    	{
		    		temp=temp->next;
		    }
	    	temp->next=newnode;
	    }
    // Since graph is undirected, add an edge from dest to src also
	    /*newnode = newadjlistnode(src);
	    temp=g->array[dest].head;
	    if(temp==0)
	    {
	    	g->array[dest].head=newnode;
	    }
	    else
	    {
	    	while(temp->next!=NULL)
	    	{
	    		temp=temp->next;
	    	}
	    	temp->next=newnode;
	    }*/
	}
    else
    {
    	struct adjlistnode* newnode = newadjlistnode(dest);
    	struct adjlistnode* temp=g->array[src].head;
	    if(temp==0)
	    {
	    	g->array[src].head=newnode;
	    }
	    else
	    {
		    while(temp->next!=NULL)
	    	{
		    		temp=temp->next;
		    }
	    	temp->next=newnode;
	    }
    }
}
void printgraph(struct graph* g)
{
    int V;
    for (V = 1; V <= g->v; ++V)
    {
        struct adjlistnode* pcrawl = g->array[V].head;
        printf("\nAdjacent nodes of vertex %d are:\n", V);
        while (pcrawl)
        {
            printf(" %d->", pcrawl->dest);
            pcrawl = pcrawl->next;
        }
        printf("\n");
    }
}
struct queue
{
	int data;
	struct queue* next;
};
struct queue* front=NULL;
struct queue* back=NULL;
void push(int d)
{
	struct queue* temp=
			(struct queue*)malloc(sizeof(struct queue));
	temp->next=NULL;
	temp->data=d;
	if(front==NULL && back==NULL)
	{
		front=temp;
		back=temp;
	}
	else
	{
		temp->next=front;
		front=temp;
	}
}
int pop()
{
    int x;
	struct queue* temp=front;
	struct queue* prev=temp;
	if(temp->next!=NULL)
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
	x=temp->data;
	prev->next=NULL;
	}
	else
	{
		x=front->data;
		front=NULL;
		back=NULL;
	}
	return x;
}
int empty()
{
	if(front==NULL && back==NULL)
		return 1;
	else return 0;
}
int returnback()
{
	return back->data;
}
void BFS(int s,struct graph* g,int v)
{
	int color[v],par[v],i,count=0;
	for(i=0;i<v;i++)color[i]=0;
	push(s);
	while(!empty())
	{
		int x=pop();
		struct adjlistnode* temp = g->array[x].head;
		if(temp!=0)
		while(temp!=0)
		{
		     if(color[temp->dest]==0)
            {
            	count++;
                color[temp->dest]=1;
                printf("%d ",temp->dest);
                push(temp->dest);
            }
            temp=temp->next;
		}
		else
		{
			color[x]=2;
			continue;
		}
		printf("\n");
		color[x]=2;
	}
	if(count==0)
		printf("No adjacent nodes of %d exist",s);
}
void DFS_visit(int v,int time,int *color,int *d,struct graph* graph)
{

    color[v]=1;d[v]=++time;//printf("r=%d",color[1]);

    struct adjlistnode* temp=graph->array[v].head;
    while(temp!=0)
    {   //printf("---%d---",color[1]);
        //printf("color[%d]=%d",temp->dest,color[temp->dest]);

        if(color[temp->dest]==0)
        {
            color[temp->dest]=1;
            printf("%d ",temp->dest);
            DFS_visit(temp->dest,time,color,d,graph);
        }
        temp=temp->next;
    }
}
void DFS(struct graph* graph,int v)
{
    int color[MAX];
    int time=0;int i,j=1;
    int d[MAX];
    for(i=0;i<MAX;i++)
    {
    	color[i]=0;
    	d[i]=0;
    }

    for(i=1;i<=v;i++)
    {
        if(color[i]==0)
        {
            printf("Component %d: %d ",j,i);
            DFS_visit(i,time,color,d,graph);
            printf("\n");
            j++;
        }
    }
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct graph* graph = creategraph(V);
    addedge(graph, 2, 1);
    addedge(graph, 1, 4);
    addedge(graph, 4, 2);
    addedge(graph, 1, 3);

    addedge(graph, 2, 3);
    addedge(graph, 2, 2);


    // print the adjacency list representation of the above graph
    printgraph(graph);

    printf("BFS of 2 is:\n");
    BFS(2,graph,V);
    DFS(graph,V);
    
    return 0;
}
