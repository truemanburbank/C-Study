#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int divider;
	long cnt = 0;

	cin >> n >> divider;

	vector<long> sum(n + 1, 0);
	vector<long> sameRemainder(divider + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		cin >> tmp;

		sum[i] = sum[i - 1] + tmp;
	}

	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i] % divider;
		sameRemainder[sum[i]]++;
	}

	for (int i = 0; i < divider; i++)
	{
		if (sameRemainder[i] >= 2)
		{
			long tmp = sameRemainder[i] * (sameRemainder[i] - 1) / 2;
			cnt += tmp;
		}
	}

	cout << cnt + sameRemainder[0];
}