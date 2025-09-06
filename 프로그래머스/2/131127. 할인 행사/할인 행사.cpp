#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0;i<=discount.size()-10;i++)
    {
        int flag=1;
        vector<int> temp=number;
        for(int j=i;j<i+10;j++)
        {
            if(find(want.begin(),want.end(),discount[j])==want.end())
            {
                flag=0;
                break;
            }
            else
            {
                int idx=find(want.begin(),want.end(),discount[j])-want.begin();
                if(temp[idx]==0)
                {
                    flag=0;
                    break;
                }
                else
                    temp[idx]-=1;
            }
        }
        if(flag==1)
            answer+=1;
    }
    return answer;
}