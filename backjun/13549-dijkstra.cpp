#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 100001
using namespace std;

// 거리와 노드 정보 필요 

int Solve(int start, int end)
{
    // 거리를 저장할 배열
    vector<int> dist(MAX, INF);

    // 우선 순위 큐를 이용한 다익스트라 알고리즘 구현
    // 거리 & 인덱스
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curIndex = pq.top().second;
        pq.pop();

        // 이미 처리된 노드라면 건너뛰기
        // curDist는 오래된 값이라고 보면 된다. (우선순위 큐의 원리)
        // dist[curIndex]는 최소값을 반영한 최신값 
        if (curDist > dist[curIndex]) continue;
        
        for (int dx : {curIndex - 1, curIndex + 1, curIndex * 2})
        {
            if (dx < 0 || dx >= MAX) continue;
            
            int nextDist = curDist + (dx == curIndex * 2 ? 0 : 1);
            
            if (nextDist < dist[dx])
            {
                dist[dx] = nextDist;
                pq.push({nextDist, dx});
            }
        }
    }
    return dist[end];
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << Solve(N, K);
}