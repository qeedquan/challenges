/*

Summary
When starting off with threading sometimes it would seem that using boolean flags to protect critical sections should be enough.
That's not always the case, as demonstrated with this Kata. Your task is to fix the bug so that we won't get into the critical section more than once.

Issue
The kata presents a solution, wherein your have threadCode which is executed in some number of threads.
In this code you make a call to a critical section, which should only be called by one thread at a time.
The example provided is subject to a race condition which needs to be mitigated to ensure we're calling the critical section in only one thread at a time. The critical_section may be performing significant work.

*/

use std::sync::mpsc::channel;
use std::sync::{Arc, Mutex};
use std::thread;

fn main() {
    const N: usize = 100000;

    let data = Arc::new(Mutex::new(0));
    let (tx, rx) = channel();
    for _ in 0..N {
        let (data, tx) = (Arc::clone(&data), tx.clone());
        thread::spawn(move || {
            let mut data = data.lock().unwrap();
            *data += 1;
            if *data == N {
                tx.send(()).unwrap();
            }
        });
    }

    rx.recv().unwrap();
    println!("{data:?}");
}
