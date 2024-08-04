//
// Created by tydik on 04.08.24.
//

#include "metal.h"

namespace simpleRT {

bool metal::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const
{
	vec3 reflected = reflect(r_in.direction(), rec.normal);
	scattered = ray(rec.p, reflected);
	attenuation = albedo;
	return true;
}

metal::metal(const simpleRT::color& albedo) : albedo(albedo) {}

} // simpleRT