/*

Build a function that will take an array of filenames (as string) and return an array of array. Each array will provide 3 informations about the image file: the full filename, its name and the extension. (See the example below)

Detect the image files based on the end of the filename which is their format (extension).
Image files are defined as jpg, gif, png, tiff, svg and bmp. So "puppies.jpg" is a image file while "puppies.html" is not.

For example:
Input: ["imgName.extension", "notAnImg"]
Output: [["imgName.extension", "imgName", "extension"], null]

So:
imageFilter(["index.html", "favicon.gif"])
return [null, ["favicon.gif", "favicon", "gif"]]

!Non Case Sensitive, so a file with the extension .jpg or .JPG is still an image.

*/

package main

import (
	"fmt"
	"path"
	"strings"
)

func main() {
	fmt.Println(filter([]string{"index.html", "favicon.gif"}))
}

func filter(names []string) [][3]string {
	var result [][3]string
	for _, name := range names {
		ext := path.Ext(name)
		switch strings.ToLower(ext) {
		case ".png", ".jpg", ".gif", ".tiff", ".svg", ".bmp":
			result = append(result, [3]string{name, name[:len(name)-len(ext)], ext[1:]})
		default:
			result = append(result, [3]string{})
		}
	}
	return result
}
