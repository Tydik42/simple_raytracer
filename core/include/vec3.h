#pragma once

#include <cmath>
#include <iostream>

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


	[[nodiscard]] double length() const { return std::sqrt(length_squared()); }
	[[nodiscard]] double length_squared() const { return get_x()*get_x()+get_y()*get_y()+get_z()*get_z(); }

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
}