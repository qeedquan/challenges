/*

Challenge
Write a program which, using the XML data from the site here, display the name of the programme which is currently showing on BBC 1.

Information
All times are given at London time (GMT+1 at the time of posting and GMT+0 after the 30th October). Therefore, you should convert your local time to London time.

Each programme is given a start and end time. If the current time is after the start time and before the end time of a programme, that programme is currently showing. Your programme may handle overlaps in anyway you wish.

Your output must be the programme title, like so:

BBC News
However, if the programme has a subtitle (shown by the presence of the subtitle tag), the output should be like so:

Steptoe and Son: The Piano
Where Steptoe and Son is the title and The Piano is the subtitle. An example programme with a subtitle is as follows:

<programme>
    <subtitle>Newcastle</subtitle>
    <title>Flog It!</title>
    <end>1710</end>
    <start>1610</start>
    <desc>
      Antiques series. Paul Martin presents from the Discovery Museum in Newcastle. The items uncovered include a book of autographs with a local connection. Also in HD. [S]
    </desc>
</programme>
URL shorteners are disallowed but XML parsing libraries are allowed.

Winning
The shortest code in bytes wins.

*/

package main

import (
	"encoding/xml"
	"fmt"
	"io"
	"log"
	"net/http"
	"sort"
	"time"
)

func main() {
	err := listings(link(time.Now()))
	if err != nil {
		log.Fatal(err)
	}
}

func link(date time.Time) string {
	const format = "https://tvprofil.net/xmltv/data/bbc1.uk/%04d-%02d-%02d_bbc1.uk_tvprofil.net.xml"
	return fmt.Sprintf(format, date.Year(), date.Month(), date.Day())
}

func listings(url string) error {
	resp, err := http.Get(url)
	if err != nil {
		return err
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return err
	}

	var result Listing
	err = xml.Unmarshal(data, &result)
	if err != nil {
		return err
	}

	titles := []string{}
	seen := make(map[string]bool)
	for _, programs := range result.Programs {
		if !seen[programs.Title] {
			titles = append(titles, programs.Title)
			seen[programs.Title] = true
		}
	}
	sort.Strings(titles)

	for i := range titles {
		fmt.Println(titles[i])
	}

	return nil
}

type Listing struct {
	XMLName  xml.Name  `xml:"tv"`
	Channel  Channel   `xml:"channel"`
	Programs []Program `xml:"programme"`
}

type Channel struct {
	ID          string `xml:"id,attr"`
	DisplayName string `xml:"display-name"`
	URL         string `xml:"url"`
	Icon        Icon   `xml:"icon"`
}

type Icon struct {
	Src string `xml:"src,attr"`
}

type Program struct {
	Title string `xml:"title"`
}
