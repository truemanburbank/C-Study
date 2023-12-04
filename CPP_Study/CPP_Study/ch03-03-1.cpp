#include <iostream>

struct Point
{
	int xpos;
	int ypos;

	// 좌표 이동
	void MovePos(int x, int y)
	{
		xpos += x;
		ypos += y;
	}

	// 점의 좌표 증가
	void AddPoint(const Point &pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
	}

	void ShowPosition()
	{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}
};

int main()
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}