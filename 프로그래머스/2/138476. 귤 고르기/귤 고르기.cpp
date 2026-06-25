#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> m;
    for (int x : tangerine) {
        m[x]++;
    }

    map<int, int, greater<int>> m2;
    for (auto [size, cnt] : m) {
        m2[cnt]++;
    }

    for (auto [cnt, kind] : m2) {
        while (kind > 0) {
            k -= cnt;
            answer++;
            kind--;

            if (k <= 0) return answer;
        }
    }

    return answer;
}