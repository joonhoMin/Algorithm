#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<int, string, int> t1, tuple<int, string, int> t2)
{
    if (get<0>(t1) == get<0>(t2))
        return get<2>(t1) < get<2>(t2);

    return get<0>(t1) < get<0>(t2);
}

int main(void)
{
    int N, age, i;
    string name;
    cin >> N;
    vector<tuple<int, string, int>> v;
    for (i = 0; i < N; i++)
    {
        cin >> age >> name;
        v.push_back({ age, name, i });
    }

    sort(v.begin(), v.end(), compare);
    for (i = 0; i < N; i++)
    {
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n";
    }

    return 0;
}