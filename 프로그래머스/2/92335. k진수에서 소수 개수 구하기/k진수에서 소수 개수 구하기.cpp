#include <bits/stdc++.h>

using namespace std;

string s="0123456789";

bool isprime(long long n)
{
    if(n==1)
        return false;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string tmp1="";
    while(n>0)
    {
        tmp1+=to_string(n%k);
        n/=k;
    }
    
    reverse(tmp1.begin(),tmp1.end());

    string tmp2="";
    for(int i=0;i<tmp1.length();i++)
    {
        if(tmp1[i]=='0')
        {
            if(tmp2.length()!=0&&isprime(stoll(tmp2)))
            {
                answer+=1;
            }
            tmp2="";
        }
        else
            tmp2+=tmp1[i];
    }
    
    
    if(tmp2.length()!=0&&isprime(stoll(tmp2)))
        answer+=1;
    
    return answer;
}