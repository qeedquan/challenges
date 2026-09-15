/*

Background

Here is a Halloween related challenge.

As you may have seen from my last challenge I quite like what I term as ascii art animations, that is not just draw a pattern but draw a pattern that progresses. This idea came to me after I was asked a couple of years ago to liven up a (rather dull) presentation by making random ascii bats fly across the screen on Halloween. Needless to say I duly obliged (I was being paid for it) but it made me think that there is more to life than random bats. Inspired by this I would like to propose this challenge.

Challenge

Make a bat fly around the moon.

Here is a bat:

^o^
Here is the moon:

     mmm
   mmmmmmm
  mmmmmmmmm
   mmmmmmm
     mmm
You must show every stage of the bats flight (see output).

Input

None

Output

      ^o^
      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm^o^
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm
    mmmmmmm^o^
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm^o^
    mmmmmmm
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm^o^
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm^o^


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm
      ^o^


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
   ^o^mmm


      mmm
    mmmmmmm
   mmmmmmmmm
 ^o^mmmmmmm
      mmm


      mmm
    mmmmmmm
^o^mmmmmmmmm
    mmmmmmm
      mmm


      mmm
 ^o^mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


   ^o^mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      ^o^
      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm
Rules

No reading from external files or websites
You may submit a full program or a function
Extra spaces and/or newlines are fine by me
Standard loopholes banned as usual
The bat must finish back at the top of the moon
Please feel free to clear the screen between frames if you wish however this is not a requirement. Output as shown above is fine
As this is code golf, the winner will be the answer with the lowest byte count although any answer is welcome
Sample

Reference implementation in totally ungolfed Python 2 (620 bytes but just to prove that it can be done. May golf it later).

b='^o^'
m=['                     ',
'         mmm         ',
'       mmmmmmm       ',
'      mmmmmmmmm      ',
'       mmmmmmm       ',
'         mmm         ',
'                     ']
p=[(9,12),(12,15),(14,17),(15,18),(14,17),(12,15),(9,12),(6,9),(4,7),(3,6),(4,7),(6,9),(9,12)]
d=0
for z in range(7):
    x=map(str,m[z])
    c="".join(x[:p[z][0]]) + b + "".join(x[p[z][1]:])+"\n"
    print "\n".join(m[:z]) + "\n" + c+"\n".join(m[z+1:])
for z in range(6)[::-1]:
    x=map(str,m[z])
    c="".join(x[:p[z+6][0]]) + b + "".join(x[p[z+6][1]:])+"\n"
    print "\n".join(m[:z]) + "\n" + c+"\n".join(m[z+1:])

Result

Although @Jonathan obviously wins on byte count with Jelly, I am going to mark the Brainfuck answer from @Oyarsa as the accepted answer purely because I think that anyone who can actually do something like this in such a crazy language deserves +15 rep no matter how many bytes it takes. This is not because I have any problem with golfing languages. See my answer to a question regarding this on meta if you have any doubts. Many thanks and respect to all who contributed in whatever language.

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
      ^o^
      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm^o^
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm
    mmmmmmm^o^
   mmmmmmmmm
    mmmmmmm
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm^o^
    mmmmmmm
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm^o^
      mmm


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm^o^


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm
      ^o^


      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
   ^o^mmm


      mmm
    mmmmmmm
   mmmmmmmmm
 ^o^mmmmmmm
      mmm


      mmm
    mmmmmmm
^o^mmmmmmmmm
    mmmmmmm
      mmm


      mmm
 ^o^mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


   ^o^mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm


      ^o^
      mmm
    mmmmmmm
   mmmmmmmmm
    mmmmmmm
      mmm
`
