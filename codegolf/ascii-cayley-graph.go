/*

While doing some research for a different challenge I'm formulating, I came across a Cayley graph, specifically this one. Since I'm one of the top ascii-art challenge writers, of course I had to make an ASCII art challenge for this.

Your challenge is to produce this ASCII art depiction of a Cayley graph of the free group on two generators as follows:

                                               +
                                              +++
                                             + | +
                                            ++-+-++
                                             + | +
                                          +    |    +
                                         +++   |   +++
                                        + |    |    | +
                                       ++-+----+----+-++
                                        + |    |    | +
                                         +++   |   +++
                                          +    |    +
                                   +           |           +
                                  +++          |          +++
                                 + | +         |         + | +
                                ++-+-++        |        ++-+-++
                                 + | +         |         + | +
                              +    |           |           |    +
                             +++   |           |           |   +++
                            + |    |           |           |    | +
                           ++-+----+-----------+-----------+----+-++
                            + |    |           |           |    | +
                             +++   |           |           |   +++
                              +    |           |           |    +
                                 + | +         |         + | +
                                ++-+-++        |        ++-+-++
                                 + | +         |         + | +
                    +             +++          |          +++             +
                   +++             +           |           +             +++
                  + | +                        |                        + | +
                 ++-+-++                       |                       ++-+-++
                  + | +                        |                        + | +
               +    |    +                     |                     +    |    +
              +++   |   +++                    |                    +++   |   +++
             + |    |    | +                   |                   + |    |    | +
            ++-+----+----+-++                  |                  ++-+----+----+-++
             + |    |    | +                   |                   + |    |    | +
              +++   |   +++                    |                    +++   |   +++
               +    |    +                     |                     +    |    +
        +           |                          |                          |           +
       +++          |                          |                          |          +++
      + | +         |                          |                          |         + | +
     ++-+-++        |                          |                          |        ++-+-++
      + | +         |                          |                          |         + | +
   +    |           |                          |                          |           |    +
  +++   |           |                          |                          |           |   +++
 + |    |           |                          |                          |           |    | +
++-+----+-----------+--------------------------+--------------------------+-----------+----+-++
 + |    |           |                          |                          |           |    | +
  +++   |           |                          |                          |           |   +++
   +    |           |                          |                          |           |    +
      + | +         |                          |                          |         + | +
     ++-+-++        |                          |                          |        ++-+-++
      + | +         |                          |                          |         + | +
       +++          |                          |                          |          +++
        +           |                          |                          |           +
               +    |    +                     |                     +    |    +
              +++   |   +++                    |                    +++   |   +++
             + |    |    | +                   |                   + |    |    | +
            ++-+----+----+-++                  |                  ++-+----+----+-++
             + |    |    | +                   |                   + |    |    | +
              +++   |   +++                    |                    +++   |   +++
               +    |    +                     |                     +    |    +
                  + | +                        |                        + | +
                 ++-+-++                       |                       ++-+-++
                  + | +                        |                        + | +
                   +++             +           |           +             +++
                    +             +++          |          +++             +
                                 + | +         |         + | +
                                ++-+-++        |        ++-+-++
                                 + | +         |         + | +
                              +    |           |           |    +
                             +++   |           |           |   +++
                            + |    |           |           |    | +
                           ++-+----+-----------+-----------+----+-++
                            + |    |           |           |    | +
                             +++   |           |           |   +++
                              +    |           |           |    +
                                 + | +         |         + | +
                                ++-+-++        |        ++-+-++
                                 + | +         |         + | +
                                  +++          |          +++
                                   +           |           +
                                          +    |    +
                                         +++   |   +++
                                        + |    |    | +
                                       ++-+----+----+-++
                                        + |    |    | +
                                         +++   |   +++
                                          +    |    +
                                             + | +
                                            ++-+-++
                                             + | +
                                              +++
                                               +
Input
No input, unless your language explicitly requires input to run.

Output
The ASCII art representation shown above.

MD5 Hashes
Since this is a pretty large output, to check your work here are some MD5 hashes of example forms of output (all are UTF-8 without BOM):

Square space padding, CR/LF linefeeds, and trailing newline -- 954B93871DAAE7A9C05CCDF79B00BF3C -- this is the representation used above.
Square space padding, CR/LF linefeeds, no trailing newline -- 28405EF91DA305C406BD03F9275A175C
Square space padding, LF linefeeds, and trailing newline -- 8CA65FB455DA7EE5A4C10F25CBD49D7E
Square space padding, LF linefeeds, no trailing newline -- FDB1547D68023281BB60DBEC82C8D281
No trailing spaces, CR/LF linefeeds, and trailing newline -- 77FDE8CE5D7BD1BDD47610BA23264A19
No trailing spaces, CR/LF linefeeds, no trailing newline -- EAD390C3EFD37F0FCACE55A84B793AB5
No trailing spaces, LF linefeeds, and trailing newline -- 1F6CAB740F87881EB2E65BED65D08C36
No trailing spaces, LF linefeeds, no trailing newline -- 7D41CE1E637619FEA9515D090BFA2E9C
If there is an additional MD5 you would like for comparison, please let me know and I'll create it and update the challenge.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import "fmt"

func main() {
	draw(gen(95, 5))
}

func draw(p [][]byte) {
	for i := range p {
		fmt.Printf("%s\n", p[i])
	}
}

// ported from @dim solution
func gen(n, s int) [][]byte {
	p := alloc(n)
	recurse(p, n/2, n/2, s)
	return p
}

func alloc(n int) [][]byte {
	t := make([]byte, n*n)
	p := make([][]byte, n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
		for j := range p {
			p[i][j] = ' '
		}
	}
	return p
}

func recurse(p [][]byte, x, y, s int) {
	if s < 0 || p[y][x] != ' ' {
		return
	}

	n := ^s + (1 << s)
	i := -n
	for ; i <= n; i++ {
		p[y][x+i] = '-'
		p[y+i][x] = '+'
		if i != 0 {
			p[y+i][x] = '|'
		}
	}

	recurse(p, x+i, y, s-1)
	recurse(p, x-i, y, s-1)
	recurse(p, x, y+i, s-1)
	recurse(p, x, y-i, s-1)
}
