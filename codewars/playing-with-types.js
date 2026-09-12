/*

JavaScript is a dynamically typed programming language. This means that you don't have to specify what kind of information a variable contains, but sometimes it's useful to know it.

You have to implement a typing() function that takes a parameter and is able to tell the type and value of it.

For example:

typing(2);            //returns "number=2"
typing(true);         //returns "boolean=true"
typing("test");       //returns "string="test""
typing([1,2,3]);      //returns "object=[1,2,3]"
typing({a:1,b:2});    //returns "object={"a":1,"b":2}"
typing(function(){}); //returns "function=function (){}"
typing(undefined);    //returns "undefined"

*/

function typing(param) {
	let type = typeof param;
	if (param === undefined)
		return 'undefined';
	if (type === 'string')
		return `${type}="${param}"`;
	if (type != 'object')
		return `${type}=${param.toString()}`;
	if (Array.isArray(param))
		return `${type}=[${param.join(',')}]`;

	let entries = Object.entries(param);
	let string = `${type}={`;
	for ([key, value] of entries) {
		string += `"${key}":`;
		if (typeof value === 'string')
			string += `"${value}"`;
		else
			string += `${value}`;
		string += ",";
	}
	if (string.endsWith(","))
		string = string.slice(0, -1);
	string += "}";

	return string;
}

console.log(typing(2)); 
console.log(typing(true)); 
console.log(typing("test")); 
console.log(typing([1, 2, 3]));
console.log(typing({a:1, b:2}));
console.log(typing(function(){})); 
console.log(typing(undefined));
