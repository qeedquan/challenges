/*

PUZZLE #1. SUM

Assignment:

Write a function named sum which performs addition in the way shown below

sum(4)(5)(9)(); // => 18
sum(5)();       // => 5
sum();          // => 0
```ruby sum(4).(5).(9).() #=> 18 sum(5).() #=> 5 sum() #=> 0

NOTE: Pay attention that last brackets are left empty to indicate end of operations

Thanks to @JohanWiltink, @donaldsebleung

*/

function sum() {
	let total = 0;
	const next = (value=null) => {
    	if (value === null)
			return total;
		total += value;
		return next;
	};
	return next(arguments[0]);
}

console.log(sum(4)(5)(9)());
console.log(sum(5)());
console.log(sum());

