#include <iostream>
#include <vector>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"

int main()
{
	Curve* a = nullptr;
	Ellipse el(6, 4);

	for (double e : el.GetPoint(3.14159))
	{
		std::cout << e << std::endl;
	}

	Circle cr(5);

	for (double c : cr.GetPoint(3.14159))
	{
		std::cout << c << std::endl;
	}


	return 0;
}
