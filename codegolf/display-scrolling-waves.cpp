/*

The challenge is to display and scroll a sine waveform in the least number of characters.

Restrictions:

Total height of wave must be at least seven units (characters, pixels, etc).
The generated wave must scroll in-place.
Additional Rules/Information:

The sine wave must be distinguishable from triangle and square waves.
"distinguishable" indicates sampling at least every π/8
Additional Judgement Criteria:

Appearance/Quality of the wave
Number of periods displayed
Winning entries will have the fewest characters of code and generate a sine wave with the most samples per period.

*/

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <cmath>
#include <iostream>
#include <getopt.h>
#include <SDL3/SDL.h>

using namespace std;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

[[noreturn]]
void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	exit(1);
}

struct Wave
{
	double phase;
	double amplitude;
	double speed;
	double freq;

	Wave(double phase, double amplitude, double speed, double freq)
		: phase(phase), amplitude(amplitude), speed(speed), freq(freq)
	{
	}

	void update_and_render(SDL_Renderer *renderer, float dt)
	{
		int w, h;
		SDL_GetRenderOutputSize(renderer, &w, &h);

		auto a = w / (4 * SDL_PI_D);
		auto b = w / 2.0;

		// linear remap from [-2pi, 2pi] to screen and then
		// draw it with phase shifted to see it move
		for (auto t = -2 * SDL_PI_D; t <= 2 * SDL_PI_D; t += 0.001)
		{
			auto x = a * t + b;
			auto y = amplitude * sin(freq * (t + phase)) + h / 2;

			SDL_SetRenderDrawColor(renderer, 128, 96, 64, 255);
			SDL_RenderPoint(renderer, x, y);
		}
		phase += dt * speed;
	}
};

struct Options
{
	static constexpr auto default_width = 800;
	static constexpr auto default_height = 600;
	static constexpr auto default_phase = 0.0;
	static constexpr auto default_amplitude = 50.0;
	static constexpr auto default_speed = 0.5;
	static constexpr auto default_freq = 1.0;

	int width;
	int height;

	double phase;
	double amplitude;
	double speed;
	double freq;

	Options(int argc, char *argv[])
	{
		width = default_width;
		height = default_height;
		phase = default_phase;
		amplitude = default_amplitude;
		speed = default_speed;
		freq = default_freq;
		parse(argc, argv);
	}

	void parse(int argc, char *argv[])
	{
		int opt;
		while ((opt = getopt(argc, argv, "w:h:p:a:s:f:")) != -1)
		{
			switch (opt)
			{
			case 'w':
				width = atoi(optarg);
				break;

			case 'h':
				height = atoi(optarg);
				break;

			case 'p':
				phase = atof(optarg);
				break;

			case 'a':
				amplitude = atof(optarg);
				break;

			case 's':
				speed = atof(optarg);
				break;

			case 'f':
				freq = atof(optarg);
				break;

			default:
				fprintf(stderr, "usage:\n");
				fprintf(stderr, "\t-w width default=%d\n", default_width);
				fprintf(stderr, "\t-h height default=%d\n", default_height);
				fprintf(stderr, "\t-p phase default=%lf\n", default_phase);
				fprintf(stderr, "\t-a amplitude default=%lf\n", default_amplitude);
				fprintf(stderr, "\t-s speed default=%lf\n", default_speed);
				fprintf(stderr, "\t-f freq default=%lf\n", default_freq);
				exit(1);
			}

			auto check = [](auto &x, auto def, const auto &what) {
				if (x <= 0 && x != def)
				{
					cout << "invalid value for " << what << ", using default of " << def << endl;
					x = def;
				}
			};

			check(width, default_width, "width");
			check(height, default_height, "height");
			check(phase, default_phase, "phase");
			check(amplitude, default_amplitude, "amplitude");
			check(speed, default_speed, "speed");
			check(freq, default_freq, "freq");
		}
	}
};

int main(int argc, char *argv[])
{
	Options opt(argc, argv);

	SDL_Window *window;
	SDL_Renderer *renderer;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	if (!SDL_CreateWindowAndRenderer("Scrolling Wave", opt.width, opt.height, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	Wave wave(opt.phase, opt.amplitude, opt.speed, opt.freq);

	auto then = SDL_GetTicks();
	for (;;)
	{
		auto now = SDL_GetTicks();
		auto tick = now - then;
		then = now;

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
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
		SDL_RenderClear(renderer);

		auto dt = ((float)tick / 1e2f);
		wave.update_and_render(renderer, dt);
		SDL_RenderPresent(renderer);

		if (tick < 1000 / 60)
			SDL_Delay(1000 / 60 - tick);
	}

	return 0;
}
