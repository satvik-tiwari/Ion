#include "Color.h"

RTM::Color::Color()
	: Vec3()
{
}

RTM::Color::Color(double e0, double e1, double e2)
	: Vec3(e0, e1, e2)
{
}

RTM::Color::Color(const Vec3& vector)
	: Vec3(vector)
{
}


void RTM::Color::WriteColor(std::ostream& out, const RTM::Color& pixel_color)
{
	double r = pixel_color.X();
	double g = pixel_color.Y();
	double b = pixel_color.Z();

	//map rgb values from 0-1 to 0-255
	int rbyte = int(r * 255.999);
	int gbyte = int(g * 255.999);
	int bbyte = int(b * 255.999);

	//write out the pixel color componenets
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';

}
