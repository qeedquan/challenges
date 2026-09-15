/*

Respond Proportionately
The question then was Fire the Nukes or Keep the Peace? If we can also Respond Proportionately, if we have a third option, another datatype is necessary:

switch ( option ) {
  deescalate: keep(peace);
  reciprocate: respond(proportionately);
  escalate: fire(nukes);
}
Or compare two numbers to each other. The three possible outcomes are:

Ordering = LT | EQ | GT
Again, we have Constructors, now three of them. Their order is arbitrary, but we need to agree on it, because the order of the function arguments we will later feed into the encodings functions corresponds with it. Following the recipe from last time

For every Constructor, define a curried function that takes as many arguments as there are Constructors ( keeping arguments in order of their enumeration in the type definition ), and returns one of them:

LT = lt => eq => gt => lt
EQ = lt => eq => gt => eq
GT = lt => eq => gt => gt
TASK: If you write the functions LT, EQ and GT, the Example Tests will feed them arguments and inspect the answers.

Compare this to the JavaScript convention for sorting values:

x  <  y  <=>  -1 ( or any other negative number )
x === y  <=>   0
x  >  y  <=>   1 ( or any other positive number )
Doing a certain operation, making a certain choice, when x < y, means

if ( compare(x,y) < 0 ) keep(peace);
With Scott encoding, that would look like

compare(x,y) (keep(peace)) () ()
Not completely applying an Ordering is pretty useless ( the function will just wait for more arguments ), but there may be possibilities for empty values ( SideEffect: do(nothing), Thing: null, Property: undefined ).
By saturating the Ordering value with arguments, the whole thing again becomes an expression, of the same type as the arguments we supplied.

The first real exercise is determining a sorted list from an input. You are given the function compare, which takes two numbers and returns an Ordering. As mentioned, JavaScript sort expects Numbers as the result of a comparison, not Orderings. ( See MDN, paragraph "If compareFn is supplied ..". )

TASK: Change sorted so that it works ( do not change compare ).

With the same compare, the next exercise is determining the maximum of a list of numbers. By walking the entire list and calculating the maximum of the list so far for every element, calculate the maximum of the entire list. ( See MDN, callbackFn. Your callbackFn should return the maximum of accumulator and currentValue. )

TASK: Change maximum so that it works.

Respond Proportionately
As promised, now the case where there is one possible value:

switch ( option ) {
  reciprocate: respond(proportionately);
}

Unit = UNIT
Remember,

For every Constructor, define a curried function that takes as many arguments as there are Constructors ( keeping arguments in order of their enumeration in the type definition ), and returns one of them.

TASK: If you write the function UNIT, the Example Tests will feed it arguments and inspect the answers.

< pregnant pause >

Well, that was useful.

A datatype that can have only one value does not contain any information. Whatever comes out of the encoded value had to be put in first!

Still, almost every programming language in existence has a Unit datatype ( JavaScript even has two! ).
They may be named undefined, null, None, NIL, Unit, or () ( the zero-tuple. but don't worry if you don't know what that is ).
Apparently there is a use for it :] and we may encounter one in a future example on encoding numbers in unary, as lists of .. nothings. But we are not there yet.

do(nothing) .. or even less?
The case where there are zero possible values. It looks like this:

switch ( option ) {
}

Void
This case is completely nuts. There is a datatype, but it has no values. Because only values are encoded, and not the datatype .. there is no encoding either. You do not have to write the function - there is no function; there can be no tests, there are no inputs, no outputs, there is less than zero information ( remember, Unit had no information ). So what is the use of a datatype that has no values?

On the value level, there is none. ( It is acceptable to stop reading now. ) But when reasoning about code, at the type level, there can be use cases for a Void type. It turns out there are useful things that can be done at the type level, without ever considering things as mundane as value implementations. There is a kata about type cardinality, if you are interested ( and can handle 2kyu Haskell ). Void also has use in proof languages: an impossibility at the value level can encode a falsehood at the type level.

Rainbow Colours
To not go out on a note of complete and utter uselessness, a final exercise with a happier subject: rainbows. Remember

Colour = RED | ORANGE | YELLOW | GREEN | BLUE | PURPLE
TASK: If you write functions RED, ORANGE, YELLOW, GREEN, BLUE and PURPLE, the Example Tests will throw things in and show what comes out.

This concludes today's lecture
Next time: unary Constructors. They add information to existing information!

*/

const LT = (lt) => (eq) => (gt) => lt;
const EQ = (lt) => (eq) => (gt) => eq;
const GT = (lt) => (eq) => (gt) => gt;

// do not change this function //
function compare(x, y) {
	if (x < y)
		return LT;
	if (x > y)
		return GT;
	return EQ;
}

function sorted([...xs]) {
	return xs.sort((a, b) => compare(a, b)(-1)(1)(0));
}

function maximum(xs) {
	return xs.reduce((accumulator, currentValue) =>
		compare(accumulator, currentValue)(currentValue)(currentValue)(accumulator),
	);
}

const UNIT = (val) => val;

const RED = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => red;
const ORANGE = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => orange;
const YELLOW = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => yellow;
const GREEN = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => green;
const BLUE = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => blue;
const PURPLE = (red) => (orange) => (yellow) => (green) => (blue) => (purple) => purple;

