---
layout: post
title: [unity]Title UI 및 로그인 환경 만들기
categories : unity
tag : unity
---

# 로그인 씬 만들기

## UI
![텍스트](post/2023-03-07/login1.png)

아이디와 비밀번호를 입력할 Input Field를 생성하고, 회원가입과 로그인 버튼을 만들어준다.

## 변수
 ```c# 
    // 사용자 아이디 변수
    public InputField id;

    // 사용자 패스워드 변수
    public InputField password;

    // 검사 텍스트 변수
    public Text notify;

 ```

## 아이디와 비밀번호가 공란일때 체크 함수
```c#
  bool CheckInput(string id, string pwd)
    {
        // 아이디와 패스워드 입력란이 비어 있으면 사용자 정보입력을 요구
        if (id == "" || pwd == "")
        {
            notify.text = "아이디 또는 패스워드를 입력해주세요.";
            return false;
        }
        else
            return true;
    }
```

## 회원 가입 함수
```c#
   // 아이디와 패스워드 저장함수
    public void SaveUserData()
    {
        if (!CheckInput(id.text, password.text))
        {
            return;
        }
        // 만일 시스템에 저장돼 있는 아이디가 존재하지 않는다면
        if (!PlayerPrefs.HasKey(id.text))
        {
            // 사용자의 아이디는 key로 패스워드를 value으로 설정해 저장
            PlayerPrefs.SetString(id.text, password.text);
            notify.text = "아이디 생성이 완료됐습니다.";
        }
        else
            notify.text = "이미 존재하는 아이디입니다.";
    }

```
## 로그인 함수

```c#

       public void CheckUserData()
    {
        if (!CheckInput(id.text, password.text))
        {
            return;
        }
        // 사용자가 입력한 아이디를 키로 사용해 시스템에 저장된 값을 불러옴
        string pass = PlayerPrefs.GetString(id.text);
        if (password.text == pass)
        {
            // 1번 씬 로드
            Debug.Log("실행");
            SceneManager.LoadScene(1);
        }
        else
            notify.text = "입력하신 아이디와 패스워드가 일치하지 않습니다.";
    }

```


