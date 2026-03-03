#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),greater<>());
    //6 5 3 1 0
    //0 1 2 3 4
    
    //6 6 6 6 6
    //0 1 2 3 4
    
    int i;
    for(i=0;i<citations.size();i++)
    {
        if(citations[i]<i+1)
            return i;
    }
    return i;
}