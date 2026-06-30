#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> nodes[50];
int dist[50];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first; // 우선순위큐는 내림차순 정렬이기 때문
        int here = pq.top().second;
        pq.pop();

        // 이미 최단거리 정보 있으면 pass
        //if (dist[here] < cost) continue;

        for (int i = 0; i < nodes[here].size(); i++) {
            int via_cost = cost + nodes[here][i].second;
            int via_place= nodes[here][i].first;
            // here을 경유해서 가는게 빠르면 dist 갱신 후 push
            if (via_cost < dist[via_place]) {
                dist[via_place] = via_cost;
                pq.push({via_cost,via_place});
                // 내림차순 정렬이라서 최소값이 가장 앞에 오도록 하기 위해 음수로 변환
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (int i = 0; i < 50; i++)
        dist[i] = 1e9;

    for(int i=0;i<road.size();i++)
    {
        nodes[road[i][0]-1].push_back({road[i][1]-1,road[i][2]});
        nodes[road[i][1]-1].push_back({road[i][0]-1,road[i][2]});
    }
    

    dijkstra(0);

    for (int i = 0; i < 50; i++)
        if(dist[i]<=K)
        {
            answer+=1;
        }
    
    return answer;
}