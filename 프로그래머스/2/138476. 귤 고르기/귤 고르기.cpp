#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int,int> m;
    
    for(int i=0;i<tangerine.size();i++)
    {
        m[tangerine[i]]+=1;
    }
    
    vector<int> v;
    
    for(auto i: m)
    {
        v.push_back(i.second);
    }
    
    sort(v.begin(),v.end(),greater<>());
    
    int i=0;
    
    while(1)
    {
        answer+=1;
        k-=v[i++];
        if(k<=0)
            break;
    }
    
    
    return answer;
}