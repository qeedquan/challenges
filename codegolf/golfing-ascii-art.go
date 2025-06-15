/*

Let's try to golf this piece of ascii-art representing a golfing man:


      '\                   .  .                        |>18>>
        \              .         ' .                   |
       O>>         .                 'o                |
        \       .                                      |
        /\    .                                        |
       / /  .'                                         |
 jgs^^^^^^^`^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Source: JGS - http://www.retrojunkie.com/asciiart/sports/golf.htm

Rules:

No input allowed
No external resources allowed
The output must be exactly this text, displayed in a monospace font (OS console, JS console, HTML <pre> tag, ...), including the leading and trailing line-break.
Surrounding quotes or double-quotes are allowed (the JS console adds double quotes when you output a string, this is okay)
The best answer will be the one using the less characters in any language.

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `

      '\                   .  .                        |>18>>
        \              .         ' .                   |
       O>>         .                 'o                |
        \       .                                      |
        /\    .                                        |
       / /  .'                                         |
 jgs^^^^^^^` + "`" + `^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`
