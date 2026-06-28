#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> remain;
    
    for(int i=0;i<progresses.size();i++)
    {
        remain.push_back(ceil((double)(100-progresses[i])/speeds[i]));
    }
    //7 3 9
    
    int piv=0;
    for(int i=1;i<remain.size();i++)
    {
        if(remain[i]>remain[piv])
        {
            answer.push_back(i-piv);
            piv=i;
        }

    }
    
    answer.push_back(remain.size()-piv);
    
    return answer;
}