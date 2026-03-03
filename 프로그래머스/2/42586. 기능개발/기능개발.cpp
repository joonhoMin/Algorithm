#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;

    for(int i=0;i<progresses.size();i++){
        int d = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        days.push_back(d);
    }

    int current = days[0];
    int count = 1;

    for(int i=1;i<days.size();i++){
        if(days[i] <= current){
            count++;
        } else {
            answer.push_back(count);
            current = days[i];
            count = 1;
        }
    }

    answer.push_back(count);

    return answer;
}