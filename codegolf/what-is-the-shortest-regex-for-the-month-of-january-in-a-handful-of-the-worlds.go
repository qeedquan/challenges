/*

What is the shortest regular expression equivilant to the following?

ENERO|GENER|GENNAIO|IANUARI|IANUARII|IONAWR|JAANUARIL|JANAIRU|JANAR|JANNEWARIS|JANUAR|JANUARI|JANUARIE|JANUARO|JANUARY|JANUWALE|JANVIER|JANVYE|JENUWARI
The shortest regex, in bytes, wins.

If you are worried about what flavor of regex we are using, then be the first one to edit my question, and you can have a link to a description of the specific regex flavor of your choice. Please choose a mainstream regex flavor, nothing too esoteric. * should mean zero or more. + should be one or more and so on and so forth.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	re := regexp.MustCompile("ENERO|GENER|GENNAIO|IANUARI|IANUARII|IONAWR|JAANUARIL|JANAIRU|JANAR|JANNEWARIS|JANUAR|JANUARI|JANUARIE|JANUARO|JANUARY|JANUWALE|JANVIER|JANVYE|JENUWARI")
	fmt.Println(re.FindAllString("JANVIER JENUWARI GENER JANUARO", -1))
}
