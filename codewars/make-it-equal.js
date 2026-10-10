/*

Here we have a strange looking expression.

(a == 2 && a == 3);

Your task is to make this expression true (see testcase).

HINT: javascript coercion rules.

*/

const a = {
	value: 2,
	toString() {
		return this.value++;
	},
};

if (a == 2 && a == 3) {
	console.log("got here");
}
