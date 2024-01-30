#include <cmath>
#include "Circle.h"


double Circle::GetRadius()
{
	return Radius;
}

DoubleVector Circle::GetPoint(double t)
{
	return { Radius * cos(t), Radius * sin(t), 0.0 };
}

DoubleVector Circle::GetDerivative(double t)
{
	return { -Radius * sin(t), Radius * cos(t), 0.0 };
}

Circle::Circle(double radiusValue)
{
	Radius = radiusValue;
}

Circle::~Circle()
{
}
