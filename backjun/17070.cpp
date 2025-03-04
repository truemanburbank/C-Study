#include <iostream>
using namespace std;

void Solve(int x, int y, int dir);
int map[20][20];
int N;
int ans;

enum Direction
{
    right,
    rightDown,
    down,
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    
    Solve(0, 1, Direction::right);
    cout<< ans;
}


void Solve(int x, int y, int dir)
{
    if(x > N || y > N) return;
    if(x == N - 1 && y == N - 1) ans++;
    
    if(map[x][y + 1] == 0 && (dir == Direction::right || dir == Direction::rightDown))
        Solve(x, y + 1, Direction::right);
    if(map[x + 1][y] == 0 && (dir == Direction::down || dir == Direction::rightDown))
        Solve(x + 1, y, Direction::down);
    if(map[x + 1][y] == 0 && map[x][y + 1] == 0 && map[x + 1][y + 1] == 0)
        Solve(x + 1, y + 1, Direction::rightDown);
}
