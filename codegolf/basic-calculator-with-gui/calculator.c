/*

I recently had to add a small basic calculator to a project. I wrote a quick dirty one, but it seemed small enough to check with you people out here ;)

Just out of curiosity & an appetite to get surprised for some real hacky solutions, try and beat this one :

CODE (JS/JQUERY):

function scalcy() {
    var b="", p=parseFloat,t,i;
    return $("<div>").append("789/456*123-.0=+".split("").map(function(i){
        return $("<button/>").text(i).width(32).height(32).click(function(){
        b = (!p(i=$(this).text())? b.replace(/\D+$/,""): b) + i;
        t.val(((!(i.match(/[.\d]/))? (b=eval(b.slice(0,-1))+i+"").slice(0,-1):
                p(b.match(/[.\d]+/g).pop()) || 0) + "").slice(0,8));
    })})).prepend(t=$("<input/>").width(123).click(function(){
        this.value=b="0";})).width(130);
}
Screenshot (in chrome): (DEMO)

https://i.sstatic.net/XaMVE.png


Considerations: Better the UI & lesser the bugs, the better.

Minimum Functionalities:

Supports floating point arithmetic (/ * - +),
Reset feature,
Continuous Operation (like working on with the last result)
Note:

Use any language & library, but please not a library call like new calculator().
Forking the above code itself is most welcome.
Additional Notes:

A graphical UI is obviously considered better than not having any at all.
I'd suggest to have a look at this challenge (for inspiration): Create a GUI Piano.

https://codegolf.stackexchange.com/questions/7346/create-a-gui-piano

*/

#define STB_TRUETYPE_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <SDL3/SDL.h>
#include "stb_truetype.h"

#define MAX 100

typedef struct {
	double data[MAX];
	int top;
} ValueStack;

typedef struct {
	char data[MAX];
	int top;
} OpStack;

typedef struct {
	SDL_Texture *texture;
	stbtt_bakedchar glyphs[256];
	float size;
} Font;

typedef struct {
	float position;
	SDL_FColor color;
} ColorStop;

typedef struct {
	SDL_FRect frame;
	SDL_FPoint space;

	char text[2];

	bool selected;
	bool clicked;
	int click_type;
} Button;

typedef struct {
	char buffer[28];
	size_t size;
	bool error;
} Input;

const SDL_FColor BLACK = { 0, 0, 0, 1 };
const SDL_FColor WHITE = { 1, 1, 1, 1 };
const SDL_FColor AQUA1 = { 0.000000, 0.556863, 1.000000, 1 };
const SDL_FColor AQUA2 = { 0.000000, 0.462745, 0.658824, 1 };
const SDL_FColor BLACK1 = { 0.15, 0.15, 0.15, 1 };
const SDL_FColor GRAY1 = { 0.905, 0.905, 0.905, 1 };
const SDL_FColor GRAY2 = { 0.806, 0.806, 0.806, 1 };
const SDL_FColor GRAY3 = { 0.93, 0.93, 0.93, 1 };

SDL_Window *window;
SDL_Renderer *renderer;
Input input;
Button buttons[16];
Font font;

enum {
	WIDTH = 448,
	HEIGHT = 400,
};

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	SDL_LogMessageV(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, fmt, ap);
	va_end(ap);
	exit(1);
}

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

size_t
trim_zeros(char *buffer)
{
	size_t length;
	char *start;
	char *end;

	length = strlen(buffer);
	start = strchr(buffer, '.');
	if (!start)
		return length;

	end = start + 1;
	while (end[0] && end[0] == '0')
		end++;

	if (end[0] == '\0') {
		*start = '\0';
		length = start - buffer;
	}
	return length;
}

void
push_val(ValueStack *s, double val)
{
	if (s->top < MAX - 1)
		s->data[++(s->top)] = val;
}

double
pop_val(ValueStack *s)
{
	if (s->top >= 0)
		return s->data[(s->top)--];
	return 0;
}

void
push_op(OpStack *s, char op)
{
	if (s->top < MAX - 1)
		s->data[++(s->top)] = op;
}

char
pop_op(OpStack *s)
{
	if (s->top >= 0)
		return s->data[(s->top)--];
	return 0;
}

char
peek_op(OpStack *s)
{
	if (s->top >= 0)
		return s->data[s->top];
	return 0;
}

int
precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

double
apply_operator(double a, double b, char op)
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	return 0;
}

double
evaluate_expression(const char *expr)
{
	ValueStack val_stack = { .top = -1 };
	OpStack op_stack = { .top = -1 };
	double val1;
	double val2;
	char op;
	char *endptr;
	size_t i, j;

	i = 0;
	while (expr[i] != '\0') {
		if (isspace(expr[i])) {
			i++;
			continue;
		}

		if (expr[i] == '.' || isdigit(expr[i])) {
			val1 = strtod(&expr[i], &endptr);
			push_val(&val_stack, val1);
			j = endptr - expr;
			if (i == j)
				return 0;
			i = j - 1;
		} else if (expr[i] == '(') {
			push_op(&op_stack, expr[i]);
		} else if (expr[i] == ')') {
			while (op_stack.top != -1 && peek_op(&op_stack) != '(') {
				val2 = pop_val(&val_stack);
				val1 = pop_val(&val_stack);
				op = pop_op(&op_stack);
				push_val(&val_stack, apply_operator(val1, val2, op));
			}
			if (op_stack.top != -1) {
				pop_op(&op_stack);
			}
		} else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
			while (op_stack.top != -1 && precedence(peek_op(&op_stack)) >= precedence(expr[i])) {
				val2 = pop_val(&val_stack);
				val1 = pop_val(&val_stack);
				op = pop_op(&op_stack);
				push_val(&val_stack, apply_operator(val1, val2, op));
			}
			push_op(&op_stack, expr[i]);
		}
		i++;
	}

	while (op_stack.top != -1) {
		val2 = pop_val(&val_stack);
		val1 = pop_val(&val_stack);
		op = pop_op(&op_stack);
		push_val(&val_stack, apply_operator(val1, val2, op));
	}

	return pop_val(&val_stack);
}

SDL_FRect
inset(SDL_FRect rect, float n)
{
	rect.x += n;
	rect.y += n;
	rect.w -= 2 * n;
	rect.h -= 2 * n;
	return rect;
}

int
get_key(SDL_Event *ev)
{
	if (ev->type != SDL_EVENT_KEY_DOWN && ev->type != SDL_EVENT_KEY_UP)
		return 0;

	if (ev->key.mod & SDL_KMOD_SHIFT) {
		if (ev->key.key == '=')
			return '+';
		if (ev->key.key == '8')
			return '*';
	}

	switch (ev->key.key) {
	case SDLK_KP_PLUS:
		return '+';
	case SDLK_KP_MINUS:
		return '-';
	case SDLK_KP_MULTIPLY:
		return '*';
	case SDLK_KP_DIVIDE:
		return '/';
	case SDLK_KP_0:
		return '0';
	case SDLK_KP_1:
		return '1';
	case SDLK_KP_2:
		return '2';
	case SDLK_KP_3:
		return '3';
	case SDLK_KP_4:
		return '4';
	case SDLK_KP_5:
		return '5';
	case SDLK_KP_6:
		return '6';
	case SDLK_KP_7:
		return '7';
	case SDLK_KP_8:
		return '8';
	case SDLK_KP_9:
		return '9';
	case SDLK_KP_PERIOD:
		return '.';
	case SDLK_KP_ENTER:
		return '=';
	case SDLK_RETURN:
		return '=';
	}

	return ev->key.key;
}

void
clear_input()
{
	input.error = false;
	input.buffer[0] = '\0';
	input.size = 0;
}

void
add_input(int symbol)
{
	static const char ops[] = "+-*/";

	double value;
	int length;

	if (input.error)
		clear_input();

	if (symbol == '=') {
		value = evaluate_expression(input.buffer);
		snprintf(input.buffer, sizeof(input.buffer), "%f", value);
		length = trim_zeros(input.buffer);

		if (input.error || length >= (int)sizeof(input.buffer)) {
			snprintf(input.buffer, sizeof(input.buffer), "ERROR");
			input.error = true;
		}
		input.size = strlen(input.buffer);
		return;
	}

	if (input.size + 1 >= sizeof(input.buffer))
		return;

	if (input.size == 0 && (symbol == '*' || symbol == '/'))
		return;

	if (input.size > 0 && strchr(ops, symbol) && strchr(ops, input.buffer[input.size - 1]))
		input.size--;

	input.buffer[input.size++] = symbol;
	input.buffer[input.size] = '\0';
}

void
erase_input()
{
	if (input.error)
		clear_input();

	if (input.size > 0)
		input.buffer[--input.size] = '\0';
}

void
create_font(Font *font, const char *font_path, int atlas_width, int atlas_height, float font_size)
{
	SDL_Color colors[256];
	SDL_Palette *palette;
	SDL_Surface *surface;
	unsigned char *ttf_data;
	unsigned char *bitmap;
	int i;

	ttf_data = SDL_LoadFile(font_path, NULL);
	if (!ttf_data)
		fatal("Failed to load font");

	bitmap = xcalloc(atlas_width * atlas_height, sizeof(*bitmap));
	stbtt_BakeFontBitmap(ttf_data, 0, font_size, bitmap, atlas_width, atlas_height, 0, 256, font->glyphs);
	surface = SDL_CreateSurfaceFrom(atlas_width, atlas_height, SDL_PIXELFORMAT_INDEX8, bitmap, atlas_width);
	palette = SDL_CreatePalette(256);
	if (!surface || !palette)
		fatal("Failed to create font surface");

	for (i = 0; i < 256; i++) {
		colors[i].r = 255;
		colors[i].g = 255;
		colors[i].b = 255;
		colors[i].a = i;
	}
	SDL_SetPaletteColors(palette, colors, 0, 256);
	SDL_SetSurfacePalette(surface, palette);
	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);

	font->size = font_size;
	font->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!font->texture)
		fatal("Failed to create font texture");

	SDL_free(ttf_data);
	SDL_DestroySurface(surface);
	SDL_DestroyPalette(palette);
	free(bitmap);
}

void
init_buttons()
{
	static const char symbols[] = "789/456*123-.0=+";

	SDL_FPoint start;
	SDL_FPoint offset;
	Button *button;
	float spacing;
	int row, col;

	start.x = 32;
	start.y = 100;
	spacing = 20;

	offset.y = start.y;
	for (row = 0; row < 4; row++) {
		offset.x = start.x;
		for (col = 0; col < 4; col++) {
			button = buttons + (row * 4) + col;
			memset(button, 0, sizeof(*button));
			button->frame.w = 80;
			button->frame.h = 50;
			button->frame.x = offset.x + (col * button->frame.w);
			button->frame.y = offset.y + (row * button->frame.h);
			button->space.x = 8;
			button->space.y = 10;
			snprintf(button->text, sizeof(button->text), "%c", symbols[(row * 4) + col]);
			offset.x += spacing;
		}
		offset.y += spacing;
	}
}

void
init_sdl()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	window = SDL_CreateWindow("Calculator", WIDTH, HEIGHT, 0);
	if (!window)
		fatal("Failed to create window: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer)
		fatal("Failed to create renderer: %s", SDL_GetError());

	create_font(&font, "Roboto-Regular.ttf", 1024, 1024, 32);

	init_buttons();
}

void
update(SDL_Event *ev)
{
	SDL_FPoint mouse;
	Button *button;
	Button *clicked_button;
	Button *key_button;
	Button *mouse_button;
	bool insert;
	bool erase;
	bool chosen;
	int key;
	size_t i;

	SDL_GetMouseState(&mouse.x, &mouse.y);

	clicked_button = NULL;
	key_button = NULL;
	mouse_button = NULL;
	chosen = false;
	for (i = 0; i < SDL_arraysize(buttons); i++) {
		button = buttons + i;
		button->selected = false;

		if (SDL_PointInRectFloat(&mouse, &button->frame)) {
			if (!chosen) {
				button->selected = true;
				chosen = true;
			}
			mouse_button = button;
		}

		if (button->clicked)
			clicked_button = button;

		if (!ev)
			continue;

		key = get_key(ev);
		if (key == button->text[0])
			key_button = button;
		else if (ev->type == SDL_EVENT_KEY_UP && button->clicked) {
			if (button->text[0] == '+' && key == '=')
				key_button = button;
			else if (button->text[0] == '*' && key == '8')
				key_button = button;
		}
	}

	if (!ev)
		return;

	insert = false;
	erase = false;
	switch (ev->type) {
	case SDL_EVENT_KEY_DOWN:
		if (ev->key.key == SDLK_BACKSPACE)
			erase = true;
		else if (ev->key.key == SDLK_SPACE)
			clear_input();
		if (!clicked_button && key_button) {
			key_button->click_type = 'k';
			key_button->clicked = true;
		}
		break;

	case SDL_EVENT_KEY_UP:
		if (clicked_button && clicked_button == key_button && clicked_button->click_type == 'k')
			insert = true;
		break;

	case SDL_EVENT_MOUSE_BUTTON_DOWN:
		if (!clicked_button && mouse_button) {
			mouse_button->click_type = 'm';
			mouse_button->clicked = true;
		}
		break;

	case SDL_EVENT_MOUSE_BUTTON_UP:
		if (clicked_button && clicked_button == mouse_button && clicked_button->click_type == 'm')
			insert = true;
		break;
	}

	if (insert) {
		add_input(clicked_button->text[0]);
		clicked_button->clicked = false;
		clicked_button->click_type = 0;
	} else if (erase)
		erase_input();
}

void
event()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			if (ev.key.key == SDLK_ESCAPE)
				exit(0);
			SDL_FALLTHROUGH;
		case SDL_EVENT_KEY_UP:
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		case SDL_EVENT_MOUSE_BUTTON_UP:
			update(&ev);
			break;
		}
	}
}

void
draw_fill_rect(SDL_FRect rect, SDL_FColor color)
{
	SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void
draw_text(Font *font, float x, float y, SDL_FColor color, const char *text)
{
	SDL_FRect src, dst;
	stbtt_bakedchar b;

	SDL_SetTextureBlendMode(font->texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureColorModFloat(font->texture, color.r, color.g, color.b);

	for (; *text; text++) {
		b = font->glyphs[*text & 0xff];

		src = (SDL_FRect){
			.x = b.x0,
			.y = b.y0,
			.w = b.x1 - b.x0,
			.h = b.y1 - b.y0,
		};

		dst = (SDL_FRect){
			.x = x + b.xoff,
			.y = y + b.yoff,
			.w = src.w,
			.h = src.h,
		};

		SDL_RenderTexture(renderer, font->texture, &src, &dst);
		x += b.xadvance;
	}
}

void
draw_linear_gradient_vertical(SDL_FRect frame, ColorStop *stops, size_t nstops)
{
	SDL_Vertex vert[6];
	SDL_FColor color1, color2;
	SDL_FRect rect;
	size_t i;

	memset(vert, 0, sizeof(vert));
	rect = frame;
	for (i = 1; i < nstops; i++) {
		color1 = stops[i - 1].color;
		color2 = stops[i].color;

		rect.y = (stops[i - 1].position * frame.h) + frame.y;
		rect.h = (stops[i].position * frame.h) + frame.y;
		rect.h -= rect.y;

		vert[0].position.x = rect.x;
		vert[0].position.y = rect.y;
		vert[0].color = color1;

		vert[1].position.x = rect.x + rect.w;
		vert[1].position.y = rect.y;
		vert[1].color = color1;

		vert[2].position.x = rect.x;
		vert[2].position.y = rect.y + rect.h;
		vert[2].color = color2;

		vert[3].position.x = rect.x + rect.w;
		vert[3].position.y = rect.y;
		vert[3].color = color1;

		vert[4].position.x = rect.x;
		vert[4].position.y = rect.y + rect.h;
		vert[4].color = color2;

		vert[5].position.x = rect.x + rect.w;
		vert[5].position.y = rect.y + rect.h;
		vert[5].color = color2;

		SDL_RenderGeometry(renderer, NULL, vert, 6, NULL, 0);
	}
}

void
draw_layout()
{
	SDL_FRect background;
	SDL_FRect separator;

	separator.x = 0;
	separator.y = 70;
	separator.w = WIDTH;
	separator.h = 2;

	background.x = 0;
	background.w = WIDTH;
	background.y = separator.y;
	background.h = HEIGHT;

	SDL_SetRenderDrawColorFloat(renderer, 1, 1, 1, 1);
	SDL_RenderClear(renderer);
	draw_fill_rect(background, GRAY3);
	draw_fill_rect(separator, GRAY2);
}

void
draw_button(Button *button)
{
	ColorStop view_stops[] = {
		{ 0.0, WHITE },
		{ 0.50, GRAY1 },
		{ 0.75, GRAY2 },
		{ 1.0, GRAY2 },
	};

	ColorStop selected_stops[] = {
		{ 0.0, AQUA2 },
		{ 0.50, WHITE },
		{ 0.75, GRAY2 },
		{ 1.0, GRAY2 },
	};

	ColorStop *stops;
	size_t nstop;
	SDL_FRect frame;
	float x, y;

	frame = button->frame;
	x = frame.x + ((frame.w - font.size) / 2) + button->space.x;
	y = frame.y + (frame.h / 2) + button->space.y;

	if (button->selected)
		draw_fill_rect(frame, AQUA1);
	else
		draw_fill_rect(frame, BLACK1);

	stops = view_stops;
	nstop = SDL_arraysize(view_stops);
	if (button->clicked) {
		stops = selected_stops;
		nstop = SDL_arraysize(selected_stops);
	}

	frame = inset(frame, 2);
	draw_linear_gradient_vertical(frame, stops, nstop);
	draw_text(&font, x, y, BLACK, button->text);
}

void
draw_input()
{
	float spacing;

	spacing = 10;
	draw_text(&font, WIDTH - (input.size * font.size / 2.0) - spacing, 45, BLACK, input.buffer);
}

void
draw()
{
	size_t i;

	draw_layout();
	for (i = 0; i < SDL_arraysize(buttons); i++)
		draw_button(buttons + i);
	draw_input();

	SDL_RenderPresent(renderer);
}

int
main()
{
	init_sdl();
	for (;;) {
		event();
		update(NULL);
		draw();
	}
	return 0;
}
