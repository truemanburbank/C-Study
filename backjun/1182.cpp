#include<iostream>
#include <vector>
using namespace std;

int N, S;
int cnt;

// 접근
// 숫자들 중에 특정 수를 더할 것인지, 안 더할 것인지 여부를 판단하여 진행한다. 

// int: 정수
// bool: 그 정수를 방문 했는지
vector<pair<int, bool>> numbers;

// numberConut: 몇 번째 숫자까지 순회했는지
// numbersSum: 현재 고른 수 들의 합
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
    // 합이 0일 때 아무것도 선택하지 않을 수 있으므로 그걸 제외시킨다.
    if (S == 0) cnt--;
    cout << cnt;

    return 0;
}
