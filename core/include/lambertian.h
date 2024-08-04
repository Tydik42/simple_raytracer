#pragma once

#include "material.h"
#include "hittable.h"

namespace simpleRT {

class hit_record;

class lambertian : public material
{
public:
	explicit lambertian(const color& albedo);

	bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
private:
	color albedo;
};

} // simpleRT
