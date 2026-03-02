#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> s;

    vector<int> v = elements;
    v.insert(v.end(), elements.begin(), elements.end());

    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int len = 1; len <= n; len++) {
            sum += v[start + len - 1];
            s.insert(sum);
        }
    }

    return s.size();
}