#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int N;
char stars[2222][2222];

void PrintStars(int n, int x, int y)
{
    if (n == 1)
    {
        stars[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            PrintStars(n / 3, x + n / 3 * i, y + n / 3 * j);
        }
    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fill(stars[i], stars[i] + n, ' ');

    PrintStars(n, 0, 0);
    for (int i = 0; i < n; i++)
        cout << stars[i] << '\n';

    return 0;
}