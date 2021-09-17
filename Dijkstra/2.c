#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct vertex
{
	int num;
	int d;
}vertices;
typedef struct edge
{
	int fromVindex;
	int toVindex;
	int weight;
}edges;
typedef struct graph
{
	struct vertex *vertices;
	struct edge *edges;
}graph;
graph G;
int n, m, s;
int countEdge = 0;
int min(int a,int b) 
{
	return ((a) < (b)) ? (a) : (b);
}
void insertEdge(int a, int b, int w)
{
	G.edges[countEdge].fromVindex = a;
	G.edges[countEdge].toVindex = b;
	G.edges[countEdge].weight = w;
	countEdge++;
}
void initializeGraph()
{
	G.vertices = (vertices*)malloc(sizeof(vertices) * 100);
	G.edges = (edges*)malloc(sizeof(edges) * 1000);
}
void buildGraph()
{
	int i, fromV, toV, w;
	initializeGraph();
	scanf("%d %d %d", &n, &m, &s);
	for (i = 0; i < n; i++)
	{
		G.vertices[i].num = i + 1;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &fromV, &toV, &w);
		insertEdge(fromV - 1, toV - 1, w);
	}
}
void BellmanFordShortestPaths()
{
	int i, j, u, z;
	for (i = 0; i < n; i++)
	{
		G.vertices[i].d = 30000;
	}
	G.vertices[s - 1].d = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			u = G.edges[j].fromVindex;
			z = G.edges[j].toVindex;
			if ( G.vertices[u].d == 30000)
				continue;
			G.vertices[z].d = min(G.vertices[z].d, G.vertices[u].d + G.edges[j].weight);
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i == s - 1 || G.vertices[i].d == 30000)
			continue;
		printf("%d %d\n", G.vertices[i].num, G.vertices[i].d);
	}
}
int main()
{
	buildGraph();
	BellmanFordShortestPaths();
	return 0;
}