/*

While basic arithmetic operations like addition, subtraction, multiplication, etc. seem 'natural' to us, computers think on a very different level: under the hood, computations work with bitwise operations, using operators like ~, &, |, ^, and <<. Your task is to implement functions for (integer) addition, subtraction, negation, multiplication, division, modulo, and exponentiation, without using any "high-level" operators like + and *. Other statements like "if" and "while", or recursion for functional languages, are fine.

As a hint, you could start with a helper function that increments a binary number, and work from there. Your functions should take signed integer arguments and return signed integer values, rounding down (e.g. binary_div(14, 4) == 3, not 3.5).

Use your set of functions to implement this function:

f(a, b, c, d, e) = (a % e) * (b / (c - a) + exp(d * (-b), e))
What is the result of f(50, -40, 300, 2, 3)?

*/

function main() {
	console.log(f(50, -40, 300, 2, 3));
}

function f(a, b, c, d, e) {
	return mul(mod(a, e), add(quo(b, sub(c, a)), exp(mul(neg(b), d), e)));
}

function add(a, b) {
	let sum = a ^ b;
	let carry = a & b;
	while (carry) {
		carry <<= 1;
		a = sum;
		b = carry;
		sum = a ^ b;
		carry = a & b;
	}
	return sum;
}

function sub(a, b) {
	return add(a, neg(b));
}

function mul(a, b) {
	let sum = 0;
	let acc = b;
	while (acc) {
		sum = add(sum, a);
		acc = sub(acc, 1);
	}
	return sum;
}

function quo(a, b) {
	let acc = 0;
	while (a) {
		a = sub(a, b);
		if (a < 0)
			return acc;
		acc = add(acc, 1);
	}
	return acc;
}

function mod(a, b) {
	return sub(a, mul(b, quo(a, b)));
}

function exp(a, b) {
	let prod = 1;
	while (b) {
		prod = mul(prod, a);
		b = sub(b, 1);
	}

	return prod;
}

function neg(a) {
	return add(~a, 1);
}

main();
