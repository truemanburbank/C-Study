#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// N개 중에서, M개 뽑음
int N, M;

// n번째로 뽑은 수를 저장
int picked[10];

// 숫자 모음
int numbers[10];

// k번째 수를 중복으로 뽑았는지 확인
bool isUsed[10];

// k 번째로 저장할 수를 탐색 
void Solve(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << picked[i] << ' ';
        cout << '\n';

        return;
    }

    // 현재 depth에서 마지막으로 뽑은 숫자 저장
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        // 같은 인덱스인 수를 중복해서 뽑았거나,
        // 같은 수가 여러개 있을 경우 생기는 중복 수열을 피한다.
        if (isUsed[i] || tmp == numbers[i]) continue;
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
   
    // 사전순으로 찾기 위해 배열을 정렬
    sort(numbers, numbers + N);

    Solve(0);

    return 0;
}
