/*

Write a program or function that takes in a string guaranteed to only contain printable ASCII characters except for space, and to be a positive triangular number (1, 3, 6, 10, 15, ...) in length.

Print or return the same string, but shaped into a triangle using spaces. Some examples will best show what I mean:

If the input is R then the output will be

R
If the input is cat then the output will be

 c
a t
If the input is monk3y then the output will be

  m
 o n
k 3 y
If the input is meanIngfu1 then the output will be

   m
  e a
 n I n
g f u 1
If the input is ^/\/|\/[]\ then the output will be

   ^
  / \
 / | \
/ [ ] \
If the input is

Thisrunofcharactersismeanttohavealengththatcanbeexpressedasatriangularnumber.Diditwork?Youtellme,Ican'tcountverywell,ok?
then the output will be

              T
             h i
            s r u
           n o f c
          h a r a c
         t e r s i s
        m e a n t t o
       h a v e a l e n
      g t h t h a t c a
     n b e e x p r e s s
    e d a s a t r i a n g
   u l a r n u m b e r . D
  i d i t w o r k ? Y o u t
 e l l m e , I c a n ' t c o
u n t v e r y w e l l , o k ?
Basically, newlines are inserted between the substrings of triangular length, spaces are added between all characters, and each line is indented with spaces to fit the triangle shape.

A single trailing newline and lines with trailing spaces are optionally allowed, but otherwise your output should exactly match these examples. The last line of the triangle should not have leading spaces.

The shortest code in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"strings"
)

func main() {
	fmt.Println(triangulate("R"))
	fmt.Println(triangulate("cat"))
	fmt.Println(triangulate("monk3y"))
	fmt.Println(triangulate("meanIngfu1"))
	fmt.Println(triangulate(`^/\/|\/[]\`))
	fmt.Println(triangulate("Thisrunofcharactersismeanttohavealengththatcanbeexpressedasatriangularnumber.Diditwork?Youtellme,Ican'tcountverywell,ok?"))
}

func triangulate(s string) string {
	w := new(bytes.Buffer)
	t := triangularroot(len(s))
	for i, n := 0, 1; n <= t; n++ {
		fmt.Fprint(w, strings.Repeat(" ", t-n))
		for j := 0; j < n; i, j = i+1, j+1 {
			fmt.Fprintf(w, "%c ", s[i])
		}
		fmt.Fprintln(w)
	}
	return w.String()
}

func triangularroot(x int) int {
	return int((math.Sqrt(8*float64(x)+1) - 1) / 2)
}
