#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char map[1001][1001];
int fv[1001][1001];
int sv[1001][1001];

void InitArray()
{
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
        {
            fv[i][j] = 0;
            sv[i][j] = 0;
        }
}

int Solve()
{
    int w, h;
        cin >> w >> h;
        
        queue<pair<int, int>> fq;
        queue<pair<int, int>> sq;
        InitArray();
        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)
            {
                cin >> map[j][k];
                if(map[j][k] == '*')
                {
                    fq.push({j, k});
                    fv[j][k] = 1;
                }
                else if(map[j][k] == '@')
                {
                    sq.push({j, k});
                    sv[j][k] = 1;
                }
                else if(map[j][k] == '#')
                {
                    fv[j][k] = -1;
                    sv[j][k] = -1;
                }
            }
        }

        while (!fq.empty())
        {
            int x = fq.front().first;
            int y = fq.front().second;
            fq.pop();

            for(int a = 0; a < 4; a++)
            {
                int nx = x + dx[a];
                int ny = y + dy[a];
                        
                if(nx >= h || nx < 0 || ny >= w || ny < 0) continue;
                if(fv[nx][ny] == -1 || fv[nx][ny] > 0) continue;

                fq.push({nx, ny});
                fv[nx][ny] = fv[x][y] + 1;
            }
        }
    
        while (!sq.empty())
        {
            int x = sq.front().first;
            int y = sq.front().second;
            sq.pop();

            for(int a = 0; a < 4; a++)
            {
                int nx = x + dx[a];
                int ny = y + dy[a];
                        
                if(nx >= h || nx < 0 || ny >= w || ny < 0)
                {
                    return sv[x][y];
                }
                if(sv[nx][ny] == -1 || sv[nx][ny] > 0 ||( fv[nx][ny] != 0 && fv[nx][ny] < sv[x][y] + 2)) continue;

                sq.push({nx, ny});
                sv[nx][ny] = sv[x][y] + 1;
            }
        }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ans = Solve();
        if(ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
}