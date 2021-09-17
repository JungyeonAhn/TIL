#include <stdio.h>
#include <stdlib.h>

int rear,front,size;

void print(int* Q){
    for(int i=0;i<size;i++){
        printf(" %d",Q[i]);
    }
    printf("\n");
}

void enqueue(int* Q,int data){
    if((rear+1) % size == front){ //포화상태
        printf("overflow");
        print(Q);
        exit(1);
    }
    rear=(rear+1)%size;
    Q[rear]=data;
}
void dequeue(int* Q){
    if(front == rear){    //공백상태
        printf("underflow\n");
       exit(1);
    }
    front=(front+1) % size;
    Q[front]=0;
}

int main(){
    int q,n,i,data;
    char c;
    int *Q;
    scanf("%d%d",&q,&n);
    size=q;
    Q=(int*)malloc(sizeof(int)*size);
    rear=front=0;
    
    for(i=0;i<size;i++)
        Q[i]=0;
    
    for(i=0;i<n;i++){
        getchar();
        scanf("%c",&c);
        switch (c) {
            case 'I':
                scanf("%d",&data);
                enqueue(Q, data);
                break;
            case 'D':
                dequeue(Q);
                break;
            case 'P':
                print(Q);
                break;
            default:
                break;
        }
    }
    
}


