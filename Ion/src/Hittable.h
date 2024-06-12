#pragma once

#ifndef Hittable_H
#define Hittable_H

#include "Ray.h"

class HitRecord
{
public:
	RTM::Point3 m_Point;
	RTM::Vec3 m_Normal;
	double m_T;
};

class Hittable
{
public:
	virtual ~Hittable() = default;

	virtual bool Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const = 0;
 };

#endif // !Hittable_H
