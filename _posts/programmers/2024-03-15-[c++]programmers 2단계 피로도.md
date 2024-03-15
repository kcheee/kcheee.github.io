---
layout: post
title: programmers 2단계 피로도
categories : programmers 2단계
tag : [programmers,sort,next_permutation,순열]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 피로도 - 87946 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/87946) 

### 성능 요약

메모리: 4.22 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 완전탐색

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 15일 20:18:07

### 문제 설명

<p>XX게임에는 피로도 시스템(0 이상의 정수로 표현합니다)이 있으며, 일정 피로도를 사용해서 던전을 탐험할 수 있습니다. 이때, 각 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있습니다. "최소 필요 피로도"는 해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도를 나타내며, "소모 피로도"는 던전을 탐험한 후 소모되는 피로도를 나타냅니다. 예를 들어 "최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상 이어야 하며, 던전을 탐험한 후에는 피로도 20이 소모됩니다.</p>

<p>이 게임에는 하루에 한 번씩 탐험할 수 있는 던전이 여러개 있는데, 한 유저가 오늘 이 던전들을 최대한 많이 탐험하려 합니다. 유저의 현재 피로도 k와 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열 dungeons 가 매개변수로 주어질 때, 유저가 탐험할수 있는 최대 던전 수를 return 하도록 solution 함수를 완성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>k는 1 이상 5,000 이하인 자연수입니다.</li>
<li>dungeons의 세로(행) 길이(즉, 던전의 개수)는 1 이상 8 이하입니다.

<ul>
<li>dungeons의 가로(열) 길이는 2 입니다.</li>
<li>dungeons의 각 행은 각 던전의 ["최소 필요 피로도", "소모 피로도"] 입니다.</li>
<li>"최소 필요 피로도"는 항상 "소모 피로도"보다 크거나 같습니다.</li>
<li>"최소 필요 피로도"와 "소모 피로도"는 1 이상 1,000 이하인 자연수입니다.</li>
<li>서로 다른 던전의 ["최소 필요 피로도", "소모 피로도"]가 서로 같을 수 있습니다. </li>
</ul></li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>k</th>
<th>dungeons</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>80</td>
<td>[[80,20],[50,40],[30,10]]</td>
<td>3</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>현재 피로도는 80입니다.</p>

<p>만약, 첫 번째 → 두 번째 → 세 번째 던전 순서로 탐험한다면</p>

<ul>
<li>현재 피로도는 80이며, 첫 번째 던전을 돌기위해 필요한 "최소 필요 피로도" 또한 80이므로, 첫 번째 던전을 탐험할 수 있습니다. 첫 번째 던전의 "소모 피로도"는 20이므로, 던전을 탐험한 후 남은 피로도는 60입니다.</li>
<li>남은 피로도는 60이며, 두 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 50이므로, 두 번째 던전을 탐험할 수 있습니다. 두 번째 던전의 "소모 피로도"는 40이므로, 던전을 탐험한 후 남은 피로도는 20입니다.</li>
<li>남은 피로도는 20이며, 세 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 30입니다. 따라서 세 번째 던전은 탐험할 수 없습니다.</li>
</ul>

<p>만약, 첫 번째 → 세 번째 → 두 번째 던전 순서로 탐험한다면</p>

<ul>
<li>현재 피로도는 80이며, 첫 번째 던전을 돌기위해 필요한 "최소 필요 피로도" 또한 80이므로, 첫 번째 던전을 탐험할 수 있습니다. 첫 번째 던전의 "소모 피로도"는 20이므로, 던전을 탐험한 후 남은 피로도는 60입니다.</li>
<li>남은 피로도는 60이며, 세 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 30이므로, 세 번째 던전을 탐험할 수 있습니다. 세 번째 던전의 "소모 피로도"는 10이므로, 던전을 탐험한 후 남은 피로도는 50입니다.</li>
<li>남은 피로도는 50이며, 두 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 50이므로, 두 번째 던전을 탐험할 수 있습니다. 두 번째 던전의 "소모 피로도"는 40이므로, 던전을 탐험한 후 남은 피로도는 10입니다.</li>
</ul>

<p>따라서 이 경우 세 던전을 모두 탐험할 수 있으며, 유저가 탐험할 수 있는 최대 던전 수는 3입니다.</p>

<hr>

<p>※ 공지 - 2022년 2월 25일 테스트케이스가 추가되었습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

최소 필요 피로도 - 소모 필요도를 비교하여 정렬한 후 계산을 해서 풀어보았다.   
정답률이 89.5가 나왔는데 반례를 못 찾다가 gpt에 물어봤는데 gpt3.5도 찾지 못해서 뤼튼을 사용하여 반례를 찾아보았다.   
k = 100일때 [[100,90],[10,5],[10,5]] 이면 정답은 3 이지만 내 코드에 대한 답은 2가 나온다. ㅠㅠㅠㅠ

### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 이 코드의 반례 
// k = 100 [[100,90],[10,5],[10,5]]
bool compare(vector<int> a,vector<int> b)
{
    // 차이가 같을 경우
    if((a[0]-a[1])==(b[0]-b[1])) return a[1] < b[1];
    return (a[0]-a[1]) > (b[0]-b[1]);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(),dungeons.end(),compare);
    
    for(int i=0;i<dungeons.size();i++)
    {
        if(dungeons[i][0]<=k)
        {
            if(k-dungeons[i][1]>=0)
            {
                k-=dungeons[i][1];
                answer++;
            }
        }
    }
        
    for(auto n : dungeons) for(auto m : n) cout<<m<<" ";
    return answer;
}
```   


### 나의 정답 풀이

완전 탐색 밖에 답이 없다 싶어서 for문으로 돌려보려하였는데 **next_permutation** 이란 순열을 구하는 함수를 찾아서 사용해보았다.   
이 문제는 다시 풀어봐야겠다..


```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 완전 탐색

int solution(int k, vector<vector<int>> dungeons) {
 int answer = 0;
    
    sort(dungeons.begin(), dungeons.end()); // next_permutation을 사용하기 위해 초기 정렬
    do {
        int tempK = k;
        int tempAnswer = 0;
        for(int i = 0; i < dungeons.size(); i++) {
            if(dungeons[i][0] <= tempK) { // 최소 피로도 조건을 만족하면
                tempK -= dungeons[i][1]; // 피로도 감소
                tempAnswer++; // 탐험한 던전 수 증가
            }
        }
        answer = max(answer, tempAnswer); // 최대 탐험 가능한 던전 수 갱신
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}

```