/*

You walk in a maze. You need to reach the exit through many rooms. These rooms are in a straight line.

You can only walk in the dark. Otherwise, you will be caught by the enemy.

Your trouble is that some rooms have light bulbs. If the light bulb is bright when you enter the room. You were caught by the enemy.

Fortunately, the status of these bulbs (on/off) is aoto-switched every minute. So you have a chance to go through the maze.

Task
Let's us use a string map to represent these rooms， like this: "xo oxox".

"x" means there is a bulb in the room, and its initial status is off;

"o" means there is a bulb in the room, and its initial status is on;

" "(space) means a room without bulb, it's always dark.

Your task is to determine if you can go through the maze. Return true if you can, false otherwise.

Note
Your initial position is the most left, the exit position is the most right.

Your moving speed is 1 minute per step. You can not stop before you start your moving until you reach the exit.

Examples
For map = "xo oxox". The output should be true.

step 0 :  xo oxox
          ^ <--------You are here
step 1 :  ox xoxo
           ^ <--------You are here
step 2 :  xo oxox
            ^ <--------You are here
step 3 :  ox xoxo
             ^ <--------You are here
step 4 :  xo oxox
              ^ <--------You are here
step 5 :  ox xoxo
               ^ <--------You are here
step 6 :  xo oxox
                ^ <--------You are here
step 7 :  ox xoxo
                 ^ <--------You've go through the maze :)

For map = "xo  oxox". The output should be false.

step 0 :  xo  oxox
          ^ <--------You are here
step 1 :  ox  xoxo
           ^ <--------You are here
step 2 :  xo  oxox
            ^ <--------You are here
step 3 :  ox  xoxo
             ^ <--------You are here
step 4 :  xo  oxox
              ^ <--------You were caught by the enemy :(

Happy Coding ^_^

*/

#include <assert.h>
#include <stdio.h>

bool
bulbmaze(const char *maze)
{
	size_t i;

	for (i = 0; maze[i]; i++) {
		if (!(i & 1) && maze[i] == 'o')
			return false;
		if ((i & 1) && maze[i] == 'x')
			return false;
	}
	return true;
}

int
main()
{
	assert(bulbmaze("xo oxox") == true);
	assert(bulbmaze("xo  oxox") == false);
	assert(bulbmaze("xo ox xo") == true);
	assert(bulbmaze("xooxxo") == false);
	assert(bulbmaze("xxxxxx") == false);
	assert(bulbmaze("oooooo") == false);
	assert(bulbmaze("x") == true);
	assert(bulbmaze("o") == false);
	assert(bulbmaze("      ") == true);
	assert(bulbmaze(" ox") == true);
	assert(bulbmaze("xo") == true);

	return 0;
}
