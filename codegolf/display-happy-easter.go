/*

Your task is to print the following ASCII Art:

 _     _                            _______                           _
| |   | |                          (_______)          _              | |
| |__ | | ____ ____  ____  _   _    _____   ____  ___| |_  ____  ____| |
|  __)| |/ _  |  _ \|  _ \| | | |  |  ___) / _  |/___)  _)/ _  )/ ___)_|
| |   | ( ( | | | | | | | | |_| |  | |____( ( | |___ | |_( (/ /| |    _
|_|   |_|\_||_| ||_/| ||_/ \__  |  |_______)_||_(___/ \___)____)_|   |_|
              |_|   |_|   (____/

Remember, this is code-golf, so the code with the smallest amount of bytes wins. Good luck.

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
| |   | |                          (_______)          _              | |
| |__ | | ____ ____  ____  _   _    _____   ____  ___| |_  ____  ____| |
|  __)| |/ _  |  _ \|  _ \| | | |  |  ___) / _  |/___)  _)/ _  )/ ___)_|
| |   | ( ( | | | | | | | | |_| |  | |____( ( | |___ | |_( (/ /| |    _
|_|   |_|\_||_| ||_/| ||_/ \__  |  |_______)_||_(___/ \___)____)_|   |_|
              |_|   |_|   (____/
`