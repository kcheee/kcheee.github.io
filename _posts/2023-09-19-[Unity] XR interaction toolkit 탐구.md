---
layout: post
title: unity XR interaction toolkit 탐구 1
categories : unity VR
tag : [unity,XR interaction toolkit]
---

# XR interaction toolkit 탐구
   
<a herf = " https://docs.unity3d.com/Packages/com.unity.xr.interaction.toolkit@1.0/manual/index.html"> XR interaction 메뉴얼 </a>    

## 기본 구조

3가지 공통 상태가 있음.   

**Hover** : 물체 위를 맴도는 것으로 상호작용하는 것.   

**Select** : 사용자가 버튼이나 트리거 누름과 같은 작업을 필요. ex) Selection은 붙잡을 수 있는 물체를 집거나 레버를 잡거나 호버를 통해 포커스가 있는 도어를 밀 준비를 모의실험할 수 있다.   

**Activate** : 활성화는 일반적으로 현재 선택한 개체에 영향을 미치는 버튼이나 트리거에 매핑되는 추가 작업이다. 이렇게 하면 사용자가 선택한 개체와 더 많은 상호작용을 할 수 있다. Activate 작업은 Interactiveable에 따라 달라진다. 예를 들어 Activate를 사용하여 Interactor가 현재 선택한 총을 발사할 수 있다. Interactable Events 아래의 Inspector 창을 사용하여 기존 콜백을 후크한 다음 UnityEvents를 통해 Activated에 추가하여 구성 요소를 후크하여 추가 코드 없이 Activate를 처리할 수 있다.   


### 기본 방식   


**액션 기반 (Action-based)** :
액션 기반 시스템에서는 입력 이벤트를 처리하기 위해 Input System을 사용합니다. 이 방식은 Unity의 Input System을 기반으로 하며, Input System을 사용하여 다양한 입력을 추상화하고 처리합니다.

- 주요 특징 :
Input System 사용: Unity의 Input System을 활용하여 입력을 추상화하고 처리합니다. 이것은 다양한 입력 장치를 지원하고 관리할 수 있게 해줍니다.   


- 액션 정의: XR Interaction Toolkit은 액션을 정의하여 이벤트를 트리거합니다. 예를 들어, 'Grab'이나 'Select'와 같은 사용자 정의 액션을 만들 수 있습니다.   

- 액션 매핑 및 바인딩: 액션은 특정 키, 버튼 또는 디바이스에 바인딩됩니다. 이것은 입력을 특정 행동 또는 동작으로 매핑하는 과정입니다.   

- 다양한 입력 장치 지원: 액션 기반 시스템은 다양한 입력 장치를 지원합니다. 예를 들어, 컨트롤러, 키보드, 마우스 등이 여기에 포함됩니다.   

- 이벤트 기반 처리: 액션은 이벤트를 발생시키며, 이러한 이벤트를 수신하여 상호 작용을 처리합니다.

**장치 기반 (Device-based)** :
장치 기반 시스템에서는 각각의 XR 디바이스 (예: 컨트롤러)가 직접적으로 관리됩니다. 이 방식은 기본적으로 Unity의 Input System에 기반하지만, 입력 이벤트를 처리하는 과정이 더 간단합니다.

 - 주요 특징 : 
디바이스 중심 접근: 각 XR 디바이스는 별도의 개체로서 관리되며, 각 디바이스의 입력을 직접 처리합니다.

 - 디바이스 관리 : XR 디바이스를 추가, 제거, 설정 및 관리하는 기능을 제공합니다.

- 컨트롤러 정의: XR Interaction Toolkit은 여러 종류의 컨트롤러를 미리 정의하고 있어서, 이러한 컨트롤러를 쉽게 설정하고 사용할 수 있습니다.

- 입력 이벤트 처리: 디바이스의 입력 이벤트를 직접 처리하며, 이러한 이벤트를 사용하여 상호 작용을 구현합니다.

- 액션 사용 선택: 액션 기반과 장치 기반 시스템을 혼합하여 사용할 수 있습니다. 이것은 프로젝트의 요구 사항에 따라 선택할 수 있는 유연성을 제공합니다.

- - -   

## interactor 

**interaction manager** : 간단하게 말해서 interaction을 주관해서 실행해주는 것. 보통 Hand에 달아준다.   

 - interactor : interaction 시도하는 쪽
 - interactable : interaction이 되는 쪽

  %주의% Interactor 과 Interactable 의 Interaction Layer Mask가 겹쳐야 Interaction 발생

![image](https://github.com/kcheee/kcheee/assets/86779278/94a059a0-7dbf-4a19-a8c7-8995165c4918)

### **XR Direct Interactor**   
직접적인 상호작용을 할 수 있게 해줌.   
 대상에 직접 가져다대어 상호작용.
 
###  **Ray Interactor**   
컨트롤러나 Hand에서 Ray를 쏴 오브젝트와 상호작용할 수 있게 해주는 스크립트.   

Teleport나 멀리있는 오브젝트를 select하여 끌어 당길 떄 사용한다.   

![image](https://github.com/kcheee/kcheee/assets/86779278/aa04b9b0-a199-4ca5-9737-5843cebc86cb)   
   
XR Interactor Line Visual을 사용하여 Ray를 보여줄 수 있다.   

### **Poke interactor**   
가볍게 콕 누르는(가볍게 터치하는) 동작에 대해 자연스러운 interaction
ex) Button 누르기.   

### **Gaze interactor**   
바라보는 방향으로 interaction하는 것.   

## interactable    

interactor와 상호작용하게 해주는 interactable 컴포넌트. 이 컴포넌트가 붙어 있는 오브젝트들을 잡을 수 있거나 상호작용을 할 수 있음.

- 기본적으로 rigidbody와 Collider가 있어야 함.  
 
### XR Simple Interactable   

상호 작용 가능한 오브젝트를 쉽게 구현할 수 있게 해주는 컴포넌트.   

### XR Grab Ineractable   

게임 오브젝트를 집을 수 있게 해주는 컴포넌트
   
![image](https://github.com/kcheee/kcheee/assets/86779278/b62e837d-f06b-4833-b31f-b66186ead7f0)

잡히는 오브젝트에 붙혀줘야함.

## Events

### Interactor   
- Hover Entered, Hover Exited
- Select Entered, Select Exited

### Interactable
- First Hover Entered, Last Hover Exited, Hover Entered, Hover Exited
- First Select Entered, Last Select Exited, Select Entered, Select Exited
- Activated, Deactivated   

- - -   

* 실행순서
    - **Interactor** Entered -> **Interactable** First Entered -> **Interactable** Entered    
    -> **Interactor** Exited -> **Interactable** Last Exited -> **Interactable** Exited