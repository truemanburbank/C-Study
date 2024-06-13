#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> numbers(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				int tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << numbers[i] << "\n";
	}
}