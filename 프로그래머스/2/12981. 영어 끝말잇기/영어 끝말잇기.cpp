#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> newwords;
    newwords.push_back(words[0]);
    int round=1,turn=2;
    for(int i=1;i<words.size();i++)
    {
        if(find(newwords.begin(),newwords.end(),words[i])!=newwords.end()||words[i-1][words[i-1].length()-1]!=words[i][0])
        {
            answer.push_back(turn);
            answer.push_back(round);
            break;
        }
        else
        {
            newwords.push_back(words[i]);
            if(turn+1>n)
            {
                turn=1;
                round+=1;
            }
            else
                turn+=1;
        }
        
    }
    
    if(answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}