#pragma once

#include "material.h"
#include "hittable.h"

namespace simpleRT {

class dielectric : public material
{
public:
	dielectric(double refraction_index);

	bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
	// Refractive index in vacuum or air, or the ratio of the material's refractive index over
	// the refractive index of the enclosing media
	double refraction_index;

	static double reflectance(double cosine, double refraction_index)
	{
		// Use Schlick's approximation for reflectance.
		auto r0 = (1 - refraction_index) / (1 + refraction_index);
		r0 = r0*r0;
		return r0 + (1-r0)*pow((1 - cosine),5);
	}
};

} // simpleRT
