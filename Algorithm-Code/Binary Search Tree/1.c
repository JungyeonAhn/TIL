#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left, *right;
}node;
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
	return p;
}
node* insert(node *node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

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
node* minValueNode(node *node)
{
	struct node *p = node;

	while (p->left != NULL)
		p = p->left;

	return p;
}
node* deleteNode(struct node* root, int key)
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
		node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
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