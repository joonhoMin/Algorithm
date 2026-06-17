#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n=prices.size();
    vector<int> answer(n,0);
    
    stack<int> st;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&prices[st.top()]>=prices[i])
            st.pop();
        if(st.empty())
            answer[i]=n-i-1;
        else
            answer[i]=st.top()-i;
        
        st.push(i);
    }
    
    return answer;
}