#include <iostream>
using namespace std;

const string str[] =
{
    "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n",

    "\"����Լ��� ������?\"\n",
    "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
    "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
    "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
    "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n",
    "��� �亯�Ͽ���.\n"
};

// �Լ� ���� ����
void Solve(int n);
string printUnderBar(int n);

// base condition
// if(n == 0) return;

// ��� �� ����
// print(n) + ""

int N;

void Solve(int n)
{
    cout << printUnderBar(n) + str[1];
    if (n == N)
    {
        cout << printUnderBar(n) + str[5];
        cout << printUnderBar(n) + str[6];
        return;
    }
    cout << printUnderBar(n) + str[2];
    cout << printUnderBar(n) + str[3];
    cout << printUnderBar(n) + str[4];
    Solve(n + 1);
    cout << printUnderBar(n) + str[6];
}

string printUnderBar(int n)
{
    string str = "";
    for (int i = 0; i < n; i++)
    {
        str += "____";
    }
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    Solve(0);

    return 0;
}