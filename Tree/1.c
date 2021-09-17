#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* makeRootNode(int data, Node* leftNode, Node* rightNode)
{
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void inorder(Node* root)
{
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void printNode(Node* node)
{
    if(node == NULL){
        printf("-1");
        return;
    }
    else{
        printf("%d ",node->data);
        if(node->left!=NULL)
            printf("%d ",node->left->data);
        if(node->right !=NULL)
            printf("%d ",node->right->data);
    }
}

int main()
{
    int n;
    Node* F[8]={NULL};
    F[7] = makeRootNode(80, NULL, NULL);
    F[6] = makeRootNode(130, NULL, NULL);
    F[5] = makeRootNode(120, F[6], F[7]);
    F[4] = makeRootNode(90, NULL, NULL);
    F[3] = makeRootNode(70, NULL, NULL);
    F[2] = makeRootNode(50, NULL, F[5]);
    F[1] = makeRootNode(30, F[3], F[4]);
    F[0] = makeRootNode(20, F[1], F[2]);
    
    scanf("%d",&n);
    
    if(n>8 || n<0)
        printf("-1\n");
    else
        printNode(F[n-1]);
    
    
    return 0;
}

