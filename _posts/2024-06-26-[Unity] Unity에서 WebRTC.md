---
layout: post
title: Unity에서 WebRTC 구현
categories : unity WebRTC
tag : [WebRTC]
---

# Unity에서 WebRTC 구현

### [스크립트 파일](https://github.com/k0-juhyun/EduVerse/tree/BetaMain/Assets/02.%20Scripts/KCH/Rtc)


## 구글의 스턴 서버 사용

```csharp
//RTC 구성
RTCConfiguration configuration = new RTCConfiguration
{
    iceServers = new[] { new RTCIceServer { urls = new[] { "stun:stun.l.google.com:19302" } } }
};

```

## GameMgr.cs

WebRTC 세션 전반을 관리하는 중심적인 역할.

- 플레이어 관리 : **PhotonViewID** 관리
- 세션 제어 : 플레이어 간의 WebRTC연결을 시작, 관리하며, 필요한 시그널링 작업 조정

## RtcPlayer

- 게임 시작 시 ‘RtcSender, RtcReceiver 플레이어 객체에 AddComponent
- 미디어 스트림 송수신

```csharp
void Start()
{
    // 내 캐릭터에만 RtcSender, RtcReceiver 를 붙이자
    if(photonView.IsMine)
    {
        rtcSender = gameObject.AddComponent<RtcSender>();
        rtcReceiver = gameObject.AddComponent<RtcReceiver>();

        // rtcSender가 있는 경우
        if (GameMgr.instance.viewOn)
        {
            rtcSender.Setup();
        }
    }

    //플레이어의 photonView 를 GameMgr 에 알려주자
    GameMgr.instance.AddPlayer(photonView);
}
```



## RtcSender

`RtcSender` 스크립트는 로컬 미디어 스트림을 초기화하고, 이를 다른 피어와 공유하기 위한 연결을 설정합니다.

### ICE Candidate 교환

ICE(Interactive Connectivity Establishment) Candidate는 네트워크 연결을 가능하게 하는 후보 네트워크 주소입니다. `RtcSender`에서는 다음 단계로 ICE 후보를 수집하고 교환합니다:

1. **ICE 후보 생성**: `RTCPeerConnection` 객체가 생성될 때, WebRTC 프레임워크는 네트워크 인터페이스와 포트를 사용하여 가능한 모든 ICE 후보를 수집합니다.
2. **ICE 후보 전송**: 후보가 발견될 때마다, 이를 JSON 형식으로 변환하여 상대 피어(`RtcReceiver`)에게 전송합니다.

```csharp

peer.OnIceCandidate = (RTCIceCandidate candidate) => {
    RTCIceCandidateInit candidateInit = new RTCIceCandidateInit {
        candidate = candidate.Candidate,
        sdpMid = candidate.SdpMid,
        sdpMLineIndex = candidate.SdpMLineIndex
    };
    string strCandidate = JsonUtility.ToJson(candidateInit);
    GameMgr.instance.AddIceCandidate(receiverId, GetComponent<PhotonView>().ViewID, strCandidate, false);
};

```

### SDP 교환

SDP는 피어 간 미디어 협상을 위해 사용되는 메타데이터를 설명합니다. `RtcSender`에서는 SDP를 생성하고 이를 피어에게 제공하여 세션을 협상합니다:

1. **Offer 생성**: 로컬 세션 설명(offer)를 생성합니다.
2. **Local Description 설정**: 생성된 offer를 로컬 설명으로 설정합니다.
3. **Offer 전송**: 설정된 offer를 `RtcReceiver`에게 전송합니다.

```csharp

IEnumerator CreateOffer(int receiverId) {
    RTCPeerConnection p = peerList[receiverId];
    var operation = p.CreateOffer();
    yield return operation;

    if (!operation.IsError) {
        yield return OnSuccessCreateOffer(receiverId, operation.Desc);
    }
}

```

## RtcReceiver

`RtcReceiver`는 `RtcSender`로부터 전송된 미디어 스트림과 네트워크 정보를 수신하고, 이를 통해 피어 간 연결을 완성합니다.

### ICE Candidate 처리

수신된 ICE 후보를 로컬 피어 연결에 추가하여, 최적의 네트워크 경로를 확립합니다.

```csharp

public void AddIceCandidate(int senderId, string strCandidate) {
    RTCIceCandidateInit candidateInit = JsonUtility.FromJson<RTCIceCandidateInit>(strCandidate);
    if (peerList.ContainsKey(senderId)) {
        peerList[senderId].AddIceCandidate(new RTCIceCandidate(candidateInit));
    }
}

```

### SDP 처리

`RtcSender`로부터 받은 SDP를 사용하여 원격 세션 설명을 설정하고, 이를 통해 피어 간 미디어 협상을 완료합니다.

1. **Remote Description 설정**: 수신된 offer를 원격 설명으로 설정합니다.
2. **Answer 생성**: 설정된 원격 설명에 기반하여 answer를 생성합니다.
3. **Local Description 설정**: 생성된 answer를 로컬 설명으로 설정합니다.

```csharp

IEnumerator SetRemoteDescription(int senderId, RTCSessionDescription sessionDescription) {
    RTCPeerConnection p = peerList[senderId];
    var operation = p.SetRemoteDescription(ref sessionDescription);
    yield return operation;

    if (!operation.IsError) {
        yield return CreateAnswer(senderId);
    }
}

```

이렇게 `RtcSender`와 `RtcReceiver`는 ICE 후보와 SDP를 교환하여 WebRTC 기반의 실시간 통신을 구현합니다. 이 과정은 네트워크 환경에 맞춰 최적의 연결을 자동으로 선택하고, 미디어 스트림의 안정적인 전송을 보장합니다.