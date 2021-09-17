#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct linkedlist{
    node *head;
}linkedlist;

linkedlist* creatLinkedList()
{
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

void print(linkedlist *L){
    node *p=L->head;
    if(p==NULL){
        printf(" 0\n");
        return;
    }
    while(p!=NULL){
        printf(" %d",p->data);
        p=p->link;
    }
    printf("\n");
}

linkedlist* unionSet(linkedlist *A, linkedlist *B){
    linkedlist *U = creatLinkedList();
    node *p=A->head,*q=B->head;
    
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            addNode(U, p->data);
            p=p->link;
        }
        else if (p->data > q->data){
            addNode(U, q->data);
            q=q->link;
        }
        else{
            addNode(U, p->data);
            p=p->link;
            q=q->link;
        }
    }
    while(p!=NULL){
        addNode(U, p->data);
        p=p->link;
    }
    while(q!=NULL){
        addNode(U, q->data);
        q=q->link;
    }
    return U;
}
linkedlist* intersectSet(linkedlist *A, linkedlist *B){
    linkedlist *I = creatLinkedList();
    node *p=A->head,*q=B->head;
    
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            p=p->link;
        }
        else if (p->data > q->data){
            q=q->link;
        }
        else{
            addNode(I, p->data);
            p=p->link;
            q=q->link;
        }
    }
    return I;
}

int main(){
    linkedlist *A = creatLinkedList();
    linkedlist *B = creatLinkedList();
    linkedlist *U = creatLinkedList();
    linkedlist *I = creatLinkedList();
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
    
    U=unionSet(A, B);
    I=intersectSet(A, B);
    
    print(U);
    print(I);
    
}
