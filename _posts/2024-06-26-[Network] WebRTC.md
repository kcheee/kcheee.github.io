---
layout: post
title: Network WebRTC
categories : Network WebRTC
tag : [Network,WebRTC]
---

# WebRTC

## WebRTC란?

웹 또는 앱(Android, IOS)에서 별도의 소프트웨어, 플러그인 없이 음성, 영상, 텍스트 같은 데이터를 주고 받을 수 있는 기술.

![webrtc](https://github.com/kcheee/kcheee/assets/86779278/ef806859-6fe5-459e-ae55-31566da71c5e)

### 장점

- 별 다른 소프트웨어 없이 실시간 커뮤니케이션 가능
- 무료

### 단점

- STUN/TURN 서버 필요
- 브라우저 간 호환

## P2P 절차

WebRTC는 P2P 방식의 커뮤니케이션이기 때문에 각각의 웹 브라우저는 다음과 같은 절차를 밟아야 합니다.

1. 각 브라우저가 P2P 커뮤니케이션에 동의
2. 서로의 주소를 공유
3. 보안 사항 및 방화벽 우회
4. 멀티미디어 데이터를 실시간으로 교환

여기서 2번과 3번 단계에서 외부에서 접근 할 수 있는 주소가 없기 때문에 중재자의 역할이 필요!

## NAT traversal

[NAT는 여러 대의 컴퓨터(IP)가 하나의 IP 주소로 변환하는 기술.](https://namu.wiki/w/NAT) 이 때문에 공인IP만을 알아낸다해서 특정 IP를 가리킬 수는 없습니다. 공인 IP뿐만 아니라 사설 IP 주소까지 알아내야 특정한사용자를 지정할 수 있게 된다.

어떤 두 브라우저가 서로 p2p형식으로 통신하려면, 각자 현재 연결된 공인 IP주소와 포트를 먼저 알아내야 한다.

하지만 어떤 라우터들은 특정 주소나 포트와의 연결을 차단하는 방화벽 설정이 되어 있을 수도 있습니다. 이처럼 **라우터를 통과해서 연결할 방법을 찾는 과정**을 [**NAT 트래버셜(NAT traversal)**](https://brunch.co.kr/@linecard/155)이라고 한다.

## STUN, TURN

![STUN TURN](https://github.com/kcheee/kcheee/assets/86779278/bc4eeccf-7ea1-484f-ac9d-41fabc8474c8)

### STUN(Session Traversal Utilities for NAT)

NAT traversal 작업은 SUTN(Session Treaversal Utilities for NAT) 서버에 의해 이루어진다. WebRTC 연결을 시작하기 전에 STUN 서버를 향해 요청을 보내면, STUN 서버는 NAT 뒤에 있는 피어(Peer)들이 서로 연결할 수 있도록 공인 IP와 포트를 찾아줍니다.

### TURN(Traversal Using Relay NAT)

STUN 서버를 사용하더라도 항상 정보를 알아낼 수 있는 것은 아닙니다. 방화벽 정책 등 다양한 문제로 인해 자신의 주소를 찾아내지 못했을 경우, TURN 서버를 대안으로 이용하게 됩니다.

TURN 방식은 **네트워크 미디어를 중개하는 서버**를 이용하는 것입니다. TURN 방식은 중간에 서버를 한 번 거치기 때문에, 엄밀히 이야기하자면 P2P 통신이 아니게 되며 그 구조상 지연이 필연적으로 발생하게 됩니다. 하지만 보안 정책이 엄격한 개인 NAT 내부에 위치한 브라우저와 P2P 통신을 할 수 있는 유일한 방법이기 때문에, TURN 방식은 최후의 수단으로 선택되어야 합니다.

요약하자면

- 개개인간의 방화벽 등 여러가지 보호장치들이 존재하고 있어, 서로간의 연결을 위한 정보를 공유하여 p2p 통신을 가능하게 해주는 것이 STUN/TURN server이다.


## ICE와 Candidate

STUN, TURN 서버를 이용해서 획득했던 IP주소와 프로토콜, 포트의 조합으로 구성된 연결 가능한 네트워크 주소들을 Candidate라고 말합니다.

3개의 주소를 얻게 됌.

- 자신의 사설 IP와 포트 넘버
- 자신의 공인 IP와 포트 넘버 (STUN, TURN 서버로부터 획득 가능)
- TURN 서버의 IP와 포트 넘버 (TURN 서버로부터 획득 가능)

**ICE(Interactive Connectivity Establishment)** 라는 프레임워크에서 이루지는데, ICE는 두 개의 단말이 p2p 연결을 가능하게 하도록 최적의 경로를 찾아주는 프레임워크입니다.

## SDP

WebRTC에서 **스트리밍 미디어의 해상도나 형식, 코덱 등의 멀티미디어 컨텐츠의 초기 인수를 설명하기 위해 채택한 프로토콜**입니다. 비디오의 해상도를 보낼 수 있고, 오디오 전송 또는 수신 여부 등 초기 세팅 정보를 기술하 프로토콜입니다.

SDP는 Offer/Answer인 제안 응답 모델을 갖고 있습니다. offer를 하고 응답을 받게 되면 각자의 peer가 수집한 ICE 후보 중에서 최적의 결로를 결정하고 협상하는 프로세스가 발생. 이 과정을 통해 피어간의 p2p 연결이 완전히 설정되고 활성화 됩니다.

## 시그널링

위에서 이야기한 모든 과정을 일컬어 [시그널링(Signaling)](https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API/Session_lifetime#signaling)이라고 부릅니다. 즉 **RTCPeerConnection 통신에 사용할 프로토콜, 채널, 미디어 코덱 및 형식, 데이터 전송 방법, 라우팅 정보와 NAT 통과 방법을 포함한 통신 규격을 교환하기 위해 두 장치의 제어 정보를 교환하는 과정**을 의미합니다.

![signaling](https://github.com/kcheee/kcheee/assets/86779278/006ca399-2d72-4c44-8c34-0909d12db2da)   

[유니티로 WebRTC 구현](https://kcheee.github.io/posts/Unity-Unity%EC%97%90%EC%84%9C-WebRTC/)

### 출처

https://developer.mozilla.org/ko/docs/Web/API/WebRTC_API/Protocols

https://medium.com/@hyun.sang/webrtc-webrtc란-43df68cbe511

https://web.dev/articles/webrtc-infrastructure?hl=ko

https://brunch.co.kr/@linecard/156

https://velog.io/@kkj53051000/WebRTC와-시그널링이란-시그널링-Mozilla-분석