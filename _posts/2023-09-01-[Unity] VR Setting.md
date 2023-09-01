---
layout: post
title: unity에서 oculus 세팅하기
categories : unity VR 
tag : [unity,VR,oculus]
---

# oculus 앱 및 SDK 설치

## 유니티
https://www.oculus.com/Setup/?locale=ko_KR   
위 링크에 가서 오큘러스 앱을 설치해준다.   
빌드 하지않고 Editor에서 실행시켜주기 위해서는 오큘러스 앱을 실행시키고 테스트를 실행해야 한다.

<br/>   

https://developer.oculus.com/downloads/package/unity-integration/   
위 링크는 유니티에서 오큘러스 퀘스트2를 실행시키기 위한 SDK이다. 다운을 받고 Import해준다.

<br/>    

# Unity

Bulid Setting -> Player Setting에 가서 XR plugin Management에서 install XR plugin Management 해준다.

![image](https://github.com/kcheee/kcheee/assets/86779278/692d847e-68dd-41e4-91ce-e23c0c7e813b)   

Oculus를 체크해준다.

![image](https://github.com/kcheee/kcheee/assets/86779278/5b2f3497-8f0b-4df5-8296-f84d2f6865f2)

Hierarchy창에 OVRPlayerController을 추가해주고 실행해주면 끝.
![image](https://github.com/kcheee/kcheee/assets/86779278/17391d78-1362-4d79-a594-777f0190297b)
