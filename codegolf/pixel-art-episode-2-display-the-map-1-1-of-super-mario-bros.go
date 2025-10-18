/*

Last challenge (Pixel-art, episode 1: display Super Mario) was just a training... (and you completed it in amazing ways, thanks!)

This time, you have to work a little bit more. You have to display all the first overworld map of Super Mario bros on NES, without enemies, and without Mario.

Your program or function must display all the pixels of the following image OR produce an image file similar to it (BMP, PNG, or GIF).

Your program must not access the internet in any way.

The output can be zoomed if you want, and the pixels can be ASCII or HTML elements if you want, as long as they have the right color.

Here's the model you have to follow:

The whole image: https://i.sstatic.net/2kfVc.png

The tileset (if you need it): http://img.ctrlv.in/img/14/10/19/5443f44c7eb78.png
You can produce your own tileset, subset or superset of this one.
You can use your tileset as a separate image file or include it in your code (for example, in base64). If it's separate, add its size in bytes to your score.

The map with coordinates: http://goo.gl/c8xJIx or http://img.ctrlv.in/img/14/10/19/544373adc9f64.png

The colors:

Sky blue: #5C94FC
Black: #000000
Pink: #FCBCB0 (for the blocks and the castle)
Brown: #C84C0C (for the blocks and the castle)
Orange: #FC9838 (for the "?" block)
Light green: #80D010 (for bushes, mountains, flagpole, warp)
Dark green: #00A800 (for bushes, mountains, flagpole, warp)
White: #FCFCFC (clouds)
Light blue: #3CBCFC (clouds)
Shortest answer wins.

EDIT: There will be two score boards, one where scores are counted in bytes and one where they are counted in characters.

Good luck!

P.S: Here are some notes that could help you optimizing your program:

Clouds, bushes and mountains have a repeating pattern (every 48 columns)
Flying blocks are only present on lines 4 and 8
Each tile or sprite of the map uses at most 4 colors (including blue or transparent, depending on how you see it)
Bushes are just "top of clouds" with a diferent color palette
Single, double and triple bushes/clouds can easily be formed using the same mini set of 16x16px pieces. This is also true for the single and triple mountains

*/

package main

import (
	"bytes"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(worldmap())
}

func repeat(s string, n int) string {
	return strings.Repeat(s, n)
}

func block(n int64) string {
	return "<div style='background: url(data:;base64,iVBORw0KGgoAAAANSUhEUgAAAQAAAAAgBAMAAAAPh7vXAAAAG1BMVEVclPwAAAAAqADITAyA0BD8/Pz8vLD8mDg8vPyQWLLUAAACwklEQVR4XrWWS4rjMBCGXcxjrfKje23hA4wRJNtJ8AEmi4JsTUD7phd9gkCOPSWN5OiRttsx8xGJ2CKpj99SJcVOW8bdv+miHd+U5VfxRaQDE/y61jz91FqpHrFSPb/rFRctXEW8KF668E31b+w/LG+BAOIXBOoh4uDX1c4ImCLIVFxcmaEKbSMYc4FXWz8QACKxLFBKyQLS02YCaAkEbAQ4CaBj//GuVJgANESnryRgBLqjZLquyxJAh9rx9GIEtGKcwKh6n8H+Q2G1DwQaYgFYJSCP+SPo0VKZ+HkkAj1WgcDre58IUCO2JLAsoPU4J3DmDLYmgI5MIN8Db68qEAA6X+lKp2cTwBfN4IS/DgSyY/je412g4er0RAL++PrvRYe/nheYTgEgOQSsTQCOUiwLWKUXFTcinAQa8ohGrEygNt1gWUAjCwSGJoG9FwCaOJFYlYAXwE8o9IhMjxfbjII+ED6CHxQgxLoESivgs0WHvy40GioursdIgFsxulYMDQWcko0IiGImgSWBES09FzdjWgh/jBqKiAXQFMCZX0OQUswIuOuq5zHywIQlAXR1paPIP25n/IRpd0aZiiRkighXQVpaOd20z+A4BI3w+2/XBzDB3HskUPPnYpozGc55AKULoGwfCHTdUwLImyiL4GoUrlkCIL2AFE8mgI57sYERIo3gdqXbjR3iCMq7QDufAH7CtDtjgcMhESAufzuzAvMn2wElsomYTSA8AeFJeCzQpQ8BkA34ZQMQaQBt2Zp5JoEVAjbCoxHIMjgR0wT1QXoBaRDPJJDtAWB7JhOAhgQSIQQLZSzQrt8DeR/Aevo/nSgApn/MQSaI7X0ABs8B2H6eUia02/tAPUzUSwIgM8TmPjAEHGBdAEy7tQ/gEFKLdQEwYlsfgCFGrAuAaZME/qMAyIeIbX2gjgQOawNg2rV74C9KQ+xyNDQoswAAAABJRU5ErkJ)-" + fmt.Sprint((n%16)*16) + "px -" + fmt.Sprint((n/16)*16) + "px; width: 16px; height: 16px; float: left; }'></div>"
}

func blocks(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		n, _ := strconv.ParseInt(string(r), 32, 64)
		w.WriteString(block(n))
	}
	return w.String()
}

// ported from @Snack solution
func worldmap() string {
	w := new(bytes.Buffer)
	w.WriteString("<html>")
	w.WriteString("<head><title>Mario World Map #1</title></head>")
	w.WriteString("<body style=width:3392px>")
	w.WriteString(repeat(block(7), 212))
	w.WriteString(repeat(blocks("777777777777777777745677777777777777455677777777"), 4))
	w.WriteString(blocks("777777c7777777777777"))
	w.WriteString(repeat(blocks("7777777745677777777klm77777455567777kllm77777777"), 4))
	w.WriteString(blocks("777777s7456777777777"))
	w.WriteString(repeat(blocks("77777777klm7777777777777777klllm7777777777777777"), 4))
	w.WriteString(blocks("777777s7klm777777777"))
	w.WriteString(blocks("777777777777777777777737777777777777777777777777777777777777777777777777777777772222222277722237777777777777737777777777722277772332777777777777777777777777777777777777777777777777777777770077777777s7777777777777"))
	w.WriteString(blocks("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777700077777777s7777777777777"))
	w.WriteString(blocks("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777000077777777s7777777777777"))
	w.WriteString(blocks("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777770000077777777s7777ddd777777"))
	w.WriteString(blocks("7777777777777777377723232777777777777777777777ab777777777ab7777777777777777772327777777777777727777727777737737737777727777777777227777770770777777777700770777777777777223277777777777700000077777777s7777tgv777777"))
	w.WriteString(blocks("77877777777777777777777777777777777777ab777777qr778777777qr7777777777777777777777777777777777777778777777777777777777777777777777777777700770077778777000770077777777777777777777777777000000077778777s777dfffd77777"))
	w.WriteString(blocks("7nop777777777777787777777777ab77777777qr777777qr7nop77777qr77777787777777777777777777777777777777nop777777777777787777777777777777777770007700077nop700007700077787ab77777777777777ab700000000777nop77s777ggegg77877"))
	w.WriteString(blocks("no9op777777hiiijnop7777hij77qr77777777qr7hiij7qrno9op7777qrhiiijnop7777hij777777777777777hiij777no9op777777hiiijnop7777hij7777777777770000ii0000no9o00000770000jnopqr77hij777777777qr00000000077no9op70777gguggjnop7"))
	w.WriteString(repeat(repeat(block(1), 69)+blocks("77")+repeat(block(1), 15)+blocks("777")+repeat(block(1), 64)+blocks("77")+repeat(block(1), 57), 2))
	w.WriteString("</body>")
	w.WriteString("</html>")
	return w.String()
}
