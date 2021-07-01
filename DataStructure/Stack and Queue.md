## Stack and Queue
### Stack

![](https://images.velog.io/images/yeonns2/post/dc9a8b0c-8433-4230-ae35-3bc48e08595c/image.png)

 - stack 의 개념
    
    한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Last in First out) 형식의 선형 자료구조

- Stack 의 연산
    
    스택은 LIFO를 따른다. 즉, 가장 최근에 스택에 추가한 항목이 가장 먼저 삭제될 항목이다.
    
    - pop(): 스택에서 가장 위에 있는 항목을 삭제
    - push(item): item 하나를 스택의 가장 윗 부분에 추가
    - peek(): 스택의 가장 위에 있는 항목을 반환
    - isEmpty(): 스택이 비어 있을 때에 true를 반환


push 와 pop할 때는 해당 위치를 알고 있어야 하므로 기억하고 있는 '스택 포인터(sp)'가 필요함. 스택 포인터는 다음 값이 들어갈 위치를 가리키고 있음 (처음 기본값은 -1)



- Stack의 사용 사례
    
    재귀 알고리즘을 사용하는 경우 스택이 유용하다. 
    
    - 재귀 알고리즘
        - 재귀적으로 함수를 호출해야 하는 경우에 임시 데이터를 스택에 넣어준다.
        - 재귀함수를 빠져 나와 퇴각 검색(backtrack)을 할 때는 스택에 넣어 두었던 임시 데이터를 빼 줘야 한다.
        - 스택은 이런 일련의 행위를 직관적으로 가능하게 해 준다.
        - 또한 스택은 재귀 알고리즘을 반복적 형태(iterative)를 통해서 구현할 수 있게 해준다.
    - 웹 브라우저 방문기록 (뒤로가기)
    - 실행 취소 (undo)
    - 역순 문자열 만들기
    - 수식의 괄호 검사 (연산자 우선순위 표현을 위한 괄호 검사)
        - Ex) 올바른 괄호 문자열(VPS, Valid Parenthesis String) 판단하기
후위 표기법 계산
    

### code

#### sp 
```
private int sp = -1;
```
#### push
```
public void push(Object o) {
    if(isFull(o)) {
        return;
    }
    
    stack[++sp] = o;
}
```
#### pop
```
public Object pop() {
    
    if(isEmpty(sp)) {
        return null;
    }
    
    Object o = stack[sp--];
    return o;
    
}
```

#### isEmpty
```
private boolean isEmpty(int cnt) {
    return sp == -1 ? true : false; 
}
```

#### isFull
```
private boolean isFull(int cnt){
    return sp+1 == MAX_SIZE ? true : false;
}
```

---
### Queue

FIFO (First In First Out) : 먼저 들어간 것이 먼저 나옴

- 사용용도 : 버퍼, 마구 입력된 것을 처리하지 못하고 있는 상황, BFS
- 큐의 가장 첫 원소를 front, 끝 원소를 rear라고 부름
- 큐는 들어올 때 rear로 들어오지만, 나올 때는 front부터 빠지는 특성을 가짐
- 접근방법은 가장 첫 원소와 끝 원소로만 가능

- 큐의 연산 
    - 데이터 넣음 : enQueue()
    - 데이터 뺌 : deQueue()
    - 비어있는 지 확인 : isEmpty()
    - 꽉차있는 지 확인 : isFull

- 데이터를 넣고 뺄 때 해당 값의 위치를 기억해야 하는 front와 rear 포인터가 필요함. (스택에서 스택 포인터와 같은 역할)

    - front : deQueue 할 위치 기억
    - rear : enQueue 할 위치 기억

### code

#### 기본값
```
private int size = 0; 
private int rear = -1; 
private int front = -1;

Queue(int size) { 
    this.size = size;
    this.queue = new Object[size];
}

```

#### enqueue
```
public void enQueue(Object o) {
    
    if(isFull()) {
        return;
    }
    
    queue[++rear] = o;
}
```


#### dequeue
```
public Object deQueue(Object o) {
    
    if(isEmpty()) { 
        return null;
    }
    
    Object o = queue[front];
    queue[front++] = null;
    return o;
}
```

#### isEmpty
```
public boolean isEmpty() {
    return front == rear;
}
```



#### isFull 
```
public boolean isFull() {
    return (rear == queueSize-1);
}
```

 일반 큐의 단점 : 큐에 빈 메모리가 남아 있어도, 꽉 차있는것으로 판단할 수도 있음 (rear가 끝에 도달했을 때)


-> 이를 개선한 것이 **'원형 큐'**

</br>

### 원형 큐 

- 논리적으로 배열의 처음과 끝이 연결되어 있는 것으로 간주함!

- 원형 큐는 초기 공백 상태일 때 front와 rear가 0

- 공백, 포화 상태를 쉽게 구분하기 위해 자리 하나를 항상 비워둠

- (index + 1) % size로 순환시킨다


### code
#### 기본값
```
private int size = 0; 
private int rear = 0; 
private int front = 0;

Queue(int size) { 
    this.size = size;
    this.queue = new Object[size];
}

```

#### enqueue
```
public void enQueue(Object o) {
    
    if(isFull()) {
        return;
    }
    
    rear = (++rear) % size;
    queue[rear] = o;
}
```


#### dequeue
```
public Object deQueue(Object o) {
    
    if(isEmpty()) { 
        return null;
    }

    front = (++front) % size;
    Object o = queue[front];
    return o;
}
```

#### isEmpty
```
public boolean isEmpty() {
    return front == rear;
}
```



#### isFull 
```
public boolean isFull() {
    return ((rear+1)% size == front);
}
```

- 원형 큐의 단점 : 메모리 공간은 잘 활용하지만, 배열로 구현되어 있기 때문에 큐의 크기가 제한  
    -> 이를 개선한 것이 '연결리스트 큐'

</br>

### 연결리스트 큐

- 연결리스트 큐는 크기가 제한이 없고 삽입, 삭제가 편리

### code

#### enqueue 구현
```
public void enqueue(E item) {
    Node oldlast = tail; // 기존의 tail 임시 저장
    tail = new Node; // 새로운 tail 생성
    tail.item = item;
    tail.next = null;
    if(isEmpty()) head = tail; // 큐가 비어있으면 head와 tail 모두 같은 노드 가리킴
    else oldlast.next = tail; // 비어있지 않으면 기존 tail의 next = 새로운 tail로 설정
}
```
- 데이터 추가는 끝 부분인 tail에 한다.
- 기존의 tail는 보관하고, 새로운 tail 생성
- 큐가 비었으면 head = tail를 통해 둘이 같은 노드를 가리키도록 한다.
- 큐가 비어있지 않으면, 기존 tail의 next에 새로만든 tail를 설정해준다.


#### dequeue 구현
```
public T dequeue() {
    // 비어있으면
    if(isEmpty()) {
        tail = head;
        return null;
    }
    // 비어있지 않으면
    else {
        T item = head.item; // 빼낼 현재 front 값 저장
        head = head.next; // front를 다음 노드로 설정
        return item;
    }
}
```

- 데이터는 head로부터 꺼낸다. (가장 먼저 들어온 것부터 빼야하므로)
- head의 데이터를 미리 저장해둔다.
- 기존의 head를 그 다음 노드의 head로 설정한다.
- 저장해둔 데이터를 return 해서 값을 빼온다.

이처럼 삽입은 tail, 제거는 head로 하면서 삽입/삭제를 스택처럼 O(1)에 가능하도록 구현이 가능하다.
