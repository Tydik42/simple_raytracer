#pragma once

#include "material.h"
#include "hittable.h"

namespace simpleRT {

class hit_record;

class metal : public material {
public:
	metal(const color& albedo, double fuzz);

	bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
	color albedo;
	double fuzz;
};
} // simpleRT