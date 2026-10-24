/*

A little while ago we took advantage of a very useful blank map hosted at Wikipedia.
https://www.reddit.com/r/dailyprogrammer/comments/yj38u/8202012_challenge_89_difficult_coloring_the/
https://en.wikipedia.org/wiki/File:Blank_US_Map.svg

The advantage of this map is that it is very easy to assign different colors to each state
(for details on how to do this, see the previous problem).
We only had some silly fun with it, but it can also obviously be very useful in visualizing information about the country.

Here is a text-file with unemployment data for all US states for each month from January 1980 to June 2012, stored in CSV format.
The first column is the dates, then each column is the data for each state (the order of which is detailed in the headers).
I got this information from the Federal Reserve Bank of St. Louis FRED database, which has excellent API access (good work, St. Louis Fed!).
https://fred.stlouisfed.org/

Using this table, make a program that can draw a map of unemployment across the United States at a given date.
For instance, here is a map of unemployment for July 2005.
As you can see, I edited the map slightly, adding a scale to the left side and a header that includes the date.
You can do that too if you wish, but it is not necessary in any way.

Your map doesn't need to look anything like mine.
You can experiment with different colors and different styles.
I selected the colors linearly based on unemployment, but you may want to use a different function to select colors,
or perhaps color all states within a certain range the same
(so that all states with 0%-2% are the same color, as are the states with 2%-4%, 4%-6%, etc). Experiment and see what you like.

Create a map which shows unemployment for February 1995.

*/

package main

import (
	"bytes"
	"encoding/csv"
	"flag"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
	"time"
)

type Stat struct {
	Date   time.Time
	States map[string]float64
	Min    float64
	Max    float64
}

type Color struct {
	R, G, B, A float64
}

var flags struct {
	svgfile string
	csvfile string
	outfile string
	date    time.Time
	stop0   Color
	stop1   Color
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("unemployment: ")

	parseflags()

	svg, err := os.ReadFile(flags.svgfile)
	check(err)

	stats, err := readstats(flags.csvfile)
	check(err)

	stat := finddate(stats, flags.date)
	if stat == nil {
		log.Fatalf("failed to find info for date %v", flags.date)
	}

	err = render(stat, svg, flags.outfile, flags.stop0, flags.stop1)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	var (
		date string
		err  error
	)
	flag.StringVar(&date, "date", "1995-02-01", "specify date to render")
	flag.StringVar(&flags.svgfile, "map", "map.svg", "Specify SVG map file")

	flags.stop0 = Color{0.4, 0.5, 1, 1}
	flags.stop1 = Color{0, 0, 1, 1}

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 2 {
		usage()
	}

	flags.date, err = time.Parse("2006-01-02", date)
	check(err)

	flags.csvfile = flag.Arg(0)
	flags.outfile = flag.Arg(1)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] data.csv output.svg")
	flag.PrintDefaults()
	os.Exit(2)
}

func render(stat *Stat, svg []byte, outfile string, stop0, stop1 Color) error {
	buf := new(bytes.Buffer)
	for state, value := range stat.States {
		x := minmaxnorm(value, stat.Min, stat.Max)
		color := colorlerp(x, stop0, stop1)
		fmt.Fprintf(buf, ".%s {fill:%s} /* %v */\n", state, hexcolor(color), value)
	}

	i := bytes.Index(svg, []byte("</style>"))
	if i > 0 {
		svg = append(svg[:i], append(buf.Bytes(), svg[i:]...)...)
	}
	return os.WriteFile(outfile, svg, 0644)
}

func readstats(name string) ([]Stat, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	reader := csv.NewReader(file)
	records, err := reader.ReadAll()
	if err != nil {
		return nil, err
	}

	var (
		stats    []Stat
		headings = make(map[int]string)
	)
	for index, record := range records {
		if len(record) != 51 {
			return nil, fmt.Errorf("invalid number of columns, got %d columns", len(record))
		}

		if index == 0 {
			for id, field := range record {
				headings[id] = strings.ToLower(field)
			}
			continue
		}

		stat := Stat{}
		stat.Date, _ = time.Parse("2006-01-02", record[0])
		stat.States = make(map[string]float64)
		for id := 1; id < len(record); id++ {
			stat.States[headings[id]], _ = strconv.ParseFloat(record[id], 64)
		}
		for _, value := range stat.States {
			if stat.Min == 0 {
				stat.Min = value
			}
			stat.Min = min(stat.Min, value)
			stat.Max = max(stat.Max, value)
		}

		stats = append(stats, stat)
	}
	return stats, nil
}

func finddate(stats []Stat, date time.Time) *Stat {
	for i := range stats {
		stat := &stats[i]
		if stat.Date.Equal(date) {
			return stat
		}
	}
	return nil
}

func minmaxnorm(x, min, max float64) float64 {
	return (x - min) / (max - min)
}

func hexcolor(c Color) string {
	r := int(c.R * 255)
	g := int(c.G * 255)
	b := int(c.B * 255)
	return fmt.Sprintf("#%02x%02x%02x", r, g, b)
}

func colorlerp(x float64, c0, c1 Color) Color {
	return Color{
		lerp(x, c0.R, c1.R),
		lerp(x, c0.G, c1.G),
		lerp(x, c0.B, c1.B),
		lerp(x, c0.A, c1.A),
	}
}

func lerp(x, a, b float64) float64 {
	return a*(1-x) + b*x
}
