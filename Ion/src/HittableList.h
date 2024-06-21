#pragma once

#ifndef HittableList_H
#define HittableList_H

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable
{
private:
	std::vector<std::shared_ptr<Hittable>> m_Objects;

public :
	HittableList();
	HittableList(std::shared_ptr<Hittable> object);
	
	void Clear();
	void Add(std::shared_ptr<Hittable> object);
	bool Hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override;
};

#endif // !HittableList_H
