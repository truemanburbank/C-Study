#include <iostream>
#include <deque>
#include <vector>
#define INF 987654321
#define MAX 200001
using namespace std;

// 거리와 노드 정보 필요 

void Solve(int start, int end)
{
    // 거리를 저장할 배열
    vector<int> dist(MAX, INF);

    // deque을 이용한 0-1 bfs 구현
    // 거리 & 인덱스
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(0, start));
    dist[start] = 0;

    while (!dq.empty())
    {
        int curDist = dq.front().first;
        int curIndex = dq.front().second;
        dq.pop_front();

        if (curIndex == end)
        {
            cout << dist[end];
            return;
        }
        
        for (int dx : {curIndex - 1, curIndex + 1, curIndex * 2})
        {
            if (dx < 0 || dx >= MAX) continue;
            
            int nextDist = (dx == curIndex * 2) ? curDist : curDist + 1;
            
            if (nextDist < dist[dx])
            {
                dist[dx] = nextDist;
                if (dx == curIndex * 2)
                    dq.push_front({nextDist, dx});
                else
                    dq.push_back({nextDist, dx});
            }
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    Solve(N, K);
}