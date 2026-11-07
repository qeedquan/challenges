/*

Description
Three-cushion billiards, also called three-cushion carom, is a form of carom billiards. The object of the game is to carom the cue ball off both object balls while contacting the rail cushions at least three times before contacting the second object ball.

The table consists of 4 cushions (north, east, south and west)
There are 3 balls (white, yellow, red)
The cue ball is the ball that the player starts with (white and yellow are allowed to be picked)
The object balls are the 2 remaining balls that the player did not pick to start with (red is always one of these balls)
wiki link ( https://en.wikipedia.org/wiki/Three-cushion_billiards )

The billiards table
           n
   +----------------+
   |                |
   |                |
   |        R       |
   |                |
 w |                | e
   |                |
   |                |
   |                |
   |      W Y       |
   |                |
   +----------------+
            s

Task
Given an encoded string representing the collisions of the cue ball with object balls and cushions, return a boolean indicating whether a point was scored. You may assert the player hits a valid cue ball (white or yellow).

Input
The input consists of a combination of zero, one or more occurences of the following chars:

'w', 'e', 'n', 's' - west, east, north and south cushion
'W', 'Y', 'R' - white, yellow and red ball

Output
return a boolean indicating whether a point is scored

Conditions to score a point
The cue ball must have made contact with the cushions at least three times before contacting the second object ball for the first time.
Both object balls must be hit at least once.

Additional info
The cue ball may contact the cushions before or after hitting the first object ball.
The cue ball does not have to contact three different cushions as long as it has been in contact with any cushion at least three times in total.
Using a specific technique (a massé shot), it is possible to hit the same cushion multiple times in succession, curving the cue ball.
It is allowed that both object balls collide a number of times, this is not encoded in the input and can be ignored altogether

Examples
Scoring a point
input       description
------------------------------------------------------------------------------
"YnesR"     white ball is cue ball, first hits yellow ball,
            then 3 cushions, finally red ball

"RnesY"     white ball is cue ball, first hits red ball,
            then 3 cushions, finally yellow ball

"WnesR"     yellow ball is cue ball, first hits white ball,
            then 3 cushions, finally red ball

"wWnsR"     yellow ball is cue ball, first hits a cushion,
            then white ball, 2 more cushions, finally red ball

"wnWsR"     yellow ball is cue ball, first hits 2 cushions,
            then white ball, 1 more cushion, finally red ball

"wnsWR"     yellow ball is cue ball, first hits 3 cushions,
            then white ball, finally red ball

"YneswR"    white ball is cue ball, first hits yellow ball,
            then 4 cushions, finally red ball

"YnesRs"    white ball is cue ball, first hits yellow ball,
            then 3 cushions, then red ball, finally another cushion

"YnesYR"    white ball is cue ball, first hits yellow ball,
            then 3 cushions, then yellow ball again, finally red ball

"wnwYR"     white ball is cue ball, first hits 3 cushions (one cushion twice),
            then white ball, finally red ball

"wwwYR"     white ball is cue ball, first hits 3 cushions (one cushion trice),
            then white ball, finally red ball

No score
input       description
------------------------------------------------------------------------------
"YneRw"     there are only 2 cushions hit before hitting the second object
            ball (red)

"wYnwY"     the yellow ball is hit twice, but the red ball was not hit

"neR"       only the red ball was hit, no other object ball

""          a total miscue, causing no collisions after hitting the cue ball

"YRnnenRY"  more than 3 cushions were hit, but not before hitting the
            second object ball for the first time (red)

"eRWewsnW"  more than 3 cushions were hit, but not before hitting the
            second object ball for the first time (white)

Good luck, have fun

*/

package main

func main() {
	assert(scored("YnesR") == true)
	assert(scored("RnesY") == true)
	assert(scored("WnesR") == true)
	assert(scored("wWnsR") == true)
	assert(scored("wnWsR") == true)
	assert(scored("wnsWR") == true)
	assert(scored("YneswR") == true)
	assert(scored("YnesRs") == true)
	assert(scored("YnesYR") == true)
	assert(scored("wnwYR") == true)
	assert(scored("wwwYR") == true)

	assert(scored("YneRw") == false)
	assert(scored("wYnwY") == false)
	assert(scored("neR") == false)
	assert(scored("") == false)
	assert(scored("YRnnenRY") == false)
	assert(scored("eRWewsnW") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func scored(input string) bool {
	hits := 0
	ball := rune(0)
	for _, char := range input {
		switch char {
		case 'W', 'R', 'Y':
			switch {
			case ball == 0:
				ball = char
			case ball != char:
				return hits > 2
			}
		default:
			hits++
		}
	}
	return false
}
