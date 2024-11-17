#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 제일 작은 수로 이길 수 있는 최대의 수를 이겨야 한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    
    int ans = 0;
    
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
   
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i] > B[j] && B[j] != 0)
            {
                ans += 2;
                A[i] = 0;
                B[j] = 0;
                break;
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        if(A[i] == 0)
            continue;
        for(int j = 0; j < N; j++)
        {
            if(A[i] == B[j])
            {
                ans += 1;
                A[i] = 0;
                B[j] = 0;
                break;
            }
        }
    }
    
    // 반례
    // 3 4 5 6
    // 1 2 5 7
    cout << ans;
}

