#include <iostream>

class Caculator
{
private: 
	int addCount;
	int subCount;
	int divCount;
	int mulCount;

public:
	void Init()
	{
		addCount = 0;
		subCount = 0;
		divCount = 0;
		mulCount = 0;
	}
	double Add(double a, double b)
	{
		addCount++;
		return a + b;
	}
	double Sub(double a, double b)
	{
		subCount++;
		return a - b;
	}
	double Div(double a, double b)
	{
		divCount++;
		return a / b;
	}
	double Mul(double a, double b)
	{
		mulCount++;
		return a * b;
	}

	void ShowOpCount()
	{
		std::cout << "µ¡¼À: " << addCount << " »¬¼À: " << subCount << " °ö¼À: " << mulCount << " ³ª´°¼À: " << divCount;
	}
};

int main()
{
	Caculator cal;
	cal.Init();
	std::cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << std::endl;
	std::cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << std::endl;
	std::cout << "2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << std::endl;
	std::cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;
	cal.ShowOpCount();
	return 0;
}