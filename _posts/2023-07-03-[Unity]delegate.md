---
layout: post
title: Unity delegate
categories : unity delegate
tag : [delegate,unity,C#]
---

# delegate
다음과 같은 하나의 함수가 있다고 가정하자.
(주: 여기서의 함수는 개념적으로 메서드와 동일한 의미로 가정)   

```c#
void RunA(int i) { ... }
```   

이 함수는 정수 하나를 파라미터로 받아들인다. 이 함수를 호출하기 위해서는 아래와 같이 정수를 메서드 파라미터로 넘기면 된다.   

```c#  
int j = 123;
RunA(j);
```   

좀 더 복잡한 경우로서 다음과 같이 클래스 객체를 넘기는 경우를 생각해 볼 수 있다.   

```c#
void RunB(MyClass c) { ... }
```   


이 경우 MyClass는 위의 int와 같은 Built-in 타입이 아니므로 개발자가 그 타입을 어딘가에서 정의해 주어여야 한다 (예를 들어 아래와 같이).   

```c#
class MyClass
{
    int id;   //필드
    string name;       
    public void Display() { }  //메서드
}
```   


이 함수(RunB)를 호출하기 위해서는 아래와 같이 클래스 인스턴스를 만들어 이를 메서드 파라미터로 넘기면 된다.

```c#
MyClass c = new MyClass();
RunB(c);
```   

그런데 위의 2가지 케이스를 자세히 보면, 파라미터로서 정수 혹은 객체 즉 어떤 "데이타"를 메서드에 보내고 있는 것을 알 수 있다.

그러면, 이러한 통상적인 개념의 물리적 "데이타" 말고, 어떤 "메서드" 자체를 함수(메서드)의 파라미터로 전달할 수 있을까?


Delegate는 이렇게 메서드를 다른 메서드로 전달할 수 있도록 하기 위해 만들어 졌다. 아래 그림에서 보이듯이, 숫자 혹은 객체를 메서드의 파라미터로써 전달할 수 있듯이, 메서드 또한 파라미터로서 전달할 수 있다. (주: 복수 개의 메서드들도 전달 가능) Delegate는 메서드의 입력 파라미터로 피호출자에게 전달될 수 있을 뿐만 아니라, 또한 메서드의 리턴값으로 호출자에게 전달 수도 있다.   


Delegate 개념 이해하기

예를 들어, 다음과 같은 함수를 가정해 보자. 여기서 MyDelegate가 델리게이트 타입이라고 가정하면, 이 함수는 다른 어떤 메서드를 Run() 메서드에 전달하고 있는 것이다.   

```c#   
void Run(MyDelegate method) { ... }
```   

그러면 델리게이트 타입 MyDelegate은 어떻게 정의하는가? 위의 클래스 예제(MyClass)의 경우 C# 키워드 class 를 사용하여 해당 클래스를 정의하였는데, 델리게이트 타입을 정의하기 위해선 특별한 C# 키워드 delegate 를 사용한다.   

```c#   
delegate int MyDelegate(string s);
```    

델리게이트 정의에서 중요한 것은 입력 파리미터들과 리턴 타입이다. 만약 어떤 메서드가 이러한 델리게이트 메서드 원형(Prototype)과 일치한다면, 즉 입력 파리미터 타입 및 갯수, 리턴 타입이 동일하다면 그 메서드는 해당 델리게이트에서 사용될 수 있다.

델리게이트 정의는 마치 하나의 함수(메서드)를 정의하는 Prototype 선언식처럼 보이는데, 사실 내부적으로 이 선언식은 컴파일러에 의해 특별한 클래스로 변환된다.


델리게이트가 이렇게 정의된 후에는 클래스 객체를 생성한 것과 비슷한 방식으로 new를 써서 델리게이트 객체를 생성한다.
(주: delegate는 결국 클래스이므로 클래스 객체 생성과 같은 방식을 사용한다)

델리게이트를 다른 메서드에 전달하는 방식은 델리게이트 객체를 메서드 호출 파라미터에 넣으면 된다. 이는 메서드를, 좀 더 정확히는 그 메서드 정보를 갖는 Wrapper 클래스의 객체를, 다른 메서드의 입력 파라미터로 전달하는 것이 된다.   

```c#
// int StringToInt(string s) { ... }

MyDelegate m = new MyDelegate(StringToInt);
Run(m);
```
전달된 델리게이트로부터 실제 메서드를 호출하는 것은 어떻게 하는가? 이는 델리게이트 객체의 .Invoke() 메서드나 .BeginInvoke() 메서드를 써서 호출한다. 예를 들어, m 이라는 델리게이트 객체를 전달 받았을 경우, 아래와 같이 Invoke() 메서드를 호출한다. 만약 메서드에 입력파라미터가 있을 경우, 이를 Invoke() 안에 추가한다.   


```c#
i = m.Invoke("123");
```   

또 다른 메서드 호출방법으로 C# 프로그래머들이 더 애용하는 방식은, .Invoke 메서드명을 생략하고 다음과 같이 직접 함수처럼 사용하는 방법이다. 이 방식은 마치 메서드를 직접 호출하는 느낌을 주므로 더 직관적이다.
```c#   
i = m("123");
   ```   

예제
```c#   
class Program
{
    static void Main(string[] args)
    {
        new Program().Test();
    }

    // 델리게이트 정의
    delegate int MyDelegate(string s);

    void Test()
    {
        //델리게이트 객체 생성
        MyDelegate m = new MyDelegate(StringToInt);

        //델리게이트 객체를 메서드로 전달
        Run(m);
    }

    // 델리게이트 대상이 되는 어떤 메서드
    int StringToInt(string s)
    {
        return int.Parse(s);
    }

    // 델리게이트를 전달 받는 메서드
    void Run(MyDelegate m)
    {
        // 델리게이트로부터 메서드 실행
        int i = m("123");

        Console.WriteLine(i);
    }
}
```
UI를 사용한 예시
```c#
class program
{
    delegate ing myDelegate();

    static void ButtonPressed(myDelegate clickedFunction)   clickedFunction;

    static int TestDelegate()
    {
        Debug.log("Hello world");
        return 0;
    }

    static void Main(String[] args)
    buttonPressed(TestDelegate);
}
```

##  .Invoke()
ButtonPressed 함수 내부에서, 전달받은 함수 TestDelegate를 호출할 때 clickedFunction() 형태로 호출했습니다.

그런데, .Invoke() 함수를 이용해서, 다음과 같은 형태로 함수를 호출하는 것 또한 가능합니다.

```c#
using System;

namespace Delegate_Example
{
    class Program
    {
        delegate int MyDelegate();

        static void ButtonPressed(MyDelegate clickedFunction)
        {
            clickedFunction.Invoke();
        }

        static int TestDelegate()
        {
            Console.WriteLine("Hello World");
            return 0;
        }

        static void Main(string[] args)
        {
            ButtonPressed(TestDelegate);
        }
    }
}
[출력결과] Hello World
```

입력할 파라미터가 존재하는 경우 Invoke() 메서드의 괄호 안에 입력값을 넣어 줍니다. 

## 델리게이트 체인(Delegate Chain)   

Delegate.Combine() 메소드를 이용하면, 여러개의 메서드를 묶는 것이 가능합니다. 아래는 Delegate.Combine()을 이용해 plus, minus, divide 함수를 묶어서 출력한 예시입니다.
   
```c#   
using System;

namespace Delegate_Example
{
    class Program
    {
        delegate void MyDelegate(int a, int b);

        static void plus(int a, int b)
        {
            Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
        }

        static void minus(int a, int b)
        {
            Console.WriteLine("{0} - {1} = {2}", a, b, a - b);
        }

        static void divide(int a, int b)
        {
            Console.WriteLine("{0} / {1} = {2}", a, b, a / b);
        }

        static void Main(string[] args)
        {
            MyDelegate d = (MyDelegate)Delegate.Combine(new MyDelegate(plus), new MyDelegate(minus), new MyDelegate(divide));
            d(10, 2);
        }
    }
}
```