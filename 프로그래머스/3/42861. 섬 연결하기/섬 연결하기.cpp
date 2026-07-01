#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// 현재 섬이 속한 그룹의 대표 찾기
int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

// 두 그룹 합치기
void unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b)
        parent[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int selected = 0;

    // 비용 기준 오름차순 정렬
    sort(costs.begin(), costs.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[2] < b[2];
         });

    // 처음에는 각 섬이 자기 자신만 있는 그룹
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (const auto& cost : costs) {
        int a = cost[0];
        int b = cost[1];
        int price = cost[2];

        // 이미 같은 그룹이면 연결하면 사이클 생김
        if (findParent(a) == findParent(b))
            continue;

        // 다른 그룹이면 다리 선택
        unite(a, b);
        answer += price;
        selected++;

        // 섬 n개를 연결하려면 다리는 n-1개면 충분
        if (selected == n - 1)
            break;
    }

    return answer;
}