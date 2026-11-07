/*

This is the simplest of interactive problems - please read explanations in this article before trying. The purpose of this task is to learn exchanging post requests with server at all.

You are to play quite clever game against the server:

after you send the first request (i.e. one with a lonely token), server choses random value between 1 and 99 and returns it to you (with the name of secret);
you should then send another request with field answer which contains another value, so that their sum is exactly 100.
GAME-NAME is say-100 - use it in the server url given in the instruction above.

Input data gives you a token to play and answer should contain victory token returned to you by server.

Example:

YOU                                 SERVER
------------------------            ------------------------

token: <your-token>                                                         // request #1

                                    secret: 74                              // response #1

token: <your-token>                                                         // request #2
answer: 26

                                    end: <your-victory-token>               // response #2

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"strconv"
	"sync"
)

var (
	addr    = flag.String("addr", ":8080", "address to listen on")
	secrets = make(map[string]int)
	lock    sync.Mutex
)

func main() {
	flag.Parse()
	log.Println("Starting server...")
	http.HandleFunc("/", mainpage)
	check(http.ListenAndServe(*addr, nil))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func mainpage(w http.ResponseWriter, r *http.Request) {
	lock.Lock()
	defer lock.Unlock()

	sid, err := r.Cookie("session_id")
	if err != nil {
		fmt.Fprintf(w, "No Session ID")
		return
	}

	secret, found := secrets[sid.Value]
	if !found {
		secret = rand.Intn(99) + 1
		secrets[sid.Value] = secret
		fmt.Fprintln(w, secret)
		return
	}

	answer, err := r.Cookie("answer")
	if err != nil {
		fmt.Fprintln(w, "No answer")
		return
	}

	value, _ := strconv.Atoi(answer.Value)
	if value < 1 || value >= 100 || value+secrets[sid.Value] != 100 {
		fmt.Fprintln(w, "Lost")
	} else {
		fmt.Fprintln(w, "Victory")
		delete(secrets, sid.Value)
	}
}
