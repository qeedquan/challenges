%{

The vowel letters in the Latin alphabet are A, E, I, O, U, and Y.
The remaining letters are considered consonants.
Write a program that counts the number of vowels in a given text.

Input
The input contains a single line of text consisting only of uppercase Latin letters and spaces.
The length of the string does not exceed 100 characters.

Output
Output one integer — the number of vowels in the input text.

Examples

Input #1
PROGRAMMING CONTEST

Answer #1
5

%}

function count = vowels(string)
	count = nnz(ismember(lower(string), 'aeiouy'));
end

vowels("PROGRAMMING CONTEST")
