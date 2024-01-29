#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
private:
	double RadiusX;
	double RadiusY;

public:
	DoubleVector GetPoint(double t) override;
	DoubleVector GetDerivative(double t) override;

	Ellipse(double radiusValueX, double radiusValueY);
	~Ellipse();

};

