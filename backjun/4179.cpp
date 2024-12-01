#include <iostream>
#include <queue>
using namespace std;

char board[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    queue<pair<int, int>> jq;
    int jtime[1001][1001] = {0};
    
    queue<pair<int, int>> fq;
    int ftime[1001][1001] = {0};
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'J')
            {
                jq.push({i, j});
                jtime[i][j] = 1;
            }
            else if(board[i][j] == 'F')
            {
                fq.push({i, j});
                ftime[i][j] = 1;
            }
        }
    
    // 불 경로
    while (!fq.empty())
    {
        int x = fq.front().first;
        int y = fq.front().second;
        
        fq.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(newx >= r || newy >= c || newx < 0 || newy < 0) continue;
            if(board[newx][newy] == '#' || ftime[newx][newy] >= 1) continue;
            
            fq.push({newx, newy});
            ftime[newx][newy] = ftime[x][y] + 1;
        }
    }

    // 지훈이 경로
    while (!jq.empty())
    {
        int x = jq.front().first;
        int y = jq.front().second;
        
        jq.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(newx >= r || newy >= c || newx < 0 || newy < 0)
            {
                cout << jtime[x][y];
                return 0;
            }
            if(board[newx][newy] == '#' || jtime[newx][newy] >= 1)
                continue;
            if(ftime[newx][newy] != 0 && jtime[x][y] + 1 >= ftime[newx][newy])
                continue;
            
            jq.push({newx, newy});
            jtime[newx][newy] = jtime[x][y] + 1;
        }
    }
    
    cout << "IMPOSSIBLE";
}
