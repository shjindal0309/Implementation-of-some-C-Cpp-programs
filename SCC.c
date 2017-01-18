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
int top()
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
            printf("%d ",temp->dest);
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
    int i,k=1;
    for(i=0;i<v+1;i++)
    {
        visited[i]=0;
        st[i]=0;
        ft[i]=0;
    }
    for(i=1;i<v+1;i++)
    {
        if(visited[i]==0)
        {
            printf("depth first forest of %d is: ",i);
            visit_dfs(i,graph,visited,st,ft,time);
            k++;
            printf("\n");
        }
    }
}
int visit_dfs1(int s,struct graph* graph,int *visited,int *st,int *ft,int *time,
		          int *m,int k,int v,int SCC[v+1])
{
    struct adjlistnode* temp=graph->array[s].head;
    (*time)++;
    st[s]=(*time);
    visited[s]=1;
    while(temp!=NULL)
    {
        if(visited[temp->dest]==0)
        {
        	SCC[*m]=k;
        	(*m)++;
            visit_dfs1(temp->dest,graph,visited,st,ft,time,m,k,v,SCC);
        }
        temp=temp->next;
    }
    visited[s]=2;
    *time=*time+1;
    ft[s]=*time;
}
int dfs1(struct graph* graph,int v,int *visited,int *st,int *ft,int *time,
            int SCC[v+1])
{
    int i,j,x;
    int k=0;
    int m=1;
    for(i=0;i<v+1;i++)
    {
        visited[i]=0;
        st[i]=0;
        ft[i]=0;
    }
    while(!empty())
    {
    	x=top();
    	pop();
        if(visited[x]==0)
        {
            visit_dfs1(x,graph,visited,st,ft,time,&m,k,v,SCC);
    	    k++;
        }
    }
    return k;
}
void transpose(struct graph* graph,int *a,int *b,int v,int E)
{
    int i;
    //struct graph* graph=makegraph(v);
    for(i=1;i<=E;i++)
    {
        insertedge(graph, b[i], a[i]);
    }
    //return graph;
}
void delete_this(struct graph* graph,struct adjlistnode* temp,struct adjlistnode* prev)
{
    if(temp->next==NULL)
    {
        prev->next=NULL;
        free(temp);
    }
    else if(temp->next!=NULL)
    {
        prev->next=temp->next;
        free(temp);
    }

}
int main()
{
    int V,E;
    printf("Enter number of nodes: ");
    scanf("%d",&V);
    getchar();
    printf("Enter number of edges: ");
    scanf("%d",&E);
    struct graph* graph1 = makegraph(V);
    struct graph* graph2 = makegraph(V);
    printf("Enter directed edges from v1 to v2 using positive integers:\n");
    int v1,v2,i;

    int a[E+1],b[E+1];
    for(i=0;i<V+1;i++)
    {
        a[i]=-1;
        b[i]=-1;
    }

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
        //printf("v1=%d ",v1);
        a[i]=v1;
        b[i]=v2;

    	insertedge(graph1, v1, v2);
        //insertedge(graph2, v2, v1);
    }

    for(i=1;i<=E;i++)
    {
        printf("a[%d]=%d b[%d]=%d\n",i,a[i],i,b[i]);
    }

    transpose(graph2,a,b,V,E);

    //printf("for graph G");
    //showgraph(graph1);

    printf("\n");

    printf("for transpose graph");
    showgraph(graph2);

    int visited[V+1];
    int st[V+1];
    int ft[V+1];
    int time=0;
    dfs(graph1,V,visited,st,ft,&time);

    int visited1[V+1];
    int st1[V+1];
    int ft1[V+1];
    int time1=0;

    int SCC[V+1];
    for(i=0;i<V+1;i++)
    {
        SCC[i]=-1;
    }

    int count_SCC=dfs1(graph2,V,visited1,st1,ft1,&time1,SCC);

    struct graph* graph3 = makegraph(V);
    for(i=1;i<V+1;i++)
    {
        struct adjlistnode* temp=graph1->array[i].head;
        while(temp!=NULL)
        {
            if(SCC[temp->dest]!=SCC[i])
            {
                insertedge(graph3,SCC[i],SCC[temp->dest]);
            }
            temp=temp->next;
        }
    }

    int GSCC[V+1];
    for(i=0;i<V+1;i++)
    {
        GSCC[i]=-1;
    }

    for(i=1;i<=count_SCC;i++)
    {
        struct adjlistnode* temp=graph1->array[i].head;
        struct adjlistnode* prev=NULL;
        while(temp!=NULL)
        {
            GSCC[temp->dest]=i;
            if(GSCC[temp->dest]==i)
            {
                delete_this(graph3,temp,prev);
            }
            prev=temp;
            temp=temp->next;
        }
    }

    printf("\n");
    printf("\n");
    printf("\n");
    showgraph(graph3);
    return 0;
}
