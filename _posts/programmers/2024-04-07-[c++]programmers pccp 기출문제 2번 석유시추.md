---
layout: post
title: programmers pccp 기출문제 석유시추
categories : programmers pccp
tag : [programmers,dfs]
---

<style>
    table, th, td {
        color: white;
    }
</style>

# [level 2] [PCCP 기출문제] 2번 / 석유 시추 - 250136 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/250136) 

### 성능 요약

메모리: 14 MB, 시간: 2.75 ms

### 구분

코딩테스트 연습 > PCCP 기출문제

### 채점결과

정확성: 60.0<br/>효율성: 40.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 07일 15:06:14

### 문제 설명

<p><strong>[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]</strong></p>

<p>세로길이가 <code>n</code> 가로길이가 <code>m</code>인 격자 모양의 땅 속에서 석유가 발견되었습니다. 석유는 여러 덩어리로 나누어 묻혀있습니다. 당신이 시추관을 수직으로 <strong>단 하나만</strong> 뚫을 수 있을 때, 가장 많은 석유를 뽑을 수 있는 시추관의 위치를 찾으려고 합니다. 시추관은 열 하나를 관통하는 형태여야 하며, 열과 열 사이에 시추관을 뚫을 수 없습니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/beb862a9-5382-4f61-adae-bd6e9503c014/%E1%84%89%E1%85%A5%E1%86%A8%E1%84%8B%E1%85%B2%E1%84%89%E1%85%B5%E1%84%8E%E1%85%AE-1.drawio.png" title="" alt="석유시추-1.drawio.png"></p>

<p>예를 들어 가로가 8, 세로가 5인 격자 모양의 땅 속에 위 그림처럼 석유가 발견되었다고 가정하겠습니다. 상, 하, 좌, 우로 연결된 석유는 하나의 덩어리이며, 석유 덩어리의 크기는 덩어리에 포함된 칸의 수입니다. 그림에서 석유 덩어리의 크기는 왼쪽부터 8, 7, 2입니다. </p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0b10a9f6-6d98-44d6-a342-f984ea47315c/%E1%84%89%E1%85%A5%E1%86%A8%E1%84%8B%E1%85%B2%E1%84%89%E1%85%B5%E1%84%8E%E1%85%AE-2.drawio.png" title="" alt="석유시추-2.drawio.png"></p>

<p>시추관은 위 그림처럼 설치한 위치 아래로 끝까지 뻗어나갑니다. 만약 시추관이 석유 덩어리의 일부를 지나면 해당 덩어리에 속한 모든 석유를 뽑을 수 있습니다. 시추관이 뽑을 수 있는 석유량은 시추관이 지나는 석유 덩어리들의 크기를 모두 합한 값입니다. 시추관을 설치한 위치에 따라 뽑을 수 있는 석유량은 다음과 같습니다.</p>
<table class="table">
        <thead><tr>
<th>시추관의 위치</th>
<th>획득한 덩어리</th>
<th>총 석유량</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>[8]</td>
<td>8</td>
</tr>
<tr>
<td>2</td>
<td>[8]</td>
<td>8</td>
</tr>
<tr>
<td>3</td>
<td>[8]</td>
<td>8</td>
</tr>
<tr>
<td>4</td>
<td>[7]</td>
<td>7</td>
</tr>
<tr>
<td>5</td>
<td>[7]</td>
<td>7</td>
</tr>
<tr>
<td>6</td>
<td>[7]</td>
<td>7</td>
</tr>
<tr>
<td>7</td>
<td>[7, 2]</td>
<td>9</td>
</tr>
<tr>
<td>8</td>
<td>[2]</td>
<td>2</td>
</tr>
</tbody>
      </table>
<p>오른쪽 그림처럼 7번 열에 시추관을 설치하면 크기가 7, 2인 덩어리의 석유를 얻어 뽑을 수 있는 석유량이 9로 가장 많습니다.</p>

<p>석유가 묻힌 땅과 석유 덩어리를 나타내는 2차원 정수 배열 <code>land</code>가 매개변수로 주어집니다. 이때 시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량을 return 하도록 solution 함수를 완성해 주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>land</code>의 길이 = 땅의 세로길이 = <code>n</code> ≤ 500

<ul>
<li>1 ≤ <code>land[i]</code>의 길이 = 땅의 가로길이 = <code>m</code> ≤ 500</li>
<li><code>land[i][j]</code>는 <code>i+1</code>행 <code>j+1</code>열 땅의 정보를 나타냅니다.</li>
<li><code>land[i][j]</code>는 0 또는 1입니다.</li>
<li><code>land[i][j]</code>가 0이면 빈 땅을, 1이면 석유가 있는 땅을 의미합니다.</li>
</ul></li>
</ul>

<h6>정확성 테스트 케이스 제한사항</h6>

<ul>
<li>1 ≤ <code>land</code>의 길이 = 땅의 세로길이 = <code>n</code> ≤ 100

<ul>
<li>1 ≤ <code>land[i]</code>의 길이 = 땅의 가로길이 = <code>m</code> ≤ 100</li>
</ul></li>
</ul>

<h6>효율성 테스트 케이스 제한사항</h6>

<ul>
<li>주어진 조건 외 추가 제한사항 없습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>land</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[[0, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1, 0, 0], [1, 1, 0, 0, 0, 1, 1, 0], [1, 1, 1, 0, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0, 1, 1]]</td>
<td>9</td>
</tr>
<tr>
<td>[[1, 0, 1, 0, 1, 1], [1, 0, 1, 0, 0, 0], [1, 0, 1, 0, 0, 1], [1, 0, 0, 1, 0, 0], [1, 0, 0, 1, 0, 1], [1, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]]</td>
<td>16</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제의 예시와 같습니다.</p>

<p><strong>입출력 예 #2</strong></p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/5e619c77-c940-46e6-9520-e5769e49194c/%E1%84%89%E1%85%A5%E1%86%A8%E1%84%8B%E1%85%B2%E1%84%89%E1%85%B5%E1%84%8E%E1%85%AE-3.drawio.png" title="" alt="석유시추-3.drawio.png"></p>

<p>시추관을 설치한 위치에 따라 뽑을 수 있는 석유는 다음과 같습니다.</p>
<table class="table">
        <thead><tr>
<th>시추관의 위치</th>
<th>획득한 덩어리</th>
<th>총 석유량</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td data-sider-select-id="280ebadc-be4d-4a6d-b1ed-676795926d77">[12]</td>
<td>12</td>
</tr>
<tr>
<td>2</td>
<td>[12]</td>
<td>12</td>
</tr>
<tr>
<td>3</td>
<td>[3, 12]</td>
<td>15</td>
</tr>
<tr>
<td>4</td>
<td>[2, 12]</td>
<td>14</td>
</tr>
<tr>
<td>5</td>
<td>[2, 12]</td>
<td>14</td>
</tr>
<tr>
<td>6</td>
<td>[2, 1, 1, 12]</td>
<td>16</td>
</tr>
</tbody>
      </table>
<p>6번 열에 시추관을 설치하면 크기가 2, 1, 1, 12인 덩어리의 석유를 얻어 뽑을 수 있는 석유량이 16으로 가장 많습니다. 따라서 <code>16</code>을 return 해야 합니다.</p>

<hr>

<p><strong>제한시간 안내</strong></p>

<ul>
<li>정확성 테스트 : 10초</li>
<li>효율성 테스트 : 언어별로 작성된 정답 코드의 실행 시간의 적정 배수</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이

소요시간 2시간 이상   


첫번째 풀이방법으로는 dfs를 사용하여 1이 나오면 주위에 있는 모든 1값을 더하는 방식으로 풀었다. 하지만 정확성테스트에서는 모두 맞았지만 효율성 테스트에서는 모두 실패(시간초과)라고 나왔다.   

왜 시간초과가 나왔을까 생각을 해보니 land의 가로의 길이만큼 dfs를 실행하므로 실행시간이 길 거 같다고 파악했다.
그러므로, dfs는 처음 한번만 실행을 하여 land의 크기만큼 배열을 선언하고 그 배열안에 석유덩어리값을 저장하는 방식으로 접근해보았다.

### 나의 틀린 풀이

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> Land;
int m=0;
int ans=0;
int dfs2(int x,int y, vector<vector<bool>>& visited,int _m)
{ 
    if(0<x)
    {
        if(Land[y][x-1]==1 && visited[y][x-1]==false) { visited[y][x-1]=true; dfs2(x-1,y,visited,++m); }
    }
    if(x<Land[0].size()-1)
    {
        if(Land[y][x+1]==1 && visited[y][x+1]==false) { visited[y][x+1]=true; dfs2(x+1,y,visited,++m); }
    }
    if(0<y)
    {
        if(Land[y-1][x]==1 && visited[y-1][x]==false) { visited[y-1][x]=true; dfs2(x,y-1,visited,++m); }
    }
    if(y<Land.size()-1)
    {
        if(Land[y+1][x]==1 && visited[y+1][x]==false) { visited[y+1][x]=true; dfs2(x,y+1,visited,++m); }
    }
     
    return m;
}

int dfs(int x,int y,vector<vector<bool>> visited)
{
    if(Land[y][x]==1 && visited[y][x]==false) { m=0; visited[y][x]=true; ans+=dfs2(x,y,visited,++m); };
    
    if(y<Land.size()-1)  { dfs(x,y+1,visited);}
   
    return ans;
}

int solution(vector<vector<int>> land) {
    vector<vector<bool>> flag(land.size(),vector<bool>(land[0].size(),false));
    vector<vector<int>> land_size;
    Land=land;
    int answer=0;
    for(int i=0;i<land[0].size();i++)
    {
        int c = dfs(i,0,flag);
        if(answer<c) answer =c;
        ans=0;
    }
 
    return answer;
}
```   

dfs로 한번만 석유 덩어리와, path로 석유덩어리의 위치 정보를 계산하여 저장하고,
set을 사용하여 가로 크기만큼 할당한 landSize에 path.size()만큼 저장해주는 방법으로 풀어보았다.

### 나의 정답 풀이

```c++
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;


void dfs(int x,int y, vector<vector<int>>& Land,vector<vector<bool>>& visited,
        vector<pair<int,int>>& path)
{    
    // 현재 위치 저장
    path.push_back({y,x});
        if(0<x&&Land[y][x-1]==1 && visited[y][x-1]==false) 
        {             
            visited[y][x-1]=true; dfs(x-1,y,Land,visited,path);
        }

        if(x<Land[0].size()-1&&Land[y][x+1]==1 && visited[y][x+1]==false) 
        {           
            visited[y][x+1]=true; dfs(x+1,y,Land,visited,path); 
        }
    

        if(0<y&&Land[y-1][x]==1 && visited[y-1][x]==false)
        {                      
            visited[y-1][x]=true; dfs(x,y-1,Land,visited,path); 
        }
    
        if(y<Land.size()-1&&Land[y+1][x]==1 && visited[y+1][x]==false)
        {                                
            visited[y+1][x]=true; dfs(x,y+1,Land,visited,path); 
        }     
}

int solution(vector<vector<int>> land) {
    int answer=0;
    vector<vector<bool>> flag(land.size(),vector<bool>(land[0].size(),false));
    vector<pair<int,int>> path;
    vector<int> landSize(land[0].size(),0);
    
    for(int y=0;y<land.size();y++)
    {
        for(int x=0;x<land[0].size();x++)
        {
            if(land[y][x]!=0&&flag[y][x]==false){
                flag[y][x]=true;                 
                dfs(x,y,land ,flag,path);
                int size= path.size();
                // 여기서 석유덩어리를 판별해야함.
                set<int> t;
                while(!path.empty())
                {
                    t.insert(path.back().second);
                    land[path.back().first][path.back().second] = size;
                    path.pop_back();
                }

                for(auto it = t.begin();it!=t.end();it++)
                    landSize[*it] +=size;                
            }
        }
    }
   
    
    for(auto n : landSize) if(answer<n) answer=n;
    
   
    return answer;
}

```