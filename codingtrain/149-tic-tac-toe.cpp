/*

https://en.wikipedia.org/wiki/Tic-tac-toe

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstdarg>
#include <algorithm>
#include <array>
#include <vector>
#include <SDL3/SDL.h>
#include <cairo.h>

using namespace std;

struct XO
{
	vector<array<int, 2> > available;
	int board[3][3];
	int current_player;
	int players[2];

	void reset();
	int check_winner();
	void next_turn();
	void draw(cairo_t *cr, double width, double height);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	XO xo;

	bool done;

	Uint64 start;
	bool paused;

	double width, height;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void update();
	void upload();
	void draw();
};

bool equals3(int a, int b, int c)
{
	return a == b && b == c && a != 0;
}

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void draw_circle(cairo_t *cr, double x, double y, double r)
{
	cairo_arc(cr, x, y, r, 0, 2 * SDL_PI_D);
	cairo_stroke(cr);
}

void draw_line(cairo_t *cr, double x1, double y1, double x2, double y2)
{
	cairo_move_to(cr, x1, y1);
	cairo_line_to(cr, x2, y2);
	cairo_stroke(cr);
}

void XO::reset()
{
	memset(board, 0, sizeof(board));
	current_player = SDL_rand(SDL_arraysize(players));
	players[0] = 'X';
	players[1] = 'O';

	available.clear();
	for (auto j = 0; j < 3; j++)
	{
		for (auto i = 0; i < 3; i++)
			available.push_back({ i, j });
	}
}

int XO::check_winner()
{
	for (auto i = 0; i < 3; i++)
	{
		if (equals3(board[i][0], board[i][1], board[i][2]))
			return board[i][0];
	}

	for (auto i = 0; i < 3; i++)
	{
		if (equals3(board[0][i], board[1][i], board[2][i]))
			return board[0][i];
	}

	if (equals3(board[0][0], board[1][1], board[2][2]))
		return board[0][0];

	if (equals3(board[2][0], board[1][1], board[0][2]))
		return board[2][0];

	if (available.size() == 0)
		return 'T';

	return 0;
}

void XO::next_turn()
{
	auto index = SDL_rand(available.size());
	auto &spot = available[index];
	auto i = spot[0];
	auto j = spot[1];
	board[i][j] = players[current_player];
	current_player = (current_player + 1) % SDL_arraysize(players);
	available.erase(available.begin() + index);
}

void XO::draw(cairo_t *cr, double width, double height)
{
	auto w = width / 3;
	auto h = height / 3;

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_paint(cr);

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width(cr, 4);
	draw_line(cr, w, 0, w, height);
	draw_line(cr, w * 2, 0, w * 2, height);
	draw_line(cr, 0, h, width, h);
	draw_line(cr, 0, h * 2, width, h * 2);

	for (auto j = 0; j < 3; j++)
	{
		for (auto i = 0; i < 3; i++)
		{
			auto x = w * i + w / 2;
			auto y = h * j + h / 2;
			auto spot = board[i][j];
			if (spot == players[1])
				draw_circle(cr, x, y, w / 4);
			else if (spot == players[0])
			{
				auto xr = w / 4;
				draw_line(cr, x - xr, y - xr, x + xr, y + xr);
				draw_line(cr, x + xr, y - xr, x - xr, y + xr);
			}
		}
	}
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
	if (!SDL_CreateWindowAndRenderer("Tic Tac Toe", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);
}

void App::reset()
{
	xo.reset();
	done = false;
	start = SDL_GetTicks();
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
			case SDLK_RETURN:
				paused = !paused;
				break;
			case SDLK_SPACE:
				reset();
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}
}

void App::update()
{
	if (done)
		return;

	auto now = SDL_GetTicks();
	if (now - start < 50)
		return;
	start = now;

	if (paused)
		return;

	auto result = xo.check_winner();
	if (result)
	{
		printf("Outcome: %c\n", result);
		done = true;
	}
	else
		xo.next_turn();
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

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	xo.draw(cr, width, height);

	upload();

	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	SDL_srand(time(NULL));
	auto app = new App();
	app->init();
	app->reset();
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
