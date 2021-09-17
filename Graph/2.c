#include <stdio.h>
#include <stdlib.h>
Vnum = 0;
typedef struct vertex {
	int name;
}Vertex;
typedef struct edge {
	int ep1;
	int ep2;
	int weight;
}Edge;
typedef struct graph {
	Vertex *vertexs;
	Edge *edges;
	int vn; //정점 개수
	int **matrix; //그래프 인접 행렬
}Graph;

Graph *newGraph(int max_vertex)
{
	int i = 0, j = 0;
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexs = (Vertex*)malloc(sizeof(Vertex) * 6);
	graph->edges = (Edge*)malloc(sizeof(Edge) * 7 * 3);
	graph->vn = max_vertex;

	//인접행렬 동적 생성
	graph->matrix = (int**)malloc(sizeof(int*)*max_vertex);
	for (i = 0; i < max_vertex; i++)
	{
		graph->matrix[i] = (int*)malloc(sizeof(int)*max_vertex);
		for (j = 0; j < max_vertex; j++)
		{
			graph->matrix[i][j] = -1;
		}
	}
	return graph;
}
//간선 생성
Edge *newEdge(int ep1, int ep2, int weight) {
	Edge *edge = (Edge*)malloc(sizeof(Edge));
	edge->ep1 = ep1;
	edge->ep2 = ep2;
	edge->weight = weight;
	return edge;
}
void addVertex(Graph *graph, int name) // vertex 추가
{
	graph->vertexs[Vnum].name = name;
	Vnum++;
}
int existEdge(Graph *graph, int ep1, int ep2) 
{
	int i, flag = -1;
	for (i = 0; i < 7 * 3; i++)
	{
		if (graph->edges[i].ep1 == ep1 && graph->edges[i].ep2 == ep2) //존재할 경우
		{
			flag = i;
		}
	}
	return flag;
}
void addEdge(Graph *graph, int ep1, int ep2,int weight) //간선 추가
{
	int i = existEdge(graph, ep1, ep2);
	graph->edges[i] = *newEdge(ep1, ep2, weight);
	//인접 행렬에 추가
	graph->matrix[ep1-1][ep2-1] = i; 
	graph->matrix[ep2-1][ep1-1] = i;
}
void adjacent(Graph *graph, int ep)
{
	int i, j;
	int index;

	if (ep < 1 || ep>6)
	{
		printf("-1\n");
		return;
	}

	for (i = 0; i < graph->vn; i++)
	{
		if (graph->matrix[ep-1][i] != -1)
		{
			index = graph->matrix[ep-1][i];
			printf(" %d %d", i+1, graph->edges[index].weight);
		}
	}
	printf("\n");
}
void modify(Graph *graph, int ep1, int ep2, int weight)
{
		int i, tmp;
		if (ep1 > ep2)
		{
			tmp = ep1;
			ep1 = ep2;
			ep2 = tmp;
		}
		if (ep1 < 1 || ep2>6)
		{
			printf("-1\n");
			return;
		}
		i = existEdge(graph, ep1, ep2);
		if (weight == 0) // 가중치가 0인 경우 해당 간선 삭제
		{
			graph->matrix[ep1-1][ep2-1] = -1;
			graph->matrix[ep2-1][ep1-1] = -1;
		}
		else if (graph->matrix[ep1-1][ep2-1]==-1) // 간선이 없으면 간선 추가
		{
			addEdge(graph, ep1, ep2, weight);
		}
		else // 간선이 존재하면 가중치 변경
		{
			graph->edges[i].weight = weight;
		}

}
int main()
{
	char c;
	int ep, tmp = 0, i, j;
	int ep1, ep2, weight;
	Graph *graph = newGraph(6);


	addVertex(graph, 1);
	addVertex(graph, 2);
	addVertex(graph, 3);
	addVertex(graph, 4);
	addVertex(graph, 5);
	addVertex(graph, 6);

	for (i = 0; i < 6; i++)
	{
		for (j = i; j < 6; j++)
		{
			graph->edges[tmp] = *newEdge(i + 1, j + 1, 0);
			tmp++;
		}
	}

	addEdge(graph, 1, 2, 1);
	addEdge(graph, 1, 3, 1);
	addEdge(graph, 1, 4, 1);
	addEdge(graph, 1, 6, 2);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 5, 4);
	addEdge(graph, 5, 5, 4);
	addEdge(graph, 5, 6, 3);

	while (1) {
		scanf("%c", &c);
		if (c == 'a') {
			scanf("%d", &ep);
			adjacent(graph, ep);
		}
		else if (c == 'm') {
			scanf("%d%d%d", &ep1, &ep2, &weight);
			modify(graph, ep1, ep2, weight);
		}
		else
			break;
		getchar();
	}
	return 0;
}