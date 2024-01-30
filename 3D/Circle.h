#pragma once
#include <vector>
#include "Curve.h"

class Circle : public Curve
{
private:
	double Radius;

public:

	double GetRadius();
	DoubleVector GetPoint(double t) override;
	DoubleVector GetDerivative(double t) override;

	Circle(double radiusValue);
	~Circle();

};

