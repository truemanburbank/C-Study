#include <iostream>
using namespace std;

// ������ ���� : �б⹮
// �����͸� �޸𸮿� �Ҵ��ϰ� �����ϰ� ����� ���� �˾ƺ�
// ������ �����͸� �̿��ؼ� �����ΰ��� �ϰ� �ʹٸ�?

int main()
{
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	if (input == ROCK)
		cout << "������ �½��ϴ�." << endl;
	else if (input == PAPER)
		cout << "���� �½��ϴ�." << endl;
	else if (input == SCISSORS)
		cout << "������ �½��ϴ�." << endl;
	else
		cout << "�ӳ�" << endl;

	// switch - case - break

	// ���� �迭�� ���� �� �ִ�.
	switch (input)
	{
	case ROCK:
		cout << "������ �½��ϴ�." << endl;
		break;
	case PAPER:
		cout << "���� �½��ϴ�." << endl;
		break;
	case SCISSORS:
		cout << "������ �½��ϴ�." << endl;
		break;
	default:
		cout << "�ӳ�" << endl;
		break;
	}
}