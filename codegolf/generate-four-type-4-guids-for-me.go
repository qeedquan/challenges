/*

The type 4 GUID is described by Wikipedia, quoth:

Version 4 UUIDs use a scheme relying only on random numbers. This algorithm sets the version number (4 bits) as well as two reserved bits. All other bits (the remaining 122 bits) are set using a random or pseudorandom data source. Version 4 UUIDs have the form xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx where x is any hexadecimal digit and y is one of 8, 9, A, or B (e.g., f47ac10b-58cc-4372-a567-0e02b2c3d479).

Write a program that loads 488 bits (61 bytes) of cryptographic quality randomness and output them as 4 GUIDs using the format quoted above.

Do not waste randomness.
All random bits must appear in the encoded output.
All encoded bits must be traceable to either a single random bit or one of the six fixed bits that must appear in each GUID.
Use the cryptographic quality random number generator supplied by your language's standard library.
Do not use a library or external resource that generates GUIDs.
The hyphens must appear in their correct positions.
The fixed bits of this form of GUID must appear in their correct positions.
You may use a standard library function designed to output a GUID from 128 bits.
Normal code-golf rules apply.
For example...

> gentype4
6FA53B63-E7EA-4461-81BE-9CD106A1AFF8
856970E9-377A-458E-96A7-43F587724573
E4F859AC-0004-4AA1-A3D2-AECB527D1D24
766811C5-0C44-4CC8-8C30-E3D6C7C6D00B
Update:
I asked for four GUIDs in order to allow a whole number of random bytes to be gathered without leaving any remainder. I also specified that none of the bits should be wasted in order to avoid the easy answer of getting 16 random bytes and dropping the 4 in. (No, shift the other bits along first.)

Update 2:
If your language's standard library doesn't have a cryptographic quality random byte generator, you may instead assume that there is a 61 byte file present with enough random bytes for you to use when the program starts. The file should be called "/dev/urandom" or another filename with 12 characters.

*/

package main

import (
	"crypto/rand"
	"fmt"
)

func main() {
	for range 4 {
		fmt.Println(guid4())
	}
}

func guid4() string {
	var b [17]byte
	_, err := rand.Read(b[:])
	if err != nil {
		panic(err)
	}

	s := fmt.Sprintf("%08X-%04X-%04X-%04X-%012X", b[:4], b[4:6], b[6:8], b[8:10], b[10:16])
	p := []byte(s)
	p[14] = '4'
	if b[16] &= 3; b[16] < 2 {
		p[19] = '8' + b[16]
	} else {
		p[19] = 'A' + b[16] - 2
	}
	return string(p)
}
