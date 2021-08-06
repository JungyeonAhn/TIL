# 프로세스 동기화

여러 개의 프로세스가 공유 데이터에 동시 접근한 경우, 예상치 못한 문제 혹은 결과가 발생할 수 있다.

Synchronization은 이러한 문제를 해결하기 위해 도입된 개념으로, 동시 접근을 아예 금지하거나 제약 조건을 둔다. 결과적으로 Data의 일관성을 보장한다.

- 생산자와 소비자 문제 예시
    - 생산자
        - 아이템 수를 나타내는 count값을 갖는다.
        - count = buffer size이면 바쁜 대기를 수행한다.
        - 여유 공간이 생기면 아이템을 생성하고 count를 1 증가시킨다.
    - 소비자
        - buffer에 아무런 데이터가 없으면 바쁜 대기를 수행한다.
        - buffer에 데이터가 존재하면 그 데이터를 소비하고 count를 1 감소시킨다.
    - 생산자와 소비자가 개별적으로 동작하면 적절하게 동작하지만, 병렬적으로 동작하는 경우 문제가 생긴다.
        - count의 값이 5일 때, 생산자와 소비자를 동시에 실행시킨다.
        - 동시에 실행이 완료되면 count가 4인지 6인지 보장할 수 없다.
        - 이러한 문제가 발생하는 이유는 두 프로세스가 동시에 조작할 수 있도록 허용했기 때문이다.

## 임계 구역(Critical Section)

멀티 프로세스 환경에서 둘 이상의 프로세스가 진입하면 안 되는 공유 자원의 코드 영역

### 임계구역 문제를 해결하는 3가지 조건

1. Mutual Exclusion(상호 배제)
    - 하나의 프로세스가 임계 구역을 점유하고 있으면 다른 프로세스는 임계 구역에 진입할 수 없다.
2. Progress(진행)
    - 임계구역에 접근한 프로세스가 없다면 어느 프로세스가 진입할 것인지 전략적으로 선택해야 한다.
3. Bounded Waiting(한정 대기)
    - 기아 상태를 방지하기 위해 한 번 진입했다가 나온 프로세스는 다음 진입에 제한을 둔다.

### Peterson's Algorithm

- 3가지 조건을 모두 만족하며 임계구역을 해결하는 알고리즘이다.

flag와 turn 변수를 사용한다.

- Process Pi, Pj

```java
int turn;// 진입 순번
boolean flag[2];// flag[i] : 진입 준비 완료do {
// entry section start
    flag[i] = true;
    turn = j;

while(flag[j] && turn == j);// Busy Waiting(바쁜 대기)// entry section end// exit section start
    flag[i] = false;
// exit section end

    remainder section
} whild(true);
```

- 바쁜 대기
    - 바쁜 대기는 두 개 이상의 프로세스나 스레드가 공유 자원에 대한 진입 권한을 얻고자 하는 동기화 상황에서 발생한다.
    - 바쁜 대기는 무한 루프를 돌며 CPU 자원을 쓸데없이 낭비한다.
    - 뮤텍스, 세마포어 기법을 사용하면 바쁜 대기를 사용하지 않을 수 있다.
    - 뮤텍스, 세마포어를 사용하기에는 오버헤드가 큰 상황이라면 바쁜 대기로 간단히 처리할 수 있다.

## 임계 구역 문제를 해결하는 알고리즘

### Mutex

Mutual Exclusion의 약자이다. mutex는 상호 배제를 수행하는 커널 모드의 동기화 객체를 말한다. 멀티 프로세스, 멀티 스레드 환경에서 공유 불가능한 자원의 동시 사용을 막는다.

**Mutex는 lock, unlock 연산으로 상호 배제를 구현한다.**

- lock
    - 임계 구역에 접근할 수 있는 권한을 부여한다.
    - 다른 프로세스가 임계 구역을 진입한 상태이면 종료할 때까지 대기한다.
- unlock
    - 임계 구역을 모두 사용했음을 알리고 임계 구역에 접근할 수 있는 권한을 반환한다.
    - 대기 중인 다른 프로세스가 임계 구역에 진입할 수 있게 된다.

        ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fb515113-ef73-43b1-a80c-fb76e5b6ff8b/스크린샷_2021-08-06_오후_6.21.38.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fb515113-ef73-43b1-a80c-fb76e5b6ff8b/스크린샷_2021-08-06_오후_6.21.38.png)

### Semaphore

두 개의 원자적인 함수로 제어되는 정수 변수를 활용하여 멀티 프로그래밍 환경에서 공유 자원에 대한 접근을 제어한다.* 정수 변수 S를 둔다. S는 자원의 개수이다.

- wait(), signal() 연산으로 접근한다.

```
wait(S) {
while(S <= 0)
        ;// busy waiting
    s--;
}

signal(S) {
    S++;
}
```

- Binary Semaphore
    - S의 값이 0과 1로 제한되는 세마포어로, 뮤텍스와 유사하게 동작한다.
    - 시스템에 따라서 뮤텍스 대신 이진 세마포어를 사용하기도 한다.
        - 상호 배제를 더 잘 보장한다.
- Counting Semaphore
    - 자원의 개수 S를 유한한 숫자로 설정한다.

### Semephore without busy waiting

바쁜 대기 대신 프로세스를 봉쇄하고 다시 깨우는 방법을 사용한다.

- 구현

```
typedefstruct {
int value;
structprocess *list;
}

voidwait(semaphore *S) {
    S->value--;
if(s->value < 0) {
        S->list.push(process)
        block();
    }
}

voidsignal(semaphore *S) {
    S->value++;
    process p = S.list.pop();
    wakeup(p);
}
```

block()은 프로세스를 중지시키고, wakeup은 봉쇄된 프로세스를 깨워서 다시 실행시킨다.

### 교착상태와 기아(Deadlock and Starvation)

- 교착 상태는 교착 상태 파일에 더 자세히 설명되어 있다.
- 아래 테이블은 교착 상황을 일으키는 예시이다.
    - 두 개의 프로세스 P0, P1이 존재한다.
    - 자원의 수가 1로 지정된 세마포어 S, Q가 있다.

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fb515113-ef73-43b1-a80c-fb76e5b6ff8b/스크린샷_2021-08-06_오후_6.21.38.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fb515113-ef73-43b1-a80c-fb76e5b6ff8b/스크린샷_2021-08-06_오후_6.21.38.png)

1. P1은 t0에서 `wait(Q)`를 호출했다. Q의 자원 1개를 가져간다.
2. P0는 t1에서 `wait(Q)`를 호출했다. 그러나 P1이 이미 자원을 가져간 상황이므로 할당할 수 없다.
    - t2에서 P1이 Q 자원을 방출해야 P0에서 Q를 사용할 수 있다.

## 고전적인 동기화 문제 3선

이 문제들을 해결하기 위해 세마포어나 뮤텍스가 사용된다.

### 유한 버퍼 문제(The Bounded-Buffer Problem)

- 공유 데이터

```
int n;
semaphore metux = 1;
semaphore empty = n;
semaphore full = 0;
```

- 생산자 프로세스의 구조

```
do {
    ...
//produce an item in nextp
    ...
    wait(empty);
    wait(mutex);
    ...
// add nextp to buffer
    ...
    signal(mutex);
    signal(full);
}while (true);
```

- 소비자 프로세스의 구조

```
do {
    wait(full);
    wait(mutex);
    ...
// remove an item from buffer to nextc
    ...
    signal(mutex);
    signal(empty);
    ...
// consume the item in nextc
    ...
}while (true);
```

- mutex 세마포어는 상호 배제 기능을 제공하며 1로 초기화되어 있다.
- empty는 빈 버퍼의 수이며 n으로 초기화된다.
- full은 꽉 찬 버퍼의 수이며 0으로 초기화된다.

**생산자는 꽉 찬 버퍼를 생산하고, 소비자는 빈 버퍼를 생산한다.**

### Readers-Writers 문제

- 사전 정의
    - 하나의 DB가 모든 작업에 사용할 수 있도록 공유되어 있다.
    - readers는 DB를 읽는 작업을 수행한다.
    - writers는 DB에 쓰는 작업을 수행한다.
- 둘 이상의 reader가 공유 데이터에 동시에 접근해도 문제되지 않는다.
- 그러나, writer가 접근하고 있는 데이터에 다른 프로세스(writer, reader)가 *동시에 접근*하면 문제가 발생한다.

**이 문제를 해결하기 위해 공유 DB에 배타적 접근 권한을 부여해야 한다.**

아래는 두 가지 해결책이다.

1. writer가 공유 객체를 사용할 권한을 얻지 못했다면 다른 reader를 기다리게 하면 안 된다.
    - writer에서 기아가 발생할 수 있다.
2. writer가 준비되면 가능한 빠르게 쓰기 작업을 수행할 것을 요구한다. 쓰기 작업이 진행 중이면 reader가 접근하지 못하기 때문이다.
    - reader에서 기아가 발생할 수 있다.
- 1번에 대한 해결책
    - reader는 아래의 자료 구조를 공유한다.

```
semaphore rw_mutex = 1;// writer, reader가 같이 사용
semaphore mutex = 1;// read_count 갱신 시 상호배제 보장int read_count = 0;// 몇 개의 프로세스가 이 객체를 읽고 있는지
```

* writer 구조

```
do {
    wait(rw_mutex);
    ...
// writing is performed
    ...
    signal(rw_mutex);
}while (true);
```

* reader 구조

```
do {
    wait(mutex);
    read_count++;
if (read_count == 1) {
        wait(rw_mutex);
    }
    signal(mutex);
    ...
// reading is performed
    ...
    wait(mutex);
    read_count--;
if(read_count == 0) {
        signal(rw_mutex);
    }
    signal(mutex);
}while (true);
```

### 식사하는 철학자들 문제(The Dining-Philosophers Problems)

가장 유명한 동기화 문제로, 병행 제어의 예시이다.

- 사전 정의
    - 5명의 철학자가 원탁에 앉아 있다.
    - 원탁의 중앙에는 식사가 담겨 있는 큰 그릇이 놓여 있다.
    - 각 철학자 앞에는 식사를 담아 먹을 조그만 그릇이 놓여 있다.
    - 각 철학자 사이에는 포크가 1개씩, 총 5개 놓여 있다.
    - 철학자는 포크를 양 손에 한 개씩 쥐었을 때 식사를 시작한다.
    - 철학자들은 평화주의자이기 때문에 다른 사람이 쥔 포크를 강제로 빼앗지 않는다.
    - 식사를 마치면 양 손의 포크를 내려놓는다.
- 공유 데이터

    ```
    semaphore fork[5];
    ```

- 철학자 i의 구조

```
do {
    wait(fork[i]);
    wait(fork[(i + 1) % 5]);
    ...
// eat
    ...
    signal(fork[i]);
    signal(fork[(i + 1) % 5]);
}while (true);
```

- 위의 소스 코드는 철학자들이 동시에 식사하지 않게 보장한다. **그러나 교착 상태를 일으킬 가능성을 내재한다.**
    1. 5명의 철학자가 동시에 식사를 시작하는 과정을 가정한다.
    2. fork[i]가 왼쪽 포크라면, 모두 왼쪽 포크를 든 채로 오른쪽 포크를 기다리게 된다.

교착 상태를 해결하기 위해 교착 상태를 일으키는 4가지 조건을 깨뜨려야 한다.

- 교착 상태 해결 방법
    1. 각 철학자가 포크를 양 손에 들 수 없는 상황이면 애초에 쥐지 않도록 처리한다.
        - 1개의 포크로는 아무런 의미가 없기 때문이다.
    2. 철학자들이 포크를 잡을 때의 일정한 방향성을 제거한다.
        - 홀수번째 철학자는 왼쪽부터 포크를 쥔다.
        - 짝수번째 철학자는 오른쪽부터 포크를 쥔다.
    3. 포크의 수를 늘리거나 철학자의 수를 줄인다.
    4. 포크를 뺏을 수 있도록 철학자의 폭력성을 증가시킨다.
