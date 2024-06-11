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
	
	RTM::Point3 At(double t) const;

	inline const RTM::Point3& GetOrigin() const
	{
		return m_Origin;
	}

	inline const RTM::Vec3& GetDirection() const
	{
		return m_Direction;
	}

};

#endif // !Ray_H
