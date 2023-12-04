// ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해 보자
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