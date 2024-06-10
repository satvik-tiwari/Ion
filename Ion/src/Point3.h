#pragma once

#ifndef Point3_H
#define Point3_H

#include "Vec3.h"

namespace RTM
{
	class Point3 : public Vec3
	{
	public:
		Point3();
		Point3(double e0, double e1, double e2);
		Point3(const Vec3& vector);

	};
}

#endif // !Point3_H

