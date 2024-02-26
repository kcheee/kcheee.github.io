---
layout: post
title: programmers 2단계 연속 부분 수열의 합
categories : programmers 2단계
tag : [programmers,sort,unique,erase,set]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 연속 부분 수열 합의 개수 - 131701 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/131701) 

### 성능 요약

메모리: 7.44 MB, 시간: 3717.30 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 02월 26일 19:17:40

### 문제 설명

<p>철호는 수열을 가지고 놀기 좋아합니다. 어느 날 철호는 어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇 가지인지 알아보고 싶어졌습니다. 원형 수열이란 일반적인 수열에서 처음과 끝이 연결된 형태의 수열을 말합니다. 예를 들어 수열 [7, 9, 1, 1, 4] 로 원형 수열을 만들면 다음과 같습니다.<br>
<img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f207cd37-34dc-4cbd-96bb-83435bd6efd4/%EA%B7%B8%EB%A6%BC.png" title="" alt="그림.png"><br>
원형 수열은 처음과 끝이 연결되어 끊기는 부분이 없기 때문에 연속하는 부분 수열도 일반적인 수열보다 많아집니다.<br>
원형 수열의 모든 원소 <code>elements</code>가 순서대로 주어질 때, 원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를 return 하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>3 ≤ <code>elements</code>의 길이 ≤ 1,000</li>
<li>1 ≤ <code>elements</code>의 원소 ≤ 1,000</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>elements</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[7,9,1,1,4]</td>
<td>18</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
길이가 1인 연속 부분 수열로부터 [1, 4, 7, 9] 네 가지의 합이 나올 수 있습니다.<br>
길이가 2인 연속 부분 수열로부터 [2, 5, 10, 11, 16] 다섯 가지의 합이 나올 수 있습니다.<br>
길이가 3인 연속 부분 수열로부터 [6, 11, 12, 17, 20] 다섯 가지의 합이 나올 수 있습니다.<br>
길이가 4인 연속 부분 수열로부터 [13, 15, 18, 21] 네 가지의 합이 나올 수 있습니다.<br>
길이가 5인 연속 부분 수열로부터 [22] 한 가지의 합이 나올 수 있습니다.<br>
이들 중 중복되는 값을 제외하면 다음과 같은 18가지의 수들을 얻습니다.<br>
[1, 2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 15, 16, 17, 18, 20, 21, 22]</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges   

## 풀이

### 나의 정답 풀이   

```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 마지막에 sort하고 unique하고 erase 해줌

int solution(vector<int> elements) {
    
    vector<int> a;

    long long add=0;
    for(int i=0;i<elements.size();i++)
    {
        for(int j=0;j<elements.size();j++)
        {
            for(int k=0;k<i+1;k++)
            {
                add +=elements[(j+k)%elements.size()];
            }
            a.push_back(add);
            add=0;
        }       
    }
    
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    
    //원형 수열을 일단 만들자
     
    return a.size();
}
```   

### 다른 사람 풀이   
   
Set을 사용하면 자동으로 오름차순으로 정렬해주고, 중복을 제거해줘 시간 복잡도를 줄일 수 있다..   
자꾸 까먹어서 나중에 따로 set 자료구조 정리를 해놔야겠다.   

```c++
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0 ; i < n ; ++i) {
        int sum = 0;
        for (int j = i ; j < i + n ; ++j) {
            sum += elements[j % n];
            S.insert(sum);
        }
    }

    return S.size();
}


```