#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {

    // 실제 프로세스 순서를 관리할 queue
    // pair<priority, original index>
    queue<pair<int,int>> q;

    // 현재 큐에 있는 priority 중 가장 큰 값을 빠르게 찾기 위한 heap
    priority_queue<int> pq;

    // 큐와 힙 초기화
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i}); // (우선순위, 원래 위치)
        pq.push(priorities[i]);     // 우선순위만 저장
    }

    int answer = 0; // 몇 번째 실행인지

    while(!q.empty())
    {
        // 현재 큐 맨 앞 프로세스
        auto cur = q.front();
        q.pop();

        // 현재 프로세스가 가장 높은 priority라면 실행
        if(cur.first == pq.top())
        {
            pq.pop();   // heap에서도 제거
            answer++;   // 실행 순서 증가

            // 우리가 찾는 프로세스라면 종료
            if(cur.second == location)
                return answer;
        }
        else
        {
            // 더 높은 priority가 있으므로 다시 뒤로 보냄
            q.push(cur);
        }
    }
    
    return answer;
}