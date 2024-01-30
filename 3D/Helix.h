#pragma once
#include "Curve.h"

class Helix : public Curve
{
	double Radius;
	double Step;

public:
	DoubleVector GetPoint(double t) override;
	DoubleVector GetDerivative(double t) override;

	Helix(double radiusValue, double stepValue);
};

