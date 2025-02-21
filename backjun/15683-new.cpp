#include <iostream>
#include <vector>
using namespace std;

// 남, 동, 북, 서 (2차원 배열에서)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board1[10][10]; // 원본 board
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
int N, M;
vector<pair<int, int>> cctvs;

// (x, y)에서 dir 방향으로 진행하면서 벽을 만날 때까지 지나치는 모든 빈칸을 7로 바꿈
void RotateCCTV(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];

        // 범위를 넘어갈 경우 && 벽이 있을 경우 함수 종료 
        if (x < 0 || x >= N || y < 0 || y >= M || board2[x][y] == 6) return;

        // 현재 위치에 CCTV가 있을 경우 뚫고 지나감
        if (board2[x][y] != 0) continue;

        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N >> M;
    
    int ans = 0; // 사각지대의 최소 크기 (답)
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctvs.push_back({ i, j });
            if (board1[i][j] == 0) ans++;
        }
    }

    // cctv를 통해 일어날 수 있는 모든 경우의 수
    // 4^k
    int cnt = 1 << (2 * cctvs.size()); 
    for (int tmp = 0; tmp < cnt; tmp++)
    {
        // 원본 board를 복사
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }

        // 각각 방향의 경우의 수가 최대 4가지이므로 4진수를 이용하여 풀이.
        int curCase = tmp;
        for (int i = 0; i < cctvs.size(); i++)
        {
            // 4진수의 각 자리수를 구하여 경우의 수 적용
            int dir = curCase % 4;
            curCase /= 4;

            int x = cctvs[i].first;
            int y = cctvs[i].second;

            if (board1[x][y] == 1)
            {
                RotateCCTV(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                RotateCCTV(x, y, dir);
                RotateCCTV(x, y, dir + 2);
            }
            else if (board1[x][y] == 3)
            {
                RotateCCTV(x, y, dir);
                RotateCCTV(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            {
                RotateCCTV(x, y, dir);
                RotateCCTV(x, y, dir + 1);
                RotateCCTV(x, y, dir + 2);
            }
            else
            {
                RotateCCTV(x, y, dir);
                RotateCCTV(x, y, dir + 1);
                RotateCCTV(x, y, dir + 2);
                RotateCCTV(x, y, dir + 3);
            }
        }

        // 사각지대 세기
        int val = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                val += (board2[i][j] == 0);
            }
        }

        ans = min(ans, val);
    }

    cout << ans;

    return 0;
}
