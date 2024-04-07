---
layout: post
title: programmers 3단계 등굣길
categories : programmers 3단계
tag : [programmers,dp]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 3] 등굣길 - 42898 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42898) 

### 성능 요약

메모리: 3.8 MB, 시간: 0.06 ms

### 구분

코딩테스트 연습 > 동적계획법（Dynamic Programming）

### 채점결과

정확성: 50.0<br/>효율성: 50.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 07일 21:18:13

### 문제 설명

<p data-sider-select-id="6016e429-0837-49df-b348-02ab2a9a5e8e">계속되는 폭우로 일부 지역이 물에 잠겼습니다. 물에 잠기지 않은 지역을 통해 학교를 가려고 합니다. 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다. </p>

<p data-sider-select-id="c3debd57-f106-494b-9944-4801c6845e43">아래 그림은 m = 4, n = 3 인 경우입니다.</p>

<p><img src="https://grepp-programmers.s3.amazonaws.com/files/ybm/056f54e618/f167a3bc-e140-4fa8-a8f8-326a99e0f567.png" title="" alt="image0.png"></p>

<p data-sider-select-id="73fb85fc-24c7-478a-a4b3-b18e9333f8e8">가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다. </p>

<p data-sider-select-id="cbe93536-bd2f-4cb1-b344-be8008eb99c0">격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다. <strong>오른쪽과 아래쪽으로만 움직여</strong> 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li data-sider-select-id="24ee57eb-3cd2-4596-b3e6-07736b602415">격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.

<ul>
<li data-sider-select-id="f96dfd64-b37f-40f9-89d8-b15716b4d259">m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.</li>
</ul></li>
<li>물에 잠긴 지역은 0개 이상 10개 이하입니다.</li>
<li>집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>m</th>
<th>n</th>
<th>puddles</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td data-sider-select-id="8164473c-b050-435d-81fa-c4bb988884a0">4</td>
<td data-sider-select-id="c9dcea09-a80a-4f50-b06d-6dcc6e1d8638">3</td>
<td>[[2, 2]]</td>
<td>4</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p><img src="https://grepp-programmers.s3.amazonaws.com/files/ybm/32c67958d5/729216f3-f305-4ad1-b3b0-04c2ba0b379a.png" title="" alt="image1.png"></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 1시간

dp 문제로 물에 잠긴 부분은 -1로 선언해주고, 오른쪽과 왼쪽으로만 이동 가능하므로 왼쪽과 위쪽의 최단경로dp의 개수를 합하여 경로를 계산하였다.

풀이방법은 바로 생각해서 풀었으나, % 1000000007 하는 부분을 생각지 못해서, 시간을 잡아먹었다.   
문제를 똑바로 읽도록 하자!

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> dp(n, vector<long long>(m, 0)); // 초기값을 0으로 설정
    
    // 물에 잠긴 지역 표시
    for (auto puddle : puddles) {
        dp[puddle[1] - 1][puddle[0] - 1] = -1; // 물에 잠긴 지역은 -1로 표시
    }
    
    // 집 위치 초기값 설정
    dp[0][0] = 1;
    
    // 최단경로 개수 계산
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // 물에 잠긴 지역인 경우 해당 지점의 값을 0으로 설정
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            // 위쪽과 왼쪽의 최단경로 개수를 합산하여 현재 지점의 최단경로 개수를 계산
            if (i > 0) dp[i][j] += dp[i - 1][j] % 1000000007;
            if (j > 0) dp[i][j] += dp[i][j - 1] % 1000000007;
        }
    }
    
    // 최단경로의 개수 반환
    return dp[n - 1][m - 1] % 1000000007;
}
```   
