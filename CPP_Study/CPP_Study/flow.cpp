#include <iostream>
using namespace std;

// 오늘의 주제 : 분기문
// 데이터를 메모리에 할당하고 가공하고 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?

int main()
{
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	if (input == ROCK)
		cout << "바위를 냈습니다." << endl;
	else if (input == PAPER)
		cout << "보를 냈습니다." << endl;
	else if (input == SCISSORS)
		cout << "가위를 냈습니다." << endl;
	else
		cout << "머냐" << endl;

	// switch - case - break

	// 정수 계열만 넣을 수 있다.
	switch (input)
	{
	case ROCK:
		cout << "바위를 냈습니다." << endl;
		break;
	case PAPER:
		cout << "보를 냈습니다." << endl;
		break;
	case SCISSORS:
		cout << "가위를 냈습니다." << endl;
		break;
	default:
		cout << "머냐" << endl;
		break;
	}
}