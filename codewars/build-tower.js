/*

Build Tower
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Python: return a list;
JavaScript: returns an Array;
C#: returns a string[];
PHP: returns an array;
C++: returns a vector<string>;
Haskell: returns a [String];
Ruby: returns an Array;
Lua: returns a Table;
Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ', 
  ' *** ', 
  '*****'
]
and a tower of 6 floors looks like below

[
  '     *     ', 
  '    ***    ', 
  '   *****   ', 
  '  *******  ', 
  ' ********* ', 
  '***********'
]

*/

function build(floors) {
	let tower = [];
	for (let i = 0; i < floors; i++) {
		let spaces = floors - (i + 1);
		let stars = (floors*2 - 1) - spaces*2;

		tower[i] = '';
		for (let j = 0; j < spaces; j++)
			tower[i] += ' ';
		for (let j = 0; j < stars; j++)
			tower[i] += '*';
		for (let j = 0; j < spaces; j++)
			tower[i] += ' ';
	}
	return tower;
}

for (let i = 1; i <= 6; i++)
	console.log(JSON.stringify(build(i), null, 4));

