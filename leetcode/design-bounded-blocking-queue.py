#!/usr/bin/env python3

"""

Implement a thread safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is blocked until the queue is no longer full.
int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the calling thread is blocked until the queue is no longer empty.
int size() Returns the number of elements currently in the queue.
Your implementation will be tested using multiple threads at the same time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls to the dequeue method. The size method will be called after every test case.

Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.



Example 1:

Input:
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

Output:
[1,0,2,2]

Explanation:
Number of producer threads = 1
Number of consumer threads = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // initialize the queue with capacity = 2.

queue.enqueue(1);   // The producer thread enqueues 1 to the queue.
queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
queue.enqueue(0);   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
queue.enqueue(2);   // The producer thread enqueues 2 to the queue.
queue.enqueue(3);   // The producer thread enqueues 3 to the queue.
queue.enqueue(4);   // The producer thread is blocked because the queue's capacity (2) is reached.
queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.


Example 2:

Input:
3
4
["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","dequeue","enqueue"]
[[3],[1],[0],[2],[],[],[],[3]]

Output:
[1,0,2,1]

Explanation:
Number of producer threads = 3
Number of consumer threads = 4

BoundedBlockingQueue queue = new BoundedBlockingQueue(3);   // initialize the queue with capacity = 3.

queue.enqueue(1);   // Producer thread P1 enqueues 1 to the queue.
queue.enqueue(0);   // Producer thread P2 enqueues 0 to the queue.
queue.enqueue(2);   // Producer thread P3 enqueues 2 to the queue.
queue.dequeue();    // Consumer thread C1 calls dequeue.
queue.dequeue();    // Consumer thread C2 calls dequeue.
queue.dequeue();    // Consumer thread C3 calls dequeue.
queue.enqueue(3);   // One of the producer threads enqueues 3 to the queue.
queue.size();       // 1 element remaining in the queue.

Since the number of threads for producer/consumer is greater than 1, we do not know how the threads will be scheduled in the operating system, even though the input seems to imply the ordering. Therefore, any of the output [1,0,2] or [1,2,0] or [0,1,2] or [0,2,1] or [2,0,1] or [2,1,0] will be accepted.

"""

from collections import *
from threading import *

class Queue:
    def __init__(self, capacity):
        self.data = deque()
        self.seme = Semaphore(capacity)
        self.semd = Semaphore(0)

    def enqueue(self, val):
        self.seme.acquire()
        self.data.append(val)
        self.semd.release()

    def dequeue(self):
        self.semd.acquire()
        val = self.data.popleft()
        self.seme.release()
        return val

    def size(self):
        return len(self.data)

def producer(queue, vals):
    for val in vals:
        print("Enqueue", val)
        queue.enqueue(val)

def consumer(queue, vals):
    for _ in vals:
        val = queue.dequeue()
        print("Dequeue", val)

def decode(instruction):
    toks = instruction.split(" ")
    op, val = toks[0], 0
    if len(toks) > 1:
        val = int(toks[1])
    return op, val

def test(queue_size, num_producers, num_consumers, instructions):
    if num_producers < 1 or num_consumers < 1 or len(instructions) < 1:
        return

    queue = Queue(queue_size)
    argp = [[] for i in range(num_producers)]
    argc = [[] for i in range(num_consumers)]
    pi = 0
    ci = 0
    for i in range(len(instructions)-1):
        op, val = decode(instructions[i])
        if op == "enqueue":
            argp[pi].append(val)
            pi = (pi + 1) % len(argp)
        elif op == "dequeue":
            argc[ci].append(val)
            ci = (ci + 1) % len(argc)

    threads = []
    for arg in argp:
        threads.append(Thread(target=producer, args=(queue, arg))) 
    for arg in argc:
        threads.append(Thread(target=consumer, args=(queue, arg))) 
    
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()

    op, val = decode(instructions[-1])
    assert(op == "size" and val == queue.size())

    print()

def main():
    test(2, 1, 1, ["enqueue 1", "dequeue", "dequeue", "enqueue 0", "enqueue 2", "enqueue 3", "enqueue 4", "dequeue", "size 2"])
    test(3, 3, 4, ["enqueue 1", "enqueue 0", "enqueue 2", "dequeue", "dequeue", "dequeue", "enqueue 3", "size 1"])

main()
