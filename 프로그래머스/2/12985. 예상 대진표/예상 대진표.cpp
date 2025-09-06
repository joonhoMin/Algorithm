#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    if(a>b)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    
    while(1)
    {
        if(a%2==1&&a+1==b)
            break;
        a=(a+1)/2;
        b=(b+1)/2;
        answer+=1;
    }

    return answer;
}