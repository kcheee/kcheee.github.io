---
layout: post
title: unity Lerp
categories : unity study Lerp
tag : [unity,Lerp]
---

# Lerp 선형보간.

--> 오브젝트 A의 위치가 0,0,0 에 있다고 하겠습니다. 이 오브젝트의 위치를 5,5,5로 바꾸고 싶은데 부드럽게 이동하고 싶습니다.

이 때 void Update() 내에 선형보간 함수를 사용할 수 있습니다. MomoBehavior을 상속 받은 상태여야합니다. (Update를 사용하기 위해서)


```c#
        public GameObject A; //new Vector3(0, 0, 0);
        Vector3 pos = new Vector3(5, 5, 5);

        void Awake()
        {
            A.transform.position = Vector3.zero;//new Vector3(0, 0, 0);
        }
        void Update()
        {
            A.transform.position = Vector3.Lerp(A.transform.position, pos, Time.deltaTime);
        }
```
위와 같이 입력 해 줄 수 있습니다. Time.delaTime에 1이상의 수를 곱하면 그 수가 커질 수록 보이는 속도가 빨라집니다.

이 정도만 알고 있으면 사용하는데에는 우선 문제가 없습니다. 하지만 궁금하신 분들을 위해 Vector3.Lerp 이 선형 보간 함수를 좀 더 구체적으로 설명드리겠습니다.



Vector3.Lerp(위치1, 위치2, 0~1사이의 실수) 라고 하겠습니다.



Vector3.Lerp가 반환하는 Vertor3의 값은 마지막 인자에 따라 바뀝니다.



따라서

Vector3.Lerp(위치1, 위치2, 0) = 위치1

Vector3.Lerp(위치1, 위치2, 1) = 위치2



이러한 벡터 값을 반환하게 됩니다. Vector3.Lerp(위치1, 위치2, 0.5f) = 위치1과 위치2의 중간위치 이겠지요.



Time.deltatime 은 지난 프레임이 완료되는 데 까지 걸린 시간을 나타내며, 단위는 초를 사용합니다. (읽기전용)



당연한 말이지만 이 개념을 제대로 이해해야 Time.deltatime을 이용하기가 수월합니다.



위치1 = Vector3.Lerp(위치1, 위치2, Time.deltatime)



기본적으로 Update 함수는 한프레임에 한번 호출됩니다.

Update 함수에서 인자에 Time.deltatime 을 넣어주게 되면

기존의 위치 1은 위치 2의 방향으로  둘 사이의 거리 * (전 프레임에 걸린시간) 만큼 이동하게 되는 것입니다.

예를 들어 둘사이의 거리가 10이고  전프레임에 걸린시간이 0.1f 초 였다고 가정해 보겠습니다. (=1초에 10프레임 즉 10fps인 경우입니다.)



간단하게 UpdateN = N번째 호출이라고 하겠습니다. 위치1 = 0, 위치2 = 10 이라고 하겠습니다. 방향은 단일 축으로 생각하겠습니다.



Vector3.Lerp(위치1, 위치2, Time.deltatime) 를 Uptate에 입력했을때,

(단일 축이기때문에 숫자만 변경할 시 Mathf.Lerp를 사용해도 무방합니다.)



Update0 -> 위치1 = 0

Update1 -> 위치1 = 1 // 전 프레임의 위치 +(10 * 0.1)

Update2 -> 위치1 = 1.9 // 전 프레임의 위치 +(9 * 0.1)

Update3 -> 위치1 = 2.71 // 전 프레임의 위치 +(8.1 * 0.1)

Update4 -> 위치1 = 3.439  // 전 프레임의 위치 +(7.29 * 0.1)

...

...

Update? -> 위치1 = 위치2



점점 적은 수치만큼 증가하다가 결국 위치1의 오브젝트가 위치2에 위치하게 됩니다. 여기서 Time.deltaTime에 2f를 곱해주게 되면



Vector3.Lerp(위치1, 위치2, Time.deltatime * 2f)



Update0 -> 위치1 = 0

Update1 -> 위치1 = 2 // 전 프레임의 위치 +(10 * 0.2)

Update2 -> 위치1 = 3.8 // 전 프레임의 위치 +(9 * 0.2)

Update3 -> 위치1 = 5.42 // 전 프레임의 위치 +(8.1 * 0.2)

Update4 -> 위치1 = 6.878  // 전 프레임의 위치 +(7.29 * 0.2)

...

...

Update? -> 위치1 = 위치2



정확히 원래의 속도보다 두 배 빨리 이동하는 셈입니다. 결론적으로 Time.deltaTime * Speed 정도로 생각할 수 있습니다.


