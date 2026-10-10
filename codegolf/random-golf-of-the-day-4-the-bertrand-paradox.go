/*

About the Series
First off, you may treat this like any other code golf challenge, and answer it without worrying about the series at all. However, there is a leaderboard across all challenges. You can find the leaderboard along with some more information about the series in the first post.

Although I have a bunch of ideas lined up for the series, the future challenges are not set in stone yet. If you have any suggestions, please let me know on the relevant sandbox post.

Hole 4: The Bertrand Paradox
The Bertrand paradox is an interesting problem, which shows how different methods for picking random chords in a circle can yield different distributions of chords, their midpoints and their lengths.

In this challenge you are supposed to generate random chords of the unit circle, using the "right" method, i.e. one which produces a distribution of chords which is invariant under scaling and translation. In the linked Wikipedia article, "Method 2" is such a method.

Here are the exact rules:

You should take one positive integer N which specifies how many chords should be returned. The output should be a list of N chords, each specified as two points on the unit circle, given by their polar angle in radians.
Your code should be able to return at least 220 different values for each of the two angles. If your available RNG has a smaller range, you must either first build an RNG with a sufficiently large range on top of the built-in one or you must implement your own suitable RNG. This page may be helpful for that.
The distribution of chords must be indistinguishable from the one produced by "Method 2" in the linked Wikipedia article. If you implement a different algorithm to choose chords, please include a proof of correctness. Whatever algorithm you choose to implement, it must theoretically be able to generate any valid chord in the unit circle (barring limitations of the underlying PRNG or limited-precision data types).
Your implementation should use and return either floating-point numbers (at least 32 bits wide) or fixed-point numbers (at least 24 bits wide) and all arithmetic operations should be accurate within at most 16 ulp.
You may write a full program or a function and take input via STDIN (or closest alternative), command-line argument or function argument and produce output via STDOUT (or closest alternative), function return value or function (out) parameter.

Output may be in any convenient list or string format, as long as the individual numbers are clearly distinguishable and their total number is always even.

This is code golf, so the shortest submission (in bytes) wins. And of course, the shortest submission per user will also enter into the overall leaderboard of the series.

Visualisation
You can use the following snippet to render the generated lines and inspect their distribution. Simply paste a list of pairs of angles into the text area. The snippet should be able to handle almost any list format, as long as the numbers are simple decimal numbers (no scientific notation). I recommend you use at least 1000 lines to get a good idea of the distribution. I've also provided some example data for the different methods presented in the article below.

Hide code snippet

function draw() {
  document.getElementById("output").innerHTML = svg
}

function drawLines() {
  lines = document.getElementById("lines").value;
  var e = prefix;
  //e += '<circle cx="' + offset + '" + cy="' + offset + '" r="' + radius + '" stroke="black" fill="white"/>';
  lines = lines.match(/-?(?:\d*\.\d+|\d+\.\d*|\d+(?!\.))/g);
  for (i = 0; i < lines.length; i+=2)
  {
    t1 = parseFloat(lines[i]);
    t2 = parseFloat(lines[i+1]);
    x1 = Math.cos(t1);
    y1 = Math.sin(t1);
    x2 = Math.cos(t2);
    y2 = Math.sin(t2);
    e += '<path stroke="black" stroke-opacity="0.2" d="M ' + (x1 * radius + offset) + ' ' + (y1 * radius + offset) + ' L ' + (x2 * radius + offset) + ' ' + (y2 * radius + offset) + '"/>';
  }
  e += suffix;
  svg = e;
  draw();
}
var prefix = '<svg height="450" width="450">',
  suffix = "</svg>",
  scale = 0.95,
  offset = 225,
  radius = scale*offset,
  svg = "";
svg {
  position: absolute;
}
Paste line specifications here
<br>
<input id="lines" type="textarea" size="60" oninput='drawLines()' />
<br>
<br>
<div id="output"></div>

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

func main() {
	for range 1000000 {
		fmt.Println(sample())
	}
}

func sample() (float64, float64) {
	x := 1 - rand.Float64()*2
	y := 1 - rand.Float64()*2
	r2 := math.Pi * y
	r1 := r2 + 2*math.Acos(x)
	return r1, r2
}
