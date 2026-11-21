/*

In this challenge you've to print multiplication tables by input, Here are some examples:

Input: 2

Output:
0 2  4 6 8  10  12  14  16  18  20

Input: 20

Output: 20 40 60 80 100 120 140 160 180 200
Rules
The shortest code in bytes wins.

This challenge is a code-golf, It follows code-golf general rules (code-golf)

If, just if, your code can't print number, you can use letters, Here is an example:

Input: B

Output: B D F H J L N P R T

You can choose to start from 0 or your number (like 20). You can choose if put spaces or don't. The challenge is free, just take an input and print multiplication tables.

Your output must list the first 10 members of the times table for the given number. You may leave out 0*n.

*/

function table(n) {
	var l = 10;
	for (var i = 0; i <= l; i++) {
		process.stdout.write('' + (i * n));
		if (i != l)
			process.stdout.write(' ');
	}
	console.log();
}

function main() {
	table(2);
	table(20);
}

main();
