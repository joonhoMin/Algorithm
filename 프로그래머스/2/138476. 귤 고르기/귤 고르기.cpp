#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 1;
    
    vector<int> v(10000001);
    for(int i=0;i<tangerine.size();i++)
    {
        v[tangerine[i]]+=1;
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<v.size();i++)
    {
        k-=v[i];
        if(k<=0)
            break;
        answer+=1;
    }
    return answer;
}