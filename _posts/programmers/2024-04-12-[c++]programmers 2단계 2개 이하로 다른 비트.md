---
layout: post
title: programmers 2단계 2개 이하로 다른 비트
categories : programmers 2단계
tag : [programmers,비트연산자]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 2개 이하로 다른 비트 - 77885 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/77885#) 

### 성능 요약

메모리: 27.9 MB, 시간: 39.91 ms

### 구분

코딩테스트 연습 > 월간 코드 챌린지 시즌2

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 12일 18:02:58

### 문제 설명

<p>양의 정수 <code>x</code>에 대한 함수 <code>f(x)</code>를 다음과 같이 정의합니다.</p>

<ul>
<li><code>x</code>보다 크고 <code>x</code>와 <strong>비트가 1~2개 다른</strong> 수들 중에서 제일 작은 수</li>
</ul>

<p>예를 들어, </p>

<ul>
<li><code>f(2) = 3</code> 입니다. 다음 표와 같이 2보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 3이기 때문입니다.</li>
</ul>
<table class="table">
        <thead><tr>
<th>수</th>
<th>비트</th>
<th>다른 비트의 개수</th>
</tr>
</thead>
        <tbody><tr>
<td>2</td>
<td><code>000...0010</code></td>
<td></td>
</tr>
<tr>
<td>3</td>
<td><code>000...0011</code></td>
<td>1</td>
</tr>
</tbody>
      </table>
<ul>
<li><code>f(7) = 11</code> 입니다. 다음 표와 같이 7보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 11이기 때문입니다.</li>
</ul>
<table class="table">
        <thead><tr>
<th>수</th>
<th>비트</th>
<th>다른 비트의 개수</th>
</tr>
</thead>
        <tbody><tr>
<td>7</td>
<td><code>000...0111</code></td>
<td></td>
</tr>
<tr>
<td>8</td>
<td><code>000...1000</code></td>
<td>4</td>
</tr>
<tr>
<td>9</td>
<td><code>000...1001</code></td>
<td>3</td>
</tr>
<tr>
<td>10</td>
<td><code>000...1010</code></td>
<td>3</td>
</tr>
<tr>
<td>11</td>
<td><code>000...1011</code></td>
<td>2</td>
</tr>
</tbody>
      </table>
<p>정수들이 담긴 배열 <code>numbers</code>가 매개변수로 주어집니다. <code>numbers</code>의 모든 수들에 대하여 각 수의 <code>f</code> 값을 배열에 차례대로 담아 return 하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>numbers</code>의 길이 ≤ 100,000</li>
<li>0 ≤ <code>numbers</code>의 모든 수 ≤ 10<sup>15</sup></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>numbers</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td><code>[2,7]</code></td>
<td><code>[3,11]</code></td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<ul>
<li>문제 예시와 같습니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 1시간

1. long long은 64비트 이므로 반복해줌.
2. 첫번째 비트가 0이라면 단순 1만 더해서 푸시
3. 아니라면 AND 연산을 사용해서 mask에 오른쪽으로 시프트하여 0이 될때까지 반복, 만약 0이 나왔다면 그 뒷자리 비트도 1로 설정하여 XOR 연산 적용.

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// 뒤에서 계산해서 0이 나온다면 그 값을 1로 바꾸고 뒤에 있는 값은 0으로 바꿔줌.
// 뒤에값이 없거나 0이라면 냅두고 1이라면 0으로 바꿔줌.

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long mask = 1;
        
    for(auto n : numbers)
    {
        mask=1;
        for(int i=0;i<64;i++)
        {
            if(i==0 && (n&mask)==0)
            {
                //numbers값에 1만 더해준다.
                answer.push_back(n+1);
                break;
            }
            if((n&mask)!=0)
                mask <<=1;
            
            else
            {          
                long long result = mask + pow(2,i-1);
                answer.push_back(n ^ result);
                break;
            }          
        }    
    }
    
    
    // 1부터 바꾸면 되지
    // mask는 계속 왼쪽으로 shift해줌 
    // and & 연산자 사용 만약 값이 0이 나왔다면 그 뒤에 있는 값과 1을 ^ 연산 해줌.

    
    return answer;
}
```   

