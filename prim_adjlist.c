#include <stdio.h>
#include <limits.h>

int min_weight(int *key,int *color,int V)
{
	int i,index,limit=1000;
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

void prim_algo(int *key,int *color,int *parent,int V,int a[][V+1])
{
	key[1]=0;
	parent[1]=-1;

	int i,j;

	for (i=1;i<V;i++)
    {
        int adj=min_weight(key,color,V);

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
void print_MST(int V,int a[][V+1],int *parent)
{
	int i;
	printf("Edges\tWeights\n");
	for(i=2;i<V+1;i++)
	{
		
		{
			printf("%d<--->%d\t%d\n",parent[i],i,a[i][parent[i]]);
		}
	}
}

int insertedge(int V,int a[][V+1],int src,int dest,int w)
{
	a[src][dest]=w;
	a[dest][src]=w;
}
int main()
{
	int V;
	printf("Enter number of vertices");
	scanf("%d",&V);
	getchar();

	int E;
	printf("Enter number of edges");
	scanf("%d",&E);
	getchar();
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

	int key[V+1],color[V+1],parent[V+1],w[V+1],v1,v2;
	for(i=0;i<V+1;i++)
	{
		key[i]=1000;
		color[i]=0;
		parent[i]=-1;
		w[i]=0;
	}

	for(i=1;i<=E;i++)
    {
    	printf("Enter edge %d is: ",i);
    	scanf("%d %d",&v1,&v2);
    	getchar();

    	while((v1>V || v2>V) || (v1 <=0 || v2 <=0))
    	{
            printf("    Enter vertex number in the range [1,%d]\n",V);
            printf("    Again enter edge %d : ",i);

            scanf("%d %d",&v1,&v2);
            getchar();
    	}
    	printf("Enter this Edge's weight: ");

    	scanf("%d",&w[i]);
    	getchar();
    	insertedge(V,a,v1,v2,w[i]);
    }

    for(i=1;i<V+1;i++)
    {
    	for(j=1;j<V+1;j++)
    	{
    		printf("%-3d ",a[i][j]);
    	}
    	printf("\n");
    }

    prim_algo(key,color,parent,V,a);

    print_MST(V,a,parent);

    return 0;
}
