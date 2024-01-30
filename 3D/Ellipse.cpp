#include <cmath>
#include "Ellipse.h"

DoubleVector Ellipse::GetPoint(double t)
{
	return { RadiusX * cos(t), RadiusY * sin(t), 0.0 };
}

DoubleVector Ellipse::GetDerivative(double t)
{
	return { -RadiusX * sin(t), RadiusY * cos(t), 0.0 };
}

Ellipse::Ellipse(double radiusValue1, double radiusValue2)
{
	RadiusX = radiusValue1;
	RadiusY = radiusValue2;
}

Ellipse::~Ellipse()
{
}
