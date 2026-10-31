/*

You're playing TF2, and you want to make a bot that will just put voice commands into the chat box. Typically, to "call" a voice command, one would press a key (Z, X, or C) and a number (1-8) to create an audio dialogue. Here are the text equivalents of the audios displayed when pressing these keys:

Voice Menu 1
Default key: Z
==============
1. MEDIC!
2. Thanks!
3. Go Go Go!
4. Move Up!
5. Go Left
6. Go Right
7. Yes
8. No


Voice Menu 2
Default key: X
==============
1. Incoming
2. Spy!
3. Sentry Ahead!
4. Teleporter Here
5. Dispenser Here
6. Sentry Here
7. Activate ÜberCharge!
8. MEDIC: ÜberCharge Ready   ; ignore the MEDIC: bit


Voice Menu 3
Default key: C
==============
1. Help!
2. Battle Cry    ; see bonus
3. Cheers
4. Jeers
5. Positive
6. Negative
7. Nice Shot
8. Good Job
Objective Given an input string (or input character + character, character + number, etc.; whatever is most relevant/convenient to your language), take the respective message from the chart above and output it. If the input is invalid, do not output anything. This is a code-golf, so the shortest program in bytes wins.

Example IOs
> Z3
Go Go Go!

> Z1
MEDIC!

> Z5
Go Left

> X8
ÜberCharge Ready

> X7
Activate ÜberCharge!

> C1
Help!

> C8
Good Job
Bonuses/penalties
These bonuses are applied in the order of appearance in this list.

-1 byte for every byte used in the physical text of C2 (i.e., Battle Cry); I will not add points for errors on C2, so be creative if you wish! (By physical text, I mean every byte used for constructing (not outputting) the string. For example, for STDOUT "AHHHHHHHH!", "AHHHHHHHH!" is free, but nothing else is. In console.log(`${v="Tha"}t's too you, you idiot!`), the free characters are `"Tha" t's too you, you idiot!`. These characters are the only ones that make up part of the string and their respective quotes.)
-15% if your program takes input and outputs the respective entry until an invalid input is given, at which point your program should terminate.
+5 bytes for every capitalization, punctuation, or spacing error
+10 bytes for every wrong/missing letter
-20 bytes if you can take a string like "X5C3Z6..." and output each respective message, separated by newlines.
-30 bytes if you take a class input (either Scout, Soldier, Pyro, Demoman, Heavy, Engineer, Sniper, Medic, or Spy) and verify if the class can say the given expression. The only expression that applies is X8, i.e., MEDIC: ÜberCharge Ready; only the Medic can say this. If any other class besides the medic attempts to say this, do not output anything. (The names are case insensitive.)

*/

package main

func main() {
	assert(say("Z3") == "Go Go Go!")
	assert(say("Z1") == "MEDIC!")
	assert(say("Z5") == "Go Left")
	assert(say("X8") == "ÜberCharge Ready")
	assert(say("X7") == "Activate ÜberCharge!")
	assert(say("C1") == "Help!")
	assert(say("C8") == "Good Job")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func say(code string) string {
	lut := map[string]string{
		"Z1": "MEDIC!",
		"Z2": "Thanks!",
		"Z3": "Go Go Go!",
		"Z4": "Move Up!",
		"Z5": "Go Left",
		"Z6": "Go Right",
		"Z7": "Yes",
		"Z8": "No",

		"X1": "Incoming",
		"X2": "Spy!",
		"X3": "Sentry Ahead!",
		"X4": "Teleporter Here",
		"X5": "Dispenser Here",
		"X6": "Sentry Here",
		"X7": "Activate ÜberCharge!",
		"X8": "ÜberCharge Ready",

		"C1": "Help!",
		"C2": "Battle Cry",
		"C3": "Cheers",
		"C4": "Jeers",
		"C5": "Positive",
		"C6": "Negative",
		"C7": "Nice Shot",
		"C8": "Good Job",
	}

	return lut[code]
}
