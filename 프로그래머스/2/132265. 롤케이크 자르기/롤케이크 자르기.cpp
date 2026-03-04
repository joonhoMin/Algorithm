#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {

    int answer = 0;  // 공평하게 자르는 경우의 수

    // 오른쪽 케이크의 토핑 개수
    vector<int> right(10001, 0);

    // 왼쪽 케이크의 토핑 개수
    vector<int> left(10001, 0);

    int leftKind = 0;   // 왼쪽 케이크의 토핑 종류 수
    int rightKind = 0;  // 오른쪽 케이크의 토핑 종류 수


    // -----------------------------
    // 처음에는 모든 토핑이 오른쪽 케이크에 있음
    // -----------------------------
    for(int t : topping)
    {
        if(right[t] == 0)   // 처음 등장한 토핑이면
            rightKind++;    // 종류 증가

        right[t]++;         // 해당 토핑 개수 증가
    }


    // -----------------------------
    // 토핑을 하나씩 왼쪽으로 이동
    // -----------------------------
    for(int t : topping)
    {
        // 왼쪽 케이크에 추가
        if(left[t] == 0)    // 처음 등장한 토핑이면
            leftKind++;     // 종류 증가

        left[t]++;          // 토핑 개수 증가


        // 오른쪽 케이크에서 제거
        right[t]--;

        if(right[t] == 0)   // 더 이상 없으면
            rightKind--;    // 종류 감소


        // 두 케이크의 토핑 종류 수 비교
        if(leftKind == rightKind)
            answer++;
    }

    
    return answer;
}