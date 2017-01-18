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
struct stack
{
	int data;
	struct stack* next;
};
struct stack* head=NULL;
void push(int d)
{
	struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=d;
	temp->next=NULL;
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
int pop()
{
	struct stack* temp=head;
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		head=head->next;
		free(temp);
	}
}
int front()
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		return head->data;
	}
}
int empty()
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct adjlistnode* newadjlistnode(int dest)
{
    struct adjlistnode* newnode =
            (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}
void insertedge(struct graph* g, int src, int dest)
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
struct graph* makegraph(int V)
{
    int i;
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->v=V;
    g->array=(struct adjlist*)malloc((V+1)*sizeof(struct adjlist));
    for(i=0;i<V+1;i++)
    {
        g->array[i].head=NULL;
    }
    return g;
}
void showgraph(struct graph* graph)
{
    int V,count=0;
    for (V = 1; V <= graph->v; ++V)
    {
        struct adjlistnode* next = graph->array[V].head;
        printf("\nDirected edges from vertex %d are:\n", V);
        while (next)
        {
        	count++;
            printf(" %d ", next->dest);
            next = next->next;
        }
        if(count==0)
        {
        	printf("No directed edge from vertex %d",V);
       	}
        printf("\n");
    }
}
int visit_dfs(int s,struct graph* graph,int *visited,int *st,int *ft,int *time)
{
    struct adjlistnode* temp=graph->array[s].head;
    (*time)++;
    st[s]=*time;
    visited[s]=1;
    while(temp!=NULL)
    {
        if(visited[temp->dest]==0)
        {
            visit_dfs(temp->dest,graph,visited,st,ft,time);
        }
        temp=temp->next;
    }
    visited[s]=2;
    *time=*time+1;
    ft[s]=*time;
    push(s);
}
int dfs(struct graph* graph,int v,int *visited,int *st,int *ft,int *time)
{
    int i;
    for(i=0;i<v+1;i++)
    {
        visited[i]=0;
        st[i]=0;
        ft[i]=0;
    }
    for(i=1;i<v+1;i++)
    {
        if(visited[i]==0)
        visit_dfs(i,graph,visited,st,ft,time);
    }
}
int print_empty_stack()
{
	printf("Topological sorted order is: ");
	while(!empty())
	{
		printf("%d ",front());
		pop();
	}
	printf("\n");
}
int main()
{
    int V,E;
    printf("Enter number of nodes: ");
    scanf("%d",&V);
    getchar();
    printf("Enter number of edges: ");
    scanf("%d",&E);
    struct graph* graph = makegraph(V);
    printf("Enter directed edges from v1 to v2 using positive integers:\n");
    int v1,v2,i;

    for(i=1;i<=E;i++)
    {
    	printf("Enter edge %d is: ",i);
    	scanf("%d %d",&v1,&v2);

    	while((v1>V || v2>V) || (v1 <=0 || v2 <=0))
    	{
            printf("    Enter vertex number in the range [1,%d]\n",V);
            printf("    Again enter edge %d : ",i);
            getchar();
            scanf("%d %d",&v1,&v2);
    	}
    	insertedge(graph, v1, v2);
    }
    showgraph(graph);

    int visited[V+1];
    int st[V+1];
    int ft[V+1];
    int time=0;
    dfs(graph,V,visited,st,ft,&time);
    
    print_empty_stack();
    return 0;
}
