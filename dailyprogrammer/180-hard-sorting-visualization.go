/*

This challenge is up a bit early as I'm busy tomorrow so I'll probably forget. Anyway, after reading the comments on this week's Weekly Discussion, I wrote this week's Hard challenge based on two commonly requested things:

Graphical visualization

Usage of algorithms

and I decided to combine the two. This will also be a relatively open-ended challenge, as they seem to be quite popular among the developers - i.e. you - here. For this challenge, you will input a set of real numbers, and visualise the sorting of that set into ascending order, with an algorithm(s) of your choice, with any mode of visualisation you can imagine.

Input Description
You will be given a set of numbers that are between 0 and 1 (inclusive). The method of input is up to you.

Output Description
Visualise the sorting of the data, in a step-by-step manner, in any way you like. It can be console-based, graphical based, web-based, 3D based or even physically with an Arduino or the like, if you're feeling particularly adventurous!

Further Reading
To get to grips with some different sorting algorithms, let's look at four here.

Bubble Sort
Bubble sort is the simplest of the four. You simply step through the list, looking at pairs of elements that are next to each other. If the pair is not in order, you swap them and look at the next pair, like so:

4 1 2 3 5
<->

1 4 2 3 5
  <->

1 2 4 3 5
    <->

1 2 3 4 5
       x

1 2 3 4 5
If the list is not sorted after doing this, you go through the list again until it is. Done! This is simple but slow. Onto the next one...

Selection Sort
Selection sort is, to me, the most intuitive of the four, and is probably similar to what you do when you sort a pack of playing cards. Simply start with your list L and an empty list S. While L is not empty, move the lowest value from L to the end of S, like so:

[3 5 6 1 8 7 2 4] []

[3 5 6 8 7 2 4] [1]

[3 5 6 8 7 4] [1 2]

[5 6 8 7 4] [1 2 3]

[5 6 8 7] [1 2 3 4]

[6 8 7] [1 2 3 4 5]

[8 7] [1 2 3 4 5 6]

[8] [1 2 3 4 5 6 7]

[] [1 2 3 4 5 6 7 8]
And now S is our sorted list. Simple again, however this too is slow on larger lists.

Merge Sort
Fast and surprisingly simple, once you get your head round it. First, split the list into lists with only 1 item:

[3] [5] [6] [1] [8] [7] [2] [4]
Then, take pairs of lists and merge them. How to merge them, you say? It's fairly simple - to merge lists A and B into new list C, do the following. While A and B are not empty, look at the first item in both lists. Append the lowest of the two to the end of list C. If either A or B is empty and the other isn't, just put the remaining items from the non-empty list at the end of C. OK.

Now, we have the following lists after merging 3 times:

[3 5] [1 6] [7 8] [2 4]

[1 3 5 6] [2 4 7 8]

[1 2 3 4 5 6 7 8]
The final list there is your list in order. Done!

Quicksort
This one is perhaps the most difficult of the four, but it's still not too hard. The first step is to take the list - let's call it L - and partition it into two halves, with a 'pivot' value in the middle. A good way to choose the pivot is to pick 3 random values from L and choose the median. Anyway, after we've split the list in half - into two lists, A and B - we look at the elements in A, which we will make our lower list, and compare each value against the pivot value. If the element is greater than the pivot value, put it at into list B (our higher list), in no particular position. Now, do the same for list B; look at each element and see if it is lower than the pivot. If it is, put it into list A at no particular position. Our list L now looks like:

A pivot B
now sort A and B the same way we sorted L. If A or B contain either no elements or one element, it is already sorted, and if there are only 2 values, you can just swap them.

Stuck?
Here are a few videos to kick-start your imagination!

15 Sorting Algorithms in 6 Minutes
https://www.youtube.com/watch?v=kPRA0W1kECg

Bubble Sort folk dance
https://www.youtube.com/watch?v=lyZQPjUT5B4

Quick Sort visualized
https://www.youtube.com/watch?v=8hEyhs3OV1w

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/gif"
	"log"
	"math/rand/v2"
	"os"
	"sort"
)

var flags struct {
	array  []int
	delay  int
	size   int
	width  int
	height int
}

var palette color.Palette

func main() {
	parseflags()
	stream := &gif.GIF{
		LoopCount: -1,
	}
	visualize(stream, flags.width, flags.height, flags.delay, flags.array)
	check(gif.EncodeAll(os.Stdout, stream))
}

func init() {
	palette = []color.Color{}
	for shade := uint8(0); shade < 255; shade++ {
		palette = append(palette, color.RGBA{shade, shade, shade, 255})
	}
	palette = append(palette, color.RGBA{255, 0, 0, 255})
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options]")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.IntVar(&flags.delay, "delay", 5, "specify delay time between frames")
	flag.IntVar(&flags.width, "width", 10, "specify bar width")
	flag.IntVar(&flags.height, "height", 100, "specify bar height")
	flag.IntVar(&flags.size, "size", 64, "specify array size")
	flag.Usage = usage
	flag.Parse()
	flags.array = rand.Perm(flags.size)
}

// Ported from @skeeto solution
func visualize(stream *gif.GIF, width, height, delay int, array []int) {
	frame(stream, width, height, delay, array, -1, -1)
	sort.Slice(array, func(i, j int) bool {
		frame(stream, width, height, delay, array, i, j)
		return array[i] < array[j]
	})
	frame(stream, width, height, delay, array, -1, -1)
}

func frame(stream *gif.GIF, width, height, delay int, array []int, index0, index1 int) {
	bounds := image.Rect(0, 0, width*len(array), height)
	picture := image.NewPaletted(bounds, palette)
	for y := range height {
		edge := y < height/10 || y > height-height/10
		for x := range width * len(array) {
			index := x / width
			selected := index == index0 || index == index1
			if edge && selected {
				picture.SetColorIndex(x, y, 255)
			} else {
				shade := min(254, (array[index]*255)/len(array))
				picture.SetColorIndex(x, y, uint8(shade))
			}
		}
	}
	stream.Image = append(stream.Image, picture)
	stream.Delay = append(stream.Delay, delay)
}
