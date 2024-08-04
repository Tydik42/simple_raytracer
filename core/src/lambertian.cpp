#include "lambertian.h"

namespace simpleRT {

bool lambertian::scatter(const ray& r_in, const hit_record& rec, color& attenuation,
		simpleRT::ray& scattered) const
{
	auto scatter_direction = rec.normal + random_unit_vector();
	if (scatter_direction.near_zero())
		scatter_direction = rec.normal;
	scattered = ray(rec.p, scatter_direction);
	attenuation = albedo;
	return true;
}

lambertian::lambertian(const color& albedo) : albedo(albedo) {}

} // simpleRT