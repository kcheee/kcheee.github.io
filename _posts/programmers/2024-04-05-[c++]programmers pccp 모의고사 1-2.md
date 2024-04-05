---
layout: post
title: programmers pccp 모의고사 1-2
categories : programmers pccp
tag : [programmers,dfs]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [PCCP 모의고사 #1] 1번 - 외톨이 알파벳

[문제 링크](https://school.programmers.co.kr/learn/courses/15008/lessons/121685)  



## 풀이

dp를 사용해서 풀다가 뇌정지&스트레스가 와서 갈아엎고 dfs방식으로 풀었다.

### 나의 틀린 풀이

```c++
#include <vector>
#include <algorithm>
using namespace std;

int maxScore = 0; // 최대 능력치 합을 저장할 변수

// dfs 
void dfs(vector<vector<int>>& ability, vector<bool>& visited, int depth, int score, int n, int m) {
    if (depth == m) { // 모든 종목에 대해 대표를 선발했다면
        maxScore = max(maxScore, score); // 최대 능력치 합 갱신
        return;
    }
    for (int i = 0; i < n; ++i) { // 모든 학생에 대해 반복
        if (!visited[i]) { 
            visited[i] = true; 
            dfs(ability, visited, depth + 1, score + ability[i][depth], n, m); // 다음 종목에 대해 dfs 진행
            visited[i] = false; 
        }
    }
}

int solution(vector<vector<int>> ability) {
    int n = ability.size(); // 학생 수
    int m = ability[0].size(); // 종목 수
    vector<bool> visited(n, false); 

    maxScore = 0; 
    dfs(ability, visited, 0, 0, n, m); // dfs 탐색 시작

    return maxScore; 
}

```   
