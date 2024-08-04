#pragma once

#include <utility>

#include "simplert.h"
#include "hittable.h"

namespace simpleRT {
class sphere : public hittable
{
public:
	sphere(const point3& center, double radius, std::shared_ptr<material> mat)
			: center(center), radius(fmax(0,radius)), mat(std::move(mat)) {}

	bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

private:
	point3 center;
	double radius;
	std::shared_ptr<material> mat;
};
}