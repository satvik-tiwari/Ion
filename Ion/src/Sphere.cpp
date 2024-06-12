#include "Sphere.h"

Sphere::Sphere(const RTM::Point3& center, double radius)
	: m_Center(center), m_Radius(radius)
{
}

bool Sphere::Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const
{
	return false;
}
