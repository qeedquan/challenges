/*

The Friday challenge was not able to be submitted, so I'm going to deviate from the Friday standard here and do a submission which will benefit a different group of Daily Programmers. The vast majority of problems here are for computer scientists, and I feel this leaves out the rest of you - ie. those who are here more for the programming practice than the logical puzzles. Therefore, rather than being expected to solve a logic problem, you will be expected to implement a piece of software from a required specification, thus serving as an exercise in good programming practice and making use of language features available to you.

In this exercise you will implement functionality for complex numbers. (If your language already supports such functionality, pretend it doesn't exist.) Please note that this challenge is an object-oriented one. I apologise now to people who prefer procedural or functional languages, and I will try to make such an exercise in the future. Before you do this, let me introduce you to what a complex number is.

Background
The complex number system was created by mathematicians to more intuitively solve certain problems involving square roots. It has long been known that you cannot conventionally compute the square root of a negative number, as there is no number which, when multiplied by itself, will produce a negative number. If the original number is positive, the squared number will obviously also be positive. If the original number is negative, the squared number is also positive as multilplying two negative numbers together produces a positive number.

However, this meant that certain mathematical equations involving square roots had no solutions. This was quite an inconvenience for mathematicians at the time - it meant that certain polynomial equations could not be solved, as they ended up trying to work out the square root of a negative number. At some point, someone had the bright idea of ignoring the fact that you can't square root negatives. What if you pretended that the square root of -1 did exist? This is exactly what happened, and the value was defined as the imaginary unit, or i (imaginary as in the classical understanding of numbers, it doesn't actually exist). Therefore, i=√(-1). Using algebra this lets you square root other negative numbers as multiples of i, as √(ab) = √(a) * √(b).

√(-4) = √4 * √(-1) = √4 * i = 2 * i = 2i

√(-7) = √7 * √(-1) = √7 i

And so on. These numbers are called imaginary numbers. On their own they are useful, but they really come into their own when paired with normal numbera (aka real numbers, to distinguish them from imaginary numbers.) An example of a complex number would be 2+3i or 0.5-2.2i. These complex numbers are split into two bits, as you can see: the real component and the imaginary component. For example, given the complex number 3-7i, the real component is 3 and the imaginary component is -7i. Hence, a normal real number can be represented as a complex number with imaginary component 0i, like 2+0i.

Adding or subtracting two complex numbers is relatively simple. To do so, just add/subtract each component individually. For example, 1+3i add 3-2i equals 4+i. This requires no further explanation as there isn't much else to it.

Multiplying complex numbers is a bit more involved but still simple. Multiply the two complex numbers as you would an algebraic expression. For example, to multiply 1+3i and 3-2i, multiply each component together and add them all:

1	3i
3	3	9i
-2i	-2i	-6i2
Now, recall that i=√(-1). Hence, i2=-1. Therefore, -6i2=6. This means 1+3i multiplied by 3-2i equals 3+9i-2i+6, which is 9+7i.

To visualise it, you could plot these complex numbers on the number line. But wait... how would you do that? How can you represent the imaginary component on the number line without it floating somewhere above the line? In fact, that's essentially exactly what happens - an Argand diagram is used to do this. An Argand diagram representing the complex number 3-2i looks like this. This diagram can be used to compute a value of a complex number called the modulus, which is, is essence, the 'distance from zero' on the diagram - ie. the length of the grey line, which can be computed with Pythagoras' theorem. In this case, the modulus is √(32+(-2)2), which is √13.

Finally, there is another value of complex numbers, that is easy to work out. To work out the complex conjugate of a complex number, simply invert the sign of the imaginary component. For example, the complex conjugate of 3-2i is 3+2i. Simple.

Specification
You are to implement a class representing a complex number.

It is to be represented by floating-point number fields for the Real and Imaginary components.

It is to expose a method GetModulus which returns a floating point number representing the modulus of the complex number.

It is to expose a method GetConjugate which returns another Complex number representing the complex conjugate.

It is to have 3 static/shared/classifier methods, each taking 2 parameters, for the 3 operations Add, Subtract and Multiply, each performing its respective operation and returning a Complex with the result of the operation.

It is to expose a method ToString which converts the complex number to its string representation correctly: eg. "3-2i", "1-i" or "13".

The UML diagram for the Complex class looks like this.

Extension
If you are feeling up to it, implement these, too:

It is to expose a method GetArgument which returns a floating point angle, in radians, representing the argument of the complex number.

It is to have another static method taking 2 parameters for the operation Divide, which divides two complex numbers.

The UML diagram for the extended Complex class looks like this.

Making Use of your Language
The main challenge of this exercise is knowing your language and its features, and adapting your solution to them. For example, in Ruby, you would not write a ToString method - you would write a to_s method, as that is the standard in Ruby. In C++ and C#, you would not write static Add, Multiply methods. You would instead overload the +, -, *, / operators, and rather than writing a GetModulus method you would write a Modulus property. Knowing and using these features that programming language provide is an important part of software development.

You should also be writing clean, legible code. Follow the style guide for your language, and use the correct naming/capitalisation conventions, which differ from language to language.

*/

#include <iostream>
#include <complex>

using namespace std;

int main()
{
	complex<double> x = 1.0 + 2i;
	complex<double> y = 2.0 + 3i;
	cout << x << endl;
	cout << y << endl;
	cout << "Argument: " << arg(x) << endl;
	cout << "Conjugate: " << conj(x) << endl;
	cout << "Modulus: " << abs(x) << endl;
	cout << "Addition: " << (x + y) << endl;
	cout << "Subtraction: " << (x - y) << endl;
	cout << "Multiplication: " << (x * y) << endl;
	cout << "Division: " << (x / y) << endl;

	return 0;
}
