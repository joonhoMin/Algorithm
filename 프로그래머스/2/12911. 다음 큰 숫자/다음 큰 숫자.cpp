#include <bits/stdc++.h>

using namespace std;

int binaryOneCount(int n)
{
    string binary;
    int count=0;
    
    while(n>0)
    {
        binary+=to_string(n%2);
        n/=2;
    }
    
    for(int i=0;i<binary.length();i++)
        if(binary[i]=='1')
            count+=1;
    
    return count;
    
}

int solution(int n) {
    int answer = 0;
    
    int count = binaryOneCount(n);
    
    while(1)
    {
        n=n+1;
        if(count==binaryOneCount(n))
            return n;
    }
    
    return answer;
}