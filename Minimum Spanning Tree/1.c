#include <stdio.h>
#include <stdlib.h>

//정점 구조체
typedef struct vertices{
    int key;
    int pre;
}V;

//우선순위 큐
typedef struct queue{
    int front;
    int *v;
    int rear;
}Qu;

int **w;
V *v;
Qu Q;

//비어있는지 반환
int isEmpty() {
    return Q.front == Q.rear;
}

//큐에 삽입
void enqueue(int k){
    Q.v[Q.rear] = k;
    Q.rear++;
}

//treeSearch
int search(int k) {
    int i;
    for(i= Q.front; i< Q.rear; i++) {//처음부터 탐색
        if(Q.v[i] == k)
        	return 1;
    }
    return 0;
}


int getmin() {
    int i, j;
    int key;

    for(i=Q.front+1; i<Q.rear; i++) {
        key = Q.v[i];
        j = i;
        while((--j >= Q.front) && (v[key].key < v[Q.v[j]].key)) {
            Q.v[j+1] = Q.v[j];
        }
        Q.v[j+1] = key;
    }

    return Q.v[Q.front++];
}

//PrimJarnik알고리즘
void PrimJarnik(int n) {
    int i, u;
    int total = 0;

    for(i = 0 ; i < n; i++){//초기화
        v[i].key = 9999;
        v[i].pre = -9999;
        enqueue(i);
    }

    v[0].key = 0;//초기화

    while(isEmpty() != 1){//비어있지 않으면

        u = getmin();//getmin함수 호출
        printf(" %d", u+1);//print

        for(i = 0 ; i < n; i ++) {

            if(w[u][i] != 0) {
                if(search(i) && (w[u][i] < v[i].key)) {
                    v[i].key = w[u][i];
                    v[i].pre = u;
                }
            }

        }
    }

	//MST의 총무게를 total에 저장
    for(i = 1 ; i < n ; i ++){
    	total += v[i].key;
    }
    printf("\n%d", total);
}

int main() {
    int n, m;//n=정점m=간선
    int end1, end2, weight;//양끝 정점2개, 무게
    int i, j;

    scanf("%d %d", &n, &m);

    w = (int**)malloc(n*sizeof(int*));//동적할당

    for(i=0; i<n; i++) {
        w[i] = (int*)malloc(n*sizeof(int));
    }

    v = (V*)malloc(n*sizeof(V));
    Q.v = (int*)malloc(n*sizeof(int));
    
    for(i = 0 ; i < m; i ++) {
        scanf("%d %d %d", &end1, &end2, &weight);

		//무게저장
        w[end1-1][end2-1] = weight;
        w[end2-1][end1-1] = weight;
    }

    PrimJarnik(n);//함수호출

    return 0;
}

