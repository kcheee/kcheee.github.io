---
layout: post
title: unity Material
categories : unity study Material
tag : [unity,Material,Shader,PBS,PBR]
---

# Material

## 1. Materials 

- 어떤 텍스처를 얼마나 타일링하며 표면의 질감처리 설정
- 해당 Material을 표현할때 사용할 Shader 타입을 설정하면 이에 따라 조절 가능한 속성이 달라짐
- 설정이 끝난 Material은 게임오브젝트에 붙어있는 Mesh Renderer 컴포넌트로 전달되어 Mesh를 렌더링하는데 사용

## 2. Shaders

- Material, Lighting 정보를 기반으로 픽셀마다 어떤 색상으로 표현할지 계산하는 수식과 알고리즘으로 구성된 스크립트

## 3. Textures

- 오브젝트의 표면에 대한 정보를 담고 있는 비트맵 이미지
- Texture/Atlas에서 원하는 부분만 선택저으로 사용 가능(UV Mapping)

***

## 물리 기반 렌더링 **PBR(Physically Basic Renderering)**

컴퓨터에서는 빛이 물체 표면에 반사되는 경로를 물리적인 공식을 이용해 계산하고, 그 결과를 Material를 통해 표현한다.

  ![텍스트](https://user-images.githubusercontent.com/86779278/223753835-e66f13ea-9ba0-4bd6-a2be-90fcbb38b190.png)


PBR이전의 물리적인 계산


<img src="https://user-images.githubusercontent.com/86779278/223754092-2f566dc2-d211-4ad9-a994-09781c699954.png" width=300>
<img src="https://user-images.githubusercontent.com/86779278/223755022-a924d4a3-e277-434e-a998-d6deb38591af.png" width=300>


이러한 PBR에 사용하는 셰이더를 **PBS(Physically Basic Shader)** 라고 한다.

PBS의 특징은 **Alvedo,Metallic, Smoothness** 등등이 있다.

<br/>


***
<br/>

## Rendering Mode : Material의 투명 속성 설정
<br/>

**Opaqque** : 투명한 부분이 없는 일반 물체를 표현(default)

**Cutout** : 불투명한 부분과 투명한 부분이 섞인 물체를 표현. 투명도는 중간값이 없으며 0% 아니면 100%이다. 나뭇잎이나 찢어진 조각들을 표현하는데 적합. 무조건 0과 1로써 페이드와 비교 할 수 있다. fade보다 가볍다.

**Transparent** : 투명한 물체를 표현. texture의 알파 채널과 tint color의 알파값에 따라 투명도가 조절된다. 실제 투명한 물체와 마찬가지로 빛의 반사가 일어난다.   

Ex) 창문 텍스처의 경우 유리창은 투명하고 창틀은 불투명해야한다. 텍스쳐에 Transparent를 적용하면 알파 채널의 검은 부분은 투명하게, 흰 부분은 불투명하게 표현된다. 따라서 알파 채널에서 유리창은 검은색으로, 창틀은 흰색으로 표현하면 유리창만 투명하게 표현된다.

**Fade** : 투명도를 페이드 인/아웃하는 애니메이션을 적용할 수 있다. 빛의 반사도 함께 변화하기에 항상 투명해야하는 물체에는 적합하지 않다. 0부터 1까지 설정 할 수 있다.   
 *홀로그램 효과 적용가능*

**Albedo** : 빛을 반사하는 정도(반사율)를 설정. 표면의 기본 색상을 설정할 수 있지만 일반적으로 색상보다 텍스처를 연결하는 방식으로 설정. 빛이나 그림자 효과가 없을 때의 표면 상태이다. 현실 세계의 모든 물체는 각기 다른 빛 반사율을 가진다는 것에서 착안   
bulit in : albedo   &nbsp;
URP : base color   &nbsp;

**Specular** : Specular stepup 모드에서만 보이는 설정. 광원으로부터 빛을 받은 물체가 빛을 거울처럼 반사하는 설정. *Smoothness*로 반사 정도 조절 가능. 텍스처의 일부만 반짝이게 만들고 싶은 경우는 (EX ( 옷의 단추만 반짝이게 만들고 싶은 경우) Specular에 의해 적용받을 부분을 표시한 텍스처를 연결. 텍스처를 연결할 경우 Specular, Smoothness 속성은 더 이상 인스펙터 뷰에서 조절할 수 없다. 대신 RGB 채널ㄹ이 Specular(반사관의 색상)를, 알파 채널이 Smoothness(질감에 따른 반사정도)를 제어한다. 텍스처가 연결되지 않은 경우 속성으로 설정한 값이 표면 전체에 균일하게 적용.

<img src="https://user-images.githubusercontent.com/86779278/223757672-e5d657b7-1827-4bbc-9fa3-f8699daaaf7f.png">

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Specular Mode : Smoothness 값 조절에 따른 변화

<br/>


**Metallic** : 비금속/금속을 포함한 모든 물체의 표면에 관한 설정(단지 금속성 물체만을 위한 설정이 아니다.) Mettallic 값을 높이면 표면에 주변 환경을 더 많이 투영하며 Albedo는 더 적게 표한됨. 값을 낮추면 주변환경을 더 적게 투영하며 Alvedo와 표면 반사가 뚜렷하게 표현된다. 특정 부분만 금속성을 부여하고 싶은 경우 금속 부분만 밝게 표한한 텍스처를 연결한다. 텍스처를 연결할 경우 Mettalic와 Smoothness 속성은 Inspector창에서 조절할 수 없다. 대신 텍스처의 Red 값이 Metallic을, 알파 채널이 Smoothness를 제어(Green,blue값은 무시). 텍스처가 연결되지 않은 경우 속성으로 설정한 값이 표면 전체에 균일하게 적용



<img src="https://user-images.githubusercontent.com/86779278/223757043-ddd010fe-2d26-43ff-9d21-ea9252ef22b1.png">

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Metallic 값 조절에 따른 변화 

<br/>

**Smoothness** : Metallic, Specular Mode에 상관없이 microsurface detail or 부드러움 정도를 조절한다.

*microsurface detail* 이란 표면의 미세한 굴곡 정도에 따라 반사되는 빛의 방향을 다르게 표현하는 것이다.
표면이 부드러우면 microsurface detail 이 낮고 반사되는 빛의 방향이 일정하며, 빛이 모여있어서 주변 환경을 또렷하게 투영한다. 반대로 표면이 거칠면 microsurface detail이 높고 빛이 여러 각도로 반사된다. 텍스처를 추가하여 부분에 따라 다르게 값을 조절할 수 있다.   
source : Smoothness 값을 어떤 텍스처의 알파채널에서 불러올지 설정   
Specular/Metallic Alpha : Smoothness는 단일한 값이기 때문에 하나의 채널만 필요로 하며, 따라서 일반적으로 Specular/Metallic 텍스처의 알파값에 저장.   
Albedo Alpha : Albedo 텍스처의 알파값에 저장   
Highlights : 체크할 경우 Highlights 계산을 하지 않는다. 모바일 기기를 위한 최적화 옵션
Relections : 체크할 경우 Reflections 계산을 하지 않는다. 모바일 기기를 위한 최적화 옵션 


<img src="https://user-images.githubusercontent.com/86779278/223758322-2801876b-e2c9-4ed1-aaae-6938e7971854.png">

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Smoothness 값 조절에 따른 변화 

<br/>

<img src="https://user-images.githubusercontent.com/86779278/223757658-ecb189cd-f9eb-43f3-8c7e-5c5827339f83.png">

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Smoothness 값 조절에 따른 microsurface detail 차이

<br/>

**Normal Map** : Bump Map의 하나로서, 물체 표면의 돌출(bump), 홈, 스크래치를 별도의 텍스처로 표현한다.
EX) 항공기 선체의 나사 하나, 굴곡 하나 등등 표현하는 것만 해도 수많은 폴리곤이 사용되기 때문에 비용이 너무 크다. 표면이 실제로는 평면이지만 폴리곤의 굴곡을 텍스처로 투사시켜 컴퓨터한테 착시를 주는 것이 Nomal Map이다. 적은 수의 폴리곤을 갖고도 마치 폴리곤을 많이 써서 표현한 것 같이 컴퓨터를 속이는 기술이다.
Texture Type을 Nomal Map으로 바꿔야 한다.

**Normal Map 추출**   
![스크린샷 2023-07-06 160559](https://github.com/kcheee/kcheee/assets/86779278/816b56f1-7d6a-499e-98e6-1ba7cbafbee5)

이미지 타입을 nomal map으로 바꾸고 Grayscale을 체크

<img src="https://user-images.githubusercontent.com/86779278/223758854-318accbc-e8d3-4ea5-9b7e-5d1f58ea440e.png" width =500>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;좌 : 400만개의 폴리곤 중 : 500개의 폴리곤 우 : 500개의 폴리곤과 노멀맵

<br/>

**Height Map** : parallax mapping이라고도 불린다. **normal mapping과 유사하지만 기술적으로 더 복잡하고 비용도 더 많이 든다.** 보통 Nomal Map과 동시에 사용된다. 특정 영역을 들어 올리는 방식으로 입체감을 부여하며
들어올려진 영역에 의해 반대쪽 영역이 가려지는 효과까지 계산된다. 단, 폴리곤의 평면적은 표면에만 사용하는 걸 권장한다. 왜냐하면 Height Map을 적용해도 실제 mesh는 변형되지 않기에 평면으로 볼 때는 돌출된 입체감이 느껴지는 반면 물체의 실루엣은 밋밋하게 보이기 때문이다.   
요약해서 높낮이를 표현해 준다.

<img src="https://user-images.githubusercontent.com/86779278/223760039-9971520a-4d8a-42fe-a351-bf82cdf7cf2a.png">
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;좌 : Albedo only              중 : Albedo + NoMal Map        우 : Albedo + Nomal Map + Height Map

<br/>

**Occlusion Map** : 모델의 어느 영역에 간접사광(indirect lighting)의 영향을 더 크게 또는 더 적게 적용할지 설정. 간접광은 ambient lighting이나 reflelction에 의해 발생한다. grey 스케일 이미지로 표현되는 Occlusion Map에서 하얀 부분이 간접광을 많이 받는 부분이다.

<img src = "https://user-images.githubusercontent.com/86779278/223760966-d7ab1acb-e0f9-4708-88ab-6d72493bddd7.png">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;우측이 적용 후

<br/>

**Emission** : 표면에서 방출되는 빛의 색상과 강도를 설정한다. 씬 내에 Emission이 적용된 Material이 잇다면 해당 Material이 마치 빛을 방출하는 것처럼 표현된다. 모델의 특정 부분이 내부로부터 빛을 발생시키는 것처럼 보여야하는 경우 사용한다. EX) 게임 속 켜져있는 모니터 화면을 표현할 때, 어둠 속 빛나는 눈 등등. 색상과 밝기는 emission map texture의 설정을 따른다. Global illumination을 Realtime으로 설정하면 이 효과로 인해 방출되는 빛이 실시간 전역 조명으로 계산되어 근처의 게임오브젝트에 영향을 주며, Baked로 설정하면 근처의 static 게임 오브젝트에만 영향을 준다.

<img src = "https://user-images.githubusercontent.com/86779278/223761139-c965db75-4963-4494-903d-2156cf84ff52.png">

