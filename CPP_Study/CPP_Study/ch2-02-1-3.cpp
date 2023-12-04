// ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ�� SwapPointer �Լ��� ������ ����
#include <iostream>

void SwapPointer(int* &ptr1, int* &ptr2)
{
	int* tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}

int main()
{
	int num1 = 5;
	int* ptr1 = &num1;

	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	std::cout << "num1: " << *ptr1 << std::endl;
	std::cout << "num2: " << *ptr2 << std::endl; 
	return 0;
}