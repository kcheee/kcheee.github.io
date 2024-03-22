---
layout: post
title: Mobile Touch입력기술
categories : unity Mobile Touch
tag : [Mobile,Touch]
---

# 모바일 터치 입력 기술
   
## Touch 구조체   

deltaPosition   
마지막 위치로부터 움직인 위치 변위 값 

deltaTime   
마지막 변경 이후부터 경과된 시간 

fingerId  
손가락의 고유 인덱스(터치별로 고유 값이 설정됨) 

phase   
터치의 유형(터치 시작, 종료, 취소, 오래 누르기) 

position   
터치의 좌표(픽셀 단위) 

tapCount   
탭의 수 

## Input.touches   

- Touch 구조체 배열을 반환함

- 한번에 여러 개의 손가락 터치를 처리하기 위해서 배열로 넘어옴.

- 스크린 한번의 터치를 발생시키면 Input.touches[0]으로 

- 첫 번째 터치 정보를 알 수 있음.

## Input.touchCount (입력)   
터치된 개수 int반환

## Input.GetTouch 함수
손가락 터치의 인덱스를 받는다.   
다중 터치 이벤트를 처리할 때 인덱스를 사용하여 각 손가락 터치를 구분할 수있다!

## TouchPhase   
 터치의 유형을 정의한 열거형   

Began  
스크린에 터치 시작 

Moved   
스크린에 터치 후 이동하는 상태

Stationary  
터치 후 이동하지 않고 계속 터치하고 있는 상태 

Ended  
터치를 종료했을 때 

Canceled  
터치가 취소되었을 때 

ex)
```c# 
        switch (touch.phase)
        {
            case TouchPhase.Began:
                break;
            case TouchPhase.Moved:
                break;
            case TouchPhase.Ended:
                break;
            case TouchPhase.Stationary:
                break;
            case TouchPhase.Canceled:
                break;
        }
            
```
           

   


[유니티 Touch공식문서](https://docs.unity3d.com/ScriptReference/Touch.html)