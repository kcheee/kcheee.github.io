---
layout: post
title: programmers 2단계 n개의 최소공배수
categories : programmers 2단계
tag : [programmers,2단계,유클리드 호제법]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] N개의 최소공배수 - 12953 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12953) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 02월 23일 22:57:02

### 문제 설명

<p>두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 예를 들어 2와 7의 최소공배수는 14가 됩니다. 정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요. </p>

<h5>제한 사항</h5>

<ul>
<li>arr은 길이 1이상, 15이하인 배열입니다.</li>
<li>arr의 원소는 100 이하인 자연수입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>arr</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[2,6,8,14]</td>
<td>168</td>
</tr>
<tr>
<td>[1,2,3]</td>
<td>6</td>
</tr>
</tbody>
      </table>

> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
## 풀이

## 나의 정답 풀이   

유클리드 호제법을 사용하여 최대공약수와 최소공배수를 계산후   
두 수의 최소 공배수를 활용하여 그 다음 최소 공배수를 구하는 방식으로 풀었다.

while b!=0
int r = a%b;
a= b;
b=r;


```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 유클리드 호제법

// 유클리드 호제법을 이용한 최대공약수 계산
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수 계산
int lcm(int a, int b) {
    return a / gcd(a, b) * b; // 오버플로우를 방지하기 위해 순서 주의
}

int solution(vector<int> arr) {
    int result = arr[0]; // 배열의 첫 번째 요소로 초기화

    for (int i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]); 
    }

    return result;
}
```