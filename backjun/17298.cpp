#include <iostream>
#include <stack>
using namespace std;


const int MAX_SIZE = 1000001;
int N;
int A[MAX_SIZE];
int result[MAX_SIZE];
stack<int> tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	tmp.push(0); // Save index

	for (int i = 1; i < N; i++)
	{
		while (!tmp.empty() && A[i] > A[tmp.top()])
		{
			result[tmp.top()] = A[i];
			tmp.pop();
		}

		tmp.push(i);
	}

	while (!tmp.empty())
	{
		result[tmp.top()] = -1;
		tmp.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << ' ';
	}
}