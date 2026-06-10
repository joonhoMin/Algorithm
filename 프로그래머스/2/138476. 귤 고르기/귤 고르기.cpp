#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int,int> m;
    
    for(int i:tangerine)
        m[i]++;
    /*
    m[1]=1
    m[2]=2
    m[3]=2
    m[4]=1
    m[5]=2
    크기가 1인 귤 1개, ... 크키가 5인 귤 2개
    */
    
    int n=tangerine.size();
    
    vector<int> v(n+1);
    
    for(auto i:m)
        v[i.second]++;
    /*
    크기는 상관없이 갯수가 많은거 순서대로 넣어야 하니
    v[2]=3
    v[1]=2
    2개의 같은 크기를 가진 귤이 3종류, 1개의 같은 크기를 가진 귤이     2종류
    */
    
    //가장 갯수가 많은 크기의 귤부터 빼야 하니 역순으로
    for(int i=n;i>=1;i--)
    {
        //한 종류씩 담으면서 k에서 빼줌
        while(v[i]>0)
        {
            k-=i;
            v[i]-=1;
            answer+=1;
            if(k<=0)
            return answer;
        }
    }
}