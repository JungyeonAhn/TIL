#include <stdio.h>
#include <stdlib.h>
typedef struct vertex
{
	char name;
	struct node *outEdges;
	struct node *inEdges;
	int inDegree;
}vertices;
typedef struct edge
{
	int origin;
	int destination;
}edges;
typedef struct graph
{
	struct vertex *vertices;
	struct edge *edges;
}graph;
typedef struct node
{
	struct node *next;
	int element;
}node;
int n, m;
graph G;
int topOrder[101];
int Q[100];
int front = -1;
int rear = -1;
void enqueue(int data)
{
	if (rear == n - 1) 
	{
		printf("overflow\n");
	}	
	Q[++rear] = data;
}
int dequeue()
{

	if (rear == front)
	{
		printf("underflow\n");
	}
	return Q[++front];
}
int isEmpty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}
int index(char vName)
{
	int i;
	for (i = 0; i < n; i++)
		if (G.vertices[i].name == vName)
			return i;
}
void addFirst(node *H, int i)
{
	node *Node = (node*)malloc(sizeof(node));
	Node->element = i;
	Node->next = H->next;
	H->next = Node;
}
void topologicalSort()
{
	int i;
	int *in = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i);
	}
	int t = 1;
	while (!isEmpty())
	{
		int u = dequeue();
		topOrder[t] = u;
		t = t + 1;
		node *tmp = G.vertices[u].outEdges->next;
		while (tmp != NULL)
		{
			int e = tmp->element;
			int w = G.edges[e].destination;
			in[w] = in[w] - 1;
			if (in[w] == 0)
				enqueue(w);
			tmp = tmp->next;
		}
	}
	if (t <= n)
		topOrder[0] = 0;
	else
		topOrder[0] = 1;
	free(in);
}
void insertVertex(char vName, int i)
{
	G.vertices[i].name = vName;
	G.vertices[i].outEdges = (node*)malloc(sizeof(node));
	G.vertices[i].outEdges->next = NULL;
	G.vertices[i].inEdges = (node*)malloc(sizeof(node));
	G.vertices[i].inEdges->next = NULL;
	G.vertices[i].inDegree = 0;
}
void insertDirectedEdge(char uName, char wName, int i)
{
	int u = index(uName);
	int w = index(wName);
	G.edges[i].origin = u;
	G.edges[i].destination = w;
	addFirst(G.vertices[u].outEdges, i);
	addFirst(G.vertices[w].inEdges, i);
	G.vertices[w].inDegree++;
}
void initializeGraph()
{
	G.vertices = (vertices*)malloc(sizeof(vertices) * 100);
	G.edges = (edges*)malloc(sizeof(edges) * 1000);
}
void buildGraph()
{
	int i;
	char vName, uName, wName;

	initializeGraph();

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%c", &vName);
		getchar();
		insertVertex(vName, i);
	}

	scanf("%d", &m);
	getchar();
	for (i = 0; i < m; i++)
	{
		scanf("%c", &uName);
		getchar();
		scanf("%c", &wName);
		getchar();
		insertDirectedEdge(uName, wName, i);
	}
}
int main()
{
	int i;
	buildGraph();

	topologicalSort();

	if (topOrder[0] == 0)
		printf("0\n");
	else
	{
		for (i = 1; i <= n; i++)
			printf("%c ", G.vertices[topOrder[i]].name);
		printf("\n");
	}


	return 0;
}