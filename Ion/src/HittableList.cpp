#include "HittableList.h"

HittableList::HittableList()
{
}

HittableList::HittableList(std::shared_ptr<Hittable> object)
{
	Add(object);
}

void HittableList::Clear()
{
	m_Objects.clear();
}

void HittableList::Add(std::shared_ptr<Hittable> object)
{
	m_Objects.push_back(object);
}

bool HittableList::Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const
{
	HitRecord tempRec;
	bool hitAnything = false;
	double closestSoFar = ray_tmax;

	for (const auto& object : m_Objects)
	{
		if (object->Hit(r, ray_tmin, closestSoFar, tempRec))
		{
			hitAnything = true;
			closestSoFar = tempRec.m_T; // tempRec is updated as we passed its ref in the abve Hit() call
			rec = tempRec;
		}
	}

	return hitAnything;
}
