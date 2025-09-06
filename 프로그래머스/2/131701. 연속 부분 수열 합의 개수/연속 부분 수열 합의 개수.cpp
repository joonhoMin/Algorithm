#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int oldsize=elements.size();
    for(int i=0;i<oldsize;i++)
        elements.push_back(elements[i]);
    set<int> s;

    for(int i=0;i<oldsize;i++)
    {
        for(int j=1;j<=oldsize;j++)
        {
            int sum=0;
            for(int k=i;k<i+j;k++)
                sum+=elements[k];
            s.insert(sum);
        }
    }
    
    answer=s.size();
    return answer;
}