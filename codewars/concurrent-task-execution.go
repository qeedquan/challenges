/*

Implement a Worker class, which given a set of tasks (implementations of Runnable interface in Java and custom Runnable class in C#) will execute them concurrently and return the summary of the execution with tasks categorized as successful, failed or timed out.

For example, following input:

actions=[Task3(throws after 3s), Task4(compl. after 4s), Task2(compl. after 2s), Task1(throws after 1s)], timeout=8s
Should return following result after 4 seconds:

result.successful = [Task2, Task4]
result.failed = (Task3, Task1)
result.timedOut = ()
And following input:

actions=[Task3(throws after 3s), Task5(hangs), Task4(compl. after 4s), Task2(compl. after 2s), Task1(compl. after 1s)], timeout=8s
Should return following result after 8 seconds:

result.successful = [Task1, Task2, Task4]
result.failed = (Task3)
result.timedOut = (Task5)
Requirements:

You need to execute tasks before timeout given as parameter, as well as before CodeWars times out the test run. Currently, CodeWars timeouts are 16s for Java and 12s for C#. Collective duration of all the tasks will surely exceed the timeout, so you cannot execute tasks iteratively one after another.
There will be something between 25 and 60 tasks to execute.
Some of the tasks will work for some time and then finish. Other will fail and its run method will throw an unspecified exception. It can also happen that task hangs and does not return in short time. Worker needs to categorize each passed task as successful, failed or timed out and add them into respective collections of returned ExecutedTasks instance.
Successfull tasks must be returned in the order of their duration. It's guaranteed that when all tasks are started simultanoussly, each successful task will end in some distinct point in time and there should be no two tasks that finish at the same moment (for some definition of "same moment", see note below). Order of failed or timed out tasks is not important.
When it happens that there is no hanging task, method should return after a time not significantly longer than duration of the longest running task. For example, when the longest running task takes 3 seconds to execute, method should return after 3 seconds + maybe some small additional time (but see note below).
It's forbidden for this kata to use busy loops and Thread.sleep method in Java and Thread.Sleep in C#, as all waits and blocks should be realized with proper methods and timeouts. Tests do some effort to detect quickly spinning delay loops, and solution file will be scanned for all occurences of the phrase "sleep" or "Sleep" and will be rejected when any is found. It's a textual search, so the phrase cannot appear even as a name of variable or method defined by you, nor in the comments (sorry for that!). It's not perfect because it still allows for other improper implementations of delay which I cannot protect against, but be sure that when you use any of these, Threading Fairy is going to punch you right into your critical section.
It's guaranteed that:

Each task will take less than expected timeout to execute, unless it hangs. When it hangs, it hangs for a few minutes and definitely will not finish in any short time. You can safely assume that if execution of a task takes more than provided timeout, it hangs.
Time limit given as parameter will be always significantly smaller than timeout of CodeWars platform.
It's not important what happens to timed out tasks. You can kill them, you can leave them running. You do not need to take any particular action against them, but it rather won't hurt anyone if you do. Just do not crash them :)
Tasks are mostly idling and simulate blocking operations (waiting for user input, I/O operation, and such), so they rather won't get into the way of other tasks and block their execution. They won't compete about any kind of common resources, including CPU.
References to Runnable objects passed in as input collection point to unique objects and there are no duplicates.
Skeleton of the Worker class is provided in the solution setup:

public class Worker {

    public static class ExecutedTasks {

        public final List<Runnable> successful = new ArrayList<>();
        public final Set<Runnable> failed = new HashSet<>();
        public final Set<Runnable> timedOut = new HashSet<>();
    }

    public ExecutedTasks execute(Collection<Runnable> actions, long timeoutMillis) throws InterruptedException {

        ExecutedTasks result = new ExecutedTasks();
        //your code here...
        return result;
    }
}
NOTE: As the nature of concurrency-related APIs is often unspecified in aspects such as order of execution, timings, task scheduling details and so on, it's possible that under some circumstances tests will fail although they are expected to pass. I did my best to fine tune the factors of test tasks in such a way that tests will pass for correct solutions. I tried to set the time margins and values of expected timeouts to reasonable values with which I believe tests should pass without problems. But still I could do something incorrectly, especially in C# version, where contraints imposed by CodeWars platform are a bit more restrictive. If you believe that your solution is correct but it failed, then resubmit and check again. Server load might also affect the result, so if solution keeps failing due to some millisecond errors, then try again later when server does not experience heavy traffic. If still no luck and you are really convinced that your solution is OK, please raise an issue.

Credits: This kata is inspired by Execute me nTimes by dcieslak - you can try it before solving this one.

*/

package main

import (
	"errors"
	"fmt"
	"time"
)

type taskfn func() error

func main() {
	fmt.Println(launch([]taskfn{
		worker(1, true),
		worker(2, false),
		worker(3, true),
		worker(4, false),
	}, 8*time.Second))

	fmt.Println(launch([]taskfn{
		worker(1, false),
		worker(2, false),
		worker(3, true),
		worker(4, false),
		worker(100, false),
	}, 8*time.Second))
}

func worker(seconds time.Duration, fail bool) taskfn {
	return func() error {
		time.Sleep(seconds * time.Second)
		if fail {
			return errors.New("failed")
		}
		return nil
	}
}

func launch(tasks []taskfn, timeout time.Duration) (successful, failed, timedout []int) {
	chan0 := make(chan int, len(tasks))
	chan1 := make(chan int, len(tasks))
	for index, task := range tasks {
		go func() {
			if task() == nil {
				chan0 <- index + 1
			} else {
				chan1 <- index + 1
			}
		}()
	}

	seen := make(map[int]bool)
	ticker := time.NewTicker(timeout)
	defer ticker.Stop()

loop:
	for id := 0; len(seen) < len(tasks); seen[id] = true {
		select {
		case id = <-chan0:
			successful = append(successful, id)
		case id = <-chan1:
			failed = append(failed, id)
		case <-ticker.C:
			for id := 1; id <= len(tasks); id++ {
				if !seen[id] {
					timedout = append(timedout, id)
				}
			}
			break loop
		}
	}
	return
}
