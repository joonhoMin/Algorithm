#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i=0;i<priorities.size();i++)
    {
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    
    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        
        if(cur.first==pq.top())
        {
            pq.pop();
            
            if(cur.second==location)
                return answer;
            answer+=1;
        }
        else
        {
            q.push(cur);
        }
        
    }
}