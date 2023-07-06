---
layout: post
title: unity Light
categories : unity study Material
tag : [unity,직접광,간접광]
---

# Light   

**조명은 메모리를 많이 잡아 먹기 때문에 잘 써야 한다..**   



## 직접광   


### Directional Light   

- 태양과 같은 역할이다 Position은 상관 없고 Rotation으로 빛의 방향을 설정 할 수 있다.

### Point Light   

- 전구와 같은 역할. 구의 형태로 되어 있으며, Range와 Intensity로 거리와 세기조절 가능하다    
   
- Mode로 매 프레임 마다 계산해주는 Realtime Bake와 섞어쓰는 Mixed, Baked 모드가 있다.
- Shadow Type으로 그림자 설정.

### SpotLight   

- 가로등과 같은 역할이다. Point Light와 같은 설정을 가지고 있다.   
- Shadow Type으로 그림자 설정.
손전등 같은 효과를 가지고 있다.

### Area Light   

- Area 기즈모 밑 방향으로 빛이 나감.   
   
- 사각형과 원 모양으로 바꿀 수 있다.   
   
- Type은 베이크를 했을 때만 나타내 준다.   
   
- 다른 설정은 위와 같다.   

--주의--   
**겹치지 않게 설정 해야됌(조명 엔진은 무겁다..)
**
- project setting에서 퀄리티 설정에 light 개수 설정 가능.

## 간접광   

연산은 GI(Global Illumination)와 SkyBox 따로 연산을 한다.

window -> Rendering -> ligining

### GI에 관련 간접광
<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/73680959-12e4-46d4-875a-6342bef94f96">

Realtime Lighing   
 -Realtime Global lllunmination : 실시간으로 간접광, 직접광 계산   

   

### SkyBox 관련 간접광   

<img src= " https://github.com/kcheee/Study_Algorithm/assets/86779278/7d9fe8fc-e059-42ea-8d40-5837dcba21ba">     
   

<br/>   

### fog 설정   
   
![스크린샷 2023-07-06 171123](https://github.com/kcheee/kcheee/assets/86779278/392dc575-dd8c-47ca-8bef-6098b9503e68)
    
Start와 End를 통해 안개낀 느낌을 줄 수 있다.   


<br>    

## Light Bake   

**만약 고정되어 있는 물체(실시간 계산이 필요없는) Object는 **Light Bake**를 한다. -> static 설정**   

Light Bake 하기 위해서 필요 조건
   
1. Static 체크 

조명 관련된 static은 Contribute GI이다.   

![스크린샷 2023-07-06 172016](https://github.com/kcheee/kcheee/assets/86779278/09ddf74c-129f-4625-bb4c-18b7b62dc040)

2. 조명 => "bake"   
 - Mode를 baked로 설정해야됌

3. 오브젝트 UV 도화지  
<img src= "https://github.com/kcheee/ Study_Algorithm/assets/86779278/8d04380a-21f3-4338-af73-fa83196d6c1f">   
Light map을 그릴 수 있는 전용 UV 도화지를 채널을 추가한다는 의미를 가지고 있다.   

4. Lighting 설정

![image](https://github.com/kcheee/kcheee/assets/86779278/37a50fd3-b5b9-4996-a537-ab93b7afcaff)

baked Indirect : 간접광만   
subtractive : 간접광, 직접광 모두   
shadowmask : 가장 무거움.   
   
<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/73680959-12e4-46d4-875a-6342bef94f96">   
Realtime Lighting 설정을 해제해야함.   

<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/80cd89a2-7b3b-45cb-9153-3caf2cca8641">

LightMapper에서 cpu, gpu, Enlighten로 설정을 바꿀 수 있다.   

ENLIGHTEN = realtime 
     
<br/>
Lighting mapping setting   

Light bake의 퀄리티를 설정해줌.    



5. Generate Lighting   

Light 오브젝트를 제거해도 Object의 빛이 있는 것 처럼 보임.

