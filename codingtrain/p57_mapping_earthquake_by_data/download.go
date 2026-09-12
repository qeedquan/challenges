package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

var flags struct {
	longitude float64
	latitude  float64
	zoom      float64
	width     int
	height    int
	apikey    string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("")

	parseflags()

	url := fmt.Sprintf(
		"https://api.mapbox.com/styles/v1/mapbox/dark-v9/static/%v,%v,%v/%vx%v?access_token=%v",
		flags.longitude, flags.latitude, flags.zoom, flags.width, flags.height,
		flags.apikey,
	)
	file := fmt.Sprintf("worldmap_%v_%v_%v_%vx%v.png", flags.longitude, flags.latitude, flags.zoom, flags.width, flags.height)
	download(url, file)

	download("https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_day.csv", "all_day.csv")
	download("https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_month.csv", "all_month.csv")
}

func parseflags() {
	flag.Float64Var(&flags.longitude, "longitude", 0, "specify longitude")
	flag.Float64Var(&flags.latitude, "latitude", 0, "specify latitude")
	flag.Float64Var(&flags.zoom, "zoom", 1, "specify zoom")
	flag.IntVar(&flags.width, "width", 1024, "specify width")
	flag.IntVar(&flags.height, "height", 512, "specify height")
	flag.StringVar(&flags.apikey, "apikey", "", "specify apikey")
	flag.Parse()
}

func download(url, file string) {
	log.Printf("Downloading %q\n", url)

	resp, err := http.Get(url)
	if err != nil {
		log.Printf("Failed to get: %v\n", err)
		return
	}

	buf, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Printf("Failed to download body: %v\n", err)
		return
	}

	err = os.WriteFile(file, buf, 0644)
	if err != nil {
		log.Printf("Failed to write to file: %v\n", err)
		return
	}
}
