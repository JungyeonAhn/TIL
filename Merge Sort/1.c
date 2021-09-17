#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node * next;
}Node;

Node * merge(Node * L1, Node * L2) {
	Node * retNode;
	Node *p, *q;
	Node *r;


	p = L1;
	q = L2;

	if (p->num <= q->num)
		retNode = p, p = p->next;
	else
		retNode = q, q = q->next;

	r = retNode;

	while (p != NULL && q != NULL) {
		if (p->num <= q->num)
			r->next = p, p = p->next;
		else
			r->next = q, q = q->next;
		r = r->next;
	}

	while (p != NULL)
		r->next = p, p = p->next, r = r->next;
	while (q != NULL)
		r->next = q, q = q->next, r = r->next;

	return retNode;
}

void mgPartition(Node ** L1, Node ** L2, Node * L, int k) {
	int i;
	Node *p;

	*L1 = L;
	p = L;

	for (i = 0; i < k - 1; i++)
		p = p->next;

	*L2 = p->next;
	p->next = NULL;
}


void mergeSort(Node **L, int size) {

	Node * L1, *L2;

	if (size > 1) {
		mgPartition(&L1, &L2, *L, size / 2);
		mergeSort(&L1, size / 2);
		if (size % 2 == 0)
			mergeSort(&L2, size / 2);
		else
			mergeSort(&L2, (size / 2) + 1);
		*L = merge(L1, L2);
	}
	return;

}

Node * List(int n) {
	Node * retNode;
	Node * p;
	int i;

	retNode = (Node *)malloc(sizeof(Node));

	p = retNode;

	for (i = 0; i < n - 1; i++) {
		scanf("%d", &(p->num));
		p->next = (Node *)malloc(sizeof(Node));
		p = p->next;
	}
	scanf("%d", &(p->num));
	p->next = NULL;

	return retNode;
}

void main()
{
	Node * root;
	int n;
	Node * p;
	int i;
	Node * trav;
	Node * remove;


	scanf("%d", &n);

	root = List(n);

	mergeSort(&root, n);
	
	p = root;

	while (p != NULL) {
		printf(" %d", p->num);
		p = p->next;
	}

	remove = root;
	trav = remove->next;

	while (trav != NULL) {
		free(remove);
		remove = trav;
		trav = trav->next;
	}

	free(remove);

}