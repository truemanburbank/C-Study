#include<iostream>
using namespace std;

// �ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷�

int N, M;

int numbers[10];
int isUsed[10];

void Solve(int numberCount)
{
    // �ߺ� ���� M ���� �� ����� ���
    if (numberCount == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << numbers[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // �̹� �湮���� ��� �� ���� �� �湮���� �ʴ´�. 
        if (isUsed[i]) continue;

        // �ߺ��� ������ ������ �ʱ� ����
        // (1, 2) (1, 3) �� ������ (3, 1), (2, 1)�� �� �ǹǷ�
        // �̹� ���� ���ڰ� ���� ���� ���ں��� ũ�� �������� ���ϵ��� �ߴ�.
        if (numberCount > 0 && numbers[numberCount - 1] > i + 1) continue;

        // ��Ʈ��ŷ 
        isUsed[i] = true;
        numbers[numberCount] = i + 1;
        Solve(numberCount + 1);
        isUsed[i] = false;
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
