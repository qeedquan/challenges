/*

https://en.wikipedia.org/wiki/L-system

*/

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <SDL3/SDL.h>
#include <cairo.h>

#define deg2rad(x) ((x) * SDL_PI_D / 180)

using namespace std;

struct Vec2d
{
	double x, y;
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	double length;
	double angle;
	string axiom;
	string sentence;

	unordered_map<char, string> rules;

	int width, height;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void generate();

	void render();

	void event();
	void upload();
	void draw();
};

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	if (canvas)
	{
		cairo_surface_destroy(canvas);
		cairo_destroy(cr);
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	canvas = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(canvas);
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Fractal Trees: L System", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	resize(width, height);
}

void App::reset()
{
	angle = deg2rad(25);
	length = 150;

	axiom = "F";
	sentence = axiom;
	rules = {
		{ 'F', "FF+[+F-F-F]-[-F+F+F]" },
	};

	cout << sentence << endl;
	render();
}

void App::event()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key)
			{
			case SDLK_ESCAPE:
				exit(0);
			case SDLK_SPACE:
				reset();
				break;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			generate();
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			render();
			break;
		}
	}
}

void App::generate()
{
	length /= 2;

	string next = "";
	for (auto current : sentence)
	{
		auto it = rules.find(current);
		if (it == rules.end())
			next += current;
		else
			next += it->second;
	}
	sentence = next;
	cout << sentence << endl;

	render();
}

void App::upload()
{
	void *pixels, *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void App::render()
{
	cairo_set_source_rgb(cr, 0.2, 0.2, 0.2);
	cairo_paint(cr);

	cairo_set_line_width(cr, 2);
	cairo_set_source_rgba(cr, 0.6, 0.6, 0.6, 0.39);
	cairo_identity_matrix(cr);
	cairo_move_to(cr, width / 2, height);

	vector<Vec2d> locations;
	Vec2d position;
	for (auto current : sentence)
	{
		switch (current)
		{
		case 'F':
			cairo_rel_line_to(cr, 0, -length);
			cairo_stroke_preserve(cr);
			break;

		case '+':
			cairo_rotate(cr, angle);
			break;

		case '-':
			cairo_rotate(cr, -angle);
			break;

		case '[':
			cairo_get_current_point(cr, &position.x, &position.y);
			locations.push_back(position);
			cairo_save(cr);
			break;

		case ']':
			position = locations.back();
			locations.pop_back();
			cairo_restore(cr);
			cairo_move_to(cr, position.x, position.y);
			break;

		default:
			assert(0);
		}
	}
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	upload();

	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	app->reset();
	for (;;)
	{
		app->event();
		app->draw();
	}

	return 0;
}
