#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;

    // 가장 느린 심사관 혼자 n명을 처리하는 최악 시간
    long long right = 1LL * (*max_element(times.begin(), times.end())) * n;

    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long people = 0;

        // mid분 동안 각 심사관이 몇 명 처리 가능한지 합침
        for (int time : times) {
            people += mid / time;

            // n명 이상이면 더 셀 필요 없음
            if (people >= n)
                break;
        }

        if (people >= n) {
            // mid분이면 가능
            answer = mid;
            right = mid - 1;
        } else {
            // mid분으로는 부족
            left = mid + 1;
        }
    }

    return answer;
}