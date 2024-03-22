---
layout: post
title: unity UnityWebRequest받아온 Json데이터 처리
categories : unity study http통신 
tag : [unity,webRequest,GET,POST,PUT,DELETE,Json]
---

# UnityWebRequest

https://jsonplaceholder.typicode.com   
에서 UnityWebRequest 하여 Json 데이터를 가져온다.


웹 통신하기 위해 타입과 정보를 갱신하기 위한 클래스
**HttpManager**
```c#
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEditor.PackageManager.Requests;
using UnityEngine;
using UnityEngine.Networking;


// json 값을 저장해주는 키값
[Serializable]
public class JsonList<T>
{
    public List<T> data;
}

// json 데이터를 담을 수 있는 구조체
[Serializable]

public struct commentInfo
{
    public int PostId;
    public int id;
    public string name;
    public string email;
    public string body;
}
[Serializable]
public struct SignUpInfo
{
    public string userName;
    public string birthday;
    public int age;
} 


public enum RequestType
{
    GET, POST, PUT, DELETE,TEXTURE
}

// 웹 통신하기 위한 정보
public class HttpInfo
{
    public RequestType requestType;
    public string url ="";
    public string body;
    public Action<DownloadHandler> onReceive;


    public void Set(
       RequestType type, string u, Action<DownloadHandler> callback,bool useDefault=true)
    {
        requestType = type;
        if(useDefault) url = "https://jsonplaceholder.typicode.com" + u;
        url += u;
        onReceive = callback;
    }
}

public class HttpManager : MonoBehaviour
{
    static public HttpManager instance;
    public static HttpManager Get()
    {
        if (instance == null)
        {
            GameObject go = new GameObject("HttpStudy");
            go.AddComponent<HttpManager>();
        }

        return instance;
    }


    private void Start()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
    }

    public void SendERequest(HttpInfo httpinfo)
    {
        StartCoroutine(COSendRequest(httpinfo));
    }

    IEnumerator COSendRequest(HttpInfo httpinfo)
    {

        UnityWebRequest req = null;

        // POST, GET, PUT, DELETE 분기
        switch (httpinfo.requestType)
        {
            // 데이터 가져올떄
            case RequestType.GET:
                req = UnityWebRequest.Get(httpinfo.url);
                break;
                // 데이터 보낼때
            case RequestType.POST:
                req = UnityWebRequest.Post(httpinfo.url, httpinfo.body);
                byte[] byteBody = Encoding.UTF8.GetBytes(httpinfo.body);
                req.uploadHandler = new UploadHandlerRaw(byteBody);
                // 헤더 추가, 헤더를 맞춰줘야 함.
                req.SetRequestHeader("Content-Type", "application/json");
                break;
            case RequestType.PUT:
                req = UnityWebRequest.Put(httpinfo.url, httpinfo.body);
                break;
            case RequestType.DELETE:
                req = UnityWebRequest.Delete(httpinfo.url);
                break;
            case RequestType.TEXTURE:
                req = UnityWebRequestTexture.GetTexture(httpinfo.url);
                break;
        }

        //서버에 요청을 보내고 응답이 올때까지 양보한다
        yield return req.SendWebRequest();
        if (req.result == UnityWebRequest.Result.Success)
        {
            //print("네트워크 응답 : " + req.downloadHandler.text);
            if(httpinfo.onReceive != null)
            {
                httpinfo.onReceive(req.downloadHandler);
            }
        }
        else print("네트워크 에러 : " + req.error);
    }

}

```


![image](https://github.com/kcheee/kcheee/assets/86779278/0c969aed-18c3-4193-b920-390397e6b7e2)


## POST

## PUT

## DELETE






## Texture 가져오기

Texture는 json 데이터로 가져오지 못하기 때문에 ((DownloadHandlerTexture)downloadHandler) 형 변환을 해준다.

```c# 
// button
    public void OnClickDownloadimage()
    {
        // https://via.placeholder.com/150/92c952
        HttpInfo info = new HttpInfo();

        info.Set(RequestType.TEXTURE, "https://via.placeholder.com/150/92c952", OncompleteDownloadTexture, false);
        HttpManager.Get().SendERequest(info);
    }

    // 텍스쳐는 json 형태가 아니므로 이런식으로 parsing
    void OncompleteDownloadTexture(DownloadHandler downloadHandler)
    {
        // 다운로드된 image 데이터를 sprite로 만든다.
        // texture2d -> sprite
        Texture2D texture = ((DownloadHandlerTexture)downloadHandler).texture;

        downloadimg.sprite = Sprite.Create(texture, new Rect(0, 0, texture.width, texture.height), Vector2.zero);
    }
```

![image](https://github.com/kcheee/kcheee/assets/86779278/44e358bf-6bd2-4890-ae67-cf23a9d111a3)

