#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    vector<int> v;
    
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i][0]=='I')
        {
            string s="";
            for(int j=2;j<operations[i].size();j++)
                s+=operations[i][j];
            v.push_back(stoi(s));
            sort(v.begin(),v.end());
        }
        else if(operations[i][0]=='D')
        {
            if(v.empty())
                continue;
            if(operations[i][2]=='-')
                v.erase(v.begin());
            else
                v.pop_back();
        } 
    }
    
    if(v.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(v.back());
        answer.push_back(v.front());
    }
    
    return answer;
}