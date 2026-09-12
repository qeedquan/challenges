/*

Continuing my It was just a bug challenge:

Input:
A string consisting of printable ASCII characters without white-spaces nor new-lines.

Output:
First turn the input into a palindrome by reverting the input, and adding it before itself, excluding the middle character (i.e. with an input 1234567890, it will becomes 0987654321234567890).

And then output this text:

0        9        8        7        6        5        4        3        2        1        2        3        4        5        6        7        8        9        0
         0       9       8       7       6       5       4       3       2       1       2       3       4       5       6       7       8       9       0
                  0      9      8      7      6      5      4      3      2      1      2      3      4      5      6      7      8      9      0
                           0     9     8     7     6     5     4     3     2     1     2     3     4     5     6     7     8     9     0
                                    0    9    8    7    6    5    4    3    2    1    2    3    4    5    6    7    8    9    0
                                             0   9   8   7   6   5   4   3   2   1   2   3   4   5   6   7   8   9   0
                                                      0  9  8  7  6  5  4  3  2  1  2  3  4  5  6  7  8  9  0
                                                               0 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 0
                                                                        0987654321234567890
                                                               0 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 0
                                                      0  9  8  7  6  5  4  3  2  1  2  3  4  5  6  7  8  9  0
                                             0   9   8   7   6   5   4   3   2   1   2   3   4   5   6   7   8   9   0
                                    0    9    8    7    6    5    4    3    2    1    2    3    4    5    6    7    8    9    0
                           0     9     8     7     6     5     4     3     2     1     2     3     4     5     6     7     8     9     0
                  0      9      8      7      6      5      4      3      2      1      2      3      4      5      6      7      8      9      0
         0       9       8       7       6       5       4       3       2       1       2       3       4       5       6       7       8       9       0
0        9        8        7        6        5        4        3        2        1        2        3        4        5        6        7        8        9        0
(From the middle outward in both directions, each character is separated by one more space than the previous line.)

Challenge rules:
You need to print twice the length of the input, minus 3 lines. So with the input 1234567890, the output displayed above is 17 lines (length 10 * 2 - 3).
The input will only contain printable ASCII (excluding space, tab and new-line).
Trailing spaces are optional.
A single trailing new-line is optional.
(Additional) leading spaces or leading new-lines are not allowed.
You can assume the input will always be at least four characters long.
Unlike my It was just a bug challenge, both the input and output formats are flexible. So you are allowed to output the result as a String-array, String-list, etc.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases:
Input: 1234567890
Output:
0        9        8        7        6        5        4        3        2        1        2        3        4        5        6        7        8        9        0
         0       9       8       7       6       5       4       3       2       1       2       3       4       5       6       7       8       9       0
                  0      9      8      7      6      5      4      3      2      1      2      3      4      5      6      7      8      9      0
                           0     9     8     7     6     5     4     3     2     1     2     3     4     5     6     7     8     9     0
                                    0    9    8    7    6    5    4    3    2    1    2    3    4    5    6    7    8    9    0
                                             0   9   8   7   6   5   4   3   2   1   2   3   4   5   6   7   8   9   0
                                                      0  9  8  7  6  5  4  3  2  1  2  3  4  5  6  7  8  9  0
                                                               0 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 0
                                                                        0987654321234567890
                                                               0 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 0
                                                      0  9  8  7  6  5  4  3  2  1  2  3  4  5  6  7  8  9  0
                                             0   9   8   7   6   5   4   3   2   1   2   3   4   5   6   7   8   9   0
                                    0    9    8    7    6    5    4    3    2    1    2    3    4    5    6    7    8    9    0
                           0     9     8     7     6     5     4     3     2     1     2     3     4     5     6     7     8     9     0
                  0      9      8      7      6      5      4      3      2      1      2      3      4      5      6      7      8      9      0
         0       9       8       7       6       5       4       3       2       1       2       3       4       5       6       7       8       9       0
0        9        8        7        6        5        4        3        2        1        2        3        4        5        6        7        8        9        0

Input: ABCD
Output:
D  C  B  A  B  C  D
   D C B A B C D
      DCBABCD
   D C B A B C D
D  C  B  A  B  C  D

Input: =>)}]
Output:
]   }   )   >   =   >   )   }   ]
    ]  }  )  >  =  >  )  }  ]
        ] } ) > = > ) } ]
            ]})>=>)}]
        ] } ) > = > ) } ]
    ]  }  )  >  =  >  )  }  ]
]   }   )   >   =   >   )   }   ]

Input: XXxxXX
Output:
X    X    x    x    X    X    X    x    x    X    X
     X   X   x   x   X   X   X   x   x   X   X
          X  X  x  x  X  X  X  x  x  X  X
               X X x x X X X x x X X
                    XXxxXXXxxXX
               X X x x X X X x x X X
          X  X  x  x  X  X  X  x  x  X  X
     X   X   x   x   X   X   X   x   x   X   X
X    X    x    x    X    X    X    x    x    X   X

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	inputbug("1234567890")
	inputbug("ABCD")
	inputbug("=>)}]")
	inputbug("XXxxXX")
}

func inputbug(s string) {
	n := len(s)
	r := []rune(s)
	for i := 2 - n; i < n-1; i++ {
		fmt.Print(strings.Repeat(" ", (n-1)*abs(n-abs(i)-2)))
		t := reverse(s) + string(r[1:])
		for _, c := range t {
			fmt.Printf("%c%s", c, strings.Repeat(" ", abs(i)))
		}
		fmt.Println()
	}
	fmt.Println()
}

func reverse(s string) string {
	r := []rune(s)
	n := len(r)
	for i := 0; i < n/2; i++ {
		r[i], r[n-i-1] = r[n-i-1], r[i]
	}
	return string(r)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
