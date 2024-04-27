---
layout: post
title: programmers 2단계 다리를 지나는 트럭
categories : programmers 2단계
tag : [programmers,multiset,map,set]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 다리를 지나는 트럭 - 42583 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42583) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.03 ms

### 구분

코딩테스트 연습 > 스택／큐

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 13일 15:30:26

### 문제 설명

<p>트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다. 단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.</p>

<p>예를 들어, 트럭 2대가 올라갈 수 있고 무게를 10kg까지 견디는 다리가 있습니다. 무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.</p>
<table class="table">
        <thead><tr>
<th data-sider-select-id="4e697027-bf2b-4602-84d5-3b48188f35f0">경과 시간</th>
<th>다리를 지난 트럭</th>
<th>다리를 건너는 트럭</th>
<th>대기 트럭</th>
</tr>
</thead>
        <tbody><tr>
<td>0</td>
<td>[]</td>
<td>[]</td>
<td>[7,4,5,6]</td>
</tr>
<tr>
<td>1~2</td>
<td>[]</td>
<td>[7]</td>
<td>[4,5,6]</td>
</tr>
<tr>
<td>3</td>
<td>[7]</td>
<td>[4]</td>
<td>[5,6]</td>
</tr>
<tr>
<td>4</td>
<td>[7]</td>
<td>[4,5]</td>
<td>[6]</td>
</tr>
<tr>
<td>5</td>
<td>[7,4]</td>
<td>[5]</td>
<td>[6]</td>
</tr>
<tr>
<td>6~7</td>
<td>[7,4,5]</td>
<td>[6]</td>
<td>[]</td>
</tr>
<tr>
<td>8</td>
<td>[7,4,5,6]</td>
<td>[]</td>
<td>[]</td>
</tr>
</tbody>
      </table>
<p>따라서, 모든 트럭이 다리를 지나려면 최소 8초가 걸립니다.</p>

<p>solution 함수의 매개변수로 다리에 올라갈 수 있는 트럭 수 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭 별 무게 truck_weights가 주어집니다. 이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.</p>

<h5>제한 조건</h5>

<ul>
<li>bridge_length는 1 이상 10,000 이하입니다.</li>
<li>weight는 1 이상 10,000 이하입니다.</li>
<li>truck_weights의 길이는 1 이상 10,000 이하입니다.</li>
<li>모든 트럭의 무게는 1 이상 weight 이하입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th data-sider-select-id="90fb4dd6-9f61-46fa-b0a5-eab1ec4bfeb8">bridge_length</th>
<th>weight</th>
<th>truck_weights</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td data-sider-select-id="08de9e56-16b1-407a-bf00-b384b0eec580">2</td>
<td>10</td>
<td>[7,4,5,6]</td>
<td>8</td>
</tr>
<tr>
<td>100</td>
<td>100</td>
<td>[10]</td>
<td>101</td>
</tr>
<tr>
<td>100</td>
<td>100</td>
<td>[10,10,10,10,10,10,10,10,10,10]</td>
<td>110</td>
</tr>
</tbody>
      </table>
<p><a href="http://icpckorea.org/2016/ONLINE/problem.pdf" target="_blank" rel="noopener">출처</a></p>

<p>※ 공지 - 2020년 4월 06일 테스트케이스가 추가되었습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

1. 정렬을 하고 weight을 통해 또 한번 정렬
2. pair( 무게, 단위시간 ) 를 사용한 que vector를 사용해서 풀었다.

하지만 생각을 해보니 트럭이 [7,4,5,6] 이렇게 있을 때 
문제설명에 나온것처럼 [7,4,5,6] 이 아니라 [7,6,4,5] 일 때 최단시간 7초가 걸려야한다. 아니나 다를까 질문하기 페이지에서 나와 같은 실수를 한 사람이 있었다.. 마냥 최단시간이라 써져있는것을 보고 배열 순서를 바꿔야지 생각을 했던것이다ㅠ. 문제 설명이 너무 불친절하다;; 하;

### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Weight = 0;
bool compare(int a,int b)
{
    return (a+b)>=Weight;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int t=1;
    queue<pair<int,int>> q;
    Weight=weight;
    int cur_weight=0;
    
    sort(truck_weights.begin(),truck_weights.end(),greater<int>());   
    sort(truck_weights.begin(),truck_weights.end(),compare);
    

 // 트럭이 모두 다리를 건널 때까지 반복
    while (!truck_weights.empty() || !q.empty()) {
        answer++;

        // 다리 위의 트럭을 빼고 무게 갱신
        if (!q.empty() && answer - q.front().second == bridge_length) {            
            cur_weight -= q.front().first;
            q.pop();
            
        }
        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (!truck_weights.empty() && cur_weight + truck_weights.back() <= weight) {
            q.push({truck_weights.back(),answer});
            
            cout<<answer;
            cur_weight += truck_weights.back();
            truck_weights.pop_back();
        }
       
    }

    
    return answer;
}
```   

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Weight = 0;
bool compare(int a,int b)
{
    return (a+b)>=Weight;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int t=1;
    queue<pair<int,int>> q;
    Weight=weight;
    int cur_weight=0;
    

 // 트럭이 모두 다리를 건널 때까지 반복
    while (!truck_weights.empty() || !q.empty()) {
        answer++;

        // 다리 위의 트럭을 빼고 무게 갱신
        if (!q.empty() && answer - q.front().second == bridge_length) {            
            cur_weight -= q.front().first;
            q.pop();
            
        }
        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (!truck_weights.empty() && cur_weight + truck_weights.back() <= weight) {
            q.push({truck_weights.back(),answer});
            
            cout<<answer;
            cur_weight += truck_weights.back();
            truck_weights.pop_back();
        }
       
    }

    
    return answer;
}
```

