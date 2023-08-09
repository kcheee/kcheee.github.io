---
layout: post
title: unity Photon Chat
categories : unity study Photon Chat
tag : [unity,Photon,Chat,UI]
---

# Photon UICHAT   

ChatManager 오브젝트를 하나 만들고, Photon View 컴포넌트를 넣어준다.   

![image](https://github.com/kcheee/kcheee/assets/86779278/375e7efc-ed8d-46b1-ade4-241233989bdd)

<br/>   

- - -   

<br/>   

**ChatManager Script**   

  - - -    

  
```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Photon.Pun;

// 포톤을 사용하기 위한 MonobehaviourPun
public class ChatManager : MonoBehaviourPun
{
    // inputField
    public InputField chatInput;

    // ChatItem Prefab
    public GameObject chatItemFactory;
    // ScrollView 에 있는 Content의 RectTransform
    public RectTransform rtContent;

    //ScrolView의 RectTransform
    public RectTransform rtScrollView;

    // content h 값을 가직 있는 변수
    float prevContentH;

    // 닉네임 색상
    public Color nickNameColor;


    private void Start()
    {
        // 닉네임 색상 랜덤하게 설정
        nickNameColor = new Color(Random.value, Random.value, Random.value);

        // 엔터키를 누르면 InputField에 있는 텍스트 내용 알려주는 함수 등록 
        chatInput.onSubmit.AddListener(OnSubmit);

        // inputField의 내용이 변경될 때마다 호출해주는 함수 등록
        chatInput.onValueChanged.AddListener(onValueChanged);

        //InputField 의 Focusing이 사라졌을 때 호출해주는 함수 등록 
        chatInput.onEndEdit.AddListener(onEndEdit);
    }


    void OnSubmit(string s)
    {
        // s의 길이가 0이라면 함수를 나가라.
        if (s.Length == 0) return;

        // 새로운 채팅이 추가되기 전의 content의 h값을 저장.
        prevContentH = rtContent.sizeDelta.y;

        // 닉네임을 붙여서 채팅내용을 만들자
        //"<color=#fff00> 원하는 내용 </color>"
        string chat = "<color=#" + ColorUtility.ToHtmlStringRGB(nickNameColor) + ">" +
            PhotonNetwork.NickName + "</color>" + " : " + s;

        //Rpc 함수로 모든 사람한테 채팅 내용을 전달
        photonView.RPC(nameof(AddChatRpc), RpcTarget.All,chat);

        //chatInput 값을 초기화
        chatInput.text = "";

        // chatInput을 활성화
        chatInput.ActivateInputField();
    }

// 값을 서버에 던지기 위한 PunRPC
    [PunRPC]
    void AddChatRpc(string chat)
    {
        // Chatitem을 만든다.
        GameObject ci = Instantiate(chatItemFactory, rtContent);
        // 만들어진 item의 부모를 Content로 한다.
        ci.transform.SetParent(rtContent);
        // 만들어진 item에서 chatItem 컴포넌트를 가져온다.
        ChatItem item = ci.GetComponent<ChatItem>();

        //가져온 컴포넌트에서 SetText 함수 실행
        item.SetText(chat);

        // 자동으로 스크롤 내림
        StartCoroutine(AutoScrollBottom());
    }

    IEnumerator AutoScrollBottom()
    {
        // 한 프레임 지나고 나서 실행
        yield return 0;

        // scrol view의 H보다 Content의 H 값이 크다면 (스크롤이 가능한 상태라면)
        if (rtContent.sizeDelta.y > rtScrollView.sizeDelta.y)
        {
            // 이전의 바닥에 닿아있었다면 , anchroedPosition은 recttransform에서 사용하는 값
            if (prevContentH - rtScrollView.sizeDelta.y <= rtContent.anchoredPosition.y)
            {
                // content의 y값을 재설정한다.
                rtContent.anchoredPosition =
                    new Vector2(0,rtContent.sizeDelta.y - rtScrollView.sizeDelta.y);
            }
        }
    }

    // 값이 바뀔때 실행됌
    void onValueChanged(string s)
    {
        //print("onValueChanged : " + s);
    }

    void onEndEdit(string s)
    {
        //print("onEndEdit : " + s);
    }
}
```   


<br/>  

### Test      

![image](https://github.com/kcheee/kcheee/assets/86779278/9d3ff2c4-1c3b-42f0-8f36-89bb8f2cf3d8)
