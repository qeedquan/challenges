/*

Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true;

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;

*/

package main

func main() {
	var l Logger
	l.Init(10)
	assert(l.ShouldPrint(1, "foo") == true)
	assert(l.ShouldPrint(2, "bar") == true)
	assert(l.ShouldPrint(3, "foo") == false)
	assert(l.ShouldPrint(8, "bar") == false)
	assert(l.ShouldPrint(10, "foo") == false)
	assert(l.ShouldPrint(11, "foo") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Logger struct {
	database map[string]uint64
	limiter  uint64
}

func (l *Logger) Init(limiter uint64) {
	l.database = make(map[string]uint64)
	l.limiter = limiter
}

func (l *Logger) ShouldPrint(timestamp uint64, message string) bool {
	lasttime, exist := l.database[message]
	if !exist || (timestamp >= lasttime && timestamp-lasttime >= l.limiter) {
		l.database[message] = timestamp
		return true
	}
	return false
}
