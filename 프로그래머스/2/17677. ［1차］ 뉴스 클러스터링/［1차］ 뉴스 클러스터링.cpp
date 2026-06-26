#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> v1;
    vector<string> v2;
    
    string tmp="";
    
    for(int i=0;i<str1.size()-1;i++)
    {
        tmp="";
        if(isalpha(str1[i])==0)
            continue;
        if(isalpha(str1[i+1])==0)
        {
            i+=1;
            continue;
        }
        tmp+=toupper(str1[i]);
        tmp+=toupper(str1[i+1]);
        v1.push_back(tmp);
    }
    
    for(int i=0;i<str2.size()-1;i++)
    {
        tmp="";
        if(isalpha(str2[i])==0)
            continue;
        if(isalpha(str2[i+1])==0)
        {
            i+=1;
            continue;
        }
        tmp+=toupper(str2[i]);
        tmp+=toupper(str2[i+1]);
        v2.push_back(tmp);
    }
    
    
    if(v1.size()==0&&v2.size()==0)
        return 65536;
    
    if(v1.size()>v2.size())
        v1.swap(v2);
    
    
    int sum=v1.size()+v2.size();
    int dif=0;
    cout << sum << "\n";
    
    for(int i=0;i<v1.size();i++)
    {
        int idx=find(v2.begin(),v2.end(),v1[i])-v2.begin();
        if(idx==v2.size())
            continue;
        else
        {
            v2.erase(v2.begin()+idx);
            dif+=1;
        }
    }
    
    cout << dif << "\n";
    
    float a=(float)dif/(sum-dif)*65536;
    a=floor(a);
    answer=(int)a;
    return answer;
}