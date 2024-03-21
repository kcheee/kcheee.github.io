---
layout: post
title: programmers 2단계 k진수에서 소수 개수 구하기
categories : programmers 2단계
tag : [programmers,소수,진수,find,reverse]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] k진수에서 소수 개수 구하기 - 92335 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/92335) 

### 성능 요약

메모리: 3.71 MB, 시간: 0.05 ms

### 구분

코딩테스트 연습 > 2022 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 21일 14:19:21

### 문제 설명

<h5>문제 설명</h5>

<p>양의 정수 <code>n</code>이 주어집니다. 이 숫자를 <code>k</code>진수로 바꿨을 때, 변환된 수 안에 아래 조건에 맞는 소수(Prime number)가 몇 개인지 알아보려 합니다.</p>

<ul>
<li><code>0P0</code>처럼 소수 양쪽에 0이 있는 경우</li>
<li><code>P0</code>처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우</li>
<li><code>0P</code>처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우</li>
<li><code>P</code>처럼 소수 양쪽에 아무것도 없는 경우</li>
<li>단, <code>P</code>는 각 자릿수에 0을 포함하지 않는 소수입니다.

<ul>
<li>예를 들어, 101은 <code>P</code>가 될 수 없습니다.</li>
</ul></li>
</ul>

<p>예를 들어, 437674을 3진수로 바꾸면 <code>211</code>0<code>2</code>01010<code>11</code>입니다. 여기서 찾을 수 있는 조건에 맞는 소수는 왼쪽부터 순서대로 211, 2, 11이 있으며, 총 3개입니다. (211, 2, 11을 <code>k</code>진법으로 보았을 때가 아닌, 10진법으로 보았을 때 소수여야 한다는 점에 주의합니다.) 211은 <code>P0</code> 형태에서 찾을 수 있으며, 2는 <code>0P0</code>에서, 11은 <code>0P</code>에서 찾을 수 있습니다.</p>

<p>정수 <code>n</code>과 <code>k</code>가 매개변수로 주어집니다. <code>n</code>을 <code>k</code>진수로 바꿨을 때, 변환된 수 안에서 찾을 수 있는 <strong>위 조건에 맞는 소수</strong>의 개수를 return 하도록 solution 함수를 완성해 주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>n</code> ≤ 1,000,000</li>
<li>3 ≤ <code>k</code> ≤ 10</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>k</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>437674</td>
<td>3</td>
<td>3</td>
</tr>
<tr>
<td>110011</td>
<td>10</td>
<td>2</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제 예시와 같습니다. </p>

<p><strong>입출력 예 #2</strong></p>

<p>110011을 10진수로 바꾸면 110011입니다. 여기서 찾을 수 있는 조건에 맞는 소수는 11, 11 2개입니다. 이와 같이, 중복되는 소수를 발견하더라도 모두 따로 세어야 합니다.</p>

<h5>문제가 잘 안풀린다면😢</h5>

<p>힌트가 필요한가요? [코딩테스트 연습 힌트 모음집]으로 오세요! → <a href="https://school.programmers.co.kr/learn/courses/14743?itm_content=lesson92335" target="_blank" rel="noopener">클릭</a></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이
  
테스트 1번에서 core dumped가 계속 나와 자료형을 long long으로 바꾸고 소수 판별을 sqrt(n)으로 바꿔서 계산하였다.

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
    // 1. 소수 양쪽에 0  => 이건 가운데
    // 2. 소수 오른쪽에 0 왼쪽에 아무것도 없어야 함 =>왼쪽 끝에 자리에서 오른쪽에 0이 나올 때 까지
    // 3. 소수 왼쪽에 0 오른쪽에 아무것도 없어야 함 =>오른쪽 끝에 자리에서 왼쪽에 0이 나올 때 까지
    // 4. 양쪽에 아무것도 없는경우 => 0이 없는 경우

// 소수 판별기 소수면 true
bool decimal(long long n){
    if(n < 2) return false;     
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }   
    return true;
}

// 2번,3번 조건의 문자열 cut
string cut(string s)
{
    string ans;
    auto it = s.find('0');
    if(it!=string::npos)
    {
        for(int i=0;i<it;i++)    
            ans+=s[i];         
    }
    else ans =s;
    return ans;
}

int solution(int n, int k) {
    int answer = 0;
    // 진법 계산
    string str;
    while(n!=0)
    {       
        str = to_string(n%k)+str;
        n=n/k;
    } 
    cout<<str<<endl;
    
    // 4번 체크
    if(cut(str)==str) 
    {
        return decimal(stoll(str))==true ? 1 : 0;
    }
    
    // 1번 체크
    // - 첫번째 글자 건너뛰고 마지막 글자도 계산 안해야 함.
    
    bool flag =false;
    string ans1;
    for(int i=0;i<str.size();i++)
    {
        if(flag) 
        {          
            if(str[i] == '0') 
            {
                flag=false;
                if(str[i-1]!='0')                
                answer += decimal(stoll(ans1))==true ? 1 : 0;
                ans1="";
            }
            else ans1+= str[i];                          
        }

        if(str[i] == '0') flag=true;
    }
    
    // 2번 체크
    if(str[0]!='0')
    answer += decimal(stoi(cut(str)))==true ? 1 : 0;
    // 3번 체크
    string str_reverse = str;  reverse(str_reverse.begin(),str_reverse.end());
    if(str_reverse[0]!='0')
    {      
        string s = cut(str_reverse); reverse(s.begin(),s.end());
        answer += decimal(stoll(s))==true ? 1 : 0;
    }
    
    return answer;
}
```   
