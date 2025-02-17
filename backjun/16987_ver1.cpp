#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Egg
{
    int DEF = 0;
    int ATK = 0;
};

int N = 0;
int ans = 0;

vector<bool> IsCrashed;
vector<Egg> eggs;

void Solve(int idx, int cnt)
{
    // 마지막 계란까지 탐색 완료
    if (idx == N)
    {
        if (ans < cnt)
            ans = cnt;
        return;
    }

    // 현재 계란이 이미 깨졌다면 다음으로 이동
    if (IsCrashed[idx])
    {
        Solve(idx + 1, cnt);
        return;
    }

    bool isAttacked = false;
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
        
        Solve(idx + 1, cnt);

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

        isAttacked = true;
    }

    // 계란이 공격을 한 번도 하지 못했을 때
    // 자신 말고 다 깨져 있는 경우 
    if (!isAttacked)
        Solve(idx + 1, cnt);
}


int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;
    eggs.resize(N);
    IsCrashed.resize(N);

    for (int i = 0; i < N; i++)
        std::cin >> eggs[i].DEF >> eggs[i].ATK;

    Solve(0, 0);
    
    std::cout << ans;

    return 0;
}
