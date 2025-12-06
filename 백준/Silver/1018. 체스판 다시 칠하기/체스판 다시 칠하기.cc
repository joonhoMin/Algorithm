#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M, count = 0, mincount=32;
    string S;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        for (int j = 0; j < M; j++)
        {
            if (S[j] == 'W')
                v[i][j] = 0;
            else
                v[i][j] = 1;
        }
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            count = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if ((k + l) % 2 == 0 && v[k][l] == 1)
                        count++;
                    if ((k + l) % 2 == 1 && v[k][l] == 0)
                        count++;
                }
            }
            count = min(count, 64 - count);
            if (count < mincount)
                mincount = count;
        }
    }

    cout << mincount << "\n";
    return 0;
}