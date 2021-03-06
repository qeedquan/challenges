#include "lib.h"

color ray_color(const ray &r, const hittable &world)
{
	hit_record rec;
	if (world.hit(r, 0, infinity, rec))
	{
		return 0.5 * (rec.normal + color(1, 1, 1));
	}
	vec3 unit_direction = normalize(r.direction);
	auto t = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void render(int width, int height, int samples_per_pixel)
{
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, nullptr));

	camera cam(width, height);

	printf("P3\n");
	printf("%d\n%d\n%d\n", width, height, 255);
	for (int y = height - 1; y >= 0; y--)
	{
		fprintf(stderr, "Scanlines remaining: %d\n", y + 1);
		for (int x = 0; x < width; x++)
		{
			color pixel_color(0, 0, 0);
			for (int s = 0; s < samples_per_pixel; s++)
			{
				auto u = (x + random_double()) / (width - 1);
				auto v = (y + random_double()) / (height - 1);
				ray r = cam.get_ray(u, v);
				pixel_color += ray_color(r, world);
			}
			write_color(stdout, pixel_color, samples_per_pixel, 1);
		}
	}
}

int main()
{
	seed_rng();
	render(1024, 576, 100);
	return 0;
}