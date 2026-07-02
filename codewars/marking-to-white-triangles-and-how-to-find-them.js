/*

My tired eyes surveyed the horizon to spot a right triangle, made of an unknown material that sparkles in the endless void I have trekked thus far.

I hurried towards it. However far it seemed, it can't compare to the uncounted days I have been trapped here in this endless void. To break the monotony, it shall do nicely.

Reaching the triangle, I inspected it. It is even more spectacular up close than a far, like a piece of the heavens, just as grand as the best Hubble photo I've ever seen. Adorned onto its striking surface were two numbers, each hugging a side of the triangle in white chalk.

{a: 3, b: 4}
Almost unconsciously, I grabbed at the misshapen chalk piece in my pocket, a small stone shaped calcium oddity I found among the void. I am hit with the sudden urge to write on the cosmic shape, to complete the numbers by filling in the missing side. The shear burning desire scares me, but I did it anyway. With a bit of internal head math, I wrote down my solution.

{a: 3, b: 4, c: 5}
The triangle glowed white, contrasting almost blindingly against the surrounding darkness around me. Could it be, that solving this shape would be my salvation, my escape from this dark and empty place?

I stared at the shining geometry for what felt like ever, before, with a disappointed sigh, I glanced away from the mesmerizing false hope. Only to catch the sight of two more triangles of right angles.

{a: 5, c: 13}
{b: 2, c: 3}
Somehow, I knew the third triangle had its first side unmarked, rather than its second, I'll have to take that into account were I to do this right. I idly solved them both, looking on in wonder as they too turned white.

{a: 5, c: 13, b: 12}
{b: 2, c: 3, a: 2.236}
Something on the edge of my peripheral vision moved. I looked up, to be greeted with hundreds of right triangles, like angels from the heavens, coming down right at me.

I might need a better solution to turn them all shining white...

*/

function howToFindThem(rightTriangle) {
	let { a, b, c } = rightTriangle;
	if (typeof a !== 'number')
		a = Math.sqrt(c*c - b*b);
	if (typeof b !== 'number')
		b = Math.sqrt(c*c - a*a);
	if (typeof c !== 'number')
		c = Math.sqrt(a*a + b*b);
	return { a, b, c };
}

console.log(howToFindThem({a: 3, b: 4}));
console.log(howToFindThem({a: 5, c: 13}));

