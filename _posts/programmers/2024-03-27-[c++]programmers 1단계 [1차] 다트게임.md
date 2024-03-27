---
layout: post
title: programmers 1단계 다트게임
categories : programmers 1단계
tag : [programmers,map]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 1] [1차] 다트 게임 - 17682 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17682) 

### 성능 요약

메모리: 4.15 MB, 시간: 0.02 ms

### 구분

코딩테스트 연습 > 2018 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 27일 19:06:29

### 문제 설명

<h2>다트 게임</h2>

<p>카카오톡에 뜬 네 번째 별! 심심할 땐? 카카오톡 게임별~</p>

<p><img src="http://t1.kakaocdn.net/welcome2018/gamestar.png" title="게임별" alt="Game Star"></p>

<p>카카오톡 게임별의 하반기 신규 서비스로 다트 게임을 출시하기로 했다. 다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 실력을 겨루는 게임으로, 모두가 간단히 즐길 수 있다.<br>
갓 입사한 무지는 코딩 실력을 인정받아 게임의 핵심 부분인 점수 계산 로직을 맡게 되었다. 다트 게임의 점수 계산 로직은 아래와 같다.</p>

<ol>
<li>다트 게임은 총 3번의 기회로 구성된다.</li>
<li>각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.</li>
<li>점수와 함께 Single(<code>S</code>), Double(<code>D</code>), Triple(<code>T</code>) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수<sup>1</sup> , 점수<sup>2</sup> , 점수<sup>3</sup> )으로 계산된다.</li>
<li>옵션으로 스타상(<code>*</code>) , 아차상(<code>#</code>)이 존재하며 스타상(<code>*</code>) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 아차상(<code>#</code>) 당첨 시 해당 점수는 마이너스된다.</li>
<li>스타상(<code>*</code>)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(<code>*</code>)의 점수만 2배가 된다. (예제 4번 참고)</li>
<li>스타상(<code>*</code>)의 효과는 다른 스타상(<code>*</code>)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(<code>*</code>) 점수는 4배가 된다. (예제 4번 참고)</li>
<li>스타상(<code>*</code>)의 효과는 아차상(<code>#</code>)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(<code>#</code>)의 점수는 -2배가 된다. (예제 5번 참고)</li>
<li>Single(<code>S</code>), Double(<code>D</code>), Triple(<code>T</code>)은 점수마다 하나씩 존재한다.</li>
<li>스타상(<code>*</code>), 아차상(<code>#</code>)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다. </li>
</ol>

<p>0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.</p>

<h3>입력 형식</h3>

<p>"점수|보너스|[옵션]"으로 이루어진 문자열 3세트.<br>
예)  <code>1S2D*3T</code></p>

<ul>
<li>점수는 0에서 10 사이의 정수이다.</li>
<li>보너스는 S, D, T 중 하나이다.</li>
<li>옵선은 *이나 # 중 하나이며, 없을 수도 있다.</li>
</ul>

<h3>출력 형식</h3>

<p>3번의 기회에서 얻은 점수 합계에 해당하는 정수값을 출력한다.<br>
예) 37</p>

<h3>입출력 예제</h3>
<table class="table">
        <thead><tr>
<th>예제</th>
<th>dartResult</th>
<th>answer</th>
<th>설명</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td><code>1S2D*3T</code></td>
<td>37</td>
<td>1<sup>1</sup> * 2 + 2<sup>2</sup> * 2 + 3<sup>3</sup></td>
</tr>
<tr>
<td>2</td>
<td><code>1D2S#10S</code></td>
<td>9</td>
<td>1<sup>2</sup> + 2<sup>1</sup> * (-1) + 10<sup>1</sup></td>
</tr>
<tr>
<td>3</td>
<td><code>1D2S0T</code></td>
<td>3</td>
<td>1<sup>2</sup> + 2<sup>1</sup> + 0<sup>3</sup></td>
</tr>
<tr>
<td>4</td>
<td><code>1S*2T*3S</code></td>
<td>23</td>
<td>1<sup>1</sup> * 2 * 2 + 2<sup>3</sup> * 2 + 3<sup>1</sup></td>
</tr>
<tr>
<td>5</td>
<td><code>1D#2S*3S</code></td>
<td>5</td>
<td>1<sup>2</sup> * (-1) * 2 + 2<sup>1</sup> * 2 + 3<sup>1</sup></td>
</tr>
<tr>
<td>6</td>
<td><code>1T2D3D#</code></td>
<td>-4</td>
<td>1<sup>3</sup> + 2<sup>2</sup> + 3<sup>2</sup> * (-1)</td>
</tr>
<tr>
<td>7</td>
<td><code>1D2S3T*</code></td>
<td>59</td>
<td>1<sup>2</sup> + 2<sup>1</sup> * 2 + 3<sup>3</sup> * 2</td>
</tr>
</tbody>
      </table>
<p><a href="http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/" target="_blank" rel="noopener">해설 보러가기</a></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

처음에 dfs로 풀다가 도저히 안풀려서 코드를 참고하며 풀었다. 풀면서 깨달은 점은 최단거리 문제는 dfs보다 bfs가 더 좋다는 것이다.. 
코드를 참고하면서 백터의 크기 설정을 강제하여 메모리를 적게 쓸 수 있다는 점을 배웠다.   
아직 익숙치 않아 bfs,dfs 꼭 많이 풀어보기!
   

**풀이**   

숫자가 나올경우 다음 기회로 넘어가는형식으로 코드를 짰다.

### 나의 정답 풀이

```c++
#include <string>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    
    
    int answer = 0;
    map<int,int> ans;
    int chance =0;
    for(int i=0;i<dartResult.size();i++)
    {   
        //1~9
        if(dartResult[i]>47 && dartResult[i]<58)
        {
            // 10이 나올 경우
            if(dartResult[i-1]=='1'&&dartResult[i]=='0')     { ans[chance] = 10; continue; }
            chance++; 
            ans[chance] = dartResult[i]-'0';
        }
        else if(dartResult[i]=='D'){  ans[chance]=pow(ans[chance],2); }
        else if(dartResult[i]=='T') ans[chance]=pow(ans[chance],3);
        else if(dartResult[i]=='*') 
        {
            if(chance>1)
            {
                ans[chance]*=2;
                ans[chance-1]*=2;                            
            }
            else ans[chance]*=2;
        }
        else if(dartResult[i]=='#') ans[chance]*=-1;
    }
    
    for(auto n : ans) 
        answer+=n.second;
    
    return answer;
}

```   
