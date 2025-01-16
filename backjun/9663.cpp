#include<iostream>
using namespace std;

// ���� ������ Ȯ��
bool isUsed0[30];

// ���� �� �밢�� �� �ִ��� Ȯ��
bool isUsed1[30];

// ���� �� �밢�� �� �ִ��� Ȯ�� 
bool isUsed2[30];

// 1 <= n < 15
int n;

int cnt;

// curX��° �ึ�� ���� �ϳ��� ��ġ ����
void Solve(int curX)
{
    if (curX == n)
    {
        cnt++;
        return;
    }

    // (curX, i)�� ���� ���´�.
    for (int i = 0; i < n; i++)
    {
        if (isUsed0[i] || isUsed1[curX + i] || isUsed2[curX - i + n - 1]) continue;
        isUsed0[i] = true;
        isUsed1[curX + i] = true;
        isUsed2[curX - i + n - 1] = true;
        Solve(curX + 1);
        isUsed0[i] = false;
        isUsed1[curX + i] = false;
        isUsed2[curX - i + n - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    Solve(0);

    cout << cnt;

    return 0;
}
