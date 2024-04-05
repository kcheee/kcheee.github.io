---
layout: post
title: programmers pccp 모의고사 1-4
categories : programmers pccp
tag : [programmers,compare,priority_queue]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [PCCP 모의고사 #1] 4번 - 운영체제

[문제 링크](https://school.programmers.co.kr/learn/courses/15008/lessons/121686)  



## 풀이

1. sort를 사용하여 program의 호출시간, 프로그램점수를 1순위,2순위로하여 정렬한다.
2. priority_queue를 사용하여 점수가 낮은 순으로 정렬하는 a를 선언한다.
3. t는 현재시간으로, 현재시간보다 작으면(첫 push 제외) a에 푸시해준다. 여기서 a는 Compare구조체로 인하여 
프로그램점수가 낮을수록, 호출시간이 앞에 있을수록 값은 맨 위로 올라간다.
4. do while문을 사용하여 a와 program이 비어있지않을 때 실행을 하고, a.top을 사용하여 프로그램 실행시간을 가져와 현재시간 t를 업데이트한다.
5. 만약 t보다 작은 값이 안나오고 program에 값이 있다면 program.back()에 있는 호출시간에 t를 업데이트한다


### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

// 05:30
using namespace std;
struct Compare {
    // 우선순위 큐에서 사용할 비교 함수
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1]; // 점수가 같으면, 호출 시간이 늦은 순
        return a[0] > b[0]; // 점수가 낮은 순서로
    }
};

long long ans = 0;
bool compare(vector<int> a, vector<int> b)
{
    if(a[1]==b[1]) return a[0]>b[0]; 
    return a[1]>b[1];
}

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11,0);
    // 내림차순
    priority_queue<vector<int>, vector<vector<int>>, Compare> a;
    long long t=0;
    
    sort(program.begin(),program.end(),compare); 
        
    do {
    // program 배열에서 현재 시간 t 이전에 호출된 모든 프로그램을 a 우선순위 큐에 추가
    while(!program.empty() && t >= program.back()[1]) {
        a.push(program.back());
        program.pop_back();
    }

    if (!a.empty()) {
        // a 우선순위 큐에서 프로그램을 처리
        answer[a.top()[0]] += t - a.top()[1]; // 대기 시간 계산
        t += a.top()[2]; // 프로그램 실행 시간을 t에 추가
        a.pop(); 
    } else if (!program.empty()) {
        // a가 비어있고, program에 처리할 프로그램이 남아있는 경우
        // t를 다음 프로그램의 호출 시점으로 업데이트
        t = program.back()[1];
    }
} while (!program.empty() || !a.empty());

    answer[0]=t;
    
    return answer;
}


```   
