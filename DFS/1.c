#include <stdio.h>
#include <stdlib.h>

int Vnum = 0;
int Enum = 0;
typedef struct node {
	int name;
	struct node *next;
}node;
typedef struct vertex {
	int name;
	int vertexlabel;
	node *head;
}Vertex;
typedef struct edge {
	int ep1;
	int ep2;
	int edgelabel;
}Edge;
typedef struct Graph {
	Vertex *vertexs;
	Edge *edges;
	int vn, en;
}Graph;
Graph *newGraph(int vn, int en);
Edge *newEdge(int ep1, int ep2);
void addVertex(Graph *graph, int name);
void addEdge(Graph *graph, int ep1, int ep2);
int existVertex(Graph *graph, int name);
int existEdge(Graph *graph, int ep1, int ep2);
int oppositVertex(Edge e, Vertex v);
void rDFS(Graph *graph, int s);
void DFS(Graph *graph, int s);
void printGraph(Graph *graph);
int main()
{
	int i, ep1, ep2, n,m,s;
	Graph *graph=NULL;

	scanf("%d%d%d", &n, &m, &s);
	graph = newGraph(n,m);

	for (i = 0; i < graph->en ; i++) {
		scanf("%d %d", &ep1, &ep2);
		addEdge(graph, ep1, ep2);
	}
	//printGraph(graph);
	DFS(graph,s);
	return 0;
}
//그래프 생성
Graph *newGraph(int vn, int en)
{
	int i, j;
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vn = vn;
	graph->en = en;
	graph->vertexs = (Vertex*)malloc(sizeof(Vertex) * graph->vn);
	graph->edges = (Edge*)malloc(sizeof(Edge) * graph->vn*graph->vn);

	for (i = 1; i <= graph->vn; i++)
	{
		addVertex(graph, i);
	}

	for (i = 0; i < graph->vn; i++) //간선 배열 초기화
	{
		for (j = i; j < graph->vn; j++)
		{
			graph->edges[Enum] = *newEdge(i + 1, j + 1);
			Enum++;
		}
	}
	return graph;
}
//간선 생성
Edge *newEdge(int ep1, int ep2) {
	Edge *edge = (Edge*)malloc(sizeof(Edge));
	edge->ep1 = ep1;
	edge->ep2 = ep2;
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
void addEdge(Graph *graph, int ep1, int ep2)
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
	graph->edges[i] = *newEdge(ep1, ep2);

	// 해당하는 간선에 대한 인접리스트 삽입
	n->name = i;
	n->next = NULL;
	p = graph->vertexs[ep1 - 1].head;
	while (p->next != NULL && p->next->name < n->name)
	{
		p = p->next;
	}
	n->next = p->next;
	p->next = n;

	if (ep1 == ep2) return; // 루프일 경우 중복삽입 제외

	m->name = i;
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
	for (i = 0; i < graph->vn; i++)
	{
		if (name == graph->vertexs[i].name)
			flag = i;
	}
	return flag;
}
// 두 개의 정점 사이에 간선이 있는지 확인
int existEdge(Graph *graph, int ep1, int ep2) 
{
	int i, flag = -1;
	for (i = 0; i < Enum; i++)
	{
		if (graph->edges[i].ep1 == ep1 && graph->edges[i].ep2 == ep2) //존재할 경우
		{
			flag = i;
		}
	}
	return flag;
}
int oppositVertex(Edge e, Vertex v)
{
	if (e.ep1 == v.name)
		return e.ep2;
	else
		return e.ep1;
}
void rDFS(Graph *graph, int s)
{
	node *tmp = NULL;
	int x = -1;
	// 정점 방문 후 label 1로 표시
	printf("%d\n", s); 
	graph->vertexs[s - 1].vertexlabel = 1;

	//인접리스트 순회
	tmp = graph->vertexs[s - 1].head->next;
	while (tmp != NULL)
	{
		if (graph->edges[tmp->name].edgelabel == 0) //만약 인접리스트의 간선을 방문안했을 경우
		{	
			//x에 인접리스트의 간선의 반대 정점 저장
			x = existVertex(graph, oppositVertex(graph->edges[tmp->name], graph->vertexs[s - 1])); 
			if (graph->vertexs[x].vertexlabel == 0) //반대 정점을 방문안했을 경우
			{
				rDFS(graph, graph->vertexs[x].name); //재귀
			}
			else //방문했을 경우
				graph->edges[tmp->name].edgelabel = 2; //간선 방문표시
		}
		tmp = tmp->next;
	}
	return;
}
void DFS(Graph *graph, int s)
{
	int i;
	for (i = 0; i < graph->vn; i++)
	{
		graph->vertexs[i].vertexlabel = 0;
	}
	for (i = 0; i < Enum; i++)
	{
		graph->edges[i].edgelabel = 0;
	}
	rDFS(graph, s);
}
void printGraph(Graph *graph)
{
	int i;
	node *p = NULL;
	for (i = 0; i < graph->vn; i++)
	{
		printf(" %d %d\n", graph->vertexs[i].name, graph->vertexs[i].vertexlabel);
		p = graph->vertexs[i].head;
		while (p->next != NULL)
		{
			printf(" %d", p->name);
			p = p->next;
		}
		printf("\n");
	}
	for (i = 0; i < Enum; i++)
	{
		printf(" %d %d %d\n", graph->edges[i].ep1, graph->edges[i].ep2, graph->edges[i].edgelabel);
	}
}