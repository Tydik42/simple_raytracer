#pragma once

#include "simplert.h"

namespace simpleRT {
class interval {
public:
	double min, max;

	interval() : min(+infinity), max(-infinity) {} // Default interval is empty

	interval(double min, double max) : min(min), max(max) {}

	[[nodiscard]] double size() const {
		return max - min;
	}

	[[nodiscard]] bool contains(double x) const {
		return min <= x && x <= max;
	}

	[[nodiscard]] bool surrounds(double x) const {
		return min < x && x < max;
	}

};
const interval empty    = interval(+infinity, -infinity);
const interval universe = interval(-infinity, +infinity);
}
