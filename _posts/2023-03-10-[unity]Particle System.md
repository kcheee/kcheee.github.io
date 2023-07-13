---
layout: post
title: unity Particle System
categories : unity study
tag : [unity,Particle System]
---

# 파티클 시스템(particle System)

**Duration** : 지속시간. 

**Looping** :반복여부.

**Prewarm**: 예열기간. 처음부터 입자가 모두 방출된채로 시작할건지/ 서서히 방출하기 시작할건지 


**Start Delay** : 시스템이 활성화된 후 방출을 시작하기까지 기다리는 지연 시간
**Start Lifetime** :생명주기. 입자가 생성되고 언제 사라지는지

**Start speed** :입자 방출 속도


**3D Start Size**: 3D 시작 크기

 

**Start Size**: 시작 크기

- **Constant** :상수 (고정값)

- **Curve** :  곡선

- **Random Between Two Constants**: 두 상수사이에서 랜덤하게 선택.

- **Random Between Two Curves** : 두 곡선사이에서 랜덤하게 선택.


**Start Rotation** : 시작각도

 

**Start Color** : 시작 색깔

 

**Gravity Modifier**: 중력. 0으로 하면 중력 효과가 해제


**Simulation Space**:  파티클을 부모 오브젝트를 따라 이동하게 할지, 커스텀 오브젝트를 따라 이동하게 할지, 게임 월드에서 독립적으로 이동하게 할지 결정   

ex) 예를 들어 구름, 호스, 화염 방사기와 같은 시스템에서는 파티클이 부모 게임 오브젝트와 따로 움직이도록 해야함.

오브젝트가 주변을 움직이면서 파티클을 생성하더라도 생성된 파티클은 월드 공간에 잔류하는 흔적을 남기기 때문.

반면에 두 개의 전극 사이에서 생기는 불꽃을 만드는 데 사용되는 파티클이라면 부모 오브젝트와 함께 이동해야함.Custom으로 설정하면 파티클이 더 이상 자체 트랜스폼 컴포넌트에 비례하여 움직이지 않으며, 지정된 트랜스폼 컴포넌트의 움직임에 비례하여 움직임.

**Simulation Speed** :시뮬레이션 속도

 

**Delta Time**: 일시정지했을때 계속 재생시킬것인지 여부

 

**Scaling Mode**: 트랜스폼에서 스케일을 사용하는 방법을 설정

 

Hierarchy/Local/Shape

Local을 선택하면 파티클 시스템 트랜스폼 스케일만 적용되고 부모는 무시

Shape을 선택하면 파티클의 시작 포지션에 스케일이 적용되지만 크기에는 영향X.

 

**Play on Awake**: 씬 시작할때 재생시킬것인지 여부

 

**Emitter Velocity**: 파티클 시스템이 이동할 경우 속도 계산을 트랜스폼 기반으로 할지, 리지드바디(물리) 기반으로 할지 결정한다.


**Max Particles**:동시에 활성화되있는 최대 입자수

 

**Auto Random Seed**:활성화하면 파티클 시스템을 재생할 때마다 시스템이 조금씩 다르게 표시됨. 비활성화하면 시스템을 재생할 때마다 파티클 시스템이 똑같이 보임.

 

**Stop Action**: 시스템에 속한 모든 파티클이 완료되어 시스템이 중지되었을 때 특정 동작을 수행하도록 설정

Particle system을 정지시켰을때 게임 오브젝트의 상태 결정 

 

None

Destroy(파괴)

Disable(비활성화)

Callback(OnParticleSystemStopped 콜백을 게임 오브젝트에 연결된 스크립트로 전송)

**Culling Mode** :파티클이 화면을 벗어나면 파티클 시스템 시뮬레이션을 일시정지할지 여부

 
**Ring buffer Mode** :파티클이 Max Particles 수에 도달할 때까지 파티클을 계속 활성화. Max Particles 수에 도달하면 수명이 경과한 파티클을 제거하는 대신 가장 오래된 파티클을 재활용하여 새 파티클을 생성함.   

Disabled : 시스템이 수명이 경과한 파티클을 제거하도록 Ring Buffer Mode 를 비활성화합니다.   

Pause Until Replaced : 수명을 다한 오래된 파티클을 일시정지했다가 Max Particle 한계에 도달하면 시스템에서 재활용하여 새 파티클로 다시 표시되게 합니다.   

Loop Until Replaced	: 수명을 다한 파티클이 특정한 수명 비율 지점으로 다시 돌아가며, Max Particle 한계에 도달하면 시스템에서 재활용하여 새 파티클로 다시 표시되게 합니다.
## 모듈

<img src = "https://user-images.githubusercontent.com/86779278/224129805-03deb320-e65f-4e4a-ba43-34cc8ba5a619.png">

<br/>   

**Emission** : 파티클 시스템의 방출 속도와 타이밍   

1 | 2
--:|--|
Rate over Time| 시간 단위당 방출되는 파티클의 수   
Rate over Distance| 이동한 거리 단위당 방출되는 파티클의 수
Bursts| 파티클을 생성하는 이벤트. 이 설정을 통해 지정된 시점에 파티클을 방출함
Time|파티클 시스템이 시작된 이후로 버스트를 방출할 시점을 초 단위로 설정
Count |방출되는 파티클 수를 설정
Cycles|  반복할 횟수
Interbal| 버스트가 반복되는 시간 사이의 간격(초)
Probability| 각 버스트 이벤트가 파티클을 생성할 가능성을 제어 값이 클수록 시스템이 더 많은 파티클을 생성, '1'이 최대 (100%)

<img src = "https://user-images.githubusercontent.com/86779278/224132246-08d7ec6d-bb28-4993-b77c-3acf954e88bd.png">
<img src = "https://user-images.githubusercontent.com/86779278/224132250-81e4c4b8-028b-4446-8c9a-106dc9de34ff.png">   

<br/>   


**Shape** : 파티클 시스템이 방출될 수 있는 체적 또는 표면과 시작 속도의 방향을 정의

<img src = "https://user-images.githubusercontent.com/86779278/224130032-bc59dbb0-fc14-466d-bd9c-da28581c90af.png">   

Shape :방출 볼륨의 모양

Angle: 방출 볼륨의 각도

Radius :입자들이 뿜어져 나오는 원의 범위   

Postion/Rotation /Scale: 방출볼륨의 위치,회전각,규모(크기)

**Velocity over Lifetime** : 파티클의 수명 주기에 걸친 속도 조절

**Velocity over Lifetime** : 파티클의 수명 주기에 걸친 속도 조절

Liner : X축, Y축, Z축에 있는 파티클의 직선속도   

Orbital : X축, Y축, Z축 주위에 있는 파티클의 궤도 속도   

Offset : 궤도를 따라 파티클을 회전시키기 위한 궤도의 중앙 포지션   

<img src = "https://user-images.githubusercontent.com/86779278/224131595-fa49a295-0870-4949-8978-74ae72ff5b98.png">

<img src = "https://user-images.githubusercontent.com/86779278/224131061-8b02610e-0b56-4041-ab18-e18e466c7c20.gif">   

<br/>   

**Limit Velocity over Lifetime** : 파티클의 속도가 전체 수명 동안 어떻게 감소되는지 제어   

drag : 저항값, 시간이 지날수록 점점 speed를 낮춤

**Force over Lifetime** : 파티클의 움직임은 이 모듈에서 설정된 힘에 의해 가속화   
(speed와 다른개념.)ex) 바람이나 인력

**Color over Lifetime** : 시간에 따른 색깔변화   

<img src = "https://user-images.githubusercontent.com/86779278/224131754-5e680b46-7677-4c74-97aa-02594942a8ac.png">    

alpha 값으로 색깔이 희미해지게 만들수 있다.(최대값 : 255)   


**Size over Lifetime** : 시간에 따른 크기 변화 -> 그래프로 표현 가능


**Ingerit Velocity Module(속도 상속 모듈)** : 시간이 지남에 따라 파티클의 속도가 부모 오브젝트의 움직임에 반응하는 방식을 제어, 시간이 지남에 따라 천천히 표류. ex) 자동차의 먼지 구름, 로켓의 연기, 증기 기관차 굴뚝의 증기.   
***(Simulation Space)*** 가 Main 모듈에서 World로 설정된 경우 입자에만 영향을 미친다.

mode : 속도가 입자에 적용되는 방법을 지정한다.

mode_unitlal : 각 입자가 생성될 때 이미터 속도가 한 번 적용.   

Mode_Current : 현재 속도는 모든 프레임의 모든 입자에 적용된다. 이미터가 느려지면 모든 입자도 느려진다.   

<img src = "https://user-images.githubusercontent.com/86779278/224131178-6031232a-3003-4ca1-a902-6e622d9c88df.gif">
<img src = "https://user-images.githubusercontent.com/86779278/224131193-9762fb53-29e0-4a5d-aadc-4462fbbfa519.gif"> 


**Size by Speed** : 사이즈에 따른 속도 조절   

**Rotation by Speed** : 회전 조절

**External Forces** : 윈드존에 영향을 받는 정도를 설정한다.   
Game Object -> 3D -> Wind Zone   

**Nosie** : particle의 노이즈효과(움직임 방해) 파티클에 불규칙적인 움직임을 연출한다.

<img src = "https://user-images.githubusercontent.com/86779278/224132794-522dd9fa-46fa-4ef2-a1e4-6cb03cc8f630.gif">    


**Collision** : 입자의 충돌여부   

**Triggers** : 충돌했을 경우 특정 이벤트 실행
Inside : 콜리더에 닿는순간.

Outside :콜리더에 닿지 않는순간

Enter : 들어올때

Exit :들어왔다 빠져나갈때 

kill(없음) /ignore(무시)/callback 

+onTriggerExit와 같은 함수를 이용해 특정 장치가 실행되도록 할수도있다.


**Sub Emitters** : 입자들의 입자 

EX) 폭탄이 땅에 착지하고 터질때 . 미사일의 잔해가 다른 곳으로 날라가서 또 폭발을 일으킬때

**Texture Sheet Animation** :입자를 sprite로 바꿀수 있도록함.   

<img src ="https://user-images.githubusercontent.com/86779278/224134389-1359210c-9cc3-469a-86a6-47cc4932790e.png">   


**Light** : 파티클에 실시간 광원을 추가
Ratio : 광원이 붙어있을 확률 1=100%

**Trail** : 입자가 지나간 흔적을 표시

Ratio :흔적을 표시할 확률

Minimum Vertex Distance :잔상에 새로운 버텍스가 추가되기까지 파티클이 이동해야 하는 거리를 정의.최적화같은것. 0에 가까울수록 과부하 , 1에 가까울수록 나아짐.

Texture Mode : 여러가지효과 tile/segment/stretch 등등

Color over Lifetime :잔상이 추가된 파티클의 수명에 따라 전체 잔상의 색상을 제어

Width over Trail : 잔상의 너비를 길이에 따라 제어

Color over Trail : 잔상의 컬러를 길이에 따라 제어

처음에 무작정 적용시키면 자주색으로 그래픽이 깨져서 보이는데 그건 render module 의 Trail Material 을 설정해주지 않아서 그렇다. 


**Renderer**     

Render Mode :렌더링된 이미지가 그래픽 이미지나 메시에서 생성되는 방식

Stretched Billboard:파티클은 항상 카메라를 향하지만, 다양한 스케일이 적용

Horizontal Billboard:파티클 평면과 XZ “바닥” 평면이 평행해짐 
-> = 위에서 아래로 내려다봐야 보임

Vertical Billboard : 파티클이 월드 Y축에 똑바로 서 있지만 카메라를 향함.
-> xy 평면을바라보아야 보임.


Render Alignment :파티클 빌보드가 어느 방향을 향하고 있는지 선택
c1|c2
--|--|
View |파티클은 카메라 평면을 향합니다.   
World	|파티클은 월드 축과 정렬됩니다.   
Local	|파티클은 해당 게임 오브젝트의 Transform 컴포넌트에 따라 정렬됩니다.   
Facing | 파티클은 카메라 게임 오브젝트의 정면을 향합니다.

Masking : 가려지게하는거

Cast Shadow:활성화하면 파티클 시스템은 섀도우 캐스팅 광원이 빛날 때 섀도우를 만듬.Receice Shadows : 다른것에 의해 그림자 영향을 받을것인가Sorting Layer/Order in Layer :우선순위 결정Light Probes : 프로브 기반 조명 보간 모드Reflection Probes :이 옵션이 활성화되어 있고 반사 프로브가 씬에 존재할 경우 이 게임 오브젝트에 대한 반사 텍스처가 선택되고 빌트인 셰이더 uniform 변수로 설정

Pivot : 회전하는 파티클의 중심 피벗 포인트를 수정