/*
 * 1. 섬을 찾는다.
 * 2. 다른 섬과 이어지는 가장 가까운 장소를 찾고, 거리를 저장한다.
 * 3. 그 거리들 간의 최소값을 출력한다.
 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int map[101][101];
int visited[101][101];
int dist = 987654321;

int n;

bool IsInBoundary(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    return false;
}

void FindIsland(int x, int y, int count)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    map[x][y] = count;
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!IsInBoundary(nx, ny) || visited[nx][ny] > 0 || map[nx][ny] == 0) continue;

            map[nx][ny] = count;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void FindShortestDistance(queue<pair<int, int>>& q)
{
    // 방문 배열 초기화
    memset(visited, 0, sizeof(visited));
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 섬 바깥으로 거리 측정
            if (!IsInBoundary(nx, ny) || map[nx][ny] == map[cx][cy]) continue;

            // 다른 섬을 만나면 거리 출력하고 종료
            if (map[nx][ny] != 0)
            {
                dist = min(dist, visited[nx][ny] + visited[cx][cy]);
            }
            else
            {
                map[nx][ny] = map[cx][cy];
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int count = 1;
    
    // 섬들을 찾아 각각 번호를 붙여줌
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 1 && visited[i][j] == 0)
                FindIsland(i, j, count++);
            
    queue<pair<int, int>> q;
    // 각각의 좌표마다 다음 섬까지의 최단 거리 찾음 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] > 0)
            {
                q.push({i, j});
            }

    
    FindShortestDistance(q);

    cout << dist;

    
    return 0;
}