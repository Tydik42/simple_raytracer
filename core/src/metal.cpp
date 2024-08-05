//
// Created by tydik on 04.08.24.
//

#include "metal.h"

namespace simpleRT {

bool metal::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const
{
	vec3 reflected = reflect(r_in.direction(), rec.normal);
	reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
	scattered = ray(rec.p, reflected);
	attenuation = albedo;
	return (dot(scattered.direction(), rec.normal) > 0);
}

metal::metal(const simpleRT::color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

} // simpleRT