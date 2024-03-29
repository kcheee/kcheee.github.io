---
layout: post
title: programmers 3단계 단어변환
categories : programmers 3단계
tag : [programmers,dfs]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 3] 단어 변환 - 43163 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43163) 

### 성능 요약

메모리: 4.16 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 29일 13:12:01

### 문제 설명

<p>두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.</p>
<div class="highlight"><pre class="codehilite"><code>1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
</code></pre></div>
<p>예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.</p>

<p>두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>각 단어는 알파벳 소문자로만 이루어져 있습니다.</li>
<li>각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.</li>
<li>words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.</li>
<li>begin과 target은 같지 않습니다.</li>
<li>변환할 수 없는 경우에는 0를 return 합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>begin</th>
<th>target</th>
<th>words</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>"hit"</td>
<td>"cog"</td>
<td>["hot", "dot", "dog", "lot", "log", "cog"]</td>
<td>4</td>
</tr>
<tr>
<td>"hit"</td>
<td>"cog"</td>
<td>["hot", "dot", "dog", "lot", "log"]</td>
<td>0</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>예제 #1<br>
문제에 나온 예와 같습니다.</p>

<p>예제 #2<br>
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

dfs 방법을 사용해서 풀었다.

1. 한개의 알파벳만 차이나는 단어를 찾는 함수 str_bool을 만들어 bool 체크
2. dfs를 사용하여 target과 알파벳 하나 차이나는 단어를 찾고 ans가 가장 작은 값을 answer에 더해준다.

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool str_bool(string a,string b)
{
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) cnt++;
        if(cnt>1) return false;
    }
    return true;
}
bool flag[51];
vector<string> str;
int answer = 55; 
void dfs(string s,string target,int ans)
{
    // target을 찾은경우

    if(str_bool(s,target)) 
    {
        ans++;
        answer = answer>ans ? ans : answer;        
    }
    for(int i=0;i<str.size();i++)
    {
        if(str_bool(s,str[i])&&flag[i]==false)
        {
            flag[i] = true;
           // cout<<str[i]<<" "<<ans<<" ";
            if(str_bool(s,target)) dfs(s,target,++ans);     
            else  dfs(str[i],target,++ans);            
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(),words.end(),target) == words.end()) return 0;
    
    str = words;
    
    dfs(begin,target,0);
      
    return answer;
}
```   
