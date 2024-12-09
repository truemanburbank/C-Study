#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y, vector<vector<int>> &graph, int N)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    graph[x][y] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(graph[nx][ny] != 0) continue;
            q.push({nx, ny});
            graph[nx][ny] = 1;
        }
    }
}

vector<vector<int>> rain(int max, int N)
{
    vector<vector<int>> ret(N, vector<int>(N, 0));
    for(int i = 0; i <N; i++)
    {
        for(int j = 0; j <N; j++)
        {
            if(map[i][j] < max) ret[i][j] = -1; 
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int max = 0;
    for(int i = 0; i <N; i++)
    {
        for(int j = 0; j <N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] > max) max = map[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= max; i++)
    {
        int cnt = 0;
        vector<vector<int>> curMap = rain(i, N);

        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k <N; k++)
            {
                if(map[j][k] != -1 && curMap[j][k] == 0)
                {
                    bfs(j, k, curMap, N);
                    cnt++;
                }
            }
        }

        if(cnt > ans) ans = cnt;
    }

    cout << ans;
}