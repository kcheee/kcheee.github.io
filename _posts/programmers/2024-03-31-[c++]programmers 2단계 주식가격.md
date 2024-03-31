---
layout: post
title: programmers 2단계 주식가격
categories : programmers 2단계
tag : [programmers,priority_queue,pair]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 주식가격 - 42584 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42584) 

### 성능 요약

메모리: 16.2 MB, 시간: 14.94 ms

### 구분

코딩테스트 연습 > 스택／큐

### 채점결과

정확성: 66.7<br/>효율성: 33.3<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 31일 19:39:46

### 문제 설명

<p>초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.</p>

<h5>제한사항</h5>

<ul>
<li>prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.</li>
<li>prices의 길이는 2 이상 100,000 이하입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>prices</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[1, 2, 3, 2, 3]</td>
<td>[4, 3, 1, 1, 0]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<ul>
<li>1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.</li>
<li>2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.</li>
<li>3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.</li>
<li>4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.</li>
<li>5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.</li>
</ul>

<p>※ 공지 - 2019년 2월 28일 지문이 리뉴얼되었습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 1시간   

priority_queue와 pair를 사용하여 풀었다.   
queue에 prices와 인덱스를 저장후 prices의 크기만큼 반복문을 통하여 queue.top()보다 값이 작다면 queue.top().second 저장한 인덱스에 현재 반복문을 돈 i만큼 빼서 answer[queue.top().second]에 값을 저장한다. 그 후, queue 값이 남아있다면 i만큼 빼는것이 아닌 prices.size()-1만큼 빼준다.


### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    priority_queue<pair<int,int>> a;

    for (int i = 0; i < prices.size(); ++i) {
        while (!a.empty() && a.top().first > prices[i]) {
            answer[a.top().second] = i - a.top().second;
            a.pop();
        }
        a.push({prices[i], i});
    }

    while (!a.empty()) {
        answer[a.top().second] = prices.size() - 1 - a.top().second;
        a.pop(); 
    }

    return answer;
}
```   
