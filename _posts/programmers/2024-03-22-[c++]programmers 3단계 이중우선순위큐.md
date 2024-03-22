---
layout: post
title: programmers 3단계 이중우선순위큐
categories : programmers 3단계
tag : [programmers,map,muliiset]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 3] 이중우선순위큐 - 42628 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42628) 

### 성능 요약

메모리: 3.68 MB, 시간: 0.04 ms

### 구분

코딩테스트 연습 > 힙（Heap）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 22일 20:49:43

### 문제 설명

<p>이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.</p>
<table class="table">
        <thead><tr>
<th>명령어</th>
<th>수신 탑(높이)</th>
</tr>
</thead>
        <tbody><tr>
<td>I 숫자</td>
<td>큐에 주어진 숫자를 삽입합니다.</td>
</tr>
<tr>
<td>D 1</td>
<td>큐에서 최댓값을 삭제합니다.</td>
</tr>
<tr>
<td>D -1</td>
<td>큐에서 최솟값을 삭제합니다.</td>
</tr>
</tbody>
      </table>
<p>이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.</li>
<li>operations의 원소는 큐가 수행할 연산을 나타냅니다.

<ul>
<li>원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.</li>
</ul></li>
<li>빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>operations</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]</td>
<td>[0,0]</td>
</tr>
<tr>
<td>["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]</td>
<td>[333, -45]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li>16과 -5643을 삽입합니다.</li>
<li>최솟값을 삭제합니다. -5643이 삭제되고 16이 남아있습니다.</li>
<li>최댓값을 삭제합니다. 16이 삭제되고 이중 우선순위 큐는 비어있습니다.</li>
<li>우선순위 큐가 비어있으므로 최댓값 삭제 연산이 무시됩니다.</li>
<li>123을 삽입합니다.</li>
<li>최솟값을 삭제합니다. 123이 삭제되고 이중 우선순위 큐는 비어있습니다.</li>
</ul>

<p>따라서 [0, 0]을 반환합니다.</p>

<p>입출력 예 #2</p>

<ul>
<li>-45와 653을 삽입후 최댓값(653)을 삭제합니다. -45가 남아있습니다.</li>
<li>-642, 45, 97을 삽입 후 최댓값(97), 최솟값(-642)을 삭제합니다. -45와 45가 남아있습니다.</li>
<li>333을 삽입합니다.</li>
</ul>

<p>이중 우선순위 큐에 -45, 45, 333이 남아있으므로, [333, -45]를 반환합니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

map은 자동으로 오름차순으로 정렬되기 때문에 map을 사용하여 풀었다.   
풀다보니 ans.end()->first 값이 계속 이상하게 나와 왜 그런지 찾아보니깐 end()는 범위의 끝을 나타내는 특별한 반복자라 유효한 데이터를 가르키지 않는다고 나와있다...
따라서 (--ans.end())->first를 해주거나 반복자를 하나 이전으로 이동시키는 함수인 **prev** 함수를 사용해서 뒤로 이동시킨 후 삭제하였다.


### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    map<int,int> ans;
    
    for(auto n : operations )
    {
        // 삽입
        if(n[0] == 'I')
        {
            int num = stoi(n.substr(2,n.size()-2));            
            ans[num]++;           
        }
        else if(n[0]=='D')
        {
            string str = n.substr(2,n.size()-2);
            if(str=="1") 
            {     
                if(!ans.empty())
                {    
                    if(prev(ans.end())->second>1)
                        prev(ans.end())->second--;
                    else
                        ans.erase(prev(ans.end()));
                }
            }
            else if(str=="-1")
            {
                if(!ans.empty())
                {                 
                    if(ans.begin()->second>1)
                        ans.begin()->second--;
                    else
                        ans.erase(ans.begin());
                }
            }
        }
    }
    if(ans.empty()) 
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(prev(ans.end())->first);
    answer.push_back(ans.begin()->first);
        
    return answer;
}
```   

### 다른 사람 풀이

나도 처음에 set을 사용할까 싶었지만 set은 중복을 허용하지 않기 때문에 쓰지 않았는데, 다른 사람 풀이를 보니 multiset이란걸 써서 풀었다.   

set과의 다른 점은 multiset은 중복을 허용한다는 것이다.

```c++
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
```