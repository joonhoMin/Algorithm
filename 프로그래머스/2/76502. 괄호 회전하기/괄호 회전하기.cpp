#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = 0;

    string t = s + s;

    for (int i = 0; i < n; i++) {
        stack<char> stk;
        bool valid = true;

        for (int j = i; j < i + n; j++) {
            char c = t[j];

            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty()) {
                    valid = false;
                    break;
                }

                if ((c == ')' && stk.top() == '(') ||
                    (c == '}' && stk.top() == '{') ||
                    (c == ']' && stk.top() == '['))
                    stk.pop();
                else {
                    valid = false;
                    break;
                }
            }
        }

        if (valid && stk.empty())
            answer++;
    }

    return answer;
}