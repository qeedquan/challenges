/*

We all love horoscopes, don't we? But I have a serious problem in this Horoscope App installed on my Smart Phone that it only displays the icon of the Zodiac Sign for each day's horoscope. Now, I do remember my horoscope, but its hard to remember others' whose horoscope I am interested in.

Challenge
So here is your challenge for an another addition to the ASCII Art of the Day series. Given a date and month input, output the corresponding Zodiac sign in ASCII format as shown below. Each Zodiac Sign is followed after the name and date range (DD MM format) for the zodiac sign.

Aries - 21 03 - 20 04
 .-.   .-.
(_  \ /  _)
     |
     |
Taurus - 21 04 - 20 05
 .     .
 '.___.'
 .'   '.
:       :
:       :
 '.___.'
Gemini - 21 05 - 20 06
._____.
  | |
  | |
 _|_|_
'     '
Cancer - 21 06 - 20 07
   .--.
  /   _'.
 (_) ( )
'.    /
  '--'
Leo - 21 07 - 20 08
  .--.
 (    )
(_)  /
    (_.
Virgo - 21 08 - 20 09
 _
' ':--.--.
   |  |  |_
   |  |  | )
   |  |  |/
        (J
Libra - 21 09 - 20 10
     __
___.'  '.___
____________
Scorpio - 21 10 - 20 11
 _
' ':--.--.
   |  |  |
   |  |  |
   |  |  |  ...
         '---':
Sagittarius - 21 11 - 20 12
      ...
      .':
    .'
'..'
.''.
Capricorn - 21 12 - 20 01
        _
\      /_)
 \    /'.
  \  /   :
   \/ __.'
Aquarius - 21 01 - 20 02
.-"-._.-"-._.-
.-"-._.-"-._.-
Pisces - 21 02 - 20 03
'-.    .-'
   :  :
 --:--:--
   :  :
.-'    '-.

Input
You would be provided two integers corresponding to the date of month and month of year (in that order) of the birthday.
The date and month will be 1 indexed like in normal calendars.
You can take input form STDIN/ARGV/function arguments or the closest equivalent

Output
Based on what date range the input date falls in, output to STDOUT, the corresponding Zodiac Sign.
You can have upto 4 trailing spaces in each line but no leading spaces that are not part of the output.
You can either write a full program or a named function.
This is code-golf so the shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"strings"
	"time"
)

type Zodiac struct {
	sign    string
	start   time.Time
	end     time.Time
	drawing string
}

func main() {
	sign(21, 6)
	sign(13, 2)
	sign(30, 3)
	sign(2, 5)
}

func sign(day, month int) *Zodiac {
	current := time.Date(0, time.Month(month), day, 0, 0, 0, 0, time.UTC)
	for index, zodiac := range ZODIACS {
		if between(current, zodiac.start, zodiac.end) {
			fmt.Println(zodiac.sign, day, "-", month)
			fmt.Println(zodiac.drawing)
			fmt.Println()
			return &ZODIACS[index]
		}
	}
	return nil
}

func between(current, start, end time.Time) bool {
	if !(start.Before(current) || start.Equal(current)) {
		return false
	}
	if !(end.Equal(current) || end.After(current)) {
		return false
	}
	return true
}

func parse(art string) []Zodiac {
	zodiacs := []Zodiac{}
	lines := strings.Split(art, "\n")
	for _, line := range lines {
		var (
			sign  string
			day   [2]int
			month [2]int
		)

		if strings.TrimSpace(line) == "" {
			continue
		}

		_, err := fmt.Sscanf(line, "%s - %d %d - %d %d", &sign, &day[0], &month[0], &day[1], &month[1])
		if err == nil {
			zodiacs = append(zodiacs, Zodiac{
				sign:  sign,
				start: time.Date(0, time.Month(month[0]), day[0], 0, 0, 0, 0, time.UTC),
				end:   time.Date(0, time.Month(month[1]), day[1], 0, 0, 0, 0, time.UTC),
			})
		} else if index := len(zodiacs) - 1; index >= 0 {
			zodiacs[index].drawing += line + "\n"
		}
	}

	return zodiacs
}

var ZODIACS = parse(ART)

const ART = `
Aries - 21 03 - 20 04
 .-.   .-.
(_  \ /  _)
     |
     |
Taurus - 21 04 - 20 05
 .     .
 '.___.'
 .'   '.
:       :
:       :
 '.___.'
Gemini - 21 05 - 20 06
._____.
  | |
  | |
 _|_|_
'     '
Cancer - 21 06 - 20 07
   .--.
  /   _'.
 (_) ( )
'.    /
  '--'
Leo - 21 07 - 20 08
  .--.
 (    )
(_)  /
    (_.
Virgo - 21 08 - 20 09
 _
' ':--.--.
   |  |  |_
   |  |  | )
   |  |  |/
        (J
Libra - 21 09 - 20 10
     __
___.'  '.___
____________
Scorpio - 21 10 - 20 11
 _
' ':--.--.
   |  |  |
   |  |  |
   |  |  |  ...
         '---':
Sagittarius - 21 11 - 20 12
      ...
      .':
    .'
'..'
.''.
Capricorn - 21 12 - 20 01
        _
\      /_)
 \    /'.
  \  /   :
   \/ __.'
Aquarius - 21 01 - 20 02
.-"-._.-"-._.-
.-"-._.-"-._.-
Pisces - 21 02 - 20 03
'-.    .-'
   :  :
 --:--:--
   :  :
.-'    '-.
`
