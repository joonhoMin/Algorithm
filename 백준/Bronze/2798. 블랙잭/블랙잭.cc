#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, M, card, max=0;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> card;
        v.push_back(card);
    }
    for (int i = 0; i < N - 2; i++)
        for (int j = i + 1; j < N - 1; j++)
            for (int k = j + 1; k < N; k++)
                if (v[i] + v[j] + v[k] <= M && v[i] + v[j] + v[k] > max)
                    max = v[i] + v[j] + v[k];
    cout << max << "\n";
    return 0;
}