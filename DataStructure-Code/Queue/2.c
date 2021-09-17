#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int element;
    struct node *next;
    struct node *prev;
}node;

int dequeNumber;
node *deque, *rear, *front;

void delete_front(){
    node *p;
    if (dequeNumber == 0){
        printf("underflow\n");
        exit(1);
    }
    
    else{
        p = front;
        if (dequeNumber == 1){
            free(p);
        }
        else{
            front = front->next;
            front->prev = NULL;
            free(p);
        }
    }
}

void delete_rear(){
    node *p;
    if (dequeNumber == 0) {
        printf("underflow\n");
        exit(1);
    }
    
    else{
        p = rear;
        if (dequeNumber == 1){
            free(p);
        }
        
        else{
            rear = rear->prev;
            rear->next = NULL;
            free(p);
        }
    }
    
}

void add_front(int value){
    
    node *newnode = (node*)malloc(sizeof(node));
    newnode->element = value;
    newnode->prev = NULL;
    newnode->next = front;
    newnode->next->prev = newnode;
    front = newnode;
}

void add_rear(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->element = value;
    newnode->prev = rear;
    newnode->next = NULL;
    newnode->prev->next = newnode;
    rear = newnode;
}



void print(){
    node *p = front;
    while (p != NULL){
        printf(" %d", p->element);
        p = p->next;
    }
    printf("\n");
}


void freeDeque() {
    node *temp = front;
    while (temp != NULL) {
        front = front->next;
        free(temp);
        temp = front;
    }
}

int main(){
    int n, value;
    char str[5];
    dequeNumber = 0;
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++){
        scanf("%s", &str);
        getchar();
        
        if (strcmp(str, "AF") == 0){
            scanf("%d", &value);
            getchar();
            if (dequeNumber == 0){
                deque = (node*)malloc(sizeof(node));
                deque->element = value;
                deque->next = NULL;
                deque->prev = NULL;
                front = deque;
                rear = deque;
                dequeNumber++;
            }
            
            else{
                add_front(value);
                dequeNumber++;
            }
        }
        
        else if (strcmp(str, "AR") == 0){
            scanf("%d", &value);
            getchar();
            
            if (dequeNumber == 0) {
                deque = (node*)malloc(sizeof(node));
                deque->element = value;
                deque->next = NULL;
                deque->prev = NULL;
                front = deque;
                rear = deque;
                dequeNumber++;
            }
            
            else {
                add_rear(value);
                dequeNumber++;
            }
        }
        
        else if (strcmp(str, "DF") == 0){
            delete_front();
            dequeNumber--;
        }
        
        else if (strcmp(str, "DR") == 0){
            delete_rear();
            dequeNumber--;
        }
        
        else if (strcmp(str, "P") == 0){
            print();
        }
    }
    freeDeque();
    
}
