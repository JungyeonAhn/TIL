#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;


Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


void insert(Node *root,int data, int left, int right)
{
	if (root == NULL)
		return;
	if (root->data == data) {

		if (left != 0) {
			root->left = newNode(left);
		}
		if (right != 0) {
			root->right = newNode(right);
		}
	}
	insert(root->left, data, left, right);
	insert(root->right, data, left, right);
}

void preorder(Node* root)
{
	if (root != NULL) {
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void search(Node* root, char *s) {
	int n = strlen(s),i;
	Node *p = root;
	printf(" %d", p->data);
	for (i = 0; i < n; i++) {
		if (s[i] == 'R')
			p = p->right;
		if (s[i] == 'L')
			p = p->left;
		if (p != NULL) {
			printf(" %d", p->data);
		}
	}
	printf("\n");
}

int main()
{
	Node* root = NULL;
	Node *node = NULL;
	int data, left, right, n,m, i;
	char s[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &data, &left, &right);
		if (root == NULL)
			root = newNode(data);
		insert(root,data, left, right);
	}
	
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%s", s);
		search(root,s);
	}

	//preorder(root);


	return 0;
}