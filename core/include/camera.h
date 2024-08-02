#pragma once
#include "simplert.h"
#include "hittable.h"

namespace simpleRT {
class camera {
public:
	double aspect_ratio = 1.0;  // Ratio of image width over height
	int    image_width  = 100;  // Rendered image width in pixel count
	int    samples_per_pixel = 10;   // Count of random samples for each pixel

	void render(const hittable& world);

private:
	int    image_height;   // Rendered image height
	point3 center;         // Camera center
	point3 pixel00_loc;    // Location of pixel 0, 0
	vec3   pixel_delta_u;  // Offset to pixel to the right
	vec3   pixel_delta_v;  // Offset to pixel below
	double pixel_samples_scale; // Color scale factor for a sum of pixel samples

	void initialize();
	[[nodiscard]] color ray_color(const ray& r, const hittable& world) const;
	[[nodiscard]] ray get_ray(int i, int j) const;
	[[nodiscard]] vec3 sample_square() const;
};
}