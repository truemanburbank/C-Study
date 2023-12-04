#include <iostream>

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;
// ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ����

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* res = new Point;
	res->xpos = p1.xpos + p2.xpos;
	res->ypos = p1.ypos + p2.ypos;

	return *res;
}

int main()
{
	Point* point1 = new Point;
	point1->xpos = 10; point1->ypos = 12;

	Point* point2 = new Point;
	point2->xpos = 1; point2->ypos = 2;

	// �Լ� �ȿ� �ִ� Point ����(�� ����)�� ������ �� �ִ�. 
	Point& res = PntAdder(*point1, *point2);

	std::cout << res.xpos << " " << res.ypos;

	delete point1;
	delete point2;
	delete &res;
}