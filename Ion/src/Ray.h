#pragma once

#ifndef Ray_H
#define Ray_H

#include "Point3.h"

class Ray
{
private:
	RTM::Point3 m_Origin;
	RTM::Vec3 m_Direction;

public:
	Ray();
	Ray(const RTM::Point3& orig, const RTM::Vec3& dir);

	inline const RTM::Point3& GetOrigin() const;
	inline const RTM::Vec3& GetDirection() const;

	RTM::Point3 At(double t) const;
};

#endif // !Ray_H
