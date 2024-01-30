#pragma once
#include <vector>
typedef std::vector<double> DoubleVector;

class Curve
{
public:
	virtual DoubleVector GetPoint(double t) = 0;
	virtual DoubleVector GetDerivative(double t) = 0;

	virtual ~Curve()
	{
	}
};

