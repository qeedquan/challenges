/*

+-= is a language created by Esolangs user Anonymous in 2017.
The language consists of only three commands:

+ increases the accumulator by one.
- decreases the accumulator by one.
= outputs the accumulator and a newline.
Rules
This is code-golf, all usual golfing rules apply.
Standard rules apply.
You may assume input will be valid.
Interpreters must get input once and output the result.
Test cases
+++++=
5

+=+=+=+=+=+=+=+=+=+=
1
2
3
4
5
6
7
8
9
10

+++==
3
3

+-=
0

=
0

-=
-1

---=++-=
-3
-2

*/

function interpret(code) {
	console.log(code);
	let ac = 0;
	for (let i = 0; i < code.length; i++) {
		switch (code[i]) {
		case '+':
			ac += 1;
			break;

		case '-':
			ac -= 1;
			break;

		case '=':
			console.log(ac);
			break;
		}
	}
	console.log("");
	return ac;
}

function main() {
	interpret("+++++=");
	interpret("+=+=+=+=+=+=+=+=+=+=");
	interpret("+++==");
	interpret("+-=");
	interpret("=");
	interpret("-=");
	interpret("---=++-=");
}

main();
