package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"strconv"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("skit: ")

	var folder string
	flag.StringVar(&folder, "f", "folder", "folder name")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	depth, err := strconv.Atoi(flag.Arg(0))
	check(err)

	check(skit(depth, folder))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] depth")
	flag.PrintDefaults()
	os.Exit(2)
}

func skit(depth int, folder string) error {
	dir := ""
	for i := 0; i < depth; i++ {
		dir = filepath.Join(dir, folder)
	}

	err := os.MkdirAll(dir, 0755)
	if err != nil {
		return err
	}

	exe, err := os.Executable()
	if err != nil {
		return err
	}

	data, err := os.ReadFile(exe)
	if err != nil {
		return err
	}

	base := filepath.Base(exe)
	outfile := filepath.Join(dir, base)
	return os.WriteFile(outfile, data, 0644)
}
