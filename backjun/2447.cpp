#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int N;
char stars[2222][2222];
// 접근
// 
// 우선 N = 3일 때 사각형을 찍어보자!
// 
// 그럼 N = n이라면?
// 함수 식 생각
void PrintStars(int n, int x, int y)
{
    if (n == 1) 
    {
        stars[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;
            PrintStars(n / 3, x + n / 3 * i, y + n / 3 * j);
        }
    }
}


int main()
{
    // 데이터 입력 받음
    //scanf("%d", &N);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fill(stars[i], stars[i] + n, ' ');

    PrintStars(n, 0, 0);
    for (int i = 0; i < n; i++)
        cout << stars[i] << '\n';

    return 0;
}