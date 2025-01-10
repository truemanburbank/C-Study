#include <iostream>
#include <vector>
using namespace std;

int papers[2200][2200];
int N;
int paper[3];

// ���� ������ �������� Ȯ��
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

    // ���� ���� ������ ���̰� �ƴ϶��
    // ���� ��ü�� 9��� �ؼ� �ٽ� �����Ѵ�.
    int parts = n / 3; // ���ο� ����
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

    // ���� �Է� ����
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> papers[i][j];
    
    Solve(0, 0, N);

    for (int i : paper)
        cout << i << '\n';

    return 0;
}