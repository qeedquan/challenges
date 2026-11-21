/*

In honour of CrowdStrike's exception at 0x9c, what's the shortest way (character-wise) to cause a segfault by dereferencing address 0x9c?

The best I can come up with is:

int main(){*(int*)156=0;}

Rules:

It must be valid C++ (so no removing the return type int of main)
It must crash the program

*/

package main

import "unsafe"

func main() {
	*(*int)(unsafe.Pointer(uintptr(0x9c))) = 0
}
