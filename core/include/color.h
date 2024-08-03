#pragma once

#include "vec3.h"

namespace simpleRT {

inline double linear_to_gamma(double linear_component);

void write_color(std::ostream& out, const color& pixel_color);
}