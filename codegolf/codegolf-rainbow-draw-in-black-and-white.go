/*

Introduction:

https://i.sstatic.net/SnMxA.jpg
A rainbow emerges from a forest.

Image credit: CC-By-SA 2.5 Wing‑Chi Poon via Wikimedia Commons

When we look at a rainbow it will always have the colors from top to bottom:
Red; orange; yellow; green; blue; indigo; violet

If we look at these individual rings, the red ring is of course bigger than the violet ring.
In addition, it's also possible to have two or even three rainbow at the same time.

All this above combined will be used in this challenge:

Challenge:
Given an integer n, output that many rings of the (possibly more than one) 'rainbows', where we'll use the letters vibgyor for the colors.

See the test cases below to see how they are built upwards from n=1, and how the spacing should be handled (at n=8). As you can see, one space is added between two rainbows, including spacing at the top, before we add the ring of the next rainbow in line.

Challenge rules:
You are allowed to use capital VIBGYOR instead of lowercase
There should be a space between the individual rainbows
Any amount of leading and/or trailing spaces/new-lines are allowed, as long as the actual rainbow (wherever it is placed on the screen) is correct
The input will always be a positive integer (>= 1). The behavior when n=0 is therefore undefined, and the program/function can do whatever it wants (outputting nothing; outputting the rainbow of n=1; random output; fail with an error; etc.)
You are allowed to output a list/array of strings or 2D array/list of characters if you want (you could add the actual pretty-printing code in the TIO footer).
Ignore the fact that the outputs looks more like Mayan temples than rainbows.. xD
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, adding an explanation for your answer is highly recommended.
Test cases (first n=1 through n=10, and n=25):
1:
 vvv
v   v

2:
  iii
 ivvvi
iv   vi

3:
   bbb
  biiib
 bivvvib
biv   vib

4:
    ggg
   gbbbg
  gbiiibg
 gbivvvibg
gbiv   vibg

5:
     yyy
    ygggy
   ygbbbgy
  ygbiiibgy
 ygbivvvibgy
ygbiv   vibgy

6:
      ooo
     oyyyo
    oygggyo
   oygbbbgyo
  oygbiiibgyo
 oygbivvvibgyo
oygbiv   vibgyo

7:
       rrr
      rooor
     royyyor
    roygggyor
   roygbbbgyor
  roygbiiibgyor
 roygbivvvibgyor
roygbiv   vibgyor

8:
         vvv
        v   v
       v rrr v
      v rooor v
     v royyyor v
    v roygggyor v
   v roygbbbgyor v
  v roygbiiibgyor v
 v roygbivvvibgyor v
v roygbiv   vibgyor v

9:
          iii
         ivvvi
        iv   vi
       iv rrr vi
      iv rooor vi
     iv royyyor vi
    iv roygggyor vi
   iv roygbbbgyor vi
  iv roygbiiibgyor vi
 iv roygbivvvibgyor vi
iv roygbiv   vibgyor vi

10:
           bbb
          biiib
         bivvvib
        biv   vib
       biv rrr vib
      biv rooor vib
     biv royyyor vib
    biv roygggyor vib
   biv roygbbbgyor vib
  biv roygbiiibgyor vib
 biv roygbivvvibgyor vib
biv roygbiv   vibgyor vib

25:
                            ggg
                           gbbbg
                          gbiiibg
                         gbivvvibg
                        gbiv   vibg
                       gbiv rrr vibg
                      gbiv rooor vibg
                     gbiv royyyor vibg
                    gbiv roygggyor vibg
                   gbiv roygbbbgyor vibg
                  gbiv roygbiiibgyor vibg
                 gbiv roygbivvvibgyor vibg
                gbiv roygbiv   vibgyor vibg
               gbiv roygbiv rrr vibgyor vibg
              gbiv roygbiv rooor vibgyor vibg
             gbiv roygbiv royyyor vibgyor vibg
            gbiv roygbiv roygggyor vibgyor vibg
           gbiv roygbiv roygbbbgyor vibgyor vibg
          gbiv roygbiv roygbiiibgyor vibgyor vibg
         gbiv roygbiv roygbivvvibgyor vibgyor vibg
        gbiv roygbiv roygbiv   vibgyor vibgyor vibg
       gbiv roygbiv roygbiv rrr vibgyor vibgyor vibg
      gbiv roygbiv roygbiv rooor vibgyor vibgyor vibg
     gbiv roygbiv roygbiv royyyor vibgyor vibgyor vibg
    gbiv roygbiv roygbiv roygggyor vibgyor vibgyor vibg
   gbiv roygbiv roygbiv roygbbbgyor vibgyor vibgyor vibg
  gbiv roygbiv roygbiv roygbiiibgyor vibgyor vibgyor vibg
 gbiv roygbiv roygbiv roygbivvvibgyor vibgyor vibgyor vibg
gbiv roygbiv roygbiv roygbiv   vibgyor vibgyor vibgyor vibg

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 1; i <= 25; i++ {
		rainbow(i)
	}
}

// ported from @ovs solution
func rainbow(n int) {
	const sym = " vibgyor"

	fmt.Printf("n=%d\n", n)
	if n < 0 {
		return
	}

	n += n / 7
	for s := ""; n >= 0; n-- {
		s += string(sym[n&7])
		l := len(s)

		fmt.Print(strings.Repeat(" ", n))
		fmt.Print(s)
		fmt.Printf("%c", s[l-1])
		for i := l - 1; i >= 0; i-- {
			fmt.Printf("%c", s[i])
		}
		fmt.Println()
	}
	fmt.Println()
}
