---
layout: post
title: unity Json
categories : unity Json 
tag : [unity,Json]
---

# Json

## json 기본구조   

정수, 실수, 문자열, 배열, bool, null타입의 데이터 타입 지원

```json
{
    "id":"wergia",
    "level":10,
    "exp":33.3,
    "hp":400,
    "items":
    [
        "Sword",
        "Armor",
        "Hp Potion",
        "Hp Potion",
        "Hp Potion"
    ]
}
```

Json은 주석을 지원하지 않기 때문에 Json 검사기를 통해 검사를 하는걸 추천.

유니티가 지원하는 json형태로 데이터 변환   

<br/>

```c#
        myInfo = new UserInfo();

        myInfo.userName = "강찬희";
        myInfo.age = 20;
        myInfo.height = 186;
        myInfo.gender = false;
        myInfo.favoriteFood = new List<string>();
        myInfo.favoriteFood.Add("피자");
        myInfo.favoriteFood.Add("소");
        myInfo.favoriteFood.Add("돈까스");

        // myInfo 를 Json 형태로 만든다.
        string jsonData = JsonUtility.ToJson(myInfo,true);
        print(jsonData);

```  

<br/>   

data를 json화 시켜주는 메서드.
**JsonUtility.ToJson(myInfo,true))** JsonUtility.ToJson(myInfo,false)) 로 parsing 하는게 좋다.


## Json화 시킨 데이터 파일로 저장

```c#
  
    // 나의 정보
    public UserInfo myInfo;

     // myInfo 를 Json 형태로 만든다.
            string jsonData = JsonUtility.ToJson(info, true);
            print(jsonData);
            // jsonData를 파일로 저장
            FileStream file = new FileStream(Application.dataPath + "/myInfo.txt", FileMode.Create);

            // json string 데이터를 byte 배열로 만든다.
            byte[] byteData = Encoding.UTF8.GetBytes(jsonData);
            // bydata를 file에 쓰자
            file.Write(byteData, 0, byteData.Length);

            file.Close();

``` 

<br/>   
   
## Json화 시킨 데이터 파일로 불러오기.

```c#
            // myInfo.txt를 읽어오자
            FileStream file = new FileStream(Application.dataPath + "/myInfo.txt", FileMode.Open);

            // file의 크기만큼 byte 배열을 할당한다. file.length는 myInfo.txt의 크기와 같다.
            byte[] byteData = new byte[file.Length];
            // byData에 file의 내용을 읽어온다.
            file.Read(byteData,0, byteData.Length);
            // 파일을 닫아주자
            file.Close();

                        // byteData를 문자열로 바꾸자.
            string jsonData = Encoding.UTF8.GetString(byteData);

            // 문자열로 되어있는 jsonData를 myInfo에 parsing 한다. UserInfo 구조체에 맞게.
             myInfo = JsonUtility.FromJson<UserInfo>(jsonData);

```    

<br/>   

### 예제   

```c#
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using UnityEngine;

// 랜덤하게 만들어지는 오브젝트의 정보
[System.Serializable]
public class ObjectInfo
{
    public int type;
    public Transform tr;
}

[System.Serializable]
public class SaveInfo
{
    public int type;
    public Vector3 pos;
    public Quaternion rot;
    public Vector3 scale;
}

[System.Serializable]
public class JsonList<T>
{
    public List<T> data;
}

public class ObjectSaveLoad : MonoBehaviour
{
    public List<ObjectInfo> objectList = new List<ObjectInfo>();

    private void Update()
    {
        // 1번키 누르면 랜덤한 모양, 크기 위치, 회전이 된 오브젝트 만들자
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            // 모양을 랜덤하게 뽑자. (0 - 3) 
            int type = Random.Range(0, 4);

            for (int i = 0; i < 10; i++)
            {

            // type 모양으로 Gameobject 만들자
            GameObject go = GameObject.CreatePrimitive((PrimitiveType)type);

            // 크기 위치 회전 랜덤하게 설정
            go.transform.localScale = Vector3.one * Random.Range(0.5f, 2.0f);
            go.transform.position = Random.insideUnitSphere * Random.Range(1.0f, 20.0f);
            go.transform.rotation = Random.rotation;

            // 만들어진 오브젝트의 정보를 List에 담자.
            ObjectInfo info = new ObjectInfo();
            info.type = type;
            info.tr = go.transform;
            objectList.Add(info);
            }

        }

        // 데이터 저장
        if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            List<SaveInfo> saveInfoList = new List<SaveInfo>();
            // objectList 를 기반으로 저장할 정보를 빼오자
            for (int i = 0; i < objectList.Count; i++)
            {
                SaveInfo saveinfo = new SaveInfo();
                saveinfo.type = objectList[i].type;
                saveinfo.pos = objectList[i].tr.position;
                saveinfo.rot = objectList[i].tr.rotation;
                saveinfo.scale = objectList[i].tr.localScale;

                saveInfoList.Add(saveinfo);

            }
            //saveInfoList를 이용해 JsonData로 만들자.
            JsonList<SaveInfo> jsonList = new JsonList<SaveInfo>();
            jsonList.data = saveInfoList;

            string jsonData = JsonUtility.ToJson(jsonList, true);
            print(jsonData);

            FileStream file = new FileStream(Application.dataPath + "/ObjectInfo.txt", FileMode.Create);

            // json string 데이터를 byte 배열로 만든다.
            byte[] byteData = Encoding.UTF8.GetBytes(jsonData);
            // bydata를 file에 쓰자
            file.Write(byteData, 0, byteData.Length);

            file.Close();
        }

        // 데이터 불러오기
        if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            FileStream file = new FileStream(Application.dataPath + "/ObjectInfo.txt", FileMode.Open);

            // file의 크기만큼 byte 배열을 할당한다. file.length는 myInfo.txt의 크기와 같다.
            byte[] byteData = new byte[file.Length];
            // byData에 file의 내용을 읽어온다.
            file.Read(byteData, 0, byteData.Length);
            // 파일을 닫아주자
            file.Close();

            // byteData를 문자열로 바꾸자.
            string jsonData = Encoding.UTF8.GetString(byteData);
            print(jsonData);

            // JsonData를 이용해서 JsonList에 parsing 하자
            JsonList<SaveInfo> jsonList = JsonUtility.FromJson<JsonList<SaveInfo>>(jsonData);

            // jsonList.data 의 갯수 만큼 오브젝트를 생성하자.
            for (int i = 0; i < jsonList.data.Count; i++)
            {
                // type 모양으로 Gameobject 만들자
                GameObject go = GameObject.CreatePrimitive((PrimitiveType)jsonList.data[i].type);

                // 데이터를 가져와 값을 넣어 준다.
                go.transform.localScale = jsonList.data[i].scale;
                go.transform.position = jsonList.data[i].pos;
                go.transform.rotation = jsonList.data[i].rot;
            }
        }
    }
}


```