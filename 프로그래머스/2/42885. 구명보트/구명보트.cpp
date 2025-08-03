#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end());
    
    int start=0, end=people.size()-1;
    
    while(end>=start)
    {
        if(start==end)
        {
            answer+=1;
            break;
        }
        
        if(people[start]+people[end]<=limit)
        {
            start+=1;
            end-=1;
            answer+=1;
        }
        else
        {
            end-=1;
            answer+=1;
        }
        
    }
    
    return answer;
}