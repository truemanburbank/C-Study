#include <iostream>
#include <vector>
using namespace std;

// ��, ��, ��, �� (2���� �迭����)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board1[10][10]; // ���� board
int board2[10][10]; // �簢 ������ ������ ���� ���� ����� ����
int N, M;
vector<pair<int, int>> cctvs;

// (x, y)���� dir �������� �����ϸ鼭 ���� ���� ������ ����ġ�� ��� ��ĭ�� 7�� �ٲ�
void RotateCCTV(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];

        // ������ �Ѿ ��� && ���� ���� ��� �Լ� ���� 
        if (x < 0 || x >= N || y < 0 || y >= M || board2[x][y] == 6) return;

        // ���� ��ġ�� CCTV�� ���� ��� �հ� ������
        if (board2[x][y] != 0) continue;

        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N >> M;
    
    int ans = 0; // �簢������ �ּ� ũ�� (��)
    
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

    // cctv�� ���� �Ͼ �� �ִ� ��� ����� ��
    // 4^k
    int cnt = 1 << (2 * cctvs.size()); 
    for (int tmp = 0; tmp < cnt; tmp++)
    {
        // ���� board�� ����
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }

        // ���� ������ ����� ���� �ִ� 4�����̹Ƿ� 4������ �̿��Ͽ� Ǯ��.
        int curCase = tmp;
        for (int i = 0; i < cctvs.size(); i++)
        {
            // 4������ �� �ڸ����� ���Ͽ� ����� �� ����
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

        // �簢���� ����
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
