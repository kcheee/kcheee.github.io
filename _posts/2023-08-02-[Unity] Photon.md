---
layout: post
title: unity Photon
categories : unity study Photon
tag : [unity,Photon]
---

# Photon

멀티 플레이를 지원해주는 툴

## 사용법

**포톤 기본 설정**

포톤 사이트에 들어가서 pun으로 하나 만듦.

![image](https://github.com/kcheee/kcheee/assets/86779278/37d77856-9894-4f72-9469-6f14abc48edd)    

Photon 기본 설정

![image](https://github.com/kcheee/kcheee/assets/86779278/be70e1e6-1daf-4540-8532-2141c8336529)   

**App Id Pun** : Pun Id 추가 (Photon 사이트에서 가져옴)   
**App version** : 같은 버전에 있는 사람들만 통신 가능.   
**Fixed Region** : 나라 설정.   

```c# 
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;

public class SimpleConnectMgr : MonoBehaviourPunCallbacks
{
    // Start is called before the first frame update
    void Start()
    {
        // 접속
        PhotonNetwork.ConnectUsingSettings();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    // OnConnectedToMaster 상속 
    // 마스터 서버 접속 완료
    public override void OnConnectedToMaster()
    {
        // 부모에 있는 OnConnectedToMaster(); 호출하고 자기걸 실행.
        base.OnConnectedToMaster();

        // string 값으로 바꿔줌.
        print(nameof(OnConnectedToMaster));

        // 로비진입.
        JoinLobby();
    }

    // 로비진입 함수
    void JoinLobby()
    {
        // 닉네임 설정.
        PhotonNetwork.NickName = "강찬희";
        // 기본 Lobby 입장.
        PhotonNetwork.JoinLobby();      
    }

    // 로비진입 완료
    public override void OnJoinedLobby()
    {
        base.OnJoinedLobby();

        print(nameof(OnJoinedLobby));
        RoomOptions roomOption = new RoomOptions();
  
        PhotonNetwork.JoinOrCreateRoom("meta_unity_room", roomOption,TypedLobby.Default);
    }

    // 방 생성완료시 호출되는 함수
    public override void OnCreatedRoom()
    {
        base.OnCreatedRoom();
        print(nameof(OnCreatedRoom));
    }
    // 방 생성 실패시 호출
    public override void OnCreateRoomFailed(short returnCode, string message)
    {
        base.OnCreateRoomFailed(returnCode, message);
        print(nameof(OnCreateRoomFailed));
    }

    // 방 참여시 호출되는 함수.
    public override void OnJoinedRoom()
    {
        base.OnJoinedRoom();
        print(nameof(OnJoinedRoom));
    }
}

```

### 기본설정 2

![image](https://github.com/kcheee/kcheee/assets/86779278/8feedab3-4f2d-472a-9238-3a9d4f5bc58f)

Player에 Photon view 컴포넌트를 붙여준다.

```c# 
GameManager
void Start
{  
        // Resources 폴더에 있는 Player 프리팹 가져와서 instantiate
         PhotonNetwork.Instantiate("Player",Vector3.zero,Quaternion.identity);
}
```
을 사용하기 위해 Resources 폴더를 이용해서 Player를 프리팹화 시킨다.

Photon에서는 Resources 폴더를 잘 사용해야 한다.

실행을 시켜보면 Player가 Instantiate 되고 photon view에 값이 들어간 것을 볼 수 있다.
![image](https://github.com/kcheee/kcheee/assets/86779278/4cd915cd-b9ed-48b7-8079-f07c0800f067)


카메라 및 이동 등등 


```c#
 if (photonView.IsMine)
        {
          // trcam은 카메라
            trCam.gameObject.SetActive(true);
        }
```

카메라 회전

```c#
 void Update()
    {
        //마우스의 움직임따라 플레이를 좌우 회전하고
        //카메라를 위아래 회전하고 싶다.

        // 내것이 아닐때 리턴을 하여 못움직이게
        if (!photonView.IsMine) return;

        //1. 마우스 입력을 받자.
        float mx = Input.GetAxis("Mouse X");
        float my = Input.GetAxis("Mouse Y");

        //2. 마우스의 움직임 값을 누적
        rotX += mx * rotSpeed * Time.deltaTime;
        rotY += my * rotSpeed * Time.deltaTime;

        //3. 누적된 값만큼 회전 시키자.
        transform.localEulerAngles = new Vector3(0, rotX, 0);
        trCam.localEulerAngles = new Vector3(-rotY, 0, 0);
    }
```

이 함