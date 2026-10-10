fn main() {
    assert_eq!(cycle(5555), 32);
    assert_eq!(cycle(815), 17);
    assert_eq!(cycle(6239), 111);
}

fn cycle(seed: isize) -> isize {
    let mut count = 1;
    let mut slow = seed;
    let mut fast = seed;
    loop {
        slow = f(slow);
        fast = f(f(fast));
        if slow == fast {
            break;
        }
    }

    slow = seed;
    while slow != fast {
        slow = f(slow);
        fast = f(fast);
        count += 1;
    }

    slow = f(fast);
    while slow != fast {
        count += 1;
        slow = f(slow);
    }

    count
}

fn f(x: isize) -> isize {
    return (x * x / 100) % 10000;
}
