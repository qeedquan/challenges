/*

Your challenge: Connect to the Online Encyclopedia of Integer Sequences OEIS.org, access any random valid sequence, output it's ID, and ouput all of the members of the sequence provided by the OEIS entry. The only website you're allowed to connect to is OEIS.org.

Hints: Sequences are found in URLs such as http://oeis.org/A280629, however a more easily parseable version is found at URLs such as http://oeis.org/search?q=id:A280629&fmt=text. Every present and future sequence matches the regex "[A-Z]\d{6}". (The regex is there to describe what an ID looks like. There are a lot of invalid sequences that match it, too). The webcam (http://oeis.org/webcam) feature of OEIS generates random sequences, but you'll have to find a way to change the dropdown menu from 'best sequences' to 'all sequences' to use it.

Example output:

A280629
1, 1, 7, 139, 6913, 508921, 57888967, 9313574419, 1984690709953, 547467006437041, 188946742298214727, 79783392959511537499, 40498043815904027702593, 24314800861291379306213161, 17047720745682515427867108487, 13802952030641885344209574247779, 12780883488499783875309105315925633, 13420910251496135926622603184056054881, 15863354775169518855398667975850797997447, 20966527201075972453953302254528386060431659
Every existing sequence has to have a chance of being outputed, it does not have to be an equal chance.

Your program should continue to function properly regardless of future sequences being added. Even though all IDs presently start with A, there will eventually be a sequence B000001 after all the A sequences run out. You can assume that there will be no more sequences after Z999999 is defined, but you do have to assume that it will eventually be defined.

An invalid sequence, which your program should never output, is one that doesn't exist. You may treat sequences with no given members (such as A280611 either as invalid or give just the sequence ID and nothing else or a falsy value, but you must be consistent.

This is code-golf, fewest bytes wins!

*/

package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"net/http"
	"strings"
	"time"
)

func main() {
	oeis()
}

func oeis() {
	id := genid()
	fmt.Println(id)

	url := fmt.Sprintf("http://oeis.org/search?q=id:%s&fmt=text", id)
	resp, err := http.Get(url)
	if err != nil {
		return
	}

	scan := bufio.NewScanner(resp.Body)
	filter := fmt.Sprintf("%%S %s ", id)
	for scan.Scan() {
		line := scan.Text()
		if strings.HasPrefix(line, "%S") {
			line = strings.TrimPrefix(line, filter)
			line = strings.TrimSuffix(line, ",")
			fmt.Println(line)
			break
		}
	}
}

func genid() string {
	ns := time.Now().UnixNano()
	source := rand.NewSource(ns)
	rng := rand.New(source)
	zipf := rand.NewZipf(rng, 10, 1, 25)
	return fmt.Sprintf("%c%06d", 'A'+zipf.Uint64(), rand.Intn(1000000))
}
