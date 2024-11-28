#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> s;
    string str;
    cin >> str;

    int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    bool flag = true;
    for(int i = 0 ; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            cnt1++;
            s.push(str[i]);
            flag = true;
        }
        else if(str[i] == '[')
        {
            cnt2++;
            s.push(str[i]);
            flag = true;
        }
        else if(str[i] == ')' && !s.empty())
        {
            if(flag)
                ans += (int)pow(2, cnt1) * (int)pow(3, cnt2);
            if(!s.empty() && s.top() == '(')
                s.pop();
            cnt1--;
            flag = false;
        }
        else if(str[i] == ']' && !s.empty())
        {
            if(flag)
                ans += (int)pow(2, cnt1) * (int)pow(3, cnt2);
            if(!s.empty() && s.top() == '[')
                s.pop();
            cnt2--;
            flag= false;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }

    if(!s.empty())
        cout << 0;
    else
        cout << ans;
}