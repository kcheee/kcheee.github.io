---
layout: post
title: unity Bezier_Curve
categories : unity study Bezier_Curve
tag : [unity,Lerp,Bezier_Curve]
---

나중에 정리

# Bezier_Curve

![image](https://search.pstatic.net/sunny/?src=https%3A%2F%2Fi.stack.imgur.com%2F0FFgo.png&type=sc960_832)


![image](https://github.com/kcheee/kcheee/assets/86779278/d4e71d4a-2aab-41dd-b798-d3bbe756bb1d)

<br/>   

```c#
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using UnityEngine;

public class BezierCurve : MonoBehaviour
{
    LineRenderer lr;
    public Transform a, b, c;
    public int pointCount = 100;

    private void Start()
    {
        lr = GetComponent<LineRenderer>();
        lr.positionCount = 3;
        lr.SetPosition(0, a.position);
        lr.SetPosition(1, b.position);
        lr.SetPosition(2, c.position);
    }
    private void Update()
    {
        lr.positionCount = pointCount;
        for (int i = 0; i < pointCount; i++)
        {
            float t = (float)i / (pointCount - 1);  
            lr.SetPosition(i,GetCurvePoint(a.position,b.position,c.position,t));
        }
    }

// bezier curve 함수.
    Vector3 GetCurvePoint(Vector3 a, Vector3 b,Vector3 c,float t)
    {
        Vector3 ab = Vector3.Lerp(a,b,t);
        Vector3 bc = Vector3.Lerp(b,c,t);

        return Vector3.Lerp(ab,bc,t);          
    }
}

```