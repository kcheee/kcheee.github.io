---
layout: post
title: unity 비동기 씬 로딩하기
categories : unity study
tag : unity,비동기
---

# 비동기 씬 로딩하기

## 기본 UI setting
![텍스트](https://user-images.githubusercontent.com/86779278/223472004-b553aebb-a885-4652-a552-0dc47aaaa16a.png)

씬을 비동기 방식으로 로드하려면 <code>SceneManager</code> 클래스의 <code>LoadScene()</code> 대신 <code>LoadSceneAsync()</code> 함수를 사용해야 한다. 이 함수는 현재 로딩 중인 상태 데이터를 갖고 있는 **AsyncOperation** 타입의 클래스 변수를 반환한다. **AsyncOperation**클래스는 유니티에서 제공하는 비동기 씬 로드 코루틴이다.


```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LoadingNextScene : MonoBehaviour
{
    // 다음 씬을 비동기 방식으로 로드하고 싶다.
    // 시각적으로 표현

    public int SceneNumber = 2;

    //로딩 슬라이더 바
    public Slider loadingBar;
    //진행 텍스트
    public Text loadingText;
    private void Start()
    {
        StartCoroutine(TransitionNextScene(SceneNumber));
    }
    // 비동기 씬 로드 코루틴
    IEnumerator TransitionNextScene(int num)
    {
        // 지정된 씬을 비동기 형식으로 로드한다.
        AsyncOperation ao = SceneManager.LoadSceneAsync(num);

        // 로드되는 씬의 모습이 화면에 보이지 않게 한다.
        ao.allowSceneActivation = false;

        while (!ao.isDone)
        {
            // 로딩 진행률을 슬라이더 바와 텍스트로 표시한다.
            loadingBar.value = ao.progress;
            loadingText.text = (ao.progress * 100f).ToString() + "%";

            // 만일, 씬 로드 진행률이 90%를 넘어가면..
            if (ao.progress >= 0.9f)
                // 로드된 씬
                ao.allowSceneActivation = true;

            // 다음 프레임이 될 때까지 기다림.
            yield return null;
        }
    }
}
```
## build setting

![텍스트](https://user-images.githubusercontent.com/86779278/223472159-15673556-bc75-4fcd-856e-1b1977041f59.png)

1에 배치