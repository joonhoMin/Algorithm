#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string,int> m;
    
    for(int i=0;i<clothes.size();i++)
    {
        m[clothes[i][1]]+=1;
    }
    
    for(auto i:m)
    {
        answer*=i.second+1;
    }
    
    answer-=1;
    
    return answer;
}