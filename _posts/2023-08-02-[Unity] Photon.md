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
을 사용하기 위해 **Resources 폴더를 이용해서 Player**를 프리팹화 시킨다.
(PhotonNetwork.Instantiate를 사용하기 위해서는 무조건 프리팹이 Resources 폴더에 있어야한다.)

Photon에서는 Resources 폴더를 잘 사용해야 한다.

실행을 시켜보면 Player가 Instantiate 되고 photon view에 값이 들어간 것을 볼 수 있다.
![image](https://github.com/kcheee/kcheee/assets/86779278/4cd915cd-b9ed-48b7-8079-f07c0800f067)


카메라 및 이동 등등 


```c#
 if (photonView.IsMine==false)
        {
          // trcam은 카메라
            trCam.gameObject.SetActive(false);
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

### OnPhotonSerializeView 호출 빈도 조절
// 보이는 프레임 조절.
```c# 
        PhotonNetwork.SerializationRate = 60;
```


### 서버에 값을 던져주는 인터페이스 IPunObserbable   

계속 변화하는 어떤 것을 네트워크에 동기화시켜주기 위한 인터페이스
PlayerMove Script
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class PlayerMove : MonoBehaviourPun, IPunObservable
{

    //속력 
    float speed = 5;

    //Character Controller 담을 변수
    CharacterController cc;

    //점프 파워
    float jumpPower = 5;
    //중력
    float gravity = -9.81f;
    //y 속력
    float yVelocity = 0;

    // 서버에서 넘어오는 위치값
    Vector3 receivePos;
    // 서버에서 넘어오는 회전값
    Quaternion receiveRot;

    // 보정하는 속력
    private float lerpSpeed=50;

    void Start()
    {
        //Character Controller 가져오자
        cc = GetComponent<CharacterController>();
    }

    void Update()
    {

        // 내가 만든 플레이어라면
        if (photonView.IsMine)
        {
            //W, S, A, D 키를 누르면 앞뒤좌우로 움직이고 싶다.

            ```움직이는 코드```

        }

        // 내 플레이어가 아닐 떄
        else
        {
            transform.position = Vector3.Lerp(transform.position,receivePos,lerpSpeed*Time.deltaTime);

            transform.rotation = Quaternion.Lerp(transform.rotation,receiveRot,lerpSpeed*Time.deltaTime);
        }
    }

    // IPunObservable 인터페이스 구현을 위한 함수
    public void OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        // 나의 위치, 회전 값을 보낸다.
        // 내 Player아니라면
        // 위치, 회전을 받자

        // 내 player면
        if (stream.IsWriting)
        {
            // 나의 위치값을 보냄
            stream.SendNext(transform.position);
            // 나의 회전값을 보냄
            stream.SendNext(transform.rotation);
        }
        else
        {
            // 위치, 회전을 받자
            receivePos = (Vector3)stream.ReceiveNext();
            receiveRot = (Quaternion)stream.ReceiveNext();
        }

    }

}
```

파괴하는 객체도 
```c#

// 내 오브젝트라면
 if(photonView.IsMine)
 // 서버에 있는 객체를 파괴한다.
 PhotonNetwork.Destroy(gameObject); 

```

### 원격으로 함수 호출 RPC

```c#

    [PunRPC]    // 함수위에 붙여줘야함.
    void FireBulleyByRpc()
    {
        Vector3 pos = Camera.main.transform.position + Camera.main.transform.forward * 1;

        Quaternion dir = Camera.main.transform.rotation;

        GameObject bomb = Instantiate(bombFactory);
        bomb.transform.position = pos;
        bomb.transform.rotation = dir;
    }

```
함수 호출
RPC의 호출 순서 주의
각자 pc에서 다 호출

```c#
photonView.RPC("함수 이름", RpcTarget.All);

//RpcTarget.All 전체 서버에 보냄
// RpcTarget.others 나뺴고 다
// RpcTarget.MasterClient 마스터만
```

Rpc 함수는 서버 세팅에 Rpc List로 나오게 된다.

![image](https://github.com/kcheee/kcheee/assets/86779278/83527366-7d74-42e5-a86e-4a9678845787)


