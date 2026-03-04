#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> right(10001,0);
    vector<int> left(10001,0);

    int leftKind = 0;
    int rightKind = 0;

    for(int t : topping)
    {
        if(right[t]==0) rightKind++;
        right[t]++;
    }

    for(int i=0;i<topping.size();i++)
    {
        int t = topping[i];

        if(left[t]==0) leftKind++;
        left[t]++;

        right[t]--;
        if(right[t]==0) rightKind--;

        if(leftKind==rightKind)
            answer++;
    }

    return answer;
}