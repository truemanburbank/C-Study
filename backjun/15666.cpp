#include <iostream>
#include <algorithm>
using namespace std;

// N개 중에서, M개 뽑음
int N, M;

// n번째로 뽑은 수를 저장
int picked[10];

// 숫자 모음
int numbers[10];

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
        // 1. 같은 수가 여러개 있을 경우 생기는 중복 수열을 피한다.
        // 예 (1, 9(A)), (1, 9(B))

        // 2. 비내림차순 수열을 방지한다.
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
   
    // 사전순으로 찾기 위해 배열을 정렬
    sort(numbers, numbers + N);

    Solve(0);

    return 0;
}
