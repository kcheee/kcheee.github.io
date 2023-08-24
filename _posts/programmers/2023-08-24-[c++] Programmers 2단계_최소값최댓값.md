---
layout: post
title: programmers 2단계 최댓값 최소값
categories : programmers
tag : [programmers,sort,2단계]
---


# [level 2] 최댓값과 최솟값 - 12939 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12939) 

### 성능 요약

메모리: 3.59 MB, 시간: 0.10 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

Empty

### 문제 설명

<p>문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.<br>
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.</p>

<h5>제한 조건</h5>

<ul>
<li>s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>s</th>
<th style="text-align: center">return</th>
</tr>
</thead>
        <tbody><tr>
<td>"1 2 3 4"</td>
<td style="text-align: center">"1 4"</td>
</tr>
<tr>
<td>"-1 -2 -3 -4"</td>
<td style="text-align: center">"-4 -1"</td>
</tr>
<tr>
<td>"-1 -1"</td>
<td style="text-align: center">"-1 -1"</td>
</tr>
</tbody>
      </table>


```c++
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// 1. 공백으로 구분 split 하기
// 2. 배열이나 list에 넣기.
// 3. sort 하기.

// 음수 조건문 붙여주기.
bool compare(string a, string b) {
  //이름이 같으면, 나이가 적은순
        return stoi(a) < stoi(b);
}

string solution(string s) {

    string result;
    stringstream stream(s);

    // 공백 분리 결과를 저장할 배열
    vector<string> words;

    string word;
    // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
    while (getline(stream, word, ' ')) {
        words.push_back(word);
    }
    
    sort(words.begin(), words.end(),compare);

    cout << words.front() << words.back();

    result = words.front() + " " + words.back();
    return result;
}
```

> 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges