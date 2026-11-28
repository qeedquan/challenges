/*

If a compiled language is used, the program must delete the compiled executable (but need not delete the source file). If an interpreted language is used, the program must delete the source file.

My opening bid:

Python (29 characters)
import os;os.remove(__file__)
Edit: to prevent solutions like rm -rf /, the program must not delete anything except the executable or source file.

*/

package main

import (
	"log"
	"os"
)

func main() {
	exe, err := os.Executable()
	if err != nil {
		log.Fatal(err)
	}
	os.Remove(exe)
}
