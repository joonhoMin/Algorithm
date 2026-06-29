#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    int a,b;
    while(pq.top()<K&&pq.size()>1)
    {
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        pq.push(a+b*2);
        answer+=1;
    }
    
    if(pq.top()<K)
        return -1;
    
    return answer;
}