/*

Description
In theoretical computer science, the closest string is an NP-hard computational problem, which tries to find the geometrical center of a set of input strings. To understand the word "center", it is necessary to define a distance between two strings. Usually, this problem is studied with the Hamming distance in mind. This center must be one of the input strings.

In bioinformatics, the closest string problem is an intensively studied facet of the problem of finding signals in DNA. In keeping with the bioinformatics utility, we'll use DNA sequences as examples.

Consider the following DNA sequences:

ATCAATATCAA
ATTAAATAACT
AATCCTTAAAC
CTACTTTCTTT
TCCCATCCTTT
ACTTCAATATA
Using the Hamming distance (the number of different characters between two sequences of the same length), the all-pairs distances of the above 6 sequences puts ATTAAATAACT at the center.

Input Description
You'll be given input with the first line an integer N telling you how many lines to read for the input, then that number of lines of strings. All strings will be the same length. Example:

4
CTCCATCACAC
AATATCTACAT
ACATTCTCCAT
CCTCCCCACTC
Output Description
Your program should emit the string from the input that's closest to all of them. Example:

AATATCTACAT
Challenge Input
11
AACACCCTATA
CTTCATCCACA
TTTCAATTTTC
ACAATCAAACC
ATTCTACAACT
ATTCCTTATTC
ACTTCTCTATT
TAAAACTCACC
CTTTTCCCACC
ACCTTTTCTCA
TACCACTACTT

21
ACAAAATCCTATCAAAAACTACCATACCAAT
ACTATACTTCTAATATCATTCATTACACTTT
TTAACTCCCATTATATATTATTAATTTACCC
CCAACATACTAAACTTATTTTTTAACTACCA
TTCTAAACATTACTCCTACACCTACATACCT
ATCATCAATTACCTAATAATTCCCAATTTAT
TCCCTAATCATACCATTTTACACTCAAAAAC
AATTCAAACTTTACACACCCCTCTCATCATC
CTCCATCTTATCATATAATAAACCAAATTTA
AAAAATCCATCATTTTTTAATTCCATTCCTT
CCACTCCAAACACAAAATTATTACAATAACA
ATATTTACTCACACAAACAATTACCATCACA
TTCAAATACAAATCTCAAAATCACCTTATTT
TCCTTTAACAACTTCCCTTATCTATCTATTC
CATCCATCCCAAAACTCTCACACATAACAAC
ATTACTTATACAAAATAACTACTCCCCAATA
TATATTTTAACCACTTACCAAAATCTCTACT
TCTTTTATATCCATAAATCCAACAACTCCTA
CTCTCAAACATATATTTCTATAACTCTTATC
ACAAATAATAAAACATCCATTTCATTCATAA
CACCACCAAACCTTATAATCCCCAACCACAC
Challenge Output
ATTCTACAACT

TTAACTCCCATTATATATTATTAATTTACCC
EDITED to correct the output of the first challenge.

Bonus
Try this with various other algorithms to measuring string similarity, not just the Hamming distance.

*/

var assert = require('assert');

function hamming(string1, string2) {
	let distance = 0;
	let length = Math.min(string1.length, string2.length);
	for (let index = 0; index < length; index++) {
		if (string1[index] != string2[index]) {
			distance += 1;
		}
	}
	return distance;
}

function argmin(array) {
	let lowest = 0;
	for (let index = 1; index < array.length; index++) {
		if (array[index] < array[lowest])
			lowest = index;
	}
	return lowest;
}

function lowest(strings) {
	let distances = [];
	for (string1 of strings) {
		let distance = 0;
		for (string2 of strings) {
			distance += hamming(string1, string2);
		}
		distances.push(distance);
	}
	let index = argmin(distances);
	return strings[index];
}

function main() {
	assert(lowest(['ATCAATATCAA', 'ATTAAATAACT', 'AATCCTTAAAC', 'CTACTTTCTTT', 'TCCCATCCTTT', 'ACTTCAATATA']) == 'ATTAAATAACT');
	assert(lowest(['CTCCATCACAC', 'AATATCTACAT', 'ACATTCTCCAT', 'CCTCCCCACTC']) == 'AATATCTACAT');
	assert(lowest(['AACACCCTATA', 'CTTCATCCACA', 'TTTCAATTTTC', 'ACAATCAAACC', 'ATTCTACAACT', 'ATTCCTTATTC', 'ACTTCTCTATT', 'TAAAACTCACC', 'CTTTTCCCACC', 'ACCTTTTCTCA', 'TACCACTACTT']) == 'ATTCTACAACT');
	assert(lowest(['ACAAAATCCTATCAAAAACTACCATACCAAT', 'ACTATACTTCTAATATCATTCATTACACTTT', 'TTAACTCCCATTATATATTATTAATTTACCC', 'CCAACATACTAAACTTATTTTTTAACTACCA', 'TTCTAAACATTACTCCTACACCTACATACCT', 'ATCATCAATTACCTAATAATTCCCAATTTAT', 'TCCCTAATCATACCATTTTACACTCAAAAAC', 'AATTCAAACTTTACACACCCCTCTCATCATC', 'CTCCATCTTATCATATAATAAACCAAATTTA', 'AAAAATCCATCATTTTTTAATTCCATTCCTT', 'CCACTCCAAACACAAAATTATTACAATAACA', 'ATATTTACTCACACAAACAATTACCATCACA', 'TTCAAATACAAATCTCAAAATCACCTTATTT', 'TCCTTTAACAACTTCCCTTATCTATCTATTC', 'CATCCATCCCAAAACTCTCACACATAACAAC', 'ATTACTTATACAAAATAACTACTCCCCAATA', 'TATATTTTAACCACTTACCAAAATCTCTACT', 'TCTTTTATATCCATAAATCCAACAACTCCTA', 'CTCTCAAACATATATTTCTATAACTCTTATC', 'ACAAATAATAAAACATCCATTTCATTCATAA', 'CACCACCAAACCTTATAATCCCCAACCACAC']) == 'TTAACTCCCATTATATATTATTAATTTACCC');
}

main();
