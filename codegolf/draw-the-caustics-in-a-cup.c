/*

If you have ever consumed liquid from a shallow cup in sunlight, you may have noticed a shape like the following at the bottom:

a heart shaped caustic in the bottom of a white mug
https://i.sstatic.net/7Aqf750e.png

You might notice a nephroid shaped bright outline, a brighter area on the outside of the nephroid, and a diffuse bright spot extending from the cusp of the nephroid.

Your task is to draw this shape.

A clearer rendered example:

caustic
https://i.sstatic.net/TuO8TzJj.png

You can create this shape by bounding parallel horizontal rays off the inside of a circle and counting how many intersect near a point.

A diagram showing rays hitting the inner edge of a semicircle and bouncing off. The tangents create a nephroid shape.

Example code (GLSL):

#define PI 3.1415926538
#define STEPS 3200.0

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.y * 2.0 - vec2(1.0, 1.0);

    if (length(uv) < 1.0) {
        float col = 0.0;
        for (float i = 0.0; i<STEPS; i+=1.0) {
            float y = i/(STEPS / 2.0) - 1.0;
            float x = sqrt(1.0 - y * y);
            float angle = asin(y) * 2.0;

            float slope = tan(angle);
            float dist = abs(slope * (uv.x - x) - (uv.y - y)) / sqrt(slope * slope + 1.0);

            if (dist < 0.005) {
                col+=0.005 - dist;
            }
        }

        fragColor = vec4(col,col*0.5,col*0.25,1.0);
    } else {
        fragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
}
Rules:

Minimum resolution is 512x512
Use at least 16 distinct colors. You are free to pick the color scheme.
All three aspects must be clearly visible: Nephroid rim, bright area on the outside, diffuse bright area near the cusp.
If you use the ray-based approximation, you must use at least 400 rays. You are welcome to use an alternative approach than drawing discrete rays.
Area outside the circle is undefined behavior, it can be any color or pattern
As is standard with graphical-output, you can save the image to a file using any reasonable image format, display it on the screen, or print a representation to the terminal using ANSII escape codes to set the color.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

enum {
	WINDOW_SIZE = 512
};

void
caustic(float x, float y, float rgba[4])
{
	static const float STEPS = 150;

	float dist;
	float angle;
	float slope;
	float col;
	float X, Y;
	float i, u, v;

	rgba[0] = rgba[1] = rgba[2] = 0;
	rgba[3] = 1;

	u = ((x * 2.0) / WINDOW_SIZE) - 1.0;
	v = ((y * 2.0) / WINDOW_SIZE) - 1.0;
	if (hypot(u, v) >= 1)
		return;

	col = 0.0;
	for (i = 0.0; i < STEPS; i += 1.0) {
		Y = i / (STEPS / 2.0) - 1.0;
		X = sqrt(1.0 - Y * Y);
		angle = asin(Y) * 2.0;

		slope = tan(angle);
		dist = fabs(slope * (u - X) - (v - Y)) / sqrt(slope * slope + 1.0);
		if (dist < 0.005)
			col += 0.025 - dist;
	}
	rgba[0] = col;
	rgba[1] = col * 0.5;
	rgba[2] = col * 0.25;
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Cup Caustics", WINDOW_SIZE, WINDOW_SIZE, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_SIZE, WINDOW_SIZE);
	if (!texture) {
		SDL_Log("Couldn't create streaming texture: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *event)
{
	if (event->type == SDL_EVENT_QUIT)
		return SDL_APP_SUCCESS;
	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_Surface *surface;
	float rgba[4];
	int x, y;

	if (SDL_LockTextureToSurface(texture, NULL, &surface)) {
		for (y = 0; y < WINDOW_SIZE; y++) {
			for (x = 0; x < WINDOW_SIZE; x++) {
				caustic(x, y, rgba);
				SDL_WriteSurfacePixelFloat(surface, x, y, rgba[0], rgba[1], rgba[2], rgba[3]);
			}
		}
		SDL_UnlockTexture(texture);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
	SDL_DestroyTexture(texture);
}
