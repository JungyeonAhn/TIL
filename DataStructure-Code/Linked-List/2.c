#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *link;
    int coef,expo;
}node;

typedef struct linkedlist{
    node *head;
}linkedList;

linkedList* createList(void);
void freeList(linkedList *L);
void addNode(linkedList *L,int c,int e);
void deleteNode(linkedList *L);
void print(linkedList *L);
linkedList* addPoly(linkedList *A, linkedList *B);

linkedList* createList(void){
    linkedList *L= (linkedList*)malloc(sizeof(linkedList));
    L->head=NULL;
    return L;
}
void freeList(linkedList *L){
    node *p=L->head;
    while(p!= NULL){
        L->head = L->head->link;
        free(p);
        p=L->head;
    }
}

void addNode(linkedList *L,int c,int e)
{
    node *newnode=(node*)malloc(sizeof(node*));
    node *p;
    newnode->coef=c;
    newnode->expo=e;
    newnode->link=NULL;
    if(L->head==NULL){
        L->head=newnode;
        return;
    }
    p=L->head;
    while(p->link!=NULL)
        p=p->link;
    p->link=newnode;
}
linkedList* addPoly(linkedList *A, linkedList *B){
    linkedList *C=createList();
    node *result=(node*)malloc(sizeof(node*));
    node *p=A->head,*q=B->head,*r=NULL;
    int sum;
    while(p!=NULL && q!=NULL){
        if(p->expo > q->expo){
            addNode(C, p->coef, p->expo);
            p=p->link;
        }
        else if(p->expo < q->expo){
            addNode(C, q->coef, q->expo);
            q=q->link;
        }
        else{
            sum=p->coef+q->coef;
            if(sum!=0)
                addNode(C, sum, p->expo);
            p=p->link;
            q=q->link;
        }
    }
    while(p!=NULL){
        addNode(C, p->coef, p->expo);
        p=p->link;
    }
    while(q!=NULL){
        addNode(C, q->coef, q->expo);
        q=q->link;
    }
    return C;
}

void print(linkedList *L)
{
    node *p=L->head;
    while(p!=NULL){
        printf(" %d %d",p->coef,p->expo);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    linkedList *A=createList();
    linkedList *B=createList();
    linkedList *C=createList();
    int a,b,c,e,i;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d%d",&c,&e);
        addNode(A,c,e);
    }
    
    scanf("%d",&b);
    for(i=0;i<b;i++){
        scanf("%d%d",&c,&e);
        addNode(B,c,e);
    }
  
    C=addPoly(A, B);
    print(C);

}
