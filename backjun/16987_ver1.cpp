#include <iostream>
using namespace std;

struct Egg
{
    int DEF = 0;
    int ATK = 0;
};

int N = 0;
int ans = 0;
int cnt = 0;
int IsCrashed[10];
Egg eggs[10];

void Solve(int idx)
{
    // 마지막 계란까지 탐색 완료
    if (idx == N)
    {
        ans = max(ans, cnt);
        return;
    }

    // 현재 계란이 이미 깨졌다면 다음으로 이동
    // 현재 계란 말고 다른 계란이 전부 깨져 있으면 다음으로 이동
    if (IsCrashed[idx] || cnt == N - 1)
    {
        Solve(idx + 1);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // 자기 자신이나 깨진 계란 제외
        if (idx == i || IsCrashed[i])
        {
            continue;
        }

        eggs[idx].DEF -= eggs[i].ATK;
        eggs[i].DEF -= eggs[idx].ATK;

        if (eggs[idx].DEF <= 0)
        {
            cnt++;
            IsCrashed[idx] = true;
        }

        if (eggs[i].DEF <= 0)
        {
            cnt++;
            IsCrashed[i] = true;
        }
        
        Solve(idx + 1);

        // 원상 복구
        eggs[idx].DEF += eggs[i].ATK;
        eggs[i].DEF += eggs[idx].ATK;
        if (IsCrashed[idx])
        {
            cnt--;
            IsCrashed[idx] = false;
        }

        if (IsCrashed[i])
        {
            cnt--;
            IsCrashed[i] = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;

    for (int i = 0; i < N; i++)
        std::cin >> eggs[i].DEF >> eggs[i].ATK;

    Solve(0);
    
    std::cout << ans;

    return 0;
}
