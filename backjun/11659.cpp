#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; // 수의 개수
    int M; // 합을 구해야 하는 횟수
    int temp;
    int sum[100001] = {};
    
    int i;
    int j;
    
    cin >> N >> M;
    
    for(int k = 1; k <= N; k++)
    {
        cin >> temp;
        sum[k] = sum[k - 1] + temp;
    }
    
    for(int k = 0; k < M; k++)
    {
        cin >> i >> j;
        
        // endl로 했을 땐 시간 초과였음
        cout << sum[j] - sum[i - 1] << '\n';
    }
}
