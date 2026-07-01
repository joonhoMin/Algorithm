#include <bits/stdc++.h>

using namespace std;

string S="AEIOU";
string target;
int answer = 0;
int cnt=-1;
void dfs(string nowword)
{
    cnt+=1;
    if(nowword==target)
    {
        answer=cnt;
        return;
    }
    for(int i=0;i<S.size();i++)
    {
        if(nowword.length()+1>5)
            return;
        dfs(nowword+S[i]);
    }
    
    
}

int solution(string word) {
    target=word;
    
    dfs("");
    
    return answer;
}