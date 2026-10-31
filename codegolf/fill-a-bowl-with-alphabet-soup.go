/*

We seem to never get tired of alphabet-related challenges...

The recipe
Given

a string of letters S, and
two positive integers M, N,
produce an alphabet soup with the letters of S occupying random positions in a rectangular bowl of size M×N, framed by a non-alphabetic, non-space character to represent the rim of the bowl.

Positions not used by letters should be displayed as spaces. See the examples below.

Aditional rules
The size M×N refers to the interior of the bowl. The size including the rim is M+2×N+2.
Each character from S should appear once in the bowl, in a different position; that is, one character cannot overwrite another.
S may contain duplicates. For instance, if S is the string 'abcc', the soup must contain one a, one b, and two c (all in different positions).
The inputs will satisfy the restrictions M >= 1, N >= 1, 1 <= length(S) <= M*N.
The rim of the bowl can be any non-alphabetic, non-space character, consistent across program runs and input values.
Letter positions in the bowl are random, so the result may differ every time the program is run with the same inputs.
Given the input, every possible set of letter positions should have a non-zero probability. Since this cannot be checked from a few realizations of the program, please explain how your code fulfills this.
Leading or trailing whitespace around the rim is allowed.
S will contain are only uppercase letters. If wou wish, you can choose to take only lowercase letters.
Input and output are flexible as usual. For example, the output can be a string with newlines, a 2D character array, or a list of lines.
Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.
The shortest code in bytes wins.
Examples
Inputs are shown as S, [M N], where M is number of rows and N is number of columns. The character # is used for the rim.

'O', [1 1]:

###
#O#
###

'HEY', [1 3]:

#####
#YHE#
#####


'HELLO', [4 11]:

#############
#  O        #
#         H #
#    LE     #
#   L       #
#############


'ADVNJSGHETILMVXERTYIOJKCVNCSF', [8 12]:

##############
#K  V  L   S #
# A   V  X H #
#T    M C    #
# I       O N#
#  YC        #
# G  I   R SE#
#   J      F #
#JT  D  V EN #
##############


'OOOOOOOOOOXXXXX', [13 31]:

#################################
#    X                          #
#                O              #
#                               #
#                  X            #
#                        O      #
#             X           O     #
#      O                        #
#         X                     #
#                        O      #
#       X                       #
#                    O          #
#  O      O      O              #
#                             O #
#################################


'ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ', [11 41]

###########################################
#                                       JU#
#     Q         C M    G     R T U Y  H   #
#  KI          E   H    M   YO            #
#      V BW        I    JC                #
#     SV           D     P   B          U #
#           A     F    RF   J  KP E       #
#            E   N      TH        Z       #
#    N  BM  O     Q   I        AS N  WX   #
#   S     O  K       G L       P       Q  #
#Z     L T         R   L       A      F DD#
#      V   Y           WX   C       G XZ  #
###########################################

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	bowl("O", 1, 1)
	bowl("HEY", 3, 1)
	bowl("HELLO", 11, 4)
	bowl("ADVNJSGHETILMVXERTYIOJKCVNCSF", 12, 8)
	bowl("OOOOOOOOOOXXXXX", 31, 13)
	bowl("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ", 41, 11)
}

func bowl(s string, w, h int) {
	paint(gen(s, w, h), w, h)
}

func gen(s string, w, h int) []rune {
	r := []rune(s)
	n := len(r)

	p := make([]rune, w*h)
	i := 0
	for j := range p {
		p[j] = ' '
		if i < n {
			p[j], i = r[i], i+1
		} else if n > 0 && rand.Intn(100) >= 90 {
			p[j] = r[rand.Intn(n)]
		}
	}
	rand.Shuffle(len(p), func(i, j int) {
		p[i], p[j] = p[j], p[i]
	})

	return p
}

func paint(p []rune, w, h int) {
	fmt.Printf("%dx%d\n", w, h)
	for range w + 2 {
		fmt.Printf("#")
	}
	fmt.Println()
	for y := range h {
		fmt.Printf("#")
		for x := range w {
			fmt.Printf("%c", p[y*w+x])
		}
		fmt.Println("#")
	}
	for range w + 2 {
		fmt.Printf("#")
	}
	fmt.Println()
	fmt.Println()
}
