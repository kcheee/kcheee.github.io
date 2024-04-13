---
layout: post
title: programmers 3단계 베스트앨범
categories : programmers 3단계
tag : [programmers,multiset,map,set]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 3] 베스트앨범 - 42579 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42579#) 

### 성능 요약

메모리: 3.68 MB, 시간: 0.02 ms

### 구분

코딩테스트 연습 > 해시

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 12일 21:03:32

### 문제 설명

<p>스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.</p>

<ol>
<li>속한 노래가 많이 재생된 장르를 먼저 수록합니다.</li>
<li>장르 내에서 많이 재생된 노래를 먼저 수록합니다.</li>
<li>장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.</li>
</ol>

<p>노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.</p>

<h5>제한사항</h5>

<ul>
<li>genres[i]는 고유번호가 i인 노래의 장르입니다.</li>
<li>plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.</li>
<li>genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.</li>
<li>장르 종류는 100개 미만입니다.</li>
<li>장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.</li>
<li>모든 장르는 재생된 횟수가 다릅니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>genres</th>
<th>plays</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>["classic", "pop", "classic", "classic", "pop"]</td>
<td>[500, 600, 150, 800, 2500]</td>
<td>[4, 1, 3, 0]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.</p>

<ul>
<li>고유 번호 3: 800회 재생</li>
<li>고유 번호 0: 500회 재생</li>
<li>고유 번호 2: 150회 재생</li>
</ul>

<p>pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.</p>

<ul>
<li>고유 번호 4: 2,500회 재생</li>
<li>고유 번호 1: 600회 재생</li>
</ul>

<p>따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.</p>

<ul>
<li>장르 별로 가장 많이 재생된 노래를 최대 두 개까지 모아 베스트 앨범을 출시하므로 2번 노래는 수록되지 않습니다.</li>
</ul>

<p>※ 공지 - 2019년 2월 28일 테스트케이스가 추가되었습니다.</p>


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

