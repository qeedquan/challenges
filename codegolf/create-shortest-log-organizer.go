/*

Create the shortest script that organizes all the logs by month and date.

Rules
Syntax

organize <folder to scan> <folder to place logs>
folder cannot be root
the two folder should be different and not contain one another
Behaviour

The script should scan all the *.log files in <folder to scan> and copy them to <folder to place logs> in sub-folders corresponding to the year and month of the last modified time of the log file, named like year_month.

Example:

organize /var/log/apache2 /temp/logs
would give folder structure like this:

/temp/logs/
|-- 2014_01
|-- 2014_02
|-- 2014_03
|-- 2014_04
|-- 2014_05
Languages, environment

All languages and OSs are permitted but need to be specified.

But since this is a code-golf question, script languages (python, bash, windows batch) will be more fit from the start.

*/

package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"path/filepath"
)

func main() {
	log.SetPrefix("organize: ")
	log.SetFlags(0)

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	files, err := filepath.Glob(filepath.Join(flag.Arg(0), "*.log"))
	check(err)

	for _, file := range files {
		fileinfo, err := os.Stat(file)
		if err != nil {
			log.Println("organize: error:", err)
			continue
		}

		modtime := fileinfo.ModTime()
		directory := filepath.Join(flag.Arg(1), fmt.Sprintf("%d_%d", modtime.Year(), modtime.Month()))
		err = os.MkdirAll(directory, 0755)
		if err != nil {
			log.Println("organize: error:", err)
			continue
		}

		output := filepath.Join(directory, fileinfo.Name())
		err = copyfile(file, output)
		if err != nil {
			log.Println("organize: error", err)
		}
	}
}

func copyfile(from, to string) error {
	in, err := os.Open(from)
	if err != nil {
		return err
	}
	defer in.Close()

	out, err := os.Create(to)
	if err != nil {
		return err
	}
	defer out.Close()

	_, err = io.Copy(out, in)
	if err != nil {
		return err
	}

	return nil
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <folder to scan> <folder to place logs>")
	flag.PrintDefaults()
	os.Exit(2)
}
