---
layout: post
title: c++ Programmers 올바른괄호
categories : Programmers 2단계
tag : [Programmers,2단계]
---

# [level 2] 올바른 괄호 - 12909 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12909) 

### 성능 요약

메모리: 3.81 MB, 시간: 0.36 ms

### 구분

코딩테스트 연습 > 스택／큐

### 채점결과

Empty

### 문제 설명

<p>괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 예를 들어</p>

<ul>
<li>"()()" 또는 "(())()" 는 올바른 괄호입니다.</li>
<li>")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.</li>
</ul>

<p>'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.</p>

<h5>제한사항</h5>

<ul>
<li>문자열 s의 길이 : 100,000 이하의 자연수</li>
<li>문자열 s는 '(' 또는 ')' 로만 이루어져 있습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>

<span style="color:white">
<table class="table">
        <thead><tr>
<th> s</th>
<th>answer</th>
</tr>
</thead>
        <tbody><tr>
<td>"()()"</td>
<td>true</td>
</tr>
<tr>
<td>"(())()"</td>
<td>true</td>
</tr>
<tr>
<td>")()("</td>
<td>false</td>
</tr>
<tr>
<td>"(()("</td>
<td>false</td>
</tr>
</tbody>
      </table>
      </span>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1,2,3,4<br>
문제의 예시와 같습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

// 틀렸던 문제   

카운트를 세서 같으면 정답이라고 단순하게 생각을 했지만 반례가 있었다..   

// 반례 "())(()"   

```c++
bool solution(string s)
{
	bool result;
	vector<char> str;
	for (int i = 0; i < s.length(); i++)	
		str.push_back(s[i]);
		
	if (str.front() == ')' || str.back() == '(') return 0;
	
	return count(str.begin(), str.end(), ')') == count(str.begin(), str.end(), '(');
}

```

// 정답

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    int data = 0;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            data++;
        else if (s[i] == ')')
            data--;

        if (data < 0)
            return false;

    }
    return data == 0;
}

```