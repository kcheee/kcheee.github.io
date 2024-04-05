---
layout: post
title: programmers pccp 모의고사 1-1
categories : programmers pccp
tag : [programmers,map]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [PCCP 모의고사 #1] 1번 - 외톨이 알파벳

[문제 링크](https://school.programmers.co.kr/learn/courses/15008/lessons/121683)  



## 풀이

map<char,<vecot<int>> 을 사용하여 value 값에 char가 위치한 인덱스위치 정보를 저장하고, 그 위치가 1이상 차이난다 싶으면 answer에 푸시하는 방법으로 풀었다.


### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// map을 사용하여 map<string,vector<int>>
string solution(string input_string) {
    string answer = "";
    // 그 값과 값의 인덱스 값
    map<char,vector<int>> ans;
    
    for(int i=0;i<input_string.size();i++)
        ans[input_string[i]].push_back(i);
    
    for(auto it = ans.begin();it!=ans.end();it++)
    {
        int a=it->second[0];
       for(auto n : it->second) 
       {
           // 만약 거리가 다음값보다 1이상 차이난다 싶으면 answer 푸시
           if(n-a>1) {
               cout<< n <<" "<< a;
               answer+=it->first;
               break;
           }
           a=n;
       }      
    }
    if(answer=="") answer+="N";
    
    return answer;
}

```   
