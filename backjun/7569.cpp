#include <iostream>
#include <queue>
using namespace std;

// 행 열 헷갈려서 틀림 

int tomato[101][101][101];
int visitd[101][101][101];

int dx[6] = {0, 0, 1, -1, 0, 0}; // x 방향 변화량
int dy[6] = {1, -1, 0, 0, 0, 0}; // y 방향 변화량
int dh[6] = {0, 0, 0, 0, 1, -1}; // z 방향 변화량

int m, n, h;

struct pos
{
    int x;
    int y;
    int h;
};

queue<pos> q;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int height = q.front().h;
        q.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            int newH = height + dh[i];
            
            if(newX >= n || newY >= m || newH >= h|| newX < 0 || newY < 0 || newH < 0) continue;
            if(visitd[newH][newX][newY] != 0 || tomato[newH][newX][newY] == 1 || tomato[newH][newX][newY] == -1) continue;
            
            visitd[newH][newX][newY] = visitd[height][x][y] + 1;
            q.push({newX, newY, newH});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> h;

    
    for(int i = 0; i < h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1)
                {
                    q.push({j, k, i});
                    visitd[i][j][k] = 1;
                }
                else if(tomato[i][j][k] == -1)
                    visitd[i][j][k] = -1;
            }
    
    bfs();
    int ans = 0;
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(ans < visitd[i][j][k])
                    ans = visitd[i][j][k];
                if(visitd[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    

    cout<< ans - 1;
}
