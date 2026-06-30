#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey)
    {
        int a=storey%10;
        int b=storey/10%10;
        if(a>5)
        {
            answer+=10-a;
            storey+=10-a;
        }
        else if(a==5)
        {
            answer+=5;
            storey+=b>=5?10:0;
        }
        else
        {
            answer+=a;
        }
        storey/=10;
    }
    
    return answer;
}