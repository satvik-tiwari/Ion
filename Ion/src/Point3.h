#pragma once

#ifndef Point_H
#define Point_H

#include "Vec3.h"

namespace RTM
{
	class Point : public Vec3
	{
	public:
		Point();
		Point(double e0, double e1, double e2);
	};
}

#endif // !Point_H

