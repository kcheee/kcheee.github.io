---
layout: post
title: programmers 1단계 숫자 짝궁
categories : programmers 1단계
tag : [programmers,아스키코드,map]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 1] 숫자 짝꿍 - 131128 
 
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/131128) 

### 성능 요약

메모리: 4.17 MB, 시간: 0.02 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 09일 20:46:52

### 문제 설명

<p data-sider-select-id="e48cfa4c-0c1d-4ced-a6df-4a1966af1c58">두 정수 <code>X</code>, <code>Y</code>의 임의의 자리에서 공통으로 나타나는 정수 k(0 ≤ k ≤ 9)들을 이용하여 만들 수 있는 가장 큰 정수를 두 수의 짝꿍이라 합니다(단, 공통으로 나타나는 정수 중 서로 짝지을 수 있는 숫자만 사용합니다). <code>X</code>, <code>Y</code>의 짝꿍이 존재하지 않으면, 짝꿍은 -1입니다. <code>X</code>, <code>Y</code>의 짝꿍이 0으로만 구성되어 있다면, 짝꿍은 0입니다.</p>

<p>예를 들어, <code>X</code> = 3403이고 <code>Y</code> = 13203이라면, <code>X</code>와 <code>Y</code>의 짝꿍은 <code>X</code>와 <code>Y</code>에서 공통으로 나타나는 3, 0, 3으로 만들 수 있는 가장 큰 정수인 330입니다. 다른 예시로 <code>X</code> = 5525이고 <code>Y</code> = 1255이면 <code>X</code>와 <code>Y</code>의 짝꿍은 <code>X</code>와 <code>Y</code>에서 공통으로 나타나는 2, 5, 5로 만들 수 있는 가장 큰 정수인 552입니다(<code>X</code>에는 5가 3개, <code>Y</code>에는 5가 2개 나타나므로 남는 5 한 개는 짝 지을 수 없습니다.)<br>
두 정수 <code>X</code>, <code>Y</code>가 주어졌을 때, <code>X</code>, <code>Y</code>의 짝꿍을 return하는 solution 함수를 완성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li data-sider-select-id="81caac21-a7ee-43c4-8213-ab26e6b28f8b">3 ≤ <code>X</code>, <code>Y</code>의 길이(자릿수) ≤ 3,000,000입니다.</li>
<li><code>X</code>, <code>Y</code>는 0으로 시작하지 않습니다.</li>
<li><code>X</code>, <code>Y</code>의 짝꿍은 상당히 큰 정수일 수 있으므로, 문자열로 반환합니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>X</th>
<th>Y</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>"100"</td>
<td>"2345"</td>
<td>"-1"</td>
</tr>
<tr>
<td>"100"</td>
<td>"203045"</td>
<td>"0"</td>
</tr>
<tr>
<td>"100"</td>
<td>"123450"</td>
<td>"10"</td>
</tr>
<tr>
<td>"12321"</td>
<td>"42531"</td>
<td>"321"</td>
</tr>
<tr>
<td>"5525"</td>
<td>"1255"</td>
<td>"552"</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<ul>
<li><code>X</code>, <code>Y</code>의 짝꿍은 존재하지 않습니다. 따라서 "-1"을 return합니다.</li>
</ul>

<p><strong>입출력 예 #2</strong></p>

<ul>
<li><code>X</code>, <code>Y</code>의 공통된 숫자는 0으로만 구성되어 있기 때문에, 두 수의 짝꿍은 정수 0입니다. 따라서 "0"을 return합니다.</li>
</ul>

<p><strong>입출력 예 #3</strong></p>

<ul>
<li><code>X</code>, <code>Y</code>의 짝꿍은 10이므로, "10"을 return합니다.</li>
</ul>

<p><strong>입출력 예 #4</strong></p>

<ul>
<li><code>X</code>, <code>Y</code>의 짝꿍은 321입니다. 따라서 "321"을 return합니다.</li>
</ul>

<p><strong>입출력 예 #5</strong></p>

<ul>
<li>지문에 설명된 예시와 같습니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges


## 풀이

소요시간 20분

map을 사용해서 개수를 세어주고, 9부터 0까지 반복하여 만약 둘중 하나라도 개수가 0이 되면 다음 숫자로 넘어가게 로직을 짯다.   
처음에 int to char를 할 때 char(i)를 했었는데 값이 이상하게 나와 시간을 많이 썼다.int형에서 char로 바꿀때는  '0' 또는 아스키코드인 48을 더해서 형 변환해줘야 된다는것을 기억해두자!

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 존재하지 않으면 -1 0으로 구성되어있으면 0

string solution(string X, string Y) {
    string answer = "";
    
    map<char,int> mx;
    map<char,int> my;
    
    for(auto c : X) mx[c]++; 
    for(auto c : Y) my[c]++;
      
    for(int i=9;i>=0;i--)
    {
        char c = i+'0';
        while(mx[c] !=0&&my[c] !=0) 
        {
            answer+=c;
            mx[c]--;
            my[c]--;
        }
    }
    
    if(answer=="") return "-1";
    else if (answer[0]=='0') return "0";
    return answer;
}
```   
