#include "Helix.h"

DoubleVector Helix::GetPoint(double t)
{
	return { Radius * cos(t), Radius * sin(t), Step * t };
}

DoubleVector Helix::GetDerivative(double t)
{
	return { -Radius * sin(t), Radius * cos(t), Step };
}

Helix::Helix(double radiusValue, double stepValue)
	: Radius(radiusValue)
	, Step(stepValue)
{
}
