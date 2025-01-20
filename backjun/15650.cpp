#include<iostream>
using namespace std;

// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램

int N, M;

int numbers[10];
int isUsed[10];

void Solve(int numberCount)
{
    // 중복 없이 M 개를 다 골랐을 경우
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
        // 이미 방문했을 경우 그 수를 더 방문하지 않는다. 
        if (isUsed[i]) continue;

        // 중복된 순열을 만들지 않기 위해
        // (1, 2) (1, 3) 은 되지만 (3, 1), (2, 1)은 안 되므로
        // 이미 뽑은 숫자가 다음 뽑을 숫자보다 크면 진행하지 못하도록 했다.
        if (numberCount > 0 && numbers[numberCount - 1] > i + 1) continue;

        // 백트래킹 
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
