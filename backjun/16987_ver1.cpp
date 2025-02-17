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
    // ������ ������� Ž�� �Ϸ�
    if (idx == N)
    {
        ans = max(ans, cnt);
        return;
    }

    // ���� ����� �̹� �����ٸ� �������� �̵�
    // ���� ��� ���� �ٸ� ����� ���� ���� ������ �������� �̵�
    if (IsCrashed[idx] || cnt == N - 1)
    {
        Solve(idx + 1);
        return;
    }

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
        
        Solve(idx + 1);

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
