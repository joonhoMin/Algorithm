#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stack<char> stk;
    
    for(int i=0;i<s.length();i++)
    {
        int flag=1;
        
        while(!stk.empty())
            stk.pop();
        for(int j=0;j<s.length();j++)
        {
           if(s[j]=='('||s[j]=='{'||s[j]=='[')
               stk.push(s[j]);
           else if(s[j]==')'||s[j]=='}'||s[j]==']')
           {
               if(stk.empty())
               {
                   flag=0;
                   break;
               }
               else if(s[j]==')'&&stk.top()=='(')
                   stk.pop();
               else if(s[j]=='}'&&stk.top()=='{')
                   stk.pop();
               else if(s[j]==']'&&stk.top()=='[')
                   stk.pop();
               else
               {
                   flag=0;
                   break;
               }
           }
        }
        if(!stk.empty())
            flag=0;
        if(flag==1)
            answer+=1;
        char tmp=s[0];
        for(int j=0;j<s.length()-1;j++)
            s[j]=s[j+1];
        s[s.length()-1]=tmp;
    }
    
    return answer;
}