---
layout: post
title: Network TCP
categories : Network TCP
tag : [Network,TCP]
---
   
# TCP 통신을 통해 Unity에서 통신

## 1. 소켓 생성
클라이언트에서는 **TcpClient** 를, 서버에서는 **TcpListener를** 생성하여 네트워크 연결을 준비합니다.

```c#
// Client
socket = new TcpClient(ip, port);

// Server
server = new TcpListener(IPAddress.Any, port);
server.Start();
```

---

## 2. Bind
서버에서 특정 포트를 통해 네트워크 바인딩을 완료합니다.

```c#
// 서버에서 지정된 포트를 바인딩
server = new TcpListener(IPAddress.Any, port);
server.Start();
```

---

## 3. Listen
서버는 클라이언트의 연결 요청을 대기 상태로 유지합니다.

```c#
// 서버가 클라이언트의 연결을 대기
StartListening();

void StartListening() => server.BeginAcceptTcpClient(AcceptTcpClient, server);
```

---

## 4. Accept
클라이언트의 연결 요청을 수락하고, 소켓 연결을 활성화합니다.

```c#
// 클라이언트 연결 요청 수락
void AcceptTcpClient(IAsyncResult ar)
{
    TcpListener listener = (TcpListener)ar.AsyncState;
    clients.Add(new ServerClient(listener.EndAcceptTcpClient(ar)));
    StartListening();
}
```

---

## 5. 통신
클라이언트와 서버는 **NetworkStream**을 통해 데이터를 주고받습니다.

### 클라이언트
```c#
// 데이터 송신
void Send(string data)
{
    writer.WriteLine(data);
    writer.Flush();
}

// 데이터 수신
if (socketReady && stream.DataAvailable)
{
    string data = reader.ReadLine();
    if (data != null) OnIncomingData(data);
}
```

### 서버
```c#
// 데이터 수신
NetworkStream s = c.tcp.GetStream();
if (s.DataAvailable)
{
    string data = new StreamReader(s, true).ReadLine();
    if (data != null) OnIncomingData(c, data);
}

// 데이터 송신
void Broadcast(string data, List<ServerClient> cl)
{
    foreach (var c in cl)
    {
        StreamWriter writer = new StreamWriter(c.tcp.GetStream());
        writer.WriteLine(data);
        writer.Flush();
    }
}
```

---

## 6. 통신 종료
연결 종료 및 리소스 해제는 **Close()** 메서드로 관리합니다.

### 클라이언트
```c#
void CloseSocket()
{
    writer.Close();
    reader.Close();
    socket.Close();
    socketReady = false;
}
```

### 서버
```c#
foreach (ServerClient c in disconnectList)
{
    c.tcp.Close();
    clients.Remove(c);
}


```


