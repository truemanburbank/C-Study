// ���� 1
// �����ڸ� �̿��ؼ� ���� �䱸 ���׿� �����ϴ� �Լ��� ���� �����϶�
// - ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
// - ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�

#include <iostream>

void add(int& value)
{
	value += 1;
}

void switchSign(int& value)
{
	value *= -1;
}

int main()
{
	int a = 20;
	add(a);
	switchSign(a);
	std::cout << a;

	return 0;
}