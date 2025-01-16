#include<iostream>
using namespace std;

// 같은 열인지 확인
bool isUsed0[30];

// 같은 ↗ 대각선 상에 있는지 확인
bool isUsed1[30];

// 같은 ↘ 대각선 상에 있는지 확인 
bool isUsed2[30];

// 1 <= n < 15
int n;

int cnt;

// curX번째 행마다 퀸을 하나씩 배치 예정
void Solve(int curX)
{
    if (curX == n)
    {
        cnt++;
        return;
    }

    // (curX, i)에 퀸을 놓는다.
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
