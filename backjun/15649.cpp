#include<iostream>
using namespace std;

int n, m;
int numbers[10];
int isUsed[10];

void Solve(int k)
{
    // k는 0부터 시작하므로 k == m이면 다 뽑고 다음 턴임.
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << numbers[i] << ' ';
        cout << '\n';
        return;
    }

    // 1부터 n까지의 숫자에 대해
    for (int i = 1; i <= n; i++)
    {
        // 아직 그 숫자가 사용되지 않았다면
        if (!isUsed[i])
        {
            numbers[k] = i;
            isUsed[i] = true;
            Solve(k + 1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    Solve(0);

    return 0;
}
