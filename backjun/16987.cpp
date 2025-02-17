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
int picked;

bool IsAllCrashedExceptOneEgg()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (IsCrashed[i])
            cnt++;
    }

    return cnt == 1;
}

void Solve(int idx, int cnt)
{
    if (idx == N)
    {
        if (ans < cnt)
            ans = cnt;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (IsCrashed[i])
        {
            continue;
        }

        if (IsCrashed[idx])
        {
            Solve(idx + 1, cnt);
            continue;
        }

        Egg& handEgg = eggs[idx];
        picked = idx;

        if (picked == i) continue;

        Egg& targetEgg = eggs[i];

        handEgg.DEF -= targetEgg.ATK;
        targetEgg.DEF -= handEgg.ATK;

        if (handEgg.DEF <= 0)
        {
            cnt++;
            IsCrashed[idx] = true;
        }

        if (targetEgg.DEF <= 0)
        {
            cnt++;
            IsCrashed[i] = true;
        }
        
        Solve(idx + 1, cnt);

        if (handEgg.DEF <= 0)
        {
            cnt--;
            IsCrashed[idx] = false;
        }

        if (targetEgg.DEF <= 0)
        {
            cnt--;
            IsCrashed[i] = false;
        }

        handEgg.DEF += targetEgg.ATK;
        targetEgg.DEF += handEgg.ATK;
    }

    if (ans < cnt)
        ans = cnt;
}


int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        // first  : 내구도 DEF
        // second : 무게   
        Egg tmp;
        std::cin >> tmp.DEF >> tmp.ATK;
        eggs.push_back(tmp);
        IsCrashed.push_back(false);
    }

    Solve(0, 0);
    
    std::cout << ans;

    return 0;
}
