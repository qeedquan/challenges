/*

Write a function solution:whiner/1, describing a process, which will await {awake} message, and - after getting it - will start sending Parent process {whine, "Is anybody out there?"} message, every 1000ms. It should do so infinitely, or stop and exit alltogether, should it receive {give_up} message.

Be aware; she may be a whiner, but this function is damn diligent, so it shall read every message, even malformed one!

Even when it's awake and busy sending messages to the Parent every 1000ms, it should still attend all the coming messages without delay.

*/

package main

import (
	"log"
	"time"
)

func main() {
	parent := make(chan string)
	event := make(chan string)
	go whiner(parent, event)
	go mailman(2*time.Second, event, "awake")
	go mailman(5*time.Second, event, "give_up")

	log.Println("init")
loop:
	for {
		select {
		case message := <-parent:
			log.Println(message)
			if message == "exit" {
				break loop
			}
		}
	}
}

func whiner(parent, event chan string) {
	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()

	state := 0
	for {
		select {
		case message := <-event:
			switch message {
			case "awake":
				state = 1
			case "give_up":
				parent <- "exit"
				return
			}

		case <-ticker.C:
			if state == 1 {
				parent <- "whine: Is anybody out there?"
			}
		}
	}
}

func mailman(duration time.Duration, mailbox chan string, message string) {
	time.Sleep(duration)
	mailbox <- message
}
