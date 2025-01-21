#include <iostream>
using namespace std;

// N개 중에서, M개 뽑음
int N, M;

// n번째로 뽑은 수를 저장
int numbers[10];

// k 번째로 저장할 수를 탐색 
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
