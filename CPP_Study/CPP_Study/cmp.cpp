#include <iostream>
using namespace std;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

int a = 1;
int b = 2;

int main()
{
#pragma region �� ����

	// ���� �ʿ��Ѱ�?
	// ex) ü���� 0�� �Ǹ� ���
	// ex) ü���� 30% �����̸� �ñر⸦ �ߵ� (100 * hp / maxHp)
	// ex) ����ġ�� 100 �̻��̸� ������

	// a == b : a�� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);

	// a != b : a�� b�� ���� �ٸ���?
	// �ٸ��� 1, ������ 0
	isDifferent = (a != b);

	// a > b : a�� b���� ū��?
	// a >= b : a�� b���� ũ�ų� ������?
	// 1 �ƴϸ� 0
	isGreater = (a > b);
	
	// a < b : a�� b���� ������?
	// a <= b : a�� b���� �۰ų� ������?
	// 1 �ƴϸ� 0
	isSmaller = (a < b);
#pragma endregion
}