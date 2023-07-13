---
layout: post
title: unity PostProcessing
categories : unity study PostProcessing
tag : [unity,PostProcessing]
---


# PostProcessing
기본적으로 무거우니 조심해서 사용.   

bulit in은 따로 postprocessing을 받아야한다.   

URP,HDRP는 자동으로 생성 

----   

<br/>   

![image](https://github.com/kcheee/kcheee/assets/86779278/0149c1f7-2edd-4fba-b723-a79d8555eba5)

Profile new를 하면 현재 씬에 postprocessing 폴더가 생긴다.


## 사용 방법

Post-process Volume에 Laer 설정

카메라에 Post-Process Layer 컴포넌트를 붙임.

![image](https://github.com/kcheee/kcheee/assets/86779278/4cce5010-a0ae-4a01-9fd0-cfdbc5065c3b)


Post-Process Volume에 맞는 Layer를 설정해준다.


## Post-process Volume

![image](https://github.com/kcheee/kcheee/assets/86779278/0149c1f7-2edd-4fba-b723-a79d8555eba5)

Is Global : 전체 씬에 적용   
Weight : 세기   
Priority : 여러개의 post processing 효과가 있을때 우선 순위.    

- 중첩되어 있는 post processing에 없는 효과가 있을 때 추가가 된다.   

- 중첩되어 있는 post processing에 중복되어 있으면 우선순위가 높은 post processing을 적용

## 사용 효과

### Bloom

Bloom은 너무 밝은 빛에서 뿌옇게 보이는 기능을 한다고 한다.

또한 Bloom의 Dirty기능을 활용하면 1인칭 슈팅게임에 많이 나오는

시야에 흙이나 먼지가 있는 연출이 가능하다.   

### Color Grading    

색감을 조절하는 역할.   

### Ambient Occlusion   

![image](https://github.com/kcheee/kcheee/assets/86779278/e4090797-b612-4157-a01e-77c2fcb6ab74)

구석진 곳에 효과를 주는 효과

 주름 구멍 교차점 및 서로 가까운 표면을 어둡게 한다고 한다.

이 기능은 연산이 비싸기 때문에(카메라가 물체와 가까울수록 매우 비싸짐) 많은 오브젝트에서

쓰는 걸 주의해야 한다고 한다.

### Auto Exposure

Auto Exposure은 어두운 곳에 있다가 밝은 곳으로 갈 때 우리 눈은

바로 밝아지지 않고 천천히 밝아지는데, 그런 과정이라고 한다.

한 번에 밝아지거나 어두워지면 어색해 보일 수 있기에

이런 효과를 주는 것이라고 이해하면 되겠다.   

### Vinette

카메라 렌즈 효과

![image](https://github.com/kcheee/kcheee/assets/86779278/71619865-d123-4f99-b028-2271a5e5b461)


### Depth of Field (피사계 심도)  

카메라 초점을 맞추고 뒤에 배경을 날리는 효과.

![image](https://github.com/kcheee/kcheee/assets/86779278/ecb4c98c-9a45-4bcb-b9a6-e85ac11b243b)
