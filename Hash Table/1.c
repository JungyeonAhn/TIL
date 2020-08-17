#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *next;
}node;

int hashfunction(int x, int M)
{
	return x % M;
}
void insert(node *hashtable, int size, int x)
{
	int code = hashfunction(x, size);
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value = x;
	tmp->next = hashtable[code].next;
	hashtable[code].next = tmp;
}
void search(node *hashtable, int M, int x)
{
	int code = hashfunction(x, M);
	int cnt = 0;
	node *tmp = hashtable[code].next;

	while (tmp != NULL)
	{
		cnt++;
		if (tmp->value == x)
		{
			printf("%d\n", cnt);
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		printf("0\n");

}
void deleteNode(node *hashtable, int M, int x)
{
	int code = hashfunction(x, M);
	int cnt = 0;
	node *tmp = &hashtable[code];
	node *p = NULL;

	while (tmp->next != NULL)
	{
		cnt++;
		if (tmp->next->value == x)
		{
			printf("%d\n", cnt);
			p = tmp->next;
			tmp->next = tmp->next->next;
			free(p);
			break;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL && p==NULL)
		printf("0\n");
}
void printhash(node *hashtable, int M)
{
	int i;
	node *tmp = NULL;
	for (i = 0; i < M; i++)
	{
		tmp = hashtable[i].next;
		while (tmp != NULL)
		{
			printf(" %d", tmp->value);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
int main()
{
	int M, x, i;
	char c;
	node *hashtable;
	scanf("%d", &M);
	hashtable = (node*)malloc(sizeof(node)*M);
	for (i = 0; i < M; i++)
	{
		hashtable[i].value = 0;
		hashtable[i].next = NULL;
	}
	while (1)
	{
		getchar();
		scanf("%c", &c);
		if (c == 'e')
			break;
		switch (c)
		{
		case 'i':
			scanf("%d", &x);
			insert(hashtable, M, x);
			break;
		case 's':
			scanf("%d", &x);
			search(hashtable, M, x);
			break;
		case 'd':
			scanf("%d", &x);
			deleteNode(hashtable, M, x);
			break;
		case 'p':
			printhash(hashtable, M);
			break;
		default:
			break;
		}
	}

	return 0;
}