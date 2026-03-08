#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    
    unordered_map<int,int> cnt;
    
    // 1. 귤 크기별 개수
    for(int t : tangerine)
        cnt[t]++;
    
    int n = tangerine.size();
    
    // 2. 버킷
    vector<int> bucket(n+1,0);
    
    for(auto &p : cnt)
        bucket[p.second]++;
    
    int answer = 0;
    
    // 3. 큰 개수부터 greedy
    for(int i=n;i>=1;i--)
    {
        while(bucket[i] > 0 && k > 0)
        {
            k -= i;
            bucket[i]--;
            answer++;
        }
        
        if(k <= 0)
            break;
    }
    
    return answer;
}