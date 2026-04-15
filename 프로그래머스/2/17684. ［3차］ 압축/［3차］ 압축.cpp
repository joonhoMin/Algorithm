#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string,int> m;
    
    for(int i=1;i<=26;i++)
    {
        string s="";
        s+='A'+i-1;
        m[s]=i;
    }
    
    int nextidx=27;
    
    for(int i=0;i<msg.length();i++)
    {
        string w="";
        w+=msg[i];
        
        int lastidx=m[w];
        
        for(int j=i+1;j<msg.length();j++)
        {
            string next=w+msg[j];
            
            if(m.find(next)!=m.end())
            {
                w=next;
                lastidx=m[w];
                i++;
            }
            else
                break;
        }
        
        answer.push_back(lastidx);
        
        if(i+1<=msg.length()-1)
            m[w+msg[i+1]]=nextidx++;
    }
    
    return answer;
}