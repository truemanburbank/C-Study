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
    // ������ ������� Ž�� �Ϸ�
    if (idx == N)
    {
        if (ans < cnt)
            ans = cnt;
        return;
    }

    // ���� ����� �̹� �����ٸ� �������� �̵�
    if (IsCrashed[idx])
    {
        Solve(idx + 1, cnt);
        return;
    }

    bool isAttacked = false;
    for (int i = 0; i < N; i++)
    {
        // �ڱ� �ڽ��̳� ���� ��� ����
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

        // ���� ����
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

    // ����� ������ �� ���� ���� ������ ��
    // �ڽ� ���� �� ���� �ִ� ��� 
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
