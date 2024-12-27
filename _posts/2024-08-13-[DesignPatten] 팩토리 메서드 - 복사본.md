---
layout: post
title: Factory Method Pattern
categories : DesignPattern FactoryMethodPattern
tag : [Design Pattern,FactoryMethodPattern]
---
   

# 팩토리 메서드

팩토리 메소드 패턴은 객체 생성을 위한 인터페이스를 제공하되, 실제 객체 생성은 서브클래스에서 처리하는 패턴입니다. 주로 객체 생성 로직을 캡슐화하여 코드의 유연성과 재사용성을 높이고자 할 때 사용합니다. 

**따라서 생성하는 공장은 딱 하나이고, 어떻게 생성할지에 대한 여러 방식들을 공장의 자식 클래스들로 구현하는 것을 말합니다.**
   
게임으로 예를 들면 전체 몬스터를 스폰해주는 어떠한 클래스가 생산자(Creator)입니다. 모든 몬스터는 이 클래스에서 생산이 됩니다. 그리고 생산돌 몬스터를 결정해주는 클래스가 구상 생산자(ConcreteCreator)입니다.   



- 유지 보수가 편리   
생성 방식들을 추가/수정할땐 서브 팩토리 클래스 내용을 수정하거나 서브 팩토리 클래스 또 다른거 하나 더 추가하거나 그렇게만 하면 된다.
팩토리 클래스를 수정할 필요는 없다.   

<br/>


## 팩토리 계층 구조

![image](https://github.com/user-attachments/assets/0a9d554b-3596-4e12-844c-91d8bedd2eb1)   


1. 최상위 Factory를 abstract class로 만들어주고, 생성함수 만들어줌.   
2. 몬스터별로 Factory따로 만들어줌.
3. 각 몬스터 Factory는 생성함수를 각자 맞춰서 정의.   


<br/>

- - - 

<details>
<summary style="font-size: 20px; font-weight: bold;">Monster 계층</summary>

<div markdown="1">

**Monster**
```c#
public enum MonsterType
{
    Slime,
    Gobline,
    Orc
}

public abstract class Monster
{
    protected MonsterType type;
    protected string name;
    protected int hp;
    protected int exp;

    public abstract void Attack();
    public abstract void Move();
}
```

**Slime**
```c#
class Slime : Monster
{
    public Slime()
    {
        type = MonsterType.Slime;
        name = "Slime";
        hp = 120;
        exp = 15;

        Debug.Log(this.name + " : 생성!!");
    }

    public override void Attack()
    {
        Debug.Log(this.name + " : 공격!!");
    }
    public override void Move()
    {
        Debug.Log(this.name + " : 공격!!");
    }
}


```

</div>
</details>

- - -

### 생성하는 부모 공장

**AbsMonsterFactory** 

```c#
public abstract class AbsMonsterFactory : MonoBehaviour
{
    public abstract Monster CreateMonster();
}
```   
<br/>

#### 추가적인 구현 예시

1. 공통 초기화 또는 설정 메서드
몬스터 생성 과정에서 공통적으로 필요한 초기화나 설정 작업이 있다면, 이를 AbsMonsterFactory에서 정의할 수 있습니다. 예를 들어, 모든 몬스터가 생성될 때 기본적으로 설정해야 하는 로그 기록, 이벤트 트리거링, 또는 기본 속성 값 설정 등을 포함할 수 있습니다.

2. 템플릿 메서드 패턴 적용
CreateMonster() 메서드 외에도, 몬스터 생성 과정의 여러 단계를 구분하여 템플릿 메서드 패턴을 적용할 수 있습니다. 예를 들어, PreCreate(), PostCreate()와 같은 메서드를 정의하여, 각 팩토리에서 이를 오버라이드 할 수 있게 합니다.

3. 공통 유틸리티 메서드
모든 몬스터 생성에 유용한 유틸리티 함수나 헬퍼 메서드를 추가할 수 있습니다. 예를 들어, 몬스터의 특성을 랜덤으로 생성하는 메서드나, 특정 설정을 로드하는 메서드 등을 포함할 수 있습니다.

<br/>

**예시 코드**
```c#
public abstract class AbsMonsterFactory : MonoBehaviour
{
    public abstract Monster CreateMonster();

    // 몬스터 생성 전에 호출되는 메서드
    protected virtual void PreCreate()
    {
        Debug.Log("Preparing to create a monster");
    }

    // 몬스터 생성 후에 호출되는 메서드
    protected virtual void PostCreate(Monster monster)
    {
        Debug.Log($"{monster.Name} has been created with {monster.HP} HP and {monster.EXP} EXP");
        TriggerCreationEvent(monster);
    }

    // 몬스터 생성 이벤트 트리거
    protected void TriggerCreationEvent(Monster monster)
    {
        // 이벤트 로직을 구현
        // 예: EventManager.TriggerEvent("MonsterCreated", new EventData(monster));
    }
}

```

- - -

<br/>

### 자식 공장


**SlimeFactory**

```c#
public class SlimeFactory : AbsMonsterFactory
{
    public override Monster CreateMonster()
    {
        return new Slime();
    }
}
```

<br/>

#### 추가적인 구현 예시

몬스터 타입별 초기화: 각 몬스터 타입별로 고유한 초기화 과정이 필요할 수 있습니다. 예를 들어, 특정 몬스터는 생성 시 추가 스킬이나 능력치를 설정할 수 있습니다.

이벤트 트리거링: 몬스터 생성 시 특정 이벤트를 게임 엔진에 트리거 할 수 있습니다. 예를 들어, 특정 몬스터가 생성될 때 게임 내에서 알림이나 효과를 발생시킬 수 있습니다.

로그 기록: 생성 로그를 남겨 게임 디버깅과 관리에 유용한 정보를 제공할 수 있습니다.

**예시 코드**

```c#

public class SlimeFactory : AbsMonsterFactory
{
    public override Monster CreateMonster()
    {
        // 몬스터 생성 로그 출력
        Debug.Log("Creating a new Slime Monster");

        // Slime 객체 생성
        Slime newSlime = new Slime();

        // 몬스터의 초기 설정 (예: 스킬 설정, 아이템 설정 등)
        InitializeMonster(newSlime);

        // 생성된 몬스터 반환
        return newSlime;
    }

    private void InitializeMonster(Slime slime)
    {
        // 몬스터에 초기 스킬 추가
        slime.AddSkill("Acid Splash");

        // 초기 아이템 설정, 예를 들어 힐링 포션 할당
        slime.AddItem("Healing Potion", 1);

        // 초기 상태값 설정, 예를 들어 경험치 부여
        slime.SetExperience(100);

        // 추가 설정이 필요한 경우 여기에 코드 추가
    }
}

```