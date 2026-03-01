/*

Write a class Block that creates a block (Duh..)

##Requirements

The constructor should take an array as an argument, this will contain 3 integers of the form [width, length, height] from which the Block should be created.

Define these methods:

`getWidth()` return the width of the `Block`

`getLength()` return the length of the `Block`

`getHeight()` return the height of the `Block`

`getVolume()` return the volume of the `Block`

`getSurfaceArea()` return the surface area of the `Block`

Examples
    let b = new Block([2,4,6]) -> creates a `Block` object with a width of `2` a length of `4` and a height of `6`
    b.getWidth() // -> 2

    b.getLength() // -> 4

    b.getHeight() // -> 6

    b.getVolume() // -> 48

    b.getSurfaceArea() // -> 88

Note: no error checking is needed

Any feedback would be much appreciated

*/

package main

func main() {
	block := NewBlock(2, 4, 6)
	assert(block.Width() == 2)
	assert(block.Length() == 4)
	assert(block.Height() == 6)
	assert(block.Volume() == 48)
	assert(block.SurfaceArea() == 88)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Block struct {
	width  int
	length int
	height int
}

func NewBlock(width, length, height int) *Block {
	return &Block{width, length, height}
}

func (b *Block) Width() int  { return b.width }
func (b *Block) Length() int { return b.length }
func (b *Block) Height() int { return b.height }
func (b *Block) Volume() int { return b.width * b.length * b.height }
func (b *Block) SurfaceArea() int {
	return 2 * (b.width*b.length + b.width*b.height + b.length*b.height)
}
