/*

Objectives: Output a String which contains every positive integer strictly below 1000.

The obvious answer would be to concatenate every one of them, and that would create a String of 2890 characters (thanks manatwork), to avoid this kind of easy answer, the length of the string must be under 1500 characters. Here is a straightforward Java code which outputs a 1200 chars String.

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

import static org.junit.Assert.assertTrue;

// Created with IntelliJ IDEA.
// User: fab
// Date: 05/11/13
// Time: 09:53
// To change this template use File | Settings | File Templates.
//
public class AStringToContainThemAll {

    @Test
    public void testsubStrings() throws Exception {
        String a = generateNewString();
        boolean cool = true;
        for (int i = 0; i < 1000; i++) {
            assertTrue(a.contains(Integer.toString(i)));
        }
    }

    private String generateNewString() {
        List<Integer> myTree = new ArrayList<Integer>();
        String finalString = new String("100");
        for (int i = 10; i < 1000; i++) {
            myTree.add(i);
        }
        while (myTree.size() > 0) {
            if (finalString.contains(Integer.toString(myTree.get(0)))) {
                myTree.remove(0);
            } else {
                String substringLong = finalString.substring(finalString.length() - 2, finalString.length());
                boolean found = false;
                loop:
                for (Integer integer : myTree) {
                    if (integer.toString().startsWith(substringLong) && !finalString.contains(integer.toString())) {
                        finalString = finalString.concat(integer.toString().substring(2, 3));
                        myTree.remove(integer);
                        found = true;
                        break loop;
                    }
                }
                if(! found){
                    finalString = finalString.concat(myTree.get(0).toString());
                    myTree.remove(0);
                }
            }


        }
        return finalString;
    }
}
Shortest code win, bonus point for the shortest String!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

@Peter Taylor

This is a variant on the Lyndon word concatenation approach: rather than use the primitive 1-char words it uses multiples of 111 for shorter code but repeated occurrences of those numbers;
and rather than use minimal elements of the conjugacy groups it uses maximal elements, because that shortens the loops.

Trying to make this do reverse strings runs into problems with omitting the multiples of 111.

To see that 999 is the optimal length (since my brief comments above don't convince everyone), start from the full de Bruijn sequence which (taken as a cyclic string) contains every 3-digit sequence of characters from 0 to 9.
Since there are 1000 of them, it must be at least 1000 characters long;
that it can be precisely 1000 characters long is usually proven by an Eulerian walk on a graph whose nodes are two-digit sequences xy with 10 edges, each labelled with one digit z, which take xy to yz.

We don't need sequences beginning 0, so given a de Bruijn sequence we can rotate to put 000 at the end.
Then we don't need either of the sequences which wrap round to the beginning, but we do need two of the 0s to finish the sequence starting with the digit before 000, so we can delete one of them to get a 999-character string.
Every remaining 0 is used in a number which doesn't begin with 0.

*/

const char *
number()
{
	return "100200300400500600700800901101201301401501601701801902102202302402502602702802903103203303403503603703803904104204304404504604704804905105205305405505605705805906106206306406506606706806907107207307407507607707807908108208308408508608708808909109209309409509609709809911121131141151161171181191221231241251261271281291321331341351361371381391421431441451461471481491521531541551561571581591621631641651661671681691721731741751761771781791821831841851861871881891921931941951961971981992223224225226227228229233234235236237238239243244245246247248249253254255256257258259263264265266267268269273274275276277278279283284285286287288289293294295296297298299333433533633733833934434534634734834935435535635735835936436536636736836937437537637737837938438538638738838939439539639739839944454464474484494554564574584594654664674684694754764774784794854864874884894954964974984995556557558559566567568569576577578579586587588589596597598599666766866967767867968768868969769869977787797887897987998889899900";
}

int
main()
{
	const char *s;
	char b[128];
	int i;

	s = number();
	for (i = 0; i <= 999; i++) {
		snprintf(b, sizeof(b), "%d", i);
		assert(strstr(s, b) != NULL);
	}

	return 0;
}
