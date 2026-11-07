/*

Code as fast as you can!

You need to make a constructor function with two methods (and only these two methods) to return and increment a counter, but the counter should not be directly accessible from outside the function.

*/

mod my {
    pub struct Counter {
        value: isize,
    }

    impl Counter {
        pub fn new(value: isize) -> Counter {
            Counter { value: value }
        }

        pub fn increment(&mut self) {
            self.value += 1;
        }

        pub fn get(&self) -> isize {
            self.value
        }
    }
}

fn main() {
    let mut counter = my::Counter::new(0);
    for _ in 0..10 {
        counter.increment();
        println!("{}", counter.get());
    }
}
