/*

You bought a tasty Orange in the supermarket and got 78 cents change. How many possible ways the supermarket guy can give you the change using 1,5,10 or 25 coins

Input: Change amount
Output: The number of possible ways to give the change.
Order is not important 1,5 is same as 5,1

Win conditions:

Best performance
Shortest code
Also please add the result for 78 in your title.

*/

function recurse(target, coins, value, result) {
	if (value > target) {
		return;
	}

	if (value == target) {
		console.log(result);
		return;
	}

	for (let i = 0; i < coins.length; i++) {
		result.push(coins[i]);
		recurse(target, coins, value + coins[i], result);
		result.pop();
	}
}

function solve(target, coins) {
	console.log(target);
	recurse(target, coins, 0, []);
}

function main() {
	solve(78, [1, 5, 10, 25]);
}

main();
