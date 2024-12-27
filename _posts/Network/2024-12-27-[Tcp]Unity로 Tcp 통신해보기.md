---
layout: post
title: Unity로 TCP 통신 해보기
categories : Network TCP
tag : [Network,TCP]
---
   
# TCP 통신을 통해 Unity에서 Text 통신신

## 1. 소켓 생성
클라이언트에서는 `TcpClient`를, 서버에서는 `TcpListener`를 생성하여 네트워크 연결을 준비합니다.

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
클라이언트와 서버는 `NetworkStream`을 통해 데이터를 주고받습니다.

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
연결 종료 및 리소스 해제는 `Close()` 메서드로 관리합니다.

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


# 스크립트

## Server

<details>
<summary>Server</summary>
<div markdown="1">

```C#
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.UI;
using System;
using System.IO;

public class Server : MonoBehaviour
{
    public InputField PortInput;

    List<ServerClient> clients;
    List<ServerClient> disconnectList;

    TcpListener server;
    bool serverStarted;


	public void ServerCreate()
	{
        clients = new List<ServerClient>();
        disconnectList = new List<ServerClient>();
        
        try
        {
            int port = PortInput.text == "" ? 7777 : int.Parse(PortInput.text);
            server = new TcpListener(IPAddress.Any, port);
            server.Start();

            StartListening();
            serverStarted = true;
            Chat.instance.ShowMessage($"서버가 {port}에서 시작되었습니다.");
        }
        catch (Exception e) 
        {
            Chat.instance.ShowMessage($"Socket error: {e.Message}");
        }
	}

	void Update()
	{
        if (!serverStarted) return;

        foreach (ServerClient c in clients) 
        {
            // 클라이언트가 여전히 연결되있나?
            if (!IsConnected(c.tcp))
            {
                c.tcp.Close();
                disconnectList.Add(c);
                continue;
            }
            // 클라이언트로부터 체크 메시지를 받는다
            else 
            {
                NetworkStream s = c.tcp.GetStream();
                if (s.DataAvailable) 
                {
                    string data = new StreamReader(s, true).ReadLine();
                    if (data != null)
                        OnIncomingData(c, data);
                }
            }
        }

		for (int i = 0; i < disconnectList.Count - 1; i++)
		{
            Broadcast($"{disconnectList[i].clientName} 연결이 끊어졌습니다", clients);

            clients.Remove(disconnectList[i]);
            disconnectList.RemoveAt(i);
		}
	}

	

	bool IsConnected(TcpClient c)
	{
        try
        {
            if (c != null && c.Client != null && c.Client.Connected)
            {
                if (c.Client.Poll(0, SelectMode.SelectRead))
                    return !(c.Client.Receive(new byte[1], SocketFlags.Peek) == 0);

                return true;
            }
            else
                return false;
        }
        catch 
        {
            return false;
        }
	}

	void StartListening()
	{
        server.BeginAcceptTcpClient(AcceptTcpClient, server);
	}

    void AcceptTcpClient(IAsyncResult ar) 
    {
        TcpListener listener = (TcpListener)ar.AsyncState;
        clients.Add(new ServerClient(listener.EndAcceptTcpClient(ar)));
        StartListening();

        // 메시지를 연결된 모두에게 보냄
        Broadcast("%NAME", new List<ServerClient>() { clients[clients.Count - 1] });
    }


    void OnIncomingData(ServerClient c, string data)
    {
        if (data.Contains("&NAME")) 
        {
            c.clientName = data.Split('|')[1];
            Broadcast($"{c.clientName}이 연결되었습니다", clients);
            return;
        }

        Broadcast($"{c.clientName} : {data}", clients);
    }

    void Broadcast(string data, List<ServerClient> cl) 
    {
        foreach (var c in cl) 
        {
            try 
            {
                StreamWriter writer = new StreamWriter(c.tcp.GetStream());
                writer.WriteLine(data);
                writer.Flush();
            }
            catch (Exception e) 
            {
                Chat.instance.ShowMessage($"쓰기 에러 : {e.Message}를 클라이언트에게 {c.clientName}");
            }
        }
    }
}


public class ServerClient
{
    public TcpClient tcp;
    public string clientName;

    public ServerClient(TcpClient clientSocket) 
    {
        clientName = "Guest";
        tcp = clientSocket;
    }
}

```

</div>
</details>

## Client

<details>
<summary>Client</summary>
<div markdown="1">

```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Net.Sockets;
using System.IO;
using System;

public class Client : MonoBehaviour
{
	public InputField IPInput, PortInput, NickInput;
	string clientName;

    bool socketReady;
    TcpClient socket;
    NetworkStream stream;
	StreamWriter writer;
    StreamReader reader;


	public void ConnectToServer()
	{
		// 이미 연결되었다면 함수 무시
		if (socketReady) return;

		// 기본 호스트/ 포트번호
		string ip = IPInput.text == "" ? "127.0.0.1" : IPInput.text;
		int port = PortInput.text == "" ? 7777 : int.Parse(PortInput.text);

		// 소켓 생성
		try
		{
			socket = new TcpClient(ip, port);
			stream = socket.GetStream();
			writer = new StreamWriter(stream);
			reader = new StreamReader(stream);
			socketReady = true;
		}
		catch (Exception e) 
		{
			Chat.instance.ShowMessage($"소켓에러 : {e.Message}");
		}
	}

	void Update()
	{
		if (socketReady && stream.DataAvailable) 
		{
			string data = reader.ReadLine();
			if (data != null)
				OnIncomingData(data);
		}
	}

	void OnIncomingData(string data)
	{
		if (data == "%NAME") 
		{
			clientName = NickInput.text == "" ? "Guest" + UnityEngine.Random.Range(1000, 10000) : NickInput.text;
			Send($"&NAME|{clientName}");
			return;
		}

		Chat.instance.ShowMessage(data);
	}

	void Send(string data)
	{
		if (!socketReady) return;

		writer.WriteLine(data);
		writer.Flush();
	}

	public void OnSendButton(InputField SendInput) 
	{
#if (UNITY_EDITOR || UNITY_STANDALONE)
		if (!Input.GetButtonDown("Submit")) return;
		SendInput.ActivateInputField();
#endif
		if (SendInput.text.Trim() == "") return;

		string message = SendInput.text;
		SendInput.text = "";
		Send(message);
	}


	void OnApplicationQuit()
	{
		CloseSocket();
	}

	void CloseSocket()
	{
		if (!socketReady) return;

		writer.Close();
		reader.Close();
		socket.Close();
		socketReady = false;
	}
}

```

</div>
</details>

## Chat

<details>
<summary>Chat</summary>
<div markdown="1">

```c#
using UnityEngine;
using UnityEngine.UI;

public class Chat : MonoBehaviour
{
    public static Chat instance;
    void Awake() => instance = this;

    public InputField SendInput;
    public RectTransform ChatContent;
    public Text ChatText;
    public ScrollRect ChatScrollRect;


    public void ShowMessage(string data)
    {
        ChatText.text += ChatText.text == "" ? data : "\n" + data;

        Fit(ChatText.GetComponent<RectTransform>());
        Fit(ChatContent);
        Invoke("ScrollDelay", 0.03f);
    }

    void Fit(RectTransform Rect) => LayoutRebuilder.ForceRebuildLayoutImmediate(Rect);

    void ScrollDelay() => ChatScrollRect.verticalScrollbar.value = 0;

    private void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            ShowMessage("dfs");
        }
    }
}

```

</div>
</details>