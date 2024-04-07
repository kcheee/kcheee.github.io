---
layout: post
title: programmers 오픈채팅방
categories : programmers 2단계
tag : [programmers,dfs]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 오픈채팅방 - 42888 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42888) 

### 성능 요약

메모리: 35.6 MB, 시간: 180.37 ms

### 구분

코딩테스트 연습 > 2019 KAKAO BLIND RECRUITMENT

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 07일 19:55:13

### 문제 설명

<h2 data-sider-select-id="91ece322-c903-4e06-b12b-26f8434b5c2e">오픈채팅방</h2>

<p>카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.</p>

<p data-sider-select-id="7c80b6f2-580b-4c98-8e2d-adb8660d7067">신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 채팅방에 누군가 들어오면 다음 메시지가 출력된다.</p>

<p>"[닉네임]님이 들어왔습니다."</p>

<p>채팅방에서 누군가 나가면 다음 메시지가 출력된다.</p>

<p>"[닉네임]님이 나갔습니다."</p>

<p data-sider-select-id="15973fdd-28ba-4553-a7cb-1c0166d17dbd">채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.</p>

<ul>
<li data-sider-select-id="87139d4d-0ab4-4b07-b6d3-99342cc8ce8c">채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.</li>
<li>채팅방에서 닉네임을 변경한다.</li>
</ul>

<p>닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다. </p>

<p>예를 들어, 채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.</p>

<p>"Muzi님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.</p>

<p>"Muzi님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."<br>
"Muzi님이 나갔습니다."</p>

<p>Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.</p>

<p>"Prodo님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."<br>
"Prodo님이 나갔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.</p>

<p>"Prodo님이 들어왔습니다."<br>
"Ryan님이 들어왔습니다."<br>
"Prodo님이 나갔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.</p>

<h5>제한사항</h5>

<ul>
<li>record는 다음과 같은 문자열이 담긴 배열이며, 길이는 <code>1</code> 이상 <code>100,000</code> 이하이다.</li>
<li>다음은 record에 담긴 문자열에 대한 설명이다.

<ul>
<li>모든 유저는 [유저 아이디]로 구분한다.</li>
<li data-sider-select-id="f8cd9238-2a4d-483f-aa1f-8c48507819b4">[유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")</li>
<li>[유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")</li>
<li>[유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")</li>
<li>첫 단어는 Enter, Leave, Change 중 하나이다.</li>
<li>각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.</li>
<li>유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.</li>
<li>유저 아이디와 닉네임의 길이는 <code>1</code> 이상 <code>10</code> 이하이다.</li>
<li>채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.</li>
</ul></li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>record</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td><code data-sider-select-id="879d9511-68be-4885-a5f0-44bf412252d0">["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]</code></td>
<td><code>["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]</code></td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
문제의 설명과 같다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 30분

1. map을 사용하여 key에는 uid, value는 닉네임을 저장하여 Enter나 Change일때 이름을 갱신한다.   
2. Enter나 Leave일때는 queue에 (Enter일때 1, Leave일 때 0)을 쌓는다.   
3. user와 ans.first값을 사용하여 uid를 비교하고 answer에 푸시

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

// 07:30 ~ 07:57

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,int>> ans;
    map<string,string> user;

    for (auto n : record) {
        string x, y, z;
        stringstream s(n);
        s >> x >> y >> z;
        if (x == "Change" || x == "Enter") {
            user[y] = z; // 사용자 이름을 갱신
        }
    }

    // "Enter" 또는 "Leave" 기록을 처리
    for (auto n : record) {
        string x, y, z;
        stringstream s(n);
        s >> x >> y >> z;
        if (x == "Enter") {
            ans.push({y, 1});
        } else if (x == "Leave") {
            ans.push({y, 0});
        }
    }

    
    while (!ans.empty()) {
        if (ans.front().second == 1) {
            answer.push_back(user[ans.front().first] + "님이 들어왔습니다.");
        } else if (ans.front().second == 0) {
            answer.push_back(user[ans.front().first] + "님이 나갔습니다.");
        }
        ans.pop();
    }

    return answer;
}

```   
