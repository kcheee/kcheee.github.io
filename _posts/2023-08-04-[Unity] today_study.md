---
layout: post
title: unity 상속
categories : unity study 상속
tag : [unity,Struct,Class,Serializeable]
---

# Serializable 사용해 inspector 정리

```c#
public struct stTest
{
    public string monsterName;
    // 필요한 컴포넌트
    [SerializeField] Animator anim;
    [SerializeField] Rigidbody rigid;
    [SerializeField] BoxCollider boxCol;
  

    [SerializeField] AudioClip[] sound_Normal;
    [SerializeField] AudioClip sound_Hurt;
    [SerializeField] AudioClip sound_Dead;
}
public class Test2 : MonoBehaviour
{
    [SerializeField]
    protected stTest 몬스터기본스텟;
}
```

![image](https://github.com/kcheee/kcheee/assets/86779278/c9e4ccaa-9203-4a56-bd2b-1ce753cf2c2f)













