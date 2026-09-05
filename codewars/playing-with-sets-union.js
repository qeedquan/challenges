/*

Set objects are new JavaScript built-in objects defined since ECMAScript 2015

A Set lets you store unique values of any type. It comes with some useful methods like .add, .clear, .has . . . BUT some "Set operations" are missing, like . . .

Union

https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/Venn0111.svg/330px-Venn0111.svg.png

Two sets can be "added" together. The union of A and B, denoted by A ∪ B, is the set of all things that are members of either A or B.

Examples:
  {1, 2} ∪ {1, 2} = {1, 2}.
  {1, 2} ∪ {2, 3} = {1, 2, 3}.
  {1, 2, 3} ∪ {3, 4, 5} = {1, 2, 3, 4, 5}

Task
Create function union getting 2 sets as arguments and returning a new Set as result of union of these 2 sets.

Examples:
A = new Set([1,2]);
B = new Set([2,3]);

C = union(A,B) // -> {1,2,3}


" May the Code be with you ! "

*/

function union(set1, set2) {
	return new Set([...Array.from(set1), ...Array.from(set2)]);
}

let A = new Set([1,2]);
let B = new Set([2,3]);
let C = union(A, B);
console.log(C);

