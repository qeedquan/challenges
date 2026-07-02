/*

Description
We want to find the closest airborne aeroplane to any given position in North America or Europe. To assist in this we can use an API which will give us the data on all currently airborne commercial aeroplanes in these regions.

OpenSky's Network API can return to us all the data we need in a JSON format.

https://opensky-network.org/api/states/all
From this we can find the positions of all the planes and compare them to our given position.

Use the basic Euclidean distance in your calculation.

Input
A location in latitude and longitude, cardinal direction optional

An API call for the live data on all aeroplanes

Output
The output should include the following details on the closest airborne aeroplane:

Geodesic distance
Callsign
Lattitude and Longitude
Geometric Altitude
Country of origin
ICAO24 ID
Challenge Inputs
Eifel Tower:

48.8584 N
2.2945 E
John F. Kennedy Airport:

40.6413 N
73.7781 W
Bonus
Replace your distance function with the geodesic distance formula, which is more accurate on the Earth's surface.

Challenge Credit:
This challenge was posted by u/Major_Techie, many thanks. Major_Techie adds their thanks to u/bitfluxgaming for the original idea.

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"math"
	"net/http"
	"os"
	"strconv"
)

const (
	EARTH_RADIUS = 6371
)

type State struct {
	Callsign  string
	Latitude  float64
	Longitude float64
	Altitude  float64
	Country   string
	ICAO24    string
}

var flags struct {
	metric  string
	service string
	target  [2]float64
}

func main() {
	parseflags()

	states, err := getflights(flags.service)
	check(err)

	var metric func([2]float64, [2]float64) float64
	switch flags.metric {
	case "euclidean":
		metric = euclidean
	case "spherical":
		metric = spherical
	default:
		log.Fatalf("unsupported metric: %q", flags.metric)
	}
	getclosest(flags.target, states, metric)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <latitude> <longitude>")
	flag.PrintDefaults()
	fmt.Fprintln(os.Stderr, "available metric function: euclidean spherical")
	os.Exit(2)
}

func parseflags() {
	flag.StringVar(&flags.metric, "metric", "spherical", "specify metric")
	flag.StringVar(&flags.service, "service", "https://opensky-network.org/api/states/all", "specify service")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	var err0, err1 error
	flags.target[0], err0 = strconv.ParseFloat(flag.Arg(0), 64)
	flags.target[1], err1 = strconv.ParseFloat(flag.Arg(1), 64)
	check(err0)
	check(err1)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func getclosest(target [2]float64, states []State, metric func([2]float64, [2]float64) float64) {
	var (
		from      = [2]float64{deg2rad(target[0]), deg2rad(target[1])}
		bestdist  = math.MaxFloat64
		beststate State
	)
	for _, state := range states {
		to := [2]float64{deg2rad(state.Latitude), deg2rad(state.Longitude)}
		dist := metric(from, to)
		if dist < bestdist {
			bestdist = dist
			beststate = state
		}
	}
	fmt.Printf("%f km\n", bestdist)
	fmt.Printf("%s\n", beststate.Callsign)
	fmt.Printf("(%f, %f)\n", beststate.Latitude, beststate.Longitude)
	fmt.Printf("%f\n", beststate.Altitude)
	fmt.Printf("%s\n", beststate.Country)
	fmt.Printf("%s\n", beststate.ICAO24)
	fmt.Println()
}

func getflights(url string) (states []State, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return
	}

	var airb struct {
		Time   int64
		States [][17]any
	}
	err = json.Unmarshal(data, &airb)
	if err != nil {
		return
	}

	for _, fields := range airb.States {
		var state State
		state.Callsign, _ = fields[1].(string)
		state.Latitude, _ = fields[6].(float64)
		state.Longitude, _ = fields[5].(float64)
		state.Altitude, _ = fields[7].(float64)
		state.Country, _ = fields[2].(string)
		state.ICAO24, _ = fields[0].(string)
		states = append(states, state)
	}
	return
}

func euclidean(from, to [2]float64) float64 {
	A := latlon2ecef(from[0], from[1])
	B := latlon2ecef(to[0], to[1])
	X := A[0] - B[0]
	Y := A[1] - B[1]
	Z := A[2] - B[2]
	return EARTH_RADIUS * math.Sqrt(X*X+Y*Y+Z*Z)
}

func spherical(from, to [2]float64) float64 {
	X, Y := from, to
	D0 := math.Sin(X[0]) * math.Sin(Y[0])
	D1 := math.Cos(X[0]) * math.Cos(Y[0])
	D2 := math.Cos(math.Abs(X[1] - Y[1]))
	return EARTH_RADIUS * math.Acos(D0+D1*D2)
}

func latlon2ecef(lat, lon float64) [3]float64 {
	return [3]float64{
		math.Sin(lat) * math.Cos(lon),
		math.Sin(lat) * math.Sin(lon),
		math.Cos(lat),
	}
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
