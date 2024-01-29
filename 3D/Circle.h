#pragma once
#include <vector>
#include "Curve.h"

class Circle : public Curve
{
private:
	double Radius;

public:

	DoubleVector GetPoint(double t) override;
	DoubleVector GetDerivative(double t) override;

	Circle(double radiusValue);
	~Circle();

};

