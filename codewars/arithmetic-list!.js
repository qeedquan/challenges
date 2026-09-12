/*

In this kata, you will write an arithmetic list which is basically a list that contains consecutive terms in the sequence.
You will be given three parameters :

first the first term in the sequence
c the constant that you are going to ADD ( since it is an arithmetic sequence...)
l the number of terms that should be returned

Useful link: Sequence (http://en.wikipedia.org/wiki/Sequence)

*/

function seqlist(first, constant, length) {
	return Array.from({ length: length }, (_, i) => first + i*constant);
}

console.log(seqlist(20, 4, 5));

