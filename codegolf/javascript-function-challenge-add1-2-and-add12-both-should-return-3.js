/*

A friend of mine challenged me to write a function that works with both of these scenarios

add(1,2)  // 3
add(1)(2) // 3
My instinct was the write an add() function that returns itself but I'm not sure I'm heading in the right direction. This failed.

function add(num1, num2){
    if (num1 && num2){
        return num1 + num2;
    } else {
        return this;
    }
}

alert(add(1)(2));
So I started reading up on functions that return other functions or return themselves.

http://davidwalsh.name/javascript-functions https://stackoverflow.com/questions/17235259/javascript-self-calling-function-returns-a-closure-what-is-it-for https://stackoverflow.com/questions/17235259/javascript-self-calling-function-returns-a-closure-what-is-it-for

I am going to keep trying, but if someone out there has a slick solution, I'd love to see it!

*/

function add(a, b) {
	if (typeof b == "undefined")
		return function(c) { return a + c; }
	return a + b;
}

function main() {
	console.log(add(2, 3), add(2)(3))
}

main();
