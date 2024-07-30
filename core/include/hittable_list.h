#pragma once

#include "simplert.h"
#include "hittable.h"

namespace simpleRT {
class hittable_list : public hittable
{
public:
	std::vector<std::shared_ptr<hittable>> objects;

	hittable_list() = default;
	explicit hittable_list(const std::shared_ptr<hittable>& object) { add(object); }

	void clear() { objects.clear(); }
	void add(const std::shared_ptr<hittable>& object) { objects.push_back(object); }

	bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};
}

