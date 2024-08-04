#include "simplert.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "lambertian.h"
#include "metal.h"

using namespace simpleRT;

int main() {
	hittable_list world;

	auto material_ground = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
	auto material_center = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
	auto material_left   = std::make_shared<metal>(color(0.8, 0.8, 0.8));
	auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2));

	world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
	world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
	world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width  = 1600;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.render(world);
}