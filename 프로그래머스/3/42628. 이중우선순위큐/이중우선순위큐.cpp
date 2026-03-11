#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {

    multiset<int> ms;

    for(string op : operations)
    {
        if(op[0] == 'I')
        {
            int num = stoi(op.substr(2));
            ms.insert(num);
        }
        else
        {
            if(ms.empty()) continue;

            if(op == "D 1")
                ms.erase(prev(ms.end()));   // 최대 삭제
            else
                ms.erase(ms.begin());       // 최소 삭제
        }
    }

    if(ms.empty())
        return {0,0};

    return { *prev(ms.end()), *ms.begin() };
}