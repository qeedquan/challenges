/*

In the spirit of the Underhanded C Contest, I'm starting an Underhanded Code Contest. The objective of this contest is to straightforwardly implement some code, while subtly hiding a nefarious bug inside it.

The contest
You are a secret Russian mole working in the IT department of an American spy agency. Your American boss has just asked you to implement a password hashing algorithm to use for encrypting secret messages.

Your boss wants you to implement the following function:

f: String -> byte[16]
which converts a password to a 16-byte quantity suitable for use as an AES key. Your boss wants a secure function, which in this context means that different password strings should generate different results with overwhelming probability. For instance, returning the md5 hash of the input would be a simple implementation of f.

Of course, your real boss in the Russian spy agency would want you to subvert this process. Your task is to implement f such that the Russians can decrypt all the secret messages encrypted using keys returned by f.

To do so, you must implement f so that it returns only a small subset of the 2^128 possible outputs. In particular, your f must return at most 2^16 different results so that the Russians can do an easy brute-force search for the correct key for each encrypted message they wish to decrypt.

Keep in mind, however, that espionage carries the death penalty. In order not to get caught, your function f must generate at least 2^8 different results, so that a cursory inspection of a few outputs of f is unlikely to reveal a duplicate. And most importantly, the code you introduce to limit the range of f must look unintentional, not deliberate. If you ever get hauled into a courtroom, there must be some reasonable doubt as to whether you introduced the bug deliberately or by accident.

Judging
I and two others I recruit will judge the entries (email me if you'd like to judge). I'm offering a 200 reputation bounty for the winning entry. Submissions must be uploaded by May 1.

Judging will take into account the following criteria:

Does f adhere to the spec, i.e. does it generate between 2^8 and 2^16 possible outputs. Don't feel that these are hard limits, but we'll deduct points if you're too far out of range.
Is the bug plausibly the result of an unintentional mistake?
Do the outputs of f look random?
The shorter your implementation of f, the better.
The clearer your implementation of f, the better.

Notes
You may use any language to implement your code. You're trying to hide a bug in plain sight, so obfuscated code is not suggested.

You might want to take a look at some of the previous Underhanded C contest winners to get a feel for what makes a good submission.

Input strings will be printable ascii (32 through 126, inclusive). You may assume a reasonable max length if you want.

*/

package main

import (
	"encoding/binary"
	"fmt"
)

func main() {
	sim(1e7)
}

func sim(N uint64) {
	seen := make(map[[16]byte][8]byte)
	hit := 0
	for i := uint64(0); i < N; i++ {
		var (
			in  [8]byte
			out [16]byte
		)
		binary.BigEndian.PutUint64(in[:], i)
		weakhash(in[:], out[:])

		if _, exist := seen[out]; exist {
			hit++
		} else {
			seen[out] = in
		}
	}
	fmt.Printf("Number of collisions: %d out of %d\n", hit, N)
}

/*

@han

This may not be the flashiest contest entry, but I think the following is the kind of hash function that could have been made by any coder too clever for their own good, with a vague idea of the kind of operations you see in hash functions:
In fact the hash function can return no more than L*2048 different results, where L is the number of different input string lengths that can occur. In practice, I tested the code on 1.85 million unique input lines from manual pages and html documents on my laptop, and got only 85428 different unique hashes.

*/

func weakhash(in, out []byte) {
	h := uint32(123456789)
	for n := range out {
		for i := range in {
			h = h*33 + uint32(in[i])
		}
		out[n] = byte((h >> 3) & 0xff)
		h ^= 987654321
	}
}
