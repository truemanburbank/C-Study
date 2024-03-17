#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	vector<int> numbers(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	int i = 0;
	int j = N - 1;
	int count = 0;

	while (i < j)
	{
		if (numbers[i] + numbers[j] == M)
		{
			count++;
			i++;
			j--;
		}
		else if (M < numbers[i] + numbers[j])
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	cout << count;
}