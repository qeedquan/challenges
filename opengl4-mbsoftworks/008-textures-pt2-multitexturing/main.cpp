#include "lib.h"

struct HouseTransformation
{
	Vec3f position;
	float angle;
};

vector<HouseTransformation> house_transformations{
	{ { -140, 0, 94 }, radians(90.0f) },
	{ { -140, 0, 64 }, radians(90.0f) },
	{ { -140, 0, 34 }, radians(90.0f) },
	{ { -140, 0, 4 }, radians(90.0f) },
	{ { -97, 0, 18 }, radians(-90.0f) },
	{ { -97, 0, 48 }, radians(-90.0f) },
	{ { -97, 0, 78 }, radians(-90.0f) },
	{ { -63, 0, -14 }, radians(180.0f) },
	{ { -33, 0, -14 }, radians(180.0f) },
	{ { -3, 0, -14 }, radians(180.0f) },
	{ { 27, 0, -14 }, radians(180.0f) },
	{ { -75, 0, -64 }, radians(0.0f) },
	{ { -45, 0, -64 }, radians(0.0f) },
	{ { -15, 0, -64 }, radians(0.0f) },
	{ { 15, 0, -64 }, radians(0.0f) },
	{ { 45, 0, -64 }, radians(0.0f) },
	{ { -121, 0, -54 }, radians(45.0f) }
};

class App : public GLWindow
{
public:
	App();
	virtual ~App();

	void begin();
	void event(SDL_Event *ev);
	void render();
	void release();

	void load();

	Shader vertex;
	Shader fragment;
	Program program;

	Shader ground_vertex;
	Shader ground_fragment;
	Program ground_program;

	FlyingCamera camera;
	VBO shapes;
	VBO texcoords;
	GLuint vao;

	Texture snow_texture;
	Texture path_texture;
	Texture pavement_texture;
	Texture house_texture;
	Texture house_texture_front;
	Texture house_texture_side;
	Texture roof_texture;

	Sampler main_sampler;
};

App::App()
{
}

App::~App()
{
}

void App::load()
{
	vertex.load("data/shaders/tut007/shader.vert", GL_VERTEX_SHADER);
	fragment.load("data/shaders/tut007/shader.frag", GL_FRAGMENT_SHADER);
	program.create();
	program.attach(vertex);
	program.attach(fragment);
	program.link();

	ground_vertex.load("data/shaders/tut008/ground_shader.vert", GL_VERTEX_SHADER);
	ground_fragment.load("data/shaders/tut008/ground_shader.frag", GL_FRAGMENT_SHADER);
	ground_program.create();
	ground_program.attach(ground_vertex);
	ground_program.attach(ground_fragment);
	ground_program.link();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	shapes.create();
	shapes.bind();
	shapes.add(static_geometry::plain_ground_vertices, sizeof(static_geometry::plain_ground_vertices));
	shapes.add(static_geometry::cube_vertices, sizeof(static_geometry::cube_vertices));
	shapes.add(static_geometry::pyramid_vertices, sizeof(static_geometry::pyramid_vertices));
	shapes.upload(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), 0);

	texcoords.create();
	texcoords.bind();
	texcoords.add(static_geometry::plain_ground_texcoords, sizeof(static_geometry::plain_ground_texcoords));
	texcoords.add(static_geometry::cube_texcoords, sizeof(static_geometry::cube_texcoords), 6);
	texcoords.add(static_geometry::pyramid_texcoords, sizeof(static_geometry::pyramid_texcoords), 4);

	texcoords.upload(GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (void *)0);

	snow_texture.load("data/textures/snow.png");
	path_texture.load("data/textures/tut008/path.png");
	house_texture.load("data/textures/brick.png");
	house_texture_front.load("data/textures/tut008/house_texture_front.png");
	house_texture_side.load("data/textures/tut008/house_texture_side.png");
	roof_texture.load("data/textures/prismarine_dark.png");
	pavement_texture.load("data/textures/pavement.jpg");

	main_sampler.create();
	main_sampler.bind();
	main_sampler.set_magnification_filter(MAG_FILTER_BILINEAR);
	main_sampler.set_minification_filter(MIN_FILTER_TRILINEAR);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glClearColor(0.0f, 0.28f, 0.57f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ -120.0f, 8.0f, 120.0f }, { -120.0f, 8.0f, 119.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ground_program.use();
	glBindVertexArray(vao);

	ground_program["matrices.projectionMatrix"] = proj;
	ground_program["matrices.viewMatrix"] = camera.get_view_matrix();

	// Render ground
	ground_program["matrices.modelMatrix"] = Mat4f::eye(1.0);

	// Setup snow texture
	snow_texture.bind(0);
	main_sampler.bind(0);
	ground_program["snowSampler"] = 0;

	// Setup path texture
	path_texture.bind(1);
	main_sampler.bind(1);
	ground_program["pathSampler"] = 1;

	// Setup pavement texture
	pavement_texture.bind(2);
	main_sampler.bind(2);
	ground_program["pavementSampler"] = 2;

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	program.use();
	program["matrices.projectionMatrix"] = proj;
	program["matrices.viewMatrix"] = camera.get_view_matrix();
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };

	auto house_bottom_size = 10.0f;
	auto roof_top_size = 12.0f;

	// Render "houses" on the left
	for (auto &house_translation : house_transformations)
	{
		auto house_position = house_translation.position;
		auto angle = house_translation.angle;
		// First, calculate the basic position of house
		auto model_matrix_house = Mat4f::eye(1.0);
		model_matrix_house = Mat4f::translate(model_matrix_house, house_position);

		// Render bottom cube of the house
		auto model_matrix_bottom = Mat4f::translate(model_matrix_house, Vec3f{ 0.0f, house_bottom_size / 2.0f, 0.0f });
		model_matrix_bottom = Mat4f::rotate(model_matrix_bottom, angle, Vec3f{ 0.0f, 1.0f, 0.0f });
		model_matrix_bottom = Mat4f::scale(model_matrix_bottom, Vec3f{ house_bottom_size, house_bottom_size, house_bottom_size });
		program["matrices.modelMatrix"] = model_matrix_bottom;

		// Render just plain house walls made of bricks
		house_texture.bind();
		glDrawArrays(GL_TRIANGLES, 10, 6);
		glDrawArrays(GL_TRIANGLES, 28, 6);
		// Render house wall with a door and windows
		house_texture_front.bind();
		glDrawArrays(GL_TRIANGLES, 4, 6);
		// Render house wall with a window
		house_texture_side.bind();
		glDrawArrays(GL_TRIANGLES, 16, 12);

		roof_texture.bind();
		auto translate_top_y = house_bottom_size + roof_top_size / 2.0f - 0.25f;
		auto model_matrix_top = Mat4f::translate(model_matrix_house, { 0.0f, translate_top_y, 0.0f });
		model_matrix_top = Mat4f::rotate(model_matrix_top, angle, { 0.0f, 1.0f, 0.0f });
		model_matrix_top = Mat4f::scale(model_matrix_top, { roof_top_size, roof_top_size, roof_top_size });
		program["matrices.modelMatrix"] = model_matrix_top;
		glDrawArrays(GL_TRIANGLES, 40, 12);
	}
}

void App::event(SDL_Event *ev)
{
	if (paused)
		return;

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	camera.window_center_position = Vec2i{ w / 2, h / 2 };

	auto key_input = [&](int key) {
		return ev->type == SDL_KEYDOWN && ev->key.keysym.sym == key;
	};
	auto get_cursor_pos = [&]() {
		int x, y;
		SDL_GetMouseState(&x, &y);
		return Vec2i{ x, y };
	};
	auto set_cursor_pos = [&](Vec2i pos) {
		SDL_WarpMouseInWindow(window, pos.x, pos.y);
	};
	auto speed_correction = [&](float f) { return sof(f); };
	camera.update(key_input, get_cursor_pos, set_cursor_pos, speed_correction);
}

void App::release()
{
	program.release();
	vertex.release();
	fragment.release();

	ground_program.release();
	ground_vertex.release();
	ground_fragment.release();

	shapes.release();
	texcoords.release();

	snow_texture.release();
	path_texture.release();
	pavement_texture.release();
	house_texture.release();
	house_texture_front.release();
	house_texture_side.release();
	roof_texture.release();

	main_sampler.release();

	glDeleteVertexArrays(1, &vao);
}

int main()
{
	auto title = "008.) Textures pt. 2 - Multitexturing - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
	auto major = 4;
	auto minor = 4;
	auto fullscreen = false;

	auto app = new App();
	auto ret = app->create(title, major, minor, fullscreen);
	if (ret < 0)
		fatal("Failed to create window: %s", SDL_GetError());
	app->run();
	delete app;
	return 0;
}
