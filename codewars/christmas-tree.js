/*

Create a function that returns a christmas tree of the correct height.

For example:

height = 5 should return:

    *    
   ***   
  *****  
 ******* 
*********
Height passed is always an integer between 0 and 100.

Use \n for newlines between each line.

Pad with spaces so each line is the same length. The last line having only stars, no spaces.

*/

function tree(n) {
	let r = [];
	for (let i = 1; i <= n; i++) {
		r.push(' '.repeat(n - i) + '*'.repeat(i + i - 1) + ' '.repeat(n - i));
	}
	return r.join('\n');
}

for (let i = 0; i <= 10; i++) {
	console.log(i);
	console.log(tree(i));
}
