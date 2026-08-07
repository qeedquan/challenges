/*

As a little kid, I liked to play with these toys a lot:

https://i.sstatic.net/xRBjI.jpg

They probably intended for these to be used for art, but I always used them for math! Fractals, patterns, etc. One time, I was given this challenge:

Build a triangle without using any of the green triangle tiles.

This challenge stumped me for the longest time, until I stumbled upon a really beautiful and simple way to do it with just 3 trapezoids:

  /\
 /_/\
/__\_\
Now, take this triangle, and rotate it:

______
\ \__/
 \/ /
  \/
Using these two triangles, we can construct larger triangles out of them. Here is a triangle of height 2:

     /\
    /_/\
   /__\_\
  /\ \__/\
 /_/\/ /_/\
/__\_\/__\_\
And here are triangles of height 3-7:

#3
        /\
       /_/\
      /__\_\
     /\ \__/\
    /_/\/ /_/\
   /__\_\/__\_\
  /\ \__/\ \__/\
 /_/\/ /_/\/ /_/\
/__\_\/__\_\/__\_\

#4
           /\
          /_/\
         /__\_\
        /\ \__/\
       /_/\/ /_/\
      /__\_\/__\_\
     /\ \__/\ \__/\
    /_/\/ /_/\/ /_/\
   /__\_\/__\_\/__\_\
  /\ \__/\ \__/\ \__/\
 /_/\/ /_/\/ /_/\/ /_/\
/__\_\/__\_\/__\_\/__\_\

#5
              /\
             /_/\
            /__\_\
           /\ \__/\
          /_/\/ /_/\
         /__\_\/__\_\
        /\ \__/\ \__/\
       /_/\/ /_/\/ /_/\
      /__\_\/__\_\/__\_\
     /\ \__/\ \__/\ \__/\
    /_/\/ /_/\/ /_/\/ /_/\
   /__\_\/__\_\/__\_\/__\_\
  /\ \__/\ \__/\ \__/\ \__/\
 /_/\/ /_/\/ /_/\/ /_/\/ /_/\
/__\_\/__\_\/__\_\/__\_\/__\_\

#6
                 /\
                /_/\
               /__\_\
              /\ \__/\
             /_/\/ /_/\
            /__\_\/__\_\
           /\ \__/\ \__/\
          /_/\/ /_/\/ /_/\
         /__\_\/__\_\/__\_\
        /\ \__/\ \__/\ \__/\
       /_/\/ /_/\/ /_/\/ /_/\
      /__\_\/__\_\/__\_\/__\_\
     /\ \__/\ \__/\ \__/\ \__/\
    /_/\/ /_/\/ /_/\/ /_/\/ /_/\
   /__\_\/__\_\/__\_\/__\_\/__\_\
  /\ \__/\ \__/\ \__/\ \__/\ \__/\
 /_/\/ /_/\/ /_/\/ /_/\/ /_/\/ /_/\
/__\_\/__\_\/__\_\/__\_\/__\_\/__\_\

#7
                    /\
                   /_/\
                  /__\_\
                 /\ \__/\
                /_/\/ /_/\
               /__\_\/__\_\
              /\ \__/\ \__/\
             /_/\/ /_/\/ /_/\
            /__\_\/__\_\/__\_\
           /\ \__/\ \__/\ \__/\
          /_/\/ /_/\/ /_/\/ /_/\
         /__\_\/__\_\/__\_\/__\_\
        /\ \__/\ \__/\ \__/\ \__/\
       /_/\/ /_/\/ /_/\/ /_/\/ /_/\
      /__\_\/__\_\/__\_\/__\_\/__\_\
     /\ \__/\ \__/\ \__/\ \__/\ \__/\
    /_/\/ /_/\/ /_/\/ /_/\/ /_/\/ /_/\
   /__\_\/__\_\/__\_\/__\_\/__\_\/__\_\
  /\ \__/\ \__/\ \__/\ \__/\ \__/\ \__/\
 /_/\/ /_/\/ /_/\/ /_/\/ /_/\/ /_/\/ /_/\
/__\_\/__\_\/__\_\/__\_\/__\_\/__\_\/__\_\

The Challenge
Write a program or function that takes a number n and prints a triangle-less triangle of height n. Trailing spaces on each line is acceptable, and up to one trailing or leading newline is also acceptable. IO can be in any reasonable format. The input is guarenteed to be a positive integer, so you don't have to worry about negative numbers, decimals, non-numbers etc.

Shortest answer in bytes wins!

*/

package main

import (
	"fmt"
)

func main() {
	for i := range 17 {
		triangle(i)
	}
}

// ported from @JHK solution
func triangle(n int) {
	top := [3]string{`/\`, `/_/\`, `/__\_\`}
	bot := [3]string{` \__`, `/ `, ``}
	fmt.Printf("n=%d\n", n)
	for i := range n {
		for j := range 3 {
			spaces((n-(i+1))*3 + (2 - j))
			for l := 1; l <= 2*(i+1)-1; l++ {
				if l%2 == 0 && j < 2 {
					fmt.Print(bot[j])
				} else if l%2 == 1 {
					fmt.Print(top[j])
				}
			}
			fmt.Println()
		}
	}
	fmt.Println()
}

func spaces(n int) {
	for range n {
		fmt.Print(" ")
	}
}
