/*

Implement 3D rendering using only 2D functions

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

typedef struct {
	float x, y, z;
} Vec3;

typedef float Mat3[3][3];

enum {
	WINDOW_WIDTH = 600,
	WINDOW_HEIGHT = 400,
};

SDL_Window *window;
SDL_Renderer *renderer;

float angle;
bool paused;

Vec3
add3(Vec3 vector0, Vec3 vector1)
{
	return (Vec3){
		vector0.x + vector1.x,
		vector0.y + vector1.y,
		vector0.z + vector1.z,
	};
}

Vec3
xform(Mat3 matrix, Vec3 vector)
{
	return (Vec3){
		matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
		matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
		matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z,
	};
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("3D Rendering with Rotation and Projection", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *event)
{
	switch (event->type) {
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.key) {
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_SPACE:
			paused = !paused;
			break;
		}
		break;
	}
	return SDL_APP_CONTINUE;
}

void
draw_connection(int i, int j, Vec3 *points)
{
	Vec3 origin = { WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0, 0 };
	Vec3 a = add3(points[i], origin);
	Vec3 b = add3(points[j], origin);

	SDL_RenderLine(renderer, a.x, a.y, b.x, b.y);
}

void
draw_cube(float angle)
{
	static const Vec3 points[] = {
		{ -0.5, -0.5, -0.5 },
		{ 0.5, -0.5, -0.5 },
		{ 0.5, 0.5, -0.5 },
		{ -0.5, 0.5, -0.5 },
		{ -0.5, -0.5, 0.5 },
		{ 0.5, -0.5, 0.5 },
		{ 0.5, 0.5, 0.5 },
		{ -0.5, 0.5, 0.5 },
	};

	float co = cos(angle);
	float si = sin(angle);

	Mat3 rotationZ = {
		{ co, -si, 0 },
		{ si, co, 0 },
		{ 0, 0, 1 },
	};

	Mat3 rotationX = {
		{ 1, 0, 0 },
		{ 0, co, -si },
		{ 0, si, co },
	};

	Mat3 rotationY = {
		{ co, 0, si },
		{ 0, 1, 0 },
		{ -si, 0, co },
	};

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	Vec3 projected[8];
	for (size_t i = 0; i < SDL_arraysize(points); i++) {
		Vec3 rotated = xform(rotationY, points[i]);
		rotated = xform(rotationX, rotated);
		rotated = xform(rotationZ, rotated);
		float distance = 2;
		float z = 1 / (distance - rotated.z);
		Mat3 projection = {
			{ z, 0, 0 },
			{ 0, z, 0 },
			{ 0, 0, 1 },
		};

		Vec3 projected2d = xform(projection, rotated);
		projected2d.x *= 200;
		projected2d.y *= 200;
		projected[i] = projected2d;
	}

	float pointsize = 10;
	Vec3 origin = { (WINDOW_WIDTH - pointsize) / 2.0, (WINDOW_HEIGHT - pointsize) / 2.0, 0 };
	for (size_t i = 0; i < SDL_arraysize(projected); i++) {
		Vec3 point = add3(projected[i], origin);
		SDL_FRect rect = { point.x, point.y, pointsize, pointsize };
		SDL_RenderFillRect(renderer, &rect);
	}

	for (int i = 0; i < 4; i++) {
		draw_connection(i, (i + 1) % 4, projected);
		draw_connection(i + 4, ((i + 1) % 4) + 4, projected);
		draw_connection(i, i + 4, projected);
	}
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw_cube(angle);
	SDL_RenderPresent(renderer);

	if (!paused)
		angle = fmod(angle + 8e-5, 2 * SDL_PI_F);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
