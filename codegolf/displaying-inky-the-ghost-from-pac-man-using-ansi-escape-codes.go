/*

Here's a C example using ANSI escape Codes

#include <stdio.h>

#define B "\x1b[40m"   // Black Block
#define C "\x1b[46m"   // Cyan Block
#define W "\x1b[47m"   // White Block
#define E "\x1b[44m"   // Eyes Blue Block
#define R "\x1b[0m\n"  // Reset Color

int main() {
    printf("%s%-5s%s%-4s%s%-5s%s%s%-3s%s%-8s%s%-3s%s%s%-2s%s%-10s%s%-2s%s%s%-1s%s%-1s%s%-2s%s%-4s%s%-2s%s%-3s%s%-1s%s%s%-1s%s%-3s%s%-3s%s%-4s%s%-2s%s%-1s%s%s%-1s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-1s%s%s%-1s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-3s%s%s%-2s%s%-2s%s%-4s%s%-2s%s%-4s%s%s%-14s%s%s%-14s%s%s%-14s%s%s%-2s%s%-1s%s%-3s%s%-2s%s%-3s%s%-1s%s%-2s%s%s%-1s%s%-3s%s%-2s%s%-2s%s%-2s%s%-3s%s%-1s%s",B,"",C,"",B,"",R,B,"",C,"",B,"",R,B,"",C,"",B,"",R,B,"",C,"",W,"",C,"",W,"",C,"",B,"",R,B,"",W,"",C,"",W,"",C,"",B,"",R,B,"",E,"",W,"",C,"",E,"", W,"",C,"",B,"",R,C,"",E,"",W,"",C,"", E,"",W,"",C,"",R,C,"",W,"",C,"",W,"",C,"",R,C,"",R,C,"",R,C,"",R,C,"",B,"",C,"",B,"",C,"",B,"",C,"",R,C,"",B,"",C,"",B,"",C,"",B,"",C,"",R);
    return 0;
}

https://i.stack.imgur.com/7xcPF.png

Can inky be displayed in other languages using minimal bytes?

*/

package main

import "fmt"

const (
	B = "\x1b[40m"  // Black Block
	C = "\x1b[46m"  // Cyan Block
	W = "\x1b[47m"  // White Block
	E = "\x1b[44m"  // Eyes Blue Block
	R = "\x1b[0m\n" // Reset Color
)

func main() {
	fmt.Printf("%s%-5s%s%-4s%s%-5s%s%s%-3s%s%-8s%s%-3s%s%s%-2s%s%-10s%s%-2s%s%s%-1s%s%-1s%s%-2s%s%-4s%s%-2s%s%-3s%s%-1s%s%s%-1s%s%-3s%s%-3s%s%-4s%s%-2s%s%-1s%s%s%-1s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-1s%s%s%-1s%s%-2s%s%-2s%s%-2s%s%-2s%s%-2s%s%-3s%s%s%-2s%s%-2s%s%-4s%s%-2s%s%-4s%s%s%-14s%s%s%-14s%s%s%-14s%s%s%-2s%s%-1s%s%-3s%s%-2s%s%-3s%s%-1s%s%-2s%s%s%-1s%s%-3s%s%-2s%s%-2s%s%-2s%s%-3s%s%-1s%s", B, "", C, "", B, "", R, B, "", C, "", B, "", R, B, "", C, "", B, "", R, B, "", C, "", W, "", C, "", W, "", C, "", B, "", R, B, "", W, "", C, "", W, "", C, "", B, "", R, B, "", E, "", W, "", C, "", E, "", W, "", C, "", B, "", R, C, "", E, "", W, "", C, "", E, "", W, "", C, "", R, C, "", W, "", C, "", W, "", C, "", R, C, "", R, C, "", R, C, "", R, C, "", B, "", C, "", B, "", C, "", B, "", C, "", R, C, "", B, "", C, "", B, "", C, "", B, "", C, "", R)
}
