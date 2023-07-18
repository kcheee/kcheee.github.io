---
layout: post
title: unity IK(Inverse Kinematics)
categories : unity study IK
tag : [unity,IK]
---

# Inverse Kinematics

Kinematics : 운동학

Computer Graphics 분야에서는 주로 관절이 존재하는 물체의 Animation을 다룰 때, Kinematics가 적용되는 경우가 많다.

이 때, 이 관절이 존재하는 물체를 Articulated Body라고 하고, 이는 Joints&Links로 이루어져 있으며, 이를 통해, 물체의 Animation을 표현할 수 있다.

## Forward Kinematics(FK)?
앞서 말한 Articulated Body를 통해 걸어가는 동작이 있다고 가정하면, FK는 각 관절의 Rotation을 조절하여 원하는 포즈를 만들어낸다. 

![관절](https://github.com/kcheee/kcheee/assets/86779278/34174074-bda3-4127-8339-24db6be90325)


좀 더, 의미 있게 표현하자면 각 관절의 각도(포즈)를 입력으로 주어 End Effector의 좌표를 얻어낸다. End Effector는 <Fig 1>의 머리와 각 팔다리의 끝(빨간선 끝)이라고 생각하면 된다. 

 
Input :	각 관절의 각도, 포즈
Ouput : End Effector의 좌표
 

FK를 이용해 물체의 Animation을 표현하려면, 모든 관절의 각도를 정의해야한다.

이는 굉장히 직관적이지 못하다. 보통 Articulated Body는 10개 이상의 복잡한 구조로 되어있기 때문에


## Inverse Kinematics(IK)?

 IK는 FK의 반대라고 생각하면 개념에 대한 이해가 쉽다.    
 **즉, 위치가 주어지면 End Effector가 가능한 정확하게 그 위치로 이동할 수 있도록 각 관절들의 각도(포즈)를 구하는 문제이다.**

Input : Target 좌표
Ouput : 각 관절의 각도, 포즈   

   


### 사용방법

![image](https://github.com/kcheee/kcheee/assets/86779278/4969b739-5df8-4f1e-9bd3-dacf29d89501)


```c#
// IK 쓰는 함수
 private void OnAnimatorIK(int layerIndex)
    {
        MySetIK(AvatarIKGoal.LeftHand, LHand);
        MySetIK(AvatarIKGoal.RightHand, RHand);

        // 목을 돌림.
        animator.SetLookAtWeight(1);
        animator.SetLookAtPosition(LookTarget.position);
    }

    void MySetIK(AvatarIKGoal goal,Transform target)
    {
        animator.SetIKPositionWeight(goal, 1);
        animator.SetIKRotationWeight(goal, 1);

        animator.SetIKPosition(goal, target.position);
        animator.SetIKRotation(goal, target.rotation);
    }
```

---   
---
