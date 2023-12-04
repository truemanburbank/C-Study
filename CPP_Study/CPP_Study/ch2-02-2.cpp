#include <iostream>

int main()
{
	const int num = 12;
	const int* ptr = &num;
	const int*& ref = ptr;

	std::cout << *ref;
}