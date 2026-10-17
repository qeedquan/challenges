/*

The Definition
Given an integer x, a version series is a set of digits (base 10) from which any x-length subset of consecutive members is unique compared to all other possible subsets of the same length (a unique "version").

The Task
Write a function which, when passed some subset length x, produces a version series, considering a scoring determined by the sum of the total number of characters outputted by inputs 1 through 10 (so, f(1) + f(2) + ... + f(10)).

Further rules
The output must always be the same for a specific x.
Please do not change your algorithm (except for corrections) after posting and try to avoid using others' work.
Examples
Let f(x) be the function which returns the version series.

>>> f(3)
0010111
Note that this is a valid version series as all possible consecutive subsets of length 3 (001, 010, 011, 111) are unique. This would obviously be a terrible score, however.

>>> f(3)
0123456789876543210
This is another valid version series, with a slightly better score. This is valid for the same reasoning as before.

>>> f(3)
001010011110111
This is clearly not valid; the subsets 001, 010, 101, 111 all occur more than once.

Trivia
I have referred to this as a version series as it may be used to identify a range of compatible versions by taking a larger subset of consecutive values within the full set to identify a range of compatible versions that lie therein.

Verifier (in Java)
import java.util.Scanner;
import java.util.ArrayList;

public class Checker {
    public static void main(String[] args) throws Exception {
        int substringLength = Integer.parseInt(args[0]);

        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("");

        ArrayList<Character[]> active = new ArrayList<Character[]>();

        Character[] current = new Character[substringLength],
            compare, prev;

        for (int i = 0; i < substringLength; i++) {
            current[i] = sc.next().charAt(0);
        }

        for (int index = 0; sc.hasNext(); index++) {
            for (int k = 0; k < index; k++) {
                boolean differ = false;
                compare = active.get(k);
                for (int j = 0; j < substringLength; j++) {
                    differ = differ || compare[j].compareTo(current[j]) != 0;
                }
                if (!differ)
                    throw new Exception("Match found for subset " + index);
            }
            active.add(current);
            prev = current;
            current = new Character[substringLength];
            for (int k = 1; k < substringLength; k++) {
                current[k - 1] = prev[k];
            }
            current[substringLength - 1] = sc.next().charAt(0);
        }

        System.out.println("Input is a valid version series.");
    }
}
Compile this as Checker.java, and call with program <x> | java Checker <x>, where x is your input (obviously, the input to your program is flexible).

If you are unable (or unwilling) to use Java, you may implement your own verifier, as long as you post it with your answer and show that it works.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 0; i <= 4; i++ {
		fmt.Println(series(i))
	}
}

// ported from @mbomb007 solution
func series(n int) string {
	const digits = "1234567890"

	if n < 1 {
		return ""
	}

	s := strings.Repeat("0", n)
loop:
	for {
		for _, c := range digits {
			t := fmt.Sprintf("%s%c", s, c)
			if strings.Index(s, t[len(t)-n:]) < 0 {
				s = t
				continue loop
			}
		}
		return s
	}
}
