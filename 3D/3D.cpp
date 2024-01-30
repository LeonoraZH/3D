#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <typeinfo>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
using namespace std;


int GetRandomNumber(int start, int stop);
double getRandomDouble(double min, double max);
vector<unique_ptr<Curve>> FillContainerWithCurves(size_t size);
void DisplayVector(vector<double> vec, size_t size);


int main()
{
	const size_t containerSize = 20;
	vector<unique_ptr<Curve>> curves = FillContainerWithCurves(containerSize);

	double t = 0.785397;

	for (const auto& curve : curves)
	{
		cout << "For " << typeid(*curve).name() + 6 << ":" << endl;

		cout << "Coordinats of point are ";
		DisplayVector(curve->GetPoint(t), 3);

		cout << "Coordinats of derivative are ";
		DisplayVector(curve->GetDerivative(t), 3);
		cout << endl;
	}

	vector<Circle*> circles;
	for (const auto& curve : curves)
	{
		if (auto* circle = dynamic_cast<Circle*>(curve.get()))
			circles.push_back(circle);
	}

	cout << circles.size() << endl;

	sort(circles.begin(), circles.end(), [](const auto& a, const auto& b)
		{
			return a->GetRadius() < b->GetRadius();
		});

	double radiiSum = 0.0;
	for (const auto& circle : circles) {
		radiiSum += circle->GetRadius();
	}


	return 0;
}

int GetRandomNumber(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}

double getRandomDouble(double min, double max) {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<double> distr(min, max);
	return distr(eng);
}

vector<unique_ptr<Curve>> FillContainerWithCurves(size_t size)
{
	vector<unique_ptr<Curve>> curves;

	for (size_t i = 0; i < size; i++)
	{
		const int typeCurve = GetRandomNumber(1, 3);

		switch (typeCurve)
		{
		case(1):
			curves.push_back(make_unique<Circle>(getRandomDouble(3, 5)));
			break;
		case(2):
			curves.push_back(make_unique<Ellipse>(getRandomDouble(3, 5), getRandomDouble(3, 5)));
			break;
		case(3):
			curves.push_back(make_unique<Helix>(getRandomDouble(3, 5), getRandomDouble(1, 3)));
			break;
		default:
			break;
		}

	}
	return curves;
}

void DisplayVector(vector<double> vec, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
