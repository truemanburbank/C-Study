#include <iostream>
#include <vector>
using namespace std;

int papers[2200][2200];
int N;
int paper[3];

// 같은 종류의 종이인지 확인
bool CheckPaper(int x, int y, int n)
{
    int type = papers[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (papers[i][j] != type)
                return false;
        }
    }

    return true;
}

void Solve(int x, int y, int n)
{
    if (CheckPaper(x, y, n))
    {
        paper[papers[x][y] + 1]++;
        return;
    }

    // 만약 같은 종류의 종이가 아니라면
    // 종이 전체를 9등분 해서 다시 조사한다.
    int parts = n / 3; // 새로운 범위
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Solve(x + i * parts, y + j * parts, parts);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 종이 입력 받음
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> papers[i][j];
    
    Solve(0, 0, N);

    for (int i : paper)
        cout << i << '\n';

    return 0;
}