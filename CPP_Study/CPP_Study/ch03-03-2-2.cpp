#include <iostream>
#include <string>

class Printer
{
private:
	std::string str;
public:
	void SetString(std::string a)
	{
		str = a;
	}
	void ShowString()
	{
		std::cout << str << std::endl;
	}
};

int main()
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}