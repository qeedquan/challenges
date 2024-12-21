/*

Introduction
I'm a real big fan of the SBU (Short But Unique) challenges that crop up on PPCG all of the time. The CUSRS is a system designed to refactor strings, a CUSRS function takes 2 parameters and outputs 1 String.

Challenge
Produce a program, function, lambda or acceptable alternative to do the following:

Given String input and String refactor (as examples), refactor input using refactor as follows:

The refactor String will be in the format of ((\+|\-)\w* *)+ (regex), for example:

+Code -Golf -lf +al
Each section is a refactoring action to perform on input. Each program also has a pointer.

+ Will insert it's suffix (without the plus) at the pointers current location in the String and then reset the pointer to 0.

Each operation should be applied to the input String and the result should be returned.

Example:

input:
Golf +Code //pointer location: 0

output:
CodeGolf //pointer location: 0
- Will increment the pointer through the String until it finds the suffix. The suffix will be removed from the String and the pointer will be left on the left side of the removed text. If no suffix is found the pointer will simply progress to the end of the String and be left there.

input:
Golf -lf //pointer location 0

output:
Go //pointer location 2
Examples
input:
"Simple" "-impl +nip -e +er"

output:
"Sniper"

input:
"Function" "-F +Conj"

output:
"Conjunction"

input:
"Goal" "+Code -al +lf"

output:
"CodeGolf"

input:
"Chocolate" "Chocolate"

output:
"Chocolate" //Nothing happens...

input:
"Hello" "-lo+p        +Please" //Spaces are irrelevant

output:
"PleaseHelp"

input:
"Mississippi" "-s-s-i-ppi+ng" //Operations can be in any order

output:
"Missing"

input:
"abcb" "-c -b +d"

output:
"abd"

input:
"1+1=2" "-1+22-=2+=23"

outut:
"22+1=23"
Example Code
The example is Java, it's not golfed at all.

public static String refactor(String input, String swap) {
    int pointer = 0;
    String[] commands = swap.replace(" ", "").split("(?=[-+])");

    for (String s : commands) {
        if (s.startsWith("+")) {
            input = input.substring(0, pointer) + s.substring(1) + input.substring(pointer, input.length());
            pointer = 0;
        } else {
            if (s.startsWith("-")) {
                String remove = s.substring(1);
                for (int i = pointer; i < input.length(); i++) {
                    if (input.substring(i, i + remove.length() > input.length() ? input.length() : i + remove.length()).equals(remove)) {
                        pointer = i;
                        input = input.substring(0, i) + input.substring(i + remove.length(), input.length());
                        break;
                    }
                }
            }
        }
    }

    return input;
}

Rules
Standard Loopholes Apply
Shortest code, in bytes, wins

*/

class CUSRS {
	public static void main(String[] args) {
		assertEquals(refactor("Golf", "+Code"), "CodeGolf");
		assertEquals(refactor("Simple", "-impl +nip -e +er"), "Sniper");
		assertEquals(refactor("Function", "-F +Conj"), "Conjunction");
		assertEquals(refactor("Goal", "+Code -al +lf"), "CodeGolf");
		assertEquals(refactor("Chocolate", "Chocolate"), "Chocolate");
		assertEquals(refactor("Hello", "-lo+p        +Please"), "PleaseHelp");
		assertEquals(refactor("Mississippi", "-s-s-i-ppi+ng"), "Missing");
		assertEquals(refactor("abcb", "-c -b +d"), "abd");
		assertEquals(refactor("1+1=2", "-1+22-=2+=23"), "22+1=23");
	}

	public static void assertEquals(String string1, String string2) {
		assert(string1.equals(string2) == true);
	}
	
	public static String refactor(String input, String swap) {
		var pointer = 0;
		var commands = swap.replace(" ", "").split("(?=[-+])");
		for (var command : commands) {
			if (command.startsWith("+")) {
				input = input.substring(0, pointer) + command.substring(1) + input.substring(pointer, input.length());
				pointer = 0;
			} else if (command.startsWith("-")) {
				var remove = command.substring(1);
				for (var i = pointer; i < input.length(); i++) {
					var length = Math.min(i + remove.length(), input.length());
					if (input.substring(i, length).equals(remove)) {
						pointer = i;
						input = input.substring(0, i) + input.substring(i + remove.length(), input.length());
						break;
					}
				}
			}
		}
		return input;
	}
}
