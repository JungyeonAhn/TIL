# DataStructure

* [Array vs Linked List](#array-vs-linked-list)
* [Stack and Queue](#stack-and-queue)
* [Tree](#tree)
* [Binary Heap](#binary-heap)
* [Red Black Tree](#red-black-tree)
* [Hash Table](#hash-table)
* [Graph](#graph)


</br>
</br>

## Array vs Linked List

### Array

가장 기본적인 자료구조인 `Array` 자료구조는, 논리적 저장 순서와 물리적 저장 순서가 일치한다. 따라서 `인덱스`(index)로 해당 원소(element)에 접근할 수 있다. 그렇기 때문에 찾고자 하는 원소의 인덱스 값을 알고 있으면 `Big-O(1)`에 해당 원소로 접근할 수 있다. 즉 **random access** 가 가능하다는 장점이 있는 것이다.


하지만 삭제 또는 삽입의 과정에서는 해당 원소에 접근하여 작업을 완료한 뒤(O(1)), 또 한 가지의 작업을 추가적으로 해줘야 하기 때문에, 시간이 더 걸린다. 만약 배열의 원소 중 어느 원소를 삭제했다고 했을 때, 배열의 연속적인 특징이 깨지게 된다. 즉 빈 공간이 생기는 것이다. 따라서 삭제한 원소보다 큰 인덱스를 갖는 원소들을 `shift`해줘야 하는 비용(cost)이 발생하고 이 경우의 시간 복잡도는 O(n)가 된다. 그렇기 때문에 Array 자료구조에서 삭제 기능에 대한 time complexity 의 worst case 는 O(n)이 된다.

삽입의 경우도 마찬가지이다. 만약 첫번째 자리에 새로운 원소를 추가하고자 한다면 모든 원소들의 인덱스를 1 씩 shift 해줘야 하므로 이 경우도 O(n)의 시간을 요구하게 된다.

### Linked List

이 부분에 대한 문제점을 해결하기 위한 자료구조가 linked list 이다. 각각의 원소들은 자기 자신 다음에 어떤 원소인지만을 기억하고 있다. 따라서 이 부분만 다른 값으로 바꿔주면 삭제와 삽입을 O(1) 만에 해결할 수 있는 것이다.

하지만 Linked List 역시 한 가지 문제가 있다. 원하는 위치에 삽입을 하고자 하면 원하는 위치를 Search 과정에 있어서 첫번째 원소부터 다 확인해봐야 한다는 것이다. Array 와는 달리 논리적 저장 순서와 물리적 저장 순서가 일치하지 않기 때문이다. 이것은 일단 삽입하고 정렬하는 것과 마찬가지이다. 이 과정 때문에, 어떠한 원소를 삭제 또는 추가하고자 했을 때, 그 원소를 찾기 위해서 O(n)의 시간이 추가적으로 발생하게 된다.

결국 linked list 자료구조는 search 에도 O(n)의 time complexity 를 갖고, 삽입, 삭제에 대해서도 O(n)의 time complexity 를 갖는다. 그렇다고 해서 아주 쓸모없는 자료구조는 아니기에, 우리가 학습하는 것이다. 이 Linked List 는 Tree 구조의 근간이 되는 자료구조이며, Tree 에서 사용되었을 때 그 유용성이 드러난다.

#### Personal Recommendation

* Array 를 기반으로한 Linked List 구현
* ArrayList 를 기반으로한 Linked List 구현

---

## Stack and Queue
### Stack

![](https://images.velog.io/images/yeonns2/post/dc9a8b0c-8433-4230-ae35-3bc48e08595c/image.png)

 - stack 의 개념
    
    한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Last in First out) 형식의 자료구조

- Stack 의 연산
    
    스택은 LIFO를 따른다. 즉, 가장 최근에 스택에 추가한 항목이 가장 먼저 삭제될 항목이다.
    
    - pop(): 스택에서 가장 위에 있는 항목을 삭제
    - push(item): item 하나를 스택의 가장 윗 부분에 추가
    - peek(): 스택의 가장 위에 있는 항목을 반환
    - isEmpty(): 스택이 비어 있을 때에 true를 반환

</br>

push 와 pop할 때는 해당 위치를 알고 있어야 하므로 기억하고 있는 '스택 포인터(sp)'가 필요함. 스택 포인터는 다음 값이 들어갈 위치를 가리키고 있음 (처음 기본값은 -1)

</br>


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
    

## code

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

