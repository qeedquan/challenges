/*

Background Story:
In the Dune universe, a spice harvester is a large, heavy, mobile factory designed to harvest the spice Melange. It is dropped by carrier ships (known as Carryalls) onto spice fields. Harvesters harvest and process the spice off the top of the desert floor.

Because of the rhythmic sound they make, harvesters are regularly eaten by sandworms (on the planet Arrakis, sandworms were reported to range from 100 meters to up to 450 meters in length). That's why 2 or 3 ornithopters (called spotters) are deployed to scout from the skies to watch for wormsign. Upon detection of wormsign (ie. worm movement), the spotters then contact the nearest Carryall for pickup of the target harvester.

Goal:
As a spotter pilot, you are responsible for handling dispatch of Carryalls in your vicinity. Your goal is to determine whether a carryall should be sent for rescue, or if it must be forfeited because there is not enough time.

Each test input will consist of an object data, which has the following properties:

harvester: location of the spice harvester

worm: location and travel speed of the spotted sandworm in the form [location, movement speed])

carryall: location and travel speed of the nearest carryall in the form [location, movement speed])

Conditions / Restrictions:
All coordinates (location) are in the form: [x, y] and may be positive or negative. For example: [45,225]
Assume that the sandworm and Carryall each are moving toward the harvester in a straight line at a constant speed.
A Carryall takes 1 minute to lift the harvester to a safe altitude in order to avoid being devoured by the sandworm. Take this into account when formulating your solution.
Distance is measured in kilometers (in the 213th century, the metric system is the universal standard)
Movement speed is measured in km/minute.
Input argument is always valid.
Return value should be a String type value.
Do not mutate the input.
Output:
If the harvester can be saved (that is, lifted to a safe altitude before the sandworm reaches the target location), the function should return The spice must flow! Rescue the harvester! otherwise, it should return Damn the spice! I'll rescue the miners!

Test Example:
let data1 = {harvester: [345,600], worm: [[200,100],25], carryall: [[350,200],32]};

harvesterRescue(data1); // returns 'The spice must flow! Rescue the harvester!'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	double x, y;
} Vec2;

typedef struct {
	Vec2 location;
	double speed;
} Motion;

typedef struct {
	Vec2 harvester;
	Motion worm;
	Motion carryall;
} Data;

double
distance(Vec2 vec0, Vec2 vec1)
{
	double dx, dy;

	dx = vec0.x - vec1.x;
	dy = vec0.y - vec1.y;
	return hypot(dx, dy);
}

const char *
rescue(Data *data)
{
	double cartime;
	double wormtime;

	cartime = distance(data->harvester, data->carryall.location) / data->carryall.speed + 1;
	wormtime = distance(data->harvester, data->worm.location) / data->worm.speed;
	if (cartime < wormtime)
		return "The spice must flow! Rescue the harvester!";
	return "Damn the spice! I'll rescue the miners!";
}

void
test(Data *data, const char *expected)
{
	const char *result;

	result = rescue(data);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	Data data1 = { { 345, 600 }, { { 200, 100 }, 25 }, { { 350, 200 }, 32 } };
	Data data2 = { { 200, 400 }, { { 200, 0 }, 40 }, { { 500, 100 }, 45 } };
	Data data3 = { { 850, 125 }, { { 80, 650 }, 20 }, { { 80, 600 }, 20 } };
	Data data4 = { { 0, 320 }, { { 250, 680 }, 42 }, { { 550, 790 }, 58 } };
	Data data5 = { { 0, 0 }, { { 0, 600 }, 50 }, { { 0, 880 }, 80 } };

	test(&data1, "The spice must flow! Rescue the harvester!");
	test(&data2, "Damn the spice! I'll rescue the miners!");
	test(&data3, "The spice must flow! Rescue the harvester!");
	test(&data4, "Damn the spice! I'll rescue the miners!");
	test(&data5, "Damn the spice! I'll rescue the miners!");

	return 0;
}
