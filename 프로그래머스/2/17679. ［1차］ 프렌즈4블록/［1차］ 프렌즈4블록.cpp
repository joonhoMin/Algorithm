#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    
while(1)
{
    vector<vector<int>> issame(m,vector<int>(n,0));
    
    for(int i=0;i<m-1;i++)
        for(int j=0;j<n-1;j++)
            if(board[i][j]!='9'&&board[i][j]==board[i][j+1]&&board[i][j]==board[i+1][j]&&board[i][j]==board[i+1][j+1])
            {
                issame[i][j]=1;
                issame[i][j+1]=1;
                issame[i+1][j]=1;
                issame[i+1][j+1]=1;
            }
    
    
    int oldanswer=answer;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(issame[i][j]==1)
                answer+=1;
    
    if(oldanswer==answer)
        break;
    
    
    vector<string> newboard=board;
    
    for(int j=0;j<n;j++)
    {
        int idx=m-1;
        for(int i=m-1;i>=0;i--)
        {
            if(idx<=-1)
            {
                newboard[i][j]='9';
                continue;
            }
            while(1)
            {
                if(idx<=-1)
                    break;
                if(issame[idx][j]==0)
                    break;
                idx-=1;
            }
            if(idx<=-1)
                continue;
            newboard[i][j]=board[idx][j];
            idx-=1;
        }
    }
    
    board=newboard;
}
    return answer;
}