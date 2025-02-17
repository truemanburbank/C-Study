#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 1. 25C7�� ����.
// 2. 7���� �����ִ��� Ȯ��
// 3. �̴ټ����� �� Ȯ��

// �����ؾ� �� ��
// 1. next_permutation ��Ȯ�� ����
// 2. ���� �信 ���� ��Ȯ�� ����

string board[5];

int ans;

// next_permutation
bool mask[25];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;

        board[i] = str;
    }

    // 25�� �� 7���� �����Ƿ�, 
    // mask �迭�� 0 7��, �������� 1�� ä���. 
    fill(mask + 7, mask + 25, true);

    do
    {
        queue<pair<int, int>> q;
        int dasom = 0, cnt = 0;
        bool Is7[5][5] = {}, visited[5][5] = {};

        for (int i = 0; i < 25; i++)
        {
            if (mask[i] == 0)
            {
                int x = i / 5;
                int y = i % 5;

                Is7[x][y] = true;

                if (q.empty())
                {
                    q.push({ x, y });
                    visited[x][y] = true;
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            cnt++;

            dasom += board[x][y] == 'S';

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (visited[nx][ny] || !Is7[nx][ny]) continue;

                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }

        ans += (cnt >= 7 && dasom >= 4);

    } while (next_permutation(mask, mask + 25));

    cout << ans;

    return 0;
}
