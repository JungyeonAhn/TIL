#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int vertex;
	int weight;
	struct List *next;
}List;

List *graph[101];

void insertEdge(int from, int desti, int weight)
{
	List *node;

	node = (List *)malloc(sizeof(List));
	node->vertex = desti;
	node->weight = weight;
	node->next = graph[from];
	graph[from] = node;

	node = (List*)malloc(sizeof(List));
	node->vertex = from;
	node->weight = weight;
	node->next = graph[desti];
	graph[desti] = node;
}

void Dijkstra(int start, int end, int n, int m){
	int *distance;	
	int *check;		
	distance = (int *)malloc((n + 1) * sizeof(int));
	check = (int *)malloc((n + 1) * sizeof(int));
	List *tmp;				
	int cycle, min, current, i;			

	for (i = 1; i < n+1 ; i++)		
	{
		distance[i] = 9999;		
		check[i] = 0;		
	}
	distance[start] = 0;			
	cycle = 0;

	while (cycle < n){
		min = 9999;
		for (i = 0; i < n + 1; i++){
			if (distance[i] < min && !check[i]){
				min = distance[i];
				current = i;	
			}
		}
		check[current] = 1;		
		tmp = graph[current];	

		while (tmp != NULL){
			if (!check[tmp->vertex]){
				if (min + tmp->weight < distance[tmp->vertex]){
					distance[tmp->vertex] = min + tmp->weight;
				}
			}
			tmp = tmp->next;
		}

		cycle++;
		if (current == end) break;
	}
	if (distance[end] != 9999) {
		printf("%d %d", end, distance[end]);
		printf("\n");
	}
}

int main()
{
	int n, m, q;
	int i, end;
	int from, desti, weight;
	scanf("%d %d %d", &n, &m, &q);

	for (i = 0; i < m; i++){
		scanf("%d %d %d", &from, &desti, &weight);
		insertEdge(from, desti, weight);
	}
	for (i = 1; i <= n; i++){
		end = i;
		if (end != q) {
			Dijkstra(q, end, n, m);
		}
	}
}
