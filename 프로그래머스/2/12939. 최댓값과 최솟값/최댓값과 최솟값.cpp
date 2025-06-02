#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    string tmp="";
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            v.push_back(stoi(tmp));
            tmp="";
        }
        else
            tmp+=s[i];
        
        if(i==s.length()-1)
            v.push_back(stoi(tmp));
    }
    
    int min=*min_element(v.begin(),v.end());
    int max=*max_element(v.begin(),v.end());
    
    answer=to_string(min)+" "+to_string(max);
    
    return answer;
}