/*

This is a restricted-source, kolmogorov-complexity, code-golf challenge to produce a fixed output with no input.

The output format, however, is flexible - it may be printed to standard out, printed to standard error, returned as a list of characters, returned as a list of bytes, or returned as a list of integers. If you think anything else seems reasonable just ask in the comments!

Here is a simple, big-letter ASCII art CODEGOLF:

 CCCC   OOO   DDDD   EEEEE   GGG    OOO   L      FFFFF
C      O   O  D   D  E      G      O   O  L      F
C      O   O  D   D  EEE    G  GG  O   O  L      FFF
C      O   O  D   D  E      G   G  O   O  L      F
 CCCC   OOO   DDDD   EEEEE   GGGG   OOO   LLLLL  F
Without any newlines (or trailing spaces on any lines) it is 256 characters long:

 CCCC   OOO   DDDD   EEEEE   GGG    OOO   L      FFFFFC      O   O  D   D  E      G      O   O  L      FC      O   O  D   D  EEE    G  GG  O   O  L      FFFC      O   O  D   D  E      G   G  O   O  L      F CCCC   OOO   DDDD   EEEEE   GGGG   OOO   LLLLL  F
The (0-based) indices of the non-space characters are:

1, 2, 3, 4, 8, 9, 10, 14, 15, 16, 17, 21, 22, 23, 24, 25, 29, 30, 31, 36, 37, 38, 42, 49, 50, 51, 52, 53, 54, 61, 65, 68, 72, 75, 82, 89, 93, 96, 103, 104, 111, 115, 118, 122, 125, 126, 127, 132, 135, 136, 139, 143, 146, 153, 154, 155, 156, 163, 167, 170, 174, 177, 184, 188, 191, 195, 198, 205, 207, 208, 209, 210, 214, 215, 216, 220, 221, 222, 223, 227, 228, 229, 230, 231, 235, 236, 237, 238, 242, 243, 244, 248, 249, 250, 251, 252, 255
You may not use any of these 97 bytes in your code but must produce a list (or similarly output) these bytes, in this order, with the missing bytes replaced by the 32nd byte in the code page you are using (in many, many code-pages a space character).

You may include the pretty-printing* newlines (but no trailing spaces on the lines) if it helps.

For example using the Jelly code-page this output is acceptable:

 ¢£¤¥   ®µ½   ÇÐÑ×   ßæçðı   øœþ    $%&   *      12345
6      =   A  D   H  K      R      Y   ]  `      g
h      o   s  v   z  }~¶    ⁴  ⁷⁸  ⁻   Ɓ  Ƒ      ƲȤɓ
ƈ      ɲ   ʂ  ȥ   Ẹ  Ḳ      Ṭ   Ỵ  Ḃ   Ḟ  İ      Ṡ
 ẆẊẎŻ   ẹḥị   ṇọṛṣ   ẉỵẓȧḃ   ḟġḣŀ   ṗṙṡ   ẏż«»‘  ”
...but so is:

 ¢£¤¥   ®µ½   ÇÐÑ×   ßæçðı   øœþ    $%&   *      123456      =   A  D   H  K      R      Y   ]  `      gh      o   s  v   z  }~¶    ⁴  ⁷⁸  ⁻   Ɓ  Ƒ      ƲȤɓƈ      ɲ   ʂ  ȥ   Ẹ  Ḳ      Ṭ   Ỵ  Ḃ   Ḟ  İ      Ṡ ẆẊẎŻ   ẹḥị   ṇọṛṣ   ẉỵẓȧḃ   ḟġḣŀ   ṗṙṡ   ẏż«»‘  ”
...and so is:

[32, 1, 2, 3, 4, 32, 32, 32, 8, 9, 10, 32, 32, 32, 14, 15, 16, 17, 32, 32, 32, 21, 22, 23, 24, 25, 32, 32, 32, 29, 30, 31, 32, 32, 32, 32, 36, 37, 38, 32, 32, 32, 42, 32, 32, 32, 32, 32, 32, 49, 50, 51, 52, 53, 54, 32, 32, 32, 32, 32, 32, 61, 32, 32, 32, 65, 32, 32, 68, 32, 32, 32, 72, 32, 32, 75, 32, 32, 32, 32, 32, 32, 82, 32, 32, 32, 32, 32, 32, 89, 32, 32, 32, 93, 32, 32, 96, 32, 32, 32, 32, 32, 32, 103, 104, 32, 32, 32, 32, 32, 32, 111, 32, 32, 32, 115, 32, 32, 118, 32, 32, 32, 122, 32, 32, 125, 126, 127, 32, 32, 32, 32, 132, 32, 32, 135, 136, 32, 32, 139, 32, 32, 32, 143, 32, 32, 146, 32, 32, 32, 32, 32, 32, 153, 154, 155, 156, 32, 32, 32, 32, 32, 32, 163, 32, 32, 32, 167, 32, 32, 170, 32, 32, 32, 174, 32, 32, 177, 32, 32, 32, 32, 32, 32, 184, 32, 32, 32, 188, 32, 32, 191, 32, 32, 32, 195, 32, 32, 198, 32, 32, 32, 32, 32, 32, 205, 32, 207, 208, 209, 210, 32, 32, 32, 214, 215, 216, 32, 32, 32, 220, 221, 222, 223, 32, 32, 32, 227, 228, 229, 230, 231, 32, 32, 32, 235, 236, 237, 238, 32, 32, 32, 242, 243, 244, 32, 32, 32, 248, 249, 250, 251, 252, 32, 32, 255]
(This last one is a valid list output in any language with any code-page, and one may use any reasonable list-formatting too.)

Here is Python 3 code which shows the unavailable ASCII bytes.

* Although the printing itself might not actually be all that pretty!

q=[1, 2, 3, 4, 8, 9, 10, 14, 15, 16, 17, 21, 22, 23, 24, 25, 29, 30, 31, 36, 37, 38, 42, 49, 50, 51, 52, 53, 54, 61, 65, 68, 72, 75, 82, 89, 93, 96, 103, 104, 111, 115, 118, 122, 125, 126, 127, 132, 135, 136, 139, 143, 146, 153, 154, 155, 156, 163, 167, 170, 174, 177, 184, 188, 191, 195, 198, 205, 207, 208, 209, 210, 214, 215, 216, 220, 221, 222, 223, 227, 228, 229, 230, 231, 235, 236, 237, 238, 242, 243, 244, 248, 249, 250, 251, 252, 255]
print(repr(tuple(chr(i) for i in range(256)if i in q)), end='')

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
 CCCC   OOO   DDDD   EEEEE   GGG    OOO   L      FFFFF
C      O   O  D   D  E      G      O   O  L      F
C      O   O  D   D  EEE    G  GG  O   O  L      FFF
C      O   O  D   D  E      G   G  O   O  L      F
 CCCC   OOO   DDDD   EEEEE   GGGG   OOO   LLLLL  F
 `
