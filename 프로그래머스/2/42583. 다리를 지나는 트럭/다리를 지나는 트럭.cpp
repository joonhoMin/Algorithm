#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q; //원소 bridge_length 만큼 할당가능, 합이 weight 이하여야함
    int nowweight=0; //다리 위 무게
    int idx=0; // 다음에 나갈 차량 인덱스
    
    for(int i=0;i<bridge_length;i++)
        q.push(0);
    
    while(1)
    {
        answer+=1;
        nowweight-=q.front();
        q.pop();
        
        if(nowweight+truck_weights[idx]<=weight)
        {
            nowweight+=truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        else
        {
            q.push(0);
        }
        
        if(idx==truck_weights.size())
        {
            answer+=bridge_length;
            break;
        }
    }
    
    return answer;
}