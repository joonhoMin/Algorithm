#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int tmp;
    
    for(int i=yellow;i>=1;i--)
    {
        if(yellow%i==0)
            tmp=yellow/i;
        else
            continue;
        if((i+2)*(tmp+2)==(brown+yellow))
        {
            answer.push_back(i+2);
            answer.push_back(tmp+2);
            break;
        }
    }
    
    return answer;
}