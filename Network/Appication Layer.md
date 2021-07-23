#  Application Layer

![https://1.bp.blogspot.com/-R609Bst9JHA/XcwUXLJrtwI/AAAAAAAACUA/nHfYEwN9VpAbuErOicPrwKTwxMjDBHWdgCLcBGAsYHQ/s1600/OSI_TCPIP_%25EB%25B9%2584%25EA%25B5%2590.PNG](https://1.bp.blogspot.com/-R609Bst9JHA/XcwUXLJrtwI/AAAAAAAACUA/nHfYEwN9VpAbuErOicPrwKTwxMjDBHWdgCLcBGAsYHQ/s1600/OSI_TCPIP_%25EB%25B9%2584%25EA%25B5%2590.PNG)

### **Layer 1 : 네트워크 연결 계층 (Network Access Layer) - Ethernet, Wi-Fi, Token ring**

TCP/IP 패킷을 네트워크 매체로 전달하는 것과 네트워크 매체에서 TCP/IP 패킷을 받아들이는 과정을 담당한다. 기본적으로 에러검출 / 패킷의 프레임화를 담당한다.

### **Layer 2 : 인터넷 계층 (Internet Layer) - IP (IPv4, IPv6)**

논리적인 주소 IP를 이용한 노드간 전송과 라우팅 기능을 처리하게 된다. 네트워크상 최종 목적지까지 정확하게 연결되도록 연결성을 제공한다.

### **Layer 3 : 전송 계층 (Transport Layer) - TCP, UDP, DCCP, SCTP, IL, RUDP**

자료의 송수신을 담당한다. 애플리케이션 계층의 세션과 데이터그램 통신서비스 제공한다.

### **Layer 4 : 응용 계층 (Application Layer) - DNS, TFTP, TLS/SSL, FTP, HTTP, IMAP**

다른 계층의 서비스에 접근할 수 있게 하는 application 계층을 제공한다. application들이 데이터를 교환하기위해 사용하는 protocol을 정의한다.

---

## **Applications Architecture (애플리케이션 구조)**

### 1. **클라이언트 - 서버 구조**

- 클라이언트(client)
    - 항상 켜져있지 않고, 서버에 서비스를 요청한다. (request)
    - 클라이언트들은 직접적으로 통신하지 않는다.
- 서버(server)
    - 항상 켜져 있는 호스트, 클라이언트라는 다른 호스트의 요청을 받는다. (response)
    - 고정 IP주소를 가지고 있다.

![https://blog.kakaocdn.net/dn/b90CJF/btqI57vDFL3/9JtCSiCK4dvTSjXN0fBzG0/img.png](https://blog.kakaocdn.net/dn/b90CJF/btqI57vDFL3/9JtCSiCK4dvTSjXN0fBzG0/img.png)

### 2. **Peer to Peer (P2P) 구조 : 호스트 끼리 직접 통신하는 것.**

- peer와 peer끼리 서비스를 요청하고 제공한다. (**self scalability**를 갖는다)
- 간헐적으로 연결되며 동적 IP주소를 갖는다
- ex) 토렌트, 스카이프
- 장점 : **자가 확장성.** 클라이언트 - 서버 구조에 비해 **비용도 효율적**이다.
- 단점 : 고도의 분산 구조 특성을 가져 **보안, 성능, 신뢰성**에 문제점을 가진다.

![https://blog.kakaocdn.net/dn/mhX96/btqI9HC1VQf/03aozeKRTaW77bA5IF1hDK/img.png](https://blog.kakaocdn.net/dn/mhX96/btqI9HC1VQf/03aozeKRTaW77bA5IF1hDK/img.png)

## Application layer **프로토콜**

- 인터넷은 애플리케이션 계층에 2개의 전송 프로토콜, TCP ( Transmission Control Protocol ) 과 UDP( User Datagram Protocol ) 을 제공한다.

    *TCP, UDP 라는 전송프로토콜 두 아이는 애플리케이션 계층이 아니라 한 단계 하위 계층인 트랜스포트 계층.

- telnet, FTP, DHCP, TFTP, HTTP, SMTP, DNS, SNMP 등이 있다.

<br>

## **프로세스 간 통신**

### **프로세스(process)**

- 호스트에서 실행 중인 프로그램
- 클라이언트 프로세스 - 두 프로세스 간의 통신 세션에서 통신을 초기화하는 프로세스
- 서버 프로세스 - 세션을 시작하기 위해 접속을 기다리는 프로세스

### **소켓(socket)**

- 프로세스들이 메시지를 주고 받기 위한 일종의 통로 역할
- 프로세스는 집 소켓은 출입구로 비유된다.
- 일반적인 네트워크 애플리케이션은 2개의 서로 다른 종단시스템에 존재하는 서버 프로그램과 클라이언트 프로그램으로 구성된다.
- 서버 프로그램과 클라이언트 프로그램을 실행시키면 각각의 프로세스가 생성되고 이 프로세스는 Socket 이라는 통로를 통해 읽기(read), 쓰기(write) 연산을 수행하면서 서버와 클라이언트가 데이터를 주고 받는 것.


<br>

## **애플리케이션이 이용 가능한 트랜스포트 서비스**

많은 네트워크들은 하나 이상의 트랜스포트 프로토콜을 제공한다. 개발을 할 때 애플리케이션의 요구에 가장 적합한 서비스를 제공하는 프로토콜을 선택하면 된다. 이 서비스들은 크게 4가지로 분류된다.

1. 신뢰적 데이터 전송
- 전송 데이터의 오류 / 손상에 대한 무결성 보장
- 멀티미디어 데이터는 어느 정도 손실 허용

1. 처리량
- 최소 전송률 보장을 요구
- 전송률에 유연하게 적응

1. 시간
- low delay
- timeliness service

1. 보안
- 기밀성, 무결성, 인증, 가용성 ...

<br>

## **Internet Transport Service**

### **TCP (Transmission Control Protocol)**

복잡한 절차를 거치지만 메시지의 **올바른 데이터의 전달**이 필요할 때 사용한다.

애플리케이션이 TCP 전송 프로토콜을 사용하면 아래의 두가지 서비스를 받을 수 있다.

1. 연결지향형 서비스
2. 신뢰적인 데이터 전송 서비스

### **UDP (User Datagram Protocol)**

어느정도 오류를 감수하고 대용량 메시지의 **빠른 전달**이 목적일 때 사용한다.

UDP는 **비연결형**이고, **비신뢰적인 데이터 전송** 서비스를 제공한다.

<br>

## **Web and HTTP**

### **Web**

**WWW(World Wide Web)**

- 인터넷에 연결된 컴퓨터들이 하이퍼텍스트로 표현된 다양한 정보를 이용할 수 있도록 구성된 응용서비스 시스템

**웹 페이지는 여러 객체로 구성**

- HTML파일, script코드, image, audio, video 등..
- 각 객체는 URL로 참조됨

    ![https://blog.kakaocdn.net/dn/qw8ug/btqI8d3jhX4/V3dWcdWqsQl13mg1wDcVI1/img.jpg](https://blog.kakaocdn.net/dn/qw8ug/btqI8d3jhX4/V3dWcdWqsQl13mg1wDcVI1/img.jpg)

### **HTTP**

- 웹 어플리케이션을 위한 응용계층 프로토콜
- 웹상에서 주로 HTML문서를 주고받는데 쓰임
- 클라이언트/서버 사이에 요청(request)/응답(response) 통신
- 전송계층의 TCP를 사용
- 웹 서버는 표준 포트 80번을 사용한다.

**요청 메소드 (request)**

- **GET : 정보를 요청하기 위해서 사용한다.(SELECT)**
- **POST : 정보를 넣기 위해서 사용한다. (INSERT)**
- PUT : 정보를 업데이트하기 위해서 사용한다. (UPDATE)
- DELETE : 정보를 삭제하기 위해서 사용한다. (DELETE)
- HEAD : (HTTP)헤더 정보만 요청한다. 해당 자원이 존재하는지 혹은 서버에 문제가 없는지를 확인하기 위해서 사용한다.
- OPTIONS : 웹서버가 지원하는 메서드의 종류를 요청한다.
- TRACE : 클라이언트의 요청을 그대로 반환한다. 예컨데 echo 서비스로 서버 상태를 확인하기 위한 목적으로 주로 사용한다.

**응답메세지 (response)**

- **200 OK : 요청이 성공, 정보가 응답으로 보내짐**
- **400 Bad Request : 서버가 요청을 이해할 수 없다. 일반오류코드**
- **404 Not Found : 요청 문서가 서버에 존재하지 않는다.**
- **505 HTTP Version Not Supported: 요청 HTTP 프로토콜 버전을 서버가 지원하지 않는다**

### **Cookies**

**쿠키(cookie)**

- 웹사이트가 상태정보 저장을 위해 브라우저에 전송하는 텍스트 파일
- 비상태(stateless) HTTP에서 사용자-서버 상호작용을 위한 상태 정보 관리
    - > 사이트 활동, 식별정보, 방문페이지, 비밀번호 등 사용자가 입력한 각종 정보를 저장
    - > 메모리에 임시 저장되거나 디스크에 영구적으로 기록
- 해당 사이트에 다시 접속 시 저장된 쿠키 정보를 이용

**쿠키의 주요 용도**

- authorization
- shopping carts
- recommendations
- user session state

**쿠키의 프라이버시 문제**

쿠키를 이용해 사용자명, 주소, 비밀번호, 관심분야 등의 다양한 개인정보 수집 가능

### **Web Cache**

웹 클라이언트와 서버 중개자 역할을 수행한다.

- 요청된 객체가 캐시에 존재하는 경우 -> 캐시에 저장된 객체를 바로 클라이언트에게 전송
- 요청된 객체가 캐시에 존재하지 않으면 -> 웹 서버에게 객체를 요청하여 클라이언트에게 전달