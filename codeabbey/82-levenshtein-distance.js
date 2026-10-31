/*

Nowadays many applications perform spell-checking as you type in text. Among first programs to implement this feature was Microsoft Word - you know, you type the misspelled word and it is marked with red wavy line below.

You also know that usually such spell-checking not only checks the word in question by some internal vocabulary, but also suggests some substitutions. For example if you enter crain you are proposed to change it to brain, train or chain.

How these substitutions are chosen? One of the basic and popular solution is to run through vocabulary and calculate the Levenshtein Distance between the misspelled word and each of dictionary words. Words which give minimal distance are, probably, the best substitutions.

What is the Levenshtein Distance?

Shortly speaking it is the diference between two strings. Levenshtein distance counts 1 point of penalty for each of three mismatch kind:

the letter is present in the first string but absent in the second (like plain and plan);
the letter is absent in the first string but present in the second (like tree and three);
the letter is different in the same position of two words (like woman and women).
As an example, let us see what is the distance between hate and shot:

hate -> hat      (one letter removed)
hat  -> hot      (one letter substituted)
hot  -> shot     (one letter inserted)
So the distance is 3.

Your task now is simply to calculate the Levenshtein Distance between two strings. There are different algorithms, of which most popular uses dynamic programming with a table M by N (however it could be reduced to only two lines, previous and current, reassigned after each current line is completed). You can read more in the wikipedia article on Levenshtein Distance or get info from many other sources.

Input data will contain the number of test-cases in the first line.
Next lines will contain 2 "words" each - words will contain of capital latin letters only.
Answer should contain the distances for each pair of words, separated by spaces.

Example:

input data:
5
PLAIN PLAN
TREE THREE
WOMAN WOMEN
KITTEN SITTING
YPOEHOHRIWUBXMNHZF YCPOEHORIDUBXNHZF

answer:
1 1 1 3 4
Note: this algorithm works good for languages where words are pronounced similarly to how they are spelled, like Italian, Russian, German etc. However, it is not very good for English, where women is pronounced like weeman etc., so the English have more special and complicated algorithms, like Soundex.

*/

var assert = require('assert');

function memoize(fn) {
    const cache = new Map();

    return function(...args) {
        const key = JSON.stringify(args);

        if (cache.has(key)) {
            return cache.get(key);
        }

        const result = fn.apply(this, args);
        cache.set(key, result);
        return result;
    };
}

function lev(a, b) {
    if (b.length == 0)
        return a.length;

    if (a.length == 0)
        return b.length;

    if (a[0] == b[0])
        return lev(a.slice(1), b.slice(1));

    let x = lev(a.slice(1), b);
    let y = lev(a, b.slice(1));
    let z = lev(a.slice(1), b.slice(1));
    return 1 + Math.min(x, y, z);
}

function main() {
    lev = memoize(lev);
    assert(lev("PLAIN", "PLAN") == 1);
    assert(lev("TREE", "THREE") == 1);
    assert(lev("WOMAN", "WOMEN") == 1);
    assert(lev("KITTEN", "SITTING") == 3);
    assert(lev("YPOEHOHRIWUBXMNHZF", "YCPOEHORIDUBXNHZF") == 4);
}

main();
