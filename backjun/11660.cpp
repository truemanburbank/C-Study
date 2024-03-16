#include <iostream>
using namespace std;

int map[1025][1025] = {};
int sum[1025][1025] = {};

int main()
{
    int N; // 표의 크기
    int M; // 합을 구해야 하는 횟수

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];

            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + map[i][j] - sum[i - 1][j - 1];
        }
    }


    for (int i = 0; i < M; i++)
    {
        int x1;
        int x2;
        int y1;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }
}

