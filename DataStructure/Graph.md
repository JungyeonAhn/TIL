## 1. 그래프란?

- `Node(노드)`와 `Edge(간선)`의 집합으로 이루어진 자료 구조
- 객체간의 **관계(연결성)**를 표현할 수 있다.

![](https://media.vlpt.us/images/gimtommang11/post/b632e2fd-4a41-4e96-b7c8-56399615308c/graph.png)

### 용어

- 정점 → Node, Vertex
- 간선 → Edge, Link, Branch
- 차수(Degree) → 각 정점에 연결된 정점의 갯수
- 사이클(Cycle) → 경로의 시작과 종료 지점이 같은 경우



### Graph vs Tree

- 트리는 그래프의 한 종류 → **방향성**이 있는 **비순환** 그래프
- 그래프는 트리와 달리 루트, 부모-자식 개념이 없음

## 종류
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fc12Pmi%2FbtqAnnlQ7eO%2F8Fkva3Ni9swBmwbkYddwPk%2Fimg.png)

**무방향 그래프(Undirected Graph)**

- 양방향 이동 가능
- `(A, B)` 로 표현 → `(A, B)` = `(B, A)`

**방향 그래프(Directed Graph)**

- 한방향 이동만 가능
- `<A, B>` 로 표현 → `<A, B>` **!=** `<B, A>`

**가중치 그래프(Weighted Graph)**

- 간선에 비용(가중치)가 할당된 그래프
- **네트워크(Network)**라 칭함

**완전 그래프(Complete Graph)**

- 모든 정점이 서로 연결된 그래프
- 간선의 갯수 = `n*(n-1) / 2`

### 사이클 vs 비순환 그래프

**사이클(Cycle)**

- 단순 경로의 시작 노드와 종료 노드가 동일
- 단순 경로 → 경로 중 반복되는 정점이 없음 = 같은 경로를 지나가지 않음

**비순환 그래프(Acyclic Graph)**

- 사이클이 없는 그래프


</br>

## 2. 구현 방법

### **인접 리스트**

- 가장 일반적 방법
- 구현 순서
    1. 모든 노드를 인접 리스트에 저장
        - 무방향 그래프에선 (A, B) 간선이 두 번 저장됨
    2. 각 노드마다 인접한 노드들을 담음

![](https://i.imgur.com/TyIs2Av.png)

- 간선이 적은 **희소 그래프(Sparse Graph)**에 적합
    - 장점
        - 인접 노드 탐색 → 한번에
        - 모든 간선의 수 탐색 → O(N+E)
    - 단점
        - 간선의 존재 여부 탐색 → O(Degree)

### **인접 행렬**

- 구현 순서
    1. N * N 의 Bool 행렬로 표현
    2. `matrix[i][j]` 가 True일 때 i → j 간선이 존재

![](https://i.imgur.com/7wUpNT6.png)

- 간선이 많은 **밀집 그래프(Dense Graph)**에 적합
    - 장점
        - 간선의 존재 여부 탐색 → O(1)
        - 정점의 차수 확인 → O(N) → 행(열)을 모두 더함
    - 단점
        - 인접 노드 탐색 → 모든 노드 순회 해야함
        - 모든 간선의 수 탐색 → O(N^2)

## 3. 그래프 탐색

### 깊이 우선 탐색(DFS, Depth-First Search)

1.깊이 우선 탐색은 루트 노드를 스택에 넣고 탐색을 시작한다.

2. 스택 안에 있는 노드 0 을 꺼내 출력한 후, 출력한 노드(0)의 자식노드를 스택에 넣는다. (이미 스택 안에 있는 자식은 스택에 넣지 않는다)

3. 스택에서 노드를 하나 꺼내 출력한 후, 해당 노드의 자식노드를 스택에 넣는다. 스택에 남는 노드가 없을 때까지 반복한다.

(트리 순회에서 다룬 전위/중위/후위 순회는 모두 깊이 우선 탐색에 속한다)

![](https://soapy-polish-b0e.notion.site/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fce6e5193-aa22-45f2-a00d-f1166e95c9cf%2FUntitled.png?table=block&id=e788a444-be90-4222-b566-2dc614f71bc9&spaceId=1350fdaf-8782-41d5-8b2f-41e41dc4da0d&width=2510&userId=&cache=v2)


DFS : 1 → 2 → 7 → 6 → 8 → 3 → 4 → 5

### 구현 코드 
**스택 방식**

```python
def dfs1(graph, start_node):
    visit = list()  
    stack = list()

    # 첫 번째 노드는 스택에 넣고 dfs를 시작한다.
    stack.append(start_node)

    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            stack.extend(graph[node])

    return visit
```
**재귀 방식**
```
def dfsR(graph, start_node, visit):
    visit.append(start_node)
    print(start_node, end=' ')

    for node in graph[start_node]:
        if node not in visit:
            dfsR(graph, node, visit)

```


### 너비 우선 탐색(BFS, Breadth-First Search)

- 각 노드의 인접한 노드부터 먼저 탐색한다.
- **큐** 구조를 사용한다.
- **두 노드 사이의 최단 경로**를 찾을 때
- **임의의 경로**를 찾을 때


1. 너비 우선 탐색은 루트 노드를 큐에 넣고 탐색을 시작한다.
2. 깊이 우선 탐색과 동일하게 큐에서 꺼낸 노드를 출력하고, 출력한 노드의 자식 노드를 큐에 넣는다. 
3. 큐에 데이터가 없을 때까지 연산을 반복한다.

![](https://soapy-polish-b0e.notion.site/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Faddd0d1a-99df-47ae-ae31-9ba24d7a7e28%2FUntitled.png?table=block&id=cd95b734-aa22-41b5-a7f6-6526e6bed803&spaceId=1350fdaf-8782-41d5-8b2f-41e41dc4da0d&width=2510&userId=&cache=v2)

BFS : 1 → 2 → 3 → 8 → 7 → 4 → 5 → 6

### 구현 코드

def bfs(graph, start_node):
    visit = list()  
    queue = list()

    # 첫 번째 노드는 큐에 넣고 bfs를 시작한다.
    queue.append(start_node)
    while queue:
        node = queue.pop(0)
        if node not in visit:
            visit.append(node)
            queue.extend(graph[node])

    return visit
너비 우선 탐색은 큐로 구현한다. 큐를 사용한다는 점을 제외하면 DFS와 동일하다.

from collections import deque

def bfs_deque(graph, root):
    visit = []
    queue = deque([root])

    while queue:
        node = queue.popleft()
        if node not in visit:
            visit.append(node)
            queue += graph[node] - set(visit)

    return visit
collections 모듈의 deque 사용해 bfs_deque()함수를 구현했다.
queue의 오른쪽에서 데이터를 삽입하고 왼쪽에서 제거한다.

</br>

## 4. 최소 신장 트리(MST, Minimum Spanning Tree)

### Sppaning Tree

- 그래프의 최소 연결 부분 그래프 → 모든 정점들이 연결되어 있어야 함
- 사이클을 포함하지 않음
- 노드가 `N`개라면 최소 간선의 수는 `N-1`개

![](https://blog.kakaocdn.net/dn/O2nUs/btqJrw3JajI/ny0AtAi9eGpmZNb016ZG41/img.png)


</br>


### Minimum Spanning Tree

- 스패닝 트리중 **가중치 합**이 최소

## 5. MST 구현 방법

### Kurskal Algorithm

- 그리디 알고리즘
- O(nlogn) ← 간선 E개 퀵 정렬 비용 n = E-1
- 시간 복잡도: 희소 그래프(Sparse Graph)에 적합
- 구현 방법
    - 간선 데이터를 비용에 따라 오름차순 정렬
    - 간선을 하나씩 확인하며 사이클을 발생시키는지 확인
        - 사이클이 발생하지 않는 경우만 MST에 포함
        - 사이클 확인을 반복

![](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fa2f0d57c-7d03-48c8-abca-2738a94f4051%2FUntitled.png?table=block&spaceId=1c4fca31-20ed-407b-9ebf-efb4b969e11f&id=5162e0ab-416b-41ef-826c-f906f2543ff7&width=2280&userId=8651a1d2-e20e-45e2-9c59-06276e6f0307&cache=v2)

1. (3, 4)
2. (4, 7)
3. (4, 6) → 사이클 형성(같은 집합). PASS
4. (1, 2)
5. (2, 6)
6. (2, 3) → 사이클 형성(같은 집합). PASS
7. (1, 5) → 사이클 형성(같은 집합). PASS

![](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fa2f0d57c-7d03-48c8-abca-2738a94f4051%2FUntitled.png?table=block&spaceId=1c4fca31-20ed-407b-9ebf-efb4b969e11f&id=5162e0ab-416b-41ef-826c-f906f2543ff7&width=2280&userId=8651a1d2-e20e-45e2-9c59-06276e6f0307&cache=v2)

### Prim Algorithm

- 시작 정점부터 Spanning Tree 집합을 **단계적으로 확장**하는 방법
- 시간 복잡도: O(N^2)
- 밀집 그래프(Dense Graph)에 적합

![](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fa2f0d57c-7d03-48c8-abca-2738a94f4051%2FUntitled.png?table=block&spaceId=1c4fca31-20ed-407b-9ebf-efb4b969e11f&id=74995ca0-ae63-4afe-857b-0f2bea70344f&width=2280&userId=8651a1d2-e20e-45e2-9c59-06276e6f0307&cache=v2)

1. 아무 시작 노드를 T에 넣음 (1)
2. T에 있는 노드와 T에 없는 노드 사이의 간선 중 최소 간선을 찾음
3. 반복 → (1, 2) → (2, 6) → (6, 4) → (4, 3) → (4, 7) → (6, 5)