---
layout: post
title: unity ObjectPool
categories : unity study ObjectPool
tag : [unity,ObjectPool,List]
---

# Object Pool

게임의 최적화를 위한 리팩토링.
오브젝트를 생성 후 Destory하는 것이 아니라 미리 오브젝트를 만들어 두고, 활성화 비활성화 시켜 재사용하는 것.

유니티에서 제공하는 오브젝트 풀링이 있다.

## 오브젝트 풀링

```c#
﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 오브젝트풀로 관리할 객체들을 미리 만들어서 목록으로 가지고 있고싶다.
// 해당 객체를 필요로 하는 다른 객체가 있다면 비활성화된 객체를 반환하고싶다.
// 여러개의 공장들을 가지고 관리하고싶다.

// 만약 Enemy2가 죽었어요. Init함수 호출 시 모든것을 초기화 할 수 있어야한다.

// 필요요소
// - 공장 목록
// - 각 공장별 객체 목록
// - 공장별 구분자

public class ObjectPool : MonoBehaviour
{
    public static ObjectPool instance;
    private void Awake()
    {
        instance = this;

        int factoryMaxCount = (int)FactoryName.Max;

        FactoryName[] factoryNames = new FactoryName[factoryMaxCount];
        for (int i = 0; i < factoryMaxCount; i++)
        {
            factoryNames[i] = (FactoryName)i;
        }


        GameObject[] factorys = new GameObject[factoryNames.Length];

        for (int i = 0; i < factorys.Length; i++)
        {
            factorys[i] = Resources.Load<GameObject>(factoryNames[i].ToString());
        }

        pool = new Dictionary<FactoryName, List<GameObject>>();

        for (int j = 0; j < factorys.Length; j++)
        {
            List<GameObject> list = new List<GameObject>();
            pool.Add(factoryNames[j], list);

            for (int i = 0; i < poolCount; i++)
            {
                GameObject obj = Instantiate(factorys[j]);
                obj.SetActive(false);
                list.Add(obj);
            }
        }
    }

    public enum FactoryName
    {
        Enemy2 = 0,
        BImpactEnemy,
        BImpactFloor,


        Max,
    }

    public int poolCount = 10;
    public Dictionary<FactoryName, List<GameObject>> pool;

    void Start()
    {

    }

    public GameObject GetDeactiveObject(FactoryName key)
    {
        for (int i = 0; i < pool[key].Count; i++)
        {
            if (pool[key][i].activeSelf == false)
            {
                pool[key][i].SetActive(true);
                return pool[key][i];
            }
        }

        return null;
    }

}
```



## 유니티 제공 오브젝트 풀링

나중에 사용해보기.

```c#
using UnityEngine.pool;
```