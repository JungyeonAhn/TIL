#include <stdio.h>
#include <stdlib.h>
int Vnum = 0;
int Enum = 0;
typedef struct vertex {
	int name;
	int vertexlabel;
}Vertex;
typedef struct edge {
	int ep1;
	int ep2;
	int edgelabel;
}Edge;
typedef struct graph {
	Vertex *vertexs;
	Edge *edges;
	int vn; //정점 개수
	int **matrix; //그래프 인접 행렬
}Graph;

Graph *newGraph(int vn, int en);
Edge *newEdge(int ep1, int ep2);
void addVertex(Graph *graph, int name);
int existEdge(Graph *graph, int ep1, int ep2);
void addEdge(Graph *graph, int ep1, int ep2);
void BFS(Graph *graph, int s);
void printGraph(Graph *graph);

int main()
{
	int n, m, s;
	int ep1, ep2, i;
	Graph *graph;

	scanf("%d%d%d", &n, &m, &s);
	graph = newGraph(n, m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &ep1, &ep2);
		addEdge(graph, ep1, ep2);
	}

	for (i = 0; i < graph->vn; i++)
	{
		graph->vertexs[i].vertexlabel = 0;
	}
	for (i = 0; i < Enum; i++)
	{
		graph->edges[i].edgelabel = 0;
	}
	BFS(graph, s);
//	printGraph(graph);

	return 0;
}

Graph *newGraph(int vn, int en)
{
	int i = 0, j = 0;
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexs = (Vertex*)malloc(sizeof(Vertex) * vn);
	graph->edges = (Edge*)malloc(sizeof(Edge)*vn*vn);
	graph->vn = vn;

	for (i = 0; i < graph->vn; i++)
	{
		addVertex(graph, i);
	}
	for (i = 0; i < graph->vn; i++)
	{
		for (j = i; j < graph->vn; j++)
		{
			graph->edges[Enum] = *newEdge(i + 1, j + 1);
			Enum++;
		}
	}

	//인접행렬 동적 생성 후 초기화
	graph->matrix = (int**)malloc(sizeof(int*)*vn);
	for (i = 0; i < vn; i++)
	{
		graph->matrix[i] = (int*)malloc(sizeof(int)*vn);
		for (j = 0; j < vn; j++)
		{
			graph->matrix[i][j] = -1;
		}
	}
	return graph;
}
//간선 생성
Edge *newEdge(int ep1, int ep2) {
	Edge *edge = (Edge*)malloc(sizeof(Edge));
	int tmp;
	if (ep1 > ep2)
	{
		tmp = ep1;
		ep1 = ep2;
		ep2 = tmp;
	}
	edge->ep1 = ep1;
	edge->ep2 = ep2;
	return edge;
}
void addVertex(Graph *graph, int name) // vertex 추가
{
	graph->vertexs[Vnum].name = name;
	Vnum++;
}
int existEdge(Graph *graph, int ep1, int ep2)
{
	int i, flag = -1, tmp;
	if (ep1 > ep2)
	{
		tmp = ep1;
		ep1 = ep2;
		ep2 = tmp;
	}
	for (i = 0; i < Enum; i++)
	{
		if (graph->edges[i].ep1 == ep1 && graph->edges[i].ep2 == ep2) //존재할 경우
		{
			flag = i;
		}
	}
	return flag;
}
void addEdge(Graph *graph, int ep1, int ep2) //간선 추가
{
	int i = existEdge(graph, ep1, ep2);
	graph->edges[i] = *newEdge(ep1, ep2);
	//인접 행렬에 추가
	graph->matrix[ep1 - 1][ep2 - 1] = i;
	graph->matrix[ep2 - 1][ep1 - 1] = i;
}
void BFS(Graph *graph, int s)
{
	int front = 0, rear = 0, Pop, i;
	int *queue = (int*)malloc(sizeof(int)*graph->vn);

	memset(queue, 0, sizeof(int)*graph->vn);
	queue[0] = s;
	rear++;

	//정점 방문
	graph->vertexs[s - 1].vertexlabel = 1;
	printf("%d\n", s);

	while (front < rear)
	{
		Pop = queue[front];
		front++;
		for (i = 0; i < graph->vn; i++)
		{
			if (graph->matrix[Pop-1][i] != -1 && graph->vertexs[i].vertexlabel == 0)
			{
				printf("%d\n", i+1);
				queue[rear] = i+1;
				rear++;
				graph->vertexs[i].vertexlabel = 1;
			}
		}
	}
	return;
}
void printGraph(Graph *graph)
{
	int i, j;

	for (i = 0; i < graph->vn; i++)
	{
		printf(" %d %d\n", graph->vertexs[i].name, graph->vertexs[i].vertexlabel);
		printf("\n");
	}
	for (i = 0; i < Enum; i++)
	{
		printf(" %d %d %d\n", graph->edges[i].ep1, graph->edges[i].ep2, graph->edges[i].edgelabel);
	}
	for (i = 0; i < graph->vn; i++) {
		for (j = 0; j < graph->vn; j++)
		{
			printf(" %d", graph->matrix[i][j]);
		}
		printf("\n");
	}
}