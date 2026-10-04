/*

You're given a procedure / method that executes a passed action n times, but it does so in a purely sequential manner. If you inspect the sample tests, you'll find that the action takes about 1 second to complete, and this action is repeated 20 times which results in a timeout.

Find a way to execute the action n times in parallel, such that the sample tests complete under the 12 second time limit imposed by Codewars. The submission tests will also test for similar scenarios.

Hint: If you're not sure where to start, read up on threads ( https://en.wikipedia.org/wiki/Thread_%28computing%29 ).

*/

async function execute(action, times) {
	await Promise.all(Array.from({ length: times }, (_) => action()));
}

function print() {
	console.log("><");
}

execute(print, 20);
