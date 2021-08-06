## Background

### 메모리 계층구조

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1101ab95-6fde-4f27-a075-f0420b024dbd/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1101ab95-6fde-4f27-a075-f0420b024dbd/Untitled.png)

### 메모리 전송 단위

- Block
    - 보조기억장치와 주기억장치 사이의 데이터 전송 단위
    - size : 1~4KB
- Word
    - 주기억장치와 레지스터 사이의 데이터 전송 단위
    - size : 16 ~ 64bits

### 메모리 구조

- 논리적 주소(=가상주소)
    - 코드가 저장된 공간과 프로그램에서 사용하는 자료구조.
- 물리적 주소
    - 적재하는 실제 주소. 메모리 칩이나 디스크 공간.
- 메모리 관리 장치(MMU)
    - `논리적 주소 -> 물리적 주소` 변환을 담당.

### Adress Binding

- 프로그램의 논리 주소를 실제 메모리의 물리주소로 매핑하는 작업
- Binding 시점에 따른 구분
    - Compile time binding : 컴파일할 때
    - Load time binding : 프로그램을 메모리로 올릴때
    - Run time binding : 실행 중 address 할당할 때

        ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/117c29f0-108a-46da-8e5c-3affa15c7c47/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/117c29f0-108a-46da-8e5c-3affa15c7c47/Untitled.png)

## 메모리 낭비 방지 기법

### Dynamic Loading

- 모든 루틴을 교체 가능한 형태로 디스크에 저장
- 실제 호출 전까지는 루틴을 적재하지 않음
    - 메인 프로그램만 메모리에 적재하여 수행
    - 루틴의 호출 시점에 address binding 수행
- 장점
    - 사용하지 않을 루틴은 메모리에 적재하지 않으므로 메모리를 매우 효율적으로 사용 가능

### Overlay

- 당장 필요하지 않는 프로그램의 일부를 중첩으로 설정하는 방식.
- 실행에 꼭 필요한 명령어와 데이터만 메모리에 적재하고 나머지는 메모리에 중첩영역을 따로 만들어 필요할 때 그 공간에 적재.

![https://media.vlpt.us/images/sawol/post/a878a81a-aae4-4145-85d3-1f8e03407673/image.png](https://media.vlpt.us/images/sawol/post/a878a81a-aae4-4145-85d3-1f8e03407673/image.png)

### Swapping

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d09b407e-12bb-4f33-aed1-7784842de045/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d09b407e-12bb-4f33-aed1-7784842de045/Untitled.png)

- 프로세서 할당이 끝나고 수행 완료된 프로세스는 swap-device로 보내고 (Swap-out)
- 새롭게 시작하는 프로세스는 메모리에 적재 (Swap-in)
- 디스크에 저장된 프로세스를 메모리로 올리고 메모리에 적재된 프로세스는 준비 큐에 대기시키는 중기 스케줄링에 해당됨
- 속도가 빠른 보조기억장치가 필요
- 항상 우선순위가 높은 프로세스 공간을 만들 수 있어 시스템에 유연성을 높임.
- 스와핑 불가
    - 컴파일 또는 적재 시간에 바인딩을 하면 프로세스를 보조 기억장치 등으로 이동할 수 없어 스와핑이 불가하다.
    - 입출력 버퍼가 사용자 메모리를 비동기적으로 엑세스하면 입출력 대기중이라도 스와핑을 할 수 없다.
- 스와핑 가능
    - 오직 실행 시간에 바인딩을 할 때 스와핑 가능하다.
    - 입출력 동작이 있는 프로세스는 스와핑 가능하다.

---

## 메모리 관리

- 모든 프로그램은 메모리에 적재가 되어야 실행이 가능
- 한정된 메모리를 여러 프로세스가 함께 효율적으로 사용하기 위해 메모리 관리 방법이 필요
- 메모리를 할당하고 제거하며 보호하는 활동을 메모리 관리라고 함

## 메모리 적재 방법

- 연속 메모리 적재
    - 가변 분할 : 각각의 프로세스가 메모리의 연속적인 공간에 적재되도록 하는 것
    - 고정 분할 : 각각의 프로세스가
- 비연속(분산) 메모리 적재
    - 가변 분할 : 세그먼테이션
    - 고정 분할 : 페이징

### 1. 연속 메모리 할당(Continuous Memory Allocation)

- 프로세스를 하나의 연속된 메모리 공간에 할당하는 정책
- 메모리 구성 정책이 필요
    - 메모리에 동시에 올라갈 수 있는 프로세스 수(multiprogramming degree)
    - 각 프로세스에게 할당되는 메모리 크기
    - 메모리 분할 방법

### Fixed Partition Multiprogramming(고정 분할 방식)

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/17bba02c-23f2-4fed-ab80-00f0ec457c07/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/17bba02c-23f2-4fed-ab80-00f0ec457c07/Untitled.png)

- 메모리 공간을 고정된 크기로 분할
    - 미리 분할되어있음
- 각 프로세스는 하나의 partition(분할)에 적재
    - Process:Partiton = 1:1
- Partition 의 수 = K
    - Multiprogramming degree = k
- 장점 : 메모리 관리가 간편함
- 단점 : Internal/external fragmentation

- **단편화(Fragmentation)**

    **내부 단편화(Internal fragmentation)**
    - 메모리 파티션의 크기 > 프로세스 크기메모리 남는 공간이 발생되어 메모리 낭비.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c1b5a86a-7ab9-48b0-84ca-656188b4297f/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c1b5a86a-7ab9-48b0-84ca-656188b4297f/Untitled.png)

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8581f1b7-f5e5-46b0-85c1-773ac4c13ee5/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8581f1b7-f5e5-46b0-85c1-773ac4c13ee5/Untitled.png)

    **외부 단편화(External fragmentation)**
    - 남은 메모리 크기(연속된 공간 아님) > 프로세스 크기
    - 연속된 메모리 공간이 아니므로 프로세스에게 메모리를 할당 하지 못함. 메모리에 남는 공간이 있지만 사용하지 못하므로 메모리 낭비

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/437c8ab2-ef40-41f0-8ff0-359bd606d26e/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/437c8ab2-ef40-41f0-8ff0-359bd606d26e/Untitled.png)

### Variable Partition Multiprogramming(다중 분할 방식)

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/34c1b7d8-b5de-4051-a241-399a5493bc76/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/34c1b7d8-b5de-4051-a241-399a5493bc76/Untitled.png)

- 초기에는 전체가 하나의 영역
- 프로세스를 처리하는 과정에서 메모리 공간이 동적으로 분할
- No internal fragmentation
- 프로세스를 어디에 배치해야하는가에 대한 문제가 생김
    - 배치 전략 (placement strategies)

        **최초적합 방법(first-fit)**

        - 충분히 큰 첫번째 공간에 할당.
        - 공간 활용률이 떨어짐.
        - 오버헤드가 낮음

        **최적적합 방법(best-fit)**

        - 프로세스가 들어갈 수 있는 공간 중 가장 작은 공간.
        - 크기 순으로 정렬되어 있지 않으면 전체를 검색해야함.(오버헤드가 큼)
        - 공간 활용률은 높으나 할당하기 위해 많은 시간이 소요.
        - 작은 크기의 파티션이 많이 발생함

        **최악적합 방법(worst-fit)**

        - 가장 큰 사용 가능 공간에 할당.
        - 최적적합과 마찬가지로 정렬되어 있지 않으면 전체를 검색해야함.
        - 작은 크기의 파티션의 발생을 줄일 수 있음큰 크기의 파티션을 확보하기 힘듦

        **순차 최초적합 방법(Next-fit)**

        - 최초 적합 전략과 유사
        - 마지막으로 탐색한 위치부터 탐색
        - 메모리 영역의 사용빈도 균등화
        - 낮은 오버헤드
- External fragmentation 발생

## External fragmentation 해결 방법

### Coalescing Holes (메모리 통합 방법)

- 인접한 빈 영역을 하나의 partition으로 통합
    - process가 memory를 release하고 나가면 수행
    - 낮은 오버헤드
- external fragmentation 문제를 해결

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f22bddd6-3c1e-49a6-becf-fbb0cc7e6ca1/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f22bddd6-3c1e-49a6-becf-fbb0cc7e6ca1/Untitled.png)

### Storage Compaction(메모리 압축)

- 모든 빈 공간을 하나로 통합
- 프로세스 처리에 필요한 적재 공간 확보가 필요할 때 수행
- 높은 오버해드
    - 모든 process 재배치 (process 중지)
    - 많은 시스템 자원을 소비

        ![https://media.vlpt.us/images/sawol/post/c13adce9-afa7-4be2-984b-5a1df6a59854/image.png](https://media.vlpt.us/images/sawol/post/c13adce9-afa7-4be2-984b-5a1df6a59854/image.png)

## 2. Non-contiguous allocation 분산 메모리 할당

하나의 프로세스가 메모리의 여러 영역에 분산되어 올라갈 수 있음

- paging : process의 virtual memory를 동일한 page로 나누어 물리 메모리에 올림
- segmentation : process의 virtual memory를 segment단위(code, data...)로 물리 메모리에 올림
- paged segmentation : page와 segmentation을 혼용한 방법

### **Paging**

- **페이지(page)**
    - logical memory를 block으로 잘랐을 때 하나의 블록을 page라고 함(프로세스)
- **프레임(frame)**
    - physical memory는 fixed - sized block(고정된 크기의 블록)으로 나눈 것을 프레임이라고 함
- 페이지와 프레임은 크기가 같음
- 페이징 기법은 페이지 테이블을 사용하여 page number가 있는 logical address를 -> frame 넘버가 있는 physical address로 바꿈

![https://images.velog.io/images/nnnyeong/post/55d02938-84d6-4ac4-addd-9dc195515e9c/image.png](https://images.velog.io/images/nnnyeong/post/55d02938-84d6-4ac4-addd-9dc195515e9c/image.png)

- 할당은 항상 프레임의 정수 배로 할당되는데, 이 때 프로세스가 페이지 경계와 일치하지 않는 크기의 메모리를 요구하게 되면 마지막 페이지 프레임은 전부 사용되지 않고 남아버리는 문제가 발생한다. → **internal fragmentation**

### Segmentation

- 프로세스와 물리 메모리를 세그먼트로 분할
    - Segment : 서로 다른 크기의 논리적 단위.
    - 페이지 같은 개념이지만, 프로세스를 **논리적 내용을 기반으로 나눠서** 메모리에 배치
- 세그먼트 테이블에는 각 세그먼트의 기준(base: 세그먼트의 시작 물리 주소)과 한계(limit: 세그먼트의 최대 길이)를 저장
- 세그먼트들이 적재,제거 되는 일이 반복되면 자유 공간들이 많은 수의 작은 조각들로 나뉘어져 못쓰게 될 수 있음 (외부 단편화)
- 프로세스를 Code, Data, Stack으로 나누는 것 역시 세그멘테이션!

![https://images.velog.io/images/nnnyeong/post/e5f07c87-9e6e-4c8f-90c9-9c92920ab486/image.png](https://images.velog.io/images/nnnyeong/post/e5f07c87-9e6e-4c8f-90c9-9c92920ab486/image.png)

- CPU에서 해당 세그먼트의 크기를 넘어서는 주소가 들어오면 인터럽트가 발생해서 해당 프로세스를 강제로 종료
