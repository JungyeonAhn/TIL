## 1. 해시 테이블(Hash Table)
해시 테이블(Hash Table)이란 키(Key)에 데이터(Value)를 저장하는 자료구조를 말한다. 해시 테이블(Hash Table)의 예로 파이썬의 딕셔너리(Dictionary) 타입이 있다. 보통 배열(Array)로 미리 해시 테이블 사이즈만큼 생성한 후에 사용한다.

### 용어 정리
- 해시 테이블(Hash Table)은 해시 함수(Hash function)을 사용하여 색인(index)을 버킷(bucket)이나 슬롯(slot)의 배열로 계산한다.

- 키(key) 
    
    해시 함수(Hash Function)의 인풋(input)이 된다.

- 해시(Hash) 
    
    임의의 값을 고정 길이로 변환하는 것을 말한다.

- 해시 테이블(Hash Table) 
    
    키(Key)의 연산에 의해 직접 접근이 가능한 자료구조이다.

- 해시 함수(Hash Function) 또는 해싱 함수(Hashing function) 

    키(Key)에 대해 산술 연산을 이용해 데이터(Value)의 위치를 찾을 수 있는 함수이다.

- 해시 값(Hash Value) 또는 해시 주소(Hash Address) 

    키(Key)를 해싱 함수로 연산해서 해시 값(Hash Value) 또는 해시 주소(Hash Address)를 알아내고 이를 기반으로 해시 테이블(Hash Table)에서 해당 키(Key)에 대한 데이터 위치를 일관성 있게 찾을 수 있다.

- 슬롯(Slot) 또는 버킷(Bucket) 
    
    한 개의 데이터(Value)를 저장할 수 있는 공간이다. 저장할 데이터(Value)에 대해 키(Key)를 추출할 수 있는 별도의 함수도 존재할 수 있다.

</br>


## 2. 해시 테이블(Hash Table)의 장점과 단점
해시 테이블(Hash Table)의 장점은 데이터 저장 및 읽기 속도가 빠르다. 즉 검색 속도가 빠르다. 해시는 키에 대한 데이터가 있는지 확인이 쉽다. 단점은 일반적으로 저장 공간이 더 많이 필요하다. 여러 키에 해당하는 주소가 동일할 경우 충돌(Collision)을 해결하기 위한 별도의 자료구조가 필요하다.

</br>

## 3.  충돌(Collision) 해결 알고리즘
해시 함수가 서로 다른 두 개의 입력값에 대해 동일한 출력값을 내는 상황이 발생하는데 이러한 문제를 충돌(Collision) 또는 해쉬 충돌(Hash Collision)이라고 부른다.

충돌 문제를 해결하는 큰 전략으로 오픈 해싱(Open Hashing)과 클로즈 해싱(Close Hashing)이 있다. 오픈 해싱(Open Hashing)은 해시 충돌이 발생했을 때 충돌이 발생한 데이터에 대해서는 해시 테이블 밖에 추가적인 데이터 공간을 확보해서 해결하는 방법을 말한다. 클로즈 해싱(Close Hashing)은 해시 테이블의 빈 공간을 찾아 그 공간에 데이터를 저장하는 것을 말한다.



### 1. Chaining 기법
오픈 해싱(Open Hashing) 기법 중 하나로 해시 테이블의 저장 공간 외의 공간을 활용하는 기법이다. 충돌이 일어나면 링크드 리스트(Linked List) 자료 구조를 사용해서 데이터를 추가로 뒤에 연결시켜서 저장하는 기법이다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d0/Hash_table_5_0_1_1_1_1_1_LL.svg/900px-Hash_table_5_0_1_1_1_1_1_LL.svg.png)


### 2. Linear Probing 기법
클로즈 해싱(Close Hashing) 기법 중 하나로 해시 데이블의 저장 공간 안에서 충돌 문제를 해결하는 기법이다. 충돌이 일어나면 해당 해시 주소(hash address)의 다음 주소부터 확인하여 처음으로 나오는 빈 공간에 데이터를 저장하는 기법이다. 이 기법은 저장공간의 활용도를 높이기 위함이다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/9/90/HASHTB12.svg/2880px-HASHTB12.svg.png)



### 3. 빈번한 충돌을 개선하는 기법
해시 함수를 재정의 및 해시 테이블의 저장공간을 확대한다.
해시 테이블의 시간 복잡도(Time Complexity)
충돌(Collision)이 없는 일반적인 경우의 시간 복잡도는 O(1)이다. 최악의 경우 충돌(Collision)이 모두 발생하는데 이 때의 시간 복잡도는 O(n)이다. 해시 테이블은 일반적인 경우를 기대하고 만들기 때문에 시간 복잡도는 O(1)이라고 말할 수 있다.

</br>

## 4.해시 테이블의 시간 복잡도(Time Complexity)
충돌(Collision)이 없는 일반적인 경우의 시간 복잡도는 O(1)이다. 최악의 경우 충돌(Collision)이 모두 발생하는데 이 때의 시간 복잡도는 O(n)이다. 해시 테이블은 일반적인 경우를 기대하고 만들기 때문에 시간 복잡도는 O(1)이라고 말할 수 있다.