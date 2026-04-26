/*

There is this game Genshin Impact, when an element is applied to an enemy i.e. Electro it remains for some time causing decay to the enemy health. For this challenge, we'll simplify this to a single integer representing the "aura strength" and a fixed "decay amount" per "tick." When the aura strength drops to 0 or below, it vanishes.

Your task is to write the shortest possible code that, given an initial aura strength and a decay amount per tick, calculates how many ticks it takes for the aura to completely vanish.

Input:

initial_strength: Strength of elemental aura. (0-1000 for this challenge).
decay_per_tick: The amount the aura strength decreases each tick (1 to 100 for this challenge).
Output:

A single non-negative integer representing the number of ticks until the aura vanishes.
Test Cases
initial_strength = 10, decay_per_tick = 3  => Output: 4  (10 -> 7 -> 4 -> 1 -> -2 (vanishes at 4th tick))
initial_strength = 5, decay_per_tick = 5  => Output: 1  (5 -> 0 (vanishes at 1st tick))
initial_strength = 0, decay_per_tick = 10 => Output: 0  (already vanished)
initial_strength = 1, decay_per_tick = 10 => Output: 1  (1 -> -9 (vanishes at 1st tick))
Additional Rules
No standard loop-holes
For languages with no standard input, input may be accepted from the console within program (iff standard input is not possible)
Shortest byte wins, if two existing answers are of same byte, earlier solution wins

*/

#include <assert.h>
#include <stdio.h>

int
vanish(int s, int d)
{
	if (s < 1 || d < 1)
		return 0;
	return ((s - 1) / d) + 1;
}

int
main()
{
	assert(vanish(10, 3) == 4);
	assert(vanish(5, 5) == 1);
	assert(vanish(0, 10) == 0);
	assert(vanish(1, 10) == 1);
	assert(vanish(50, 30) == 2);
	assert(vanish(50, 300) == 1);
	return 0;
}
