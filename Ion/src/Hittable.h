#pragma once

#ifndef Hittable_H
#define Hittable_H

// recording the attributes of the hit attributes of the object
class HitRecord
{
public:
	RTM::Point3 m_Point;  // hit point of the ray and object
	RTM::Vec3 m_Normal;   // normal at hit point
	double m_T;           // root
	bool m_FrontFace;	  // is ray intersecting the sphere from outside or inside, front face = outside

	void SetFaceNormal(const Ray& r, const RTM::Vec3& outwardNormal); // sets the hit record normal vector
};

// generic object called hittable
class Hittable
{
public:
	virtual ~Hittable() = default;
	virtual bool Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const = 0;
 };

#endif // !Hittable_H
