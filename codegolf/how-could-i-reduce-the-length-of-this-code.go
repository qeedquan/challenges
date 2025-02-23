/*

I need to reduce the length of this code in Python 3 as much as possible (even if it will be less readable):

a,b,x,y=[int(i) for i in input().split()]
while 1:
 r=''
 if y<b:r='S';y+=1
 if y>b:r='N';y-=1
 if x<a:r+='E';x+=1
 if x>a:r+='W';x-=1
 print(r)
It's a map: you are on (x,y) and you need to go to (a,b). S for South, N for North, NE for North East and so on. After each turn I must tell where to go using print.

Update: This is what I've got now, but is there any way to shorten it further?

a,b,x,y=map(int,input().split())
while 1:c,d=(y>b)-(y<b),(x>a)-(x<a);print((' NS'[c]+' WE'[d]).strip());y-=c;x-=d

*/

package main

import "fmt"

func main() {
	move(100, 100, 0, 0)
}

func move(a, b, x, y int) {
	for x != a && y != b {
		r := ""
		if y < b {
			r = "S"
			y += 1
		}
		if y > b {
			r = "N"
			y -= 1
		}
		if x < a {
			r += "E"
			x += 1
		}
		if x > a {
			r += "W"
			x -= 1
		}
		fmt.Println(r)
	}
}
