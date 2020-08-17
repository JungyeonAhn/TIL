#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char elem;
    struct Node *prev, *next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void addNode(linkedList_h* L,int r,char x);
void deleteNode(linkedList_h* L,int r);
void get(linkedList_h* L,int r);
void print(linkedList_h* L);

linkedList_h* createLinkedList_h(){
    linkedList_h *L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = (Node*)malloc(sizeof(Node));
    L->tail = (Node*)malloc(sizeof(Node));
    L->head->next = L->tail;
    L->tail->prev = L->head;
    return L;
}
void addNode(linkedList_h* L,int r,char x)
{
    int i;
    Node *pre, *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->elem = x;
    pre=L->head;
    
    for(i=1;i<r;i++)
    {
        pre=pre->next;
        if(pre == L->tail)
        {
            printf("invalid position\n");
            free(newnode);
            return;
        }
    }
    newnode->prev = pre;
    newnode->next = pre->next;
    pre->next = newnode;
    newnode->next->prev = newnode;
}

void deleteNode(linkedList_h* L,int r)
{
    int i;
    Node *pre = L->head;
    
    for(i=0;i<r;i++)
    {
        pre=pre->next;
        if(pre == L->tail)
        {
            printf("invalid position\n");
            return;
        }
    }
    
    pre->prev->next = pre->next;
    pre->next->prev = pre->prev;
    free(pre);
}

void get(linkedList_h* L,int r)
{
    int i;
    Node *pre=L->head;
    
    for(i=0;i<r;i++)
    {
        pre=pre->next;
        if(pre == L->tail)
        {
            printf("invalid position\n");
            return;
        }
    }
    printf("%c\n",pre->elem);
    
}

void print(linkedList_h* L)
{
    int i;
    Node *pre = L->head->next;
    
    while(pre != L->tail)
    {
        printf("%c",pre->elem);
        pre=pre->next;
    }
    printf("\n");
}

int main()
{
    linkedList_h* L;
    int n,i,r;
    char c,x;
    
    L = createLinkedList_h();
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        getchar();
        scanf("%c",&c);
        switch (c) {
            case 'A':
                scanf("%d",&r);
                getchar();
                scanf("%c",&x);
                addNode(L, r, x);
                break;
            case 'D':
                scanf("%d",&r);
                deleteNode(L, r);
                break;
            case 'G':
                scanf("%d",&r);
                get(L, r);
                break;
            case 'P':
                print(L);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
