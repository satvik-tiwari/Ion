#include "Sphere.h"

Sphere::Sphere(const RTM::Point3& center, double radius)
	: m_Center(center), m_Radius(radius)
{
}

bool Sphere::Hit(const Ray& r, double rayTmin, double rayTmax, HitRecord& rec) const
{
	//vector from origin of ray to center of sphere
	RTM::Vec3 oc = m_Center - r.GetOrigin();

	// ax^2 + bx + c = 0
	// calcualte a, b, c using quadratic eqation formula
	// if b^2 - 4ac >= 0, it means real roots exist
	// hence intersection has occured
	double a = r.GetDirection().LengthSquared();
	double h = RTM::Dot(r.GetDirection(), oc);
	double c = oc.LengthSquared() - m_Radius * m_Radius;
	double discriminant = h * h - a * c;

	// if < 0 return -1
	if (discriminant < 0)
		return false;

	double sqrtd = sqrt(discriminant);
	// return the closest intersection point t in the acceptable range, 
	// i.e, smallest root in the acceptable range

	double root = (h - sqrtd) / a;

	// if first root is not in range, check for second, if thats not in range, return false
	if (root <= rayTmin || rayTmax <= root)
	{
		root = (h + sqrtd) / a;
		if (root <= rayTmin || rayTmax <= root)
			return false;
	}

	rec.m_T = root;
	rec.m_Point = r.At(rec.m_T); // find the point of intersection using parameteric eqn
								// P(t) = Q + td
	rec.m_Normal = (rec.m_Point - m_Center) / m_Radius; // to normailze nomal for sphere, 
														// we can just divide by radius
														// thus, avoiding square root

	return true;
}
