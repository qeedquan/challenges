/*

https://www.maths.tcd.ie/~lebed/Galperin.%20Playing%20pool%20with%20pi.pdf
https://www.youtube.com/watch?v=6dTyOl1fmDo
https://arxiv.org/pdf/1912.02207
https://archive.nytimes.com/wordplay.blogs.nytimes.com/2014/03/10/pi/

*/

#define STB_IMAGE_IMPLEMENTATION
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <chrono>
#include <vector>
#include <random>
#include <SDL3/SDL.h>
#include "stb_image.h"

using namespace std;

struct Block
{
	double x;
	double y;
	double w;
	double v;
	double m;
	double xc;

	void init(double x, double w, double m, double v, double xc, double height);
	bool hit_wall();
	void reverse();
	bool collide(const Block &other);
	double bounce(const Block &other);
	void update();
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width, height;

	SDL_AudioStream *stream;
	Uint8 *wav_data;
	Uint32 wav_len;

	long count;
	int digits;
	long timesteps;

	SDL_Texture *block_image;
	int block_width;
	int block_height;

	Block block1;
	Block block2;

	Uint64 start;
	bool paused;

	void init();
	void reset();

	void event();
	void update();
	void draw_block(Block &block);
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

SDL_Texture *load_image(SDL_Renderer *re, const char *name, int &width, int &height)
{
	int comp;
	auto data = stbi_load(name, &width, &height, &comp, STBI_default);
	if (!data)
		fatal("Failed to load image: %s", name);

	auto texture = SDL_CreateTexture(re, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	SDL_UpdateTexture(texture, NULL, data, width * comp);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	free(data);

	return texture;
}

void Block::init(double x, double w, double m, double v, double xc, double height)
{
	this->x = x;
	this->y = height - w;
	this->w = w;
	this->v = v;
	this->m = m;
	this->xc = xc;
}

bool Block::hit_wall()
{
	return x <= 0;
}

void Block::reverse()
{
	v *= -1;
}

bool Block::collide(const Block &other)
{
	return !(x + w < other.x || x > other.x + other.w);
}

double Block::bounce(const Block &other)
{
	auto sumM = m + other.m;
	auto newV = (m - other.m) / sumM * v;
	newV += (2 * other.m / sumM) * other.v;
	return newV;
}

void Block::update()
{
	x += v;
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 200;
	auto wflag = 0;
	if (!SDL_CreateWindowAndRenderer("PI Collision", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	SDL_AudioSpec spec;
	if (!SDL_LoadWAV("clack.wav", &spec, &wav_data, &wav_len))
		fatal("Couldn't load .wav file: %s", SDL_GetError());

	stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
	if (!stream)
		fatal("Couldn't create audio stream: %s", SDL_GetError());

	SDL_ResumeAudioStreamDevice(stream);

	block_image = load_image(renderer, "block.png", block_width, block_height);
}

void App::reset()
{
	start = SDL_GetTicks();
	count = 0;
	digits = 7;
	timesteps = pow(10, digits - 1);

	block1.init(100, 20, 1, 0, 0, height);

	double m2 = pow(100, digits - 1);
	block2.init(500, 100, m2, -1.0 / timesteps, 20, height);
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
			case SDLK_RETURN:
				paused = !paused;
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			width = ev.window.data1;
			height = ev.window.data2;
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 16)
		return;
	start = now;

	auto clack_sound = false;
	for (long i = 0; i < timesteps; i++)
	{
		if (block1.collide(block2))
		{
			auto v1 = block1.bounce(block2);
			auto v2 = block2.bounce(block1);
			block1.v = v1;
			block2.v = v2;
			clack_sound = true;
			count++;
		}

		if (block1.hit_wall())
		{
			block1.reverse();
			clack_sound = true;
			count++;
		}

		block1.update();
		block2.update();
	}

	if (clack_sound)
		SDL_PutAudioStreamData(stream, wav_data, wav_len);
}

void App::draw_block(Block &block)
{
	float x = clamp(block.x, block.xc, width * 1.0);
	float y = block.y;
	float w = block.w;
	SDL_FRect dstrect = SDL_FRect{ x, y, w, w };
	SDL_RenderTexture(renderer, block_image, NULL, &dstrect);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);

	draw_block(block1);
	draw_block(block2);

	char text[32];
	snprintf(text, sizeof(text), "%0*ld", digits, count);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDebugText(renderer, 8, 8, text);

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
		app->update();
		app->draw();
	}

	return 0;
}
