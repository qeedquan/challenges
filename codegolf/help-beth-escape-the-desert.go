/*

While similar to the other water-carrying puzzle, the unique aspects of this challenge make it entirely different.

https://i.stack.imgur.com/6jr2y.png

Beth is located at an oasis in the middle of a desert. There is plenty of water in the lake, but unfortunately there are only X buckets, each of which has a capacity of Y liters of water.

Beth can carry 2 buckets in her hands, but to survive, she must drink exactly 1 liter after each kilometer she travels. She can also leave some buckets half-way (water does not evaporate).

The challenge
Figure out the formula and write the shortest solution that will work for positive integer values of X and Y and calculate the maximum distance Beth can travel from the oasis. Moving water between the buckets is permitted.

Example
X=3, Y=5

Beth walks 3km with two full buckets. Leaves 1 full bucket behind. The other bucket now has 2L left, which is enough to get home (Beth can have the last drink from the oasis).
She leaves with another two full buckets, arriving with 1 full, plus 2 litres in the other (12L total: 5 + 5 + 2).
Beth can advance to 6KM point and leave bucket with 4L of water in it.
She returns to the 3KM point. She now has exactly 2L to get back to the oasis.
Fill up buckets and travel to 6KM point. She now has 8L of water.
Continue all the way to 15KM point.
Answer is: 15

Input / Output
You can define X/Y directly in the code or read from input. Result could be placed in variable or output, whichever is shortest.

*/

package main

func main() {
	assert(distance(3, 5) == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Neil

The answer is 16, not 15 as in the example above because:
If Beth leaves a 5L bucket at the 5.5Km point she would have 9.5L of water on her return allowing her to reach 16Km.

When x is less than 3, you take as much water as you can and walk as far as you can, which is simply x*y+1.

When x is at least 3, you have to start building caches.

From the oasis, you can leave a full bucket at a distance y/2 and return to the oasis. You need 2 buckets to do this, but this is not useful if you only have 2 buckets because you want to be able to fill up 2 buckets when you return to the oasis.

From the oasis, with a bucket at a distance y/2, you can leave a full bucket at a distance y and return to the oasis. You need 3 buckets to do this.

From the oasis, with full buckets at both y and y/2, you can leave a full bucket at a distance 3y/2 and return to the oasis. You need 4 buckets to do this. You then have to leave a full bucket at a distance of y/2 and return to the oasis.

Eventually you can end up with a full bucket at (x-1)y/2. (You cannot leave a full bucket at xy/2 because you would not be able to get back to the oasis, as the round trip is xy, the total capacity of the buckets.)

Using your remaining buckets, you can leave full buckets at (x-3)y/2 ... y or y/2. At this point you simply walk as far as you can, picking up your full buckets as you go. When you reach (x-1)y/2 you still have two full buckets left, allowing you to reach (x+3)y/2.

The extra 1 comes from the quirk in the rules allowing you to walk your last mile without having any water. Although the example shows that you can leave the buckets slightly further away than described above, this actually does not help you walk any further, as you either have to leave less water or drink the water from the bucket as you reach it before you can move on.

https://page.mi.fu-berlin.de/rote/Papers/pdf/Optimal+logistics+for+expeditions+-+the+jeep+problem+with+complete+refilling.pdf

*/

func distance(x, y float64) float64 {
	if x < 3 {
		return (3+x)*y/2 + 1
	}
	return (2*x*y)/2 + 1
}
