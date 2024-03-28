---
layout: post
title: programmers 2단계 뒤에 있는 큰 수 찾기
categories : programmers 2단계
tag : [programmers,multiset,next]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 더 맵게 - 42626 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42626) 

### 성능 요약

메모리: 81.6 MB, 시간: 760.71 ms

### 구분

코딩테스트 연습 > 힙（Heap）

### 채점결과

정확성: 83.9<br/>효율성: 16.1<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 28일 20:04:43

### 문제 설명

<p>매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.</p>
<div class="highlight"><pre class="codehilite"><code>섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
</code></pre></div>
<p>Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.<br>
Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한 사항</h5>

<ul>
<li>scoville의 길이는 2 이상 1,000,000 이하입니다.</li>
<li>K는 0 이상 1,000,000,000 이하입니다.</li>
<li>scoville의 원소는 각각 0 이상 1,000,000 이하입니다.</li>
<li>모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>scoville</th>
<th>K</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[1, 2, 3, 9, 10, 12]</td>
<td>7</td>
<td>2</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<ol>
<li><p>스코빌 지수가 1인 음식과 2인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.<br>
새로운 음식의 스코빌 지수 = 1 + (2 * 2) = 5<br>
가진 음식의 스코빌 지수 = [5, 3, 9, 10, 12]</p></li>
<li><p>스코빌 지수가 3인 음식과 5인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.<br>
새로운 음식의 스코빌 지수 = 3 + (5 * 2) = 13<br>
가진 음식의 스코빌 지수 = [13, 9, 10, 12]</p></li>
</ol>

<p>모든 음식의 스코빌 지수가 7 이상이 되었고 이때 섞은 횟수는 2회입니다.</p>

<hr>

<p>※ 공지 - 2022년 12월 23일 테스트 케이스가 추가되었습니다. 기존에 제출한 코드가 통과하지 못할 수도 있습니다.<br>
※ 공지 - 2023년 03월 23일 테스트 케이스가 추가되었습니다. 기존에 제출한 코드가 통과하지 못할 수도 있습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

중복이 허용되는 multiset을 사용해서 풀었다. set은 vector와 달리 인덱스 접근이 불가하여 반복자에 증감연산자를 사용하거나 반복자에 사용되는 next,prev를 사용해서 구해야 한다.

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

// 가장 첫번째와 두번째가 둘다 0일 경우 -1 리턴
int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> ans;
    
    for(auto n : scoville) 
        ans.insert(n);
    
    if(*(++ans.begin()) ==0) return -1;
    while(*ans.begin()<K&&ans.size()>1)
    {
        int cnt = *ans.begin()+ *(++ans.begin()) *2;
        ans.erase(ans.begin(),next(ans.begin(), 2));     
        ans.insert(cnt);
        answer++;
    }
    if(ans.size()==1 && *ans.begin()<K) return -1; 
    
    return answer;
}
```   
