#pragma once

#ifndef Color_H
#define Color_H

#include "Vec3.h"

namespace RTM
{
	class Color : public Vec3
	{
	public:
		Color();
		Color(double e0, double e1, double e2);

		void WriteColor(std::ostream& out, const Color& pixel_color);
	};
}

#endif // !Color_H
