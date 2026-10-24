/*

Write a program that takes in a string of the four characters ()[] that satisfies these points:

Every left parenthesis ( has a matching right parenthesis ).
Every left bracket [ has a matching right bracket ].
Matching pairs of parentheses and brackets won't overlap. e.g. [(]) is invalid because the matching brackets are not fully contained in the matching parentheses, nor vice-versa.
The first and last characters are a matching pair of parentheses or brackets. So ([]([])) and [[]([])] are valid but []([]) is not.
(A grammar for the input format is <input> ::= [<input>*] | (<input>*).)

Each pair of matching parentheses and brackets evaluates to a non-negative integer:

The values of pairs inside matching parentheses are all summed. The empty match () has value 0.
The values of pairs inside matching brackets are all multiplied. The empty match [] has value 1.
(The sum or product of one number is that same number.)

For example, ([](())([][])[()][([[][]][][])([][])]) can be broken down and evaluated as 9:

([](())([][])[()][([[][]][][])([][])])    <input>
(1 (0 )(1 1 )[0 ][([1 1 ]1 1 )(1 1 )])    <handle empty matches>
(1 0   2     0   [(1     1 1 )2     ])    <next level of matches>
(1 0   2     0   [3           2     ])    <and the next>
(1 0   2     0   6                   )    <and the next>
9                                         <final value to output>
Another example:

[([][][][][])([][][])([][][])(((((([][]))))))]    <input>
[(1 1 1 1 1 )(1 1 1 )(1 1 1 )((((((1 1 ))))))]
[5           3       3       (((((2     )))))]
[5           3       3       ((((2       ))))]
[5           3       3       (((2         )))]
[5           3       3       ((2           ))]
[5           3       3       (2             )]
[5           3       3       2               ]
90                                                <output>
Your program needs to evaluate and print the integer represented by the entire input string. You can assume the input is valid. The shortest code in bytes wins.

Instead of a program, you may write a function that takes in a string and prints or returns the integer.

*/

#include <assert.h>
#include <stdio.h>

int
rec(const char **s)
{
	int r;

	r = 0;
	switch (**s) {
	case '(':
		for (*s += 1; **s && **s != ')';)
			r += rec(s);
		*s += 1;
		break;

	case '[':
		r = 1;
		for (*s += 1; **s && **s != ']';)
			r *= rec(s);
		*s += 1;
		break;
	}
	return r;
}

int
eval(const char *s)
{
	return rec(&s);
}

int
main()
{
	assert(eval("([](())([][])[()][([[][]][][])([][])])") == 9);
	assert(eval("[([][][][][])([][][])([][][])(((((([][]))))))]") == 90);
	return 0;
}
