#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> right(10001,0);
    vector<int> left(10001,0);
    
    int leftkind=0, rightkind=0;
    
    for(int i=0;i<topping.size();i++)
    {
        if(right[topping[i]]==0)
            rightkind++;
        right[topping[i]]++;
    }
    
    for(int i=0;i<topping.size();i++)
    {
        if(left[topping[i]]==0)
            leftkind++;
        left[topping[i]]++;
        
        right[topping[i]]--;
        
        if(right[topping[i]]==0)
            rightkind--;
        
        if(leftkind==rightkind)
            answer++;
    }
    
    return answer;
}