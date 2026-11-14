/*

Challenge
You find yourself in a bash terminal, and want to do some simple tests on sqlite3.

So you issue the following command:

echo "CREATE TABLE T (id INT NON NULL PRIMARY KEY)" | sqlite3 test.db
Now you want to insert the first N integers (starting from 0, excluding N) into the table T.

For convenience, you execute the following

N=5 # value arbitrary and large, not known for purposes of the challenge
Now for the example case of N == 5, you would have to execute the following SQL command:

echo "INSERT INTO T VALUES (0), (1), (2), (3), (4);" | sqlite3 test.db
But of course, N is large, so you want to come op with a bash oneliner to dynamically generate and execute the SQL statement to insert these values.

Rules
The result of entering the command string into the presented bash teminal session (and pressing enter) should be the modification of test.db as described in the challenge.

You must not leave behind any unintended artifacts on disk (ignoring command histories etc.)

Any cli tool can be called and considered installed, e.g. python -c, ghci -e, awk, ...

The final command string must be a single line of characters enterable in the bash terminal session described above (if we want to get technical, the command string cannot contain a byte with value 10 (LF))

Your command string must be valid UTF-8

You don't absolutely have to end in | sqlite3 test.db, if the tools you are using have some built in way to write to test.db, that can be used aswell. (Although it might not help you that much, see the scoring).

If you are using tools where it is not obvious how to install them for others (let's just say, if the are not available as a Debian Package), please add a link on where to get them.

Scoring
Score shall be based on the following metric, which tries to favor elegant and readable solutions:

+100 Points by default so we don't have to look at that many negative scores.

-5 points for every character not in the printable ASCII range (values 32-127, )

-3 points for every 10 characters above 80 (e.g. 89: -0, 90: -3, 99: -3, 100: -6)

-2 points for every use of \

-1 point for every use of any of these characters: (){}[]'"` (trying to punish nesting here, sorry LISP fans)

The tie breaker are the upvotes, which I hope will respect the spirit of elegant / readable solutions.

Highest Score wins !

Non competing example solution in Haskell to demonstrate Scoring:

ghci -e 'import Data.List' -e 'putStr $ "insert into T values" ++ (concat $ intersperse "," $ map (\i -> "(" ++ show i ++ ")") [0..'$N']) ++ ";"' | sqlite3 test.db
Default:                  = 100
Non Ascii:        0  * -5 =  -0
Length: 164:      8  * -3 = -24
Backslashes:      1  * -2 =  -2
Special Chars:    24 * -1 = -24
--------------------------------
Total Points:                50

*/

#include <stdio.h>

void
gen(int n)
{
	int i;

	printf("INSERT INTO T VALUES ");
	for (i = 0; i < n; i++) {
		printf("(%d)", i);
		if (i + 1 < n)
			printf(", ");
	}
	printf(";\n");
}

int
main(void)
{
	gen(5);
	return 0;
}
