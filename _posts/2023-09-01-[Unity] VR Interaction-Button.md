---
layout: post
title: unity VR Interaction - Button만들기
categories : unity VR 
tag : [unity,VR,oculus,Button]
---

# Button 만들기

1. Cylinder 오브젝트로 버튼 모양을 만들어준다.     

2. Button 오브젝트를 복사해 BoxCollider와 Rigidbody를 넣어주고 ButtonTest Script를 달아준다.   

3. collider에 trigger를 체크해주고 Rigidbody에 use gravity를 해제하고 Is Kinematic를 체크해준다.   

4. ButtonTest에 있는 OnRelease() ButtonTest.Test() 함수를 넣어준다.   

![image](https://github.com/kcheee/kcheee/assets/86779278/ff08b202-4996-4f72-bb4c-08ae12cd76d3)


## ButtonTest Script

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;


public class ButtonTest : MonoBehaviour
{
    public GameObject button;
    public UnityEvent onPress;
    public UnityEvent onRelease;
    GameObject presser;
    bool ispressed;

    private void Start()
    {
        ispressed = false;
    }
    private void OnTriggerEnter(Collider other)
    {
        if (!ispressed)
        {
            button.transform.localPosition = new Vector3 (0, 0.003f, 0);
            presser =  other.gameObject;
            onPress.Invoke();
            ispressed = true;
        }
    }
    private void OnTriggerExit(Collider other)
    {
        if(other.gameObject==presser)
        {
            button.transform.localPosition = new Vector3(0,0.015f,0);
            onRelease.Invoke();
            ispressed = false;
        }
    }

    public void Test()
    {
        GameObject sphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        sphere.transform.localScale = Vector3.one*0.5f;
        sphere.transform.localPosition = new Vector3(0, 1, 2);
        sphere.AddComponent<Rigidbody>();

    }
}

```