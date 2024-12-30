#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;

int n, cnt;
int students[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int index)
{
    visited[index] = true;

    int next = students[index];
    if (!visited[next])
        dfs(next);
    else if (!done[next])
    {
        for (int i = next; i != index; i = students[i])
            cnt++;
        cnt++;
    }

    done[index] = true;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        cin >> n;

        for (int j = 1; j <= n; j++)
            cin >> students[j];

        cnt = 0;

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
                dfs(j);
        }

        cout << n - cnt << '\n';
    }

    return 0;
}