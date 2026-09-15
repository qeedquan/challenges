/*

I recently saw this question on stackoverflow. It's a great question, but there's one fatal problem with the question. They are asking for the best way to do it. E.g, easiest to read, most idiomatic, neatest etc. Don't they know that isn't what matters? You're supposed to ask about how to do it with the fewest bytes of code!

Since I doubt that question will be appreciated on stackoverflow, I decided to ask it here.

The challenge
You must write the shortest possible program or function that generates all possible ways to interleave any two arbitrary strings. For example, if the two strings are 'ab' and 'cd', the output is:

['abcd', 'acbd', 'acdb', 'cabd', 'cadb', 'cdab']
As you can see, a is always before b, and c is always before d.

IO can be in any reasonable format. Use this python code to verify to check your output. (credit: JeD)

def shuffle(s,t):
    if s=="":
        return [t]
    elif t=="":
        return [s]
    else:
        leftShuffle=[s[0]+val for val in shuffle(s[1:],t)]
        rightShuffle=[t[0]+val for val in shuffle(s,t[1:])]
        leftShuffle.extend(rightShuffle)
        return leftShuffle
Sample IO:
shuffle("$", "1234"):
['$1234', '1$234', '12$34', '123$4', '1234$']

shuffle("az", "by"):
['azby', 'abzy', 'abyz', 'bazy', 'bayz', 'byaz']

shuffle("code", "golf"):
['codegolf', 'codgeolf', 'codgoelf', 'codgolef', 'codgolfe', 'cogdeolf', 'cogdoelf',
'cogdolef', 'cogdolfe', 'cogodelf', 'cogodlef', 'cogodlfe', 'cogoldef', 'cogoldfe',
'cogolfde', 'cgodeolf', 'cgodoelf', 'cgodolef', 'cgodolfe', 'cgoodelf', 'cgoodlef',
'cgoodlfe', 'cgooldef', 'cgooldfe', 'cgoolfde', 'cgoodelf', 'cgoodlef', 'cgoodlfe',
'cgooldef', 'cgooldfe', 'cgoolfde', 'cgolodef', 'cgolodfe', 'cgolofde', 'cgolfode',
'gcodeolf', 'gcodoelf', 'gcodolef', 'gcodolfe', 'gcoodelf', 'gcoodlef', 'gcoodlfe',
'gcooldef', 'gcooldfe', 'gcoolfde', 'gcoodelf', 'gcoodlef', 'gcoodlfe', 'gcooldef',
'gcooldfe', 'gcoolfde', 'gcolodef', 'gcolodfe', 'gcolofde', 'gcolfode', 'gocodelf',
'gocodlef', 'gocodlfe', 'gocoldef', 'gocoldfe', 'gocolfde', 'goclodef', 'goclodfe',
'goclofde', 'goclfode', 'golcodef', 'golcodfe', 'golcofde', 'golcfode', 'golfcode']

As usual, standard loopholes apply, and the shortest answer in bytes wins. Since the question was originally about python, I'd love to see the shortest python answer. (And no, pyth is not python). However, answers in any language are encouraged.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test("ab", "cd", []string{"abcd", "acbd", "acdb", "cabd", "cadb", "cdab"})
	test("$", "1234", []string{"$1234", "1$234", "12$34", "123$4", "1234$"})
	test("az", "by", []string{"azby", "abzy", "abyz", "bazy", "bayz", "byaz"})
	test("code", "golf", []string{
		"codegolf", "codgeolf", "codgoelf", "codgolef", "codgolfe", "cogdeolf", "cogdoelf",
		"cogdolef", "cogdolfe", "cogodelf", "cogodlef", "cogodlfe", "cogoldef", "cogoldfe",
		"cogolfde", "cgodeolf", "cgodoelf", "cgodolef", "cgodolfe", "cgoodelf", "cgoodlef",
		"cgoodlfe", "cgooldef", "cgooldfe", "cgoolfde", "cgoodelf", "cgoodlef", "cgoodlfe",
		"cgooldef", "cgooldfe", "cgoolfde", "cgolodef", "cgolodfe", "cgolofde", "cgolfode",
		"gcodeolf", "gcodoelf", "gcodolef", "gcodolfe", "gcoodelf", "gcoodlef", "gcoodlfe",
		"gcooldef", "gcooldfe", "gcoolfde", "gcoodelf", "gcoodlef", "gcoodlfe", "gcooldef",
		"gcooldfe", "gcoolfde", "gcolodef", "gcolodfe", "gcolofde", "gcolfode", "gocodelf",
		"gocodlef", "gocodlfe", "gocoldef", "gocoldfe", "gocolfde", "goclodef", "goclodfe",
		"goclofde", "goclfode", "golcodef", "golcodfe", "golcofde", "golcfode", "golfcode",
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t string, r []string) {
	p := shuffle(s, t)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func shuffle(s, t string) []string {
	if s == "" {
		return []string{t}
	}
	if t == "" {
		return []string{s}
	}

	l := shuffle(s[1:], t)
	r := shuffle(s, t[1:])
	for i := range l {
		l[i] = fmt.Sprintf("%c%s", s[0], l[i])
	}
	for i := range r {
		r[i] = fmt.Sprintf("%c%s", t[0], r[i])
	}

	return append(l, r...)
}
