#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// N�� �߿���, M�� ����
int N, M;

// n��°�� ���� ���� ����
int picked[10];

// ���� ����
int numbers[10];

// k��° ���� �ߺ����� �̾Ҵ��� Ȯ��
bool isUsed[10];

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
        // 1. ���� �ε����� ���� �ߺ��ؼ� �̾Ұų�,
        // 2. ���� ���� ������ ���� ��� ����� �ߺ� ������ ���Ѵ�.
        // 3. (1, 7) (7, 1)�� ���� �ߺ��� ���� ���� 
        //    (k - 1��°, k ��°)�� ���, k - 1��° �� > k��°���̸�
        //    �н��Ѵ�.

        if (isUsed[i] || tmp == numbers[i] || (k > 0 && picked[k - 1] > numbers[i])) continue;
        isUsed[i] = 1;
        picked[k] = numbers[i];
        tmp = picked[k];
        Solve(k + 1);
        isUsed[i] = 0;
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
