#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        stack<char> s;
        string ps;
        cin >> ps;

        for (int j = 0; j < ps.length(); j++)
        {
            if(ps[j] == '(')
                s.push(ps[j]);
            else if(!s.empty() && ps[j] == ')' && s.top() == '(')
                s.pop();
            else
            {
                cout << "NO\n";
                flag = true;
                break;
            }
        }

        if(flag == true) continue;
        if(s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}