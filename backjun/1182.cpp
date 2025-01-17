#include<iostream>
#include <vector>
using namespace std;

int N, S;
int cnt;

// ����
// ���ڵ� �߿� Ư�� ���� ���� ������, �� ���� ������ ���θ� �Ǵ��Ͽ� �����Ѵ�. 

// int: ����
// bool: �� ������ �湮 �ߴ���
vector<pair<int, bool>> numbers;

// numberConut: �� ��° ���ڱ��� ��ȸ�ߴ���
// numbersSum: ���� �� �� ���� ��
void Solve(int numberConut, int numbersSum)
{
    if (N == numberConut)
    {
        if (S == numbersSum) cnt++;
        return;
    }

    Solve(numberConut + 1, numbersSum + numbers[numberConut].first);
    Solve(numberConut + 1, numbersSum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;


    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.push_back({ tmp, false });
    }

    Solve(0, 0);
    // ���� 0�� �� �ƹ��͵� �������� ���� �� �����Ƿ� �װ� ���ܽ�Ų��.
    if (S == 0) cnt--;
    cout << cnt;

    return 0;
}
