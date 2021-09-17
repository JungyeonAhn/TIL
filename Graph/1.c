#include <stdio.h>
#include <stdlib.h>

int Vnum = 0;
typedef struct node {
	int name;
	struct node *next;
}node;
typedef struct vertex {
	int name;
	node *head;
}Vertex;
typedef struct edge {
	int ep1;
	int ep2;
	int weight;
}Edge;
typedef struct Graph {
	Vertex *vertexs;
	Edge *edges;
}Graph;
//그래프 생성
Graph *newGraph()
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexs = (Vertex*)malloc(sizeof(Vertex) * 6);
	graph->edges = (Edge*)malloc(sizeof(Edge) * 7 * 3);
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
//정점 추가
void addVertex(Graph *graph, int name)
{
	node *p = (node*)malloc(sizeof(node));

	if (existVertex(graph, name) != -1) // 정점이 존재할 경우
		return;
	else //정점이 없을 경우 정점 추가
	{
		p->next = NULL;
		p->name = -1;
		graph->vertexs[Vnum].name = name;
		graph->vertexs[Vnum].head = p;
		Vnum++;
	}
}
//간선 추가
void addEdge(Graph *graph, int ep1, int ep2, int weight)
{
	int tmp, i;
	node *p = NULL, *q = NULL;
	node *n = (node*)malloc(sizeof(node));
	node *m = (node*)malloc(sizeof(node));

	if (ep1 > ep2)
	{
		tmp = ep1;
		ep1 = ep2;
		ep2 = tmp;
	}

	i = existEdge(graph, ep1, ep2);
	graph->edges[i] = *newEdge(ep1, ep2, weight);

	// 해당하는 간선에 대한 인접리스트 삽입
	n->name = existEdge(graph, ep1, ep2);
	n->next = NULL;
	p = graph->vertexs[ep1 - 1].head;
	while (p->next != NULL && p->next->name < n->name)
	{
		p = p->next;
	}
	n->next = p->next;
	p->next = n;

	if (ep1 == ep2) return; // 루프일 경우 중복삽입 제외

	m->name = existEdge(graph, ep1, ep2);
	m->next = NULL;
	q = graph->vertexs[ep2 - 1].head;
	while (q->next != NULL && q->next->name < m->name)
	{
		q = q->next;
	}
	m->next = q->next;
	q->next = m;
}
// 그래프에 특정 정점이 존재하는지 확인
int existVertex(Graph *graph, int name)
{
	int i, flag = -1;
	for (i = 0; i < 6; i++)
	{
		if (name == graph->vertexs[i].name)
			flag = i;
	}
	return flag;
}
// 두 개의 정점 사이에 간선이 있는지 확인
int existEdge(Graph *graph, int ep1, int ep2) {
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
// 'a'입력시 
void findNeighvor(Graph *graph, int ep)
{
	node *p = NULL;
	int i;
	if (ep < 1 || ep>6)
	{
		printf("-1\n");
		return;
	}
	p = graph->vertexs[ep - 1].head->next;
	while (p != NULL)
	{
		i = p->name;
		if (ep == graph->edges[i].ep1)
			printf(" %d %d", graph->edges[i].ep2,graph->edges[i].weight);
		else if (ep == graph->edges[i].ep2)
			printf(" %d %d", graph->edges[i].ep1,graph->edges[i].weight);
		p = p->next;
	}
	printf("\n");
}
// 'm'입력시
void modify(Graph *graph, int ep1, int ep2, int weight)
{
	int i, tmp;
	node *p = (node*)malloc(sizeof(node));
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
	if (weight == 0) // 가중치가 0인 경우 해당 인접리스트 삭제
	{
		p = graph->vertexs[ep1 - 1].head;
		i = existEdge(graph, ep1, ep2);
		while (p->next != NULL && p->next->name != i)
		{
			p = p->next;
		}
		p->next = p->next->next;
		graph->edges[i].weight = 0;
		if (ep1 == ep2) return;
		p = graph->vertexs[ep2 - 1].head;
		while (p->next != NULL && p->next->name != i)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
	else if (graph->edges[i].weight == 0) // 간선이 없으면 간선 추가
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
	Graph *graph = newGraph();

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
			findNeighvor(graph, ep);
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