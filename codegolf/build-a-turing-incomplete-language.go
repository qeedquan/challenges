/*

The world is full of Turing-complete programming languages. Just about every useful language (and most useless ones) are Turing-complete. Some even became Turing-complete by accident. Often this is great, since every Turing-complete language supports the same power of universal computation. But the power of Turing completeness also comes with a curse! The halting problem is undecidable for arbitrary programs in a Turing-complete language, and more generally, it’s impossible to analyze arbitrary programs in any non-trivial way. Sometimes we need less powerful languages.

It takes great care to design a useful language that falls short of Turing completeness. That’s the subject of this challenge!

Requirements
Write an interpreter that will accept a program and some input for the program, and produce some output. The program, input, and output are given using simple data types of your choice.

Examples of “simple” data types: booleans; numbers; strings (bytes or Unicode); arrays or mappings of simple data types; algebraic data types defined in your interpreter.

Examples of data types not considered “simple”: function expressions; a subset of strings representing valid programs in some language (unless the subset is validated by your interpreter); generalized algebraic data types. (This restriction is intended to disqualify trivial answers such as the identity function in Agda.)

Your input format must include some way to express arbitrarily sized natural numbers, in a reasonable representation of your choice (e.g. arrays or strings of unary, binary, or decimal digits, or directly as big integers if your host language has them). Your output format must include at least two values, distinguishable from each other, to represent “true” and “false”. Whether the formats can express anything else is up to you.

You may interpret programs in any target language, existing or new, under three conditions:

Your interpreter must be observably deterministic: for a given program and input, you must always produce the same output.

Your interpreter must not be Turing-complete. Explain why this is the case—for example, it might be Turing incomplete because the interpreter eventually halts on every program and input, or because its halting problem is otherwise decidable.

As a minimum standard of usefulness, your target language must be able to express every polynomial-time function from natural numbers to booleans. Explain why this is the case. (To be clear, “polynomial-time” is defined over the length of the input in binary bits, even if your chosen representation of naturals is less efficient.)

Whether any other functions are expressible is up to you—for example, you might design your language around the primitive recursive functions, the elementary functions, or Gödel’s System T, each of which includes all polynomial-time functions.

Your interpreter may be written in any existing host language. You may assume it runs on an ideal machine with unlimited memory and pointers big enough to access it.

This is code-golf: make the shortest interpreter you can!

Clarifications
I believe these points follow from the requirements, but they’re listed here in the hope of being helpful. Feel free to request additional clarifications in the comments.

As per our default rules, your interpreter will be a program or function that follows our usual conventions for input and output. However, programs in your target language are not bound by these rules—for example, if you decide that programs in your target language will be snippets that perform I/O by accessing a predefined variable, that is fine, as long as your interpreter translates this convention by (say) automatically reading from STDIN to the variable at startup and writing the variable to STDOUT at exit. (This can be viewed as a natural consequence of our policy that languages are defined by their interpreters.)

You may of course use any data types you want within your language, as long as the program, input, and output types are simple data types.

Your interpreter must be prepared to accept anything in your chosen simple data type for programs as a program. Your interpreter may of course perform extra validity checks on the program and throw errors or fall back to some default behavior or do something else that respects the requirements—but you may not impose extra validity constraints on programs purely at the specification level. Writing “eval but you’re not allowed to pass in anything except deterministic programs that halt” does not solve this challenge.

Because of the determinism requirement, an interpreter that works by executing arbitrary code with a timeout in seconds is unlikely to be valid. (Doubly so if it leaves programs enough wiggle room to disable or evade the timeout in some underhanded way.)

Although I am willing to be may already have been proven wrong, my expectation is that solving this challenge will require doing some actual work to interpret a language. I’m not looking for solutions that put in 1% of this work to satisfy 80% of the requirements, whatever that means—that wouldn’t be fair to those who put in the effort to solve the full challenge as written.

I updated the challenge with a requirement for the representation of natural number inputs to be “reasonable” after realizing there was a loophole using an unreasonable representation of naturals.
Specifically: if we enumerate all polynomial-time functions as p0,p1,p2,…, the unreasonable representation of n∈N as (p0(n),p1(n),…,pn−1(n)) allows any polynomial-time function pm to be “programmed” as {0↦pm(0),1↦pm(1),…,m↦pm(m),n↦nm for n>m}, with every output hard-coded into either the program or the input! (I don’t think any of the existing answers have tried to exploit such an unreasonable representation.)

Related challenges
Write a Programming language of Unknown Completeness
Turing-Complete Language Interpreter
Design a One Instruction Set Computer!
Fewest (distinct) characters for Turing Completeness
Escape from the tarpit

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
)

func main() {
	el := newelementary()
	el.Set("n", 2)
	el.Set("m", 4)
	fmt.Println(el.Eval("(2^n) + (n*m) + (n*n) * (n%m) + (2^n) + (2^(n+m))"))
}

/*

https://en.wikipedia.org/w/index.php?title=ELEMENTARY#Basis_for_ELEMENTARY

@xnor

lambda s,n:s.strip("()+*%n")or eval(s)

This evaluates a subset of Python 2 given by arithmetic expressions using only characters ()+*%n, acting on natural-number input n.
This computes the class ELEMENTARY, as the closure of the expressions in the basis

{n+m,n^2,n mod m,2^n}

as noted in the Wikipedia article on ELEMENTARY and proven in Superpositions of elementary arithmetic functions.
This moreover shows that Python operators can not only do primality testing, but any polynomial-time computable function.

The paper's argument seems to be based on constructions similar to Lopsy's prime-testing solution, encoding lists as digits in a large base and expressing bounded summation on those elements via arithmetic operations.
The proof uses this expression for binomial coefficients as an intermediate step.

We check that our operators can express all operations in the basis.
The +, **, and % operators do addition, exponent, and modulo.
We can get the 2 for n^2 and 2^n as 2=0^0 + 0^0, where 0 is n**n%n**n, avoiding the modulo-by-zero that simply n%n would give for n=0.
Parentheses allow arbitrary composition of sub-expressions, and projection is trivial.
We can interpret outputs as Booleans by associating True=1, False=0, as is standard in Python.

To ensure we that only this subset can be evaluated, we check that the input expression s is limited to the characters ()+*%n by stripping them from s and returning what remains if non-empty.
Note that an invalid string is never evaluated, rather than evaluated then discarded, preventing it from anything strange it could call or overwrite to allow its output to escape.

The really isn't anything extra that's non-trivial that can be done with the whitelisted characters that we might worry allows Turing completeness. The letter n alone can't spell any function or keyword.
We can get multiplication with *, but this is of course elementary. We can't even get negative numbers or floats, though these would still be harmless. We can get the empty tuple (), but nothing interesting can be done with it.

*/

type Elementary struct {
	vars map[string]int
}

func newelementary() *Elementary {
	return &Elementary{
		vars: make(map[string]int),
	}
}

func (c *Elementary) Set(name string, value int) {
	c.vars[name] = value
}

func (c *Elementary) Eval(expr string) (int, error) {
	node, err := parser.ParseExpr(expr)
	if err != nil {
		return 0, err
	}
	return c.walk(node)
}

func (c *Elementary) walk(node ast.Expr) (value int, err error) {
	switch node := node.(type) {
	case *ast.BinaryExpr:
		x, lhserr := c.walk(node.X)
		y, rhserr := c.walk(node.Y)
		if lhserr != nil {
			err = lhserr
		} else if rhserr != nil {
			err = rhserr
		}

		switch node.Op {
		case token.ADD:
			value = x + y
		case token.MUL:
			value = x * y
		case token.REM:
			if y != 0 {
				value = x % y
			} else {
				err = fmt.Errorf("cannot mod by zero")
			}
		case token.XOR:
			if x != 2 {
				err = fmt.Errorf("only exponentiation by 2 is supported")
			}
			value = 1 << y
		default:
			err = fmt.Errorf("unknown binary operation %v", node.Op)
		}

	case *ast.Ident:
		x, found := c.vars[node.Name]
		if !found {
			err = fmt.Errorf("variable %q not found", node.Name)
		}
		value = x

	case *ast.BasicLit:
		value = 2
		if node.Value != "2" {
			err = fmt.Errorf("invalid basic literal %q", node.Value)
		}

	case *ast.ParenExpr:
		value, err = c.walk(node.X)

	default:
		err = fmt.Errorf("invalid expression %T", node)
	}

	return
}
