/*

The string tut-tutut-tut-tuttut-tut can be constructed with overlapping or concatenated instances of the word tut-tut:

tut-tutut-tut-tuttut-tut
tut-tut
      tut-tut
          tut-tut
                 tut-tut
The string tut-tututut-tutut-tut cannot:

tut-tututut-tutut-tut
tut-tut^
       |tut-tut
       |      tut-tut
       |
this u is unaccounted for
Given a string, determine whether it's constructed of overlapping or concatenated instances of the word tut-tut. Where two or more tut-tut strings overlap they must share the same letters in the same positions.

Rules
Standard I/O rules apply. You can use any two distinct, consistent values to distinguish the true and false cases.
You may assume the input strings are nonempty and only contain lowercase ASCII letters and -.
This is code golf, shortest code in bytes wins.
Test Cases

True:

tut-tut
tut-tut-tut
tut-tutut-tut
tut-tuttut-tut
tut-tut-tut-tut-tut
tut-tutut-tut-tutut-tut
tut-tutut-tut-tuttut-tut
tut-tut-tutut-tuttut-tut
tut-tuttut-tutut-tut-tutut-tut

False:

x
tut
tut-
-tut
t-tut
tu-tut
tut-tutx
tut-tutt
xtut-tut
ttut-tut
tutut-tut
tut-tu-tut
tut-tuttut
tuttut-tut
tut-tut-tutt
tut-tutt-tut
tut-tuttut-tu
tut-tututut-tut
tut-tuttuttut-tut
tut-tututut-tutut-tut

*/

package main

import "regexp"

func main() {
	assert(match("tut-tut") == true)
	assert(match("tut-tut-tut") == true)
	assert(match("tut-tutut-tut") == true)
	assert(match("tut-tuttut-tut") == true)
	assert(match("tut-tut-tut-tut-tut") == true)
	assert(match("tut-tutut-tut-tutut-tut") == true)
	assert(match("tut-tutut-tut-tuttut-tut") == true)
	assert(match("tut-tut-tutut-tuttut-tut") == true)
	assert(match("tut-tuttut-tutut-tut-tutut-tut") == true)

	assert(match("x") == false)
	assert(match("tut") == false)
	assert(match("tut-") == false)
	assert(match("-tut") == false)
	assert(match("t-tut") == false)
	assert(match("tu-tut") == false)
	assert(match("tut-tutx") == false)
	assert(match("tut-tutt") == false)
	assert(match("xtut-tut") == false)
	assert(match("ttut-tut") == false)
	assert(match("tutut-tut") == false)
	assert(match("tut-tu-tut") == false)
	assert(match("tut-tuttut") == false)
	assert(match("tuttut-tut") == false)
	assert(match("tut-tut-tutt") == false)
	assert(match("tut-tutt-tut") == false)
	assert(match("tut-tuttut-tu") == false)
	assert(match("tut-tututut-tut") == false)
	assert(match("tut-tuttuttut-tut") == false)
	assert(match("tut-tututut-tutut-tut") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Deadcode

POSIX ERE/RE2
^\b((t?\But)?-tut)+$

*/

func match(s string) bool {
	re := regexp.MustCompile(`^\b((t?\But)?-tut)+$`)
	return re.MatchString(s)
}
