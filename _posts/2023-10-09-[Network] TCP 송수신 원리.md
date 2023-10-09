---
layout: post
title: Network TCP송/수신원리 정리
categories : Network TCP
tag : [Network,TCP,Server]
---

# 다시 공부 필요!..   

Process가 File에 할 수 있는 Operation : RWX   

소켓에 대해 읽는다 -> Receive   

소켓에 대해 쓴다 -> Send   

=> 서버 프로세스가 Socket에 대고 IO를 한다.   

파일을 잘개 쪼개 버퍼에 올리고, 버퍼 내용을 복사해서 Send한다 => Buffered I/O
이때 Buffer에 담긴 쪼갠 파일도 Segment(4계층) 단위로 쪼개고, header를 붙여 Packet(3계층)으로 만들어 전송한다.   


패킷은 논리적으로 End-to-End로 전송되지만, Frame 자체는 2계층에서 전송되며 최종 원하는 단말로 전송될 때까지 계속 갈아 끼워진다. MAC 주소를 활용한 동일한 물리적 네트워크 단위의 통신인 이더넷 프로토콜 전송이기 때문이다.   


클라이언트에서 Segment를 받으면 다음 Segment 번호에 대해 요청으로 ACK를 반환한다. ACK 메세지에는 클라이언트의 TCP Buffer의 가용 영역인 Window Size를 포함한다.   

사실 서버에서는 Segments를 보낸 상태에서 WAIT하고 있었다. 이제서야 잘 보낸 것을 확인하고 다음 Segment를 보낸다. 이러한 WAIT이 TCP 성능 저하의 원인   


이러한 무작정 WAIT하는 전략의 성능 이슈를 막기 위해 등장한 전략이 있다.
Window Size > Maximum Segment Size ? YES : NO(then Wait)   


Receive Process가 Socket에 대하여 TCP Buffer를 읽으면 
Read 속도 > Network 속도 ? YES : TCP Buffer Size가 작아지며 처리 지연 현상 발생   

따라서 처리 지연 문제 발생시 장애 원인을 Network가 아니라 프로그램 구조에서 찾아야 한다   


!!일단 Process가 **TCP Buffer를 읽는 속도가 얼마나 빠른지 확인하라.**Network에서 수신하는 속도보다 무조건 빨라야 병목이 발생하지 않는다!!

[출처](https://www.youtube.com/watch?v=K9L9YZhEjC0)
