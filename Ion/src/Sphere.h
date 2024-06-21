#pragma once

#ifndef Sphere_H
#define Sphere_H

#include "Hittable.h"

class Sphere : public Hittable
{
private:
	RTM::Point3 m_Center;
	double m_Radius;
public:
	Sphere(const RTM::Point3& center, double radius);
	bool Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override;

};

#endif // !Sphere_H

