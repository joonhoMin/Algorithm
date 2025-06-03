#include <bits/stdc++.h>

using namespace std;

string tobinary(int n)
{
    string s="";
    
    while(n>0)
    {
        s+=to_string(n%2);
        n/=2;
    }
    
    reverse(s.begin(),s.end());
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int level=0;
    int cnt=0;
    int tmpcnt;
    
    while(s!="1")
    {
        level+=1;
        tmpcnt=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='1')
                tmpcnt+=1;
        cnt+=s.length()-tmpcnt;
        s=tobinary(tmpcnt);
    }
    
    answer.push_back(level);
    answer.push_back(cnt);
    return answer;
}