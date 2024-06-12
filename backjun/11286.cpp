#include <iostream>
#include <queue>
using namespace std;

// 멤버함수로만 오버로딩 가능한 연산자 
// ():함수 호출 연산자
struct compare {
	bool operator()(int o1, int o2)
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs)
			return o1 > o2;
		else
			return first_abs > second_abs;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare> q;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int request;
		cin >> request;

		if (request == 0)
		{
			if (q.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else
		{
			q.push(request);
		}
	}
}