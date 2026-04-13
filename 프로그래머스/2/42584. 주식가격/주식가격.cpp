#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    
    vector<int> answer(n,0);
    
    
    stack<int> s;
    
    for(int i=prices.size()-1;i>=0;i--)
    {
        while(!s.empty() && prices[s.top()] >= prices[i])
            s.pop();
        
        if(!s.empty())
            answer[i]=s.top()-i;
        else
            answer[i]=n-1-i;
        
        s.push(i);
    }
    
    return answer;
}