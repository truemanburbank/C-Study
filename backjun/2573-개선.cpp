#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 300 + 1;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

int map[MAX][MAX];
int visited[MAX][MAX];
int waterVisited[MAX][MAX];
int water[MAX][MAX];

int N, M;

void CalcAdjacentWater()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    waterVisited[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int count = 0;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + dirX[i];
            int y = cur.second + dirY[i];

            if (map[x][y] == 0)
                count++;
            
            if (x < 0 || x >= MAX || y < 0 || y >= MAX) continue;
            if (waterVisited[x][y] == 1) continue;

            q.push({x, y});
            waterVisited[x][y] = 1;
        }
        water[cur.first][cur.second] = count;
    }
    memset(waterVisited, 0, sizeof(waterVisited));
}

void TimePass()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] > 0)
            {
                map[i][j] -= water[i][j];
                map[i][j] = max(0, map[i][j]);
            }
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dirX[i];
            int ny = cur.second + dirY[i];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (visited[nx][ny] == 1 || map[nx][ny] == 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

bool checkZero()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] > 0) return false;
        }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    
    int year = 0;
    while (true)
    {
        if (checkZero())
        {
            cout << 0;
            return 0;
        }
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[i][j] == 1 || map[i][j] == 0)
                    continue;
                bfs(i, j);
                count++;
            }
        }

        if (count > 1) break;
        
        CalcAdjacentWater();
        TimePass();
        memset(visited, 0, sizeof(visited));
        year++;
    }

    cout << year;
    return 0;
}

