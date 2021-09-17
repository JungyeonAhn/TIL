#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	int height;
	struct node *left, *right;
}node;
node* newNode(int item);
int height(node *N);
int Max(int a, int b);
void updateHeight(node *node);
void preorder(node* root);
void inorder(node *root);
int getBalance(node *node);
node* leftRotate(node *node);
node* rightRotate(node *node);
node* insert(node *node, int key);
node* search(node *root, int key);
node* minValueNode(node *node);
node* deleteNode(struct node* root, int key);
int main()
{
	node *root = NULL;
	node *tmp = NULL;
	char c;
	int key;

	while (1)
	{
		scanf("%c", &c);
		if (c == 'q') break;
		switch (c)
		{
		case 'i':
			scanf("%d", &key);
			root = insert(root, key);
			break;
		case 'd':
			scanf("%d", &key);
			tmp = search(root, key);
			if (tmp != NULL)
			{
				printf("%d\n", tmp->key);
				root = deleteNode(root, key);
			}
			else
				printf("X\n");
			break;
		case 's':
			scanf("%d", &key);
			tmp = search(root, key);
			if (tmp != NULL)
				printf("%d\n", tmp->key);
			else
				printf("X\n");
			break;
		case 'p':
			preorder(root);
			printf("\n");
			break;
		default:
			break;
		}
		getchar();
	}

	return 0;
}
void preorder(node* root)
{
	printf(" %d", root->key);
	if (root->left) preorder(root->left);
	if (root->right) preorder(root->right);
}
void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %d", root->key);
		inorder(root->right);
	}
}
node* newNode(int item)
{
	node *p = (node*)malloc(sizeof(node));
	p->key = item;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
	
}
int height(node *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}
void updateHeight(node *node)
{
	node->height = Max(height(node->left), height(node->right)) + 1;
}
node* leftRotate(node *x)
{
	node *y = x->right;
	node *z = y->left;

	y->left = x;
	x->right = z;

	updateHeight(x);
	updateHeight(y);

	return y;
}
node* rightRotate(node *y)
{
	node *x = y->left;
	node *z = x->right;

	x->right = y;
	y->left = z;

	updateHeight(y);
	updateHeight(x);

	return x;
}
int getBalance(node *node)
{
	if (node == NULL)
		return 0;
	return  height(node->left) - height(node->right);
}
node* insert(node *node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);

	else
		node->right = insert(node->right, key);

	updateHeight(node);

	int balance = getBalance(node);
	// LL 
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	// RR
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	// LR
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// RL 
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}
node* search(node *root, int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return search(root->right, key);

	if (root->key > key)
		return search(root->left, key);
}
node* minValueNode(node *N)
{
	node *p = N;
	while (p->left != NULL)
		p = p->left;
	return p;
}
node* deleteNode(node* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL)
		{
			node *tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL)
		{
			node *tmp = root->left;
			free(root);
			return tmp;
		}
		node* tmp = minValueNode(root->right);

		root->key = tmp->key;

		root->right = deleteNode(root->right, tmp->key);
	}
	return root;
}