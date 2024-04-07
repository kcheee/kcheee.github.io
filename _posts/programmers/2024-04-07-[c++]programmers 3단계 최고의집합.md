---
layout: post
title: programmers 3단계 최고의 집합
categories : programmers 3단계
tag : [programmers]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 3] 최고의 집합 - 12938 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12938) 

### 성능 요약

메모리: 3.92 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 70.0<br/>효율성: 30.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 07일 19:14:03

### 문제 설명

<p data-sider-select-id="9fb257fd-26c6-4f32-8290-9f3467470d95">자연수 n 개로 이루어진 중복 집합(multi set, 편의상 이후에는 "집합"으로 통칭) 중에 다음 두 조건을 만족하는 집합을 최고의 집합이라고 합니다.</p>

<ol>
<li data-sider-select-id="63593ceb-1495-4121-afba-c132c4cc9a87">각 원소의 합이 S가 되는 수의 집합</li>
<li data-sider-select-id="40e1e386-b5d2-4000-8f93-bae30ad3523f">위 조건을 만족하면서 각 원소의 곱 이 최대가 되는 집합</li>
</ol>

<p data-sider-select-id="70797c28-ed06-42c9-b3db-1f099b05a5c8">예를 들어서 자연수 2개로 이루어진 집합 중 합이 9가 되는 집합은 다음과 같이 4개가 있습니다.<br>
{ 1, 8 }, { 2, 7 }, { 3, 6 }, { 4, 5 }<br>
그중 각 원소의 곱이 최대인 { 4, 5 }가 최고의 집합입니다.</p>

<p data-sider-select-id="32f8d89a-75cf-4dc0-8bb6-089a643a4056">집합의 원소의 개수 n과 모든 원소들의 합 s가 매개변수로 주어질 때, 최고의 집합을 return 하는 solution 함수를 완성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li data-sider-select-id="ca446106-5b8f-444d-bce6-002d77c5a671">최고의 집합은 <strong>오름차순으로 정렬된 1차원 배열(list, vector)</strong> 로 return 해주세요.</li>
<li>만약 최고의 집합이 존재하지 않는 경우에 <strong>크기가 1인 1차원 배열(list, vector)</strong> 에 <code>-1</code> 을 채워서 return 해주세요.</li>
<li>자연수의 개수 n은 1 이상 10,000 이하의 자연수입니다.</li>
<li data-sider-select-id="e23d77be-69b6-4ba8-8882-0f1b7c8c45ab">모든 원소들의 합 s는 1 이상, 100,000,000 이하의 자연수입니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>s</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td data-sider-select-id="1a265903-f96e-4686-b71c-111a32beb6c7">2</td>
<td>9</td>
<td>[4, 5]</td>
</tr>
<tr>
<td>2</td>
<td>1</td>
<td>[-1]</td>
</tr>
<tr>
<td>2</td>
<td>8</td>
<td>[4, 4]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예#1<br>
문제의 예시와 같습니다.</p>

<p>입출력 예#2<br>
자연수 2개를 가지고는 합이 1인 집합을 만들 수 없습니다. 따라서 -1이 들어있는 배열을 반환합니다.</p>

<p>입출력 예#3<br>
자연수 2개로 이루어진 집합 중 원소의 합이 8인 집합은 다음과 같습니다.</p>

<p>{ 1, 7 }, { 2, 6 }, { 3, 5 }, { 4, 4 }</p>

<p>그중 각 원소의 곱이 최대인 { 4, 4 }가 최고의 집합입니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges


## 풀이

소요시간 25분

while문을 돌려 s를 n, n-1, n-2 ... 1 만큼 나눴다.
이 때 s도 n만큼 나눈 값을 빼주며, 이때 몫이 있다면 1을 더해주는 방식으로 풀었다

### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 자연수 n개로 이루어진 집합 중 합이 s가 되는 집합에서 곱이 가장 큰 것
// 집합 사이의 값들이 가장 작은 것을 찾으면 됌
// 만약 n이 s보다 크다면 -1 리턴

// ex 8일때 3인경우 
// n,n-1 ...  n-a 만큼 나눠줌
// 이때 몫이 있을경우 1만큼 더해서 나눠줌
// 나눈 n값만큼 s에서 빼줌
// 8/3 = 3
// 5/2 = 3
// 2
vector<int> solution(int n, int s) {
    if(s<n) return vector<int> {-1};   
    vector<int> answer;
    
    while(n!=0)
    {
        if(n==1) { answer.push_back(s); break;}
        // 몫이 있을경우
        if(s%n!=0)
        {
            answer.push_back(s/n + 1);
            s -= s/n + 1;
        }
        else
        {            
            answer.push_back(s/n);
            s-=s/n;
        }
        n--;
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}
```   
