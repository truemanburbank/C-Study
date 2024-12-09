#include <iostream>
#include <queue>
using namespace std;

int building[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    int pos = S;
    queue<int> q;

    int dx[2] = {U, -D};
    
    q.push(pos);
    building[pos] = 1;

    if(S == G)
    {
        cout << 0;
        return 0;
    }
    
    while (!q.empty())
    {
        int curPos = q.front();
        q.pop();

        for(int i = 0; i < 2; i++)
        {
            int nextPos = curPos + dx[i];
            if(nextPos == G)
            {
                cout << building[curPos];
                return 0;
            }
            if(nextPos < 1 || nextPos > F || building[nextPos] > 0) continue;
            q.push(nextPos);
            building[nextPos] = building[curPos] + 1;
        }
    }

    cout << "use the stairs";
}