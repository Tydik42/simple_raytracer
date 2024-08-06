#include "dielectric.h"

namespace simpleRT {
dielectric::dielectric(double refraction_index) :refraction_index(refraction_index) {}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, color& attenuation,
		ray& scattered) const
{
	attenuation = color(1.0, 1.0, 1.0);
	double ri = rec.front_face ? (1.0/refraction_index) : refraction_index;

	vec3 unit_direction = unit_vector(r_in.direction());
	double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
	double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

	bool cannot_refract = ri * sin_theta > 1.0;
	vec3 direction;

	if (cannot_refract || reflectance(cos_theta, ri) > random_double())
		direction = reflect(unit_direction, rec.normal);
	else
		direction = refract(unit_direction, rec.normal, ri);

	scattered = ray(rec.p, direction);
	vec3 refracted = refract(unit_direction, rec.normal, ri);

	scattered = ray(rec.p, refracted);
	return true;
}

} // simpleRT