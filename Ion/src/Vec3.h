#pragma once

#ifndef Vec3_H
#define Vec3_H

#include <cmath>
#include <iostream>

using std::sqrt;

namespace RTM //raytracing maths library
{
	class Vec3
	{
	public:
		double m_E[3];
	
	public:
		Vec3();
		Vec3(double e0, double e1, double e2);

		double X() const;
		double Y() const;
		double Z() const;

		Vec3 operator-() const;
		double operator[](int i) const;
		double& operator[](int i);

		Vec3& operator+=(const Vec3& v);
		Vec3& operator*=(double t);
		Vec3& operator/=(double t);

		//magnitude of vector
		double Length() const;
		double LengthSquared() const; //addition of squared components
	};
}

#include "Vec3.inl"

#endif // !Vec3_H
