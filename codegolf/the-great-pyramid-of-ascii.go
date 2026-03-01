/*

Introduction
It's 2600 BC and people are building pyramids now. They already made the basis of the pyramid but don't know how to continue. So, they called you for help.

The rules of making a pyramid is quite simple. For the layer above the previous layer, all you need to do is follow this step-by-step hand guide:

Cut the edges off the previous layer.

Above the / character, there must be a \ character and vice versa. This applies to every character except the edges.

The leftmost character is always a / and the rightmost character is always \.

Let's take an example of a basis for a pyramid:

//\/\/\\
We cut off the edges, leaving:

 /\/\/\
We change the forward slashes with backward slashes and vice versa:

 \/\/\/
The leftmost character is always a / and the rightmost character is always a \, so we change that:

 //\/\\
We place this layer on the previous layer:

 //\/\\
//\/\/\\
We continue until the top is reached (which looks like /\). So, eventually we get:

   /\
  //\\
 //\/\\
//\/\/\\
This is what you need to output.

The task
Given the basis of a pyramid (with a length greater than 3), output the full pyramid. You can safely assume that the leftmost character is / and the rightmost character is a \. You can also assume that the length of the basis is always even. The use of trailing spaces is allowed. The use of leading spaces is also allowed, as long as the pyramid stays in place. The use of 1 trailing and 1 leading newlines is allowed.

Test cases
Input: /\\\
Output:
 /\
/\\\

Input: //\\///\/\
Output:
    /\
   /\\\
  /\///\
 ///\\\/\
//\\///\/\

Input: /////////////\
Output:
      /\
     /\\\
    /////\
   /\\\\\\\
  /////////\
 /\\\\\\\\\\\
/////////////\
This is code-golf, so the submission with the least amount of bytes wins!

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	fmt.Println(pyramid(`/\\\`))
	fmt.Println(pyramid(`//\\///\/\`))
	fmt.Println(pyramid(`/////////////\`))
}

// ported from @Roland Illig solution
func pyramid(s string) string {
	m := re.FindStringSubmatch(s)
	n := len(m[3])
	if n == 0 {
		return m[1] + "\n"
	}

	r := ""
	for _, c := range m[3][1 : n-1] {
		if c == '/' {
			r += `\`
		} else {
			r += `/`
		}
	}
	return pyramid(" "+m[2]+r+m[4]) + m[1] + "\n"
}

var re = regexp.MustCompile(`^((\s*\S)(\S*)(\S))\s*`)
