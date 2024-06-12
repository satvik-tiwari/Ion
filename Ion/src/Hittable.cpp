#include "Hittable.h"

void HitRecord::SetFaceNormal(const Ray& r, const RTM::Vec3& outwardNormal)
{
	// sets the hit record normal vector
	// the 'parameter outwardNormal' is asssumed to have normalized length

	m_FrontFace = RTM::Dot(r.GetDirection(), outwardNormal) < 0; // if dot product < 0, opposite direction, otherwise same - meaning ray is hitting from inside the surface
	m_Normal = m_FrontFace ? outwardNormal : -outwardNormal; 
}
