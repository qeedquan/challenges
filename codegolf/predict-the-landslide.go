/*

Landslides
In this challenge, your job is to predict the extent of damage caused by a massive landslide. We use the following simplified two-dimensional model for it, parameterized by an initial height h >= 0 and a critical coefficient c > 0. You start with a cliff of height h, and it is assumed that the terrain is completely flat infinitely to the left and to the right of it. For h = 6, the situation looks like this:

##########
##########
##########
##########
##########
##########
-----------------------
The - are immovable bedrock, and the # are unstable soil. If the height difference between two neighboring columns is more than c, a landslide occurs: the top c units of soil from the left column fall down to the next c columns on the right, one to each. The rightmost non-empty column in the figure is unstable for c = 2, so a landslide is triggered:

#########
#########
##########
##########
##########
############
-----------------------
The column is still unstable, which causes a second landslide:

#########
#########
#########
#########
############
############
-----------------------
Now, the column on its left has become unstable, so a new landslide is triggered there:

########
########
#########
###########
############
############
-----------------------
After this, the cliff is stable again. The nice thing about this model is that the order in which the landslides are processed does not matter: the end result is the same.

The Task
Your program is given the integer parameters h and c as inputs (the order does not matter, but you must specify it on your answer), and it should output the total number of columns that the landslide affects. This means the number of columns in the resulting stable cliff whose height is strictly between 0 and h. In the above example, the correct output is 4.

You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

Test Cases
These are given in the format h c -> output.

0  2  -> 0
2  3  -> 0
6  2  -> 4
6  6  -> 0
10 1  -> 10
15 1  -> 14
15 2  -> 11
15 3  -> 6
40 5  -> 16
80 5  -> 28
80 10 -> 17

*/

package main

func main() {
	assert(landslide(0, 2) == 0)
	assert(landslide(2, 3) == 0)
	assert(landslide(6, 2) == 4)
	assert(landslide(6, 6) == 0)
	assert(landslide(10, 1) == 10)
	assert(landslide(15, 1) == 14)
	assert(landslide(15, 2) == 11)
	assert(landslide(15, 3) == 6)
	assert(landslide(40, 5) == 16)
	assert(landslide(80, 5) == 28)
	assert(landslide(80, 10) == 17)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func landslide(h, c int) int {
	l := make([]int, h+h)
	for i := range h {
		l[i] = h
	}

	for {
		b := 0
		for i := range len(l) - 1 {
			if l[i]-l[i+1] > c {
				for j := range c {
					l[i+j+1] += 1
				}
				l[i] -= c
				b = 1
			}
		}
		if b == 0 {
			break
		}
	}

	r := 0
	for _, e := range l {
		if h > e && e > 0 {
			r += 1
		}
	}
	return r
}
