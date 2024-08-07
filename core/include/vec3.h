#pragma once

#include <cmath>
#include <iostream>
#include "utils.h"

namespace simpleRT {
class vec3
{
public:
	vec3() :e{0, 0, 0} { }
	vec3(double e0, double e1, double e2) :e{e0, e1, e2} { }

	[[nodiscard]] double get_x() const { return e[0]; }
	[[nodiscard]] double get_y() const { return e[1]; }
	[[nodiscard]] double get_z() const { return e[2]; }

	void set_x(double x) {e[0] = x; }
	void set_y(double y) {e[1] = y; }
	void set_z(double z) {e[2] = z; }

	vec3 operator-() const { return {-get_x(), -get_y(), -get_z()}; }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	[[nodiscard]] double length() const { return std::sqrt(length_squared()); }
	[[nodiscard]] double length_squared() const { return get_x()*get_x()+get_y()*get_y()+get_z()*get_z(); }
	[[nodiscard]] bool near_zero(double s = 1e-8) const { return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s); }

	static vec3 random() {
		return {random_double(), random_double(), random_double()};
	}

	static vec3 random(double min, double max) {
		return {random_double(min,max), random_double(min,max), random_double(min,max)};
	}

	~vec3() = default;

private:
	double e[3];
};

// point3 and color is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;
using color = vec3;


// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.get_x() << ' ' << v.get_y() << ' ' << v.get_z();
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return {u.get_x() + v.get_x(), u.get_y() + v.get_y(), u.get_z() + v.get_z()};
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return {u.get_x() - v.get_x(), u.get_y() - v.get_y(), u.get_z() - v.get_z()};
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return {u.get_x() * v.get_x(), u.get_y() * v.get_y(), u.get_z() * v.get_z()};
}

inline vec3 operator*(double t, const vec3& v) {
	return {t*v.get_x(), t*v.get_y(), t*v.get_z()};
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
	return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.get_x() * v.get_x()
			+ u.get_y() * v.get_y()
			+ u.get_z() * v.get_z();
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return {u.get_y() * v.get_z() - u.get_z() * v.get_y(),
			u.get_z() * v.get_x() - u.get_x() * v.get_z(),
			u.get_x() * v.get_y() - u.get_y() * v.get_x()};
}


inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}

inline vec3 random_in_unit_sphere() {
	while (true) {
		auto p = vec3::random(-1,1);
		if (p.length_squared() < 1)
			return p;
	}
}

inline vec3 random_in_unit_disk() {
	while (true) {
		auto p = vec3(random_double(-1,1), random_double(-1,1), 0);
		if (p.length_squared() < 1)
			return p;
	}
}

inline vec3 random_unit_vector() {
	return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal) {
	vec3 on_unit_sphere = random_unit_vector();
	if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
		return on_unit_sphere;
	else
		return -on_unit_sphere;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2*dot(v,n)*n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
	auto cos_theta = fmin(dot(-uv, n), 1.0);
	vec3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
	vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
	return r_out_perp + r_out_parallel;
}
} // simpleRT