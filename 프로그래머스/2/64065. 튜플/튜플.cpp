#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp="";
    int number;
    unordered_map<int,int> m;
    for(int i=0;i<s.length();i++)
    {
        if(isdigit(s[i])!=0)
        {
            tmp+=s[i];
        }
        else
        {
            if(tmp.length()!=0)
            {
                number=stoi(tmp);
                m[number]+=1;
                tmp="";
            }
        }
        
    }

    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        answer.push_back(v[i].first);
    }
    
    return answer;
}