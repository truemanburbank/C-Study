#include <iostream>
using namespace std;

const string str[] =
{
    "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n",

    "\"재귀함수가 뭔가요?\"\n",
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n",
    "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
    "라고 답변하였지.\n"
};

// 함수 원형 선언
void Solve(int n);
string printUnderBar(int n);

// base condition
// if(n == 0) return;

// 재귀 식 구현
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

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    Solve(0);

    return 0;
}