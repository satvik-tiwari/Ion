#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const RTM::Point3& orig, const RTM::Vec3& dir)
	: m_Origin(orig), m_Direction(dir)
{
}

RTM::Point3 Ray::At(double t) const
{
	//P(t) = a + tb
	return RTM::Point3((RTM::Vec3)m_Origin + t * m_Direction);
}
