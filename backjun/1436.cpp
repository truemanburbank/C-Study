#include<iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string series[10001] = {""};
    int idx = 1;
    int i = 0;
    while (idx < 10001)
    {
        string number = to_string(i++);
        auto isContain = number.find("666");
        if(isContain != string::npos)
            series[idx++] = number;
    }

    int n;
    cin >> n;

    cout << series[n];
}
