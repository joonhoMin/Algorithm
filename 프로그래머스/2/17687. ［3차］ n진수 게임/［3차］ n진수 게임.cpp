#include <bits/stdc++.h>

using namespace std;

string List="0123456789ABCDEF";
    
string Invert(int Num, int n)
{
    string tmp="";
    if(Num==0)
        return "0";
    while (Num != 0)
    {
        tmp +=  List[Num % n];
        Num /= n;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string Result = "";
    int i=0;
    while(Result.length()<t*m)
    {
        Result += Invert(i++, n);
    }
    
    for(int i=0;i<t;i++)
    {
        answer+=Result[p-1];
        p+=m;
    }
    
    return answer;
}