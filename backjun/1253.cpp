#include <iostream>
#include <vector>
#include<algorithm>
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
	sort(numbers.begin(), numbers.end());

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int j = 0;
		int k = N - 1;
		while (j < k)
		{
			if (numbers[j] + numbers[k] == numbers[i])
			{
				if (j != i && k != i)
				{
					count++;
					break;
				}
				else if (k == i)
				{
					k--;
				}
				else if (j == i)
				{
					j++;
				}
			}
			else if (numbers[j] + numbers[k] > numbers[i])
			{
				k--;
			}
			else
			{
				j++;
			}
		}
	}

	cout << count;

}