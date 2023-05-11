---
layout: post
title: unity Light
categories : unity study Material
tag : [unity,직접광,간접광]
---

# Light   

조명은 메모리를 많이 잡아 먹기 때문에 잘 써야 한다..   


## 직접광   


### Directional Light   

- 태양과 같은 역할이다 Position은 상관 없고 Rotation으로 빛의 방향을 설정 할 수 있다.

### Point Light   

- 전구와 같은 역할. 구의 형태로 되어 있으며, Range와 Intensity로 거리와 세기조절 가능하다    
   
- Mode로 매 프레임 마다 계산해주는 Realtime Bake와 섞어쓰는 Mixed, Baked 모드가 있다.
- Shadow Type으로 그림자 설정.

### SpotLight   

- 가로등과 같은 역할이다. Point Light와 같은 설정을 가지고 있다.

### Area Light   

- Area 기즈모 밑 방향으로 빛이 나감.   
   
- 사각형과 원 모양으로 바꿀 수 있다.   
   
- Type은 베이크를 했을 때만 나타내 준다.   
   
- 다른 설정은 위와 같다.   

## 간접광   

연산은 GI와 SkyBox 따로 연산을 한다.

window -> Rendering -> liginging

### GI에 관련 간접광
<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/73680959-12e4-46d4-875a-6342bef94f96">

Realtime Lighing   
 -Realtime Global lllunmination : 실시간으로 간접광, 직접광 계산   

   

### SkyBox 관련 간접광   

<img src= " https://github.com/kcheee/Study_Algorithm/assets/86779278/7d9fe8fc-e059-42ea-8d40-5837dcba21ba">     
   

    
<br>    

## Light Bake   

**만약 고정되어 있는 물체(실시간 계산이 필요없는) Object는 **Light Bake**를 한다.**   

Light Bake 하기 위해서 필요 조건
   
1. Static 체크   

2. 조명 => "bake"   
 - Mode를 baked로 설정해야됌

3. 오브젝트 UV 도화지  
<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/8d04380a-21f3-4338-af73-fa83196d6c1f">   
Light map을 그릴 수 있는 전용 UV 도화지를 채널을 추가한다는 의미를 가지고 있다.   

4. Lighting 설정   
<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/73680959-12e4-46d4-875a-6342bef94f96">   
Realtime Lighting 설정을 해제해야함.   

<img src= "https://github.com/kcheee/Study_Algorithm/assets/86779278/80cd89a2-7b3b-45cb-9153-3caf2cca8641">      

Lighting mapping setting   

Light bake의 퀄리티를 설정해줌.    



5. Generate Lighting   

Light 오브젝트를 제거해도 Object의 빛이 있는 것 처럼 보임.

