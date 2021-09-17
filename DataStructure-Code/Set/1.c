#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct linkedlist{
    node *head;
}linkedlist;

linkedlist* creatLinkedList(){
    linkedlist *L=(linkedlist*)malloc(sizeof(linkedlist));
    L->head=NULL;
    return L;
}

void addNode(linkedlist *L,int x){
    node *newnode=(node*)malloc(sizeof(node));
    node *pre=L->head;
    newnode->data=x;
    newnode->link=NULL;
    if(L->head==NULL){
        L->head=newnode;
        return;
    }
    while(pre->link!=NULL)
        pre=pre->link;
    pre->link=newnode;
}

int subset(linkedlist *A, linkedlist *B){
    node *p=A->head,*q=B->head;
    
    while(q!=NULL && p!=NULL){
        if(p->data == q->data){
            p=p->link;
            q=q->link;
        }
        else
            q=q->link;
    }
    if(p==NULL)
        return 0;
    else
        return p->data;
}

int main(){
    linkedlist *A = creatLinkedList();
    linkedlist *B = creatLinkedList();
    int a,b,i,x;
    
    scanf("%d",&a);
    
    for(i=0;i<a;i++){
        scanf("%d",&x);
        addNode(A, x);
    }
    
    scanf("%d",&b);
    
    for(i=0;i<b;i++){
        scanf("%d",&x);
        addNode(B, x);
    }
    
    printf("%d\n",subset(A,B));
}
