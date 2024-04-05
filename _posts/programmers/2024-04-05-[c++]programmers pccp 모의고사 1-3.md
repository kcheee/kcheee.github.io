---
layout: post
title: programmers pccp 모의고사 1-3
categories : programmers pccp
tag : [programmers,재귀]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [PCCP 모의고사 #1] 1번 - 외톨이 알파벳

[문제 링크](https://school.programmers.co.kr/learn/courses/15008/lessons/121685)  



## 풀이


1. store[17]배열에 형질이 들어갈 수 있는 개수를 미리 저장한다.
2. 만약 3세대일때 형질의 개수는 16이다.
2-1. 16/4보다 작거나 같으면 RR, 16-16/4 값보다 크거나 같으면 rr 그 사이의 값은 %4를 하여 몫이 1일때 RR 2,3일때 Rr 0일때 rr로 하여 풀었다.

코드 실행했을때 테스트는 모두 정답이 나왔지만 채점해보니 1,3,5,7 번에서 실패가 나왔다. 반례를 찾으려고 gpt, 뤼튼에 물어봤으나 찾지못했다...
결국 구글에 다름사람의 코드를 참고하여 풀었다.ㅜ


### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    long long store[17];
    store[1] = 1;
    for(int i = 2; i < 17; i++) store[i] = store[i - 1] * 4;
    
    for(auto n : queries) {
        if(n[0] == 1) { // 1세대인 경우
            answer.push_back("Rr");
        } else if(n[0] == 2) { // 2세대인 경우
            if(n[1] % 4 == 1) answer.push_back("RR");
            else if(n[1] % 4 == 2 || n[1] % 4 == 3) answer.push_back("Rr");
            else if(n[1] % 4 == 0) answer.push_back("rr");
        } else { // 3세대 이상인 경우
            if(n[1] <= store[n[0]] / 4) answer.push_back("RR");
            else if(n[1] >= store[n[0]] - store[n[0]] / 4) answer.push_back("rr");
            else {
                if(n[1] % 4 == 1) answer.push_back("RR");
                else if(n[1] % 4 == 2 || n[1] % 4 == 3) answer.push_back("Rr");
                else if(n[1] % 4 == 0) answer.push_back("rr");
            }
        }
    }
    
    return answer;
}
```   

재귀를 사용하여 풀었다.

### 나의 정답풀이
```c++
#include <string>
#include <vector>

using namespace std;

string beans(int generation, int idx){
    if(generation == 1) return "Rr";	//종료 조건
    
    string parent_bean = beans(generation-1, (idx/4));	//부모의 형질을 알아낸다.
    
    //부모의 형질을 바탕으로 자신의 형질을 알아낸다.
    if(parent_bean == "RR") return "RR";
    else if (parent_bean == "rr") return "rr";
    else {
        int bean_sort = idx%4;
        if(bean_sort == 0) return "RR";
        if(bean_sort == 1 or bean_sort == 2) return "Rr";
        return "rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for(int i=0; i<queries.size(); i++){
        answer.push_back(beans(queries[i][0], queries[i][1]-1));
    }
    
    return answer;
}
```