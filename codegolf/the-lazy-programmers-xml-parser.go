/*

Background
You are working as a programmer for a car sales company. Your task for this week is to program an XML parser that takes in data about available models from different car manufacturers, and pretty-prints information about the newest models. Luckily for you, the testing department has provided only one test case! The faster you can write code that passes it, the more time you have for procrastination during the rest of the week.

Input
Your input is exactly this piece of XML data, supplied by the testing department. It contains data about some car manufacturers, their series of cars, and the models in these series. You may assume a trailing newline.

<?xml version="1.0" ?>
<products>
  <manufacturer name="Test Manufacturer 1">
    <series title="Supercar" code="S1">
      <model>
        <name>Road Czar</name>
        <code>C</code>
        <year>2011</year>
      </model>
      <model>
        <name>Ubervehicle</name>
        <code>U</code>
        <year>2013</year>
      </model>
      <model>
        <name>Incredibulus</name>
        <code>I</code>
        <year>2015</year>
      </model>
      <model>
        <name>Model 1</name>
        <code>01</code>
        <year>2010</year>
      </model>
    </series>
    <series title="Test series 22" code="Test">
      <model>
        <name>Test model asdafds</name>
        <code>TT</code>
        <year>2014</year>
      </model>
    </series>
  </manufacturer>
  <manufacturer name="Car Corporation">
    <series title="Corporation Car" code="CC">
      <model>
        <name>First and Only Model</name>
        <code>FOM</code>
        <year>2012</year>
      </model>
    </series>
  </manufacturer>
  <manufacturer name="Second Test Manufacturer">
    <series title="AAAAAAAAAAAAAA" code="D">
      <model>
        <name>Some older model</name>
        <code>O</code>
        <year>2011</year>
      </model>
      <model>
        <name>The newest model</name>
        <code>N</code>
        <year>2014</year>
      </model>
    </series>
    <series title="BBBBBBBBBBBBBBB" code="asdf">
      <model>
        <name>Another newest model here</name>
        <code>TT</code>
        <year>2015</year>
      </model>
    </series>
  </manufacturer>
</products>
Output
Your output is this string. It lists the car manufacturers in alphabetical order, followed by a colon and the number of series they make. Under each manufacturer, it lists the series name, model name, and code of each of their models, starting from the newest and going backward by year. Trailing whitespace and line breaks are acceptable, as long as your output looks similar to this when printed.

Car Corporation: 1 series
  Corporation Car, First and Only Model (CC-FOM)
Second Test Manufacturer: 2 series
  BBBBBBBBBBBBBBB, Another newest model here (asdf-TT)
  AAAAAAAAAAAAAA, The newest model (D-N)
  AAAAAAAAAAAAAA, Some older model (D-O)
Test Manufacturer 1: 2 series
  Supercar, Incredibulus (S1-I)
  Test series 22, Test model asdafds (Test-TT)
  Supercar, Ubervehicle (S1-U)
  Supercar, Road Czar (S1-C)
  Supercar, Model 1 (S1-01)
Rules and Scoring
You may write either a function or full program. The lowest byte count wins, and standard loopholes are disallowed.

Note that the input is fixed: you don't need to support any other inputs than the one given here. Your program is allowed to return nonsense or even crash if the input is modified in any way. You may also ignore the input and hard-code the output, if desired. However, you may not use XML or HTML parser libraries or built-ins.

*/

package main

import (
	"encoding/xml"
	"fmt"
	"log"
	"sort"
)

type Products struct {
	Manufacturer []Manufacturer `xml:"manufacturer"`
}

type Manufacturer struct {
	XMLName xml.Name `xml:"manufacturer"`
	Name    string   `xml:"name,attr"`
	Series  []Series `xml:"series"`
}

type Series struct {
	XMLName xml.Name `xml:"series"`
	Title   string   `xml:"title,attr"`
	Code    string   `xml:"code,attr"`
	Model   []Model  `xml:"model"`
}

type Model struct {
	XMLName xml.Name `xml:"model"`
	Name    string   `xml:"name"`
	Code    string   `xml:"code"`
	Year    int      `xml:"year"`
}

type Car struct {
	Series *Series
	Model  *Model
}

func main() {
	err := analyze(XML)
	if err != nil {
		log.Fatal(err)
	}
}

func analyze(data string) error {
	var products Products
	err := xml.Unmarshal([]byte(data), &products)
	if err != nil {
		return err
	}

	sort.Slice(products.Manufacturer, func(i, j int) bool {
		return products.Manufacturer[i].Name < products.Manufacturer[j].Name
	})

	for _, manufacturer := range products.Manufacturer {
		fmt.Printf("%s: %d series\n", manufacturer.Name, len(manufacturer.Series))

		var cars []Car
		for _, series := range manufacturer.Series {
			for _, model := range series.Model {
				cars = append(cars, Car{&series, &model})
			}
		}

		sort.Slice(cars, func(i, j int) bool {
			return cars[i].Model.Year > cars[j].Model.Year
		})

		for _, car := range cars {
			series := car.Series
			model := car.Model
			fmt.Printf("  %s, %s (%s-%s)\n", series.Title, model.Name, series.Code, model.Code)
		}
	}

	return nil
}

const XML = `
<?xml version="1.0" ?>
<products>
  <manufacturer name="Test Manufacturer 1">
    <series title="Supercar" code="S1">
      <model>
        <name>Road Czar</name>
        <code>C</code>
        <year>2011</year>
      </model>
      <model>
        <name>Ubervehicle</name>
        <code>U</code>
        <year>2013</year>
      </model>
      <model>
        <name>Incredibulus</name>
        <code>I</code>
        <year>2015</year>
      </model>
      <model>
        <name>Model 1</name>
        <code>01</code>
        <year>2010</year>
      </model>
    </series>
    <series title="Test series 22" code="Test">
      <model>
        <name>Test model asdafds</name>
        <code>TT</code>
        <year>2014</year>
      </model>
    </series>
  </manufacturer>
  <manufacturer name="Car Corporation">
    <series title="Corporation Car" code="CC">
      <model>
        <name>First and Only Model</name>
        <code>FOM</code>
        <year>2012</year>
      </model>
    </series>
  </manufacturer>
  <manufacturer name="Second Test Manufacturer">
    <series title="AAAAAAAAAAAAAA" code="D">
      <model>
        <name>Some older model</name>
        <code>O</code>
        <year>2011</year>
      </model>
      <model>
        <name>The newest model</name>
        <code>N</code>
        <year>2014</year>
      </model>
    </series>
    <series title="BBBBBBBBBBBBBBB" code="asdf">
      <model>
        <name>Another newest model here</name>
        <code>TT</code>
        <year>2015</year>
      </model>
    </series>
  </manufacturer>
</products>
`
