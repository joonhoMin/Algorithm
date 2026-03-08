#include <bits/stdc++.h>

using namespace std;

int binaryOneCount(int n)
{
    int count=0;
    
    while(n>0)
    {
        if(n%2==1)
            count+=1;
        n/=2;
    }
    
    return count;
    
}

int solution(int n) {
    
    int count = binaryOneCount(n);
    
    while(1)
    {
        n=n+1;
        if(count==binaryOneCount(n))
            break;
    }
    
    return n;
}