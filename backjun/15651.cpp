#include <iostream>
using namespace std;

// N�� �߿���, M�� ����
int N, M;

// n��°�� ���� ���� ����
int numbers[10];

// k ��°�� ������ ���� Ž�� 
void Solve(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << numbers[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        numbers[k] = i + 1;
        Solve(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
   
    Solve(0);

    return 0;
}
