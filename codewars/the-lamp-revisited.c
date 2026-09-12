/*

Define a class called Lamp. It will have a string attribute for color and boolean attribute, on, that will refer to whether the lamp is on or not. Define your class constructor with a parameter for color and assign on as false on initialize.

Give the lamp an instance method called toggleSwitch that will switch the value of the on attribute.

Define another instance method called state that will return "The lamp is on." if it's on and "The lamp is off." otherwise.

*/

#include <stdio.h>

typedef struct {
	char color[32];
	bool on;
} Lamp;

void
lampinit(Lamp *lamp, const char *color)
{
	snprintf(lamp->color, sizeof(lamp->color), "%s", color);
	lamp->on = false;
}

void
lamptoggle(Lamp *lamp)
{
	lamp->on = !lamp->on;
}

char *
lampstate(Lamp *lamp, char *output)
{
	sprintf(output, "This lamp is %s.", (lamp->on) ? "on" : "off");
	return output;
}

int
main()
{
	Lamp lamp;
	char state[32];

	lampinit(&lamp, "red");
	lamptoggle(&lamp);
	printf("%s\n", lampstate(&lamp, state));
	return 0;
}
