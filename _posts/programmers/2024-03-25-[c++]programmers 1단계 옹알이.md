---
layout: post
title: programmers 1단계 옹알이[2]
categories : programmers 1단계
tag : [programmers,substr]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 1] 옹알이 (2) - 133499 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/133499) 

### 성능 요약

메모리: 4.15 MB, 시간: 0.05 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 25일 17:49:19

### 문제 설명

<p>머쓱이는 태어난 지 11개월 된 조카를 돌보고 있습니다. 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음과 네 가지 발음을 조합해서 만들 수 있는 발음밖에 하지 못하고 연속해서 같은 발음을 하는 것을 어려워합니다. 문자열 배열 <code>babbling</code>이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>babbling</code>의 길이 ≤ 100</li>
<li>1 ≤ <code>babbling[i]</code>의 길이 ≤ 30</li>
<li>문자열은 알파벳 소문자로만 이루어져 있습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>babbling</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>["aya", "yee", "u", "maa"]</td>
<td>1</td>
</tr>
<tr>
<td>["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]</td>
<td>2</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li>["aya", "yee", "u", "maa"]에서 발음할 수 있는 것은 "aya"뿐입니다. 따라서 1을 return합니다.</li>
</ul>

<p>입출력 예 #2</p>

<ul>
<li>["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]에서 발음할 수 있는 것은 "aya" + "ye" = "ayaye", "ye" + "ma" + "woo" = "yemawoo"로 2개입니다. "yeye"는 같은 발음이 연속되므로 발음할 수 없습니다. 따라서 2를 return합니다.</li>
</ul>

<hr>

<h5>유의사항</h5>

<ul>
<li>네 가지를 붙여 만들 수 있는 발음 이외에는 어떤 발음도 할 수 없는 것으로 규정합니다. 예를 들어 "woowo"는 "woo"는 발음할 수 있지만 "wo"를 발음할 수 없기 때문에 할 수 없는 발음입니다.</li>
</ul>

<hr>

<p>※ 공지 - 2024년 2월 20일 문제 지문의 오탈자가 수정되었습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

진법 변환하고 변환 도중 인원*순서보다 string값이 커지면 변환을 종료하는식으로 메모리를 줄였다.



### 나의 정답 풀이

반복된 값들을 함수로 만들어야 했지만 귀찮아서 그냥 했다..


```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// a y w m 앞 글자가 나온다면 뒷글자를 확인 하는 방법으로 진행
// 반복 진행은 안된다.

int solution(vector<string> babbling) {
    int answer = 0;
    string aya = "aya", ye = "ye", woo = "woo", ma = "ma";
    
    for(auto n : babbling)
        for(int i=0;i<n.size();i++)
        {
            if (n[i] == 'a' && i + 2 < n.size()) {  // 'a'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 3);
                if(sub == aya)
                {
                    i+=2;
                    if(i==n.size()-1) 
                    {
                        cout<<sub<<endl;
                        answer++;
                    }

                    if(n[i+1]=='a') 
                    {                   
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'y' && i + 1 < n.size()) {  // 'a'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 2);
                if(sub == ye)
                {                  
                    i+=1;
                    if(i==n.size()-1) 
                    {
                        cout<<sub<<endl;
                        answer++;
                    }
                    if(n[i+1]=='y') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'w' && i + 2 < n.size()) {  // 'a'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 3);
                if(sub == woo)
                {
                    i+=2;
                    if(i==n.size()-1) 
                    {
                        cout<<sub<<endl;
                        answer++;
                    }

                    if(n[i+1]=='w') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (n[i] == 'm' && i + 1 < n.size()) {  // 'a'를 찾고 그 다음 문자가 존재하는지 확인
                string sub = n.substr(i, 2);
                if(sub == ma)
                {
                    i+=1;
                    if(i==n.size()-1) 
                    {
                        cout<<sub<<endl;
                        answer++;
                    }
                    if(n[i+1]=='m') 
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            
        }
    return answer;
}
```   

### 다른 사람 풀이

다른사람 풀이를 보니 특정 문자열이 나오면 공백으로 바꿔주고
만약 포문이 끝나고 공백이라면 answer++해주는 방법으로 효율성을 높였다. 코드 가독성을 높여야겠다..

```c++
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for(int i;i<babbling.size();i++)
    {
        string temp1="";
        string temp2="";
        for(char c:babbling[i])
        {
            temp1+=c;
            if(temp1 == "aya"||temp1 == "ye"||temp1 == "woo"||temp1 == "ma")
            {
                if(temp2 == temp1) break;
                temp2=temp1;
                temp1="";
            }
        }
        if(temp1.size()==0) answer++;
    }
    return answer;
}
```
