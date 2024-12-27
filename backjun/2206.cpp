#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int map[1001][1001];

int dx[4] = {-1, 0, 1,0};
int dy[4] = {0, -1, 0, 1};

// 벽을 부순 경로와 안 부쉈을 때 경로가 다르기 때문에
// 3차원 배열로 선언한다. 
int visited[1001][1001][2];

struct status
{
    int x;
    int y;
    int isCrashed;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 공백이 없는 맵을 받기 위해 scanf %1d 사용
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &map[i][j]);

    queue<status> q;
    q.push({1, 1, 0});
    visited[1][1][0] = 1;

    while (!q.empty())
    {
        status old = q.front();
        q.pop();

        // 목적지에 도착
        if (old.x == n && old.y == m)
        {
            printf("%d\n", visited[old.x][old.y][old.isCrashed]);

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    printf("%d ", visited[i][j][0]);
                }
                printf("\n");  
            }
            
            printf("\n");

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    printf("%d ", visited[i][j][1]);
                }
                printf("\n");  
            }
            
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int x = old.x + dx[i];
            int y = old.y + dy[i];

            // 범위 확인
            if (x <= 0 || x > n || y <= 0 || y > m) continue;

            // 이미 방문한 지점인지 확인
            if (visited[x][y][old.isCrashed] > 0) continue;
            
            // 벽을 부술 수 있을 때
            if (map[x][y] == 1 && old.isCrashed == 0)
            {
                q.push({x, y, 1});
                visited[x][y][1] = visited[old.x][old.y][old.isCrashed]  + 1;
            }
            // 그냥 갈 수 있는 곳일 때
            else if (map[x][y] == 0)
            {
                q.push({x, y, old.isCrashed});
                visited[x][y][old.isCrashed] = visited[old.x][old.y][old.isCrashed] + 1;
            }
        }
    }
    
    printf("-1\n");
}