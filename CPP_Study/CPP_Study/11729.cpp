#include<iostream>
#include<cmath>

using namespace std;

void Solve(int num, int start, int to, int end);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    cout << int(pow(2,N)) - 1 << '\n';
    Solve(N, 1, 2, 3);
}

void Solve(int num, int start, int to, int end)
{
    if(num == 1)
        cout << start << " " << end << '\n';
    else
    {
        Solve(num - 1, start, end, to);
        cout << start << " " << end << '\n';
        Solve(num - 1, to, start, end);
    }
}