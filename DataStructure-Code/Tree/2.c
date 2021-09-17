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
void preorder1(Node* root)
{
    if(root!=NULL){
        printf("%d ", root->data);
        preorder1(root->left);
        preorder1(root->right);
    }
}
void inorder(Node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder1(Node* root)
{
    if(root!=NULL){
        postorder1(root->left);
        postorder1(root->right);
        printf("%d ", root->data);
    }
}
void printNode(Node* node)
{
    if(node == NULL){
        printf("-1\n");
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
    int n, i;
    Node* F[8]={NULL};
    F[7] = makeRootNode(80, NULL, NULL);
    F[6] = makeRootNode(130, NULL, NULL);
    F[5] = makeRootNode(120, F[6], F[7]);
    F[4] = makeRootNode(90, NULL, NULL);
    F[3] = makeRootNode(70, NULL, NULL);
    F[2] = makeRootNode(50, NULL, F[5]);
    F[1] = makeRootNode(30, F[3], F[4]);
    F[0] = makeRootNode(20, F[1], F[2]);
    
    scanf("%d %d",&n,&i);
    
    if(i<9){
        if(n==1)
            preorder1(F[i-1]);
        if(n==2)
            inorder(F[i-1]);
        if(n==3)
            postorder1(F[i-1]);
        printf("\n");
    }
    else
        printf("-1\n");
    
    return 0;
}

