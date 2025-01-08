#include <iostream>
using namespace std;

int Solve(int n, int r, int c)
{
    if (n == 0) return 0;
    int half = 1 << (n - 1);

    // 1번 사각형
    if (r < half && c < half)
        return Solve(n - 1, r, c);

    // 2번 사각형
    if (r < half && c >= half)
        return half * half + Solve(n - 1, r, c - half);

    // 3번 사각형
    if (r >= half && c < half)
        return 2 * half * half + Solve(n-1, r - half, c);

    // 4번 사각형
    if (r >= half && c >= half)
        return 3 * half * half + Solve(n-1, r - half, c - half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;
    
    cout << Solve(n, r, c);
    
    return 0;
}