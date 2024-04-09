#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // Numbers
	int L; // Sliding Window's Length

	cin >> N >> L;
	deque<pair<int, int>> sortedNumbers;

	for (int i = 0; i < N; i++)
	{
		int now;
		cin >> now;

		while (!sortedNumbers.empty() && sortedNumbers.back().second > now)
		{
			sortedNumbers.pop_back();
		}
		
		sortedNumbers.push_back(make_pair(i, now));

		if (i - sortedNumbers.front().first >= L)
		{
			sortedNumbers.pop_front();
		}

		cout << sortedNumbers.front().second << ' ';
	}

}