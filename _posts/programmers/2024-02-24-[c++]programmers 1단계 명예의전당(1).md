---
layout: post
title: programmers 1단계 명예의 전당
categories : programmers 1단계
tag : [programmers,우선순위 힙,priority_queue,queue]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 1] 명예의 전당 (1) - 138477 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/138477) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 02월 24일 01:24:35

### 문제 설명

<p>"명예의 전당"이라는 TV 프로그램에서는 매일 1명의 가수가 노래를 부르고, 시청자들의 문자 투표수로 가수에게 점수를 부여합니다. 매일 출연한 가수의 점수가 지금까지 출연 가수들의 점수 중 상위 k번째 이내이면 해당 가수의 점수를 명예의 전당이라는 목록에 올려 기념합니다.&nbsp;즉 프로그램 시작 이후 초기에 k일까지는 모든 출연 가수의 점수가 명예의 전당에 오르게 됩니다. k일 다음부터는 출연 가수의 점수가 기존의 명예의 전당 목록의 k번째 순위의 가수 점수보다 더 높으면, 출연 가수의 점수가 명예의 전당에 오르게 되고 기존의 k번째 순위의 점수는 명예의 전당에서 내려오게 됩니다.</p>

<p>이 프로그램에서는 매일 "명예의 전당"의 최하위 점수를 발표합니다. 예를 들어, <code>k</code> = 3이고, 7일 동안 진행된 가수의 점수가 [10, 100, 20, 150, 1, 100, 200]이라면, 명예의 전당에서 발표된 점수는 아래의 그림과 같이 [10, 10, 10, 20, 20, 100, 100]입니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/b0893853-7471-47c0-b7e5-1e8b46002810/%EA%B7%B8%EB%A6%BC1.png" title="" alt="그림1.png"></p>

<p>명예의 전당 목록의 점수의 개수 <code>k</code>, 1일부터 마지막 날까지 출연한 가수들의 점수인 <code>score</code>가 주어졌을 때, 매일 발표된 명예의 전당의 최하위 점수를 return하는 solution 함수를 완성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>3 ≤ <code>k</code> ≤ 100</li>
<li>7 ≤ <code>score</code>의 길이 ≤ 1,000

<ul>
<li>0 ≤ <code>score[i]</code> ≤ 2,000</li>
</ul></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>k</th>
<th>score</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>3</td>
<td>[10, 100, 20, 150, 1, 100, 200]</td>
<td>[10, 10, 10, 20, 20, 100, 100]</td>
</tr>
<tr>
<td>4</td>
<td>[0, 300, 40, 300, 20, 70, 150, 50, 500, 1000]</td>
<td>[0, 0, 0, 0, 20, 40, 70, 70, 150, 300]</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<ul>
<li>문제의 예시와 같습니다.</li>
</ul>

<p><strong>입출력 예 #2</strong></p>

<ul>
<li>아래와 같이, [0, 0, 0, 0, 20, 40, 70, 70, 150, 300]을 return합니다.
<img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/5175c32d-44d7-4b13-be47-360bbe6a553c/%EA%B7%B8%EB%A6%BC2.png" title="" alt="그림2.png"></li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

### 나의 틀린 풀이   

일단 push할때마다 sort한다는 점이 각 추가 작업마다 O(n log n)의 정렬 비용이 발생하므로 별로 안좋은 코드로 일단 짜보았는데 역시나 틀렸다고 나온다,,   

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    
    vector<int> answer;
    vector<int> ans;
    int min=2001;
    for(int i=0;i<k;i++)
    {
        min = score[i]<min ? score[i] : min;
        answer.push_back(min);
        ans.push_back(score[i]);      
    }
    
    sort(ans.begin(),ans.end(),greater<int>());

    for(int i=k;i<score.size();i++)
    {
        // 세번째값을 저장.  
        cout<< ans[k-1] <<" ";
        
        // 여기가 문제..
        if(score[i]>ans[k-1])
        {
            ans.push_back(score[i]);
            sort(ans.begin(),ans.end(),greater<int>());
            ans.pop_back();
        }
        answer.push_back(ans.back());
    }

    return answer;
}
```

### 나의 정답 풀이   
   
그래서 priority_queue 사용해보았다. queue에 대한 자료구조도 따로 공부해봐야겠다..

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {

   vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙 정의

    for (int i = 0; i < score.size(); ++i) {
        // 처음 k일 동안은 모든 점수를 추가
        if (i < k) {
            minHeap.push(score[i]);
        } else {
            // k일 이후부터는 새로운 점수가 현재 힙의 최소값보다 클 경우에만 처리
            if (score[i] > minHeap.top()) {
                minHeap.pop(); // 현재 힙의 최소값 제거
                minHeap.push(score[i]); // 새로운 점수 추가
            }
        }
        answer.push_back(minHeap.top()); // 매일 최하위 점수를 결과에 추가
    }

    return answer;
}
```