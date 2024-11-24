#include <iostream>
using namespace std;

void Solve(int x, int y, int n);
int paper[130][130];
int blueAns;
int whiteAns;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n;
    cin>> n;
    
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    Solve(0, 0, n);
    
    cout << whiteAns << '\n' << blueAns;
}

void Solve(int x, int y, int n)
{
    int color = paper[x][y];
    for(int i = x; i < x + n; i++)
    {
        for(int j = y ; j < y + n; j++)
        {
            if(color != paper[i][j])
            {
                Solve(x, y, n / 2);
                Solve(x, y + n / 2, n / 2);
                Solve(x + n / 2, y, n / 2);
                Solve(x + n / 2, y + n / 2, n / 2);
                return;
            }
        }
    }
    
    if(color == 0)
    {
        whiteAns++;
        return;
    }
    else
    {
        blueAns++;
        return;
    }
}
