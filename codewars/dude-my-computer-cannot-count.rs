/*

Remember the times when every website had a counter? A friend of yours runs one of those sites.

But as his site gains popularity, he observes some strange behavior: Sometimes, when there are many users accessing his page, the counter does not represent what he can get from the access logs.

Knowing your programming skills, he asks you to investigate. You look at his code and immediately see what's wrong: his VisitorStatistics implementation is not thread-safe.

"No big deal," you tell him. "I'll fix it in no time!"

*/

use std::sync::atomic::{AtomicU64, Ordering};
use std::thread;

fn main() {
    static ATOMIC: AtomicU64 = AtomicU64::new(0);

    let thread1 = thread::spawn(|| {
        ATOMIC.fetch_add(1, Ordering::Relaxed);
    });

    let thread2 = thread::spawn(|| {
        ATOMIC.fetch_add(3, Ordering::Relaxed);
    });

    let thread3 = thread::spawn(|| {
        ATOMIC.fetch_add(50, Ordering::Relaxed);
    });

    let _ = thread1.join();
    let _ = thread2.join();
    let _ = thread3.join();
    println!("{}", ATOMIC.load(Ordering::Relaxed));
}
