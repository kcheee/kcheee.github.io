---
layout: post
title: programmers 2단계 tuple
categories : programmers 2단계
tag : [programmers,set,sstream]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] 튜플 - 64065 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/64065) 


## 풀이

1. 처음과 끝에 있는 중괄호 삭제.     
2. 중괄호에 있는 값들 ans에 push후 정렬.    
3. , 를 기준으로 숫자를 int형으로 분리하고 set STL을 사용해 중복 방지 후 answer에 push   

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

bool compare(string a,string b){  return a.size()<b.size();  }

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> ans;
    string str;
    bool flag=false;
    // 처음과 끝에 있는 중괄호 삭제
    s.erase(s.begin());    s.pop_back();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='}') 
        {
            flag =false;
            ans.push_back(str);
            str.clear();
        }
        if(flag)
        {
            str+=s[i];
        }
        if(s[i]=='{') flag = true;
    }  
    sort(ans.begin(),ans.end(),compare);
    
    set<int> result;
    for(int i=0;i<ans.size();i++)
    {
        stringstream ss(ans[i]);
        string num;
        while (getline(ss, num, ',')) {
            // 분리된 숫자 출력
          int number = stoi(num);
          if(result.insert(number).second) answer.push_back(number);
        }
    }

    
    return answer;
}
```   

### 다른사람 풀이

원소들의 인덱스 값을 저장하고 그 값을 정렬하여 풀었다.   

```c++ 
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int st[101010]={};
    vector<int> answer;
    string tmp;
    for(char i: s){
        if(i-'0' >=0 && i-'0' <=9){
            tmp += i;
        }
        else{
            if(tmp.length())
                st[stoi(tmp)]++, tmp.clear();
        }
    }
    vector<pair<int, int>> v;
    for(int i =0; i <101010; i++)
        if(st[i])
            v.push_back({st[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(auto it: v) answer.push_back(it.second);
    return answer;
}
```
