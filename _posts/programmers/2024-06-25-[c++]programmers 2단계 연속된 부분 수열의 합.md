---
layout: post
title: programmers 2단계 연속된 부분 수열의 합
categories : programmers 2단계
tag : [투 포인터,수열]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 연속된 부분 수열의 합 - 178870 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/178870#) 

### 성능 요약

메모리: 3.59 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 06월 25일 23:43:06

### 문제 설명

<p>비내림차순으로 정렬된 수열이 주어질 때, 다음 조건을 만족하는 부분 수열을 찾으려고 합니다.</p>

<ul>
<li>기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열이어야 합니다.</li>
<li>부분 수열의 합은 <code>k</code>입니다.</li>
<li>합이 <code>k</code>인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 찾습니다.</li>
<li>길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열을 찾습니다.</li>
</ul>

<p>수열을 나타내는 정수 배열 <code>sequence</code>와 부분 수열의 합을 나타내는 정수 <code>k</code>가 매개변수로 주어질 때, 위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요. 이때 수열의 인덱스는 0부터 시작합니다.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>5 ≤ <code>sequence</code>의 길이 ≤ 1,000,000

<ul>
<li>1 ≤ <code>sequence</code>의 원소 ≤ 1,000</li>
<li><code>sequence</code>는 비내림차순으로 정렬되어 있습니다.</li>
</ul></li>
<li>5 ≤ <code>k</code> ≤ 1,000,000,000

<ul>
<li><code>k</code>는 항상 <code>sequence</code>의 부분 수열로 만들 수 있는 값입니다.</li>
</ul></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>sequence</th>
<th>k</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[1, 2, 3, 4, 5]</td>
<td>7</td>
<td>[2, 3]</td>
</tr>
<tr>
<td>[1, 1, 1, 2, 3, 4, 5]</td>
<td>5</td>
<td>[6, 6]</td>
</tr>
<tr>
<td>[2, 2, 2, 2, 2]</td>
<td>6</td>
<td>[0, 2]</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<p>[1, 2, 3, 4, 5]에서 합이 7인 연속된 부분 수열은 [3, 4]뿐이므로 해당 수열의 시작 인덱스인 2와 마지막 인덱스 3을 배열에 담아 [2, 3]을 반환합니다.</p>

<p>입출력 예 #2</p>

<p>[1, 1, 1, 2, 3, 4, 5]에서 합이 5인 연속된 부분 수열은 [1, 1, 1, 2], [2, 3], [5]가 있습니다. 이 중 [5]의 길이가 제일 짧으므로 해당 수열의 시작 인덱스와 마지막 인덱스를 담은 [6, 6]을 반환합니다.</p>

<p>입출력 예 #3</p>

<p>[2, 2, 2, 2, 2]에서 합이 6인 연속된 부분 수열은 [2, 2, 2]로 3가지 경우가 있는데, 길이가 짧은 수열이 여러 개인 경우 앞쪽에 나온 수열을 찾으므로 [0, 2]를 반환합니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 50분

처음에는 단순히 수열의 값이 k와 같다면 answer에 값이 있는지 없는지, 있다면 길이를 체크 후 answer에 푸시를 해주는 방식으로 문제를 풀었다. 역시나 시간초과로 나와서 어떤 알고리즘을 사용하면 좋을까 찾아보다 투 포인터 알고리즘을 사용하여 풀었다.   

각 요소에서 시작하여 최악의 경우 O(n^2)의 시간 복잡도를 가짐.

### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// 부분 수열의 합은 k
// 여러개인 경우 길이가 짧은 수열
// 길이가 짧은 수열이 여러 개인 경우 앞쪽 에 나오는 수열 <= set 사용


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int check =0; // 현재 길이
    
    for(int i=0;i<sequence.size();i++)
    {        
        int sum=0;
        vector<int> idx;
        for(int j=i;j<sequence.size();j++)
        {
            sum+=sequence[j];
            idx.push_back(j);
            if(sum==k)
            {
                if(answer.empty())
                {
                    answer.push_back(idx.front());
                    answer.push_back(idx.back());
                    check = idx.size();
                }
                // 길이를 확인후 push
                else if(idx.size()<check)
                {
                    answer.clear();
                    
                    answer.push_back(idx.front());
                    answer.push_back(idx.back());
                    check = idx.size();
                }
            }
            if(sum>k) break;
        }        
    }
    
    return answer;
}
```

투 포인터 기법을 사용하여 sequence을 한번만 순회하기 때문에 O(n)의 복잡도를 가짐.   


### 나의 정답 풀이

```c++

// 투포인트 기법

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,-1);
    
    int left, right,sum;    left=right=sum=0;
    int minLength= 1000000;
    
    while(sequence.size()>right)
    {
        sum+=sequence[right];
        
        while(sum>k && left<=right)
        {
            sum-=sequence[left];
            left++;
        }
        
        if(sum==k)
        {
            if (right - left + 1 < minLength) 
            {
            minLength = right - left + 1;  
            answer[0] = left;
            answer[1] = right;
            }    
        }     
        right++;
    }
    
    
    return
```