# Red Black Tree
BST (이진 탐색 트리)를 기반으로 둔 Tree. 
BST의 삽입,삭제 연산과정에서 발생할 수 잇는 문제점을 해결하기 위해 만드러진 자료구조

Tree의 Rebalancing 방법 중 하나로 balanced한 트리이다.

각 노드는 값(key)말고도 색을 갖고 있으며, 색은 레드 or 블랙 2종류다.

</br>

## 1. Red Black Tree 특성

---

**Root Property** : 루트(root)노드는 블랙(black)이다.

**External Property** : 모든 외부 노드 (external node)는 블랙이다.

**Depth Property** : 모든 단말 노드(leaf node)의 경우 루트부터 외부 노드 까지 방문하는 블랙 노드의 수가 같다.

**Internal Property** : 레드 노드의 자식은 블랙이다.== No Double Red : 레드 노드는 두개가 연속해서 올 수 없다.

</br>

## 2. 특징

---

- **`BST`**의 모든 특징을 갖는다.
- 노드의 자식이 없는 경우 자식을 가리키는 포인터는 NULL값을 저장 ( NULL을 **`leaf node`**라고 함)
- 루트 노드 부터 단말 노드(leaf node)까지 모든 경로 중 최소 경로와 최대 경로의 크기 비율은 2보다 크지 않다. ( **`balanced`** 상태 )
- **`AVL Tree`** 에 비해 탐색속도는 느릴 수 있으나, 삽입 / 삭제 속도는 더 빠르다.
- **`삽입`**, **`삭제`**, **`탐색`**의 시간복잡도는 **`O(log n)`**

</br>

## 3. 사용 예

---

- Java Collection의 ArrayList
- HashMap의 Separate Chaining
- C++ map

</br>

## 4. 해시와 비교해서 본 장점

---

- **`순서가 있는 자료`**일 경우 좋다. ( 해쉬는 순서가 없음 )
- **`일관성`**있는 퍼포먼스를 보여준다. ( 해쉬는 rehashing시 비정상적 시간이 걸릴 수 있음 )
- 연속된 삽입간의 공간 지역성을 유지하기 쉽다. ( 더 적은 I/O 발생 )
- 트리는 부정확한 검색에 사용될 수 있다.

</br>

## 5. 구현

---

### Insert (삽입)

1. BST의 특성을 유지하면서 노드를 삽입

2. 삽입된 노드를 red로 지정 : black-height를 최소화하기 위해서

3. RBT의 특성 위배시, 노드의 색깔을 조정한다

4. Black-Height가 위배되었을 경우, rotation을 통해 height 조정한다

### Delete (삭제)

1. BST의 특성을 유지하면서 노드를 삭제
2. 삭제될 노드의 child의 개수에 따라 rotation방법이 달라진다.

    2-1. 지워진 노드의 색깔이 black이라면 black-height가 1 감소한 경로에 black node가 1개 추가될도록 rotation하고 색깔을 조정한다.
    2-2. 지워진 노드의 색깔일 red라면 violation이 발생하지 않으므로 RBT가 그대로 유지한다.

### Search (탐색)

Red Black Tree는 BST의 일종이기 때문에 일반적인 Bianry Tree의 탐색 방법과 같음. 

- 찾는 값이 해당 노드보다 작다면 왼쪽으로 크다면 오른쪽으로 내려가며 값을 탐색

---

## 1. 삽입

### case 1 : z 삼촌이 레드 ➡ 색상 변환 ( Recoloring )

아래와 같은 트리에 5를 추가한다고 하자. 그러면 오른쪽 같이 될 것이다.

![https://gowoonsori.site/data-structure/tree/redblacktree/i1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i1.png?classes=shadow,border)

이는 leafnode부터 루트까지 black-height는 모두 동일 하나 **`double-red`**로 규칙에 위배가 된다. **`recoloring`**을 통해 색깔을 바꾸어 규칙을 만족시켜주어야 한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/i1-3.jpg?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i1-3.jpg?classes=shadow,border)

Recoloring을 통해 부모와 삼촌을 블랙으로 바꾸고 할아버지 노드를 레드로 바꾸고 할아버지를 z로 두고 루트이거나, case1조건을 위배 안 할때 까지 반복해주면 된다.

만일 root에 도달했다면, 빨간색으로 바뀐 root를 블랙으로 바꿔주면 이중 red는 해결이 된다.

![https://gowoonsori.site/data-structure/tree/redblacktree/i1-4.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i1-4.png?classes=shadow,border)

결국, 한 level이 red에서 black이 되었으므로, black-height는 1이 증가하게 된다.

### case 2 : z의 삼촌이 블랙 ➡ 회전 ( rotation , restructuring )

![https://gowoonsori.site/data-structure/tree/redblacktree/i2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2.png?classes=shadow,border)

위와 같은 트리에서 5를 삽입하려 할 때 삼촌이 블랙이면 (없어도 leafnode는 black) case1과 같이 recoloring은 black-height가 깨지기 때문에 다른 방법을 이용해야 한다. (recoloring시 왼쪽은 black-height가 2, 오른쪽은 black-height가 1)

이 때는, AVL Tree에서 썼던 **`rotate`**개념을 이용하여 트리의 구조를 바꿔 줌으로써, recoloring을 수행하여 double-red를 해결한다.

AVL-Tree와 같이 삽입한 노드 z가 왼쪽에 있냐, 오른쪽에 있냐에 따라 경우가 나뉘며, 왼쪽과, 오른쪽에 있는 방법은 **`서로 대칭`**이다.

### (1) L : 부모노드가 할아버지 노드의 왼쪽 노드일때

- **case 2-1 : z가 부모노드의 오른쪽 자식**

부모노드를 중심으로 왼쪽으로 회전시키고, 여전히 RBT특성을 위반하므로 case2- 2를 수행한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/i2-1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2-1.png?classes=shadow,border)

Case2는 삽입할 노드의 부모 노드는 자식을 2개를 갖고 있을 수 없기 때문에, rotate시에 문제없이 10이 부모 노드가 되면서 왼쪽자식으로 부모노드가 올 수 있다.

삼촌이 블랙이면, 무조건 부모는 red이어야 한다.(black-height를 만족시키기 위해)그때, 자식을 삽입시에 아래와 같은 case로 restructing이 일어나기 때문에 새로운 노드 삽입 시 case2의 경우에는 무조건 부모 노드는 하나의 자식을 갖는다.

이중 레드에, black-height가 여전히 다르고 현재 상태가 case2와 동일 하기 때문에 case2를 진행 하면 된다.

- **case 2-2 : z가 부모노드의 왼쪽 자식**

할아버지를 중심으로 오른쪽 회전시키고

![https://gowoonsori.site/data-structure/tree/redblacktree/i2-2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2-2.png?classes=shadow,border)

부모 노드는 블랙으로, 할아버지 노드는 레드로 서로 색상을 바꾼다.

![https://gowoonsori.site/data-structure/tree/redblacktree/i2-3.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2-3.png?classes=shadow,border)

이렇게 되면, 삽입한 z부터 할아버지 노드까지는 규칙에 위배되지 않으니, 할아버지 노드를 기준으로 다시 case에 위배 되지 않는지 검사하면서 root까지 검사하여 balancing을 해주면 된다.

### (2) R : 부모노드가 할아버지 노드의 오른쪽 노드일때

이 경우는 부모 노드가 할아버지 노드의 왼쪽 자식인 경우와 대칭으로 rotate 방향만 바꿔주면 방법은 동일하다.

- **case 2-1 : z가 부모노드의 왼쪽 자식**

![https://gowoonsori.site/data-structure/tree/redblacktree/i2-4.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2-4.png?classes=shadow,border)

부모노드를 중심으로 right-rotate시키고, 여전히 RBT특성을 위반하고 case 2-2 와 모양이 같기 때문에 부모노드를 z로 기준으로 2-2를 수행한다,

- **case 2-2 : z가 부모노드의 오른쪽 자식**

![https://gowoonsori.site/data-structure/tree/redblacktree/i2-5.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/i2-5.png?classes=shadow,border)

할아버지 노드를 중심으로 왼쪽 회전시키고, 부모와 할아버지의 색상을 바꾼다.

z를 할아버지 노드로 바꿔주고 할아버지의 부모가 Red가 아닐 때까지 위의 case를 반복해준다. 만일 z가 root이라면 root를 black으로 바꾸고 종료한다.

결과적으로 black-height가 증가한다.

## 2. 삭제

### case default : 무조건 실행하는 케이스

삭제할 노드를 z라 할 때, z가 RED라면 그냥 삭제하고, BLACK이라면, 그 자리를 대체하는 노드를 검은색으로 칠한다. 새로 대체하는 노드가 red인경우 black으로 바꿔 주면, 문제가 해결 되지만, 새로 대체하는 노드가 **`black`**인 경우 이중 black이 되는 경우로 이를 **`이중 흑색 노드`**라고 부르고 아래의 case에 따라 balancing을 해결하면 된다.

깨진 이중 흑색 노드는 black-height를 맞추기 위해 한 노드가 black색을 두개 가지고 있는 노드로 결국 black-height규칙이 깨졌다는 소리이므로 fix-up을 해주어야 한다.

삭제한 노드 z대신 새로 위치한 노드를 x, 그 형제 노드를 s라고 하자.

### case 1 : s가 RED인 경우

이때는 s의 자식들은 leafNode 일 수 없다. **`조건 5`**를 위반하기 때문에 한개라도 leafnode이면 black-height가 달라지므로 무조건 두개를 가지고 있다.

### (1) L : x가 부모 노드 p[x]의 왼쪽 자식일때

![https://gowoonsori.site/data-structure/tree/redblacktree/d1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d1.png?classes=shadow,border)

위 트리에서 5를 삭제하려고 한다면, 대체되는 노드 x는 leafnode가 대체되며, 이중 흑색 노드가 되어 black-height가 깨지기 때문에 rotate와 recoloring을 통해 규칙을 바로잡아주어야 한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d1-2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d1-2.png?classes=shadow,border)

s를 BLACK으로 부모를 RED로 바꿔주고 부모기준으로 left-Rotate 시켜준다. rotate시켜줌으로써, x(leafnode)의 형제 노드s가 red(20)에서, black(15)로 바뀌었다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d1-3.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d1-3.png?classes=shadow,border)

그래도 여전히 이중 흑색 노드를 갖고 있기 때문에, 다른 case들을 수행해주어야 한다.

### (2) R : x가 부모 노드 p[x]의 오른쪽 자식일때

![https://gowoonsori.site/data-structure/tree/redblacktree/d1-4.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d1-4.png?classes=shadow,border)

40을 삭제한다고 한다면, null이 x, 10이 s가 되고 x는 이중 흑색 노드가 되므로 rebalancing을 해주어야 한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d1-5.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d1-5.png?classes=shadow,border)

s를 BLACK으로 p[x]를 RED로 바꿔준 후 p

**[x](https://gowoonsori.site/data-structure/tree/redblacktree/30)**

를 right-Rotate 시켜준다. 아직 이중 흑색 노드가 남았기 때문에 다른 case를 진행한다.

### case 2 : s가 BLACK, s의 자식들도 BLACK일때

![https://gowoonsori.site/data-structure/tree/redblacktree/d2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d2.png?classes=shadow,border)

case1을 거치고 온 경우도 이에 속하며, 이중 흑색 노드가 존재하기 때문에 recoloring을 통해 balancing을 해주어야 한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d2-1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d2-1.png?classes=shadow,border)

x의 double-black을 지우고 s를 RED로 바꾼후

![https://gowoonsori.site/data-structure/tree/redblacktree/d2-2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d2-2.png?classes=shadow,border)

부모를 black으로 칠해준다. 만약, case 1을 거치고 case 2로 왔다면, p[x]는 red였기 때문에 **`종료`**되고, x의 부모 노드가 black이라면 다시 이중 흑색 노드가 생기기 때문에 부모를 기준으로 다시 다른 case를 수행해준다

### case 3

### (1) L : x가 부모 노드 p[x]의 왼쪽 자식일때 x가 부모 노드 p[x]의 왼쪽 자식일때, s는 BLACK, s의 왼쪽 자식이 RED, 오른쪽 자식이 BLACK 인 경우

![https://gowoonsori.site/data-structure/tree/redblacktree/d3.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d3.png?classes=shadow,border)

case2와 같은 방법으로 s(15)를 red로 부모(10)를 black으로 바꿔줄 경우 double-red가 되므로 recoloring을 할 수 없다. 그래서 rotate를 하여 구조를 바꿔준 후 recoloring을 수행해야한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d3-1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d3-1.png?classes=shadow,border)

s를 중심으로 right-Rotate 시켜준 후, s와 s의 왼쪽 자식의 색을 바꿔준다. 그러면, s는 15(black)에서 12(black)으로 바뀌고 s의 자식은 오른쪽으로 이동하게 되는 것을 볼 수 있다.

여전히, 이중 흑색 노드는 존재하므로 다른 case를 반복 수행하는 데, case3을 마치고 나면 case4의 모양이 되기 때문에, 바로 case4를 수행한다.

### (2) R : x가 부모 노드 p[x]의 왼쪽 자식일때 x가 부모 노드 p[x]의 오른쪽 자식일때, s는 BLACK, s의 오른쪽 자식이 RED, 왼쪽 자식이 BLACK 인 경우

![https://gowoonsori.site/data-structure/tree/redblacktree/d3-2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d3-2.png?classes=shadow,border)

case 3-L의 대칭으로 똑같이 rotate를 하여 구조를 바꿔준 후 recoloring을 수행해야한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d3-3.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d3-3.png?classes=shadow,border)

s(25)를 중심으로 left-Rotate 시켜준 후, s와 s(28)의 오른쪽 자식의 색을 바꿔준다. 그러면, s는 25(black)에서 28(black)으로 바뀌고 s의 자식은 왼쪽으로 이동하게 되는 것을 볼 수 있다.

이경우에도, 여전히 이중 흑색 노드는 존재하므로 다른 case를 반복 수행하는 데, case3을 마치고 나면 case4의 모양이 되기 때문에, 바로 case4를 수행한다.

### case 4

### (1) L : x가 부모 노드 p[x]의 왼쪽 자식일 때 s는 BLACK, s의 오른쪽 자식이 RED인 경우

![https://gowoonsori.site/data-structure/tree/redblacktree/d4.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d4.png?classes=shadow,border)

s의 색을 부모의 색으로 부모의 색을 BLACK, s의 오른쪽 자식을 BLACK으로 바꿔준다. Recoloring을 해주면 black-height가 여전히 깨져있기 때문에, rotate를 시켜줘야 한다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d4-1.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d4-1.png?classes=shadow,border)

p[x]에 대해서 left-rotate를 시켜주고 x의 double-black을 제거해주면, 모든 규칙이 성립하게 되어 끝난다.

### (2) R : x가 부모 노드 p[x]의 오른쪽 자식일 때 s는 BLACK, s의 왼쪽 자식이 RED인 경우

![https://gowoonsori.site/data-structure/tree/redblacktree/d4-2.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d4-2.png?classes=shadow,border)

이는 4-L의 대칭으로 s의 색을 p[x]의 색으로 p[x]의 색을 BLACK, s의 왼쪽 자식을 BLACK으로 바꿔준다.

![https://gowoonsori.site/data-structure/tree/redblacktree/d4-3.png?classes=shadow,border](https://gowoonsori.site/data-structure/tree/redblacktree/d4-3.png?classes=shadow,border)

부모에 대해서 right-rotate를 시켜주고 x의 double-black을 제거해주면, 모든 규칙이 성립하게 되어 끝난다.