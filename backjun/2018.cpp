#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 1;
	int end = 1;
	int sum = 1;
	int count = 0;
	int N;

	cin >> N;

	while (end != N) 
	{
		if (sum == N)
		{
			end++;
			sum += end;
			count++;
		}
		else if (sum > N)
		{
			sum -= start;
			start++;
		}
		else
		{
			end++;
			sum += end;
		}
	}

	cout << count + 1;
}