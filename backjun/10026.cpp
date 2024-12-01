#include <iostream>
#include <queue>
using namespace std;

int n;
char common[101][101];
char colorBlindness[101][101];
bool commonVisited[101][101];
bool colorBlindnessVisited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Common(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    commonVisited[x][y] = 1;
    
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            
            if(newX >= n || newY >= n || newX < 0 || newY < 0) continue;;
            if(commonVisited[newX][newY] == 1 || common[newX][newY] != common[curX][curY]) continue;
            
            q.push({newX, newY});
            commonVisited[newX][newY] = 1;
        }
    }
}

void ColorBlindness(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    colorBlindnessVisited[x][y] = 1;
    
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            
            if(newX >= n || newY >= n || newX < 0 || newY < 0) continue;;
            if(colorBlindnessVisited[newX][newY] == 1 || colorBlindness[newX][newY] != colorBlindness[curX][curY]) continue;
            
            q.push({newX, newY});
            colorBlindnessVisited[newX][newY] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            char tmp;
            cin >> tmp;
            common[i][j] = tmp;
            colorBlindness[i][j] = tmp;
            if(tmp == 'G')
            {
                colorBlindness[i][j] = 'R';
            }
        }
    }
    
    int ans1 = 0;
    int ans2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(commonVisited[i][j] == 0)
            {
                ans1++;
                Common(i, j);
            }
            if(colorBlindnessVisited[i][j] == 0)
            {
                ans2++;
                ColorBlindness(i, j);
            }
        }
    }
    
    cout << ans1 << ' ' << ans2;
}
