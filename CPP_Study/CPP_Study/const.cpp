#include <iostream>
using namespace std;

// �ѹ� �������� ���� �ٲ��� ���� ����
// constant�� ������ const�� ���� (������ ���ȭ �Ѵٰ� ��)
// const�� �ٿ����� �ʱⰪ�� �ݵ�� �����ؾ� ��

unsigned char flag;

// �׷��� const�� �ٲ��� �ʴ� �б� ���� .rodata?
// ��� C++ ǥ�ؿ��� �� �׷��� �϶�� ���� ����
// �׳� �����Ϸ� (VS) �����̶�� ��
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int FEAR = 3;
const int INVINCIBLE = 4;

// ���� ����

// [������ ����]
// .data (�ʱⰪ�� �ִ� ���)
int a = 2;

// .bss (�ʱⰪ ���� ���, 0)
int b;

// .rodata (�б� ���� ������)
const char* msg = "Hello World";

int main()
{
	// [���� ����]
	int c = 3;
#pragma region ��Ʈ ����
	// ���� ���·� �����
	flag = (1 << INVINCIBLE);

	// ���� ���¸� �߰��Ѵ� (���� + ����)
	flag |= (1 << POLYMORPH);

	// �������� Ȯ���ϰ� �ʹ�
	// bitmask
	bool invincible = (flag & (1 << INVINCIBLE)) != 0;
#pragma endregion
}