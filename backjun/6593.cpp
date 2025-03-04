﻿#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {-1, 1};

char building[31][31][31];
int visited[31][31][31];

struct pos
{
    int z;
    int x;
    int y;
};

void bfs(int L, int R, int C, pos start);
void Init();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // z , 행(세로), 열
    int L = -1;
    int R = -1;
    int C = -1;

    while(true)
    {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        pos start;
        for(int k = 0; k < L; k++)
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                {
                    cin >> building[k][i][j];
                    if(building[k][i][j] == 'S')
                        start = {k, i, j};
                }

        
        bfs(L, R, C, start);
        Init();
    }
}

void Init()
{
    for(int k = 0; k < 31; k++)
        for(int i = 0; i < 31; i++)
            for(int j = 0; j < 31; j++)
            {
                building[k][i][j] = 'x';
                visited[k][i][j] = 0;
            }
}

void bfs(int L, int R, int C, pos start)
{
    queue<pos> q;
    q.push({start.z, start.x, start.y});
    visited[start.z][start.x][start.y] = 1;
    while(!q.empty())
    {
        pos p = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int x = p.x + dx[i];
            int y = p.y + dy[i];

            if(x < 0 || x >= R || y < 0 || y >= C) continue;
            if(building[p.z][x][y] == '#' || visited[p.z][x][y] > 0) continue;

            if(building[p.z][x][y] == 'E')
            {
                cout << "Escaped in " << visited[p.z][p.x][p.y] << " minute(s)." << '\n';
                return;
            }
            pos newPos = {p.z, x, y};
            q.push(newPos);
            visited[p.z][x][y] = visited[p.z][p.x][p.y] + 1;
        }

        for(int i = 0; i < 2; i++)
        {
            int x = p.x;
            int y = p.y;
            int z = p.z + dz[i];

            if(z < 0 || z >= L) continue;
            if(building[z][x][y] == '#' || visited[z][x][y] > 0) continue;

            if(building[z][x][y] == 'E')
            {
                cout << "Escaped in " << visited[p.z][p.x][p.y] << " minute(s)." << '\n';
                return;
            }
            pos newPos = {z, x, y};
            q.push(newPos);
            visited[z][x][y] = visited[p.z][p.x][p.y] + 1;
        }
        
    }
    cout << "Trapped!" << '\n';
}