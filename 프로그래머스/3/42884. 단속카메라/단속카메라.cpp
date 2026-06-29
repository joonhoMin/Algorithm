#include <bits/stdc++.h> 

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
         });

    int answer = 1;
    int camera = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (camera < routes[i][0]) {
            answer++;
            camera = routes[i][1];
        }
    }

    return answer;
}