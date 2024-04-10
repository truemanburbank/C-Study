#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> stack;
	vector<char> res;

	int j = 1;

	for(int i = 0; i < N; i++)
	{
		int number;
		cin >> number;

		while (j <= number)
		{
			stack.push(j);
			res.push_back('+');
			j++;
		}

		if (stack.top() == number)
		{
			res.push_back('-');
			stack.pop();
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << '\n';
	}
}