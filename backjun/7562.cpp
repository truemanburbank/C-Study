#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    

    for(int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        
        int initX, initY;
        cin >> initX >> initY;
        
        int retX, retY;
        cin >> retX >> retY;
        
        int board[301][301] = {};
        
        bool flag = false;
        
        queue<pair<int, int>> q;
        q.push({initX, initY});
        board[initX][initY] = 1;
        
        while (!q.empty())
        {
            int curX = q.front().first;
            int curY = q.front().second;
            
            if(curX == retX && curY == retY)
            {
                cout << 0 << '\n';
                break;
            }
            
            q.pop();
            for(int j = 0; j < 8; j++)
            {
                int nx = curX + dx[j];
                int ny = curY + dy[j];
                
                if(nx >= l || ny >= l || nx < 0 || ny < 0) continue;
                if(board[nx][ny] != 0) continue;
            
                q.push({nx, ny});
                board[nx][ny] = board[curX][curY] + 1;
                
                if(nx == retX && ny == retY)
                {
                    cout << board[nx][ny] - 1 << '\n';
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                break;
        }
    }
    
}
