#include <iostream>
#include <algorithm>
using namespace std;

// N�� �߿���, M�� ����
int N, M;

// n��°�� ���� ���� ����
int picked[10];

// ���� ����
int numbers[10];

// k ��°�� ������ ���� Ž�� 
void Solve(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << picked[i] << ' ';
        cout << '\n';

        return;
    }

    // ���� depth���� ���������� ���� ���� ����
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        // 1. ���� ���� ������ ���� ��� ����� �ߺ� ������ ���Ѵ�.
        // �� (1, 9(A)), (1, 9(B))

        // 2. �񳻸����� ������ �����Ѵ�.
        if (tmp == numbers[i] || (k >0 && picked[k - 1] > numbers[i])) continue;
        picked[k] = numbers[i];
        tmp = picked[k];
        Solve(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
   
    // ���������� ã�� ���� �迭�� ����
    sort(numbers, numbers + N);

    Solve(0);

    return 0;
}
