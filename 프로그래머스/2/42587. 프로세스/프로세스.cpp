#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(1)
    {
        int piv=priorities[0];
        int flag=0;
        for(int i=1;i<priorities.size();i++)
        {
            if(priorities[i]>piv)
            {
                priorities.erase(priorities.begin());
                location-=1;
                priorities.push_back(piv);
                if(location==-1)
                    location=priorities.size()-1;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            priorities.erase(priorities.begin());
            answer+=1;
            location-=1;
            if(location==-1)
                    return answer;
        }
    }
}