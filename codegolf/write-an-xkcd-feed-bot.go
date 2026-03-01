/*

The new xkcd feed bot room gave me an idea for a simple challenge.

Your code will have to monitor the xkcd website and output all the new comics to the user.

Specs
When first run it should just sit around waiting.
Then, when randall posts a new comic, within a minute, it should display the new comic in any of our usual standards for images (display, save, etc.)
If the comic is interactive and not a simple image, then print out the string "interactive comic".
This does not include the comics which are an image inside a link, those still have to be displayed normally.
After displaying the image, it should go back to waiting around for the next update.
Your program cannot access any sites except http://xkcd.com
This is code-golf, so shortest code in bytes wins!

*/

package main

import (
	"encoding/xml"
	"fmt"
	"io"
	"log"
	"net/http"
	"time"
)

func main() {
	err := watch("https://xkcd.com/rss.xml")
	if err != nil {
		log.Fatal(err)
	}
}

func watch(url string) error {
	var rss0 RSS
	for {
		rss, err := get(url)
		if err != nil {
			return err
		}

		if len(rss.Channel.Item) > 0 {
			if len(rss0.Channel.Item) == 0 || rss0.Channel.Item[0].PubDate != rss.Channel.Item[0].PubDate {
				ch := &rss.Channel.Item[0]
				fmt.Println(time.Now())
				fmt.Printf("Title: %s\n", ch.Title)
				fmt.Printf("Link: %s\n", ch.Link)
				fmt.Printf("Description: %s\n", ch.Description)
				fmt.Printf("Publication Date: %s\n", ch.PubDate)
				fmt.Printf("GUID: %s\n", ch.GUID)
				fmt.Println()
			}
			rss0 = rss
		}

		time.Sleep(1 * time.Minute)
	}

	return nil
}

func get(url string) (rss RSS, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return
	}

	err = xml.Unmarshal(data, &rss)
	if err != nil {
		return
	}

	return
}

type RSS struct {
	XMLName xml.Name `xml:"rss"`
	Channel Channel
}

type Channel struct {
	XMLName     xml.Name `xml:"channel"`
	Title       string   `xml:"title"`
	Link        string   `xml:"link"`
	Description string   `xml:"description"`
	Language    string   `xml:"language"`
	Item        []Item   `xml:"item"`
}

type Item struct {
	Title       string `xml:"title"`
	Link        string `xml:"link"`
	Description string `xml:"description"`
	PubDate     string `xml:"pubDate"`
	GUID        string `xml:"guid"`
}
