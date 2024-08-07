#pragma once
#include "simplert.h"

#include "hittable.h"
#include "material.h"

namespace simpleRT {
class camera {
public:
	double aspect_ratio      = 1.0;  // Ratio of image width over height
	int    image_width       = 100;  // Rendered image width in pixel count
	int    samples_per_pixel = 10;   // Count of random samples for each pixel
	int    max_depth         = 10;   // Maximum number of ray bounces into scene

	double vfov     = 90;              // Vertical view angle (field of view)
	point3 lookfrom = point3(0,0,0);   // Point camera is looking from
	point3 lookat   = point3(0,0,-1);  // Point camera is looking at
	vec3   vup      = vec3(0,1,0);     // Camera-relative "up" direction

	double defocus_angle = 0;  // Variation angle of rays through each pixel
	double focus_dist = 10;    // Distance from camera lookfrom point to plane of perfect focus

	void render(const hittable& world);

private:
	int    image_height;         // Rendered image height
	double pixel_samples_scale;  // Color scale factor for a sum of pixel samples
	point3 center;               // Camera center
	point3 pixel00_loc;          // Location of pixel 0, 0
	vec3   pixel_delta_u;        // Offset to pixel to the right
	vec3   pixel_delta_v;        // Offset to pixel below
	vec3   u, v, w;              // Camera frame basis vectors
	vec3   defocus_disk_u;       // Defocus disk horizontal radius
	vec3   defocus_disk_v;       // Defocus disk vertical radius

	void initialize();
	[[nodiscard]] color ray_color(const ray& r, int depth, const hittable& world) const;
	[[nodiscard]] ray get_ray(int i, int j) const;
	[[nodiscard]] static vec3 sample_square();
	[[nodiscard]] point3 defocus_disk_sample() const;
};
}