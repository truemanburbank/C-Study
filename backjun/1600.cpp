#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define W_MAX 201   // 가로 (열)
#define H_MAX 201   // 세로 (행)
#define K_MAX 31    // 원숭이의 능력

int map[K_MAX][H_MAX][W_MAX];   // [능력 사용 횟수][세로][가로]
int visited[K_MAX][H_MAX][W_MAX]; // 방문 여부 저장

int kdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2}; // 말 이동 (x)
int kdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // 말 이동 (y)
int dx[4] = {0, 0, 1, -1};  // 기본 이동 (x)
int dy[4] = {1, -1, 0, 0};  // 기본 이동 (y)

struct status
{
    int x, y, useSkill;
};

void Solve()
{
    int K;  // 원숭이가 사용할 수 있는 능력 횟수
    cin >> K;

    int W, H;  // 가로, 세로
    cin >> W >> H;

    for (int i = 1; i <= H; i++)  // 세로 (행)
        for (int j = 1; j <= W; j++)  // 가로 (열)
        {
            cin >> map[0][i][j];
            
            // 다른 면에도 똑같이 장애물 설치
            for (int k = 1; k < K_MAX; k++)
                map[k][i][j] = map[0][i][j];
        }

    queue<status> q;
    q.push({1, 1, 0});  // 시작점 (1, 1)에서 능력 사용 0으로 시작
    visited[0][1][1] = 1;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int k = q.front().useSkill;
        q.pop();

        if (x == W && y == H)  // 목표 지점 도달
        {
            cout << visited[k][y][x] - 1;  // 이동 횟수 출력
            return;
        }

        // 말 이동
        if (k < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + kdx[i];
                int ny = y + kdy[i];

                if (nx < 1 || nx > W || ny < 1 || ny > H) continue;  // 범위 확인
                if (map[k][ny][nx] == 1 || visited[k + 1][ny][nx] > 0) continue;

                q.push({nx, ny, k + 1});
                visited[k + 1][ny][nx] = visited[k][y][x] + 1;
            }
        }

        // 기본 이동
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > W || ny < 1 || ny > H) continue;  // 범위 확인
            if (map[k][ny][nx] == 1 || visited[k][ny][nx] > 0) continue;

            q.push({nx, ny, k});
            visited[k][ny][nx] = visited[k][y][x] + 1;
        }
    }

    cout << -1;  // 도달 불가
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
}
