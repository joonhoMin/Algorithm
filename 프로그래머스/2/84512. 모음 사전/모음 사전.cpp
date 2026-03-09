#include <bits/stdc++.h>

using namespace std;

string S="AEIOU";
string target;
int answer = 0;
int cnt=0;
void dfs(string nowword)
{
    if(nowword.length()>5)
        return;
    if(nowword==target)
    {
        answer=cnt;
        return;
    }
    cnt+=1;
    for(int i=0;i<S.size();i++)
    {
        dfs(nowword+S[i]);
    }
    
    
}

int solution(string word) {
    target=word;
    
    dfs("");
    
    return answer;
}