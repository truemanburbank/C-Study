#include <iostream>
using namespace std;
using ull = unsigned long long;


// A ^ B % C 
// A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
// A^B mod C = (A^B/2 mod C)^2 mod C
ull Solve(ull a, ull b, ull c)
{
    if (b == 1) return a % c;
    
    ull val = Solve(a, b / 2, c);
    val = val * val % c;

    // b가 짝수일 때
    // 중간 과정 반환 
    if (b % 2 == 0) return val;
    
    // b가 홀수일 때 
    // (a^b) % c = [(a^(b-1)) × a] % c
    // = (val × a) % c 
    return val * a % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull A, B, C;
    cin >> A >> B >> C;

    cout << Solve(A, B, C);
    
    return 0;
}