#include "color.h"
#include "interval.h"

namespace simpleRT {
void write_color(std::ostream& out, const color& pixel_color)
{
	auto r = pixel_color.get_x();
	auto g = pixel_color.get_y();
	auto b = pixel_color.get_z();

	// Translate the [0,1] component values to the byte range [0,255].
	static const interval intensity(0.000, 0.999);
	int rbyte = int(256 * intensity.clamp(r));
	int gbyte = int(256 * intensity.clamp(g));
	int bbyte = int(256 * intensity.clamp(b));

	// Write out the pixel color components.
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
}