#include<iostream>
using namespace std;

int n, m;
int numbers[10];
int isUsed[10];

void Solve(int k)
{
    // k�� 0���� �����ϹǷ� k == m�̸� �� �̰� ���� ����.
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << numbers[i] << ' ';
        cout << '\n';
        return;
    }

    // 1���� n������ ���ڿ� ����
    for (int i = 1; i <= n; i++)
    {
        // ���� �� ���ڰ� ������ �ʾҴٸ�
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
