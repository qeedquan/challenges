/*

This question is slightly harder than the ASCII art version. There is no art, and now you get to do some floating point arithmetic!

The Challenge
The U.S.S. StackExchange was traveling through the gravity field of planet cg-00DLEF when an astronomical explosion occurred on board. As the head programming officer of the ship, it is your job to simulate the trajectory of your ship in order to predict whether you will be forced to crash land in cg-00DELF's solar system. During the explosion, your ship was heavily damaged. Due to the limited free DEEEPRAROM* of the spaceship, you must write your program in as few characters as possible.

*Dynamically Executable Electronically Erasable Programmable Random Access Read Only Memory

The Simulation
Somewhat like the ASCII art version, there will be the idea of time-steps. In the other version, a time-step was a relatively large amount of time: the ship could travel way beyond the gravity of a planet in a single time-step. Here, the time-step is a much smaller unit of time due to the larger distances involved. One major difference, however, is the non-existence of cells. The spaceship's current location and velocity will be floating point numbers, along with the gravitational forces involved. Another change is the fact that planets now have a much larger size.

There will be up to three planets in the simulation. All three will have a specific location, radius, and gravity. The gravity for each planet is a vector that exerts a force directly towards the center of the planet. The formula to find the strength of this vector is (Gravity)/(Distance**2), where the distance is the exact distance from the ship to the center of the planet. This means that there is no limit to where gravity can reach.

At any specific time, the spaceship has a velocity, which is the distance and angle that it traveled from last time-step to now. The ship also has momentum. The distance that it will travel between the current time-step and the next is the sum of its current velocity added to all of the gravity vectors at its location. This becomes the spaceship's new velocity.

Each simulation has a time limit of 10000 time steps. If the spaceship travels inside of a planet (it is closer to the center of the planet than the planet's radius), then it crashes into that planet. If the spaceship does not crash into any planet by the end of the simulation, then it is presumed to have escaped from gravity. It is unlikely that the ship could be aligned so perfectly that it manages to stay in orbit for 10000 time-steps while crashing on the 10001st time-step.

Input
Input will be four lines to STDIN. Each line consists of four comma-delimited numbers. Here is the format of the numbers:

ShipLocX,ShipLocY,ShipVelX,ShipVelY
Planet1LocX,Planet1LocY,Planet1Gravity,Planet1Radius
Planet2LocX,Planet2LocY,Planet2Gravity,Planet2Radius
Planet3LocX,Planet3LocY,Planet3Gravity,Planet3Radius
If there are fewer than three planets, then the leftover lines will be filled with zeros for all values. Here is an example input:

60,0,0,10
0,0,4000,50
100,100,4000,50
0,0,0,0
This means that the spaceship is located at (60,0) and is traveling straight "up/north" at a rate of 10 units/time-step. There are two planets, one located at (0,0) and one at (100,100). Both have a gravity of 4000 and a radius of 50. Even though all of these are integers, they will not always be integers.

Output
Output will be a single word to STDOUT to tell whether the spaceship has crash landed or not. If the ship crash lands, print crash. Otherwise, print escape. Here is the expected output for the above input:

crash
You may be wondering what happened. Here is a Pastebin post that has a detailed flight log for the spaceship. Numbers aren't very good at helping people visualize the event so here is what happened: The spaceship manages to escape the gravity of the first planet (to its west) with the help of the gravity of the second planet (to its northeast). It moves north and then passes slightly to the west of the second planet, barely missing it. It then curves around the northern side of the planet and crashes into the eastern side of the second planet.

Some more cases for examination
60,0,10,-10
0,0,2000,50
100,100,1357.9,47.5
0,0,0,0
escape (due to the inverse square law, 2000 isn't much gravity if you are 60 units away)

0,0,0,0
100,100,20000,140
-50,-50,50,50
-100,-100,50,50
crash (the first planet is extremely massive and extremely close)

0,0,0,0
0,0,0,0
0,0,0,0
0,0,0,0
escape (this is an edge case: there are no planets and a straightforward interpretation would suggest that the spaceship is directly on top of the planets)

Rules, Restrictions, and Notes
This is code golf. Standard code golf rules apply. Your program should be written in printable ASCII characters only. You cannot access any sort of external database. You may write entries in any language (other than one that is specialized towards solving this challenge).

End Transmission

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	double x, y;
} Vec2;

typedef struct {
	Vec2 position;
	Vec2 velocity;
} Ship;

typedef struct {
	Vec2 position;
	double gravity;
	double radius;
} Planet;

Vec2
add(Vec2 vec1, Vec2 vec2)
{
	return (Vec2){
	    .x = vec1.x + vec2.x,
	    .y = vec1.y + vec2.y,
	};
}

Vec2
sub(Vec2 vec1, Vec2 vec2)
{
	return (Vec2){
	    .x = vec1.x - vec2.x,
	    .y = vec1.y - vec2.y,
	};
}

Vec2
scale(Vec2 vec, double scale)
{
	return (Vec2){
	    .x = vec.x * scale,
	    .y = vec.y * scale,
	};
}

// ported from @Keith Randall solution
const char *
fate(Ship *ship, Planet planets[3])
{
	static const int iterations = 10000;

	Vec2 vector;
	double magnitude;
	int iteration;
	int planet_index;
	Planet *planet;

	for (iteration = 0; iteration < iterations; iteration++) {
		for (planet_index = 0; planet_index < 3; planet_index++) {
			planet = planets + planet_index;
			vector = sub(planet->position, ship->position);
			magnitude = hypot(vector.x, vector.y);
			ship->velocity = add(ship->velocity, scale(vector, planet->gravity / pow(magnitude, 3)));
			if (magnitude < planet->radius)
				return "crash";
		}
		ship->position = add(ship->position, ship->velocity);
	}

	return "escape";
}

void
test(Ship *ship, Planet planets[3], const char *expected)
{
	const char *result;

	result = fate(ship, planets);
	printf("%s\n", result);
	assert(!strcmp(result, expected));
}

int
main()
{
	Ship ship_1 = {{60, 0}, {0, 10}};
	Planet planets_1[] = {
	    {{0, 0}, 4000, 50},
	    {{100, 100}, 4000, 50},
	    {{0, 0}, 0, 0},
	};

	Ship ship_2 = {{60, 0}, {10, -10}};
	Planet planets_2[] = {
	    {{0, 0}, 2000, 50},
	    {{100, 100}, 1357.9, 47.5},
	    {{0, 0}, 0, 0},
	};

	Ship ship_3 = {{0, 0}, {0, 0}};
	Planet planets_3[] = {
	    {{100, 100}, 20000, 140},
	    {{-50, -50}, 50, 50},
	    {{-100, -100}, 50, 50},
	};

	Ship ship_4 = {{0, 0}, {0, 0}};
	Planet planets_4[] = {
	    {{0, 0}, 0, 0},
	    {{0, 0}, 0, 0},
	    {{0, 0}, 0, 0},
	};

	test(&ship_1, planets_1, "crash");
	test(&ship_2, planets_2, "escape");
	test(&ship_3, planets_3, "crash");
	test(&ship_4, planets_4, "escape");

	return 0;
}
