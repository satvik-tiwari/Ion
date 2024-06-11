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
		Color(const Vec3& vector);

		static void WriteColor(std::ostream& out, const Color& pixel_color);
	};


	inline const Color& operator*(const Color& color, double value)
	{
		auto var = color.X() * value;// , color.Y()* value, color.Z()* value;
		return Color(color.X() * value, color.Y() * value, color.Z() * value);
	}

	inline const Color& operator*(double value, const Color& color)
	{

		return color * value;
	}

	inline const Color& operator+(const Color& color1, const Color& color2)
	{
		return Color(Vec3(color1) + Vec3(color2));
	}
}

#endif // !Color_H
