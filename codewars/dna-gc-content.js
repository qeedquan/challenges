/*

The four bases found in DNA are adenine (A), cytosine (C), guanine (G) and thymine (T).

In genetics, GC-content is the percentage of Guanine (G) and Cytosine (C) bases on a DNA molecule that are either guanine or cytosine.

Given a DNA sequence (a string) return the GC-content in percent, rounded up to 2 decimal digits for Python, not rounded in all other languages.

For more information about GC-content you can take a look to wikipedia GC-content ( https://en.wikipedia.org/wiki/GC-content ).

For example: the GC-content of the following DNA sequence is 50%: "AAATTTCCCGGG".

*/

function gc(dna) {
	let count = 0;
	for (let i = 0; i < dna.length; i++) {
		if (dna[i] == 'C' || dna[i] == 'G')
			count += 1;
	}
	return count * 100 / dna.length;
}

console.log(gc("AAATTTCCCGGG"));

