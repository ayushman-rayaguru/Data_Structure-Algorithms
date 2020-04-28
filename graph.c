/*BFS and DFS on a graph represented using adjacency matrix*/
#include<stdio.h>
#define MAX 10

typedef struct Q
{
	int R,F;
	int data[MAX];
}Q;

int empty(Q *P);
int full(Q *P);
void enqueue(Q *P,int x);
int dequeue(Q *P);

void BFS(int);
void DFS(int);

int G[MAX][MAX];
int n=0;
int visited[MAX];

void main()
{
	int i,j,v,op,nedges;
	printf("\n******************** GRAPHS IN C (DSA PRACTICAL)********************\n\n");
	printf("\nMy Roll No is 22206\n");
	printf("\nEnter no of vertices : ");
	scanf("%d",&n);
	printf("\nEnter No. of edges : ");
	scanf("%d",&nedges);
	
	for(i=0;i<n;i++)
	     for(j=0;j<n;j++)
		G[i][j]=0;

	printf("\nEnter the Graph as list of edges(Starting vertex No. is 0): ");
	for(v=0;v<nedges;v++)
	   {
		printf("\nEnter the next edge(Start vertex, end vertex) : ");
		scanf("%d%d",&i,&j);
		G[i][j]=G[j][i]=1;//Mark the edge
	    }

	do{
	   printf("\n\n1)DFS\n2)BFS\n3)Display the graph\n4)QUIT");
	   printf("\nEnter Your choice : ");
	   scanf("%d",&op);
	   switch(op)
	    {
		case 1:printf("\nEnter the starting vertex for DFS : ");
		       scanf("%d",&v);
		       for(i=0;i<n;i++)
			   visited[i]=0;
		       DFS(v);break;
		case 2:printf("\nEnter the starting vertex for BFS : ");
		       scanf("%d",&v);
		       BFS(v);break;
		case 3:printf("\nAdjacency Matrix : \n");
		       for(i=0;i<n;i++)
			   {
				printf("\n");
				for(j=0;j<n;j++)
					printf("%d  ",G[i][j]);
			    }
			break;

	    }
	  }while(op!=4);

}

void BFS(int v)
{
	int visited[MAX],i;
	Q q;
	q.R=q.F=-1;
	for(i=0;i<n;i++)
	  visited[i]=0;
	enqueue(&q,v);
	printf("\n visit:\n%d",v);
	visited[v]=1;
	while(!empty(&q))
	{
		v=dequeue(&q);
		
		for(i=0;i<n;i++)
			if(visited[i]==0 && G[v][i]!=0)
			{
				enqueue(&q,i);
				visited[i]=1;
				printf("\n%d",i);
			}
	}
}

int empty(Q *P)
{
	if(P->R==-1)
		return(1);
	return(0);
}

int full(Q *P)
{
	if(P->R==MAX-1)
		return(1);
	return(0);
}

void enqueue(Q *P,int x)
{
	if(P->R==-1)
	{
		P->R=P->F=0;
		P->data[P->R]=x;
	}
	else
	{
		P->R=P->R+1;
		P->data[P->R]=x;
	}
}

int dequeue(Q *P)
{
	int x;
	x=P->data[P->F];
	if(P->R==P->F)
	{
		P->R=-1;
		P->F=-1;
	}
	else
		P->F=P->F+1;
	return(x);
}

void DFS(int i)
{
	int j;
	printf("\n%d",i);
	visited[i]=1;
	for(j=0;j<n;j++)
		if(!visited[j] && G[i][j]==1)
			DFS(j);
}


