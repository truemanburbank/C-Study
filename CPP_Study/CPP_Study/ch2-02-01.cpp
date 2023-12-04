// 문제 1
// 참조자를 이용해서 다음 요구 사항에 부합하는 함수를 각각 정의하라
// - 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
// - 인자로 전달된 int형 변수의 부호를 바꾸는 함수

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