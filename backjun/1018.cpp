#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void Solve(int x, int y);
int n, m;
bool map[50][50];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1 흰색 true
    // 2 검은색 false


    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char tmp;
            cin >> tmp;
            if(tmp == 'W')
                map[i][j] = true;
            else
                map[i][j] = false;
        }
    }
    
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            Solve(i, j);

    sort(ans.begin(), ans.end());
    cout << ans[0];
}

void Solve(int x, int y)
{
    int cnt = 0;
    
    if(x + 8 > n || y + 8 > m) return;
    
    bool curColor = false;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if(map[i][j] != curColor)
                cnt++;
            if(j != y + 7)
                curColor = !curColor;
        }
    }
    int ret1 = cnt;

    cnt = 0;
    curColor = true;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if(map[i][j] != curColor)
                cnt++;
            if(j != y + 7)
                curColor = !curColor;
        }
    }

    ans.push_back(cnt);
    int ret2 = cnt;

    int ret = ret1 > ret2 ? ret2 : ret1;
    ans.push_back(ret);
}
