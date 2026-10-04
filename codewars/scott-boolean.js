/*

Boole
Wikipedia ( https://en.wikipedia.org/wiki/George_Boole ): George Boole ( 1815 – 1864 ) was a largely self-taught English mathematician, philosopher, and logician. He is best known as the author of The Laws of Thought ( 1854 ), which contains Boolean algebra.

More Wikipedia ( https://en.wikipedia.org/wiki/Boolean_data_type ): The Boolean is a data type that has one of two possible values. It is named after George Boole.

This kata is about encoding Booleans. The above tells us the essence of a Boolean is that it can take on either one of exactly two values. Usually, these are named True and False, but they might be Yes and No, "True" and "False", 0 and 1, spin up and spin down, or any two distinct values you wish to use.

Computers are commonly thought of as working in binary, but even the binary digits ( bits ) of your laptop are encodings. 0 might be a high voltage and 1 a low voltage, or 0 might be spin down and 1 spin up in your expensive latest IBM quantum-superlaptop.

Taking things up another level of abstraction, your favourite programming language might have generic enumerated data types, like

Colour = Red | Orange | Yellow | Green | Blue | Purple

or

Answer = Yes | No

Notice how Answer looks exactly like a Boolean ? In actual fact, Answer is a Boolean data type: it allows for exactly two values. Answer is an encoding of a Boolean, though it is usually written as Boolean = False | True. The encoding of the, Platonian if you will, Boolean does not matter; the meaning we assign to the values means the encoding is for all practical purposes transparent; the encoded and the underlying values are identical as long as we agree on the encoding. In other words, an encoding is an isomorphism.

Little interlude on enumerated data types: Red .. Purple, Yes and No are called Constructors. They can be nullary values, like here, or they might wrap ( an ) other value(s), adding information to their argument(s), as in Pair Red Purple or Pair Yes Yes. ( This kata will restrict itself to nullary Constructors. ) Note that even a nullary Constructor adds information to its zero arguments; in this case, the Constructor itself is all the information.

"as long as we agree on the encoding" means we are free to choose an ( any ) encoding, as long as our audience agrees with us on it. Dear audience, let us agree to encode our Booleans as functions, because (1) we can, (2) it works, and (3) it only requires very basic maths; it requires no hardware and no additional levels of encodings. Now invoke Dana Scott.

Scott
Wikipedia ( https://en.wikipedia.org/wiki/Dana_Scott ): Dana Scott ( 1932 - ) is an American logician. His work on automata theory earned him the Turing Award in 1976.

More Wikipedia ( https://en.wikipedia.org/wiki/Mogensen%E2%80%93Scott_encoding ): Scott encoding is a way to represent ( recursive ) data types in the lambda calculus. Church encoding performs a similar function.

In the lambda calculus, all we have are variables and functions, but fortunately we agreed on encoding Booleans as functions, so we're good. So how does Scott encoding work?

We have Boolean = False | True. The Constructors are False and True.
For every Constructor, define a curried* function that takes as many arguments as there are Constructors ( keeping arguments in order of their enumeration in the type definition ), and returns one of them:

False = f => t => f
True  = f => t => t

* this kata ( https://www.codewars.com/kata/currying-functions-multiply-all-elements-in-an-array ), and the linked video, explain currying.

False and True are encodings of the two possible Booleans, but in shorthand, they are the two possible Booleans. Whenever we encounter either value, we know there's an abstract Platonian Form of truthiness, and whenever we encounter the Platonian form, we know we can encode it. So from now on, let's ignore the difference between encoding and underlying value; whenever we speak of Booleans, we mean the encodings. Because there is no real difference.

Still, False and True are functions here. Because they are encoded, we can call them, with arguments. If you write the functions False and True, the Example Tests will feed them arguments and inspect the answers.

Fire the Nukes or Keep the Peace ?
So what do you do with Booleans? You make choices to do things.

if False then fire(nukes) else keep(peace) ;
if True then pay(bigMoney) else ridicule(seller) ;

Or you choose between two simple values.

if False then Champagne else Water ;
if True then Rich else Poor ;

It doesn't matter what the options are, but it is convenient for them to be of the same type. In that case, the whole thing is an expression, of the same type as the choices, be it SideEffect ( verb ), Thing ( noun ), or Property ( adjective ).

then and else have no semantic meaning of their own, so it is possible to write a curried function call

if (boolean) (x) (y)

where boolean is a Boolean variable and x, y are variables, arbitrarily but identically typed.

How would that function if look? Have a look at the Example Tests, see how it's used, what outputs it expects for what inputs, and write it.

This concludes today's lecture.
Boolean algebra is left as an exercise for the reader. There is a kata ( https://www.codewars.com/kata/church-booleans ) on it, which uses Church encoding instead of Scott encoding - for Booleans the two differ only in the ordering of the Constructors and thus the ordering of the arguments.

*/

const False = (f) => (t) => f;
const True = (f) => (t) => t;
const Iff = (fn) => (f) => (t) => fn(t)(f);

if (True(2)) {
	console.log("True");
}

if (False(True())) {
	console.log("False");
}

if (Iff(True())) {
	console.log("Iff");
}
