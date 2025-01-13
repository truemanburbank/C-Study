#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int data[65][65];
int N;

// 같은 데이터인지 확인
bool CheckData(int x, int y, int n)
{
    int type = ::data[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (::data[i][j] != type)
                return false;
        }
    }

    return true;
}

void Solve(int x, int y, int n)
{
    if (CheckData(x, y, n))
    {
        printf("%d", ::data[x][y]);
    }
    else
    {
        printf("(");
        int half = n / 2;
        Solve(x, y, half);
        Solve(x, y + half, half);
        Solve(x + half, y, half);
        Solve(x + half, y + half, half);
        printf(")");
    }
}


int main()
{
    // 데이터 입력 받음
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &::data[i][j]);
        }
    }
    
    Solve(0, 0, N);

    return 0;
}