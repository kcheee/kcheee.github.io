---
layout: post
title: programmers 2단계 타겟넘버
categories : programmers 2단계
tag : [programmers,dfs,재귀]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 타겟 넘버 - 43165 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43165) 

### 성능 요약

메모리: 4.21 MB, 시간: 0.03 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 20일 18:07:42

### 문제 설명

<p>n개의 음이 아닌 정수들이 있습니다. 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.</p>
<div class="highlight"><pre class="codehilite"><sider-code-explain id="sider-code-explain" data-gpts-theme="light"></sider-code-explain><code>-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
</code></pre></div>
<p>사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>주어지는 숫자의 개수는 2개 이상 20개 이하입니다.</li>
<li>각 숫자는 1 이상 50 이하인 자연수입니다.</li>
<li>타겟 넘버는 1 이상 1000 이하인 자연수입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>numbers</th>
<th>target</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[1, 1, 1, 1, 1]</td>
<td>3</td>
<td>5</td>
</tr>
<tr>
<td>[4, 1, 2, 1]</td>
<td>4</td>
<td>2</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제 예시와 같습니다.</p>

<p><strong>입출력 예 #2</strong></p>
<div class="highlight"><pre class="codehilite"><code>+4+1-2+1 = 4
+4-1+2-1 = 4
</code></pre></div>
<ul>
<li>총 2가지 방법이 있으므로, 2를 return 합니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

재귀를 사용한 dfs로 풀었다.   
아직 bfs/dfs가 미숙하여 많이 풀어봐야겠다는 생각이 들었다..    

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer=0;
void dfs(vector<int>& numbers, int target, int sum, int index) {
    // 모든 숫자를 탐색했을 때
    if (index == numbers.size()) {
        // 현재까지의 합이 타겟 넘버와 같다면 방법의 수를 증가
        if (sum == target) {
            answer++;
        }
        return;
    }
    
    // 현재 숫자를 더하는 경우
    dfs(numbers, target, sum + numbers[index], index + 1);
    // 현재 숫자를 빼는 경우
    dfs(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers,target,0,0);
    return answer;
}
```   
