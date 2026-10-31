/*

Challenge:
Output the 'integer-digits' of one of the following six arithmetic-tables based on the input:
- addition (+);
- subtraction (-);
- multiplication (*);
- division (/);
- exponentiation (^);
- modulo operation (%).

Rules:
What do I define as 'integer-digits': Every result of the arithmetic operand which is exactly one of the following: 0,1,2,3,4,5,6,7,8,9. This means you exclude every result of 10 or higher, every result of -1 or lower, and every non-integer result.
How do we calculate the arithmetic results: By using the top digit first, and then use the operand with the left digit. You are allowed to do this vice-versa (i.e. y/x instead of x/y), as long as you're consistent for all six of the outputs! (So you aren't allowed to use y-x and x/y in the same answer.)†
We won't output anything for divide by 0 test-cases (for the division and modulo operation tables)
We won't output anything for the edge-case 0^0.
Output:
So output the following (table format is somewhat flexible (see below): so the lines are optional and mainly added for readability of the test cases):

Addition:

+ | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 | 0 1 2 3 4 5 6 7 8 9
1 | 1 2 3 4 5 6 7 8 9
2 | 2 3 4 5 6 7 8 9
3 | 3 4 5 6 7 8 9
4 | 4 5 6 7 8 9
5 | 5 6 7 8 9
6 | 6 7 8 9
7 | 7 8 9
8 | 8 9
9 | 9

Subtraction:

- | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 | 0 1 2 3 4 5 6 7 8 9
1 |   0 1 2 3 4 5 6 7 8
2 |     0 1 2 3 4 5 6 7
3 |       0 1 2 3 4 5 6
4 |         0 1 2 3 4 5
5 |           0 1 2 3 4
6 |             0 1 2 3
7 |               0 1 2
8 |                 0 1
9 |                   0

Multiplication:

* | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 | 0 0 0 0 0 0 0 0 0 0
1 | 0 1 2 3 4 5 6 7 8 9
2 | 0 2 4 6 8
3 | 0 3 6 9
4 | 0 4 8
5 | 0 5
6 | 0 6
7 | 0 7
8 | 0 8
9 | 0 9

Division:

/ | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 | 
1 | 0 1 2 3 4 5 6 7 8 9
2 | 0   1   2   3   4
3 | 0     1     2     3
4 | 0       1       2
5 | 0         1
6 | 0           1
7 | 0             1
8 | 0               1
9 | 0                 1

Exponentiation:

^ | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 |   1 1 1 1 1 1 1 1 1
1 | 0 1 2 3 4 5 6 7 8 9
2 | 0 1 4 9
3 | 0 1 8
4 | 0 1
5 | 0 1
6 | 0 1
7 | 0 1
8 | 0 1
9 | 0 1

Modulo:

% | 0 1 2 3 4 5 6 7 8 9
-----------------------
0 | 
1 | 0 0 0 0 0 0 0 0 0 0
2 | 0 1 0 1 0 1 0 1 0 1
3 | 0 1 2 0 1 2 0 1 2 0
4 | 0 1 2 3 0 1 2 3 0 1
5 | 0 1 2 3 4 0 1 2 3 4
6 | 0 1 2 3 4 5 0 1 2 3
7 | 0 1 2 3 4 5 6 0 1 2
8 | 0 1 2 3 4 5 6 7 0 1
9 | 0 1 2 3 4 5 6 7 8 0

Challenge rules:
Trailing new-lines and trailing spaces are optional
The horizontal and vertical lines in the test cases are optional. I only added them for better readability.†
The spaces between each result are NOT optional.
The symbol for the arithmetic may be different, as long as it's clear which one it is. I.e. × or · instead of * for multiplication; ÷ instead of / for division; etc.†
And as long as it's a single character, so sorry Python's **.
The input format is flexible. You can choose an index from 0-5 or 1-6 for the corresponding six tables; you could input the operand-symbol; etc. (Unlike what you display in the result, you are allowed to input complete strings, or ** in Python's case.)
Just make sure to state which input-format you use in your answer!

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
† Example of valid output without horizontal and vertical lines, ÷ as symbol, and using y/x instead of x/y:

÷ 0 1 2 3 4 5 6 7 8 9
0   0 0 0 0 0 0 0 0 0
1   1
2   2 1
3   3   1
4   4 2   1
5   5       1
6   6 3 2     1
7   7           1
8   8 4   2       1
9   9   3           1

*/

function binop(op, x, y) {
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		if (y == 0 || x%y != 0)
			return -1;
		return x / y;
	case '%':
		return (y) ? x%y : -1;
	case '^':
		if (x == 0 && y == 0)
			return -1;
		return Math.pow(x, y);
	}
}

function table(op) {
	process.stdout.write(`${op} | `);
	for (let x = 0; x <= 9; x++) {
		process.stdout.write(`${x}`);
		if (x < 9)
			process.stdout.write(` `);
	}
	console.log(`\n-----------------------`);
	for (let x = 0; x <= 9; x++) {
		process.stdout.write(`${x} | `);
		for (let y = 0; y <= 9; y++) {
			let z = binop(op, y, x);
			if (0 <= z && z <= 9)
				process.stdout.write(`${z}`);
			else
				process.stdout.write(` `);
			if (y < 9)
				process.stdout.write(` `);
		}
		console.log();
	}
	console.log();
}

function main() {
	table('+');
	table('-');
	table('*');
	table('/');
	table('^');
	table('%');
}

main();
